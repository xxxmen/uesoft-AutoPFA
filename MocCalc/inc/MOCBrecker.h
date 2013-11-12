// MOCBrecker.h: interface for the MOCBrecker class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCBRECKER_H__EADA4B80_1AB7_4866_A154_C962198D351C__INCLUDED_)
#define AFX_MOCBRECKER_H__EADA4B80_1AB7_4866_A154_C962198D351C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"
#include "GasProperty.h"

class MOCBrecker : public MOCJun  
{
public:
	void UpdataEnd();
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCBrecker();
	virtual ~MOCBrecker();

private:
	void CalcStm();
	BOOL InitEndInfo();

private:
	void CheckIsClose();
	BOOL IsCrack();
	void CalcImpulse(MOCTrans &trans,double dTime);
	int			m_nType;			             //阀门类型0:真空破坏和气体释放1:真空破坏2:气体释放3:真空破坏和三阶段气体释放
	double      m_dOrificeInCdA;		         //孔口全部打开流入面积值
	double      m_dOrificeOutCdA;			     //流出面积值/单位
	double      m_dInterMediateCdA;			     //孔口全部打开媒介流出面积值
	int		    m_nMediateActivationType;		 //媒介孔口激活标准0：压力不同1：流速不同
	double      m_dMediateActivation;            //标准值
	double		m_dCrackPress;				     //破裂的压力
	int			m_nConnectPipe;					 //连接管道数0：两根管道1：一根管道
	GasProperty m_GasPropety;

	BOOL m_bClose;                              //空气阀门状态
};

#endif // !defined(AFX_MOCBRECKER_H__EADA4B80_1AB7_4866_A154_C962198D351C__INCLUDED_)
