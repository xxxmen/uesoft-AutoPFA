// AFTSectionPipeFace.cpp: implementation of the AFTSectionPipeFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTSectionPipeFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTSectionPipeFace::AFTSectionPipeFace()
{

}

AFTSectionPipeFace::~AFTSectionPipeFace()
{

}

ErrorStatus::FileError AFTSectionPipeFace::Read(SectionData &Data,SectionPipePerisistent& model)
{
	model.Search(Data.Search());
	model.MaxSections(Data.MaxSections());
	model.MinSections(Data.MinSections());
	model.MaxError(Data.MaxError());
	model.PctIncrement(Data.PctIncrement());
	model.Sort(Data.Sort());
	model.IdealSections(Data.IdealSections());
	model.TimeStep(Data.TimeStep());
	return ErrorStatus::eFileOK;
}
ErrorStatus::FileError AFTSectionPipeFace::Save(SectionData &Data,SectionPipePerisistent& model)
{
	Data.Search(model.Search());
	Data.MaxSections(model.MaxSections());
	Data.MinSections(model.MinSections());
	Data.MaxError(model.MaxError());
	Data.PctIncrement(model.PctIncrement());
	Data.Sort(model.Sort());
	Data.IdealSections(model.IdealSections());
	Data.TimeStep(model.TimeStep());
	return ErrorStatus::eFileOK;
}