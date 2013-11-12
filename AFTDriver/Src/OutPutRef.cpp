// OutPutRef.cpp: implementation of the OutPutRefData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OutPutRef.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OutPutRefData::OutPutRefData()
{
	InitArray();
}

OutPutRefData::~OutPutRefData()
{

}

void OutPutRefData::InitRowHead()
{
	SetID(_T("\n[OUTPUT PREFERENCES]"));
	if (isImpFile)
	{
		CString strArray[26];
		strArray[0] = _T("Pipe Data Order=");
		strArray[1] = _T("Pipe Data Units=");
		strArray[2] = _T("Junction Data Order=");
		strArray[3] = _T("Junction Data Units=");
		strArray[4] = _T("Pipe Transient Data Order=");
		strArray[5] = _T("Pipe Transient Data Units=");
		strArray[6] = _T("Jct Transient Data Order= ");
		strArray[7] = _T("Jct Transient Data Units= ");
		strArray[8] = _T("Pump Summary Order=");
		strArray[9] = _T("Pump Summary Units=");
		strArray[10] = _T("Valve Summary Order=");
		strArray[11] = _T("Valve Summary Units=");
		strArray[12] = _T("General Section Options=");
		strArray[13] = _T("Wrap Headers=");
		strArray[14] = _T("Digits=");
		strArray[15] = _T("Use Exponential=");
		strArray[16] = _T("Column Alignment=");
		strArray[17] = _T("Magnitude Limit=");
		strArray[18] = _T("Output To Printer= ");
		strArray[19] = _T("Output To File= ");
		strArray[20] = _T("Auto Transfer Results=");
		strArray[21] = _T("Transfer Valve State=");
		strArray[22] = _T("Save Model After Transfer= ");
		strArray[23] = _T("Analysis Title=");
		strArray[24] = _T("Analysis Reference= ");
		strArray[25] = _T("MaxMin Table= ");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==26);
			m_RowArray.GetAt(i)->InitHead(strArray[i]);
			
		}
	}
	else
	{
		CString strArray[51];
		strArray[0] = _T("Pipe Data Order=");
		strArray[1] = _T("Pipe Data Units=");
		strArray[2] = _T("Junction Data Order=");
		strArray[3] = _T("Junction Data Units=");
		strArray[4] = _T("Pipe Transient Data Order=");
		strArray[5] = _T("Pipe Transient Data Units=");
		strArray[6] = _T("Jct Transient Data Order= ");
		strArray[7] = _T("Jct Transient Data Units= ");
		strArray[8] = _T("Pump Summary Order=");
		strArray[9] = _T("Pump Summary Units=");
		strArray[10] = _T("Valve Summary Order=");
		strArray[11] = _T("Valve Summary Units=");
		strArray[12] = _T("Hex Summary Order=");
		strArray[13] = _T("Hex Summary Units=");
		strArray[14] = _T("Reservoir Summary Order=");
		strArray[15] = _T("Reservoir Summary Units=");
		strArray[16] = _T("Pump Transient Order=");
		strArray[17] = _T("Pump Transient Units=");
		strArray[18] = _T("Valve Transient Order=");
		strArray[19] = _T("Valve Transient Units=");
		strArray[20] = _T("Hex Transient Order=");
		strArray[21] = _T("Hex Transient Units=");
		strArray[22] = _T("Reservoir Transient Order=");
		strArray[23] = _T("Reservoir Transient Units=");
		strArray[24] = _T("Cost Report Order=");
		strArray[25] = _T("Cost Report Units=");
		strArray[26] = _T("Show Optimized Only=");
		strArray[27] = _T("Highlight Optimized=");
		strArray[28] = _T("Dont Show Zero Cost=");
		strArray[29] = _T("Group Pipe Costs=");
		strArray[30] = _T("Show Subtotals Only=");
		strArray[31] = _T("Unit Style=");
		strArray[32] = _T("SubtotalNumDecimal=");
		strArray[33] = _T("ItemsNumDecimal=");
		strArray[34] = _T("Pipe HT Data Order=");
		strArray[35] = _T("Pipe HT Data Units=");
		strArray[36] = _T("General Section Options=");
		strArray[37] = _T("Wrap Headers=");
		strArray[38] = _T("Digits=");
		strArray[39] = _T("Use Exponential=");
		strArray[40] = _T("Column Alignment=");
		strArray[41] = _T("Magnitude Limit=");
		strArray[42] = _T("Output To Printer= ");
		strArray[43] = _T("Output To File=");
		strArray[44] = _T("Auto Transfer Results=");
		strArray[45] = _T("Transfer Valve State=");
		strArray[46] = _T("Save Model After Transfer=");
		strArray[47] = _T("Analysis Title=");
		strArray[48] = _T("Analysis Reference=");
		strArray[49] = _T("TimeFormat=");
		strArray[50] = _T("MultiScenOutput=");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==51);
			m_RowArray.GetAt(i)->InitHead(strArray[i]);
			
		}
	}
}

