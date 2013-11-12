// SettingData.cpp: implementation of the SettingData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SettingData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SettingData::SettingData()
{
	InitArray();
}

SettingData::~SettingData()
{

}

void SettingData::InitArray()
{
	if ( isImpFile )
	{
		m_RowArray.SetSize(29);
		m_RowArray.SetAt(0,&m_CheckFlags);
		m_RowArray.SetAt(1,&m_AnalysisType);
		m_RowArray.SetAt(2,&m_HPages);
		m_RowArray.SetAt(3,&m_VPages);
		m_RowArray.SetAt(4,&m_HSCValue);
		m_RowArray.SetAt(5,&m_VSCValue);
		m_RowArray.SetAt(6,&m_Zoom);
		m_RowArray.SetAt(7,&m_BackPath);
		m_RowArray.SetAt(8,&m_OutputFile);
		m_RowArray.SetAt(9,&m_PresTolType);
		m_RowArray.SetAt(10,&m_PresAbsTolType);
		m_RowArray.SetAt(11,&m_PresAbsTol);
		m_RowArray.SetAt(12,&m_PresRelTol);
		m_RowArray.SetAt(13,&m_FlowTolType);
		m_RowArray.SetAt(14,&m_FlowAbsTolType);
		m_RowArray.SetAt(15,&m_FlowAbsTol);
		m_RowArray.SetAt(16,&m_FlowRelTol);
		m_RowArray.SetAt(17,&m_RelaxationType);
		m_RowArray.SetAt(18,&m_FlowRelaxation);
		m_RowArray.SetAt(19,&m_PresRelaxation);
		m_RowArray.SetAt(20,&m_TempLimitUpper);
		m_RowArray.SetAt(21,&m_TempLimitLower);
		m_RowArray.SetAt(22,&m_FlowBalance);
		m_RowArray.SetAt(23,&m_MaximumIt);
		m_RowArray.SetAt(24,&m_ItHistory);
		m_RowArray.SetAt(25,&m_MatrixMethod);
		m_RowArray.SetAt(26,&m_GSRelax);
		m_RowArray.SetAt(27,&m_AutoDetect);
		m_RowArray.SetAt(28,&m_AutoRelax);
	} 
	else
	{
		m_RowArray.SetSize(34);
		m_RowArray.SetAt(0,&m_CheckFlags);
		m_RowArray.SetAt(1,&m_AnalysisType);
		m_RowArray.SetAt(2,&m_GSCAccess);
		m_RowArray.SetAt(3,&m_HPages);
		m_RowArray.SetAt(4,&m_VPages);
		m_RowArray.SetAt(5,&m_HSCValue);
		m_RowArray.SetAt(6,&m_VSCValue);
		m_RowArray.SetAt(7,&m_Zoom);
		m_RowArray.SetAt(8,&m_BackPath);
		m_RowArray.SetAt(9,&m_OutputFile);
		m_RowArray.SetAt(10,&m_PresTolType);
		m_RowArray.SetAt(11,&m_PresAbsTolType);
		m_RowArray.SetAt(12,&m_PresAbsTol);
		m_RowArray.SetAt(13,&m_PresRelTol);
		m_RowArray.SetAt(14,&m_TempTolType);
		m_RowArray.SetAt(15,&m_TempAbsTol);
		m_RowArray.SetAt(16,&m_TempRelTol);
		m_RowArray.SetAt(17,&m_FlowTolType);
		m_RowArray.SetAt(18,&m_FlowAbsTolType);
		m_RowArray.SetAt(19,&m_FlowAbsTol);
		m_RowArray.SetAt(20,&m_FlowRelTol);
		m_RowArray.SetAt(21,&m_RelaxationType);
		m_RowArray.SetAt(22,&m_FlowRelaxation);
		m_RowArray.SetAt(23,&m_PresRelaxation);
		m_RowArray.SetAt(24,&m_TempLimitUpper);
		m_RowArray.SetAt(25,&m_TempLimitLower);
		m_RowArray.SetAt(26,&m_FlowBalance);
		m_RowArray.SetAt(27,&m_EnergyBalance);
		m_RowArray.SetAt(28,&m_MaximumIt);
		m_RowArray.SetAt(29,&m_ItHistory);
		m_RowArray.SetAt(30,&m_MatrixMethod);
		m_RowArray.SetAt(31,&m_GSRelax);
		m_RowArray.SetAt(32,&m_AutoDetect);
		m_RowArray.SetAt(33,&m_AutoRelax);
	}
	InitRowHead();
}

