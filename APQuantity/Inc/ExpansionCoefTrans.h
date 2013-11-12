// ExpansionCoefTrans.h: interface for the ExpansionCoefTrans class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPANSIONCOEFTRANS_H__96B4F136_0E7B_465B_83DE_08B6F8D73046__INCLUDED_)
#define AFX_EXPANSIONCOEFTRANS_H__96B4F136_0E7B_465B_83DE_08B6F8D73046__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define	EXPANSION_UNIT_NUM	4
#define	EXPANSION_STD_UNIT	0

class ExpansionCoefTrans  
{
public:
	ExpansionCoefTrans();
	virtual ~ExpansionCoefTrans();
public:
	static const StdString& UnitClassToUnitString(int UnitClass);
	static int UnitStringToUnitClass(const StdString& UnitString);
	static	bool	IsSIStd( int );
	static	double	TransToStd( int );
	static	double	TransFromStd( int );
	static  int GetStdUnitIndex()
	{
		return EXPANSION_STD_UNIT;
	}
protected:
private:

	static	const StdString UnitStringArray[EXPANSION_UNIT_NUM];
	static	double	ExpansionTransRatio[EXPANSION_UNIT_NUM];
};

#endif // !defined(AFX_EXPANSIONCOEFTRANS_H__96B4F136_0E7B_465B_83DE_08B6F8D73046__INCLUDED_)
