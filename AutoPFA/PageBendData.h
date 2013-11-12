// PageBendData.h: interface for the PageBendData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PAGEBENDDATA_H__84A1CB10_0296_4EF7_8BEB_5C9EC32EF22C__INCLUDED_)
#define AFX_PAGEBENDDATA_H__84A1CB10_0296_4EF7_8BEB_5C9EC32EF22C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PageJunData.h"

class PageBendData : public PageJunData  
{
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageBendData();
	virtual ~PageBendData();

};

#endif // !defined(AFX_PAGEBENDDATA_H__84A1CB10_0296_4EF7_8BEB_5C9EC32EF22C__INCLUDED_)
