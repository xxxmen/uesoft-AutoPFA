// DefaultUnitSetting.cpp: implementation of the DefaultUnitSetting class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DefaultUnitSetting.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DefaultUnitSetting::DefaultUnitSetting()
{
	this->m_nAngleDefaultUnit = ANGLE_STD_UNIT;
	this->m_nAreaDefaultUnit = AREA_STD_UNIT;
	this->m_nDensityDefaultUnit = DENSITY_STD_UNIT;
	this->m_nForceDefaultUnit = FORCE_STD_UNIT;
	this->m_nLengthDefaultUnit = LENGTH_STD_UNIT;
	this->m_nMassDefaultUnit = MASS_STD_UNIT;
	this->m_nPowerDefaultUnit = POWER_STD_UNIT;
	this->m_nPressureDefaultUnit = PRESSURE_STD_UNIT;
	this->m_nSpeedDefaultUnit = SPEED_STD_UNIT;
	this->m_nTemperatureDefaultUnit = TEMPERATURE_STD_UNIT;
	this->m_nTimeDefaultUnit = TIME_STD_UNIT;
	this->m_nVolumnDefaultUnit = VOLUMN_STD_UNIT;
	this->m_nWorkDefaultUnit = WORK_STD_UNIT;
}

DefaultUnitSetting::~DefaultUnitSetting()
{

}
