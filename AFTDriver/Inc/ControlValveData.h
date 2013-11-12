// introlValveData.h: interface for the CintrolValveData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INTROLVALVEDATA_H__024B4285_7EBB_44D0_967B_0097F3FEEBD1__INCLUDED_)
#define AFX_INTROLVALVEDATA_H__024B4285_7EBB_44D0_967B_0097F3FEEBD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junction.h"
#include "JunTransData.h"
//流量控制阀
class AFX_EXT_CLASS ControlValveData : public JunctionData  
{
public:
	static JunctionData* Creator();
	ControlValveData();
	virtual ~ControlValveData();
public:
	StrArray<5> ControlSet();
	void ControlSet(const StrArray<5>& strValue);
	CString ModelType();
	void ModelType(CString strValue);
	CString KOrCv();
	void KOrCv(CString strValue);
	StrArray<4> FailAction();
	void FailAction(const StrArray<4>& strValue);
	StrArray<3> KOrCvUnit();
	void KOrCvUnit(const StrArray<3>& strValue);
	ListImp<StrArray<3> > KOrCvData();
	void KOrCvData(const ListImp<StrArray<3> >& strValue);
private:
	int KOrCvNum();
	int DataUnitNum();
	void AppendArray();
	void InitExtra(CString strData);
	virtual CString GetDefaultData();
public:
	JunTransData m_TranData;
	JunTransData m_FailTranData;
private:
	RowObjectFace<5> m_ControlSet;				//阀门类型0：PRF 1：PSV 2：FCV 3：PDCV
												//控制点参数类型0：水头/水头损失/体积流量1：压力/压力损失/质量流量
												//0：停滞压力1：静态压力
												//控制点参数值
												//控制点参数单位
	RowObjectFace<2> m_UnKown;					//-2（未知）\0（未知）
	RowObjectFace<1> m_ModelType;				//损失模型(0：流量系数模型，1：K系数模型 -2：使用系数表的值)
	RowObjectFace<1> m_KOrCv;					//K或Cv系数值
	RowObjectFace<1> m_UnKown4;					//none 
	RowObjectFace<1> m_DataUnitNum;				//1(打开百分比，K/CV系数)2(打开百分比单位\K/CV系数单位\阀门面积单位)
	RowObjectFace<1> m_KOrCvNum;				//阀门系数表数据的数量

	ThreeDTable      m_KOrCvData;				//打开百分比单位\K/CV系数单位\阀门面积单位
												//打开百分比，K/CV系数，阀门面积值

	//JunTransData m_TranData;					//没有周期函数RowObjectFace<5> m_Periodic;
												//没有RowObjectFace<1> m_Special;
												//没有TwoDTable m_Trans2Table;

	//JunTransData m_FailTranData;				//没有RowObjectFace<1> m_Special;
												//没有周期函数RowObjectFace<5> m_Periodic;
												//没有RowObjectFace<1> m_Repeat1;
												//没有RowObjectFace<1> m_Repeat2
												//没有RowObjectFace<1> m_TranType;
												//没有RowObjectFace<8> m_TranTriger1; 
												//没有RowObjectFace<8> m_TranTriger2; 
	RowObjectFace<3> m_UnKown5;					//0,0,None
	RowObjectFace<4> m_failAction;				//稳定状态总是控制0：没有选择 1：选择
												//使用默认的行为  0：没有选择 1：选择
												//上游压力不足表现0：全部打开 1：关闭
												//下游压力超过表现0：全部打开 1：关闭
	RowObjectFace<2> m_FthUnknown;				//0,1;
	RowObjectFace<5> m_FthUnknown1;				//0,None,0,0,NA
	RowObjectFace<1> m_FthAssert1;    
	RowObjectFace<1> m_FthAssert2;



};

#endif // !defined(AFX_INTROLVALVEDATA_H__024B4285_7EBB_44D0_967B_0097F3FEEBD1__INCLUDED_)
