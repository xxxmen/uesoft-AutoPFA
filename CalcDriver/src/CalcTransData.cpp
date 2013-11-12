// CalcTransData.cpp: implementation of the CalcTransData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcTransData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcTransData::CalcTransData()
{
	m_nValueType = 0;		
	m_bSpecial = 0;			
	m_bRepeat1 = 0;				
	m_bRepeat2 = 0;			
	m_nTranType = 0;
}

CalcTransData::~CalcTransData()
{

}

ostream& operator<< (ostream &CalcOut,CalcTransData &ref)
{
	CalcOut<<ref.m_nValueType<<s_Separator
		   <<ref.m_bSpecial<<s_Separator
		   <<ref.m_bRepeat1<<s_Separator
		   <<ref.m_bRepeat2<<s_Separator
		   <<ref.m_nTranType<<s_Separator
		   <<ref.m_Triger1<<s_Separator
		   <<ref.m_Triger2<<s_Separator
		   <<ref.m_TranData1<<s_Separator
		   <<ref.m_TranData2<<s_Separator;
	return CalcOut;
}

int CalcTransData::ValueType()
{
	return m_nValueType;
}

BOOL CalcTransData::Special()
{
	if(m_bSpecial == 0)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

BOOL CalcTransData::Repeat1()
{
	if(m_bRepeat1 == 0)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}
BOOL CalcTransData::Repeat2()
{
	if(m_bRepeat2 == 0)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}
int CalcTransData::TranType()
{
	return m_nTranType;
}
void CalcTransData::ValueType(int nValue)
{
	m_nValueType = nValue;
}
void CalcTransData::Special(int nValue)
{
	m_bSpecial = abs(nValue);
}
void CalcTransData::Repeat1(int nValue)
{
	m_bRepeat1 = abs(nValue);
}
void CalcTransData::Repeat2(int nValue)
{
	m_bRepeat2 = abs(nValue);
}
void CalcTransData::TranType(int nValue)
{
	m_nTranType = nValue;
}