// MomentTrans.h: interface for the MomentTrans class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOMENTTRANS_H__0997F8A0_5D2A_412B_B445_E6C6FED03CF2__INCLUDED_)
#define AFX_MOMENTTRANS_H__0997F8A0_5D2A_412B_B445_E6C6FED03CF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define MOMENT_UNIT_NUM 4
#define MOMENT_STD_UNIT 0
#include "Quantity_share.h"

class QUANTITY_API MomentTrans  
{
public:
	MomentTrans();
	virtual ~MomentTrans();
public:
	static int UnitStringToUnitClass(const StdString& UnitString);
	static const StdString& UnitClassToUnitString(int UnitClass);
	static bool	IsSIStd( int );
	static double TransToStd( int );
	static double TransFromStd( int );
	static  int GetStdUnitIndex()
	{
		return MOMENT_STD_UNIT;
	}
protected:

private:
	static const StdString UnitStringArray[MOMENT_UNIT_NUM];

	static double MomentTransRatio[MOMENT_UNIT_NUM];
};

#endif // !defined(AFX_MOMENTTRANS_H__0997F8A0_5D2A_412B_B445_E6C6FED03CF2__INCLUDED_)
