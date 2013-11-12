// TranContorlData.cpp: implementation of the TranContorlData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TranContorlData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TranContorlData::TranContorlData()
{
	InitArray();
}

TranContorlData::~TranContorlData()
{

}

void TranContorlData::InitRowHead()
{
	SetID("\n[TRANSIENT CONTROL]");
	if ( isImpFile )
	{
		CString strArray[11];
		strArray[0] = _T("StartTime=");
		strArray[1] = _T("StopTime=");
		strArray[2] = _T("TimeUnits=");
		strArray[3] = _T("Frequency=");
		strArray[4] = _T("ModelCavitation=");
		strArray[5] = _T("VariableResistance=");
		strArray[6] = _T("StopOnArtificialTransient=");
		strArray[7] = _T("Criteria=");
		strArray[8] = _T("CriteriaMinFlow=");
		strArray[9] = _T("CriteriaMinFlowUnits=");
		strArray[10] = _T("TotalSteps=");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==11);
			m_RowArray.GetAt(i)->InitHead(strArray[i]);
		}
	} 
	else
	{
		CString strArray[13];
		strArray[0] = _T("StartTime= ");
		strArray[1] = _T("StopTime= ");
		strArray[2] = _T("TimeStep= ");
		strArray[3] = _T("TimeUnits= ");
		strArray[4] = _T("TimeStepUnits= ");
		strArray[5] = _T("Frequency= ");
		strArray[6] = _T("TotalSteps= ");
		strArray[7] = _T("DifferenceMethod= ");
		strArray[8] = _T("RelativeTolerance= ");
		strArray[9] = _T("AbsoluteTolerance= ");
		strArray[10] = _T("AbsoluteToleranceUnits= ");
		strArray[11] = _T("MaxIterations= ");
		strArray[12] = _T("Relaxation= ");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==13);
			m_RowArray.GetAt(i)->InitHead(strArray[i]);
		}
	}
}

void TranContorlData::InitArray()
{
	if ( isImpFile )
	{
		m_RowArray.SetSize(11);
		m_RowArray.SetAt(0,&m_StartTime);
		m_RowArray.SetAt(1,&m_StopTime);
		m_RowArray.SetAt(2,&m_TimeUnits);
		m_RowArray.SetAt(3,&m_Frequency);
		m_RowArray.SetAt(4,&m_ModelCavitation);
		m_RowArray.SetAt(5,&m_VariableR);
		m_RowArray.SetAt(6,&m_StopTran);
		m_RowArray.SetAt(7,&m_Criteria);
		m_RowArray.SetAt(8,&m_CriteriaMinFlow);
		m_RowArray.SetAt(9,&m_CriteriaMinFlowUnits);
		m_RowArray.SetAt(10,&m_TotalSteps);
	} 
	else
	{
		m_RowArray.SetSize(13);
		m_RowArray.SetAt(0,&m_StartTime);
		m_RowArray.SetAt(1,&m_StopTime);
		m_RowArray.SetAt(2,&m_TimeStep);
		m_RowArray.SetAt(3,&m_TimeUnits);
		m_RowArray.SetAt(4,&m_TimeStepUnits);
		m_RowArray.SetAt(5,&m_Frequency);
		m_RowArray.SetAt(6,&m_TotalSteps);
		m_RowArray.SetAt(7,&m_DifferenceMethod);
		m_RowArray.SetAt(8,&m_RelativeTolerance);
		m_RowArray.SetAt(9,&m_AbsoluteTolerance);
		m_RowArray.SetAt(10,&m_AbsoluteToleranceUnits);
		m_RowArray.SetAt(11,&m_MaxIterations);
		m_RowArray.SetAt(12,&m_Relaxation);
	}
	InitRowHead();
}

