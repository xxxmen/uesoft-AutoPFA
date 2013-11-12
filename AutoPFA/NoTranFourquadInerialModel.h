// NoTranFourquadInerialModel.h: interface for the NoTranFourquadInerialModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOTRANFOURQUADINERIALMODEL_H__ED4583D1_50AE_42C9_90A4_7C155927B183__INCLUDED_)
#define AFX_NOTRANFOURQUADINERIALMODEL_H__ED4583D1_50AE_42C9_90A4_7C155927B183__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PumpTranModel.h"

class NoTranFourquadInerialModel : public PumpTranModel  
{
public:
	void Init(PumpTransient &ref);
	BOOL UpData(PumpTransient &ref);
	NoTranFourquadInerialModel(DlgInerailTrans &ref);
	virtual ~NoTranFourquadInerialModel();

public:
	DlgInerailTrans &m_dlgTrans;

};

#endif // !defined(AFX_NOTRANFOURQUADINERIALMODEL_H__ED4583D1_50AE_42C9_90A4_7C155927B183__INCLUDED_)
