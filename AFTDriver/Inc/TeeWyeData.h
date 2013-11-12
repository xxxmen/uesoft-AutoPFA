// TeeWyeData.h: interface for the TeeWyeData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEEWYEDATA_H__D4F1B11A_2743_4ECD_A8B7_EC047987913D__INCLUDED_)
#define AFX_TEEWYEDATA_H__D4F1B11A_2743_4ECD_A8B7_EC047987913D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//三通和Y型元件
#include "Junction.h"
#include "RowObjectFace.h"

class AFX_EXT_CLASS TeeWyeData : public JunctionData  
{
public:
	static JunctionData* Creator();
	TeeWyeData();
	virtual ~TeeWyeData();
public:
	CString Type();
	void Type(CString strValue);
	CString Angle();
	void Angle(CString strValue);
	void Arrangement(CString strValue);
	CString Arrangement();
	CString Model();
	void Model(CString strValue);
private:
	void AppendArray();
	void InitExtra(CString strData);
	virtual CString GetDefaultData();

private:
	RowObjectFace<1> m_Type;				//类型（0，锐边直三通1，圆边直三通2，面积改变3，对称）
	RowObjectFace<1> m_Angle;				//角度
	RowObjectFace<1> m_arrangement;		    //实际布置和图形同步选中为-1，0没选中
	RowObjectFace<1> m_LossModel;			//损失模型类型（1：简单模型2：详细模型）

};

#endif // !defined(AFX_TEEWYEDATA_H__D4F1B11A_2743_4ECD_A8B7_EC047987913D__INCLUDED_)
