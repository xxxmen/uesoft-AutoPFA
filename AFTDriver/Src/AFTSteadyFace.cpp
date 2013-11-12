// AFTSteadyFace.cpp: implementation of the AFTSteadyFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTSteadyFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTSteadyFace::AFTSteadyFace()
{

}

AFTSteadyFace::~AFTSteadyFace()
{

}

	
ErrorStatus::FileError AFTSteadyFace::Read(SettingData &Data,SteadyPersistent& model)
{
	model.AnalysisType(Data.AnalysisType());
	model.PresTolType(Data.PresTolType());
	model.PresAbsTol(Data.PresAbsTol());
	model.PresRelTol(Data.PresRelTol());
	model.FlowTolType(Data.FlowTolType());
	model.FlowAbsTol(Data.FlowAbsTol());
	model.FlowRelTol(Data.FlowRelTol());
	model.RelaxationType(Data.RelaxationType());
	model.FlowRelaxation(Data.FlowRelaxation());
	model.PresRelaxation(Data.PresRelaxation());
	model.MaxIterations(Data.MaxIterations());
	model.KeepHistory(Data.KeepHistory());
	model.MatrixMethod(Data.MatrixMethod());
	model.AutoDetect(Data.AutoDetect());
	return ErrorStatus::eFileOK;
}
ErrorStatus::FileError AFTSteadyFace::Save(SettingData &Data,SteadyPersistent& model)
{
	Data.AnalysisType(model.AnalysisType());
	Data.PresTolType(model.PresTolType());
	Data.PresAbsTol(model.PresAbsTol());
	Data.PresRelTol(model.PresRelTol());
	Data.FlowTolType(model.FlowTolType());
	Data.FlowAbsTol(model.FlowAbsTol());
	Data.FlowRelTol(model.FlowRelTol());
	Data.RelaxationType(model.RelaxationType());
	Data.FlowRelaxation(model.FlowRelaxation());
	Data.PresRelaxation(model.PresRelaxation());
	Data.MaxIterations(model.MaxIterations());
	Data.KeepHistory(model.KeepHistory());
	Data.MatrixMethod(model.MatrixMethod());
	Data.AutoDetect(model.AutoDetect());
	return ErrorStatus::eFileOK;
}