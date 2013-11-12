// PCFSysPropety.cpp: implementation of the PCFSysPropety class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFSysPropety.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFSysPropety::PCFSysPropety()
{

}

PCFSysPropety::~PCFSysPropety()
{

}

ErrorStatus::FileError PCFSysPropety::Read(PropertyPersistent& model)
{
	StrArray<2> strPropety;
	model.Name(_T("Water at 1 atm"));

	strPropety.Data(20, 0);
	strPropety.Data(_T("deg.C"), 1);
	model.Temperature(strPropety);

	strPropety.Data(62.30841f, 0);
	strPropety.Data(_T("lbm/ft3"), 1);
 	model.Density(strPropety);

	strPropety.Data(2.36004f, 0);
	strPropety.Data(_T("lbm/hr"), 1);
 	model.Viscos(strPropety);

	strPropety.Data(_T("296800"), 0);
	strPropety.Data(_T("psia"), 1);
 	model.Modulus(strPropety);

	strPropety.Data(36157, 0);
	strPropety.Data(_T("psia"), 1);
 	model.VaporPress(strPropety);

 	model.Gravity(_T("1"));
 	model.ReTransLam(_T("2300"));
 	model.ReTransTurb(_T("4000"));

	strPropety.Data(1, 0);
	strPropety.Data(_T("atm"), 1);
 	model.AtmosphericPress(strPropety);
	return ErrorStatus::eFileOK;
}
