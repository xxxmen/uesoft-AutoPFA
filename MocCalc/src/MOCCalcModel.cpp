// MOCCalcModel.cpp: implementation of the MOCCalcModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCCalcModel.h"
#include "CaclDriverMgr.h"
#include "PFAOutModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCCalcModel::MOCCalcModel()
{

}

MOCCalcModel::~MOCCalcModel()
{

}

BOOL MOCCalcModel::Read(CalcDriverMgr &data)
{
	if(!m_MocFluid.Read(data.GetFuild()))
	{
		return FALSE;
	}
	if(!m_ComponentMgr.Read(data))
	{
		return FALSE;
	}
	if(!m_MocCalcMgr.Read(data))
	{
		return FALSE;
	}
	m_ComponentMgr.InitComponentNet();
	return TRUE;
}

void MOCCalcModel::Calc(PFAOutModel &model)
{
	model.EmptyOut();//清空输出结果
	m_MocCalcMgr.Calc(m_ComponentMgr,model);
}



