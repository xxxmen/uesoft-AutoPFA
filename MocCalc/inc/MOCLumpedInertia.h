// MOCLumpedInertia.h: interface for the MOCLumpedInertia class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCLUMPEDINERTIA_H__13F5BAB9_C4AF_4EF0_BAB7_CBF927889470__INCLUDED_)
#define AFX_MOCLUMPEDINERTIA_H__13F5BAB9_C4AF_4EF0_BAB7_CBF927889470__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcOrifice;
class CalcShortPipe;

class MOCLumpedInertia  
{
public:
	double ElePress();
	double EleChange();
	BOOL IsOrifice();
	double CalcC1(double dPOld1,double dPOld3,double dMassOld);
	double CalcC2(double dMassOld,BOOL bInSys);
	BOOL Read(CalcOrifice &orifice,CalcShortPipe &shortPipe);
	MOCLumpedInertia();
	virtual ~MOCLumpedInertia();

private:
	int	    m_bOrificeModel;		//0：没有选择节流孔板模型，1：选择节流孔板模型
	double	m_dInFlowCD;			//孔口输入流量系数
	double	m_dOutFlowCD;			//孔口输出流量系数
	double	m_dOrificeArea;			//孔口面积值
	int		m_bShortPipeModel;		//0：没有选择短管道模型，1：选择短管道模型
	double	m_dFriction;			//短管道摩擦系数
	double	m_dShortPipeArea;		//短管道面积
	double	m_dInDia;				//短管道内直径
	double	m_dLen;					//短管道长度
	double	m_dEle;					//短管道标高变化

};

#endif // !defined(AFX_MOCLUMPEDINERTIA_H__13F5BAB9_C4AF_4EF0_BAB7_CBF927889470__INCLUDED_)
