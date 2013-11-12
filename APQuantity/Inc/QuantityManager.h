// QuantityManager.h: interface for the QuantityManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QUANTITYMANAGER_H__71D10FBC_111E_4187_A8B4_A4772C4E0C82__INCLUDED_)
#define AFX_QUANTITYMANAGER_H__71D10FBC_111E_4187_A8B4_A4772C4E0C82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <string>
#include <vector>
#include <utility>
#include "QuantitySystem.h"
#include "Quantity_share.h"

using namespace std;


class QUANTITY_API QuantityManager  
{
	QuantityManager();
	QuantityManager( const QuantityManager& );
public:
	typedef vector< QuantitySystem* > QuantitySystemSet;
	virtual ~QuantityManager();
	
public:
	static QuantityManager& Instance()
	{
		static QuantityManager mg;
		return mg;
	}

	/********************************************************************
		开发时间:	13:6:2007   15:54
		开发人:		贺灏
	    功能：     	将某单位下数值转换为该物理量标准单位下数量
	    传入参数：	strQuantity：物理量名称
					strCurUnit:单位名称
					d：数值
	    传出参数：	
	    返回值：
	    修改人：
	*********************************************************************/
	BOOL TransformToStd( double& dOut,const UeStdString& strQuantity,const UeStdString& strCurUnit,double d );

	BOOL TransformToStd( double& dOut,const UeStdString& strCurUnit,double d );

	BOOL TransformFromStd( double& dOut,const UeStdString& strDesUnit,double d );

	BOOL TransformFromTo( double& dOut,const UeStdString& strSrc,const UeStdString& strDes,double d );

	BOOL GetUnitStringsOfOneQuantity( const UeStdString& strQuantity,vector< UeStdString >& set );

	//得到某物理量的默认单位的字符串
	BOOL GetDefaultUnitString( UeStdString& strDefault,const UeStdString& strQuantity ) const;

	//设置某物理量的默认单位(write by: Liaohy)
	BOOL SetDefaultUnitString( UeStdString& strDefault,const UeStdString& strQuantity);
	
	void SetConfigFilePath( const UeStdString& strPath );

	void GetAllQuantitySysNames( vector< UeStdString >& set );

	void SetNewQuantitySys( const UeStdString& strQSysName );


	vector< UeStdString >* GetPFASet(const UeStdString& strQuantity);
	void SetConfigFilePathCString( const CString& strPath );

	//保存当前默认单位到数据文件
	void SaveConfigFile(const UeStdString& strPath);

public:
	BOOL Init();



private:
	UeStdString m_configFilePath;//单位数据文件的位置
	QuantitySystemSet m_QSysset;//单位制集合
	QuantitySystem* m_pCurQSys;//当前所使用单位


	vector<UeStdString> tempset;


};

#endif // !defined(AFX_QUANTITYMANAGER_H__71D10FBC_111E_4187_A8B4_A4772C4E0C82__INCLUDED_)
