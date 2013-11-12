// DeadEndData.h: interface for the DeadEndData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEADENDDATA_H__347A220B_813B_4379_A003_E14D4C2F4A5D__INCLUDED_)
#define AFX_DEADENDDATA_H__347A220B_813B_4379_A003_E14D4C2F4A5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junction.h"
//流体平衡和盲管
class AFX_EXT_CLASS DeadEndData : public JunctionData  
{
public:
	static JunctionData* Creator();
	DeadEndData();
	virtual ~DeadEndData();

private:
	void AppendArray();
	void InitExtra(CString strData);
	virtual CString GetDefaultData();
};

#endif // !defined(AFX_DEADENDDATA_H__347A220B_813B_4379_A003_E14D4C2F4A5D__INCLUDED_)
