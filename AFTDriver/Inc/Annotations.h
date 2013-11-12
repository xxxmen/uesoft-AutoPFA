// Annotations.h: interface for the Annotations class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANNOTATIONS_H__8A6DCDBA_E373_4217_BF8C_C5CFAAC7CCD9__INCLUDED_)
#define AFX_ANNOTATIONS_H__8A6DCDBA_E373_4217_BF8C_C5CFAAC7CCD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "persistentObj.h"

class Annotations : public PersistentObj  
{
public:
	void Init();
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	Annotations();
	virtual ~Annotations();

private:
	void InitArray();
	RowObject m_NumOfAnnotations;
	

};

#endif // !defined(AFX_ANNOTATIONS_H__8A6DCDBA_E373_4217_BF8C_C5CFAAC7CCD9__INCLUDED_)
