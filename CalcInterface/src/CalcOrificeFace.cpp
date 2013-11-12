// CalcOrificeFace.cpp: implementation of the CalcOrificeFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcOrificeFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcOrificeFace::CalcOrificeFace()
{

}

CalcOrificeFace::~CalcOrificeFace()
{

}

ErrorStatus::FileError CalcOrificeFace::Save(CalcOrifice &Data,StrArray<5> &Model)
{
	Data.Model(Model.nData(0));
	Data.InFlowCD(Model.fData(1));
	Data.OutFlowCD(Model.fData(2));
	Data.Area(TransStd(Model.Data(3),Model.Data(4)));
	return ErrorStatus::eFileOK;
}