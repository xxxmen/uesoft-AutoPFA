// PipesMgr.h: interface for the PipesMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIPESMGR_H__4BA7A586_F96A_479B_BC2B_160E18C71F73__INCLUDED_)
#define AFX_PIPESMGR_H__4BA7A586_F96A_479B_BC2B_160E18C71F73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "persistentObj.h"
#include "PipeData.h"
#include "Iterator.h"

class AFX_EXT_CLASS PipesMgr : public PersistentObj  
{
public:
	Iterator<PipeData>* CreatIterator();
	PipeData* CreatPipe();
	int GetPipeNum();
	void SetPipeNum(int nNum);
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	void Init();
	PipesMgr();
	virtual ~PipesMgr();
	
private:
	typedef CList<PipeData*,PipeData*>PipeList;
	void DelList();
	PipesMgr(const PipesMgr &ref);
	PipesMgr& operator=(const PipesMgr &ref);
	RowObject m_NumOfPipe;
	PipeList m_pipeList;
};

#endif // !defined(AFX_PIPESMGR_H__4BA7A586_F96A_479B_BC2B_160E18C71F73__INCLUDED_)
