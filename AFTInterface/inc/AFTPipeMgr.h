// AFTPipeMgr.h: interface for the AFTPipeMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTPIPEMGR_H__4329579F_9516_4BB4_923D_5B81873063FF__INCLUDED_)
#define AFX_AFTPIPEMGR_H__4329579F_9516_4BB4_923D_5B81873063FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PipesManager.h"
#include "PipesMgr.h"

class AFX_EXT_CLASS AFTPipeMgr  
{
public:
	AFTPipeMgr();
	virtual ~AFTPipeMgr();
    ErrorStatus::FileError Read(PipesMgr &Data,PipesManager& model);
	ErrorStatus::FileError Save(PipesMgr &Data,PipesManager& model);

};

#endif // !defined(AFX_AFTPIPEMGR_H__4329579F_9516_4BB4_923D_5B81873063FF__INCLUDED_)
