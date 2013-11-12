// TableBase.cpp: implementation of the TableBase class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "TableBase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TableBase::TableBase()
{

}

TableBase::~TableBase()
{

}


RowObjectFace<2>& TableBase::UnkownData()
{
	return m_Unkown;
}


RowObjectFace<1>& TableBase::NumData()
{
	return m_Num;
}

int TableBase::Num()
{
	int iKey=0;
	m_Num.GetData(iKey);
	return abs(iKey);
}

/*------------------------------------------*/

StrArray<2> TableBase::Unkown()
{
	return m_Unkown.GetArray();
}

void TableBase::Unkown(const StrArray<2>& strValue)
{
	m_Unkown.SetArray(strValue);
}

int TableBase::GetColNum()
{
	int iKey=0;
	m_Unkown.GetData(iKey,1);
	return abs(iKey);
}

CString TableBase::GetKey()
{
	return m_Unkown.GetData();
}
