// JunctionsMgr.h: interface for the JunctionsMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUNCTIONSMGR_H__CE0FB813_41F3_40FE_B9A3_4740C4AB3EF2__INCLUDED_)
#define AFX_JUNCTIONSMGR_H__CE0FB813_41F3_40FE_B9A3_4740C4AB3EF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Iterator.h"
#include "persistentObj.h" 
#include "Junction.h"

class JunDataFactory;

class AFX_EXT_CLASS JunctionsMgr: public PersistentObj  
{
public:
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	void Init();
	
	Iterator<JunctionData>* CreatIterator();
	JunctionData* CreatJun(int nID);
	int GetJunNum();
	void SetJunNum(int nNum);
	
	JunctionsMgr();
	virtual ~JunctionsMgr();

private:
	typedef CList<JunctionData*,JunctionData*>JunList;
	void DelList();
	JunctionsMgr(const JunctionsMgr &ref);
	JunctionsMgr& operator=(const JunctionsMgr &ref);
	RowObject m_NumOfJun;
	JunList m_junList;
	JunDataFactory *m_pFactory;
	
};

#endif // !defined(AFX_JUNCTIONSMGR_H__CE0FB813_41F3_40FE_B9A3_4740C4AB3EF2__INCLUDED_)
