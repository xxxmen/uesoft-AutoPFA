// JunOut.h: interface for the JunOut class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUNOUT_H__6EB28258_A05D_4453_A3F5_F5A822E367F0__INCLUDED_)
#define AFX_JUNOUT_H__6EB28258_A05D_4453_A3F5_F5A822E367F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ComponentStmOut.h"

class AFX_EXT_CLASS JunOut : public ComponentStmOut  
{
public:
	void SetSpeed(double dValue);
	void SetGasAccumVolume(double dValue);
	void SetGasAccumPress(double dValue);
	void SetSprayMassFlow(double dValue);
	void SetSprayVolumeFlow(double dValue);
	void SetSurgeLiquidH(double dValue);
	void SetSurgeHGL(double dValue);
	void SetTime(double dValue);
public:
	int Step();
	void Step(int nStep);
	double Data(int nKey,int nSubKey);

	JunOut();
	virtual ~JunOut();

private:
	int m_nStep;
};

#endif // !defined(AFX_JUNOUT_H__6EB28258_A05D_4453_A3F5_F5A822E367F0__INCLUDED_)
