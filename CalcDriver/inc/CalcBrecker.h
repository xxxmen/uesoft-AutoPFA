// CalcBrecker.h: interface for the CalcBrecker class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCBRECKER_H__98B0AAB3_6345_4334_9407_7E377F562CC4__INCLUDED_)
#define AFX_CALCBRECKER_H__98B0AAB3_6345_4334_9407_7E377F562CC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"

class AFX_EXT_CLASS CalcBrecker : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcBrecker();
	virtual ~CalcBrecker();

public:
	void Type(int nValue);
	void OrificeInCdA(double dValue);
	void OrificeOutCdA(double dValue);
	void InterMediateCdA(double dValue);
	void MediateActivationType(int nValue);
	void MediateActivation(double dValue);
	void CrackPressType(int nValue);
	void CrackPress(double dValue);
	void LiquidTempType(int nValue);
	void LiquidTemp(double dValue);
	void GasWeight(double dValue);
	void CpCv(double dValue);
	void GasTemp(double dValue);
	void GasPress(double dValue);
	void GasMass(double dValue);
	void ConnectPipe(int nValue);

	int Type();
	double OrificeInCdA();
	double OrificeOutCdA();
	double InterMediateCdA();
	int MediateActivationType();
	double MediateActivation();
	int CrackPressType();
	double CrackPress();
	int LiquidTempType();
	double LiquidTemp();
	double GasWeight();
	double CpCv();
	double GasTemp();
	double GasPress();
	double GasMass();
	int ConnectPipe();
private:
	int			m_nType;			             //阀门类型0:真空破坏和气体释放1:真空破坏2:气体释放3:真空破坏和三阶段气体释放
	double      m_dOrificeInCdA;		         //孔口全部打开流入面积值
	double      m_dOrificeOutCdA;			     //流出面积值/单位
	double      m_dInterMediateCdA;			     //孔口全部打开媒介流出面积值
	int		    m_nMediateActivationType;		 //媒介孔口激活标准0：压力不同1：流速不同
	double      m_dMediateActivation;            //标准值
	int 		m_nCrackPressType;				 //破裂的压力类型0：水头，1：压力
	double		m_dCrackPress;				     //破裂的压力
	int         m_nLiquidTempType;				 //0：系统属性1：用户指定温度
	double		m_dLiquidTemp;					 //流体温度
	double		m_dGasWeight;					 //气分子量
	double      m_dCpCv;                         //Cp/Cv
	double      m_dGasTemp;						 //气体温度
	double      m_dGasPress;				     //气体压力
	double      m_dGasMass;						 //内部初始化气体气体质量
	int			m_nConnectPipe;					 //连接管道数0：两根管道1：一根管道
};


#endif // !defined(AFX_CALCBRECKER_H__98B0AAB3_6345_4334_9407_7E377F562CC4__INCLUDED_)