void SettingData::Init()
{
	if ( isImpFile )
	{
		CString strArray[29];
		strArray[0] = _T("-1, -1, -1, -1, -1, -1");
		strArray[1] = _T("0");
		strArray[2] = _T("1");
		strArray[3] = _T("1");
		strArray[4] = _T("0");
		strArray[5] = _T("0");
		strArray[6] = _T("1");
		strArray[7] = _T("None");
		strArray[8] = _T("None");
		strArray[9] = _T("1");
		strArray[10] = _T("0");
		strArray[11] = _T("0,None");
		strArray[12] = _T(".00001");
		strArray[13] = _T("1");
		strArray[14] = _T("0");
		strArray[15] = _T("0,None");
		strArray[16] = _T(".00001");
		strArray[17] = _T("1");
		strArray[18] = _T(".1");
		strArray[19] = _T(".5");
		strArray[20] = _T("-10000,None");
		strArray[21] = _T("-10000,None");
		strArray[22] = _T("-1");
		strArray[23] = _T("50000");
		strArray[24] = _T("0 ");
		strArray[25] = _T("0");
		strArray[26] = _T("0");
		strArray[27] = _T("100");
		strArray[28] = _T("0");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==29);
			m_RowArray.GetAt(i)->ReadChild(strArray[i]);
		}
	} 
	else
	{
		CString strArray[34];
		strArray[0] = _T("-1, -1, -1, -1, 0, -1");
		strArray[1] = _T("1");
		strArray[2] = _T("0");
		strArray[3] = _T("1");
		strArray[4] = _T("1");
		strArray[5] = _T("0");
		strArray[6] = _T("0");
		strArray[7] = _T("1");
		strArray[8] = _T("None");
		strArray[9] = _T("None");
		strArray[10] = _T("1");
		strArray[11] = _T("0");
		strArray[12] = _T("0,None");
		strArray[13] = _T("0.00001");
		strArray[14] = _T("1");
		strArray[15] = _T("0,None");
		strArray[16] = _T("0");
		strArray[17] = _T("1");
		strArray[18] = _T("0");
		strArray[19] = _T("0,None");
		strArray[20] = _T("0.00001");
		strArray[21] = _T("0");
		strArray[22] = _T("0.1");
		strArray[23] = _T("0.5");
		strArray[24] = _T("-1,None");
		strArray[25] = _T("-1,None");
		strArray[26] = _T("-1");
		strArray[27] = _T("-1");
		strArray[28] = _T("50000");
		strArray[29] = _T("0 ");
		strArray[30] = _T("0");
		strArray[31] = _T("0");
		strArray[32] = _T("100");
		strArray[33] = _T("0");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==34);
			m_RowArray.GetAt(i)->ReadChild(strArray[i]);
	}
	}
}

void SettingData::InitRowHead()
{
	SetID("\n[SETTINGS]");
	if ( isImpFile )
	{
		CString strArray[29];
		strArray[0] = _T("ChecklistFlags= ");
		strArray[1] = _T("AnalysisType=");
		strArray[2] = _T("HPages=");
		strArray[3] = _T("VPages=");
		strArray[4] = _T("HSCValue=");
		strArray[5] = _T("VSCValue=");
		strArray[6] = _T("Zoom=");
		strArray[7] = _T("BackgroundPicturePath=");
		strArray[8] = _T("OutputFile=");
		strArray[9] = _T("PresTolType= ");
		strArray[10] = _T("PresAbsTolType=");
		strArray[11] = _T("PresAbsTol=");
		strArray[12] = _T("PresRelTol=");
		strArray[13] = _T("FlowTolType=");
		strArray[14] = _T("FlowAbsTolType= ");
		strArray[15] = _T("FlowAbsTol= ");
		strArray[16] = _T("FlowRelTol=");
		strArray[17] = _T("RelaxationType=");
		strArray[18] = _T("FlowRelaxation=");
		strArray[19] = _T("PresRelaxation=");
		strArray[20] = _T("TempLimitUpper=");
		strArray[21] = _T("TempLimitLower=");
		strArray[22] = _T("FlowBalance=");
		strArray[23] = _T("Maximum Iterations=");
		strArray[24] = _T("Keep Iteration History= ");
		strArray[25] = _T("Matrix Method= ");
		strArray[26] = _T("GS Relax=");
		strArray[27] = _T("AutoDetect=");
		strArray[28] = _T("AutoRelax=");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==29);
			m_RowArray.GetAt(i)->InitHead(strArray[i]);
		}
	} 
	else
	{
		CString strArray[34];
		strArray[0] = _T("ChecklistFlags= ");
		strArray[1] = _T("AnalysisType= ");
		strArray[2] = _T("GSC Access= ");
		strArray[3] = _T("HPages= ");
		strArray[4] = _T("VPages= ");
		strArray[5] = _T("HSCValue= ");
		strArray[6] = _T("VSCValue= ");
		strArray[7] = _T("Zoom= ");
		strArray[8] = _T("BackgroundPicturePath= ");
		strArray[9] = _T("OutputFile= ");
		strArray[10] = _T("PresTolType= ");
		strArray[11] = _T("PresAbsTolType= ");
		strArray[12] = _T("PresAbsTol= ");
		strArray[13] = _T("PresRelTol= ");
		strArray[14] = _T("TempTolType= ");
		strArray[15] = _T("TempAbsTol= ");
		strArray[16] = _T("TempRelTol= ");
		strArray[17] = _T("FlowTolType= ");
		strArray[18] = _T("FlowAbsTolType= ");
		strArray[19] = _T("FlowAbsTol= ");
		strArray[20] = _T("FlowRelTol= ");
		strArray[21] = _T("RelaxationType= ");
		strArray[22] = _T("FlowRelaxation= ");
		strArray[23] = _T("PresRelaxation= ");
		strArray[24] = _T("TempLimitUpper= ");
		strArray[25] = _T("TempLimitLower= ");
		strArray[26] = _T("FlowBalance= ");
		strArray[27] = _T("EnergyBalance= ");
		strArray[28] = _T("Maximum Iterations= ");
		strArray[29] = _T("Keep Iteration History= ");
		strArray[30] = _T("Matrix Method= ");
		strArray[31] = _T("GS Relax= ");
		strArray[32] = _T("AutoDetect= ");
		strArray[33] = _T("AutoRelax= ");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==34);
			m_RowArray.GetAt(i)->InitHead(strArray[i]);
		}
	}	
}

