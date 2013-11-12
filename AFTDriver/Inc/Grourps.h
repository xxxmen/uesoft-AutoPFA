// Grourps.h: interface for the Grourps class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GROURPS_H__CE0ECA59_131E_4CD4_8116_5243B4A11BDC__INCLUDED_)
#define AFX_GROURPS_H__CE0ECA59_131E_4CD4_8116_5243B4A11BDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "persistentObj.h"

class Grourps : public PersistentObj  
{
public:
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	Grourps();
	virtual ~Grourps();

};

#endif // !defined(AFX_GROURPS_H__CE0ECA59_131E_4CD4_8116_5243B4A11BDC__INCLUDED_)
