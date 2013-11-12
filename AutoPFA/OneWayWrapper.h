// OneWayWrapper.h: interface for the OneWayWrapper class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ONEWAYWRAPPER_H__CF414981_667E_4F84_A7B6_84E57A3613A4__INCLUDED_)
#define AFX_ONEWAYWRAPPER_H__CF414981_667E_4F84_A7B6_84E57A3613A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ArrayFlyWeight.h"

class OneWayWrapper  
{
public:
	BOOL GetCvModel();
	void SetCv(CString strCv);
	CString GetCv();
	int GetPostion();
	void SetPostion(int nPostion);
	void SetPress(int nType,CString strValue,CString strUnit);
	void GetPress(int &nType,CString &strValue,CString& strUnit);
	OneWayWrapper(ArrayFlyWeight<5>& checkValve);
	virtual ~OneWayWrapper();
	
private:
	ArrayFlyWeight<5>& m_CheckValve;						//止回阀流量系数
														//止回阀初始位置0：打开1：关闭
														//打开阀门Delta压力或水头的压力类型0：水头1：压力
														//压力值\单位

};

#endif // !defined(AFX_ONEWAYWRAPPER_H__CF414981_667E_4F84_A7B6_84E57A3613A4__INCLUDED_)
