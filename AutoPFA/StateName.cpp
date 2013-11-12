// StateName.cpp: implementation of the StateName class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "StateName.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StateName::StateName()
{
	m_nKey = 0;
	m_nFlyWeightType =0;
	m_bShow = FALSE;

}
StateName::StateName(CString strName,int nKey,int nType,BOOL bShow)
{
	m_strName = strName;
	m_nKey = nKey;
	m_nFlyWeightType = nType;
	m_bShow = bShow;
}
StateName::StateName(int nKey,int nType)
{
	m_nKey = nKey;
	m_nFlyWeightType = nType;
	m_bShow = FALSE;
}
StateName::~StateName()
{

}

CString StateName::NameUnit()
{
	CString strNameUnit;
	strNameUnit.LoadString(IDS_STRNAMEUNIT);
	strNameUnit = m_strName + strNameUnit;
	return strNameUnit;
}




