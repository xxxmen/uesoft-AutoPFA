// MOCPipe.h: interface for the MOCPipe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCPIPE_H__8FC702B0_058C_48C2_AE0C_76CF888BA842__INCLUDED_)
#define AFX_MOCPIPE_H__8FC702B0_058C_48C2_AE0C_76CF888BA842__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCComponent.h"
#include "EndInfo.h"
#include "MOCSteady.h"
#include "MOCTrans.h"
#include "MOCStationMgr.h"
#include "PipeTranOut.h"

class CalcPipe;
class PipeStmOut;


class MOCPipe : public MOCComponent  
{
public:
	void Result(PipeTranOut &out,int nStep);
	void CalcImpulse(MOCTrans &trans);
	BOOL InitStation();
	void CheckTol(MOCSteady &Steady);
	void Result(PipeStmOut &out);
	void CalcStm();
	void InitEndInfo();
	EndInfo* GetOutEnd();
	EndInfo* GetInEnd();
	double CalcArea();
	BOOL Read(CalcPipe &data);
	MOCPipe();
	virtual ~MOCPipe();
	double CalcR(double dF,double dEndK,int nSectionNum=1);
	double FrictionCalc();
	double B();
	double CalcR();
	double GetDeltaG();
private:
	double CalcRe();
private:
	double GetFLoss(double dF);
	double GetHLoss();
	double GetOutStaticPress();
	double GetInStaticPress();
	double GetOutStagPress();
	double GetInStagPress();
	double GetVelocity();
	double GetVolumeFlow();
	double GetMassFlow();
	double GetFK(double dF);
	double GetK(double dF);
	int m_nInJunID;				    //入口节点的ID号
	int m_nOutJunID;				//出口节点的ID号
	double m_dInDia;				//管道内径
	double m_dLen;				    //管道长度
	double m_dInitFlow;				//初始化流体流量
	double m_dPipeFactor;			//管道摩擦力设计因子，
	double m_dFitFactor;			//管道附加损失设计因子
	double m_dLocalK;				//总共局部的K系数
	int    m_nFrictionModel;		//Friction Model类型:
	double m_dFriction;				//摩擦系数大小
	int    m_nSectionNum;			//管段分段数取整
	double m_dB;                    //B
	MOCStationMgr m_stationMgr;

	EndInfo m_InEnd;
	EndInfo m_OutEnd;
	double m_dInOldPress;
	double m_dOutOldPress;
	double m_dInOldFlow;
	double m_dOutOldFlow;	
};

#endif // !defined(AFX_MOCPIPE_H__8FC702B0_058C_48C2_AE0C_76CF888BA842__INCLUDED_)
