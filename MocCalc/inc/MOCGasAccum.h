// MOCGasAccum.h: interface for the MOCGasAccum class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCGASACCUM_H__91BFA432_2356_4699_AF34_707BF5B6953F__INCLUDED_)
#define AFX_MOCGASACCUM_H__91BFA432_2356_4699_AF34_707BF5B6953F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"
#include "MOCLumpedInertia.h"

class MOCGasAccum : public MOCJun  
{
public:
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCGasAccum();
	virtual ~MOCGasAccum();

private:
	void CalcStm();
	BOOL InitEndInfo();

private:
	void Result(JunTranOut &out, int nStep);
	BOOL InitTranData(MOCComponentMgr &mgr);
	void CalcImpulse(MOCTrans &trans,double dTime);
	void UpdataEnd();
	double		  m_dPolytropic;					//变化的常量
	int           m_nType;						    //类型（0：初始化指定体积，1：初始化指定压力）
	double	      m_dInitVolume;					//初始化气体体
	double        m_dRefPress;				        //参考气体压力
	double		  m_dMaxVolume;					    //最大体积
	double		  m_dMinVolume;					    //最小体积											
	int			  m_bSelInitPress;					//静态流初试压力（0，没有选，1选中）
	double        m_dInitPress;					    //初始化压力
	MOCLumpedInertia m_lumpedInertia;                //集中阻力

	double m_dMass;                                  //瞬态流入系统流量
	double m_dCA;                                    //根据初试体积和压力计算的常量
};

#endif // !defined(AFX_MOCGASACCUM_H__91BFA432_2356_4699_AF34_707BF5B6953F__INCLUDED_)