void OutPutRefData::InitArray()
{
	if (isImpFile)
	{
		m_RowArray.SetSize(26);
		m_RowArray.SetAt(0,&m_Pipe.m_DataOrder);
		m_RowArray.SetAt(1,&m_Pipe.m_UnitOrder);
		m_RowArray.SetAt(2,&m_Junction.m_DataOrder);
		m_RowArray.SetAt(3,&m_Junction.m_UnitOrder);
		m_RowArray.SetAt(4,&m_PipeTran.m_DataOrder);
		m_RowArray.SetAt(5,&m_PipeTran.m_UnitOrder);
		m_RowArray.SetAt(6,&m_JunTran.m_DataOrder);
		m_RowArray.SetAt(7,&m_JunTran.m_UnitOrder);
		m_RowArray.SetAt(8,&m_PumpSummary.m_DataOrder);
		m_RowArray.SetAt(9,&m_PumpSummary.m_UnitOrder);
		m_RowArray.SetAt(10,&m_ValveSummary.m_DataOrder);
		m_RowArray.SetAt(11,&m_ValveSummary.m_UnitOrder);
		m_RowArray.SetAt(12,&m_GeneralSectionOptions);
		m_RowArray.SetAt(13,&m_WrapHeaders);
		m_RowArray.SetAt(14,&m_Digits);
		m_RowArray.SetAt(15,&m_UseExponential);
		m_RowArray.SetAt(16,&m_ColumnAlign);
		m_RowArray.SetAt(17,&m_MagnitudeLimit);
		m_RowArray.SetAt(18,&m_OutputToPrinter);
		m_RowArray.SetAt(19,&m_OutputToFile);
		m_RowArray.SetAt(20,&m_AutoTransferResult);
		m_RowArray.SetAt(21,&m_TransferValveState);
		m_RowArray.SetAt(22,&m_SaveModelAfterTransfer);
		m_RowArray.SetAt(23,&m_AnalysisTitle);
		m_RowArray.SetAt(24,&m_AnalysisRef);
		m_RowArray.SetAt(25,&m_MaxMinTable);
		InitRowHead();
	}
	else
	{
		m_RowArray.SetSize(51);
		m_RowArray.SetAt(0,&m_Pipe.m_DataOrder);
		m_RowArray.SetAt(1,&m_Pipe.m_UnitOrder);
		m_RowArray.SetAt(2,&m_Junction.m_DataOrder);
		m_RowArray.SetAt(3,&m_Junction.m_UnitOrder);
		m_RowArray.SetAt(4,&m_PipeTran.m_DataOrder);
		m_RowArray.SetAt(5,&m_PipeTran.m_UnitOrder);
		m_RowArray.SetAt(6,&m_JunTran.m_DataOrder);
		m_RowArray.SetAt(7,&m_JunTran.m_UnitOrder);
		m_RowArray.SetAt(8,&m_PumpSummary.m_DataOrder);
		m_RowArray.SetAt(9,&m_PumpSummary.m_UnitOrder);
		m_RowArray.SetAt(10,&m_ValveSummary.m_DataOrder);
		m_RowArray.SetAt(11,&m_ValveSummary.m_UnitOrder);
		m_RowArray.SetAt(12,&m_HexSummary.m_DataOrder);
		m_RowArray.SetAt(13,&m_HexSummary.m_UnitOrder);
		m_RowArray.SetAt(14,&m_ReservoirSummary.m_DataOrder);
		m_RowArray.SetAt(15,&m_ReservoirSummary.m_UnitOrder);
		m_RowArray.SetAt(16,&m_PumpTransient.m_DataOrder);
		m_RowArray.SetAt(17,&m_PumpTransient.m_UnitOrder);
		m_RowArray.SetAt(18,&m_ValveTransient.m_DataOrder);
		m_RowArray.SetAt(19,&m_ValveTransient.m_UnitOrder);
		m_RowArray.SetAt(20,&m_HexTransient.m_DataOrder);
		m_RowArray.SetAt(21,&m_HexTransient.m_UnitOrder);
		m_RowArray.SetAt(22,&m_ReservoirTransient.m_DataOrder);
		m_RowArray.SetAt(23,&m_ReservoirTransient.m_UnitOrder);
		m_RowArray.SetAt(24,&m_CostReport.m_DataOrder);
		m_RowArray.SetAt(25,&m_CostReport.m_UnitOrder);
		m_RowArray.SetAt(26,&m_ShowOptimized);
		m_RowArray.SetAt(27,&m_Highlight);
		m_RowArray.SetAt(28,&m_DontShowZero);
		m_RowArray.SetAt(29,&m_GroupPipe);
		m_RowArray.SetAt(30,&m_ShowSubtotals);
		m_RowArray.SetAt(31,&m_UnitStyle);
		m_RowArray.SetAt(32,&m_SubtotalNumDecimal);
		m_RowArray.SetAt(33,&m_ItemsNumDecimal);
		m_RowArray.SetAt(34,&m_PipeHT.m_DataOrder);
		m_RowArray.SetAt(35,&m_PipeHT.m_UnitOrder);
		m_RowArray.SetAt(36,&m_GeneralSectionOptions);
		m_RowArray.SetAt(37,&m_WrapHeaders);
		m_RowArray.SetAt(38,&m_Digits);
		m_RowArray.SetAt(39,&m_UseExponential);
		m_RowArray.SetAt(40,&m_ColumnAlign);
		m_RowArray.SetAt(41,&m_MagnitudeLimit);
		m_RowArray.SetAt(42,&m_OutputToPrinter);
		m_RowArray.SetAt(43,&m_OutputToFile);
		m_RowArray.SetAt(44,&m_AutoTransferResult);
		m_RowArray.SetAt(45,&m_TransferValveState);
		m_RowArray.SetAt(46,&m_SaveModelAfterTransfer);
		m_RowArray.SetAt(47,&m_AnalysisTitle);
		m_RowArray.SetAt(48,&m_AnalysisRef);
		m_RowArray.SetAt(49,&m_TimeFormat);
		m_RowArray.SetAt(50,&m_MultiScenOutput);
		InitRowHead();
	}
}

