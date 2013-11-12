// PipeTranOut.h: interface for the PipeTranOut class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIPETRANOUT_H__B47FBD12_BCDC_4259_BFF2_5765585DA8CF__INCLUDED_)
#define AFX_PIPETRANOUT_H__B47FBD12_BCDC_4259_BFF2_5765585DA8CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ComponentTranOut.h"
#include "StationOut.h"

class AFX_EXT_CLASS PipeTranOut:public ComponentTranOut  
{
public:
	StationOut* Creator(int nStep);
	ComponentStmOut* CreatorOut(int nKey);
	ComponentStmOut* LookUpMaxMin(int nKey);
	PipeTranOut();
	virtual ~PipeTranOut();
public:
	int GetArrayNum();
	virtual void GetArrayData(double dArray[], int nKey,OutDataAttr &attr);
	StationOut* GetStationOut();
	Iterator<StationOut>* CreatIterator();
	void InitMaxMin(double dTime);
	static void Instance(OutAttrArray &array,UnitSubSystem &unitsys);
	static void InstancePipeMaxMin(OutAttrArray &array,UnitSubSystem &unitsys);
	static void InstanceStationMaxMin(OutAttrArray &array,UnitSubSystem &unitsys);
private:
	void SetAllMaxMinData(ComponentStmOut *pStmOut);
	void SetMaxMinData(ComponentStmOut *pStmOut,int nIndex);
	void UpDataAllMaxMinData(ComponentStmOut *pStmOut);
	void UpDataMaxMinData(ComponentStmOut *pStmOut,int nIndex);
	void InitPipeMaxMin();
	void InitStationMaxMin(double dTime);
	static void InstanceMaxMin(OutAttrArray &array,UnitSubSystem &unitsys);
	ListImp<StationOut> m_list;
};

#endif // !defined(AFX_PIPETRANOUT_H__B47FBD12_BCDC_4259_BFF2_5765585DA8CF__INCLUDED_)
