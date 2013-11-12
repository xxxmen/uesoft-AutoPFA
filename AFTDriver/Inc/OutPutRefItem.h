// OutPutRefItem.h: interface for the OutPutRefItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OUTPUTREFITEM_H__39AA1461_085C_4F81_AC2B_1E8B067711FC__INCLUDED_)
#define AFX_OUTPUTREFITEM_H__39AA1461_085C_4F81_AC2B_1E8B067711FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RowObject.h"
class OutPutRefData;

class AFX_EXT_CLASS OutPutRefItem 
{
public:
	friend class OutPutRefData;
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	CString GetDataOrder();
	CString GetUnitOrder();
	void SetDataOrder(CString StrValue);
	void SetUnitOrder(CString StrValue);
	OutPutRefItem();
	virtual ~OutPutRefItem();

private:
	void InitDataOrder(CString InData);
	void InitUnitOrder(CString InData);

	RowObject m_DataOrder;
	RowObject m_UnitOrder;
};

#endif // !defined(AFX_OUTPUTREFITEM_H__39AA1461_085C_4F81_AC2B_1E8B067711FC__INCLUDED_)
