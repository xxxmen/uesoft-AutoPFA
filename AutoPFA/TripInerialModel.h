// TripInerialModel.h: interface for the TripInerialModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRIPINERIALMODEL_H__511D8902_67ED_48EA_A1D0_430212AEE4B1__INCLUDED_)
#define AFX_TRIPINERIALMODEL_H__511D8902_67ED_48EA_A1D0_430212AEE4B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PumpTranModel.h"

class TripInerialModel : public PumpTranModel  
{
public:
	void Init(PumpTransient &ref);
	BOOL UpData(PumpTransient &ref);
	TripInerialModel(DlgInerailTrans &ref);
	virtual ~TripInerialModel();

public:
	DlgInerailTrans &m_dlgTrans;
};

#endif // !defined(AFX_TRIPINERIALMODEL_H__511D8902_67ED_48EA_A1D0_430212AEE4B1__INCLUDED_)
