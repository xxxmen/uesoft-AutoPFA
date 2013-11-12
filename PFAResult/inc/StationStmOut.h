// StationStmOut.h: interface for the StationStmOut class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATIONSTMOUT_H__AD854A74_52F8_492F_9DEF_5B7EE8175F46__INCLUDED_)
#define AFX_STATIONSTMOUT_H__AD854A74_52F8_492F_9DEF_5B7EE8175F46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ComponentStmOut.h"

class  AFX_EXT_CLASS StationStmOut : public ComponentStmOut  
{
public:
	void SetMassFlow(double dValue);
	void SetVolumeFlow(double dValue);
	void SetVelocity(double dValue);
	void SetStagPress(double dValue);
	void SetStaticPress(double dValue);
	void SetEGL(double dValue);
	void SetHGL(double dValue);
	void SetTime(double dValue);
	void SetVopor(double dValue);

public:
	StationStmOut();
	virtual ~StationStmOut();
public:
	void InitMaxMin(ComponentStmOut&out,double dTime,int nStep);
	static void Instance(OutAttrArray &array,UnitSubSystem &unitsys);
private:
	void SetData(ComponentStmOut &out,double dTime,int nStep,int nIndex);
	void SetAllData(ComponentStmOut &out,double dTime,int nStep);
	void UpDataAllData(ComponentStmOut &out,double dTime,int nStep);
	void UpDataData(ComponentStmOut &out,double dTime,int nStep,int nIndex);
};

#endif // !defined(AFX_STATIONSTMOUT_H__AD854A74_52F8_492F_9DEF_5B7EE8175F46__INCLUDED_)
