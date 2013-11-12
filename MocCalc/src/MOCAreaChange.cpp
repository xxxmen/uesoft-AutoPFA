// MOCAreaChange.cpp: implementation of the MOCAreaChange class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCAreaChange.h"
#include "CalcAreaChange.h"
#include "LocalRStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCAreaChange::MOCAreaChange()
{
	m_dK = 0;							
	m_nBasisAreaType = 0;				
	m_dBasisArea = 0;	
}

MOCAreaChange::~MOCAreaChange()
{

}

MOCJun* MOCAreaChange::Creator()
{
	MOCAreaChange *pData = new MOCAreaChange;
	return pData;
}

BOOL MOCAreaChange::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcAreaChange *pAreaChangeData = dynamic_cast<CalcAreaChange*>(pData);
	ASSERT(pAreaChangeData != NULL);
	m_dK = pAreaChangeData->K();
	m_nBasisAreaType = pAreaChangeData->BasisAreaType();
	m_dBasisArea = pAreaChangeData->BasisArea();	
	return TRUE;
}

BOOL MOCAreaChange::InitEndInfo()
{
	m_dLossK = m_dK;
	return InitInOutEle();
}

void MOCAreaChange::CalcStm()
{
	double dArea = BasisArea( m_nBasisAreaType, m_dBasisArea );
	//Modify by Liuck [3/18/2009] K系数必须还乘上摩擦损失因子
	m_EndList.KStrategy( m_dK * m_dDesignFactor, dArea );
}

void MOCAreaChange::UpdataEnd()
{
	UpdataTwoEnd();
}

void MOCAreaChange::CalcImpulse(MOCTrans &trans, double dTime)
{
	CalcStm();
}
