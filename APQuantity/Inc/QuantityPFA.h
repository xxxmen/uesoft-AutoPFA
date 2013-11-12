// QuantityPFA.h: interface for the QuantityPFA class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QUANTITYPFA_H__B1101788_67F9_49BA_8169_02BDF3E340B2__INCLUDED_)
#define AFX_QUANTITYPFA_H__B1101788_67F9_49BA_8169_02BDF3E340B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
using namespace std;
#include "UnitPFA.h"
#include <vector>
#include "Quantity_share.h"
#include "PFAQheader.h"


class QuantityPFA  
{
public:
	typedef vector< UnitPFA* > UnitPFASet;
	QuantityPFA();
	virtual ~QuantityPFA();

public:
	void Init( const QuantityType& qt );

public:
	BOOL CanTransform( const UeStdString& strSrc,const UeStdString& strDes ) const;
	BOOL GetAllUnitStrings( vector< UeStdString >& set ) const;
	const UeStdString GetDefaultUnitString() const
	{
		ASSERT( m_pUserDefaultUnit );
		return m_pUserDefaultUnit->GetUnitString();
	}
	
	const UeStdString& GetQuantityName() const
	{
		return m_QuantityName;
	}
	
	BOOL SetDefaultUnitString(UeStdString& strDefault);//write by Liaohy

	double TransformFromTo( const UeStdString& strSrc,const UeStdString& strDes,double d ) const;
	double TransformToStd( const UeStdString& strCurUnit,double d ) const;
	double TransformFromStd( const UeStdString& strDesUnit,double d ) const;
	BOOL IsIn( const UeStdString& strName ) const;

private:
	UnitPFA* GetUnitPFA( const UeStdString& strName ) const;
private:
	UeStdString m_QuantityName;//物理量的名字
	UnitPFASet m_UnitSet;//一个物理量下单位集合
	UnitPFA* m_pSysDefaultUnit;//系统默认的单位（即转换率为1.0的单位）
	UnitPFA* m_pUserDefaultUnit;//用户定义的默认单位（可以时该物理量中的任意一个单位）

};

#endif // !defined(AFX_QUANTITYPFA_H__B1101788_67F9_49BA_8169_02BDF3E340B2__INCLUDED_)
