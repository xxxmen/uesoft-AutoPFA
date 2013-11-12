// ExpansionCoefTrans.cpp: implementation of the ExpansionCoefTrans class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ExpansionCoefTrans.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const StdString ExpansionCoefTrans::UnitStringArray[EXPANSION_UNIT_NUM] =
{
	"1/C","1E-6/C","1E-4cm/m.C","1E-6/F"
};

double ExpansionCoefTrans::ExpansionTransRatio[EXPANSION_UNIT_NUM] = 
{
	1.0,1E-6,1E-6,1.8E-6
};

ExpansionCoefTrans::ExpansionCoefTrans()
{

}

ExpansionCoefTrans::~ExpansionCoefTrans()
{

}

const StdString& ExpansionCoefTrans::UnitClassToUnitString(int UnitClass)
{
	assert(UnitClass >= 0 && UnitClass <= EXPANSION_UNIT_NUM - 1);
	return ExpansionCoefTrans::UnitStringArray[UnitClass];
}

int ExpansionCoefTrans::UnitStringToUnitClass(const StdString& UnitString)
{
	for (int i = 0; i < EXPANSION_UNIT_NUM; i++)
	{
		if (UnitString.CompareNoCase( ExpansionCoefTrans::UnitStringArray[i] ) == 0 )
		{
			return i;
		}
	}
	assert(0);
	return -1;
}

bool ExpansionCoefTrans::IsSIStd( int orgUnit )
{
	if ( orgUnit == EXPANSION_STD_UNIT )
	{
		return true;
	}
	else
	{
		return false;
	}
}

double ExpansionCoefTrans::TransToStd( int orgUnit )
{
	if (orgUnit >= 0 && orgUnit <= EXPANSION_UNIT_NUM - 1)
	{
		return ExpansionCoefTrans::ExpansionTransRatio[orgUnit];
	}
	else
	{
		assert(0);
		return 0;
	}
}

double ExpansionCoefTrans::TransFromStd( int desUnit )
{
	if (desUnit >= 0 && desUnit <= EXPANSION_UNIT_NUM - 1)
	{
		return 1.0/ExpansionCoefTrans::ExpansionTransRatio[desUnit];
	}
	else
	{
		assert(0);
		return 0;
	}
}

