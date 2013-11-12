// SettingData.h: interface for the SettingData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SETTINGDATA_H__2D4B8161_3B3A_45CD_B5F0_D50F28520793__INCLUDED_)
#define AFX_SETTINGDATA_H__2D4B8161_3B3A_45CD_B5F0_D50F28520793__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "persistentObj.h"

class AFX_EXT_CLASS SettingData : public PersistentObj  
{
public:
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	void Init();
	SettingData();
	virtual ~SettingData();
public:
	CString AnalysisType();
	void AnalysisType(CString strValue);
	CString PresTolType();
	void PresTolType(CString strValue);
	StrArray<2> PresAbsTol();
	void PresAbsTol(const StrArray<2>& strValue);
	CString PresRelTol();
	void PresRelTol(CString strValue);
	CString FlowTolType();
	void FlowTolType(CString strValue);
	StrArray<2> FlowAbsTol();
	void FlowAbsTol(const StrArray<2>& strValue);
	CString FlowRelTol();
	void FlowRelTol(CString strValue);
	CString RelaxationType();
	void RelaxationType(CString strValue);
	CString FlowRelaxation();
	void FlowRelaxation(CString strValue);
	CString PresRelaxation();
	void PresRelaxation(CString strValue);
	CString MaxIterations();
	void MaxIterations(CString strValue);
	CString KeepHistory();
	void KeepHistory(CString strValue);
	CString MatrixMethod();
	void MatrixMethod(CString strValue);
	CString AutoDetect();
	void AutoDetect(CString strValue);

	CString GSCAccess();
	void GSCAccess(CString strValue);
	CString TempTolType();
	void TempTolType(CString strValue);
	StrArray<2> TempAbsTol();
	void TempAbsTol(const StrArray<2>& strValue);
	CString TempRelTol();
	void TempRelTol(CString strValue);
	CString EnergyBalance();
	void EnergyBalance(CString strValue);

private:
	void InitArray();
	void InitRowHead();
	RowObject  m_CheckFlags;
	RowObject  m_AnalysisType;
	RowObject  m_HPages;
	RowObject  m_VPages;
	RowObject  m_HSCValue;
	RowObject  m_VSCValue;
	RowObject  m_Zoom;
	RowObject  m_BackPath;
	RowObject  m_OutputFile;
	RowObject  m_PresTolType;
	RowObject  m_PresAbsTolType;
	RowObject  m_PresAbsTol;
	RowObject  m_PresRelTol;
	RowObject  m_FlowTolType;
	RowObject  m_FlowAbsTolType;
	RowObject  m_FlowAbsTol;
	RowObject  m_FlowRelTol;
	RowObject  m_RelaxationType;
	RowObject  m_FlowRelaxation;
	RowObject  m_PresRelaxation;
	RowObject  m_TempLimitUpper;
	RowObject  m_TempLimitLower;
	RowObject  m_FlowBalance;
	RowObject  m_MaximumIt;
	RowObject  m_ItHistory;
	RowObject  m_MatrixMethod;
	RowObject  m_GSRelax;
	RowObject  m_AutoDetect;
    RowObject  m_AutoRelax;

	RowObject  m_GSCAccess;
	RowObject  m_TempTolType;
	RowObject  m_TempAbsTol;
	RowObject  m_TempRelTol;
	RowObject  m_EnergyBalance;
};

#endif // !defined(AFX_SETTINGDATA_H__2D4B8161_3B3A_45CD_B5F0_D50F28520793__INCLUDED_)
