// QuantityManager.cpp: implementation of the QuantityManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QuantityManager.h"
#include "QuantityPersist.h"
#include <vector>
#include "Quantity_share.h"
#include "ResourceInstance.h"
using namespace std;



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QuantityManager::QuantityManager():m_pCurQSys( 0 )
{

}

QuantityManager::~QuantityManager()
{
	QuantitySystemSet::const_iterator ItBegin = m_QSysset.begin();

	for ( ;ItBegin != m_QSysset.end();ItBegin++ )
	{
		delete *ItBegin;
	}
}

BOOL QuantityManager::Init()
{
	QuantityPersist& qp = QuantityPersist::Instance();
	qp.SetConfigURL( m_configFilePath );
	QSysSet qtSet;
	if ( !qp.GetAllQSys( qtSet ) )
	{
		CResourceInstance ins;
		StdString strTmp,strWarnning;
		strTmp.LoadString( IDS_QUANTITY_LOAD_FAILED );
		strWarnning.LoadString( IDS_WARNNING );

		::MessageBox( NULL,strTmp,strWarnning,MB_OK );
		return FALSE;
	}

	QSysSet::const_iterator ItBegin = qtSet.begin();
	for ( ;ItBegin != qtSet.end();ItBegin++ )
	{
		QuantitySystem* pQSys = new QuantitySystem;
		pQSys->Init( *ItBegin );
		m_QSysset.push_back( pQSys );
		
	}
	
	//m_pCurQSys = *( m_QSysset.begin() );    //暂时这么写！
	m_pCurQSys = *( m_QSysset.begin() );  
	return TRUE;
}

void QuantityManager::SetConfigFilePath( const UeStdString& strPath )
{
	m_configFilePath = strPath;
}

/********************************************************************
	开发时间:	2:6:2007   14:17
	开发人:		贺灏
    功能：     	得到所有的单位制名称
    传入参数：	无
    传出参数：	set:名称集合
    返回值：	无
    修改人：
*********************************************************************/
void QuantityManager::GetAllQuantitySysNames( vector< UeStdString >& set )
{	
	QuantitySystemSet::const_iterator ItBegin = m_QSysset.begin();

	for ( ;ItBegin != m_QSysset.end();ItBegin++ )
	{
		set.push_back( ( *ItBegin )->GetQuantitySysName() );
	}
}

/********************************************************************
	开发时间:	2:6:2007   14:21
	开发人:		贺灏
    功能：     	设置系统中当前的单位制，例如把公制改为英制
    传入参数：	strQSysName
    传出参数：	无
    返回值：	无
    修改人：
*********************************************************************/
void QuantityManager::SetNewQuantitySys( const UeStdString& strQSysName )
{
	QuantitySystemSet::const_iterator ItBegin = m_QSysset.begin();

	for ( ;ItBegin != m_QSysset.end();ItBegin++ )
	{
		if ( ( *ItBegin )->GetQuantitySysName() == strQSysName )
		{
			m_pCurQSys = *ItBegin;
			return ;
		}
	}

	ASSERT( FALSE );
	return ;
}

/********************************************************************
	开发时间:	1:6:2007   17:28
	开发人:		贺灏
	功能：     	将某单位下的数值转换为该物理量标准单位下数值
	传入参数：	strQuantity:物理量（如：长度）
				strCurUnit:当前单位（如：米）
				d:数值
	传出参数：	无
	返回值：	该物理量标准单位下数值
	修改人：
*********************************************************************/
BOOL QuantityManager::TransformToStd( double& dOut,const UeStdString& strQuantity,const UeStdString& strCurUnit,double d )
{
	return m_pCurQSys->TransformToStd( dOut,strQuantity,strCurUnit,d );
}

BOOL QuantityManager::TransformToStd( double& dOut,const UeStdString& strCurUnit,double d )
{
	return m_pCurQSys->TransformToStd( dOut,strCurUnit,d );
}

BOOL QuantityManager::TransformFromStd( double& dOut,const UeStdString& strDesUnit,double d )
{
	return m_pCurQSys->TransformFromStd( dOut,strDesUnit,d );
}

/********************************************************************
	开发时间:	1:6:2007   17:31
	开发人:		贺灏
	功能：     	将一种单位下数值转换为另一种单位下数值（在物理上必须具有可转换性）
	传入参数：	strSrc:当前单位（如：米）
				strDes:目标单位（如：厘米）
				d:数值
	传出参数：	无
	返回值：	另一种单位下数值
	修改人：
*********************************************************************/
BOOL QuantityManager::TransformFromTo( double& dOut,const UeStdString& strSrc,const UeStdString& strDes,double d )
{
	return m_pCurQSys->TransformFromTo( dOut,strSrc,strDes,d );
}

/********************************************************************
	开发时间:	1:6:2007   17:35
	开发人:		贺灏
	功能：     	得到某物理量的所有单位字符串
	传入参数：	strQuantity:物理量的名称（如：长度）
	传出参数：	set:单位字符串集合
	返回值：	BOOL
	修改人：
*********************************************************************/
BOOL QuantityManager::GetUnitStringsOfOneQuantity( const UeStdString& strQuantity,vector< UeStdString >& set )
{
	
	return m_pCurQSys->GetUnitStringsOfOneQuantity( strQuantity,set );
}


/********************************************************************
	开发时间:	1:6:2007   17:35
	开发人:		贺灏
	功能：     	得到某物理量的所有单位字符串
	传入参数：	strQuantity:物理量的名称（如：长度）
				strDefault:单位字符串
	返回值：	BOOL
	修改人：
*********************************************************************/
BOOL QuantityManager::GetDefaultUnitString( UeStdString& strDefault,const UeStdString& strQuantity ) const
{
	return m_pCurQSys->GetDefaultUnitString( strDefault,strQuantity );
}

/********************************************************************
	开发时间:	7:19:2008   17:35
	开发人:		廖环宇
	功能：     	设置某物理量的默认单位字符串
	传入参数：	strQuantity:物理量的名称（如：长度）
				strDefault:单位字符串
	返回值：	BOOL
	修改人：
*********************************************************************/
BOOL QuantityManager::SetDefaultUnitString(UeStdString& strDefault,const UeStdString& strQuantity)
{
	return m_pCurQSys->SetDefaultUnitString( strDefault,strQuantity);
}

vector< UeStdString >* QuantityManager::GetPFASet(const UeStdString& strQuantity)
{
    tempset.clear();
	GetUnitStringsOfOneQuantity( strQuantity,tempset );
	return &tempset;
}

void QuantityManager::SetConfigFilePathCString( const CString& strPath )
{
	CString strTemp( strPath );
	m_configFilePath = strTemp.GetBuffer( 0 );
}

void QuantityManager::SaveConfigFile(const UeStdString& strPath)
{

}
