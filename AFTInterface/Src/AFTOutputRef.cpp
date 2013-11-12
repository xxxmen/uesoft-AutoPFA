// AFTOutputRef.cpp: implementation of the AFTOutputRef class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTOutputRef.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTOutputRef::AFTOutputRef()
{

}

AFTOutputRef::~AFTOutputRef()
{

}

ErrorStatus::FileError AFTOutputRef::Read(OutPutRefData &Data,OutputRefPersist &model)
{	
	model.PipeDataOrder(Data.GetPipeDataOrder());
	model.PipeUnitOrder(Data.GetPipeUnitOrder());
	model.JunDataOrder(Data.GetJunDataOrder());
	model.JunUnitOrder(Data.GetJunUnitOrder());
	

// 	model.JunDataOrder(Data.GetJunDataOrder());
// 	model.JunUnitOrder(Data.GetJunUnitOrder());

    
	return ErrorStatus::eFileOK;
}

ErrorStatus::FileError AFTOutputRef::Save(OutPutRefData &Data,OutputRefPersist& model)
{
	Data.SetPipeDataOrder(model.PipeDataOrder());
	Data.SetPipeUnitOrder(model.PipeUnitOrder());
	Data.SetJunDataOrder(model.JunDataOrder());
	Data.SetJunUnitOrder(model.JunUnitOrder());
	return ErrorStatus::eFileOK;
}