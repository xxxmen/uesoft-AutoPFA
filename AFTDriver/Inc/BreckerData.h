// BreckerData.h: interface for the BreckerData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BRECKERDATA_H__36398309_949F_4F4A_9782_CF58CD82AEB8__INCLUDED_)
#define AFX_BRECKERDATA_H__36398309_949F_4F4A_9782_CF58CD82AEB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junction.h"
//真空破坏器(阀)
class AFX_EXT_CLASS BreckerData : public JunctionData  
{
public:
	static JunctionData* Creator();
	BreckerData();
	virtual ~BreckerData();

private:
	CString GetDefaultData();
	void AppendArray();
	void InitExtra(CString strData);

public:
	StrArray<3> CrackPress();
	void CrackPress(const StrArray<3>& strValue);
	StrArray<2> OrificeInCdA();
	void OrificeInCdA(const StrArray<2>& strValue);
	StrArray<2> OrificeOutCdA();
	void OrificeOutCdA(const StrArray<2>& strValue);
	StrArray<3> LiquidTemp();
	void LiquidTemp(const StrArray<3>& strValue);
	StrArray<9> GasProperty();
	void GasProperty(const StrArray<9>& strValue);
	CString ConnectPipe();
	void ConnectPipe(CString strValue);
	CString ValveType();
	void ValveType(CString strValue);
	StrArray<2> InterMediateCdA();
	void InterMediateCdA(const StrArray<2>& strValue);
	StrArray<3> MediateActivation();
	void MediateActivation(const StrArray<3>& strValue);
	
private:
	RowObjectFace<3>   m_CrackPress;             //破裂的压力类型0：水头，1：压力/压力值/压力单位
	RowObjectFace<2>   m_OrificeInCdA;             //孔口全部打开流入面积值/单位
	RowObjectFace<2>   m_OrificeOutCdA;			//流出面积值/单位
	RowObjectFace<3>   m_LiquidTemp;             //流体温度选择0：系统属性1：用户指定温度/温度值/单位
	RowObjectFace<9>   m_GasProperty;			//气体属性0：空气1、其它气体/分子量/Cp/Cv/气体温度/气体压力/内部初始化气体气体质量/单位
	RowObjectFace<1>   m_ConnectPipe;			//连接管道数0：两根管道1：一根管道
	RowObjectFace<1>   m_ValveType;				//阀门类型
	RowObjectFace<2>   m_InterMediateCdA;		//孔口全部打开媒介流出面积值/单位
	RowObjectFace<3>   m_MediateActivation;		//媒介孔口激活标准0：压力不同1：流速不同/标准值/准值的单位
};

#endif // !defined(AFX_BRECKERDATA_H__36398309_949F_4F4A_9782_CF58CD82AEB8__INCLUDED_)
