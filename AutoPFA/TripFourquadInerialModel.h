// TripFourquadInerialModel.h: interface for the TripFourquadInerialModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRIPFOURQUADINERIALMODEL_H__606F7F14_2BB9_4CB3_AFF5_B415904F3F9D__INCLUDED_)
#define AFX_TRIPFOURQUADINERIALMODEL_H__606F7F14_2BB9_4CB3_AFF5_B415904F3F9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PumpTranModel.h"

class TripFourquadInerialModel : public PumpTranModel  
{
public:
	void Init(PumpTransient &ref);
	BOOL UpData(PumpTransient &ref);
	TripFourquadInerialModel(DlgInerailTrans &ref);
	virtual ~TripFourquadInerialModel();

public:
	DlgInerailTrans &m_dlgTrans;
};

#endif // !defined(AFX_TRIPFOURQUADINERIALMODEL_H__606F7F14_2BB9_4CB3_AFF5_B415904F3F9D__INCLUDED_)