void OutPutRefData::Init()
{
	if (isImpFile)
	{
		CString strArray[26];
		strArray[0] = _T("114,3,7,14,15,130,131,22,17,21,31,8,9,11,12");
		strArray[1] = _T("None,m3/sec,meters/sec,MPa,MPa,meters,meters,MPa,MPa,MPa,meters,MPa,MPa,MPa,MPa");
		strArray[2] = _T("40,1,2,3,4,30,29,38");
		strArray[3] = _T("None,MPa,MPa,MPa,MPa,m3/sec,kg/sec,None");
		strArray[4] = _T("1,3,5,8");
		strArray[5] = _T("Pascals,meters,kg/sec,m3/sec");
		strArray[6] = _T("");
		strArray[7] = _T("");
		strArray[8] = _T("15,1,2,3,4,5,6,7,8,9,10,11");
		strArray[9] = _T("None,m3/sec,kg/sec,MPa,meters,Percent,Percent,kW,m3/sec,Percent,meters,meters");
		strArray[10] = _T("12,1,2,3,4,5,6,7,8,11");
		strArray[11] = _T("None,None,m3/sec,kg/sec,MPa,meters,MPa,None,None,None");
		strArray[12] = _T("-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,0");
		strArray[13] = _T("1");
		strArray[14] = _T("4");
		strArray[15] = _T("0");
		strArray[16] = _T("0");
		strArray[17] = _T("6");
		strArray[18] = _T("0");
		strArray[19] = _T("0");
		strArray[20] = _T("0");
		strArray[21] = _T("0");
		strArray[22] = _T("0");
		strArray[23] = _T("AFT Impulse Model imp");
		strArray[24] = _T("");
		strArray[25] = _T("1");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==26);
			m_RowArray.GetAt(i)->ReadChild(strArray[i]);
		}
	}
	else
	{
		CString strArray[51];
		strArray[0] = _T("114,3,7,14,15,130,131,22,17,21,31,8,9,11,12");
		strArray[1] = _T("None,cm3/sec,meters/sec,Pascals,Pascals,meters,meters,Pascals,Pascals,Pascals,meters,Pascals,Pascals,Pascals,Pascals");
		strArray[2] = _T("40,1,2,3,4,28,27,38");
		strArray[3] = _T("None,Pascals,Pascals,Pascals,Pascals,m3/sec,kg/sec,None");
		strArray[4] = _T("1,3,5,8");
		strArray[5] = _T("Pascals,meters,kg/sec,m3/sec");
		strArray[6] = _T("");
		strArray[7] = _T("");
		strArray[8] = _T("15,1,2,3,4,5,6,7,8,9,10,11");
		strArray[9] = _T("None,m3/sec,kg/sec,MPa,meters,Percent,Percent,kW,m3/sec,Percent,meters,meters");
		strArray[10] = _T("12,1,2,3,4,5,6,7,8,11");
		strArray[11] = _T("None,None,m3/sec,kg/sec,MPa,meters,MPa,None,None,None");
		strArray[12] = _T("8,1,2,3,4,5,7,14,6,15,10");
		strArray[13] = _T("None,m3/sec,kg/sec,MPa,meters,deg. C,kW,deg. C,deg. C,deg. C,deg. C");
		strArray[14] = _T("1,2,3,4,5,7,8,9,10");
		strArray[15] = _T("None,None,meters,meters,MPa,meters3,kg,m3/sec,kg/sec");
		strArray[16] = _T("15,1,2,3,4,5,6,7,8,9,10,11");
		strArray[17] = _T("None,m3/sec,kg/sec,MPa,meters,Percent,Percent,kW,m3/sec,Percent,meters,meters");
		strArray[18] = _T("12,1,2,3,4,5,6,7,8");
		strArray[19] = _T("None,None,m3/sec,kg/sec,MPa,meters,MPa,None,None");
		strArray[20] = _T("8,1,2,3,4,5,7,14,6,15,10");
		strArray[21] = _T("None,m3/sec,kg/sec,MPa,meters,deg. C,kW,deg. C,deg. C,deg. C,deg. C");
		strArray[22] = _T("1,2,3,4,5,7,8,9,10");
		strArray[23] = _T("None,None,meters,meters,MPa,meters3,kg,m3/sec,kg/sec");
		strArray[24] = _T("1,2,3,4,5,6,8,9,10");
		strArray[25] = _T("None,None,U.S. Dollars,U.S. Dollars,U.S. Dollars,U.S. Dollars,U.S. Dollars,U.S. Dollars,U.S. Dollars");
		strArray[26] = _T("0");
		strArray[27] = _T("0");
		strArray[28] = _T("-1");
		strArray[29] = _T("0");
		strArray[30] = _T("0");
		strArray[31] = _T("0");
		strArray[32] = _T("0");
		strArray[33] = _T("0");
		strArray[34] = _T("1,2,8,3,9,4,10,14");
		strArray[35] = _T("None,deg. C,deg. C,deg. C,deg. C,deg. C,deg. C,deg. C");
		strArray[36] = _T(" -1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,0,-1,-1");
		strArray[37] = _T("1");
		strArray[38] = _T("4");
		strArray[39] = _T("0");
		strArray[40] = _T("0");
		strArray[41] = _T("6");
		strArray[42] = _T("0");
		strArray[43] = _T("0");
		strArray[44] = _T("0");
		strArray[45] = _T("0");
		strArray[46] = _T("0");
		strArray[47] = _T("AFT Fathom Model");
		strArray[48] = _T("");
		strArray[49] = _T("seconds");
		strArray[50] = _T("0");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==51);
			m_RowArray.GetAt(i)->ReadChild(strArray[i]);
		}
	}
}

