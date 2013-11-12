// StationOut.cpp: implementation of the StationOut class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StationOut.h"
#include "PipeTranOut.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StationOut::StationOut()
{

}

StationOut::~StationOut()
{

}

StationStmOut* StationOut::Creator(int nKey)
{
	StationStmOut *pOut = new StationStmOut;
	pOut->Key(nKey);
	m_list.AddItem(pOut);
	return pOut;
}

void StationOut::Instance(OutAttrArray &array,UnitSubSystem &unitsys)
{
	StationStmOut::Instance(array,unitsys);
}

void StationOut::Step(int nStep)
{
	m_nStep = nStep;
}

int StationOut::Step()
{
	return m_nStep;
}
Iterator<StationStmOut>* StationOut::CreatIterator()
{
	return m_list.CreatIterator();
}
StationStmOut* StationOut::LookUp(int nKey)
{
	StationStmOut *pStation = NULL;
	IteratorPtr<StationStmOut> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pStation = &ItPtr->CurrentItem();
		ASSERT(pStation != NULL);
		if(pStation->GetnValue(29)==nKey)//在StationStmOut类中Key()只是管子的Key。在这里取位置作为关键字。
			return pStation;
	}
	return NULL;
}

double StationOut::GetValve(int nKey,int nSubKey)
{
	StationStmOut *pStation = LookUp(nKey);
	if(pStation != NULL)
	{
		return pStation->GetdValue(nSubKey);
	}
	else
	{
		ASSERT(FALSE);
		return 0;
	}
}

void StationOut::InitMaxMin(PipeTranOut& out,double dTime)
{
	StationStmOut *pStation = NULL;
	ComponentStmOut *pOut = NULL;
	IteratorPtr<StationStmOut> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pStation = &ItPtr->CurrentItem();
		ASSERT(pStation != NULL);
//		pOut = out.LookUpMaxMin(pStation->Key()); chage by wenzk
		pOut = out.LookUpMaxMin(pStation->GetnValue(29));//在StationStmOut类中Key()只是管子的Key。在这里取位置作为关键字。
		ASSERT(pOut != NULL);
		pStation->InitMaxMin(*pOut,dTime,m_nStep);
	}
}


void StationOut::InitMaxMinOut(PipeTranOut& out)
{
	StationStmOut *pStation = NULL;
	IteratorPtr<StationStmOut> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pStation = &ItPtr->CurrentItem();
		ASSERT(pStation != NULL);
//		out.CreatorOut(pStation->Key());
		out.CreatorOut(pStation->GetnValue(29));//在StationStmOut类中Key()只是管子的Key。在这里取位置作为关键字。
		
	}
}

double StationOut::Data(int nKey, int nSubKey)
{
	StationStmOut *pOut = LookUp(nKey);
	ASSERT(pOut != NULL);
	return pOut->GetdValue(nSubKey);
}
