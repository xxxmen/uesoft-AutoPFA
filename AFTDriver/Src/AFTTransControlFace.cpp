// AFTTransControlFace.cpp: implementation of the AFTTransControlFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTTransControlFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTTransControlFace::AFTTransControlFace()
{

}

AFTTransControlFace::~AFTTransControlFace()
{

}
ErrorStatus::FileError AFTTransControlFace::Read(TranContorlData &Data,TransControlPerisistent& model)
{
	model.StartTime(Data.StartTime());
	model.StopTime(Data.StopTime());
	model.TimeUnit(Data.TimeUnit());
	model.Frequency(Data.Frequency());
	model.Cavitation(Data.Cavitation());
	model.VariableR(Data.VariableR());
	model.Artificial(Data.Artificial());
	model.Criteria(Data.Criteria());
	model.MinFlow(Data.MinFlow());
	model.MinFlowUnit(Data.MinFlowUnit());
	model.TotalSteps(Data.TotalSteps());
	return ErrorStatus::eFileOK;
}
ErrorStatus::FileError AFTTransControlFace::Save(TranContorlData &Data,TransControlPerisistent& model)
{
	Data.StartTime(model.StartTime());
	Data.StopTime(model.StopTime());
	Data.TimeUnit(model.TimeUnit());
	Data.Frequency(model.Frequency());
	Data.Cavitation(model.Cavitation());
	Data.VariableR(model.VariableR());
	Data.Artificial(model.Artificial());
	Data.Criteria(model.Criteria());
	Data.MinFlow(model.MinFlow());
	Data.MinFlowUnit(model.MinFlowUnit());
	Data.TotalSteps(model.TotalSteps());
	
	return ErrorStatus::eFileOK;
}
	
