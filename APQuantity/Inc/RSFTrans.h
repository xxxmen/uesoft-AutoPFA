// RSFTrans.h: interface for the RSFTrans class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RSFTRANS_H__DF7A4882_62DA_43BB_B6AA_5CA9E88CAB60__INCLUDED_)
#define AFX_RSFTRANS_H__DF7A4882_62DA_43BB_B6AA_5CA9E88CAB60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define RSF_UNIT_NUM 4
#define RSF_STD_UNIT 0

class RSFTrans  
{
public:
	RSFTrans();
	virtual ~RSFTrans();
public:
	static int UnitStringToUnitClass(const StdString& UnitString);
	static const StdString& UnitClassToUnitString(int UnitClass);
	static	bool	IsSIStd( int );
	static	double	TransToStd( int );
	static	double	TransFromStd( int );
	static  int GetStdUnitIndex()
	{
		return RSF_STD_UNIT;
	}
protected:
private:
	static const StdString UnitStringArray[RSF_UNIT_NUM];
	static	double	RSFTransRatio[RSF_UNIT_NUM];
};

#endif // !defined(AFX_RSFTRANS_H__DF7A4882_62DA_43BB_B6AA_5CA9E88CAB60__INCLUDED_)
