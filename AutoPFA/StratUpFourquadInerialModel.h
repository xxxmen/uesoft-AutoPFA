// StratUpFourquadInerialModel.h: interface for the StratUpFourquadInerialModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRATUPFOURQUADINERIALMODEL_H__05C09B63_8A07_4199_B306_54A7D2C5C915__INCLUDED_)
#define AFX_STRATUPFOURQUADINERIALMODEL_H__05C09B63_8A07_4199_B306_54A7D2C5C915__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PumpTranModel.h"

class StratUpFourquadInerialModel : public PumpTranModel  
{
public:
	void Init(PumpTransient &ref);
	BOOL UpData(PumpTransient &ref);
	StratUpFourquadInerialModel(DlgInerailTrans &ref);
	virtual ~StratUpFourquadInerialModel();

public:
	DlgInerailTrans &m_dlgTrans;
};

#endif // !defined(AFX_STRATUPFOURQUADINERIALMODEL_H__05C09B63_8A07_4199_B306_54A7D2C5C915__INCLUDED_)
