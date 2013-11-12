// ontrolWrapper.h: interface for the ControlWrapper class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ONTROLWRAPPER_H__CBB5F385_2C4F_4C80_A647_559C06C1562C__INCLUDED_)
#define AFX_ONTROLWRAPPER_H__CBB5F385_2C4F_4C80_A647_559C06C1562C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ArrayFlyWeight.h"
class ControlWrapper  
{
public:
	void GetSetNum(CString &strValue,CString &strUnit);
	void SetSetNum(CString strValue,CString strUnit);
	void SetPressType(int nType);
	int GetPressType();
	void SetSetType(int nType);
	int GetSetType();
	void SetType(int nType);
	int GetType();
	ControlWrapper(ArrayFlyWeight<5> &ControlSet);
	virtual ~ControlWrapper();

private:
	ArrayFlyWeight<5>& m_ControlSet;		    //阀门类型(0：PRF 1：PSV 2：FCV 3：PDCV)
												//控制点参数类型0：水头/水头损失/体积流量1：压力/压力损失/质量流量
												//0：停滞压力1：静态压力
												//控制点参数值
												//控制点参数单位

												

};

#endif // !defined(AFX_ONTROLWRAPPER_H__CBB5F385_2C4F_4C80_A647_559C06C1562C__INCLUDED_)
