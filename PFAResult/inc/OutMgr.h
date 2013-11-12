// OutMgr.h: interface for the OutMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OUTMGR_H__E29DC095_1FCB_4897_9487_6D583116F891__INCLUDED_)
#define AFX_OUTMGR_H__E29DC095_1FCB_4897_9487_6D583116F891__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "OutDataAttr.h"
#include "Iterator.h"
#include "ComponentStmOut.h"
#include "PipeOutShow.h"
#include "JunOutShow.h"
#include "OutPutSystem.h"
class  OutputRefPersist;

typedef CMap<int,int,ComponentStmOut*,ComponentStmOut*> StmOutMap;

class AFX_EXT_CLASS OutMgr  
{
public:
	BOOL IsEmpty();
	int GetCount();
	void EmptyOut();
	OutAttrArray& GetArray();
	OutAttrArray& GetAllArray();
	virtual ComponentStmOut* LookUp(int nKey);
	virtual Iterator<ComponentStmOut>* CreatIterator();
	OutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData);
	virtual ~OutMgr();
	OutputRefPersist &m_OutPutData;
	OutPutSystem m_OutPutSys;

protected:
	virtual void InitAttrArray()=0;
	UnitSubSystem &m_unitsys;
	StmOutMap m_outMap;
	OutAttrArray m_attrArray;     //支持多文档的话就不用静态成员。
	OutAttrArray m_attAllArray;   //在文本结果里可能显示的所有属性
	PipeOutShowArray m_PipeArray;
	JunOutShowArray m_JunArray;
	
};

#endif // !defined(AFX_OUTMGR_H__E29DC095_1FCB_4897_9487_6D583116F891__INCLUDED_)
