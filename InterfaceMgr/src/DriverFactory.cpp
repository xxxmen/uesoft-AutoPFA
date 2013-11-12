// DriverFactory.cpp: implementation of the DriverFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DriverFactory.h"
#include "AFTFileDriver.h"
#include "CalcFileDriver.h"
#include "PCFFileDriver.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DriverFactory::DriverFactory()
{
	Register(_T("imp"),AFTFileDriver::CreatAFTDriver);
	Register(_T("pfa"),AFTFileDriver::CreatAFTDriver);
	Register(_T("IMP"),AFTFileDriver::CreatAFTDriver);
	Register(_T("PCF"),PCFFileDriver::CreatPCFDriver);
	Register(_T("pcf"),PCFFileDriver::CreatPCFDriver);
	Register("calc",CalcFileDriver::CreatCalcDriver);
	Register("CALC",CalcFileDriver::CreatCalcDriver);
}

DriverFactory::~DriverFactory()
{

}

DriverFactory* DriverFactory::Instance()
{
	static DriverFactory factory;
	return &factory;
}
