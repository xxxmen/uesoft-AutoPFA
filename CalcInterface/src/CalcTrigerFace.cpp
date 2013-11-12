// CalcTrigerFace.cpp: implementation of the CalcTrigerFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcTrigerFace.h"
#include "CalcTriger.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcTrigerFace::CalcTrigerFace()
{

}

CalcTrigerFace::~CalcTrigerFace()
{

}

ErrorStatus::FileError CalcTrigerFace::Save(CalcTriger &Data,StrArray<8> &Model)
{
	Data.EventType(Model.nData(0));
	Data.ConditionType(Model.nData(1));
	Data.Value(TransStd(Model.Data(2),Model.Data(3)));
	Data.Port1(Model.nData(4));
	Data.ComponentID1(Model.nData(5));
	Data.Port2(Model.nData(6));
	Data.ComponentID2(Model.nData(7));
	return ErrorStatus::eFileOK;
}