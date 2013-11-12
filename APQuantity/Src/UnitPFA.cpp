// UnitPFA.cpp: implementation of the UnitPFA class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UnitPFA.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UnitPFA::UnitPFA( const UeStdString& strName,double dRate ,double dDelta ):m_UnitString( strName ),m_dRate( dRate ),m_dDelta( dDelta )
{
	
}

UnitPFA::UnitPFA():m_UnitString( _T("") ),m_dRate( 0 ),m_dDelta( 0 )
{

}

UnitPFA::~UnitPFA()
{

}

BOOL UnitPFA::SetUnitString(UeStdString& strDefault)
{
	m_UnitString=strDefault;
	return TRUE;
}