// MOCReservior.h: interface for the MOCReservior class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCRESERVIOR_H__B18CE93B_F966_4B4C_9E86_5E7F4E557540__INCLUDED_)
#define AFX_MOCRESERVIOR_H__B18CE93B_F966_4B4C_9E86_5E7F4E557540__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"
#include "MOCTranData.h"

class MOCReservior : public MOCJun  
{
public:
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCReservior();
	virtual ~MOCReservior();

private:
	void CalcStm();
	BOOL InitEndInfo();

private:
	void SetTransZ(double dZ);
	void CalcImpulse(MOCTrans &trans,double dTime);
	BOOL InitTranData(MOCComponentMgr &mgr);
	void UpdataEnd();
	void InitPipeInfo(double dEle);
	double		 m_dSurfacePress;				//表面压力值
	int			 m_nEleOrDepthType;			    //管道与水库连接点标高或(深度0)
	ListImp<StrArray<6> > m_PipeInfo;				
												//1、连接管道的数字编号（从节点流出加负号）
												//2  类型
												//2、流体从节点流入管道时管道端口k系数
												//3、流体从节点流出管道时管道端口k系数
												//4、r/d（端口的园整度）
												//5、管道标高或深度

	MOCTranData m_tranData;
};

#endif // !defined(AFX_MOCRESERVIOR_H__B18CE93B_F966_4B4C_9E86_5E7F4E557540__INCLUDED_)
