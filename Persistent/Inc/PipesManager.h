// PipesManager.h: interface for the PipesManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIPESMANAGER_H__A56BB33F_0C42_497B_856F_6453A1290C6C__INCLUDED_)
#define AFX_PIPESMANAGER_H__A56BB33F_0C42_497B_856F_6453A1290C6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Iterator.h"
#include "PipePerisist.h"

class AFX_EXT_CLASS PipesManager  
{
public:
	PipesManager();
	virtual ~PipesManager();

public:
	int GetPipeNum();
	PipePerisist* CreatPipePerisit();
	Iterator<PipePerisist>* CreateIt();

private:
	void DelList();
	typedef CList<PipePerisist*,PipePerisist*> PipeList;
	PipeList m_pipeList;

};

#endif // !defined(AFX_PIPESMANAGER_H__A56BB33F_0C42_497B_856F_6453A1290C6C__INCLUDED_)
