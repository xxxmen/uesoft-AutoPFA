// DeadEnd.cpp: implementation of the DeadEnd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "DeadEnd.h"
#include "DlgDeadEnd.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NameArray DeadEnd::s_StateName;
CBitmap DeadEnd::m_bitmap;
const int DeadEnd::m_nTypeID = 11;
CString DeadEnd::s_typeName;

DeadEnd::DeadEnd()
{

}

DeadEnd::~DeadEnd()
{

}

void DeadEnd::Instance()
{
	Jun::Instance(s_StateName);
	m_bitmap.LoadBitmap(IDB_DEADEND);
	s_typeName.LoadString(IDS_STRDEADEND);
}


Component* DeadEnd::CreatDeadEnd()
{
	DeadEnd *pDeadEnd = new DeadEnd;
	pDeadEnd->Init();
	pDeadEnd->SetSpecial(-1);
	return pDeadEnd;
}

ScenarioObject* DeadEnd::DoClone()
{
	return new DeadEnd(*this);
}

int DeadEnd::GetID()
{
	return m_nTypeID;
}

CString DeadEnd::GetTypeName()
{
	return s_typeName;
}

BOOL DeadEnd::Read(Junperisist *pPersistent)
{
	// TODO: Add extra Read here
	
	return Jun::Read(pPersistent);
}

BOOL DeadEnd::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra Save here

	return bRet;
}

BOOL DeadEnd::Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bReadOnly)
{
	DlgDeadEnd dlg(UnitSys,*pManager,this);
	dlg.ReadOnly(bReadOnly);
	if(IDOK == dlg.DoModal())
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void DeadEnd::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
}

void DeadEnd::SaveData()
{
	// TODO: Add extra SaveData here

   Jun::SaveData();
}

BOOL DeadEnd::CanLink(int nMaxLink,int nKey)
{
	if(nMaxLink < 1)
	{
		return TRUE;
	}
	return FALSE;
}

void DeadEnd::AddLinkPipeInfo(UINT nKey)
{

}

void DeadEnd::DelLinkPipeInfo(UINT nKey)
{

}

void DeadEnd::EmptyPipeInfo()
{

}

void DeadEnd::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_PipeID.GetCount()<1)
		ref.Add(5);
}
