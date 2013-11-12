// AFTSectionPipeFace.h: interface for the AFTSectionPipeFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTSECTIONPIPEFACE_H__DB2D3862_37E3_4812_8E70_0B53A1D47444__INCLUDED_)
#define AFX_AFTSECTIONPIPEFACE_H__DB2D3862_37E3_4812_8E70_0B53A1D47444__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SectionData.h"
#include "SectionPipePersistent.h"
class AFX_EXT_CLASS AFTSectionPipeFace  
{
public:
	AFTSectionPipeFace();
	virtual ~AFTSectionPipeFace();
	ErrorStatus::FileError Read(SectionData &Data,SectionPipePerisistent &model);
	ErrorStatus::FileError Save(SectionData &Data,SectionPipePerisistent &model);

};

#endif // !defined(AFX_AFTSECTIONPIPEFACE_H__DB2D3862_37E3_4812_8E70_0B53A1D47444__INCLUDED_)
