// PipeTranOut.cpp: implementation of the PipeTranOut class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PipeTranOut.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PipeTranOut::PipeTranOut()
{

}

PipeTranOut::~PipeTranOut()
{
	m_list.DelList();
}

StationOut* PipeTranOut::Creator(int nStep)
{
	StationOut *pOut = new StationOut;
	pOut->Step(nStep);
	m_list.AddItem(pOut);
	return pOut;
}
ComponentStmOut* PipeTranOut::CreatorOut(int nKey)
{
	ComponentStmOut *pOut = new ComponentStmOut;
	pOut->Key(Key());
	pOut->SetValue(nKey,29);
	m_MaxMinStation.AddItem(pOut);
	return pOut;
}
ComponentStmOut* PipeTranOut::LookUpMaxMin(int nKey)
{
	ComponentStmOut *pOut = NULL;
	IteratorPtr<ComponentStmOut> ItPtr(m_MaxMinStation.CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pOut = &ItPtr->CurrentItem();
		ASSERT(pOut != NULL);
		if(pOut->GetnValue(29)==nKey)
			return pOut;
	}
	return NULL;
}
Iterator<StationOut>* PipeTranOut::CreatIterator()
{
	return m_list.CreatIterator();
}

void PipeTranOut::Instance(OutAttrArray &array,UnitSubSystem &unitsys)
{
	StationOut::Instance(array,unitsys);
}
void PipeTranOut::InstanceStationMaxMin(OutAttrArray &array,UnitSubSystem &unitsys)
{
	ComponentStmOut::InitAttr(array,unitsys,0,_T("管道"));
	ComponentStmOut::InitAttr(array,unitsys,29,_T("位置"));
	PipeTranOut::InstanceMaxMin(array,unitsys);
}
void PipeTranOut::InstancePipeMaxMin(OutAttrArray &array,UnitSubSystem &unitsys)
{
	ComponentStmOut::InitAttr(array,unitsys,0,_T("管道"));
	PipeTranOut::InstanceMaxMin(array,unitsys);
}
void PipeTranOut::InstanceMaxMin(OutAttrArray &array,UnitSubSystem &unitsys)
{
	ComponentStmOut::InitAttr(array,unitsys,1,Pressure,_T("最大滞止压力"));
	ComponentStmOut::InitAttr(array,unitsys,2,Time,_T("最大滞止压力时间"));
	ComponentStmOut::InitAttr(array,unitsys,3,Pressure,_T("最小滞止压力"));
	ComponentStmOut::InitAttr(array,unitsys,4,Time,_T("最小滞止压力时间"));

	ComponentStmOut::InitAttr(array,unitsys,5,Length,_T("最大EGL"));
	ComponentStmOut::InitAttr(array,unitsys,6,Time,_T("最大EGL时间"));
	ComponentStmOut::InitAttr(array,unitsys,7,Length,_T("最小EGL"));
	ComponentStmOut::InitAttr(array,unitsys,8,Time,_T("最小EGL时间"));

	ComponentStmOut::InitAttr(array,unitsys,9,MassFlow,_T("最大质量流量"));
	ComponentStmOut::InitAttr(array,unitsys,10,Time,_T("最大质量流量时间"));
	ComponentStmOut::InitAttr(array,unitsys,11,MassFlow,_T("最小质量流量"));
	ComponentStmOut::InitAttr(array,unitsys,12,Time,_T("最小质量流量时间"));

	ComponentStmOut::InitAttr(array,unitsys,13,VolumetricFlow,_T("最大体积流量"));
	ComponentStmOut::InitAttr(array,unitsys,14,Time,_T("最大体积流量时间"));
	ComponentStmOut::InitAttr(array,unitsys,15,VolumetricFlow,_T("最小体积流量"));
	ComponentStmOut::InitAttr(array,unitsys,16,Time,_T("最小体积流量时间"));

	ComponentStmOut::InitAttr(array,unitsys,17,Velocity,_T("最大流速"));
	ComponentStmOut::InitAttr(array,unitsys,18,Time,_T("最大流速时间"));
	ComponentStmOut::InitAttr(array,unitsys,19,Velocity,_T("最小流速"));
	ComponentStmOut::InitAttr(array,unitsys,20,Time,_T("最小流速时间"));

	ComponentStmOut::InitAttr(array,unitsys,21,Pressure,_T("最大静态压力"));
	ComponentStmOut::InitAttr(array,unitsys,22,Time,_T("最大静态压力时间"));
	ComponentStmOut::InitAttr(array,unitsys,23,Pressure,_T("最小静态压力"));
	ComponentStmOut::InitAttr(array,unitsys,24,Time,_T("最小静态压力时间"));

	ComponentStmOut::InitAttr(array,unitsys,25,Length,_T("最大HGL"));
	ComponentStmOut::InitAttr(array,unitsys,26,Time,_T("最大HGL时间"));
	ComponentStmOut::InitAttr(array,unitsys,27,Length,_T("最小HGL"));
	ComponentStmOut::InitAttr(array,unitsys,28,Time,_T("最小HGL时间"));

}
void PipeTranOut::InitMaxMin(double dTime)
{
	InitStationMaxMin(dTime);
	InitPipeMaxMin();
}
void PipeTranOut::InitStationMaxMin(double dTime)
{
	StationOut *pStation = NULL;
	ComponentStmOut *pMaxMin = NULL;
	IteratorPtr<StationOut> ItPtr(m_list.CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		if(pStation == NULL)
		{
			pStation = &ItPtr->CurrentItem();
			m_MaxMinStation.DelList();
			pStation->InitMaxMinOut(*this);
		}
		else
		{
			pStation = &ItPtr->CurrentItem();
		}
		ASSERT(pStation != NULL);
		pStation->InitMaxMin(*this,dTime);
	}
}
void PipeTranOut::InitPipeMaxMin()
{
	ComponentStmOut *pStmOut = NULL;
	IteratorPtr<ComponentStmOut> iteratorPtr(CreatMaxMinIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		if(pStmOut == NULL)
		{
			pStmOut = &iteratorPtr->CurrentItem();
			ASSERT(pStmOut != NULL);
			SetAllMaxMinData(pStmOut);
		}
		else
		{
			pStmOut = &iteratorPtr->CurrentItem();
			ASSERT(pStmOut != NULL);
			UpDataAllMaxMinData(pStmOut);
		}	
	}
}

