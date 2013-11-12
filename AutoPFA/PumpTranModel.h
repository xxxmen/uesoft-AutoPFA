// PumpTranModel.h: interface for the PumpTranModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUMPTRANMODEL_H__BEC039DF_54DB_4C8A_9694_88A0438ED410__INCLUDED_)
#define AFX_PUMPTRANMODEL_H__BEC039DF_54DB_4C8A_9694_88A0438ED410__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PumpTransient.h"
#include "DlgNoInerialTrans.h"
#include "DlgInerailTrans.h"

class PumpTranModel  
{
public:
	virtual void Init(PumpTransient &ref) = 0;
	virtual BOOL UpData(PumpTransient &ref) = 0;
	PumpTranModel();
	virtual ~PumpTranModel();
	

};

#endif // !defined(AFX_PUMPTRANMODEL_H__BEC039DF_54DB_4C8A_9694_88A0438ED410__INCLUDED_)
