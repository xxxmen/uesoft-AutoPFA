// CalcFuildFace.cpp: implementation of the CalcFuildFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcFuildFace.h"
#include "CaclFuild.h"
#include "sysproperty.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcFuildFace::CalcFuildFace()
{

}

CalcFuildFace::~CalcFuildFace()
{

}

ErrorStatus::FileError CalcFuildFace::Save(CalcFuild &Data,PropertyPersistent& model)
{
	Data.Density(TransStd(model.Density()));
	Data.Temperature(TransStd(model.Temperature()));
	Data.Viscos(TransStd(model.Viscos()));
	Data.Modulus(TransStd(model.Modulus()));
	Data.VaporPress(TransStd(model.VaporPress()));
	Data.Gravity(_tcstod(model.Gravity(),'\0')*GA);
	Data.ReTransLam(_tcstod(model.ReTransLam(),'\0'));
	Data.ReTransTurb(_tcstod(model.ReTransTurb(),'\0'));
	Data.AtmosphericPress(TransStd(model.AtmosphericPress()));
	return ErrorStatus::eFileOK;
}