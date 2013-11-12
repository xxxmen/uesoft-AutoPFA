// OutDataAttr.cpp: implementation of the OutDataAttr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OutDataAttr.h"
#include "UnitSubSystem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
OutDataAttr::OutDataAttr()
{
}

OutDataAttr::OutDataAttr(UnitSubSystem &unitsys,int nKey,CString strName,BOOL bShow)
{
	m_nKey = nKey;
	m_UnitType = None;
	m_strName = strName;
	m_bShow = bShow;
	m_pUnitsys = &unitsys;
}
OutDataAttr::OutDataAttr(UnitSubSystem &unitsys,int nKey,UnitTypeID type,CString strName,BOOL bShow)
{
	m_nKey = nKey;
	m_UnitType = type;
	m_strName = strName;
	m_bShow = bShow;
	m_strUnit = unitsys.FindCurSymbol(type);
	m_pUnitsys = &unitsys;
	
}

OutDataAttr::OutDataAttr(UnitSubSystem &unitsys,int nKey,UnitTypeID type,CString cursym,CString strName,BOOL bshow)
{
	m_nKey=nKey;
	m_UnitType=type;
	m_strName=strName;
	m_bShow=bshow;
	m_strUnit=cursym;
	m_pUnitsys=&unitsys;
}


OutDataAttr::~OutDataAttr()
{

}

int OutDataAttr::Key()
{
	return m_nKey;
}

CString OutDataAttr::Name()
{
	return m_strName;
}

CString OutDataAttr::Unit()
{
	return m_strUnit;
}
void OutDataAttr::Unit(CString strUnit)
{
	m_strUnit = strUnit;
}
UnitTypeID OutDataAttr::UnitType()
{
	return m_UnitType;
}



BOOL OutDataAttr::Show()
{
	return m_bShow;
}

void OutDataAttr::Show(BOOL bShow)
{
	m_bShow = bShow;
}

CString OutDataAttr::GetTitle()
{
	return m_strName +_T("\n(") + m_strUnit+_T(")");
	
}
CString OutDataAttr::GetAxisTitle()
{
	return m_strName +_T("(") + m_strUnit+_T(")");
}
CString OutDataAttr::TranData(CString Data)
{
	if(m_UnitType == None)
		return Data;
	double dOut = m_pUnitsys->StdToSelUnit(_tcstod( Data ,'\0'),m_strUnit);
	CString strRet;
	strRet.Format(_T("%.8f"),dOut);
	strRet.TrimRight('0');
	strRet.TrimRight('.');
	return strRet;
}
double OutDataAttr::TranData(double dData)
{
	if(m_UnitType == None)
		return dData;
	return m_pUnitsys->StdToSelUnit(dData,m_strUnit);
}
UnitSubSystem& OutDataAttr::UnitSys()
{
	ASSERT(m_pUnitsys != NULL);
	return *m_pUnitsys;
}
