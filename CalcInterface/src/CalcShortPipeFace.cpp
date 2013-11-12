// CalcShortPipeFace.cpp: implementation of the CalcShortPipeFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcShortPipeFace.h"
#include "CalcShortPipe.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcShortPipeFace::CalcShortPipeFace()
{

}

CalcShortPipeFace::~CalcShortPipeFace()
{

}

ErrorStatus::FileError CalcShortPipeFace::Save(CalcShortPipe &Data,StrArray<10> &Model)
{
	Data.Model(Model.nData(0));
	Data.Friction(Model.fData(1));
	Data.InDia(TransStd(Model.Data(2),Model.Data(3)));
	Data.Area(TransStd(Model.Data(4),Model.Data(5)));
	Data.Len(TransStd(Model.Data(6),Model.Data(7)));
	Data.Ele(TransStd(Model.Data(8),Model.Data(9)));
	return ErrorStatus::eFileOK;
}