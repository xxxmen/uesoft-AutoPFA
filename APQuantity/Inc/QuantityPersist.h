// QuantityPersist.h: interface for the QuantityPersist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QUANTITYPERSIST_H__05AE3499_7CDF_4E0B_8A4C_DEC3A11A9DC6__INCLUDED_)
#define AFX_QUANTITYPERSIST_H__05AE3499_7CDF_4E0B_8A4C_DEC3A11A9DC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <iostream>
#include "PFAQheader.h"

class QUANTITY_API QuantityPersist  
{
	QuantityPersist();
public:
	virtual ~QuantityPersist();

public:
	static QuantityPersist& Instance()
	{
		static QuantityPersist qp;
		return qp;
	}
	
public:
//	void Display();
	BOOL GetAllQSys( QSysSet& set );
	//BOOL GetQuantityTypeSet(  QSysSet& qsSet  );
	void SetConfigURL( const UeStdString& strURL )
	{
		m_ConfigURL = strURL;
	}
	int GetQSysNumber();

private:
	void SplitString( UeStdString& first,UeStdString& second,const UeStdString& line );
	double GetdoubleFromString( const UeStdString& strRate ) const;
	void ProcessLine( pair< UeStdString,pair< double,double > >& p, const UeStdString& strline ) const;
	BOOL GetInputSet( InputSet& set );
	const UeStdString SeperateType( TypeStringSet& tSet,const InputSet& set );
	BOOL SeperateSys( SysSet& sSet,InputSet&set );
	BOOL GetQuantitytype( QuantityType& type,const InputSet& set );
	void DeleteSpaces( UeStdString& str ) const;

private:

	InputSet m_File;
	QuantityTypeSet m_TypeSet;
	UeStdString m_ConfigURL;

private:
	static const UeStdString strTypeBegin;
	static const UeStdString strTypeEnd;
	static const UeStdString strSysBegin;
	static const UeStdString strSysEnd;

};

#endif // !defined(AFX_QUANTITYPERSIST_H__05AE3499_7CDF_4E0B_8A4C_DEC3A11A9DC6__INCLUDED_)
