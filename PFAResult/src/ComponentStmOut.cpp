// ComponentStmOut.cpp: implementation of the ComponentStmOut class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ComponentStmOut.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ComponentStmOut::ComponentStmOut()
{
	m_nType = 0;
}

ComponentStmOut::~ComponentStmOut()
{
}

int ComponentStmOut::Type()
{
	return m_nType;
}

void ComponentStmOut::Type(int nType)
{
	m_nType = nType;
}

void ComponentStmOut::Key(int nKey)
{
	SetValue(nKey,0);
}

int ComponentStmOut::Key()
{
	return GetnValue(0);
}

void ComponentStmOut::InitAttr(OutAttrArray &array,UnitSubSystem &unitsys,int nKey,CString strName,BOOL bShow)
{
	OutDataAttr temp(unitsys,nKey,strName,bShow);
	array.Add(temp);
}

void ComponentStmOut::InitAttr(OutAttrArray &array,UnitSubSystem &unitsys,int nKey,UnitTypeID type,CString strName,BOOL bShow)
{
	OutDataAttr temp(unitsys,nKey,type,strName,bShow);
	array.Add(temp);
}

void ComponentStmOut::InitAttr(OutAttrArray &array,UnitSubSystem &unitsys,int nKey,UnitTypeID type,CString cursym,CString strName,BOOL bShow)
{
	OutDataAttr temp(unitsys,nKey,type,cursym,strName,bShow);
	array.Add(temp);
}



void ComponentStmOut::SetValue(int nValue, int nKey)
{
	m_dataArray.Data(nValue,nKey);
}
void ComponentStmOut::SetValue(CString strValue, int nKey)
{
	m_dataArray.Data(strValue,nKey);
}
void ComponentStmOut::SetValue(double dValue, int nKey)
{
	m_dataArray.Data(dValue,nKey);
}

int ComponentStmOut::GetnValue(int nKey)
{
	return m_dataArray.nData(nKey);
}

double ComponentStmOut::GetdValue(int nKey)
{
	return m_dataArray.fData(nKey);
}

CString ComponentStmOut::GetValue(int nKey)
{
	return m_dataArray.Data(nKey);
}

double ComponentStmOut::Max(double dX1,double dX2)
{
	return max(dX1,dX2);
}
double ComponentStmOut::Min(double dX1,double dX2)
{
	return min(dX1,dX2);
}

void ComponentStmOut::Name(CString strName)
{
	m_strName = strName;
}
CString ComponentStmOut::Name()
{
	return m_strName;
}