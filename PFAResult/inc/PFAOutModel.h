// PFAOutModel.h: interface for the PFAOutModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PFAOUTMODEL_H__B79E2D57_5916_40CB_AA77_B1F8137EAA65__INCLUDED_)
#define AFX_PFAOUTMODEL_H__B79E2D57_5916_40CB_AA77_B1F8137EAA65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SteadyOutModel.h"
#include "TransOutModel.h"
class UnitSubSystem;
class OutputRefPersist;
class AFX_EXT_CLASS PFAOutModel  
{
public:
	BOOL HasTranData();
	void EmptyOut();
	TransOutModel& TransOut();
	SteadyOutModel& SteadyOut();
	OutputRefPersist& GetOutPutData();
	PFAOutModel(UnitSubSystem &unitsys,OutputRefPersist &OutPutData);
	virtual ~PFAOutModel();

private:
	SteadyOutModel m_SteadyOut;
	TransOutModel  m_TransOut;
	OutputRefPersist &m_OutPutData;
};

#endif // !defined(AFX_PFAOUTMODEL_H__B79E2D57_5916_40CB_AA77_B1F8137EAA65__INCLUDED_)
