// StationStmOut.cpp: implementation of the StationStmOut class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StationStmOut.h"
#include "StationOut.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StationStmOut::StationStmOut()
{

}

StationStmOut::~StationStmOut()
{

}

void StationStmOut::Instance(OutAttrArray &array,UnitSubSystem &unitsys)
{
	ComponentStmOut::InitAttr(array,unitsys,0,_T("管道"));
	ComponentStmOut::InitAttr(array,unitsys,29,_T("位置"));
	ComponentStmOut::InitAttr(array,unitsys,1,Pressure,_T("滞止压力"));//
	ComponentStmOut::InitAttr(array,unitsys,2,Length,_T("EGL"));//
	ComponentStmOut::InitAttr(array,unitsys,3,MassFlow,_T("质量流量"));// 
	ComponentStmOut::InitAttr(array,unitsys,4,VolumetricFlow,_T("体积流量"));//
	ComponentStmOut::InitAttr(array,unitsys,5,Velocity,_T("流速"));//
	ComponentStmOut::InitAttr(array,unitsys,6,Pressure,_T("静态压力"));//
	ComponentStmOut::InitAttr(array,unitsys,7,Length,_T("HGL"));//
	ComponentStmOut::InitAttr(array,unitsys,8,Time,_T("时间"));
	ComponentStmOut::InitAttr(array,unitsys,9,Volume,_T("气穴体积"));//
	
}

/*----------------------------------------------*/
void StationStmOut::SetMassFlow(double dValue)
{
	SetValue(dValue,3);
}

/*----------------------------------------------*/
void StationStmOut::SetVolumeFlow(double dValue)
{
	SetValue(dValue,4);
}

/*----------------------------------------------*/
void StationStmOut::SetVelocity(double dValue)
{
	SetValue(dValue,5);
}

/*----------------------------------------------*/
void StationStmOut::SetStagPress(double dValue)
{
	SetValue(dValue,1);
}

/*----------------------------------------------*/
void StationStmOut::SetStaticPress(double dValue)
{
	SetValue(dValue,6);
}


/*----------------------------------------------*/
void StationStmOut::SetEGL(double dValue)
{
	SetValue(dValue,2);
}

/*----------------------------------------------*/
void StationStmOut::SetHGL(double dValue)
{
	SetValue(dValue,7);
}
/*----------------------------------------------*/
void StationStmOut::SetTime(double dValue)
{
	SetValue(dValue,8);
}
void StationStmOut::SetVopor(double dValue)
{
	SetValue(dValue,9);
}
void StationStmOut::InitMaxMin(ComponentStmOut &out,double dTime,int nStep)
{
	if(nStep == 0)
	{
		out.SetValue(this->GetnValue(29),29);//在StationStmOut类中Key()只是管子的Key。在这里取位置作为关键字。
		SetAllData(out,dTime,nStep);
	}
	else
	{
		UpDataAllData(out,dTime,nStep);
	}
	SetTime(dTime*nStep);
}


void StationStmOut::SetData(ComponentStmOut &out,double dTime,int nStep,int nIndex)
{
	double dValue = GetdValue(nIndex);
	out.SetValue(dValue,nIndex*4-3);
	out.SetValue(dTime*nStep,nIndex*4-2);
	out.SetValue(dValue,nIndex*4-1);
	out.SetValue(dTime*nStep,nIndex*4);	
}

void StationStmOut::SetAllData(ComponentStmOut &out,double dTime,int nStep)
{
	for(int i=1;i<8;i++)
	{
		SetData(out,dTime,nStep,i);
	}
}

void StationStmOut::UpDataData(ComponentStmOut &out,double dTime,int nStep,int nIndex)
{
	double dValue = GetdValue(nIndex);
	double dMaxValue = out.GetdValue(nIndex*4-3);
	double dMinValue = out.GetdValue(nIndex*4-1);
	if(dValue > dMaxValue)
	{
		out.SetValue(dValue,nIndex*4-3);
		out.SetValue(dTime*nStep,nIndex*4-2);
	}
	if(dMinValue > dValue)
	{
		out.SetValue(dValue,nIndex*4-1);
		out.SetValue(dTime*nStep,nIndex*4);
	}	
}

void StationStmOut::UpDataAllData(ComponentStmOut &out,double dTime,int nStep)
{
	for(int i=1;i<8;i++)
	{
		UpDataData(out,dTime,nStep,i);
	}
}