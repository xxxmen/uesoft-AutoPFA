// MomentTrans.cpp: implementation of the MomentTrans class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MomentTrans.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const StdString MomentTrans::UnitStringArray[MOMENT_UNIT_NUM] = {"N.m","kgf.m","in.lb","ft.lb"};

double MomentTrans::MomentTransRatio[MOMENT_UNIT_NUM]={1.0,9.80665,0.11298,1.3558};
MomentTrans::MomentTrans()
{

}

MomentTrans::~MomentTrans()
{

}

double MomentTrans::TransFromStd( int orgUnit )
{
	if ( orgUnit >=0 && orgUnit <= MOMENT_UNIT_NUM - 1 )
	{
		return 1.0 / MomentTransRatio[orgUnit];
	}
	else
	{
		assert( 0 );
		return -1;
	}
}

double MomentTrans::TransToStd( int orgUnit )
{
	if ( orgUnit >=0 && orgUnit <= MOMENT_UNIT_NUM - 1 )
	{
		return MomentTransRatio[orgUnit];
	}
	else
	{
		assert( 0 );
		return -1;
	}
}

bool MomentTrans::IsSIStd( int orgUnit )
{
	if ( orgUnit == MOMENT_STD_UNIT )
	{
		return true;
	}
	else
	{
		return false;
	}
}

const StdString& MomentTrans::UnitClassToUnitString( int UnitClass )
{
	assert( UnitClass >=0 && UnitClass <= MOMENT_UNIT_NUM - 1 );
	return MomentTrans::UnitStringArray[UnitClass];
}

int MomentTrans::UnitStringToUnitClass( const StdString&  UnitClass )
{
	for ( int i = 0;i < MOMENT_UNIT_NUM;i++ )
	{
		if ( UnitClass.CompareNoCase( MomentTrans::UnitStringArray[i] ) == 0 )
		{
			return i;
		}
	}
	assert( 0 );
	return -1;
}
