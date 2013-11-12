// UnitInfo.cpp: implementation of the UnitInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UnitInfo.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UnitInfo::UnitInfo()
{
}

UnitInfo::~UnitInfo()
{
}

void UnitInfo::Init(const CStringArray &strSet)
{
	for( int i = 0 ; i < strSet.GetSize() ; ++i )
	{
		if( strSet[i] == _T( "UNITS-BORE") )
		{
			SetBoreUnit( strSet[++i]) ;
		}
		else if( strSet[i] == _T( "UNITS-CO-ORDS") )
		{
			SetCoordinateUnit( strSet[++i]) ;	
		}
		else if( strSet[i] == _T( "UNITS-WEIGHT") )
		{
			SetWeightUnit( strSet[++i]) ;	
		}
		else if( strSet[i] == _T( "UNITS-BOLT-DIA") )
		{
			SetBoltDiaUnit( strSet[++i]) ;	
		}
		else if( strSet[i] == _T( "UNITS-BOLT-LENGTH") )
		{
			SetBoltLengthUnit( strSet[++i]) ;	
		}
	}
}
