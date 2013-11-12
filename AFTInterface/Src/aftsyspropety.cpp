// AFTSysPropety.cpp: implementation of the AFTSysPropety class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTSysPropety.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTSysPropety::AFTSysPropety()
{

}

AFTSysPropety::~AFTSysPropety()
{

}

ErrorStatus::FileError AFTSysPropety::Read(FluidData &Data,PropertyPersistent& model)
{
	model.Name(Data.Name());
	model.Density(Data.Density());
	model.Temperature(Data.Temperature());
	model.Viscos(Data.Viscos());
	model.Modulus(Data.Modulus());
	model.VaporPress(Data.VaporPress());
	model.Gravity(Data.Gravity());
	model.ReTransLam(Data.ReTransLam());
	model.ReTransTurb(Data.ReTransTurb());
	model.AtmosphericPress(Data.AtmosphericPress());
	return ErrorStatus::eFileOK;
}
ErrorStatus::FileError AFTSysPropety::Save(FluidData &Data,PropertyPersistent& model)
{
	Data.Name(model.Name());
	Data.Density(model.Density());
	Data.Temperature(model.Temperature());
	Data.Viscos(model.Viscos());
	Data.Modulus(model.Modulus());
	Data.VaporPress(model.VaporPress());
	Data.Gravity(model.Gravity());
	Data.ReTransLam(model.ReTransLam());
	Data.ReTransTurb(model.ReTransTurb());
	Data.AtmosphericPress(model.AtmosphericPress());
	return ErrorStatus::eFileOK;
}
