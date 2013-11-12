// MOCTrigerPipeVolumeStrategy.h: interface for the MOCTrigerPipeVolumeStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERPIPEVOLUMESTRATEGY_H__E706F195_6745_4D30_8824_38E7B52C275D__INCLUDED_)
#define AFX_MOCTRIGERPIPEVOLUMESTRATEGY_H__E706F195_6745_4D30_8824_38E7B52C275D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerPipeVolumeStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerPipeVolumeStrategy();
	virtual ~MOCTrigerPipeVolumeStrategy();
private:
	static BOOL EndVolumeFlow(MOCTrigerStrategyMgr &mgr,double &dValue);
};

#endif // !defined(AFX_MOCTRIGERPIPEVOLUMESTRATEGY_H__E706F195_6745_4D30_8824_38E7B52C275D__INCLUDED_)