void TranContorlData::Init()
{
	if ( isImpFile )
	{
		CString strArray[11];
		strArray[0] = _T("0");
		strArray[1] = _T("1");
		strArray[2] = _T("seconds");
		strArray[3] = _T("1");
		strArray[4] = _T("1");
		strArray[5] = _T("0");
		strArray[6] = _T("-1");
		strArray[7] = _T(".5");
		strArray[8] = _T("0");
		strArray[9] = _T("kg/sec");
		strArray[10] = _T("0");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==11);
			m_RowArray.GetAt(i)->ReadChild(strArray[i]);
		}
	} 
	else
	{
		CString strArray[13];
		strArray[0] = _T("0");
		strArray[1] = _T("-1");
		strArray[2] = _T("1");
		strArray[3] = _T("hours");
		strArray[4] = _T("hours");
		strArray[5] = _T("1");
		strArray[6] = _T("-1");
		strArray[7] = _T("0");
		strArray[8] = _T("0.00001");
		strArray[9] = _T("0.0001");
		strArray[10] = _T("feet");
		strArray[11] = _T("10000");
		strArray[12] = _T("1");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==13);
			m_RowArray.GetAt(i)->ReadChild(strArray[i]);
		}
	}
}

BOOL TranContorlData::Read(CStdioFile &file)
{
	return ReadData(file);
}

BOOL TranContorlData::Save(CStdioFile &file)
{
	return SaveData(file);
}


