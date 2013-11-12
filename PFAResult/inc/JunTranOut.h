// JunTranOut.h: interface for the JunTranOut class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUNTRANOUT_H__5CC3F36E_89B5_48DE_9E5E_D2839482F574__INCLUDED_)
#define AFX_JUNTRANOUT_H__5CC3F36E_89B5_48DE_9E5E_D2839482F574__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ComponentTranOut.h"
#include "JunOut.h"
#include "OutputRefPersist.h"
class AFX_EXT_CLASS JunTranOut:public ComponentTranOut 
{
public:
	JunOut* Creator(int nStep);
	Iterator<JunOut>* CreatIterator();
	static void Instance(OutAttrArray &array,UnitSubSystem &unitsys);
	int GetArrayNum();
	void GetArrayData(double dArray[], int nKey, OutDataAttr &attr);
	JunTranOut();
	virtual ~JunTranOut();

private:
	void ShowAttr(int nKey);
	ListImp<JunOut> m_list;
};

#endif // !defined(AFX_JUNTRANOUT_H__5CC3F36E_89B5_48DE_9E5E_D2839482F574__INCLUDED_)
