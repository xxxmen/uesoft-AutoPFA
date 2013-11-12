// PCFReservior.cpp: implementation of the PCFReservior class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFReservior.h"
#include "PCFJun.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFReservior::PCFReservior()
{
	m_strName = _T("Reservior");
	m_nTypeID = 2;
	m_bPFAJun = TRUE;
	m_EleOrDepth.InitData( _T( "12,meters" ) );
	m_SurfacePress.InitData( _T( "1,atm" ) );
}

PCFReservior::~PCFReservior()
{

}

void PCFReservior::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
		SetSEFromBasePt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}

PCFJun* PCFReservior::Creator()
{
	PCFReservior *pData = new PCFReservior;
	return pData;
}


/*------------------------------------------*/
StrArray<2> PCFReservior::GetEleOrDepth()
{
	return m_EleOrDepth.GetArray();
}
void PCFReservior::SetEleOrDepth(const StrArray<2>& strValue)
{
	m_EleOrDepth.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<2> PCFReservior::GetSurfacePress()
{
	return m_SurfacePress.GetArray();
}
void PCFReservior::SetSurfacePress(const StrArray<2>& strValue)
{
	m_SurfacePress.SetArray(strValue);
}
/*------------------------------------------*/
