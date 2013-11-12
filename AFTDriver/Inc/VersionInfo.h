// VersionInfo.h: interface for the VersionInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VERSIONINFO_H__95BFF9C8_C0BB_48DE_97F4_41D48FE56B44__INCLUDED_)
#define AFX_VERSIONINFO_H__95BFF9C8_C0BB_48DE_97F4_41D48FE56B44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PersistentObj.h"


class VersionInfo : public PersistentObj  
{
public:
	void Init();
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	VersionInfo();
	virtual ~VersionInfo();
private:
	void InitRowHead();
	void InitArray();
	RowObject m_AppName;
	RowObject m_Version;
	RowObject m_CstUse;
	RowObject m_GscUse;
	RowObject m_XtsUse;

};

#endif // !defined(AFX_VERSIONINFO_H__95BFF9C8_C0BB_48DE_97F4_41D48FE56B44__INCLUDED_)
