// CalcCurveFace.cpp: implementation of the CalcCurveFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcCurveFace.h"
#include "CalcCurve.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcCurveFace::CalcCurveFace()
{

}

CalcCurveFace::~CalcCurveFace()
{

}

ErrorStatus::FileError CalcCurveFace::LossType(int &Data,StrArray<13> &Model)
{
	Data = Model.nData(0);
	return ErrorStatus::eFileOK;
}

ErrorStatus::FileError CalcCurveFace::Save(CalcCurve &Data,StrArray<13> &Model)
{
	CString strXUnit;
	CString strYUnit;
	double dXRatio = 0;
	double dYRatio = 0;
	Data.YAxisType(Model.nData(1));
	strYUnit = Model.Data(2);
	Data.XAxisType(Model.nData(3));
	strXUnit = Model.Data(4);
	Data.MaxX(TransStd(Model.Data(5),strXUnit));
	Data.CurveType(Model.nData(6));
	Data.Order(Model.nData(7));
	dXRatio = TransFromStd(1,strXUnit);
	dYRatio = TransFromStd(1,strYUnit);//y*dYRatio = a + b*dXRatio*x +c**dXRatio2*x2
	Data.A(Model.fData(8)/dYRatio);
	Data.B(Model.fData(9)*dXRatio/dYRatio);
	Data.C(Model.fData(10)*pow(dXRatio,2)/dYRatio);
	Data.D(Model.fData(11)*pow(dXRatio,3)/dYRatio);
	Data.E(Model.fData(12)*pow(dXRatio,4)/dYRatio);
	return ErrorStatus::eFileOK;
}

ErrorStatus::FileError CalcCurveFace::Save(CalcCurve &Data,StrArray<7> &Model,CString strXUnit,CString strYUnit)
{
	double dXRatio = 0;
	double dYRatio = 0;
	Data.CurveType(Model.nData(0));
	Data.Order(Model.nData(1));
	dXRatio = TransFromStd(1,strXUnit);
	dYRatio = TransFromStd(1,strYUnit);//y*dYRatio = a + b*dXRatio*x +c**dXRatio2*x2
	Data.A(Model.fData(2)/dYRatio);
	Data.B(Model.fData(3)*dXRatio/dYRatio);
	Data.C(Model.fData(4)*pow(dXRatio,2)/dYRatio);
	Data.D(Model.fData(5)*pow(dXRatio,3)/dYRatio);
	Data.E(Model.fData(6)*pow(dXRatio,4)/dYRatio);
	return ErrorStatus::eFileOK;
}

ErrorStatus::FileError CalcCurveFace::fireK(double &Data,StrArray<13> &Model)
{
	CString strXUnit;
	CString strYUnit;
	double dXRatio = 0;
	double dYRatio = 0;
	strYUnit = Model.Data(2);
	strXUnit = Model.Data(4);
	dXRatio = TransStd(1,strXUnit);
	dYRatio = TransStd(1,strYUnit);
	if(dYRatio < 0)
	{
		ASSERT(FALSE);
		return ErrorStatus::eSaveFileError;
	}
	Data = dXRatio/sqrt(dYRatio);
	return ErrorStatus::eFileOK;
}