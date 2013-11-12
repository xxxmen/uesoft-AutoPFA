// TableBase.h: interface for the TableBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TABLEBASE_H__D423B7A3_3122_404D_A990_5808830B01E2__INCLUDED_)
#define AFX_TABLEBASE_H__D423B7A3_3122_404D_A990_5808830B01E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RowObjectFace.h"
#include "PersistentObj.h"
class AFX_EXT_CLASS TableBase:public PersistentObj  
{
public:
	virtual BOOL Read(CStdioFile &file)=0;
	virtual BOOL Save(CStdioFile &file)=0;
	virtual void Init()=0;
	TableBase();
	virtual ~TableBase();
public:
	CString GetKey();
	 
	int GetColNum();
	RowObjectFace<1>& NumData();
	RowObjectFace<2>& UnkownData();
	StrArray<2> Unkown();
	void Unkown(const StrArray<2>& strValue);

protected:
	int Num();
	RowObjectFace<2> m_Unkown;			//ID\列的数量
	RowObjectFace<1> m_Num;				//数据数量

};

#endif // !defined(AFX_TABLEBASE_H__D423B7A3_3122_404D_A990_5808830B01E2__INCLUDED_)