BOOL SettingData::Read(CStdioFile &file)
{
	return ReadData(file);
}

BOOL SettingData::Save(CStdioFile &file)
{
	return SaveData(file);
}

/*------------------------------------------*/
CString SettingData::AnalysisType()
{
	CString strValue;
	m_AnalysisType.GetData(strValue,1);
	return strValue;
}
void SettingData::AnalysisType(CString strValue)
{
	if(!m_AnalysisType.SetData(strValue,1))
	{
		m_AnalysisType.ReadChild("0");
		m_AnalysisType.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SettingData::PresTolType()
{
	CString strValue;
	m_PresTolType.GetData(strValue,1);
	return strValue;
}
void SettingData::PresTolType(CString strValue)
{
	if(!m_PresTolType.SetData(strValue,1))
	{
		m_PresTolType.ReadChild("1");
		m_PresTolType.SetData(strValue,1);
	}
}
/*------------------------------------------*/
StrArray<2> SettingData::PresAbsTol()
{
	StrArray<2> strArray;
	CString strValue;
	m_PresAbsTol.GetData(strValue,1);
	strArray.Data(strValue);
	m_PresAbsTol.GetData(strValue,2);
	strArray.Data(strValue,1);
	return strArray;
}
void SettingData::PresAbsTol(const StrArray<2>& strValue)
{
	if(!m_PresAbsTol.SetData(strValue.Data(),1))
	{
		m_PresAbsTol.ReadChild("0,None");
	}
	m_PresAbsTol.SetData(strValue.Data(),1);
	m_PresAbsTol.SetData(strValue.Data(1),2);
}
/*------------------------------------------*/
CString SettingData::PresRelTol()
{
	CString strValue;
	m_PresRelTol.GetData(strValue,1);
	return strValue;
}
void SettingData::PresRelTol(CString strValue)
{
	if(!m_PresRelTol.SetData(strValue,1))
	{
		m_PresRelTol.ReadChild("0.00001");
		m_PresRelTol.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SettingData::FlowTolType()
{
	CString strValue;
	m_FlowTolType.GetData(strValue,1);
	return strValue;
}
void SettingData::FlowTolType(CString strValue)
{
	if(!m_FlowTolType.SetData(strValue,1))
	{
		m_FlowTolType.ReadChild("1");
		m_FlowTolType.SetData(strValue,1);
	}
}
/*------------------------------------------*/
StrArray<2> SettingData::FlowAbsTol()
{
	StrArray<2> strArray;
	CString strValue;
	m_FlowAbsTol.GetData(strValue,1);
	strArray.Data(strValue);
	m_FlowAbsTol.GetData(strValue,2);
	strArray.Data(strValue,1);
	return strArray;
}
void SettingData::FlowAbsTol(const StrArray<2>& strValue)
{
	if(!m_FlowAbsTol.SetData(strValue.Data(),1))
	{
		m_FlowAbsTol.ReadChild("0,None");
	}
	m_FlowAbsTol.SetData(strValue.Data(),1);
	m_FlowAbsTol.SetData(strValue.Data(1),2);
}
/*------------------------------------------*/
CString SettingData::FlowRelTol()
{
	CString strValue;
	m_FlowRelTol.GetData(strValue,1);
	return strValue;
	
}
void SettingData::FlowRelTol(CString strValue)
{
	if(!m_FlowRelTol.SetData(strValue,1))
	{
		m_FlowRelTol.ReadChild("1");
		m_FlowRelTol.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SettingData::RelaxationType()
{
	CString strValue;
	m_RelaxationType.GetData(strValue,1);
	return strValue;
}
void SettingData::RelaxationType(CString strValue)
{
	if(!m_RelaxationType.SetData(strValue,1))
	{
		m_RelaxationType.ReadChild("1");
		m_RelaxationType.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SettingData::FlowRelaxation()
{
	CString strValue;
	m_FlowRelaxation.GetData(strValue,1);
	return strValue;
}
void SettingData::FlowRelaxation(CString strValue)
{
	if(!m_FlowRelaxation.SetData(strValue,1))
	{
		m_FlowRelaxation.ReadChild("1");
		m_FlowRelaxation.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SettingData::PresRelaxation()
{
	CString strValue;
	m_PresRelaxation.GetData(strValue,1);
	return strValue;
}
void SettingData::PresRelaxation(CString strValue)
{
	if(!m_PresRelaxation.SetData(strValue,1))
	{
		m_PresRelaxation.ReadChild("1");
		m_PresRelaxation.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SettingData::MaxIterations()
{
	CString strValue;
	m_MaximumIt.GetData(strValue,1);
	return strValue;
}
void SettingData::MaxIterations(CString strValue)
{
	if(!m_MaximumIt.SetData(strValue,1))
	{
		m_MaximumIt.ReadChild("1");
		m_MaximumIt.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SettingData::KeepHistory()
{
	CString strValue;
	m_ItHistory.GetData(strValue,1);
	return strValue;
}
void SettingData::KeepHistory(CString strValue)
{
	if(!m_ItHistory.SetData(strValue,1))
	{
		m_ItHistory.ReadChild("1");
		m_ItHistory.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SettingData::MatrixMethod()
{
	CString strValue;
	m_MatrixMethod.GetData(strValue,1);
	return strValue;
}
void SettingData::MatrixMethod(CString strValue)
{
	if(!m_MatrixMethod.SetData(strValue,1))
	{
		m_MatrixMethod.ReadChild("1");
		m_MatrixMethod.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SettingData::AutoDetect()
{
	CString strValue;
	m_AutoDetect.GetData(strValue,1);
	return strValue;
}
void SettingData::AutoDetect(CString strValue)
{
	if(!m_AutoDetect.SetData(strValue,1))
	{
		m_AutoDetect.ReadChild("1");
		m_AutoDetect.SetData(strValue,1);
	}
}





/*------------------------------------------*/
CString SettingData::GSCAccess()
{
	CString strValue;
	m_GSCAccess.GetData(strValue,1);
	return strValue;
}
void SettingData::GSCAccess(CString strValue)
{
	if(!m_GSCAccess.SetData(strValue,1))
	{
		m_GSCAccess.ReadChild("1");
		m_GSCAccess.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SettingData::TempTolType()
{
	CString strValue;
	m_TempTolType.GetData(strValue,1);
	return strValue;
}
void SettingData::TempTolType(CString strValue)
{
	if(!m_TempTolType.SetData(strValue,1))
	{
		m_TempTolType.ReadChild("1");
		m_TempTolType.SetData(strValue,1);
	}
}
/*------------------------------------------*/
StrArray<2> SettingData::TempAbsTol()
{
	StrArray<2> strArray;
	CString strValue;
	m_TempAbsTol.GetData(strValue,1);
	strArray.Data(strValue);
	m_TempAbsTol.GetData(strValue,2);
	strArray.Data(strValue,1);
	return strArray;
}
void SettingData::TempAbsTol(const StrArray<2>& strValue)
{
	if(!m_TempAbsTol.SetData(strValue.Data(),1))
	{
		m_TempAbsTol.ReadChild("0,None");
	}
	m_TempAbsTol.SetData(strValue.Data(),1);
	m_TempAbsTol.SetData(strValue.Data(1),2);
}
/*------------------------------------------*/
CString SettingData::TempRelTol()
{
	CString strValue;
	m_TempRelTol.GetData(strValue,1);
	return strValue;
}
void SettingData::TempRelTol(CString strValue)
{
	if(!m_TempRelTol.SetData(strValue,1))
	{
		m_TempRelTol.ReadChild("1");
		m_TempRelTol.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString SettingData::EnergyBalance()
{
	CString strValue;
	m_EnergyBalance.GetData(strValue,1);
	return strValue;
}
void SettingData::EnergyBalance(CString strValue)
{
	if(!m_EnergyBalance.SetData(strValue,1))
	{
		m_EnergyBalance.ReadChild("1");
		m_EnergyBalance.SetData(strValue,1);
	}
}