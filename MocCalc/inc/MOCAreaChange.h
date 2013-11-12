// MOCAreaChange.h: interface for the MOCAreaChange class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCAREACHANGE_H__00191752_C0E3_44BB_BA42_07251D7C0F5B__INCLUDED_)
#define AFX_MOCAREACHANGE_H__00191752_C0E3_44BB_BA42_07251D7C0F5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCJun.h"

class MOCAreaChange : public MOCJun  
{
public:
	BOOL Read(CalcJun *pData);
	static MOCJun* Creator();
	MOCAreaChange();
	virtual ~MOCAreaChange();

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

#endif // !defined(AFX_MOCAREACHANGE_H__00191752_C0E3_44BB_BA42_07251D7C0F5B__INCLUDED_)
