// MOCJun.h: interface for the MOCJun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCJUN_H__087A9A7A_6FDC_4FB5_B82D_94E2D8C7FE99__INCLUDED_)
#define AFX_MOCJUN_H__087A9A7A_6FDC_4FB5_B82D_94E2D8C7FE99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCComponent.h"
#include "ListFlyWeightImp.h"
#include "MOCPipeMgr.h"
#include "MOCTrans.h"
#include "MOCTable.h"
#include "EndListRef.h"
#include "JunTranOut.h"

class CalcJun;
class JunStmOut;


class MOCJun : public MOCComponent  
{
public:
	MOCJun();
	virtual ~MOCJun();
public:
	virtual BOOL InitEndInfo() = 0;
	virtual BOOL Read(CalcJun *pData) = 0;
	virtual BOOL InitTranData(MOCComponentMgr &mgr);
protected:
	virtual void CalcStm() = 0;
	virtual void CalcImpulse(MOCTrans &trans,double dTime) = 0;
public:
	CString Name();
	virtual void Result(JunTranOut &out,int nStep);
	void CalcStm32();
	void CalcImpulse32(MOCTrans &trans,double dTime);
	void Result(JunStmOut &out);
	BOOL InitLinkEnd(MOCPipeMgr &mgr);
	static double K(double dCv,double dArea);
	static double RelToAbs(double dRatio,double dValue);
	EndListRef& GetEndList();
	EndInfo* GetInEnd();
	EndInfo* GetOutEnd();
protected:
	void ReadJun(CalcJun *pData);
	
protected:
	BOOL InitInOutEle();
	double BasisArea(int nType,double dValue);
	BOOL InitInfo(ListImp<StrArray<4> > &ref);
	CString m_strName;
	int    m_nID;
	double m_dInEle;			//节点入口标高
	double m_dOutEle;			//节点出口标高
	double m_dDesignFactor;		//损失设计因子
	double m_dInitGuess;		//初始化压力猜测值
	int    m_nSpecialMark;		//1.节点的特定条件0:正常，1：关闭：2：打开没有控制3：忽略
	ListImp<StrArray<1> > m_PipeID;	
	EndListRef m_EndList;
	MOCCurveData m_CurveData;

	double m_dInStagPress;
	double m_dOutStagPress;
	double m_dInStaticPress;
	double m_dOutStaticPress;
	double m_dInEGL;
	double m_dOutEGL;
	double m_dInHGL;
	double m_dOutHGL;
	double m_dLossK;
protected:
	int JunStatus();
	double GetK(double dK);
	void UpdataOneEnd();
	void UpdataTwoEnd();
	void UpdataPress(double dStag,double dStatic,double dZ,double &dStagPress,double &dStaticPress,double &dStagEGL,double &dStaticHGL);
	void UpdataEnd(EndInfo *pEnd,double &dStagPress,double &dStaticPress,double &dStagEGL,double &dStaticHGL);
	double GetEGLorHGL(double dPress,double dZ);
private:
	virtual void UpdataEnd()=0;
	virtual void CalculateK();
};
inline EndListRef& MOCJun::GetEndList()
{
	return m_EndList;
}
#endif // !defined(AFX_MOCJUN_H__087A9A7A_6FDC_4FB5_B82D_94E2D8C7FE99__INCLUDED_)
