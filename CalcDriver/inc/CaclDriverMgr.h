// CaclDriverMgr.h: interface for the CaclDriverMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CACLDRIVERMGR_H__7D395EB7_5D5E_4827_92B6_6E695B98263B__INCLUDED_)
#define AFX_CACLDRIVERMGR_H__7D395EB7_5D5E_4827_92B6_6E695B98263B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CaclFuild.h"
#include "CaclSteady.h"
#include "CalcTrans.h"
#include "CalcPipeMgr.h"
#include "CalcJunMgr.h"

class AFX_EXT_CLASS CalcDriverMgr  
{
public:
	CalcDriverMgr();
	virtual ~CalcDriverMgr();
	CalcJunMgr& GetJunMgr();
	CalcPipeMgr& GetPipeMgr();
	CalcTrans& GetTrans();
	CalcSteady& GetSteady();
	CalcFuild& GetFuild();
	BOOL Save(ofstream &stream);
	
private:
	CalcFuild m_fluid;
	CalcSteady m_Steady;
	CalcTrans m_Trans;
	CalcPipeMgr m_pipeMgr;
	CalcJunMgr  m_junMgr;
};

#endif // !defined(AFX_CACLDRIVERMGR_H__7D395EB7_5D5E_4827_92B6_6E695B98263B__INCLUDED_)
