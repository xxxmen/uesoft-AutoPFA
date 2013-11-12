// AreaChangeData.h: interface for the AreaChangeData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AREACHANGEDATA_H__85D070A4_BCB7_4E37_9418_CB1205EB080E__INCLUDED_)
#define AFX_AREACHANGEDATA_H__85D070A4_BCB7_4E37_9418_CB1205EB080E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RowObjectFace.h"
#include "Junction.h"
//异径管
class AFX_EXT_CLASS AreaChangeData : public JunctionData  
{
public:
	void Type(CString strValue);
	CString Type();
	void Dir(CString strValue);
	CString Dir();
	void Angle(CString strValue);
	CString Angle();
	void K(CString strValue);
	CString K();
	void BasisArea(StrArray<3>& array);
	StrArray<3> BasisArea();
	static JunctionData* Creator();
	AreaChangeData();
	virtual ~AreaChangeData();
	
private:
	void AppendArray();
	void InitExtra(CString strData);
	CString GetDefaultData();

private:
	RowObjectFace<1> m_TypeID;			//异径管类型（0：圆锥，1：圆柱，2：用户定义）
	RowObjectFace<1> m_Dir;				//（1：收缩，2：扩张）
	RowObjectFace<1> m_Angle;			//角度
	RowObjectFace<1> m_K;				//K系数值
    RowObjectFace<3> m_BasisArea;		//损失模型的面积引用

};

#endif // !defined(AFX_AREACHANGEDATA_H__85D070A4_BCB7_4E37_9418_CB1205EB080E__INCLUDED_)
