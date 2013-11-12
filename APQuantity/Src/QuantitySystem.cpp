// QuantitySystem.cpp: implementation of the QuantitySystem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QuantitySystem.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QuantitySystem::QuantitySystem()
{

}

QuantitySystem::~QuantitySystem()
{
	QuantityPFASet::const_iterator ItBegin = m_QuantitySet.begin();

	for ( ;ItBegin != m_QuantitySet.end();ItBegin++ )
	{
		delete *ItBegin;
	}
}

void QuantitySystem::Init( const Qsys& set )
{
	m_QSysName = set.first;
	QuantityTypeSet::const_iterator ItBegin = set.second.begin();
	for ( ;ItBegin != set.second.end();ItBegin++ )
	{
		QuantityPFA* pQPFA = new QuantityPFA;
		pQPFA->Init( *ItBegin );
		m_QuantitySet.push_back( pQPFA );
	}
}

	
BOOL QuantitySystem::TransformToStd( double& dOut,const UeStdString& strCurUnit,double d )
{
	QuantityPFASet::const_iterator ItBegin = m_QuantitySet.begin();

	for ( ;ItBegin != m_QuantitySet.end();ItBegin++ )
	{
		if ( ( *ItBegin )->IsIn( strCurUnit ) )
		{
			dOut = ( *ItBegin )->TransformToStd( strCurUnit,d );
			return TRUE;
		}
	}
	return FALSE;
}

BOOL QuantitySystem::TransformToStd( double& dOut,const UeStdString& strQuantity,const UeStdString& strCurUnit,double d )
{
	QuantityPFA* pQPFA = NULL;
	QuantityPFASet::const_iterator ItBegin = m_QuantitySet.begin();

	for ( ;ItBegin != m_QuantitySet.end();ItBegin++ )
	{
		if ( ( *ItBegin )->GetQuantityName() == strQuantity )
		{
			pQPFA = *ItBegin;
			break;
		}
	}

	if ( pQPFA )
	{
		dOut = pQPFA->TransformToStd( strCurUnit,d );
		return TRUE;
	}

	ASSERT( FALSE );
	return FALSE;
}

BOOL QuantitySystem::TransformFromStd( double& dOut,const UeStdString& strDesUnit,double d )
{
	QuantityPFASet::const_iterator ItBegin = m_QuantitySet.begin();

	for ( ;ItBegin != m_QuantitySet.end();ItBegin++ )
	{
		if ( ( *ItBegin )->IsIn( strDesUnit ) )
		{
			dOut = ( *ItBegin )->TransformFromStd( strDesUnit,d );
			return TRUE;
		}
	}
	return FALSE;
}

BOOL QuantitySystem::TransformFromTo( double& dOut,const UeStdString& strSrc,const UeStdString& strDes,double d )
{
	QuantityPFASet::const_iterator ItBegin = m_QuantitySet.begin();

	for ( ;ItBegin != m_QuantitySet.end();ItBegin++ )
	{
		if ( ( *ItBegin )->CanTransform( strSrc,strDes ) )
		{
			dOut = ( *ItBegin )->TransformFromTo( strSrc,strDes,d );
			return TRUE;
		}

	}
	
	ASSERT( FALSE );
	return FALSE;
}

BOOL QuantitySystem::GetUnitStringsOfOneQuantity( const UeStdString& strQuantity,vector< UeStdString >& set )
{
	QuantityPFASet::const_iterator ItBegin = m_QuantitySet.begin();

	for ( ;ItBegin != m_QuantitySet.end();ItBegin++ )
	{
		if ( ( *ItBegin )->GetQuantityName() == strQuantity )
		{
			return ( *ItBegin )->GetAllUnitStrings( set );
		}
	}
	ASSERT( FALSE );
	return FALSE;
}

BOOL QuantitySystem::GetDefaultUnitString( UeStdString& strDefault,const UeStdString& strQuantity ) const
{
	QuantityPFASet::const_iterator ItBegin = m_QuantitySet.begin();

	for ( ;ItBegin != m_QuantitySet.end();ItBegin++ )
	{
		if ( ( *ItBegin )->GetQuantityName() == strQuantity )
		{
			strDefault = ( *ItBegin )->GetDefaultUnitString();
			return TRUE;
		}
	}
	ASSERT( FALSE );
	return FALSE;
}

BOOL QuantitySystem::SetDefaultUnitString(UeStdString& strDefault, const UeStdString& strQuantity)
{
	QuantityPFASet::const_iterator ItBegin = m_QuantitySet.begin();

	for ( ;ItBegin != m_QuantitySet.end();ItBegin++ )
	{
		if ( ( *ItBegin )->GetQuantityName() == strQuantity )
		{
			( *ItBegin )->SetDefaultUnitString( strDefault );
			return TRUE;
		}
	}
	ASSERT( FALSE );
	return FALSE;
}