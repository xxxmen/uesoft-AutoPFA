// GeneralData.h: interface for the GeneralData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GENERALDATA_H__56A00CC8_089F_47AC_92FA_14F934745960__INCLUDED_)
#define AFX_GENERALDATA_H__56A00CC8_089F_47AC_92FA_14F934745960__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junction.h"
//通用阻力元件
class AFX_EXT_CLASS GeneralData : public JunctionData  
{
public:
	static JunctionData* Creator();
	GeneralData();
	virtual ~GeneralData();

public:
	CString Type();
	void Type(CString strValue);
	StrArray<13> Curve();
	void Curve(const StrArray<13>& strValue);
	CString KOrCv();
	void KOrCv(CString strValue);
	StrArray<3> BasisArea();
	void BasisArea(const StrArray<3>& strValue);

private:
	void AppendArray();
	void InitExtra(CString strData);
	virtual CString GetDefaultData();

private:
	RowObjectFace<1> m_Type;			//类型(0)
	VariableFace<13,7> m_Curve;			//损失模型(1：K系数恒定，2：K系数变化，3：阻力曲线)
										//Y轴参数类型数字标记[压力类型0：水头，1：压力]
										//Y轴参数单位[压力单位]
										//X轴参数类型数字标记[流体参数类型（0：体积流量1：质量流量2：流速3：雷偌数]
										//X轴参数单位[单位]
										//x的最大取值[体参数值的最大取值]
										//曲线类型[曲线类型（-2：K值变化，1：压力损失多项式，2：压力损失内插值）]
										//公式中参数和常量的个数[]
										//公式中的参数和常量a，b，c，d，e的值[]
	RowObjectFace<1> m_KOrCv;				//K系数值
	RowObjectFace<3> m_BasisArea;		//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
										//值
										//单位
	RowObjectFace<2> m_Fth2 ;			//0,None,
};

#endif // !defined(AFX_GENERALDATA_H__56A00CC8_089F_47AC_92FA_14F934745960__INCLUDED_)
