// StartUpSpeedModel.h: interface for the StartUpSpeedModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STARTUPSPEEDMODEL_H__5D73F8B7_3A5D_4108_BCD3_1B97E9350A02__INCLUDED_)
#define AFX_STARTUPSPEEDMODEL_H__5D73F8B7_3A5D_4108_BCD3_1B97E9350A02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PumpTranModel.h"

class StartUpSpeedModel : public PumpTranModel  
{
public:
	void Init(PumpTransient &ref);
	BOOL UpData(PumpTransient &ref);
	StartUpSpeedModel(DlgInerailTrans &ref);
	virtual ~StartUpSpeedModel();

public:
	DlgInerailTrans &m_dlgTrans;
};

#endif // !defined(AFX_STARTUPSPEEDMODEL_H__5D73F8B7_3A5D_4108_BCD3_1B97E9350A02__INCLUDED_)
