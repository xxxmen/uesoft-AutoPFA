// ComponentTranOut.h: interface for the ComponentTranOut class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPONENTTRANOUT_H__1D5EB84D_5838_4527_BF88_1D2984210DAB__INCLUDED_)
#define AFX_COMPONENTTRANOUT_H__1D5EB84D_5838_4527_BF88_1D2984210DAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ComponentStmOut.h"

class AFX_EXT_CLASS ComponentTranOut:public ComponentStmOut  
{
public:
	virtual void GetArrayData(double dArray[],int nKey,OutDataAttr &attr)=0;
	virtual int GetArrayNum()=0;
	ComponentTranOut();
	virtual ~ComponentTranOut();
	Iterator<ComponentStmOut>* CreatMaxMinIterator();

protected:
	ListImp<ComponentStmOut> m_MaxMinStation;
};

#endif // !defined(AFX_COMPONENTTRANOUT_H__1D5EB84D_5838_4527_BF88_1D2984210DAB__INCLUDED_)
