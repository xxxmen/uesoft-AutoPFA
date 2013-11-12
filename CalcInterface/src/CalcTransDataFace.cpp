// CalcTransDataFace.cpp: implementation of the CalcTransDataFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcTransDataFace.h"
#include "CalcTransData.h"
#include "TransDataPersistent.h"
#include "CalcPeriodicFace.h"
#include "CalcTrigerFace.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcTransDataFace::CalcTransDataFace()
{

}

CalcTransDataFace::~CalcTransDataFace()
{

}

ErrorStatus::FileError CalcTransDataFace::Save(CalcTransData &Data,TransDataPersistent &Model)
{
	CalcPeriodicFace face1;
	CalcTrigerFace face2;
	Data.ValueType(_atoi(Model.ValueType()));
	Data.Special(_atoi(Model.Special()));
	Data.Repeat1(_atoi(Model.Repeat1()));
	Data.Repeat2(_atoi(Model.Repeat2()));
	Data.TranType(_atoi(Model.TranType()));
	face1.Save(Data.m_Periodic,Model.Periodic());
	face2.Save(Data.m_Triger1,Model.TranTriger1());
	face2.Save(Data.m_Triger2,Model.TranTriger2());
	Data.m_TranData1.SetData(Model.m_Trans1Table.DataToStd());
	Data.m_TranData2.SetData(Model.m_Trans2Table.DataToStd());
	return ErrorStatus::eFileOK;
}