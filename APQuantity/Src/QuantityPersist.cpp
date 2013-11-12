// QuantityPersist.cpp: implementation of the QuantityPersist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QuantityPersist.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;
#include <algorithm>


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const UeStdString QuantityPersist::strTypeBegin( _T("QTYPE_BEGIN") );
const UeStdString QuantityPersist::strTypeEnd( _T("QTYPE_END") );

const UeStdString QuantityPersist::strSysBegin( _T("QSYS_BEGIN") );
const UeStdString QuantityPersist::strSysEnd( _T("QSYS_END") );

QuantityPersist::QuantityPersist():m_ConfigURL( _T("") ),m_File()
{
}

QuantityPersist::~QuantityPersist()
{

}

void QuantityPersist::DeleteSpaces( UeStdString& str ) const
{
	UeStdString::size_type pos = str.find_first_not_of( ' ' );
	str.erase( 0,pos );//去处头的空格
	
	pos = str.find_last_not_of( ' ' );
	str.erase( pos + 1,str.length() - pos );//去处尾的空格

	pos = str.find( _T("  ") );
	while ( pos != UeStdString::npos )//去处中间连续的空格
	{
		str.replace( pos,2,_T(" ") );
		pos = str.find( _T("  ") );
	}
}

int QuantityPersist::GetQSysNumber()
{
/*
	if ( m_File.empty() )
	{
		GetInputSet();
	}
	ASSERT( m_File.size() > 1 );

	return atoi( ( *( m_File.begin() ) ).c_str() );
*/
	return 0;
}


double QuantityPersist::GetdoubleFromString( const UeStdString& strRate ) const
{
	ASSERT( strRate.length() > 0 );
	if ( strRate.length() <= 0 )
	{
		return -1;//出错
	}
	UeStdString::size_type pos = strRate.find( '/' );
	if ( pos == UeStdString::npos )//比例不是一个分式
	{
		return _tcstod( strRate.c_str(), '\0' );
	}
	else
	{
		UeStdString numerator = strRate.substr( 0,pos );
		UeStdString denominator = strRate.substr( pos + 1, strRate.length() - pos + 1  );

		if ( numerator.length() == 0 || denominator.length() == 0 )
		{
			return -1;
		}
		else
		{
			return _tcstod( numerator.c_str(), '\0' ) / _tcstod( denominator.c_str(), '\0' );
		}
	}
}



void QuantityPersist::SplitString( UeStdString& first,UeStdString& second,const UeStdString& line )
{
	first.erase();
	second.erase();

	UeStdString::size_type pos = line.find( ',' );
	if ( pos == UeStdString::npos )
	{
		return ;
	}
	first = line.substr( 0,pos );
	second = line.substr( pos + 1,line.length() - pos + 1 );
}


BOOL QuantityPersist::GetInputSet( InputSet& set )
{
	Ueistream Config( m_ConfigURL.c_str() );
	if ( !Config )
	{
		return FALSE;
	}

	TCHAR buffer[ 80 ];
	//int i = 0;
	while ( Config.getline( buffer,80,'\n' ) )
	{
		UeStdString strTmp( buffer );
		DeleteSpaces( strTmp );
		set.push_back( strTmp );
	//	i++;
	}
	return TRUE;
}

BOOL QuantityPersist::SeperateSys( SysSet& sSet,InputSet&set )
{
	InputSet::const_iterator ItBegin = set.begin();
	InputSet::const_iterator ItEnd = set.end();
	
	ASSERT( ( *ItBegin ) == strSysBegin );
	ASSERT( ( *( ItEnd - 1 ) ) == strSysEnd );

	BOOL bFlag = TRUE;
	while ( bFlag )
	{
		InputSet::const_iterator ItPos = find( ItBegin,ItEnd,strSysEnd );
		if ( ItPos == ItEnd )
		{
			bFlag = TRUE;
			break;
		}
		InputSet Elm( ItBegin + 1,ItPos );
		sSet.push_back( Elm );
		ItBegin = ItPos + 1;
	}
	return TRUE;
}


