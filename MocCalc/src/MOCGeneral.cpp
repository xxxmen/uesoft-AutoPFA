// MOCGeneral.cpp: implementation of the MOCGeneral class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCGeneral.h"
#include "CalcGeneral.h"
#include "LocalRStrategy.h"
#include "PressDropStrategy.h"
#include "MOCFluid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCGeneral::MOCGeneral()
{
	m_nLossType = 0;                       
	m_dK = 0;							
	m_nBasisAreaType = 0;			
	m_dBasisArea = 0;
	m_dCurMass = 0;
}

MOCGeneral::~MOCGeneral()
{

}

MOCJun* MOCGeneral::Creator()
{
	MOCGeneral *pData = new MOCGeneral;
	return pData;
}

BOOL MOCGeneral::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcGeneral *pGeneralData = dynamic_cast<CalcGeneral*>(pData);
	ASSERT(pGeneralData != NULL);
	m_nLossType = pGeneralData->LossType();                       
	m_dK = pGeneralData->K();							
	m_nBasisAreaType = pGeneralData->BasisAreaType();			
	m_dBasisArea = pGeneralData->BasisArea();
	m_Polynomial.Read(pGeneralData->m_Curve);
	return TRUE;
}

BOOL MOCGeneral::InitEndInfo()
{
	return InitInOutEle();
}

void MOCGeneral::CalcStm()
{
	double dArea = BasisArea(m_nBasisAreaType,m_dBasisArea);
	if( 1 == m_nLossType )
	{
		m_EndList.KStrategy( m_dK * m_dDesignFactor, dArea );
	}
	else if( 2 == m_nLossType )
	{
		m_EndList.KStrategy( GetCurK() * m_dDesignFactor, dArea );
	}
	else if( 3==m_nLossType )
	{
		StmRCurve();
	}
	else
	{
		ASSERT(FALSE);
	}
}

double MOCGeneral::GetCurK()
{
	double dK = 1;
	return dK;
}

double MOCGeneral::GetCurPress(double dX)
{
	double dPress = 0;
	if(0 == m_Polynomial.XAxisType())//体积流量
		dX = MOCFluid::TranMassToQ(dX);
	if(dX > m_Polynomial.MaxX())
		dX = m_Polynomial.MaxX();
	if(dX < 0)
		dX = 0;
	dPress = m_Polynomial.GetY(m_CurveData,dX);
	if(m_Polynomial.YAxisType()==0)//水头
		dPress = MOCFluid::TranHToPress(dPress);
	return dPress;
}

double MOCGeneral::CalcRCurve(double dPress)
{
	return m_EndList.FixDropStrategy(dPress);

}
double MOCGeneral::CalcMass(double dPress)
{
	return m_EndList.FixDropMass(dPress);
}

void MOCGeneral::StmRCurve()
{
	double dMass = m_dCurMass;
	double dPress = GetCurPress(dMass);
	m_dCurMass = CalcMass(dPress);
	dPress = GetCurPress((m_dCurMass+dMass)/2.0);
	m_dCurMass = CalcRCurve(dPress);
}

void MOCGeneral::UpdataEnd()
{
	UpdataTwoEnd();
}

void MOCGeneral::CalcImpulse(MOCTrans &trans, double dTime)
{
	double dArea = BasisArea(m_nBasisAreaType,m_dBasisArea);
	if(1==m_nLossType)
	{
		m_EndList.KStrategy(m_dK,dArea);
	}
	else if(2==m_nLossType)
	{
		m_EndList.KStrategy(GetCurK(),dArea);
	}
	else if(3==m_nLossType)
	{
		ImpulseRCurve();
	}
	else
	{
		ASSERT(FALSE);
	}
}

void MOCGeneral::ImpulseRCurve()
{
	double dOldMass = 0;
	double dOldPress = GetCurPress(m_dCurMass);
	double dNewMass = 0;
	double dNewPress = 0;
	double dTol =0;
	do 
	{
		dOldMass = m_dCurMass;
		dNewMass = CalcMass(dOldPress);
		m_dCurMass = (dNewMass+dOldMass)/2.0;
		dNewPress = GetCurPress(m_dCurMass);
		dTol = fabs((dNewMass-dOldMass)/dNewMass);
		dOldPress = dNewPress;
	} while(dTol>1E-5||fabs((dNewPress-dOldPress))>1E-3);
	m_dCurMass = CalcRCurve(dNewPress);
}
