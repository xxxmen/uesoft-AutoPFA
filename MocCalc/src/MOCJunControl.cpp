// MOCJunControl.cpp: implementation of the MOCJunControl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCJunControl.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCJunControl::MOCJunControl()
{
	m_nPumpControl = 0;		
	m_nPressType = 0;	
	m_nControlApply = 0;   
}

MOCJunControl::~MOCJunControl()
{

}

//控制泵计算
void MOCJunControl::CalcStm(EndListRef &jun,double dControlValue,int nSet)
{
	switch(m_nPumpControl) {
	case 1:
	case 2:
		OutPressControl(jun,dControlValue);
		break;
	case 3:
	case 4:	
		InPressControl(jun,dControlValue);
		break;
	case 5:
	case 6:
		FlowControl(jun,dControlValue,nSet);
		break;
	default:
		ASSERT(FALSE);
		break;
	}
}

void MOCJunControl::PressControl(EndListRef &jun,EndInfo *pEnd,double dControlValue)
{
	ASSERT(pEnd != NULL);
	if(0==m_nPressType)
	{
		jun.StagPressStrategy(*pEnd,dControlValue);
	}
	else
	{
		jun.StaticPressStrategy(*pEnd,dControlValue);
	}
}

//入口压力水头控制
void MOCJunControl::InPressControl(EndListRef &jun,double dControlValue)
{
	EndInfo *pEnd = jun.GetInEnd();
	ASSERT(pEnd != NULL);
	PressControl(jun,pEnd,dControlValue);
	double dMassFlow = pEnd->GetMass();
	pEnd = jun.GetOutEnd();
	if(pEnd != NULL)
		FlowControl(jun,pEnd,dMassFlow);
}

//出口压力水头控制
void MOCJunControl::OutPressControl(EndListRef &jun,double dControlValue)
{
	EndInfo *pEnd = jun.GetOutEnd();
	ASSERT(pEnd != NULL);
	PressControl(jun,pEnd,dControlValue);
	double dMassFlow = pEnd->GetMass();
	pEnd = jun.GetInEnd();
	if(pEnd != NULL)
		FlowControl(jun,pEnd,dMassFlow);
}

//指定流量和流量控制泵
void MOCJunControl::FlowControl(EndListRef &jun,double dControlValue,int nSet)
{
	if(nSet > 0)//并联泵
		dControlValue = dControlValue * nSet;
	jun.FlowStrategy(dControlValue);
}

void MOCJunControl::FlowControl(EndListRef &jun,EndInfo *pEnd,double dFlow)
{
	jun.FlowStrategy(*pEnd,dFlow);
}