BOOL OutPutRefData::Read(CStdioFile &file)
{
// 	m_Pipe.Read(file);
// 
// 	m_Junction.Read(file);
// 
// 	m_PipeTran.Read(file);
// 	m_JunTran.Read(file);
// 	m_PumpSummary.Read(file);
// 	m_ValveSummary.Read(file);
// 	
// 	CString strTemp;
// 	file.ReadString(strTemp);
// 	m_GeneralSectionOptions.InitRow(strTemp);
// 
// 		
// 	file.ReadString(strTemp);
// 	m_WrapHeaders.InitRow(strTemp);
// 
// 	file.ReadString(strTemp);
// 	m_Digits.InitRow(strTemp);
// 
// 	file.ReadString(strTemp);
// 	m_UseExponential.InitRow(strTemp);
// 
// 	file.ReadString(strTemp);
// 	m_ColumnAlign.InitRow(strTemp);
// 
// 	file.ReadString(strTemp);
// 	m_MagnitudeLimit.InitRow(strTemp);
// 
// 	file.ReadString(strTemp);
// 	m_OutputToPrinter.InitRow(strTemp);
// 
// 	file.ReadString(strTemp);
// 	m_OutputToFile.InitRow(strTemp);
// 
// 	file.ReadString(strTemp);
// 	m_AutoTransferResult.InitRow(strTemp);
// 
// 	file.ReadString(strTemp);
// 	m_TransferValveState.InitRow(strTemp);
// 
// 	file.ReadString(strTemp);
// 	m_SaveModelAfterTransfer.InitRow(strTemp);
// 
// 	file.ReadString(strTemp);
// 	m_AnalysisTitle.InitRow(strTemp);
// 
// 	file.ReadString(strTemp);
// 	m_AnalysisRef.InitRow(strTemp);
// 
// 	file.ReadString(strTemp);
// 	m_MaxMinTable.InitRow(strTemp);
// 
// 	
// 	return TRUE;

	return ReadData(file);
}

