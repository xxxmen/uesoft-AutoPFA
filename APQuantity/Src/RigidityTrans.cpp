// RigidityTrans.cpp: implementation of the RigidityTrans class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RigidityTrans.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const StdString RigidityTrans::UnitStringArray[RIGIDITY_UNIT_NUM] = 
{
	"N/m","N/mm","kgf/mm","lb/in","N/cm","kgf/m"
};

double RigidityTrans::RigidityTransRatio[RIGIDITY_UNIT_NUM] =
{
	1.0,1000,9806.65,175,100,9.80665
};
RigidityTrans::RigidityTrans()
{

}

RigidityTrans::~RigidityTrans()
{

}

bool RigidityTrans::IsSIStd( int orgUnit )
{
	if ( orgUnit == RIGIDITY_STD_UNIT )
	{
		return true;
	}
	else
	{
		return false;
	}
}

double RigidityTrans::TransFromStd( int orgUnit )
{
	if ( orgUnit >= 0 && orgUnit <= RIGIDITY_UNIT_NUM - 1 )
	{
		return 1.0 / RigidityTrans::RigidityTransRatio[orgUnit];
	}
	else
	{
		assert( 0 );
		return -1;
	}
}

double RigidityTrans::TransToStd( int orgUnit )
{
	if ( orgUnit >= 0 && orgUnit <= RIGIDITY_UNIT_NUM - 1 )
	{
		return RigidityTrans::RigidityTransRatio[orgUnit];
	}
	else
	{
		assert( 0 );
		return -1;
	}
}

const StdString& RigidityTrans::UnitClassToUnitString( int UnitClass )
{
	assert( UnitClass >= 0 && UnitClass <= RIGIDITY_UNIT_NUM - 1 );
	return RigidityTrans::UnitStringArray[UnitClass];
}

int RigidityTrans::UnitStringToUnitClass( const StdString& UnitString )
{
	for ( int i = 0;i < RIGIDITY_UNIT_NUM;i++ )
	{
		if ( UnitString.CompareNoCase( RigidityTrans::UnitStringArray[i] ) == 0 )
		{
			return i;
		}
	}
	assert( 0 );
	return -1;
}
