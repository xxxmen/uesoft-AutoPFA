// CalcPump.cpp: implementation of the CalcPump class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcPump.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcPump::CalcPump()
{
	m_dNPRS = 0;			
	m_bSelViscosCor = 0;		
    m_nBEFType = 0;			
	m_dBEFFlow = 0;			
	m_bAntiReverse = 0;		
	m_bExitCheck = 0;		
	m_dCloseVel = 0;
	m_nReOpenPressType = 0;
	m_dReOpenPress = 0;			  	
	m_bSelSubmerge = 0;       
	m_nSubmergePressType = 0;
	m_dSuctionPress = 0;	
	m_nPumpSet = 0;			
	m_nTranModel = 0;		
	m_nPumpType = 0;	
	m_dPumpFlow = 0;	
	m_dSpeedRatio = 0;		
	m_nPumpControl = 0;		
	m_nControlType = 0;	
	m_nPressType = 0;	
	m_dControlValue = 0;		
	m_nControlApply = 0;        
	m_dRotateInertia = 0;		
	m_dSpeed = 0;			
	m_nFourQuadrantAngle = 0;  
}

CalcPump::~CalcPump()
{

}

CalcJun* CalcPump::Creator()
{
	CalcPump *pData = new CalcPump;
	return pData;
}

ostream& CalcPump::Write(ostream &CalcOut)
{
	CalcOut<<m_nKey<<s_Separator
		   <<m_nTypeID<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<m_dOutEle<<s_Separator
		   <<m_dNPRS<<s_Separator
		   <<m_PipeID<<s_Separator
	       <<m_nSpecialMark<<s_Separator
		   <<m_nInitGuessType<<s_Separator
		   <<m_dInitGuess<<s_Separator
		   <<m_dDesignFactor<<s_Separator
		   <<abs(m_bSelViscosCor)<<s_Separator
		   <<m_nBEFType<<s_Separator
		   <<m_dBEFFlow<<s_Separator
		   <<abs(m_bAntiReverse)<<s_Separator
		   <<abs(m_bExitCheck)<<s_Separator
		   <<m_dCloseVel<<s_Separator
		   <<m_nReOpenPressType<<s_Separator
		   <<m_dReOpenPress<<s_Separator
		   <<abs(m_bSelSubmerge)<<s_Separator
		   <<m_nSubmergePressType<<s_Separator
		   <<m_dSuctionPress<<s_Separator
		   <<m_nPumpSet<<s_Separator
		   <<m_nPumpType<<s_Separator
		   <<m_dPumpFlow<<s_Separator
		   <<m_Config
		   <<m_dSpeedRatio*100<<s_Separator
		   <<m_nPumpControl<<s_Separator
		   <<m_dControlValue<<s_Separator
		   <<m_nPressType<<s_Separator
		   <<m_nControlApply<<s_Separator
		   <<m_nTranModel<<s_Separator
		   <<m_dRotateInertia<<s_Separator
		   <<m_dSpeed<<s_Separator
		   <<m_nFourQuadrantAngle<<s_Separator
		   <<m_FourQuadrantData
		   //<<m_TranData
		   <<endl;
	return CalcOut;
}

void CalcPump::FourQuadrantData(const ListImp<StrArray<3> >& ref)
{
	m_FourQuadrantData.SetData(ref);
}

