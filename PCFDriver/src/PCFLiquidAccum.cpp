// PCFLiquidAccum.cpp: implementation of the PCFLiquidAccum class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFLiquidAccum.h"
#include "PCFJun.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFLiquidAccum::PCFLiquidAccum()
{
	m_strName = _T("LiquidAccum");
	m_nTypeID = 23;
	m_bPFAJun = TRUE;
	m_Elastic.InitData( _T( "1,Pascals" ) );
	m_Volume.InitData( _T( "3,meters3" ) );
}

PCFLiquidAccum::~PCFLiquidAccum()
{
	
}

PCFJun* PCFLiquidAccum::Creator()
{
	PCFLiquidAccum *pData = new PCFLiquidAccum;
	return pData;
}

/*------------------------------------------*/
StrArray<2> PCFLiquidAccum::Elastic()
{
	return m_Elastic.GetArray(); 
}

void PCFLiquidAccum::Elastic(StrArray<2>& array)
{
	m_Elastic.SetArray(array);
}
/*------------------------------------------*/
StrArray<2> PCFLiquidAccum::InitVolume()
{
	return m_Volume.GetArray();
}

void PCFLiquidAccum::InitVolume(StrArray<2>& array)
{
	m_Volume.SetArray(array);
}
/*------------------------------------------*/

void PCFLiquidAccum::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
		SetSEFromBasePt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}