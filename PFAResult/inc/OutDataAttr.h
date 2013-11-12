// OutDataAttr.h: interface for the OutDataAttr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OUTDATAATTR_H__1AEFCBFB_DFAE_4792_ADA9_21B71366F14A__INCLUDED_)
#define AFX_OUTDATAATTR_H__1AEFCBFB_DFAE_4792_ADA9_21B71366F14A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "UnitSysHeader.h"
class UnitSubSystem;

class AFX_EXT_CLASS OutDataAttr  
{
public:
	UnitSubSystem& UnitSys();
	CString TranData(CString Data);
	double TranData(double dData);
	CString GetTitle();
	CString GetAxisTitle();
	void Show(BOOL bShow);
	BOOL Show();
	UnitTypeID UnitType();
	CString Unit();//得到当前单位
	void Unit(CString strUnit);//设置当前单位
	CString Name();
	int Key();
	OutDataAttr();
	OutDataAttr(UnitSubSystem &unitsys,int nKey,CString strName,BOOL bShow = TRUE);
	OutDataAttr(UnitSubSystem &unitsys,int nKey,UnitTypeID type,CString strName,BOOL bShow = TRUE);
	OutDataAttr(UnitSubSystem &unitsys,int nKey,UnitTypeID type,CString cursym,CString strName,BOOL bshow=TRUE);
	virtual ~OutDataAttr();

	



private:
	int m_nKey;
	UnitTypeID m_UnitType;//单位类型
	CString m_strName;//当前物理量
	CString m_strUnit;//当前单位
	BOOL  m_bShow;
	UnitSubSystem *m_pUnitsys;


	
	
};

typedef CArray<OutDataAttr,OutDataAttr> OutAttrArray;
#endif // !defined(AFX_OUTDATAATTR_H__1AEFCBFB_DFAE_4792_ADA9_21B71366F14A__INCLUDED_)
