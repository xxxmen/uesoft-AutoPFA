// StratUpInerialModel.h: interface for the StratUpInerialModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRATUPINERIALMODEL_H__E3D2A48F_55A9_4222_AFEF_BFA50044A745__INCLUDED_)
#define AFX_STRATUPINERIALMODEL_H__E3D2A48F_55A9_4222_AFEF_BFA50044A745__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PumpTranModel.h"

class StratUpInerialModel : public PumpTranModel  
{
public:
	void Init(PumpTransient &ref);
	BOOL UpData(PumpTransient &ref);
	StratUpInerialModel(DlgInerailTrans &ref);
	virtual ~StratUpInerialModel();

public:
	DlgInerailTrans &m_dlgTrans;
};

#endif // !defined(AFX_STRATUPINERIALMODEL_H__E3D2A48F_55A9_4222_AFEF_BFA50044A745__INCLUDED_)
