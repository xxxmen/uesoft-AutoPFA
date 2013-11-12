// AFTOutputRef.h: interface for the AFTOutputRef class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTOUTPUTREF_H__640F0487_1E73_4B3F_8BA9_9D9789902049__INCLUDED_)
#define AFX_AFTOUTPUTREF_H__640F0487_1E73_4B3F_8BA9_9D9789902049__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "OutPutRef.h"
#include "OutputRefPersist.h"
class AFX_EXT_CLASS AFTOutputRef  
{
public:
	AFTOutputRef();
	virtual ~AFTOutputRef();
	ErrorStatus::FileError Read(OutPutRefData &Data,OutputRefPersist &model);
	ErrorStatus::FileError Save(OutPutRefData &Data,OutputRefPersist &model);
};

#endif // !defined(AFX_AFTOUTPUTREF_H__640F0487_1E73_4B3F_8BA9_9D9789902049__INCLUDED_)
