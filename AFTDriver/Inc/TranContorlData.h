// TranContorlData.h: interface for the TranContorlData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANCONTORLDATA_H__67EA8E2F_5A58_4170_8D4A_7F006CB7D427__INCLUDED_)
#define AFX_TRANCONTORLDATA_H__67EA8E2F_5A58_4170_8D4A_7F006CB7D427__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "persistentObj.h"

class AFX_EXT_CLASS TranContorlData : public PersistentObj  
{
public:
	BOOL Save(CStdioFile &file);
	BOOL Read(CStdioFile &file);
	void Init();
	TranContorlData();
	virtual ~TranContorlData();
public:
	CString StartTime();
	void StartTime(CString strValue);
	CString StopTime();
	void StopTime(CString strValue);
	CString TimeUnit();
	void TimeUnit(CString strValue);
	CString Frequency();
	void Frequency(CString strValue);
	CString Cavitation();
	void Cavitation(CString strValue);
	CString VariableR();
	void VariableR(CString strValue);
	CString Artificial();
	void Artificial(CString strValue);
	CString Criteria();
	void Criteria(CString strValue);
	CString MinFlow();
	void MinFlow(CString strValue);
	CString MinFlowUnit();
	void MinFlowUnit(CString strValue);
	CString TotalSteps();
	void TotalSteps(CString strValue);

	CString TimeStep();
	void TimeStep( CString strValue );
	CString TimeStepUnits();
	void TimeStepUnits( CString strValue );
	CString DifferenceMethod();
	void DifferenceMethod( CString strValue );
	CString RelativeTolerance();
	void RelativeTolerance( CString strValue );
	CString AbsoluteTolerance();
	void AbsoluteTolerance( CString strValue );
	CString AbsoluteToleranceUnits();
	void AbsoluteToleranceUnits( CString strValue );
	CString MaxIterations();
	void MaxIterations( CString strValue );
	CString Relaxation();
	void Relaxation( CString strValue );

private:
	void InitArray();
	void InitRowHead();
	RowObject  m_StartTime;
	RowObject  m_StopTime;
	RowObject  m_TimeUnits;
	RowObject  m_Frequency;
	RowObject  m_ModelCavitation;
	RowObject  m_VariableR;
	RowObject  m_StopTran;
	RowObject  m_Criteria;
	RowObject  m_CriteriaMinFlow;
	RowObject  m_CriteriaMinFlowUnits;
	RowObject  m_TotalSteps;
	
	RowObject  m_TimeStep;
	RowObject  m_TimeStepUnits;
	RowObject  m_DifferenceMethod;
	RowObject  m_RelativeTolerance;
	RowObject  m_AbsoluteTolerance;
	RowObject  m_AbsoluteToleranceUnits;
	RowObject  m_MaxIterations;
	RowObject  m_Relaxation;
};

#endif // !defined(AFX_TRANCONTORLDATA_H__67EA8E2F_5A58_4170_8D4A_7F006CB7D427__INCLUDED_)
