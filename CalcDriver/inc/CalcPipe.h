// CalcPipe.h: interface for the CalcPipe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCPIPE_H__4B3888EC_74A9_4FCA_A435_627071F4841C__INCLUDED_)
#define AFX_CALCPIPE_H__4B3888EC_74A9_4FCA_A435_627071F4841C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS CalcPipe  
{
public:
	CalcPipe();
	virtual ~CalcPipe();

public:
	void Key(int nValue);
	void InJunID(int nValue);
	void OutJunID(int nValue);
	void InDia(double dValue);
	void Len(double dValue);
	void InitFlowType(int nValue);
	void InitFlow(double dValue);
	void FitFactor(double dValue);
	void LocalK(double dValue);
	void PipeFactor(double dValue);
	void FrictionModel(int nValue);
	void Friction(double dValue);
	void B(double dValue);
	void WaveSpeed(double dValue);
	void SectionNum(int nValue);
	void InDiaReduce(double dValue);

	int    Key();
	int    InJunID();
	int    OutJunID();
	double InDia();
	double Len();
	int	   InitFlowType();
	double InitFlow();
	double FitFactor();
	double LocalK();
	double PipeFactor();
	int    FrictionModel();
	double Friction();
	double B();
	double WaveSpeed();
	int    SectionNum();
	double InDiaReduce();
	friend ostream& operator<< (ostream &CalcOut,const CalcPipe &ref);

private:
	int m_nKey;						//管道编号
	int m_nInJunID;				    //入口节点的ID号
	int m_nOutJunID;				//出口节点的ID号
	double m_dInDia;				//管道内径
	double m_dLen;				    //管道长度
	int m_nInEleNum;				//内部管段数量——循环<距始点距离 高程>
	int m_nPartFull;				//是否是排空管
	double m_dFullRate;				//初始满管率
	int  m_nInitFlowType;			//初始化流体猜测类型（0，体积1，质量2、流速）
	double m_dInitFlow;				//初始化流体猜测大小
	double m_dPipeFactor;			//管道摩擦力设计因子，
	double m_dFitFactor;			//管道附加损失设计因子
	double m_dLocalK;				//总共局部的K系数
	int m_nFrictionModel;			//Friction Model类型:
	double m_dFriction;				//摩擦系数大小
	double m_dWaveSpeed;			//管道分段修正后波速值（波速）
	int m_nSectionNum;				//管段分段数取整
	double m_dInDiaReduce;			//内直径减少百分比
	double m_dB;                    //B(单位还不能转化根据波速计算)
};

#endif // !defined(AFX_CALCPIPE_H__4B3888EC_74A9_4FCA_A435_627071F4841C__INCLUDED_)
