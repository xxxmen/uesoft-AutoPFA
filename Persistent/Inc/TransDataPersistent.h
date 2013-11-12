// TransDataPersistent.h: interface for the TransDataPersistent class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：TransDataPersistent.h
  摘要：    瞬变数据
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSDATAPERSISTENT_H__AF9BA607_F926_486A_A725_7C0542E9067B__INCLUDED_)
#define AFX_TRANSDATAPERSISTENT_H__AF9BA607_F926_486A_A725_7C0542E9067B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "TwoDTablePersistent.h"

class AFX_EXT_CLASS TransDataPersistent  
{
public:
	TransDataPersistent();
	virtual ~TransDataPersistent();
public:
    CString ValueType();
	void ValueType(CString strValue);
	CString Special();
	void Special(CString strValue);
	CString Repeat1();
	void Repeat1(CString strValue);
	CString Repeat2();
	void Repeat2(CString strValue);
	CString TranType();
	void TranType(CString strValue);
	StrArray<5>& Periodic();
	void Periodic(const StrArray<5>& strValue);
	StrArray<8>& TranTriger1();
	void TranTriger1(const StrArray<8>& strValue);
	StrArray<8>& TranTriger2();
	void TranTriger2(const StrArray<8>& strValue);
	CString TranModel();
	void TranModel(CString strValue);
	CString Speed();
	void Speed(CString strValue);
	StrArray<2>& RotateInertia();
	void RotateInertia(const StrArray<2>& strValue);
	StrArray<3>& FourQuadrant();
	void FourQuadrant(const StrArray<3>& strValue);
	

private:
    CString m_ValueType;				//1、0:绝对值，1：相对恒定流的值
	CString m_Special;					//2、0：瞬态特别条件选中“没有”，1：瞬态特别条件选“忽略瞬态数据”（针对具体节点特别条件多于2个分别查看特别条件对应的数字）
	CString m_Repeat1;					//3、0：第一次瞬变重复没选中，-1选中：
	CString m_Repeat2;					//4、0：第二次瞬变重复没选中，-1选中：
	CString m_TranType;					//5、0:时间，1：单个事件，2：两个事件循环3：两个连续事件
	StrArray<5> m_Periodic;				//1、0：周期性没有选择，-1：流量周期性选择
										//2、0：没有选择使用正弦函数的绝对值，-1：选择使用正弦函数的绝对值
										//3、正弦函数频率
										//4、正弦函数振幅
										//5、正弦函数振幅单位
	StrArray<8> m_TranTriger1;			 //事件类型
										//条件类型
										//值
										//单位
										//管道入口触发事件为1；管道出口触发事件为2（第一根管道）
										//触发事件的管道编号（第一根管道）
										//管道入口触发事件为1；管道出口触发事件为2（第二根管道）
										//触发事件的管道编号（第二根管道）
	StrArray<8> m_TranTriger2;

	//泵瞬变数据
	CString m_TranModel;				//泵瞬变模型
	StrArray<2> m_RotateInertia;			//转动惯量（泵，电动机，流体）\转动惯量单位
	CString m_Speed;					//泵额定转速
	StrArray<3> m_FourQuadrantData;        //四象限数据源标记\四象限数据的数
public:
	TwoDTablePersistent m_Trans1Table;									
	TwoDTablePersistent m_Trans2Table;	
	ThreeDTablePersistent m_FourquadTable;
									
};
/*------------------------------------------*/
inline CString TransDataPersistent::ValueType()
{
	return m_ValueType;
}
inline void TransDataPersistent::ValueType(CString strValue)
{
	m_ValueType = strValue;
}
/*------------------------------------------*/
inline CString TransDataPersistent::Special()
{
	return m_Special;
}
inline void TransDataPersistent::Special(CString strValue)
{
	m_Special = strValue;
}
/*------------------------------------------*/
inline CString TransDataPersistent::Repeat1()
{
	return m_Repeat1;
}
inline void TransDataPersistent::Repeat1(CString strValue)
{
	m_Repeat1 = strValue;
}
/*------------------------------------------*/
inline CString TransDataPersistent::Repeat2()
{
	return m_Repeat2;
}
inline void TransDataPersistent::Repeat2(CString strValue)
{
	m_Repeat2 = strValue;
}
/*------------------------------------------*/
inline CString TransDataPersistent::TranType()
{
	return m_TranType;
}
inline void TransDataPersistent::TranType(CString strValue)
{
	m_TranType = strValue;
}
/*------------------------------------------*/
inline StrArray<5>& TransDataPersistent::Periodic()
{
	return m_Periodic;
}
inline void TransDataPersistent::Periodic(const StrArray<5>& strValue)
{
	m_Periodic = strValue;
}
/*------------------------------------------*/
inline StrArray<8>& TransDataPersistent::TranTriger1()
{
	return m_TranTriger1;
}
inline void TransDataPersistent::TranTriger1(const StrArray<8>& strValue)
{
	m_TranTriger1 = strValue;
}
/*------------------------------------------*/
inline StrArray<8>& TransDataPersistent::TranTriger2()
{
	return m_TranTriger2;
}
inline void TransDataPersistent::TranTriger2(const StrArray<8>& strValue)
{
	m_TranTriger2 = strValue;
}

/*------------------------------------------*/
inline CString TransDataPersistent::TranModel()
{
	return m_TranModel;
}
inline void TransDataPersistent::TranModel(CString strValue)
{
	m_TranModel = strValue;
}
/*------------------------------------------*/
inline CString TransDataPersistent::Speed()
{
	return m_Speed;
}
inline void TransDataPersistent::Speed(CString strValue)
{
	m_Speed = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& TransDataPersistent::RotateInertia()
{
	return m_RotateInertia;
}
inline void TransDataPersistent::RotateInertia(const StrArray<2>& strValue)
{
	m_RotateInertia = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& TransDataPersistent::FourQuadrant()
{
	return m_FourQuadrantData;
}
inline void TransDataPersistent::FourQuadrant(const StrArray<3>& strValue)
{
	m_FourQuadrantData = strValue;
}
#endif // !defined(AFX_TRANSDATAPERSISTENT_H__AF9BA607_F926_486A_A725_7C0542E9067B__INCLUDED_)
