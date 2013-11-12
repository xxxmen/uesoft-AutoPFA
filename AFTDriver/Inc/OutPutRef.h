// OutPutRef.h: interface for the OutPutRefData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OUTPUTREF_H__D7BDF73B_465D_4A4F_AF1D_B1AAD9AE29F9__INCLUDED_)
#define AFX_OUTPUTREF_H__D7BDF73B_465D_4A4F_AF1D_B1AAD9AE29F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "persistentObj.h"
#include "OutPutRefItem.h"
#include "RowObjectFace.h"


class AFX_EXT_CLASS OutPutRefData : public PersistentObj  
{
public:
	BOOL Save(CStdioFile &file);
	BOOL Read(CStdioFile &file);
	void Init(); 
	void InitData(CString strData);
	OutPutRefData();
	virtual ~OutPutRefData();

	CString GetPipeDataOrder();
	void SetPipeDataOrder(CString strValue);
	CString GetPipeUnitOrder();
	void SetPipeUnitOrder(CString strValue);
	CString GetJunDataOrder();
	void SetJunDataOrder(CString strValue);
	CString GetJunUnitOrder();
	void SetJunUnitOrder(CString strValue);
	CString GetPipeTranDataOrder();
	void SetPipeTranDataOrder(CString strValue);
	CString GetPipeTranUnitOrder();
	void SetPipeTranUnitOrder(CString strValue);
	CString GetJunTranDataOrder();
	void SetJunTranDataOrder(CString strValue);
	CString GetJunTranUnitOrder();
	void SetJunTranUnitOrder(CString strValue);
	CString GetPumpSummaryDataOrder();
	void SetPumpSummaryDataOrder(CString strValue);
	CString GetPumpSummaryUnitOrder();
	void SetPumpSummaryUnitOrder(CString strValue);
	CString GetValveSummaryDataOrder();
	void SetValveSummaryDataOrder(CString strValue);
	CString GetValveSummaryUnitOrder();
	void SetValueSummaryUnitOrder(CString strValue);
	CString GetGeneralSectionOptions();
	void SetGeneralSectionOptions(CString strValue);
	CString GetWrapHeaders();
	void SetWrapHeaders(CString strValue);
	CString GetDigits();
	void SetDigits(CString strValue);
	CString GetUseExponential();
	void SetUseExponential(CString strValue);
	CString GetColumnAlign();
	void SetColumnAlign(CString strValue);
	CString GetMagnitudeLimit();
	void SetMagnitudeLimit(CString strValue);
	CString GetOutputToPrinter();
	void SetOutputTOprinter(CString strValue);
	CString GetOutputToFile();
	void SetOutputTOFile(CString strValue);
	CString GetAutoTransferResult();
	void SetAutoTransferResult(CString strValue);
	CString GetTransferValveState();
	void SetTransferValveState(CString strValue);
	CString GetSaveModelAfterTransfer();
	void SetSaveModelAfterTransfer(CString strValue);
	CString GetAnalysisTitle();
	void SetAnalysisTitle(CString strValue);
	CString GetAnalysisRef();
	void SetAnalysisRef(CString strValue);
	CString GetMaxMinTable();
	void SetMaxMinTable(CString strValue);

private:
	void InitArray();
	void InitRowHead();
	OutPutRefItem m_Pipe;
	OutPutRefItem m_Junction;
	OutPutRefItem m_PipeTran;
	OutPutRefItem m_JunTran;
	OutPutRefItem m_PumpSummary;
	OutPutRefItem m_ValveSummary;
	OutPutRefItem m_HexSummary;
	OutPutRefItem m_ReservoirSummary;
	OutPutRefItem m_PumpTransient;
	OutPutRefItem m_ValveTransient;
	OutPutRefItem m_HexTransient;
	OutPutRefItem m_ReservoirTransient;
	OutPutRefItem m_CostReport;
	OutPutRefItem m_PipeHT;
	
	//RowObjectFace<15> m_PipeData;
	//RowObjectFace<15> m_PipeUnit;

	RowObject  m_ShowOptimized;
	RowObject  m_Highlight;
	RowObject  m_DontShowZero;
	RowObject  m_GroupPipe;
	RowObject  m_ShowSubtotals;
	RowObject  m_UnitStyle;
	RowObject  m_SubtotalNumDecimal;
	RowObject  m_ItemsNumDecimal;
	RowObject  m_GeneralSectionOptions;
	RowObject  m_WrapHeaders;
	RowObject  m_Digits;
	RowObject  m_UseExponential;
	RowObject  m_ColumnAlign;
	RowObject  m_MagnitudeLimit;
	RowObject  m_OutputToPrinter;
	RowObject  m_OutputToFile;
	RowObject  m_AutoTransferResult;
	RowObject  m_TransferValveState;
	RowObject  m_SaveModelAfterTransfer;
	RowObject  m_AnalysisTitle;
	RowObject  m_AnalysisRef;
	RowObject  m_MaxMinTable;
	RowObject  m_TimeFormat;
	RowObject  m_MultiScenOutput;
};



#endif // !defined(AFX_OUTPUTREF_H__D7BDF73B_465D_4A4F_AF1D_B1AAD9AE29F9__INCLUDED_)