CString OutPutRefData::GetPipeDataOrder()
{
	return m_Pipe.GetDataOrder();
}

void OutPutRefData::SetPipeDataOrder(CString strValue)
{
	m_RowArray.GetAt(0)->RemoveAll();
	m_RowArray.GetAt(0)->InitHead("Pipe Data Order= ");
	m_RowArray.GetAt(0)->ReadChild(strValue);
}

CString OutPutRefData::GetPipeUnitOrder()
{
	return m_Pipe.GetUnitOrder();
}

void OutPutRefData::SetPipeUnitOrder(CString strValue)
{
	m_RowArray.GetAt(1)->RemoveAll();
	m_RowArray.GetAt(1)->InitHead("Pipe Data Units= ");
	m_RowArray.GetAt(1)->ReadChild(strValue);
}

CString OutPutRefData::GetJunDataOrder()
{
	CString strTemp;
	strTemp = m_Junction.GetDataOrder();
	return strTemp;
}

void OutPutRefData::SetJunDataOrder(CString strValue)
{
	m_RowArray.GetAt(2)->RemoveAll();
	m_RowArray.GetAt(2)->InitHead("Junction Data Order= ");
	m_RowArray.GetAt(2)->ReadChild(strValue);
}

CString OutPutRefData::GetJunUnitOrder()
{
	return m_Junction.GetUnitOrder();
}

void OutPutRefData::SetJunUnitOrder(CString strValue)
{
	m_RowArray.GetAt(3)->RemoveAll();
	m_RowArray.GetAt(3)->InitHead("Junction Data Units= ");
	m_RowArray.GetAt(3)->ReadChild(strValue);
}

CString OutPutRefData::GetPipeTranDataOrder()
{
	return m_PipeTran.GetDataOrder();
}

void OutPutRefData::SetPipeTranDataOrder(CString strValue)
{
	m_RowArray.GetAt(4)->RemoveAll();
	m_RowArray.GetAt(4)->InitHead("Pipe Transient Data Order= ");
	m_RowArray.GetAt(4)->ReadChild(strValue);
}

CString OutPutRefData::GetPipeTranUnitOrder()
{
	return m_PipeTran.GetUnitOrder();
}

void OutPutRefData::SetPipeTranUnitOrder(CString strValue)
{
	m_RowArray.GetAt(5)->RemoveAll();
	m_RowArray.GetAt(5)->InitHead("Pipe Transient Data Units= ");
	m_RowArray.GetAt(5)->ReadChild(strValue);
}

CString OutPutRefData::GetJunTranDataOrder()
{
	return m_JunTran.GetDataOrder();
}

void OutPutRefData::SetJunTranDataOrder(CString strValue)
{
	m_RowArray.GetAt(6)->RemoveAll();
	m_RowArray.GetAt(6)->InitHead("Jct Transient Data Order= ");
	m_RowArray.GetAt(6)->ReadChild(strValue);
}

CString OutPutRefData::GetJunTranUnitOrder()
{
	return m_JunTran.GetUnitOrder();
}

void OutPutRefData::SetJunTranUnitOrder(CString strValue)
{
	m_RowArray.GetAt(7)->RemoveAll();
	m_RowArray.GetAt(7)->InitHead("Jct Transient Data Units= ");
	m_RowArray.GetAt(7)->ReadChild(strValue);
}

