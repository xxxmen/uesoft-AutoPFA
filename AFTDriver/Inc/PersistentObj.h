// PersistentObj.h: interface for the PersistentObj class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PERSISTENTOBJ_H__96143065_EF8E_4CA6_916B_6AB0D27FD6BC__INCLUDED_)
#define AFX_PERSISTENTOBJ_H__96143065_EF8E_4CA6_916B_6AB0D27FD6BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RowObject.h"
#include "ListFlyWeightImp.h"
#include "ShareAFTDriver.h"
class SHARE_AFTDRIVER_CLASS PersistentObj  
{
public:
	void ChangeSub(CString strSub);
	void InsertSub(CString strSub);
	virtual BOOL Read(CStdioFile &file)=0;
	virtual BOOL Save(CStdioFile &file)=0;
	virtual void Init()=0;
	CString GetID();
	void SetID(CString strID);
	PersistentObj();
	virtual ~PersistentObj();
	PersistentObj(const PersistentObj &ref);
	PersistentObj& operator=(const PersistentObj &ref);
	static bool isImpFile ;
protected:
	typedef CArray<RowObject*,RowObject*>RowArrayRef;
	BOOL SaveRow(CStdioFile &file);
	BOOL ReadData(CStdioFile &file);
	BOOL SaveData(CStdioFile &file);
	BOOL SaveMark(CStdioFile &file);
	BOOL ReadMark(CStdioFile &file);
	RowArrayRef   m_RowArray;
private:
	CString m_strID;
	
};
typedef CArray<PersistentObj*,PersistentObj*>ObjectArray;
typedef CMap<CString,CString,PersistentObj*,PersistentObj*>ObjectMap;
inline void PersistentObj::SetID(CString strID)
{
	m_strID = strID + _T('\n');
}

inline CString PersistentObj::GetID()
{
	return m_strID;
}


#endif // !defined(AFX_PERSISTENTOBJ_H__96143065_EF8E_4CA6_916B_6AB0D27FD6BC__INCLUDED_)
