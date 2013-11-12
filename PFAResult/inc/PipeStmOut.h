// PipeStmOut.h: interface for the PipeStmOut class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIPESTMOUT_H__F68233EE_A002_4ED8_A4F0_794CAD128C2D__INCLUDED_)
#define AFX_PIPESTMOUT_H__F68233EE_A002_4ED8_A4F0_794CAD128C2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ComponentStmOut.h"
#include "OutPutRef.h"
#include "OutputRefPersist.h"
#include "PipeOutShow.h"
#include "OutPutSystem.h"

class UnitSubSystem;


class AFX_EXT_CLASS PipeStmOut :public ComponentStmOut 
{
public:

	void SetMassFlow(double dValue);
	void SetVolumeFlow(double dValue);
	void SetVelocity(double dValue);
	void SetInStagPress(double dValue);
	void SetOutStagPress(double dValue);
	void SetStagPressLoss(double dValue);
	void SetInStaticPress(double dValue);
	void SetOutStaticPress(double dValue);
	void SetStaticPressLoss(double dValue);
	void SetHLoss(double dValue);
	void SetGLoss(double dValue);
	void SetFLoss(double dValue);
	void SetLossFactorF(double dValue);
	void SetLossFactorT(double dValue);
	void SetInEGL(double dValue);
	void SetOutEGL(double dValue);
	void SetInHGL(double dValue);
	void SetOutHGL(double dValue);

	CString static ReadUnitOrder(LPCTSTR filename);

	void static InitUnit(CString InData,CString str[50],TCHAR chSeparator = _T(','));
	void static InitData(CString InData,CString str[50],TCHAR chSeparator = _T(','));

public:
	static void Instance(OutAttrArray &array,UnitSubSystem &unitsys,OutputRefPersist &OutPutData,PipeOutShowArray &ShowPipeArray,OutPutSystem &OutPutSys);

	PipeStmOut();
	virtual ~PipeStmOut();

protected:
private:
	
		
};

#endif // !defined(AFX_PIPESTMOUT_H__F68233EE_A002_4ED8_A4F0_794CAD128C2D__INCLUDED_)
