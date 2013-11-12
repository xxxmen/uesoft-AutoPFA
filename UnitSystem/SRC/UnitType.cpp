// UnitType.cpp: implementation of the UnitType class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UnitType.h"
#include "Iterator.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UnitType::UnitType(CString strName,UINT nID,CString strID):m_strName(strName)
{
	m_nID = nID;
	m_strID = strID;
}

UnitType::UnitType()
{
	m_nID = 0;
}

UnitType::UnitType(const UnitType &ref)
{
	m_nID = ref.m_nID;
	m_strID = ref.m_strID;
	m_strName = ref.m_strName;
	m_strCurSymbol = ref.m_strCurSymbol;
	m_strStdSymbol = ref.m_strStdSymbol;
	m_symbolList.RemoveAll();
	CloneList(ref.m_symbolList);
}

UnitType& UnitType::operator=(const UnitType &ref)
{
	//判断自赋值
	if(this == &ref)
		return *this;
    //调用基类赋值
	//释放堆内存
	DelList();
	m_symbolList.RemoveAll();
	//重新分配堆内存
	CloneList(ref.m_symbolList);
	//赋值
   	m_nID = ref.m_nID;
	m_strID = ref.m_strID;
	m_strName = ref.m_strName;
	m_strCurSymbol = ref.m_strCurSymbol;
	m_strStdSymbol = ref.m_strStdSymbol;
	return *this;
}

UnitType::~UnitType()
{
	DelList();
}

BOOL UnitType::FilterString(CString strSymbol,BOOL bUsed)
{
	UnitString *pUnitString = NULL;
	if(FindUnitString(strSymbol,pUnitString))
	{
		pUnitString->SetUsed(bUsed);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL UnitType::FindUnitString(CString strSymbol,UnitString *pSymbol)
{
	POSITION pos = m_symbolList.GetHeadPosition();
	while(pos)
	{
		pSymbol = m_symbolList.GetNext(pos);
		if(pSymbol->IsStringEqual(strSymbol))
		{
			return TRUE;
		}
	}
	return FALSE;
}

void UnitType::AddUnitSymbol(CString strSymbol)
{
	UnitString *pUnitString = UnitString::Creat(strSymbol);
	
	ASSERT(pUnitString != NULL);
	m_symbolList.AddTail(pUnitString);
}

void UnitType::InitSymbol(vector< UeStdString > &array)
{
	vector<UeStdString>::const_iterator ItBegin = array.begin();
	for ( ;ItBegin != array.end();ItBegin++ )
	{
		AddUnitSymbol(ItBegin->c_str());
	}
}


void UnitType::GetUsedArray(SymbolArray &array)
{
	UnitString *pSymbol = NULL;
	array.RemoveAll();
	POSITION pos = m_symbolList.GetHeadPosition();
	while(pos)
	{
		pSymbol = m_symbolList.GetNext(pos);
		if(pSymbol->IsUsed())
		{
			array.Add(pSymbol->GetSymbol());
		}
	}
	
}

Iterator<UnitString>* UnitType::CreatIterator()
{
	return new ListIterator<UnitString>(&m_symbolList);
}

void UnitType::DelList()
{
	UnitString *pSymbol = NULL;
	POSITION pos = m_symbolList.GetHeadPosition();
	while(pos)
	{
		pSymbol = m_symbolList.GetNext(pos);
		delete pSymbol;
	}
}

void UnitType::CloneList(const UnitStringList &symbolList)
{
	UnitString *pSymbol = NULL;
	POSITION pos = symbolList.GetHeadPosition();
	while(pos)
	{
		pSymbol = symbolList.GetNext(pos);
		m_symbolList.AddTail(pSymbol->Clone());
	}
}
