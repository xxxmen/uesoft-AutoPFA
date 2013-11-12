// GraphItem.h: interface for the GraphItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPHITEM_H__62945E18_FC36_45C6_B1B2_1730C83F87A0__INCLUDED_)
#define AFX_GRAPHITEM_H__62945E18_FC36_45C6_B1B2_1730C83F87A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RowObject.h"

class GraphItem  
{
public:
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	GraphItem();
	virtual ~GraphItem();

private:
	RowObject m_data;
	RowObject m_Template;
};

#endif // !defined(AFX_GRAPHITEM_H__62945E18_FC36_45C6_B1B2_1730C83F87A0__INCLUDED_)
