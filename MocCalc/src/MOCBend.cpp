// MOCBend.cpp: implementation of the MOCBend class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCBend.h"
#include "CalcBend.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCBend::MOCBend()
{
	m_dK = 0;							
	m_nBasisAreaType = 0;				
	m_dBasisArea = 0;
}

MOCBend::~MOCBend()
{

}

MOCJun* MOCBend::Creator()
{
	MOCBend *pData = new MOCBend;
	return pData;
}

BOOL MOCBend::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcBend *pBendData = dynamic_cast<CalcBend*>(pData);
	ASSERT(pBendData != NULL);
	m_dK = pBendData->K();
	m_nBasisAreaType = pBendData->BasisAreaType();
	m_dBasisArea = pBendData->BasisArea();	
	return TRUE;
}

BOOL MOCBend::InitEndInfo()
{
	m_dLossK = m_dK;
	return InitInOutEle();
}

void MOCBend::CalcStm()
{
	double dArea = BasisArea(m_nBasisAreaType,m_dBasisArea);
	m_EndList.KStrategy(m_dK * m_dDesignFactor, dArea );
}

void MOCBend::UpdataEnd()
{
	UpdataTwoEnd();
}

void MOCBend::CalcImpulse(MOCTrans &trans, double dTime)
{
	CalcStm();
}