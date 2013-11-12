// QuantitySystem.h: interface for the QuantitySystem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QUANTITYSYSTEM_H__72EDD183_B66B_4D80_99EB_B6A92DB18CDB__INCLUDED_)
#define AFX_QUANTITYSYSTEM_H__72EDD183_B66B_4D80_99EB_B6A92DB18CDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "QuantityPFA.h"
#include "unithead.h"
#include "PFAQheader.h"

class QuantitySystem  
{
public:
	typedef vector< QuantityPFA* > QuantityPFASet;
	QuantitySystem();
	virtual ~QuantitySystem();

public:
	void Init( const Qsys& set );

	const UeStdString GetQuantitySysName() const
	{
		return m_QSysName;
	}
	BOOL TransformToStd( double& dOut,const UeStdString& strQuantity,const UeStdString& strCurUnit,double d );

	BOOL TransformToStd( double& dOut,const UeStdString& strCurUnit,double d );

	BOOL TransformFromStd( double& dOut,const UeStdString& strDesUnit,double d );

	BOOL TransformFromTo( double& dOut,const UeStdString& strSrc,const UeStdString& strDes,double d );

	BOOL GetUnitStringsOfOneQuantity( const UeStdString& strQuantity,vector< UeStdString >& set );

	BOOL SetDefaultUnitString( UeStdString& strDefault, const UeStdString& strQuantity);
	BOOL GetDefaultUnitString( UeStdString& strDefault,const UeStdString& strQuantity ) const;
private:
	QuantityPFASet m_QuantitySet;//该单位制下物理量集合
	UeStdString m_QSysName;//该单位制的名称

};

#endif // !defined(AFX_QUANTITYSYSTEM_H__72EDD183_B66B_4D80_99EB_B6A92DB18CDB__INCLUDED_)
