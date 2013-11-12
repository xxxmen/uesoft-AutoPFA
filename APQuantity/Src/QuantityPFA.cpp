// QuantityPFA.cpp: implementation of the QuantityPFA class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QuantityPFA.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QuantityPFA::QuantityPFA():m_pSysDefaultUnit( 0 ),m_pUserDefaultUnit( 0 )
{

}

QuantityPFA::~QuantityPFA()
{
	UnitPFASet::const_iterator ItBegin = m_UnitSet.begin();

	for ( ;ItBegin != m_UnitSet.end();ItBegin++ )
	{
		delete *ItBegin;
	}
}

BOOL QuantityPFA::SetDefaultUnitString(UeStdString& strDefault)
{
	m_pUserDefaultUnit->SetUnitString(strDefault);
	return TRUE;
}

void QuantityPFA::Init( const QuantityType& qt )
{
	m_QuantityName = qt.first;
	UeStdString UserDefault = qt.second.first;
	TransPairSetOfOneType tpt = qt.second.second;
	TransPairSetOfOneType::const_iterator ItBegin = tpt.begin();

	for ( ;ItBegin != tpt.end();ItBegin++ )
	{
		TransPair tp = *ItBegin;
		UnitPFA* pUPFA = new UnitPFA( tp.first,tp.second.first,tp.second.second );
		m_UnitSet.push_back( pUPFA );
		if ( tp.first == UserDefault )//用户默认单位
		{
			m_pUserDefaultUnit = pUPFA;
		}
		if ( tp.second.first == 1.0 && tp.second.second == 0  )//系统默认单位
		{
			m_pSysDefaultUnit = pUPFA;
		}
	}
}

BOOL QuantityPFA::GetAllUnitStrings( vector< UeStdString >& set ) const
{
	UnitPFASet::const_iterator ItBegin = m_UnitSet.begin();

	for ( ;ItBegin != m_UnitSet.end();ItBegin++ )
	{
		set.push_back( ( *ItBegin )->GetUnitString() );
	}
	return TRUE;
}

UnitPFA* QuantityPFA::GetUnitPFA( const UeStdString& strName ) const
{
	UnitPFASet::const_iterator ItBegin = m_UnitSet.begin();
	CString strOne;
	CString strTwo;
	for ( ;ItBegin != m_UnitSet.end();ItBegin++ )
	{
// 		if ( ( *ItBegin )->GetUnitString() == strName )
// 		{
// 			return *ItBegin;
// 		}
		//这里为了防止出现单位一样,大小写不一样的情况,如,slug/ft3 == Slug/ft3 时的情况.
		//这里就不区分大小写了.
#ifdef UNICODE
		if ( 0 == _wcsicmp(strName.c_str(), ( *ItBegin )->GetUnitString().c_str()) )
		{
			return*ItBegin;
		}
#else
		if ( 0 == stricmp(strName.c_str(), ( *ItBegin )->GetUnitString().c_str()) )
		{
			return*ItBegin;
		}
#endif
		
// 		if ( 0 == _wcsicmp( strName.c_str(), ( *ItBegin )->GetUnitString().c_str() ) )
// 		{
// 			return*ItBegin;
// 		}
	}

	return NULL;
}

double QuantityPFA::TransformFromTo( const UeStdString& strSrc,const UeStdString& strDes,double d ) const
{
	UnitPFA* pSrc = GetUnitPFA( strSrc );
	UnitPFA* pDes = GetUnitPFA( strDes );

	ASSERT( pSrc && pDes );

	if ( !pSrc || !pDes )
	{
		return 0;
	}
	else
	{
		double dStd = d * pSrc->GetRate() + pSrc->GetDelta();
		double dDes = ( dStd - pDes->GetDelta() ) / pDes->GetRate();
		return dDes;
	}
}

double QuantityPFA::TransformToStd( const UeStdString& strCurUnit,double d ) const
{
	UnitPFA* pSrc = GetUnitPFA( strCurUnit );

	ASSERT( pSrc && m_pUserDefaultUnit );

	if ( !pSrc || !m_pUserDefaultUnit )
	{
		return 0;
	}
	else
	{
		double dStd = d * pSrc->GetRate() + pSrc->GetDelta();
		double dDes = ( dStd - m_pUserDefaultUnit->GetDelta() ) / m_pUserDefaultUnit->GetRate();
		return dDes;
	}
}

double QuantityPFA::TransformFromStd( const UeStdString& strDesUnit,double d ) const
{
	UnitPFA* pDes = GetUnitPFA( strDesUnit );

	ASSERT( pDes && m_pUserDefaultUnit );

	if ( !pDes || !m_pUserDefaultUnit )
	{
		return 0;
	}
	else
	{
		double dStd = d * m_pUserDefaultUnit->GetRate() + m_pUserDefaultUnit->GetDelta();
		double dDes = ( dStd - pDes->GetDelta() ) / pDes->GetRate();
		return dDes;
	}
}

BOOL QuantityPFA::IsIn( const UeStdString& strName ) const
{
	UnitPFASet::const_iterator ItBegin = m_UnitSet.begin();
	CString strOne;
	CString strTwo;
	for ( ;ItBegin != m_UnitSet.end();ItBegin++ )
	{
// 		if ( strName == ( *ItBegin )->GetUnitString() )
// 		{
// 			return TRUE;
// 		}
		//这里为了防止出现单位一样,大小写不一样的情况,如,slug/ft3 == Slug/ft3 时的情况.
		//这里就不区分大小写了.
#ifdef UNICODE
		if ( 0 == _wcsicmp(strName.c_str(), ( *ItBegin )->GetUnitString().c_str()) )
		{
			return TRUE;
		}
#else
		if ( 0 == stricmp(strName.c_str(), ( *ItBegin )->GetUnitString().c_str()) )
		{
			return TRUE;
		}
#endif
// 		strOne = strName.c_str();
// 		strTwo = ( *ItBegin )->GetUnitString().c_str();
// 		strOne.MakeUpper();
// 		strTwo.MakeUpper();

	}

	return FALSE;	
}

BOOL QuantityPFA::CanTransform( const UeStdString& strSrc,const UeStdString& strDes ) const
{
	if ( IsIn( strSrc ) && IsIn( strDes ) )
	{
		return TRUE;
	}
	return FALSE;
}