/*------------------------------------------*/
CString TranContorlData::StartTime()
{
	CString strValue;
	m_StartTime.GetData(strValue,1);
	return strValue;
}
void TranContorlData::StartTime(CString strValue)
{
	if(!m_StartTime.SetData(strValue,1))
	{
		m_StartTime.ReadChild("0");
		m_StartTime.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::StopTime()
{
	CString strValue;
	m_StopTime.GetData(strValue,1);
	return strValue;
}
void TranContorlData::StopTime(CString strValue)
{
	if(!m_StopTime.SetData(strValue,1))
	{
		m_StopTime.ReadChild("1");
		m_StopTime.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::TimeUnit()
{
	CString strValue;
	m_TimeUnits.GetData(strValue,1);
	return strValue;
}
void TranContorlData::TimeUnit(CString strValue)
{
	if(!m_TimeUnits.SetData(strValue,1))
	{
		m_TimeUnits.ReadChild("seconds");
		m_TimeUnits.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::Frequency()
{
	CString strValue;
	m_Frequency.GetData(strValue,1);
	return strValue;
}
void TranContorlData::Frequency(CString strValue)
{
	if(!m_Frequency.SetData(strValue,1))
	{
		m_Frequency.ReadChild("1");
		m_Frequency.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::Cavitation()
{
	CString strValue;
	m_ModelCavitation.GetData(strValue,1);
	return strValue;
}
void TranContorlData::Cavitation(CString strValue)
{
	if(!m_ModelCavitation.SetData(strValue,1))
	{
		m_ModelCavitation.ReadChild("1");
		m_ModelCavitation.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::VariableR()
{
	CString strValue;
	m_VariableR.GetData(strValue,1);
	return strValue;
}
void TranContorlData::VariableR(CString strValue)
{
	if(!m_VariableR.SetData(strValue,1))
	{
		m_VariableR.ReadChild("0");
		m_VariableR.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::Artificial()
{
	CString strValue;
	m_StopTran.GetData(strValue,1);
	return strValue;
}
void TranContorlData::Artificial(CString strValue)
{
	if(!m_StopTran.SetData(strValue,1))
	{
		m_StopTran.ReadChild("-1");
		m_StopTran.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::Criteria()
{
	CString strValue;
	m_Criteria.GetData(strValue,1);
	return strValue;
}
void TranContorlData::Criteria(CString strValue)
{
	if(!m_Criteria.SetData(strValue,1))
	{
		m_Criteria.ReadChild("0.05");
		m_Criteria.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::MinFlow()
{
	CString strValue;
	m_CriteriaMinFlow.GetData(strValue,1);
	return strValue;
}
void TranContorlData::MinFlow(CString strValue)
{
	if(!m_CriteriaMinFlow.SetData(strValue,1))
	{
		m_CriteriaMinFlow.ReadChild("0");
		m_CriteriaMinFlow.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::MinFlowUnit()
{
	CString strValue;
	m_CriteriaMinFlowUnits.GetData(strValue,1);
	return strValue;
}
void TranContorlData::MinFlowUnit(CString strValue)
{
	if(!m_CriteriaMinFlowUnits.SetData(strValue,1))
	{
		m_CriteriaMinFlowUnits.ReadChild("kg/sec");
		m_CriteriaMinFlowUnits.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::TotalSteps()
{
	CString strValue;
	m_TotalSteps.GetData(strValue,1);
	return strValue;
}
void TranContorlData::TotalSteps(CString strValue)
{
	if(!m_TotalSteps.SetData(strValue,1))
	{
		m_TotalSteps.ReadChild("0");
		m_TotalSteps.SetData(strValue,1);
	}
}



/*------------------------------------------*/
CString TranContorlData::TimeStep()
{
	CString strValue;
	m_TimeStep.GetData(strValue,1);
	return strValue;
}
void TranContorlData::TimeStep(CString strValue)
{
	if(!m_TimeStep.SetData(strValue,1))
	{
		m_TimeStep.ReadChild("0");
		m_TimeStep.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::TimeStepUnits()
{
	CString strValue;
	m_TimeStepUnits.GetData(strValue,1);
	return strValue;
}
void TranContorlData::TimeStepUnits(CString strValue)
{
	if(!m_TimeStepUnits.SetData(strValue,1))
	{
		m_TimeStepUnits.ReadChild("0");
		m_TimeStepUnits.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::DifferenceMethod()
{
	CString strValue;
	m_DifferenceMethod.GetData(strValue,1);
	return strValue;
}
void TranContorlData::DifferenceMethod(CString strValue)
{
	if(!m_DifferenceMethod.SetData(strValue,1))
	{
		m_DifferenceMethod.ReadChild("0");
		m_DifferenceMethod.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::RelativeTolerance()
{
	CString strValue;
	m_RelativeTolerance.GetData(strValue,1);
	return strValue;
}
void TranContorlData::RelativeTolerance(CString strValue)
{
	if(!m_RelativeTolerance.SetData(strValue,1))
	{
		m_RelativeTolerance.ReadChild("0");
		m_RelativeTolerance.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::AbsoluteTolerance()
{
	CString strValue;
	m_AbsoluteTolerance.GetData(strValue,1);
	return strValue;
}
void TranContorlData::AbsoluteTolerance(CString strValue)
{
	if(!m_AbsoluteTolerance.SetData(strValue,1))
	{
		m_AbsoluteTolerance.ReadChild("0");
		m_AbsoluteTolerance.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::AbsoluteToleranceUnits()
{
	CString strValue;
	m_AbsoluteToleranceUnits.GetData(strValue,1);
	return strValue;
}
void TranContorlData::AbsoluteToleranceUnits(CString strValue)
{
	if(!m_AbsoluteToleranceUnits.SetData(strValue,1))
	{
		m_AbsoluteToleranceUnits.ReadChild("0");
		m_AbsoluteToleranceUnits.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::MaxIterations()
{
	CString strValue;
	m_MaxIterations.GetData(strValue,1);
	return strValue;
}
void TranContorlData::MaxIterations(CString strValue)
{
	if(!m_MaxIterations.SetData(strValue,1))
	{
		m_MaxIterations.ReadChild("0");
		m_MaxIterations.SetData(strValue,1);
	}
}
/*------------------------------------------*/
CString TranContorlData::Relaxation()
{
	CString strValue;
	m_Relaxation.GetData(strValue,1);
	return strValue;
}
void TranContorlData::Relaxation(CString strValue)
{
	if(!m_Relaxation.SetData(strValue,1))
	{
		m_Relaxation.ReadChild("0");
		m_Relaxation.SetData(strValue,1);
	}
}