// MOCBend.h: interface for the MOCBend class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCBEND_H__B15F08EE_23F5_465E_BEEB_A20EE5039BE2__INCLUDED_)
#define AFX_MOCBEND_H__B15F08EE_23F5_465E_BEEB_A20EE5039BE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"

class MOCBend : public MOCJun  
{
public:
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCBend();
	virtual ~MOCBend();

private:
	void CalcStm();
	BOOL InitEndInfo();

private:
	void CalcImpulse(MOCTrans &trans,double dTime);
	void UpdataEnd();
	double  m_dK;								//K系数值
	int     m_nBasisAreaType;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
	double  m_dBasisArea;						//面积哦or直径
};

#endif // !defined(AFX_MOCBEND_H__B15F08EE_23F5_465E_BEEB_A20EE5039BE2__INCLUDED_)
