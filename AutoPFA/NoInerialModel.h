// NoInerialModel.h: interface for the NoInerialModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOINERIALMODEL_H__03926847_A705_4286_9270_46DB012B3B52__INCLUDED_)
#define AFX_NOINERIALMODEL_H__03926847_A705_4286_9270_46DB012B3B52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PumpTranModel.h"

class NoInerialModel : public PumpTranModel  
{
public:
	void Init(PumpTransient &ref);
	BOOL UpData(PumpTransient &ref);
	NoInerialModel(DlgNoInerialTrans &ref);
	virtual ~NoInerialModel();
public:
	DlgNoInerialTrans& m_dlgTrans;

};

#endif // !defined(AFX_NOINERIALMODEL_H__03926847_A705_4286_9270_46DB012B3B52__INCLUDED_)
