// JunTransData.h: interface for the JunTransData class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：JunTransData.h
  摘要：    AFT瞬变数据
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUNTRANSDATA_H__04CCC98C_2A08_4E0E_968D_54ED1BCA43D9__INCLUDED_)
#define AFX_JUNTRANSDATA_H__04CCC98C_2A08_4E0E_968D_54ED1BCA43D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RowObjectFace.h"
#include "TableData.h"

class AFX_EXT_CLASS JunTransData  
{
public:
	RowObjectFace<3>& FourQuadrantData();
	RowObjectFace<1>& SpeedData();
	RowObjectFace<2>& RotateInertiaData();
	RowObjectFace<1>& TranModelData();
	RowObjectFace<8>& TranTriger2Data();
	RowObjectFace<8>& TranTriger1Data();
	RowObjectFace<5>& PeriodicData();
	RowObjectFace<1>& TransTypeData();
	RowObjectFace<1>& Repeat2Data();
	RowObjectFace<1>& Repeat1Data();
	RowObjectFace<1>& SpecialData();
	RowObjectFace<1>& ValueTypeData();
	JunTransData();
	virtual ~JunTransData();

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
	StrArray<5> Periodic();
	void Periodic(const StrArray<5>& strValue);
	StrArray<8> TranTriger1();
	void TranTriger1(const StrArray<8>& strValue);
	StrArray<8> TranTriger2();
	void TranTriger2(const StrArray<8>& strValue);
	CString TranModel();
	void TranModel(CString strValue);
	CString Speed();
	void Speed(CString strValue);
	StrArray<2> RotateInertia();
	void RotateInertia(const StrArray<2>& strValue);
	StrArray<3> FourQuadrant();
	void FourQuadrant(const StrArray<3>& strValue);

private:
	RowObjectFace<1> m_ValueType;		//1、0:绝对值，1：相对恒定流的值
	RowObjectFace<1> m_Special;			//2、0：瞬态特别条件选中“没有”，1：瞬态特别条件选“忽略瞬态数据”（针对具体节点特别条件多于2个分别查看特别条件对应的数字）
	RowObjectFace<1> m_Repeat1;			//3、0：第一次瞬变重复没选中，-1选中：
	RowObjectFace<1> m_Repeat2;			//4、0：第二次瞬变重复没选中，-1选中：
	RowObjectFace<1> m_TranType;		//5、0:时间，1：单个事件，2：两个事件循环3：两个连续事件
	RowObjectFace<5> m_Periodic;		//1、0：周期性没有选择，-1：流量周期性选择
										//2、0：没有选择使用正弦函数的绝对值，-1：选择使用正弦函数的绝对值
										//3、正弦函数频率
										//4、正弦函数振幅
										//5、正弦函数振幅单位
	RowObjectFace<8> m_TranTriger1;     //事件类型
										//条件类型
										//值
										//单位
										//管道入口触发事件为1；管道出口触发事件为2（第一根管道）
										//触发事件的管道编号（第一根管道）
										//管道入口触发事件为1；管道出口触发事件为2（第二根管道）
										//触发事件的管道编号（第二根管道）
	RowObjectFace<8> m_TranTriger2;

	//泵瞬变数据
	RowObjectFace<1> m_TranModel;				//泵瞬变模型
	RowObjectFace<2> m_RotateInertia;			//转动惯量（泵，电动机，流体）\转动惯量单位
	RowObjectFace<1> m_Speed;					//泵额定转速
	RowObjectFace<3> m_FourQuadrantData;        //四象限数据源标记\四象限数据的数量\角度选择0：1：
public:
	TwoDTable m_Trans1Table;			//none（未知）\1（未知）
										//瞬态数据数量（第一次瞬态）
									    //第一项数据单位\第二项数据单位
										//数据
	TwoDTable m_Trans2Table;			//none（未知）\1（未知）
										//瞬态数据数量（第一次瞬态）
									    //第一项数据单位\第二项数据单位
										//数据'

	ThreeDTable m_FourquadTable;        //泵使用的第四象限数据表
											
};

inline RowObjectFace<1>& JunTransData::ValueTypeData()
{
	return m_ValueType;
}

inline RowObjectFace<1>& JunTransData::SpecialData()
{
	return m_Special;
}

inline RowObjectFace<1>& JunTransData::Repeat1Data()
{
	return m_Repeat1;
}

inline RowObjectFace<1>& JunTransData::Repeat2Data()
{
	return m_Repeat2;	
}

inline RowObjectFace<1>& JunTransData::TransTypeData()
{
	return m_TranType;
}

inline RowObjectFace<5>& JunTransData::PeriodicData()
{
	return m_Periodic;
}

inline RowObjectFace<8>& JunTransData::TranTriger1Data()
{
	return m_TranTriger1;
}

inline RowObjectFace<8>& JunTransData::TranTriger2Data()
{
	return m_TranTriger2;
}

inline RowObjectFace<1>& JunTransData::TranModelData()
{
	return m_TranModel;
}

inline RowObjectFace<2>& JunTransData::RotateInertiaData()
{
	return m_RotateInertia;
}

inline RowObjectFace<1>& JunTransData::SpeedData()
{
	return m_Speed;
}

inline RowObjectFace<3>& JunTransData::FourQuadrantData()
{
	return m_FourQuadrantData;
}

#endif // !defined(AFX_JUNTRANSDATA_H__04CCC98C_2A08_4E0E_968D_54ED1BCA43D9__INCLUDED_)
