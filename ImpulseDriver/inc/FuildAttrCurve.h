// FuildAttrCurve.h: interface for the FuildAttrCurve class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FUILDATTRCURVE_H__90FFC39F_6A8D_492A_950B_2CA7E365F178__INCLUDED_)
#define AFX_FUILDATTRCURVE_H__90FFC39F_6A8D_492A_950B_2CA7E365F178__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class FuildAttrCurve  
{
public:
	double GetY(double dX);
	CString GetUnit();
	CString Init(CString strData);
	FuildAttrCurve();
	virtual ~FuildAttrCurve();

private:
	CString m_strUnit;
	double m_dPrame[5];		    //公式中的参数和常量a，b，c，d，e的值
};

#endif // !defined(AFX_FUILDATTRCURVE_H__90FFC39F_6A8D_492A_950B_2CA7E365F178__INCLUDED_)
