// ComponentStmOut.h: interface for the ComponentStmOut class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPONENTSTMOUT_H__3AD9FD5A_C575_49EE_9525_B952C94FC6C2__INCLUDED_)
#define AFX_COMPONENTSTMOUT_H__3AD9FD5A_C575_49EE_9525_B952C94FC6C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "OutDataAttr.h"
#include "ListFlyWeightImp.h"

class AFX_EXT_CLASS  ComponentStmOut  
{
public:
	CString Name();
	void Name(CString strName);
	void Type(int nType);
	int Type();
	int Key();
	void Key(int nKey);
	ComponentStmOut();
	virtual ~ComponentStmOut();
public:
	CString GetValue(int nKey);
	double GetdValue(int nKey);
	int GetnValue(int nKey);
	void SetValue(int nValue,int nKey);
	void SetValue(CString strValue,int nKey);
	void SetValue(double dValue,int nKey);
protected:
	static double Max(double dX1,double dX2);
	static double Min(double dX1,double dX2);
	static void InitAttr(OutAttrArray &array,UnitSubSystem &unitsys,int nKey,CString strName,BOOL bShow = TRUE);
	static void InitAttr(OutAttrArray &array,UnitSubSystem &unitsys,int nKey,UnitTypeID type,CString strName,BOOL bShow = TRUE);
	static void InitAttr(OutAttrArray &array,UnitSubSystem &unitsys,int nKey,UnitTypeID type,CString cursym,CString strName,BOOL bShow = TRUE);


	StrArray<50> m_dataArray;
	int m_nType;
	CString m_strName;
};

#endif // !defined(AFX_COMPONENTSTMOUT_H__3AD9FD5A_C575_49EE_9525_B952C94FC6C2__INCLUDED_)
