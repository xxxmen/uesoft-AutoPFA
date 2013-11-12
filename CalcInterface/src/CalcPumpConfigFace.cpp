// CalcPumpConfigFace.cpp: implementation of the CalcPumpConfigFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcPumpConfigFace.h"
#include "CalcPumpConfig.h"
#include "onfigPerisist.h"
#include "CalcCurveFace.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcPumpConfigFace::CalcPumpConfigFace()
{

}

CalcPumpConfigFace::~CalcPumpConfigFace()
{

}
ErrorStatus::FileError CalcPumpConfigFace::Save(CalcPumpConfig &Data,ConfigPerisist &Model)
{
	// TODO: Add extra Save here
	CalcCurveFace face;
	CString strPressUnit = Model.PressUnit();
	CString strFlowUnit = Model.FlowUnit();
	CString strPowerUnit = Model.PowerUnit();
	Data.PressType(_ttoi(Model.PressType()));
	Data.FlowType(_ttoi(Model.FlowType()));
	Data.PowerType(_ttoi(Model.PowerType()));

	ConfigItemPerisist *pConfigItem = Model.GetHead();
	if(pConfigItem != NULL)
	{
		CString strData = pConfigItem->BEP().Data();
		if(strData.IsEmpty()||strData==_T("0"))
		{
			Data.CalcBEP(TRUE);
		}
		else
		{
			Data.CalcBEP(FALSE);
		}
		Data.BEP(TransStd(pConfigItem->BEP()));
		StrArray<3> &ref = pConfigItem->CurveEndFlow();
		Data.EndFlow(TransStd(ref.Data(1),ref.Data(2)));
		Data.Affiniity(strtod(pConfigItem->Affiniity()));
		Data.MaxFlow(TransStd(pConfigItem->MaxFlow(),strFlowUnit));
		face.Save(Data.m_CurveHQ,pConfigItem->Curve1(),strFlowUnit,strPressUnit);
		face.Save(Data.m_CurveNPSHR,pConfigItem->Curve2(),strFlowUnit,strPressUnit);
		face.Save(Data.m_CurvePower,pConfigItem->Curve3(),strFlowUnit,strPowerUnit);
		Data.CurveData(pConfigItem->m_RawData.DataToStd());
	}
	return ErrorStatus::eFileOK;
}