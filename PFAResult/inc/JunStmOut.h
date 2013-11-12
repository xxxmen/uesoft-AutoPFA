// JunStmOut.h: interface for the JunStmOut class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUNSTMOUT_H__B40FC88B_B885_498C_80D3_10E924A17534__INCLUDED_)
#define AFX_JUNSTMOUT_H__B40FC88B_B885_498C_80D3_10E924A17534__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ComponentStmOut.h"
#include "OutputRefPersist.h"
#include "JunOutShow.h"
#include "OutPutSystem.h"
class UnitSubSystem;
class OutputRefPersist;

class AFX_EXT_CLASS JunStmOut :public ComponentStmOut 
{
public:
	static void Instance(OutAttrArray &array,UnitSubSystem &unitsys,OutputRefPersist &OutPutData,JunOutShowArray &ShowJunArray,OutPutSystem &OutPutSys);

	JunStmOut();
	virtual ~JunStmOut();
public:
	void SetInStagPress(double dValue);
	void SetOutStagPress(double dValue);
	void SetInStaticPress(double dValue);
	void SetOutStaticPress(double dValue);
	void SetGLoss(double dValue);
	void SetInMassFlow(double dValue);
	void SetInVolumeFlow(double dValue);
	void SetThruMassFlow(double dValue);
	void SetThruVolumeFlow(double dValue);
	void SetLossK(double dValue);
	void SetInEGL(double dValue);
	void SetOutEGL(double dValue);
	void SetInHGL(double dValue);
	void SetOutHGL(double dValue);	


	void static InitUnit(CString InData,CString str[50],TCHAR chSeparator = _T(','));
	void static InitData(CString InData,CString str[50],TCHAR chSeparator = _T(','));
};

#endif // !defined(AFX_JUNSTMOUT_H__B40FC88B_B885_498C_80D3_10E924A17534__INCLUDED_)
