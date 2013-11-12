// AFTTransControlFace.cpp: implementation of the AFTTransControlFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTTransControlFace.h"
#include "PersistentObj.h"

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
	bool b_isImpFlag = PersistentObj::isImpFile ;
	if ( b_isImpFlag )
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
	} 
	else
	{
		model.StartTime( Data.StartTime() );
		model.StopTime( Data.StopTime() );
		model.TimeStep( Data.TimeStep() );
		model.TimeUnit( Data.TimeUnit() );
		model.TimeStepUnits( Data.TimeStepUnits() );
		model.Frequency( Data.Frequency() );
		model.TotalSteps( Data.TotalSteps() );
		model.DifferenceMethod( Data.DifferenceMethod() );
		model.RelativeTolerance( Data.RelativeTolerance() );
		model.AbsoluteTolerance( Data.AbsoluteTolerance() );
		model.AbsoluteToleranceUnits( Data.AbsoluteToleranceUnits() );
		model.MaxIterations( Data.MaxIterations() );
		model.Relaxation( Data.Relaxation() );
	}
	
	return ErrorStatus::eFileOK;
}
ErrorStatus::FileError AFTTransControlFace::Save(TranContorlData &Data,TransControlPerisistent& model)
{
	bool b_isImpFlag = PersistentObj::isImpFile ;
	if ( b_isImpFlag )
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
	} 
	else
	{
		Data.StartTime( model.StartTime() );
		Data.StopTime( model.StopTime() );
		Data.TimeStep( model.TimeStep() );
		Data.TimeUnit( model.TimeUnit() );
		Data.TimeStepUnits( model.TimeStepUnits() );
		Data.Frequency( model.Frequency() );
		Data.TotalSteps( model.TotalSteps() );
		Data.DifferenceMethod( model.DifferenceMethod() );
		Data.RelativeTolerance( model.RelativeTolerance() );
		Data.AbsoluteTolerance( model.AbsoluteTolerance() );
		Data.AbsoluteToleranceUnits( model.AbsoluteToleranceUnits() );
		Data.MaxIterations( model.MaxIterations() );
		Data.Relaxation( model.Relaxation() );
	}
	
	
	return ErrorStatus::eFileOK;
}
	
