// OutPutRefItem.cpp: implementation of the OutPutRefItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OutPutRefItem.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OutPutRefItem::OutPutRefItem()
{

}

OutPutRefItem::~OutPutRefItem()
{

}

BOOL OutPutRefItem::Read(CStdioFile &file)
{
	CString strTemp;
	file.ReadString(strTemp);
	//AfxMessageBox(strTemp);

	InitDataOrder(strTemp);
	file.ReadString(strTemp);
	
	//AfxMessageBox(strTemp);
	
	InitUnitOrder(strTemp);
	return TRUE;

}

void OutPutRefItem::InitDataOrder(CString InData)
{
	m_DataOrder.InitRow(InData);
}

void OutPutRefItem::InitUnitOrder(CString InData)
{
	m_UnitOrder.InitRow(InData);
}

CString OutPutRefItem::GetDataOrder()
{
	CString strTemp;
	strTemp=m_DataOrder.Save();
	strTemp=m_DataOrder.Read(strTemp,'=');
	return strTemp;

}

CString OutPutRefItem::GetUnitOrder()
{

	CString strTemp;
	strTemp=m_UnitOrder.Save();
	strTemp= m_UnitOrder.Read(strTemp,'=');
	return strTemp;
}

void OutPutRefItem::SetDataOrder(CString StrValue)
{
	m_DataOrder.InitRow(StrValue);
}

void OutPutRefItem::SetUnitOrder(CString StrValue)
{
	m_UnitOrder.InitRow(StrValue);
}