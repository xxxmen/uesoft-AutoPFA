// SprayData.h: interface for the SprayData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPRAYDATA_H__32EE6AFA_8995_40AC_9D64_10F5D126A036__INCLUDED_)
#define AFX_SPRAYDATA_H__32EE6AFA_8995_40AC_9D64_10F5D126A036__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//喷嘴管口
#include "Junction.h"
#include "JunTransData.h"

class AFX_EXT_CLASS SprayData : public JunctionData  
{
public:
	static JunctionData* Creator();
	SprayData();
	virtual ~SprayData();
public:
	CString Type();
	void Type(CString strValue);
	StrArray<13> Curve();
	void Curve(const StrArray<13>& strValue);
	StrArray<3> ExitArea();
	void ExitArea(const StrArray<3>& strValue);
	CString KOrCv();
	void KOrCv(CString strValue);
	StrArray<3> ExitPress();
	void ExitPress(const StrArray<3>& strValue);
	//6.0下管道流向多加入了K系数和管道端口与节点标高
	ListImp<StrArray<4> > PipeInfo();
	void PipeInfo(const ListImp<StrArray<4> >& strValue);
	CString DistanceUnit();
	void DistanceUnit(CString strValue);
private:
	void AppendArray();
	void InitExtra(CString strData);
	virtual CString GetDefaultData();
public:
	JunTransData m_TranData;	
private:
	RowObjectFace<1> m_Type;			//类型(Spray类型0：喷嘴管口1：喷雾)
	VariableFace<13,7> m_Curve;			//损失模型(0：流量系数1：K系数(fire sprinklers K值的定义是： K = Q/sqrt(dP))
										//Y轴参数类型数字标记[选K系数本项数值为‘1]
										//Y轴参数单位[sqrt(dP)的单位]
										//X轴参数类型数字标记[流体参数类型（0：体积流量]
										//X轴参数单位[流量的单位]
										//x的最大取值[未使用]
										//曲线类型[未使用]
										//公式中参数和常量的个数[未使用]
										//公式中的参数和常量a，b，c，d，e的值[未使用]
	RowObjectFace<3> m_SprayArea;		//单个孔口的面积\面积单位\喷嘴孔的数量
	RowObjectFace<1> m_KOrCv;			//K或Cv系数值
	RowObjectFace<3> m_ExitPress;	    //出口压力的类型0：水头1：压力
										//压力值
										//单位
	//JunTransData m_TranData;			//没有周期函数RowObjectFace<5> m_Periodic;
	//6.0下多出“0,None,None,0,0,NA,0,None,”8项,拆分如下三项	
	RowObjectFace<2> m_Sparyfth1 ;		//6.0下多出"0,None,"2项
										//多出一项,存在m_EleUnit	
	RowObjectFace<5> m_Sparyfth2 ;		//6.0下多出“0,0,NA,0,None,”5项
	//6.0下管道流向多加入了K系数和管道端口与节点标高
	TableData<3> m_linkPipeK;			//流体从节点流入管道时管道端口k系数
										//流体从节点流出管道时管道端口k系数
										//管道端口与节点标高距离
	RowObjectFace<1> m_EleUnit;			//管道端口与节点标高距离单位
};

#endif // !defined(AFX_SPRAYDATA_H__32EE6AFA_8995_40AC_9D64_10F5D126A036__INCLUDED_)
