// AFTTransDataFace.cpp: implementation of the AFTTransDataFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTTransDataFace.h"
#include "AFTTwoDTableFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTTransDataFace::AFTTransDataFace()
{

}

AFTTransDataFace::~AFTTransDataFace()
{

}

ErrorStatus::FileError AFTTransDataFace::Read(JunTransData &Data,TransDataPersistent &Model)
{
	AFTTableFace face;
	Model.ValueType(Data.ValueType());
	Model.Special(Data.Special());
	Model.Repeat1(Data.Repeat1());
	Model.Repeat2(Data.Repeat2());
	Model.TranType(Data.TranType());
	Model.Periodic(Data.Periodic());
	Model.TranTriger1(Data.TranTriger1());
	Model.TranTriger2(Data.TranTriger2());
	Model.TranModel(Data.TranModel());
	Model.RotateInertia(Data.RotateInertia());
	Model.Speed(Data.Speed());
	Model.FourQuadrant(Data.FourQuadrant());
	face.Read(Data.m_Trans1Table,Model.m_Trans1Table);
	face.Read(Data.m_Trans2Table,Model.m_Trans2Table);
	face.Read(Data.m_FourquadTable,Model.m_FourquadTable);
	return ErrorStatus::eFileOK;
}

ErrorStatus::FileError AFTTransDataFace::Save(JunTransData &Data,TransDataPersistent &Model)
{
	AFTTableFace face;
	Data.ValueType(Model.ValueType());
	Data.Special(Model.Special());
	Data.Repeat1(Model.Repeat1());
	Data.Repeat2(Model.Repeat2());
	Data.TranType(Model.TranType());
	Data.Periodic(Model.Periodic());
	Data.TranTriger1(Model.TranTriger1());
	Data.TranTriger2(Model.TranTriger2());
	Data.TranModel(Model.TranModel());
	Data.RotateInertia(Model.RotateInertia());
	Data.Speed(Model.Speed());
	Data.FourQuadrant(Model.FourQuadrant());
	face.Save(Data.m_Trans1Table,Model.m_Trans1Table);
	face.Save(Data.m_Trans2Table,Model.m_Trans2Table);
	face.Save(Data.m_FourquadTable,Model.m_FourquadTable);

	return ErrorStatus::eFileOK;
}