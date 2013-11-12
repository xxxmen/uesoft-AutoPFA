// ModelDataRef.h: interface for the ModelDataRef class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODELDATAREF_H__664D3F99_D97C_4566_AC07_9AF5C7171E42__INCLUDED_)
#define AFX_MODELDATAREF_H__664D3F99_D97C_4566_AC07_9AF5C7171E42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "persistentObj.h"

class  ModelDataRef : public PersistentObj  
{
public:
	void Init();
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	ModelDataRef();
	virtual ~ModelDataRef();

private:
	void InitRowHead();
	void InitArray();
    RowObject  m_PipeParam;
	RowObject  m_Branch;
	RowObject  m_Reservoir;
	RowObject  m_AssignedFlow;
	RowObject  m_AssignedPress;
	RowObject  m_AreaChange;
	RowObject  m_ReliefValve;
	RowObject  m_TeeWye;
	RowObject  m_Valve;
	RowObject  m_ControlValve;
	RowObject  m_CheckValve;
	RowObject  m_DeadEnd;
	RowObject  m_GasAccumulator;
	RowObject  m_Surge;
	RowObject  m_LiquidAccum;
	RowObject  m_VacuumBreaker;
	RowObject  m_SprayDischarge;
	RowObject  m_Pump;
	RowObject  m_Volume;
	RowObject  m_General;
};

#endif // !defined(AFX_MODELDATAREF_H__664D3F99_D97C_4566_AC07_9AF5C7171E42__INCLUDED_)
