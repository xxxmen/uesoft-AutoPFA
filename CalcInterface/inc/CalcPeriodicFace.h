// CalcPeriodicFace.h: interface for the CalcPeriodicFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCPERIODICFACE_H__9B535FF8_D659_40D6_8DB7_E14F98AA0C99__INCLUDED_)
#define AFX_CALCPERIODICFACE_H__9B535FF8_D659_40D6_8DB7_E14F98AA0C99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcPeriodic;

class AFX_EXT_CLASS CalcPeriodicFace  
{
public:
	CalcPeriodicFace();
	virtual ~CalcPeriodicFace();
	ErrorStatus::FileError Save(CalcPeriodic &Data,StrArray<5> &Model);
};

#endif // !defined(AFX_CALCPERIODICFACE_H__9B535FF8_D659_40D6_8DB7_E14F98AA0C99__INCLUDED_)
