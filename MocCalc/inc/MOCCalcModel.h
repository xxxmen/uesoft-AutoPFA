// MOCCalcModel.h: interface for the MOCCalcModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCCALCMODEL_H__4A4FB757_6D71_4481_8E9E_E52B30744815__INCLUDED_)
#define AFX_MOCCALCMODEL_H__4A4FB757_6D71_4481_8E9E_E52B30744815__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcDriverMgr;

#include "MOCFluid.h"
#include "MOCCalcMgr.h"
#include "MOCComponentMgr.h"
class PFAOutModel;


class AFX_EXT_CLASS MOCCalcModel  
{
public:
	void Calc(PFAOutModel &model);
	BOOL Read(CalcDriverMgr &data);
	MOCCalcModel();
	virtual ~MOCCalcModel();

private:
	MOCFluid m_MocFluid;
	MOCCalcMgr m_MocCalcMgr;
	MOCComponentMgr m_ComponentMgr;

};

#endif // !defined(AFX_MOCCALCMODEL_H__4A4FB757_6D71_4481_8E9E_E52B30744815__INCLUDED_)
