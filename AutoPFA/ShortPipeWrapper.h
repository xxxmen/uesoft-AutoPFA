// ShortPipeWrapper.h: interface for the ShortPipeWrapper class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHORTPIPEWRAPPER_H__F6F6B137_D62A_4A97_A0CC_202F58245F0B__INCLUDED_)
#define AFX_SHORTPIPEWRAPPER_H__F6F6B137_D62A_4A97_A0CC_202F58245F0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ArrayFlyWeight.h"

class ShortPipeWrapper  
{
public:
	void SetModel(BOOL bModel);
	BOOL GetModel();
	void SetFriction(CString strFriction);
	CString GetFriction();
	void SetDia(CString strValue,CString strUnit);
	void GetDia(CString &strValue,CString& strUnit);
	void SetArea(CString strValue,CString strUnit);
	void GetArea(CString &strValue,CString& strUnit);
	void SetLen(CString strValue,CString strUnit);
	void GetLen(CString &strValue,CString& strUnit);
	void SetEleChange(CString strValue,CString strUnit);
	void GetEleChange(CString &strValue,CString& strUnit);
	ShortPipeWrapper(ArrayFlyWeight<10> &ShortPipe);
	virtual ~ShortPipeWrapper();

private:
	ArrayFlyWeight<10> &m_ShortPipe;			    	//0：没有选择短管道模型，-1：选择短管道模型
														//短管道摩擦系数
														//短管道内直径\单位
														//短管道面积\单位
														//短管道长度\单位
														//短管道标高变化\单位

};

#endif // !defined(AFX_SHORTPIPEWRAPPER_H__F6F6B137_D62A_4A97_A0CC_202F58245F0B__INCLUDED_)