/*------------------------------------------------*/
void CalcPump::AntiReverse(int nValue)
{
	m_bAntiReverse = nValue;
}
/*------------------------------------------------*/
void CalcPump::ExitCheck(int nValue)
{
	m_bExitCheck = nValue;
}
/*------------------------------------------------*/
void CalcPump::CloseVel(double dValue)
{
	m_dCloseVel = dValue;
}
/*------------------------------------------------*/
void CalcPump::PressType(int nValue)
{
	m_nPressType = nValue;
}
/*------------------------------------------------*/
void CalcPump::SelSubmerge(int nValue)
{
	m_bSelSubmerge = nValue;
}
/*------------------------------------------------*/
void CalcPump::SubmergePressType(int nValue)
{
	m_nSubmergePressType = nValue;
}
/*------------------------------------------------*/
void CalcPump::SuctionPress(double dValue)
{
	m_dSuctionPress = dValue;
}
/*------------------------------------------------*/
void CalcPump::PumpSet(int nValue)
{
	if(nValue == 0)
		nValue = 1;
	m_nPumpSet = nValue;
}
/*------------------------------------------------*/
void CalcPump::TranModel(int nValue)
{
	m_nTranModel = nValue;
}
/*------------------------------------------------*/
void CalcPump::PumpType(int nValue)
{
	m_nPumpType = nValue;
}
/*------------------------------------------------*/
void CalcPump::PumpFlow(double dValue)
{
	m_dPumpFlow = dValue;
}
/*------------------------------------------------*/
void CalcPump::SpeedRatio(double dValue)
{
	m_dSpeedRatio = dValue;
}
/*------------------------------------------------*/
void CalcPump::PumpControl(int nValue)
{
	m_nPumpControl = nValue;
}
/*------------------------------------------------*/
void CalcPump::ControlType(int nValue)
{
	m_nControlType = nValue;
}
/*------------------------------------------------*/
void CalcPump::ControlValue(double dValue)
{
	m_dControlValue = dValue;
}
/*------------------------------------------------*/
void CalcPump::ControlApply(int nValue)
{
	m_nControlApply = nValue;
}
/*------------------------------------------------*/
void CalcPump::ReOpenPressType(int nValue)
{
	m_nReOpenPressType = nValue;
}
/*------------------------------------------------*/
void CalcPump::ReOpenPress(double dValue)
{
	m_dReOpenPress = dValue;
}
/*------------------------------------------------*/
void CalcPump::RotateInertia(double dValue)
{
	m_dRotateInertia = dValue;
}
/*------------------------------------------------*/
void CalcPump::Speed(double dValue)
{
	m_dSpeed = dValue;
}
/*------------------------------------------------*/
void CalcPump::FourQuadrantAngle(int nValue)
{
	m_nFourQuadrantAngle = nValue;
}


//////////////////////////////////////////////////////////
ListImp<StrArray<2> > CalcPump::FHData()
{
	ListImp<StrArray<3> > &list1 = m_FourQuadrantData.GetData();
	ListImp<StrArray<2> > list2;
	ListImp<StrArray<1> > list3;
	Divided<2,1>(list2,list3,list1);
	return list2;
}

ListImp<StrArray<2> > CalcPump::FBData()
{
	ListImp<StrArray<3> > &list1 = m_FourQuadrantData.GetData();
	ListImp<StrArray<1> > list2;
	ListImp<StrArray<2> > list3;
	ListImp<StrArray<1> > list4;
	ListImp<StrArray<1> > list5;
	Divided<1,2>(list2,list3,list1);
	Divided<1,1>(list4,list5,list3);
	return Combi<1,1>(list2,list5);
}

/*------------------------------------------------*/
int CalcPump::AntiReverse()
{
	return abs(m_bAntiReverse);
}
/*------------------------------------------------*/
int CalcPump::ExitCheck()
{
	return abs(m_bExitCheck);
}
/*------------------------------------------------*/
double CalcPump::CloseVel()
{
	return m_dCloseVel;
}
/*------------------------------------------------*/
int CalcPump::PressType()
{
	return m_nPressType;
}
/*------------------------------------------------*/
int CalcPump::SelSubmerge()
{
	return abs(m_bSelSubmerge);
}
/*------------------------------------------------*/
int CalcPump::SubmergePressType()
{
	return m_nSubmergePressType;
}
/*------------------------------------------------*/
double CalcPump::SuctionPress()
{
	return m_dSuctionPress;
}
/*------------------------------------------------*/
int CalcPump::PumpSet()
{
	return m_nPumpSet;
}
/*------------------------------------------------*/
int CalcPump::TranModel()
{
	return m_nTranModel;
}
/*------------------------------------------------*/
int CalcPump::PumpType()
{
	return m_nPumpType;
}
/*------------------------------------------------*/
double CalcPump::PumpFlow()
{
	return m_dPumpFlow;
}
/*------------------------------------------------*/
double CalcPump::SpeedRatio()
{
	return m_dSpeedRatio;
}
/*------------------------------------------------*/
int CalcPump::PumpControl()
{
	return m_nPumpControl;
}
/*------------------------------------------------*/
int CalcPump::ControlType()
{
	return m_nControlType;
}
/*------------------------------------------------*/
double CalcPump::ControlValue()
{
	return m_dControlValue;
}
/*------------------------------------------------*/
int CalcPump::ControlApply()
{
	return m_nControlApply;
}
/*------------------------------------------------*/
int CalcPump::ReOpenPressType()
{
	return m_nReOpenPressType;
}
/*------------------------------------------------*/
double CalcPump::ReOpenPress()
{
	return m_dReOpenPress;
}
/*------------------------------------------------*/
double CalcPump::RotateInertia()
{
	return m_dRotateInertia;
}
/*------------------------------------------------*/
double CalcPump::Speed()
{
	return m_dSpeed;
}
/*------------------------------------------------*/
int CalcPump::FourQuadrantAngle()
{
	return m_nFourQuadrantAngle;
}