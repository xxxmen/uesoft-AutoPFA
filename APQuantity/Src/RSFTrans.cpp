// RSFTrans.cpp: implementation of the RSFTrans class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RSFTrans.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const StdString RSFTrans::UnitStringArray[RSF_UNIT_NUM] = 
{
	"N.m/rad","N.m/deg","kgf.m/deg","in.lb/deg"
};

double RSFTrans::RSFTransRatio[RSF_UNIT_NUM] =
{
	1.0,57.307,561.986,6.4746
};
RSFTrans::RSFTrans()
{

}

RSFTrans::~RSFTrans()
{

}

bool RSFTrans::IsSIStd( int orgUnit )
{
	if ( orgUnit == RSF_STD_UNIT )
	{
		return true;
	}
	else
	{
		return false;
	}
}

double RSFTrans::TransFromStd( int orgUnit )
{
	if ( orgUnit >= 0 && orgUnit <= RSF_UNIT_NUM - 1 )
	{
		return 1.0 / RSFTrans::RSFTransRatio[orgUnit];
	}
	else
	{
		assert( 0 );
		return -1;
	}
}

double RSFTrans::TransToStd( int orgUnit )
{
	if ( orgUnit >= 0 && orgUnit <= RSF_UNIT_NUM - 1 )
	{
		return RSFTrans::RSFTransRatio[orgUnit];
	}
	else
	{
		assert( 0 );
		return -1;
	}
}

const StdString& RSFTrans::UnitClassToUnitString( int UnitClass )
{
	assert( UnitClass >= 0 && UnitClass <= RSF_UNIT_NUM - 1 );
	return RSFTrans::UnitStringArray[UnitClass];
}

int RSFTrans::UnitStringToUnitClass( const StdString& UnitString )
{
	for ( int i = 0; i < RSF_UNIT_NUM;i++ )
	{
		if ( UnitString.CompareNoCase( RSFTrans::UnitStringArray[i] ) == 0 )
		{
			return i;
		}
	}
	assert( 0 );
	return -1;
}
