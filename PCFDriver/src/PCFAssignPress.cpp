// PCFAssignPress.cpp: implementation of the PCFAssignPress class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFAssignPress.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFAssignPress::PCFAssignPress()
{
	m_strName = _T("ASSIGNPRESS");
	m_nTypeID = 4;
	m_bPFAJun = TRUE;
	m_Press.InitData( _T( "1,10,atm" ) );
	m_EleUnit.InitData( _T( "meters" ) );
}

PCFAssignPress::~PCFAssignPress()
{

}

PCFJun* PCFAssignPress::Creator()
{
	PCFAssignPress *pData = new PCFAssignPress;
	return pData;
}

/*------------------------------------------*/
CString PCFAssignPress::GetDistanceUnit()
{
	return m_EleUnit.GetData();
}
void PCFAssignPress::SetDistanceUnit(CString strValue)
{
	m_EleUnit.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> PCFAssignPress::GetPressure()
{
	return m_Press.GetArray();
}
void PCFAssignPress::SetPressure(const StrArray<3>& strValue)
{
	m_Press.SetArray(strValue);
}

void PCFAssignPress::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
		SetSEFromBasePt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}