void PipeTranOut::SetMaxMinData(ComponentStmOut *pStmOut,int nIndex)
{
	SetValue(pStmOut->GetValue(nIndex),nIndex);
}

void PipeTranOut::SetAllMaxMinData(ComponentStmOut *pStmOut)
{
	for(int i=1;i<29;i++)
	{
		SetMaxMinData(pStmOut,i);
	}
}

void PipeTranOut::UpDataMaxMinData(ComponentStmOut *pStmOut,int nIndex)
{
	double dValue1 = pStmOut->GetdValue(nIndex*4-3);
	double dValue2 = pStmOut->GetdValue(nIndex*4-1);
	double dMaxValue = GetdValue(nIndex*4-3);
	double dMinValue = GetdValue(nIndex*4-1);
	if(dValue1 > dMaxValue)
	{
		SetValue(dValue1,nIndex*4-3);
		SetValue(pStmOut->GetValue(nIndex*4-2),nIndex*4-2);
	}
	if(dMinValue > dValue2)
	{
		SetValue(dValue2,nIndex*4-1);
		SetValue(pStmOut->GetValue(nIndex*4),nIndex*4);
	}	
}

void PipeTranOut::UpDataAllMaxMinData(ComponentStmOut *pStmOut)
{
	for(int i=1;i<8;i++)
	{
		UpDataMaxMinData(pStmOut,i);
	}
}

StationOut* PipeTranOut::GetStationOut()
{
	return m_list.GetHead();
}

void PipeTranOut::GetArrayData(double dArray[], int nKey, OutDataAttr &attr)
{
	m_list.ToDuoble(dArray,nKey,attr.Key());
	for(int i=0;i<GetArrayNum();i++)
	{
		dArray[i] = attr.TranData(dArray[i]);
	}
}

int PipeTranOut::GetArrayNum()
{
	return m_list.GetCount();
}
