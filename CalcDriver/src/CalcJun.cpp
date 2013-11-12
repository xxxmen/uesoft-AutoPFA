// CalcJun.cpp: implementation of the CalcJun class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcJun.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcJun::CalcJun()
{
	m_nTypeID = 0;
	m_nKey = 0;
	m_dInEle = 0;
	m_dOutEle = 0;
	m_dDesignFactor = 0;
	m_nInitGuessType = 0;
	m_dInitGuess = 0;
	m_nSpecialMark = 0;
}

CalcJun::~CalcJun()
{

}

ostream& operator<< (ostream &CalcOut,CalcJun &ref)
{
	return ref.Write(CalcOut);
}


//ostream& CalcJun::WriteJun(ostream &CalcOut)
//{
//	CalcOut<<m_nTypeID<<s_Separator
//		   <<m_nKey<<s_Separator
//		   <<m_dInEle<<s_Separator
//		   <<m_dOutEle<<s_Separator
//		   <<m_PipeID;
//	return CalcOut;
//}
//
//ostream& CalcJun::WriteOption(ostream &CalcOut)
//{
//	CalcOut<<m_nSpecialMark<<s_Separator
//		   <<m_nInitGuessType<<s_Separator
//		   <<m_dInitGuess<<s_Separator
//		   <<m_dDesignFactor<<s_Separator;
//	return CalcOut;
//}

void CalcJun::PipeID(ListImp<StrArray<1> >& list)
{
	m_PipeID.SetData(list);
}

ListImp<StrArray<1> >& CalcJun::PipeID()
{
	return m_PipeID.GetData();
}

void CalcJun::CurveData(const ListImp<StrArray<2> >& ref)
{
	m_CurveData.SetData(ref);
}
ListImp<StrArray<2> >& CalcJun::CurveData()
{
	return m_CurveData.GetData();
}
void CalcJun::Name(CString strName)
{
	m_strName = strName;
}
/*------------------------------------------------*/
void CalcJun::ID(int nValue)
{
	m_nTypeID = nValue;
}
/*------------------------------------------------*/
void CalcJun::Key(int nValue)
{
	m_nKey = nValue;
}
/*------------------------------------------------*/
void CalcJun::InEle(double dValue)
{
	m_dInEle = dValue;
}
/*------------------------------------------------*/
void CalcJun::OutEle(double dValue)
{
	m_dOutEle = dValue;
}
/*------------------------------------------------*/
void CalcJun::DesignFactor(double dValue)
{
	m_dDesignFactor = dValue;
}
/*------------------------------------------------*/
void CalcJun::InitGuessType(int nValue)
{
	m_nInitGuessType = nValue;
}
/*------------------------------------------------*/
void CalcJun::InitGuess(double dValue)
{
	m_dInitGuess = dValue;
}
/*------------------------------------------------*/
void CalcJun::SpecialMark(int nValue)
{
	m_nSpecialMark = nValue;
}


//////////////////////////////////////////////////////////
CString CalcJun::Name()
{
	return m_strName;
}
/*------------------------------------------------*/
int CalcJun::ID()
{
	return m_nTypeID;
}
/*------------------------------------------------*/
int CalcJun::Key()
{
	return m_nKey;
}
/*------------------------------------------------*/
double CalcJun::InEle()
{
	return m_dInEle;
}
/*------------------------------------------------*/
double CalcJun::OutEle()
{
	return m_dOutEle;
}
/*------------------------------------------------*/
double CalcJun::DesignFactor()
{
	return m_dDesignFactor;
}
/*------------------------------------------------*/
int CalcJun::InitGuessType()
{
	return m_nInitGuessType;
}
/*------------------------------------------------*/
double CalcJun::InitGuess()
{
	return m_dInitGuess;
}
/*------------------------------------------------*/
int CalcJun::SpecialMark()
{
	return m_nSpecialMark;
}