// PrintFontRef.h: interface for the PrintFontRef class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRINTFONTREF_H__3ABEB74B_8EB4_41DD_9D68_CDB14DB88446__INCLUDED_)
#define AFX_PRINTFONTREF_H__3ABEB74B_8EB4_41DD_9D68_CDB14DB88446__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "persistentObj.h"

class PrintFontRef : public PersistentObj  
{
public:
	void Init();
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	PrintFontRef();
	virtual ~PrintFontRef();

private:
	void InitRowHead();
	void InitArray();
	RowObject  m_FontName;
	RowObject  m_FontSize;
	RowObject  m_FontBold;
	RowObject  m_FontItalic;
};

#endif // !defined(AFX_PRINTFONTREF_H__3ABEB74B_8EB4_41DD_9D68_CDB14DB88446__INCLUDED_)
