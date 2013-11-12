// JunOutShow.cpp: the source file of output control.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OutDataAttr.h"
#include "UnitSubSystem.h"
#include "JunOutShow.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
JunOutShow::JunOutShow()
{
	
}
JunOutShow::~JunOutShow()
{
	
}

CString JunOutShow::GetKey()
{
	return m_Key;
}

void JunOutShow::SetKey(CString nkey)
{
	m_Key=nkey;
}

UnitTypeID JunOutShow::GetTypeId()
{
	return m_TypeId;
}

void JunOutShow::SetTypeId(UnitTypeID nTypeId)
{
	m_TypeId=nTypeId;
}

CString JunOutShow::GetStrName()
{
	return m_StrName;
}

void JunOutShow::SetStrName(CString nStrName)
{
	m_StrName=nStrName;
}

CString JunOutShow::GetStrUnit()
{
	return m_StrUnit;
}

void JunOutShow::SetStrUnit(CString nStrUnit)
{
	m_StrUnit=nStrUnit;
}

BOOL JunOutShow::GetShow()
{
	return m_Show;
}

void JunOutShow::SetShow(BOOL nShow)
{
	m_Show=nShow;
}