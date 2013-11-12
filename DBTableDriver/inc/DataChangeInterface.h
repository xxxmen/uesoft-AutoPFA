// DataChangeInterface.h: interface for the CDataChangeInterface class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATACHANGEINTERFACE_H__43BBB497_79D1_414F_BA0B_EBE218C3FF91__INCLUDED_)
#define AFX_DATACHANGEINTERFACE_H__43BBB497_79D1_414F_BA0B_EBE218C3FF91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS CDataChangeInterface  
{
public:
	void GetDataFrom(CalcTable<2> &DBTable);
	void PutDataInotFile(CalcTable<2> &DBTable);
	CDataChangeInterface();
	virtual ~CDataChangeInterface();

};

#endif // !defined(AFX_DATACHANGEINTERFACE_H__43BBB497_79D1_414F_BA0B_EBE218C3FF91__INCLUDED_)