CString OutPutRefData::GetPumpSummaryDataOrder()
{
	return m_PumpSummary.GetDataOrder();
}

void OutPutRefData::SetPumpSummaryDataOrder(CString strValue)
{
	m_RowArray.GetAt(8)->RemoveAll();
	m_RowArray.GetAt(8)->InitHead("Pump Summary Order= ");
	m_RowArray.GetAt(8)->ReadChild(strValue);
}

CString OutPutRefData::GetPumpSummaryUnitOrder()
{
	return m_PumpSummary.GetUnitOrder();
}

void OutPutRefData::SetPumpSummaryUnitOrder(CString strValue)
{
	m_RowArray.GetAt(9)->RemoveAll();
	m_RowArray.GetAt(9)->InitHead("Pump Summary Units= ");
	m_RowArray.GetAt(9)->ReadChild(strValue);
}

CString OutPutRefData::GetValveSummaryDataOrder()
{
	return m_ValveSummary.GetDataOrder();
}

void OutPutRefData::SetValveSummaryDataOrder(CString strValue)
{
	m_RowArray.GetAt(10)->RemoveAll();
	m_RowArray.GetAt(10)->InitHead("Valve Summary Order= ");
	m_RowArray.GetAt(10)->ReadChild(strValue);
}

CString OutPutRefData::GetValveSummaryUnitOrder()
{
	return m_ValveSummary.GetUnitOrder();
}

void OutPutRefData::SetValueSummaryUnitOrder(CString strValue)
{
	m_RowArray.GetAt(11)->RemoveAll();
	m_RowArray.GetAt(11)->ReadChild(strValue);
}

CString OutPutRefData::GetGeneralSectionOptions()
{
	CString strTemp;
	strTemp=m_GeneralSectionOptions.Save();
	return strTemp;
}



CString OutPutRefData::GetWrapHeaders()
{
	CString strTemp;
	strTemp=m_WrapHeaders.Save();
	return strTemp;
}

CString OutPutRefData::GetDigits()
{
	CString strTemp;
	m_Digits.ReadChild(strTemp);
	return strTemp;
}

CString OutPutRefData::GetUseExponential()
{
	CString strTemp;
	m_UseExponential.ReadChild(strTemp);
	return strTemp;
}

CString OutPutRefData::GetColumnAlign()
{
	CString strTemp;
	m_ColumnAlign.ReadChild(strTemp);
	return strTemp;
}

CString OutPutRefData::GetMagnitudeLimit()
{
	CString strTemp;
	m_MagnitudeLimit.ReadChild(strTemp);
	return strTemp;
}

CString OutPutRefData::GetOutputToPrinter()
{
	CString strTemp;
	m_OutputToPrinter.ReadChild(strTemp);
	return strTemp;
}

CString OutPutRefData::GetOutputToFile()
{
	CString strTemp;
	m_OutputToFile.ReadChild(strTemp);
	return strTemp;
}

CString OutPutRefData::GetAutoTransferResult()
{
	CString strTemp;
	m_AutoTransferResult.ReadChild(strTemp);
	return strTemp;
}

CString OutPutRefData::GetTransferValveState()
{
	CString strTemp;
	m_TransferValveState.ReadChild(strTemp);
	return strTemp;
}

CString OutPutRefData::GetSaveModelAfterTransfer()
{
	CString strTemp;
	m_SaveModelAfterTransfer.ReadChild(strTemp);
	return strTemp;
}

CString OutPutRefData::GetAnalysisTitle()
{
	CString strTemp;
	m_AnalysisTitle.ReadChild(strTemp);
	return strTemp;
}

CString OutPutRefData::GetAnalysisRef()
{
	CString strTemp;
	m_AnalysisRef.ReadChild(strTemp);
	return strTemp;
}

CString OutPutRefData::GetMaxMinTable()
{
	CString strTemp;
	m_MaxMinTable.ReadChild(strTemp);
	return strTemp;
}



BOOL OutPutRefData::Save(CStdioFile &file)
{
	CString strID = GetID();
	strID.TrimLeft();
	strID.TrimRight();
	if(0 == strID.CompareNoCase(_T("[OUTPUT PREFERENCES]")))
	{
		return SaveRow(file);
	}
	else
	{
		return SaveData(file);
	}
}
