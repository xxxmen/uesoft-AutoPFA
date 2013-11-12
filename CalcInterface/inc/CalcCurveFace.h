// CalcCurveFace.h: interface for the CalcCurveFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCCURVEFACE_H__024BCC1B_30EC_435E_B245_97CE6CAA1F16__INCLUDED_)
#define AFX_CALCCURVEFACE_H__024BCC1B_30EC_435E_B245_97CE6CAA1F16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcCurve;

class AFX_EXT_CLASS CalcCurveFace  
{
public:
	CalcCurveFace();
	virtual ~CalcCurveFace();
	ErrorStatus::FileError fireK(double &Data,StrArray<13> &Model);
	ErrorStatus::FileError LossType(int &Data,StrArray<13> &Model);
	ErrorStatus::FileError Save(CalcCurve &Data,StrArray<13> &Model);
										//损失模型(1：K系数恒定，2：K系数变化，3：阻力曲线)
										//Y轴参数类型数字标记[压力类型0：水头，1：压力]
										//Y轴参数单位[压力单位]
										//X轴参数类型数字标记[流体参数类型（0：体积流量1：质量流量2：流速3：雷偌数]
										//X轴参数单位[单位]
										//x的最大取值[体参数值的最大取值]
										//曲线类型[曲线类型（-2：K值变化，1：压力损失多项式，2：压力损失内插值）]
										//公式中参数和常量的个数[]
										//公式中的参数和常量a，b，c，d，e的值[]
	ErrorStatus::FileError Save(CalcCurve &Data,StrArray<7> &Model,CString strXUnit,CString strYUnit);
										//曲线类型（1：压力损失多项式，2：压力损失内插值）
										//公式中参数和常量的个数
										//公式中的参数和常量a，b，c，d，e的值
};

#endif // !defined(AFX_CALCCURVEFACE_H__024BCC1B_30EC_435E_B245_97CE6CAA1F16__INCLUDED_)