BOOL QuantityPersist::GetQuantitytype( QuantityType& type,const InputSet& set )
{
	TransPairSetOfOneType tpt;
	InputSet::const_iterator ItBegin = set.begin();
	InputSet::const_iterator ItEnd = set.end();	
	UeStdString first,second;
	SplitString( first,second,*ItBegin );
	type.first = first;
	ItBegin++;
	for ( ;ItBegin != ItEnd ;ItBegin++ )
	{
		pair< UeStdString,pair< double,double > > p;
		ProcessLine( p, *ItBegin );
		tpt.push_back( p );
	}
	type.second = make_pair( second,tpt );
	return TRUE;
}



const UeStdString QuantityPersist::SeperateType( TypeStringSet& tSet,const InputSet& set )
{
	InputSet::const_iterator ItBegin = set.begin();
	InputSet::const_iterator ItEnd = set.end();
	ASSERT( ( *( ItBegin + 1 ) ) == strTypeBegin );
	ASSERT( ( *( ItEnd - 1 ) ) == strTypeEnd );

	UeStdString QSysName = *ItBegin;
	ItBegin++;

	BOOL bFlag = TRUE;
	while ( bFlag )
	{
		InputSet::const_iterator ItPos = find( ItBegin,ItEnd,strTypeEnd );
		if ( ItPos == ItEnd )
		{
			bFlag = TRUE;
			break;
		}
		InputSet Elm( ItBegin + 1,ItPos );
		tSet.push_back( Elm );
		ItBegin = ItPos + 1;
	}
	return QSysName;
}

BOOL QuantityPersist::GetAllQSys( QSysSet& qsSet )
{

	InputSet set;
	if ( !GetInputSet( set ) )
	{
		return FALSE;
	}
	SysSet sSet;
	if ( !SeperateSys( sSet,set ) )
	{
		return FALSE;
	}
	SysSet::const_iterator sBegin = sSet.begin();
	for ( ;sBegin != sSet.end();sBegin++ )
	{
		QuantityTypeSet qtset;
		TypeStringSet tSet;
		UeStdString QSysName = SeperateType( tSet,*sBegin );

		TypeStringSet::iterator ItBegin = tSet.begin();
		TypeStringSet::iterator ItEnd = tSet.end();

		for ( ;ItBegin != ItEnd;ItBegin++ )
		{
			QuantityType type;
			GetQuantitytype( type,*ItBegin );
			qtset.push_back( type );
		}
		qsSet.push_back( make_pair( QSysName,qtset ) );
	}
	
	return TRUE;
}

void QuantityPersist::ProcessLine( pair< UeStdString,pair< double,double > >&p, const UeStdString& strline ) const
{
	UeStdString::size_type pos = strline.find( ',' );
	if ( pos == UeStdString::npos )
	{
		return ;
	}
	UeStdString UnitName = strline.substr( 0,pos );
	UeStdString::size_type begin = pos + 1;
	pos = strline.find( ',',pos + 1 );
	if ( pos == UeStdString::npos )
	{
		return ;
	}
	UeStdString strRate = strline.substr( begin,pos - begin );
	begin = pos + 1;
	UeStdString strDelta = strline.substr( begin,strline.length() - pos + 1 );

	double dRate = GetdoubleFromString( strRate );
	double dDelta = GetdoubleFromString( strDelta );

	p.first = UnitName;
	p.second = make_pair( dRate,dDelta );
}

/*
void QuantityPersist::Display()
{
	QuantityTypeSet::const_iterator ItBegin = m_TypeSet.begin();

	for ( ;ItBegin != m_TypeSet.end();ItBegin++ )
	{
		UeStdString str = ( *ItBegin ).first;
		UeStdString defaultQ = ( *ItBegin ).second.first;
		TransPairSetOfOneType tpt = ( *ItBegin ).second.second;
		TransPairSetOfOneType::const_iterator xBegin = tpt.begin();
		for ( ;xBegin != tpt.end();xBegin++ )
		{
			TransPair tp = ( *xBegin );
			UeStdString strTmp = tp.first;
			double d = tp.second;
		}
	}
}*/


