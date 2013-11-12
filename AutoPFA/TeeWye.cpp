// TeeWye.cpp: implementation of the TeeWye class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "TeeWye.h"
#include "DlgTeeWye.h"
#include "teewyeperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NameArray TeeWye::s_StateName;
CBitmap TeeWye::m_bitmap;
const int TeeWye::m_nTypeID = 7;
CString TeeWye::s_typeName;

StrFlyWeight TeeWye::ms_Type;					
StrFlyWeight TeeWye::ms_Angle;		
StrFlyWeight TeeWye::ms_Model;

TeeWye::TeeWye()
{

}

TeeWye::~TeeWye()
{

}

void TeeWye::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,IDS_STRTYPE,6,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRANGLE,8,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRLOSSMODEL,9,1);
	m_bitmap.LoadBitmap(IDB_TEEWYE);
	s_typeName.LoadString(IDS_STRTEEWYE);
}


Component* TeeWye::CreatTeeWye()
{
	TeeWye *pTeeWye = new TeeWye;
	pTeeWye->Init();
	ms_Model.SetValue(2);
	pTeeWye->SetValue(ms_Model,9);
	ms_Angle.SetValue(90);
	pTeeWye->SetValue(ms_Angle,8);
	pTeeWye->SetSpecial(-1);
	return pTeeWye;
}

ScenarioObject* TeeWye::DoClone()
{
	return new TeeWye(*this);
}

int TeeWye::GetID()
{
	return m_nTypeID;
}

CString TeeWye::GetTypeName()
{
    return s_typeName;
}

BOOL TeeWye::Read(Junperisist *pPersistent)
{
	// TODO: Add extra Read here
	TeeWyePerisist *pTeeWyePerisist = dynamic_cast<TeeWyePerisist*>(pPersistent);
	ASSERT(pTeeWyePerisist != NULL);
	ms_Type.SetValue(pTeeWyePerisist->Type());
	ms_Angle.SetValue(pTeeWyePerisist->Angle());
	ms_Model.SetValue(pTeeWyePerisist->Model());
	return Jun::Read(pPersistent);
}

BOOL TeeWye::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra Save here
	TeeWyePerisist *pTeeWyePerisist = dynamic_cast<TeeWyePerisist*>(pPersistent);
	ASSERT(pTeeWyePerisist != NULL);
	pTeeWyePerisist->Type(ms_Type.GetValue());
	pTeeWyePerisist->Angle(ms_Angle.GetValue());
	pTeeWyePerisist->Model(ms_Model.GetValue());
	return bRet;
}


BOOL TeeWye::Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bReadOnly)
{
	if(ConnectPipeNum()==3)
	{
		DlgTeeWye dlg(UnitSys,*pManager,this);
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
	else
	{
		AfxMessageBox(IDS_STRTEEOPENMEG);
		return FALSE;
	}
}

void TeeWye::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_Type,6);
	GetValue(ms_Angle,8);
	GetValue(ms_Model,9);
}

void TeeWye::SaveData()
{
	// TODO: Add extra SaveData here

	SetValue(ms_Type,6);
	SetValue(ms_Angle,8);
	SetValue(ms_Model,9);
   Jun::SaveData();
}

BOOL TeeWye::CanLink(int nMaxLink,int nKey)
{
	if(nMaxLink < 3)
	{
		return TRUE;
	}
	return FALSE;
}

void TeeWye::AddLinkPipeInfo(UINT nKey)
{

}

void TeeWye::DelLinkPipeInfo(UINT nKey)
{

}

void TeeWye::EmptyPipeInfo()
{

}

void TeeWye::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_PipeID.GetCount()<3)
		ref.Add(5);
	if(ms_Angle.GetfValue()<15||ms_Angle.GetfValue()>165)
		ref.Add(8);
}

void TeeWye::GetPipeID(int ID[])
{
	ASSERT(ConnectPipeNum()==3);
	int i = 0;
	IteratorPtr<int> IdItPtr(ms_PipeID.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		ID[i++] = IdItPtr->CurrentItem();
	}
}

void TeeWye::SetPipeID(int ID[],int ndat)
{
	ms_PipeID.Empty();
	SetValue(ms_PipeID,5);
	for(int i=0;i<3;i++)
	{
		ms_PipeID.AddItem(ID[i]);
	}
	SetValue(ms_PipeID,5);
}
