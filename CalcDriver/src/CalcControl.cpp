// CalcControl.cpp: implementation of the CalcControl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcControl.h"

CalcControl::CalcControl()
{
	m_nType = 0;							
	m_nAlwayControl = 0;					
	m_nUpInsuffic = 0;							
	m_nDownExcess = 0;						
    m_nControlType = 0;					     
	m_nPressType = 0;						
	m_dControlValue = 0;					
	m_nLossType = 0;					
	m_dKOrCv = 0;	
	m_nBasisAreaType = 0;
	m_dBasisArea = 0;
}

CalcControl::~CalcControl()
{

}
CalcJun* CalcControl::Creator()
{
	CalcControl *pData = new CalcControl;
	return pData;
}

ostream& CalcControl::Write(ostream &CalcOut)
{
	CalcOut<<m_nKey<<s_Separator
		   <<m_nTypeID<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<m_dOutEle<<s_Separator
		   <<m_PipeID<<s_Separator
	       <<m_nSpecialMark<<s_Separator
		   <<m_nInitGuessType<<s_Separator
		   <<m_dInitGuess<<s_Separator
		   <<m_dDesignFactor<<s_Separator
		   <<m_nType<<s_Separator
		   <<m_nAlwayControl<<s_Separator
		   <<m_nUpInsuffic<<s_Separator
		   <<m_nDownExcess<<s_Separator
		   <<m_nControlType<<s_Separator
		   <<m_nPressType<<s_Separator
		   <<m_dControlValue<<s_Separator
		   <<m_nLossType<<s_Separator;
		   if(m_nLossType == -2)
		   {
			   CalcOut<<m_CvTable;
		   }
		   else
		   {
				CalcOut<<m_dKOrCv<<s_Separator;
		   }
//		   <<m_FailTranData.ValueType()<<s_Separator
//		   <<m_FailTranData.m_TranData1
//		   <<m_FailTranData.m_TranData2
    CalcOut<<m_nBasisAreaType<<s_Separator
		   <<m_dBasisArea<<s_Separator
//		   <<m_TranData
		   <<endl;
	return CalcOut;
}

/*------------------------------------------------*/
void CalcControl::Type(int nValue)
{
	m_nType = nValue;
}
/*------------------------------------------------*/
void CalcControl::AlwayControl(int nValue)
{
	m_nAlwayControl = nValue;
}
/*------------------------------------------------*/
void CalcControl::UpInsuffic(int nValue)
{
	m_nUpInsuffic = nValue;
}
/*------------------------------------------------*/
void CalcControl::DownExcess(int nValue)
{
	m_nDownExcess = nValue;
}
/*------------------------------------------------*/
void CalcControl::ControlType(int nValue)
{
	m_nControlType = nValue;
}
/*------------------------------------------------*/
void CalcControl::PressType(int nValue)
{
	m_nPressType = nValue;
}
/*------------------------------------------------*/
void CalcControl::ControlValue(double dValue)
{
	m_dControlValue = dValue;
}
/*------------------------------------------------*/
void CalcControl::LossType(int nValue)
{
	m_nLossType = nValue;
}
/*------------------------------------------------*/
void CalcControl::KOrCv(double dValue)
{
	m_dKOrCv = dValue;
}

void CalcControl::CvTable(const ListImp<StrArray<3> >& ref)
{
	m_CvTable.SetData(ref);
}

/*------------------------------------------------*/
void CalcControl::BasisAreaType(int nValue)
{
	m_nBasisAreaType = nValue;
}
/*------------------------------------------------*/
void CalcControl::BasisArea(double dValue)
{
	m_dBasisArea = dValue;
}

/////////////////////////////////////////////////////////////////
/*------------------------------------------------*/
int CalcControl::Type()
{
	return m_nType;
}
/*------------------------------------------------*/
int CalcControl::AlwayControl()
{
	return m_nAlwayControl;
}
/*------------------------------------------------*/
int CalcControl::UpInsuffic()
{
	return m_nUpInsuffic;
}
/*------------------------------------------------*/
int CalcControl::DownExcess()
{
	return m_nDownExcess;
}
/*------------------------------------------------*/
int CalcControl::ControlType()
{
	return m_nControlType;
}
/*------------------------------------------------*/
int CalcControl::PressType()
{
	return m_nPressType;
}
/*------------------------------------------------*/
double CalcControl::ControlValue()
{
	return m_dControlValue;
}
/*------------------------------------------------*/
int CalcControl::LossType()
{
	return m_nLossType;
}
/*------------------------------------------------*/
double CalcControl::KOrCv()
{
	return m_dKOrCv;
}

ListImp<StrArray<3> >& CalcControl::CvTable()
{
	return m_CvTable.GetData();
}

/*------------------------------------------------*/
int CalcControl::BasisAreaType()
{
	return m_nBasisAreaType;
}
/*------------------------------------------------*/
double CalcControl::BasisArea()
{
	return m_dBasisArea;
}