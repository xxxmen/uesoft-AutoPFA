// CalcSteadyFace.h: interface for the CalcSteadyFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCSTEADYFACE_H__1FDE2D7C_1B14_405A_A6E1_24D0BA66300E__INCLUDED_)
#define AFX_CALCSTEADYFACE_H__1FDE2D7C_1B14_405A_A6E1_24D0BA66300E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcSteady;
class SteadyPersistent;

class AFX_EXT_CLASS CalcSteadyFace  
{
public:
	CalcSteadyFace();
	virtual ~CalcSteadyFace();
    ErrorStatus::FileError Save(CalcSteady &Data,SteadyPersistent& model);
};

#endif // !defined(AFX_CALCSTEADYFACE_H__1FDE2D7C_1B14_405A_A6E1_24D0BA66300E__INCLUDED_)
