// MOCSurge.h: interface for the MOCSurge class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCSURGE_H__3083F755_42C7_4C4A_A936_B7CE5BA6D680__INCLUDED_)
#define AFX_MOCSURGE_H__3083F755_42C7_4C4A_A936_B7CE5BA6D680__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"
#include "MOCLumpedInertia.h"
#include "MOCTranData.h"
#include "MOCTable.h"

class MOCSurge : public MOCJun  
{
public:
	double GetLiquldHeight();
	double GetGL();
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCSurge();
	virtual ~MOCSurge();

private:
	void CalcStm();
	BOOL InitEndInfo();

private:
	void Result(JunTranOut &out, int nStep);
	double GetArea(double dH);
	void CalcImpulse(MOCTrans &trans,double dTime);
	BOOL InitTranData(MOCComponentMgr &mgr);
	void UpdataEnd();
    ListImp<StrArray<4> >	m_PipeInfo;
	double			 m_dSurfacePress;				//表面压力
	double			 m_dSurgeHeight;				//调压塔的高度
	double			 m_dConstArea;					//底面积值
	DataTable        m_AreaTable;			
	int 			 m_bOneWay;						//“One-Way Surge Tank”0：没有选择，1选择来建模有止回阀特征的缓冲罐。
	double           m_dCheckCv;					//止回阀流量系数
	int              m_nPosition;					//止回阀初始位置0：打开1：关闭
	double	         m_dReOpenPress;				//压力值         
	int     		 m_bSelVessel;					//模拟文丘里管0：没有选择，1：选择
	double           m_dVesselHeight;				//文丘里管到管道的高度
	double			 m_dPolytropic;					//多变的常量
	int              m_bSelSurfaceH;				//稳定状态初始化流体高度0：没有选择1：选择
	double			 m_dInitSurfaceH;	        	//高度值
	MOCLumpedInertia m_lumpedInertia;               //集中阻力
	MOCTranData m_tranData;

	double m_dLiquldHeight;
	double m_dMass;
};
inline double MOCSurge::GetLiquldHeight()
{
	return m_dLiquldHeight;
}

#endif // !defined(AFX_MOCSURGE_H__3083F755_42C7_4C4A_A936_B7CE5BA6D680__INCLUDED_)
