// GraphSet.h: interface for the GraphSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPHSET_H__B6C8E9A3_0F39_4480_874D_3F947EFFF90D__INCLUDED_)
#define AFX_GRAPHSET_H__B6C8E9A3_0F39_4480_874D_3F947EFFF90D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "persistentObj.h"
#include "GraphItem.h"
class GraphSet : public PersistentObj  
{
public:
	int GetGraphNum();
	void Init();
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	GraphSet();
	virtual ~GraphSet();
    GraphSet(const GraphSet &ref);
	GraphSet& operator=(const GraphSet &ref);
private:
	typedef CList<GraphItem*,GraphItem*> GraphItemList;
	void CloneList(const GraphItemList &itemList);
	void DelList();
	void InitArray();
	RowObject m_NumofGraph;
	GraphItemList m_ItemList;
	RowObject m_RecentSet;
};

#endif // !defined(AFX_GRAPHSET_H__B6C8E9A3_0F39_4480_874D_3F947EFFF90D__INCLUDED_)
