// RowObject.h: interface for the RowObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROWOBJECT_H__402DAE77_3474_41A2_ADFE_BC7455CAD785__INCLUDED_)
#define AFX_ROWOBJECT_H__402DAE77_3474_41A2_ADFE_BC7455CAD785__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class AFX_EXT_CLASS RowObject  
{
public:
	//nIndex从0开始
	BOOL SetData(int nData,int nIndex=0);
	BOOL SetData(double dData,int nIndex=0);
	BOOL SetData(CString strData,int nIndex);
	BOOL SetSeparator(TCHAR chSeparator,int nIndex);
	TCHAR GetSeparator(int nIndex);
	BOOL SetData(long nData,int nIndex=0);
	BOOL GetData(int &nData,int nIndex=0);
	BOOL GetData(double &dData,int nIndex=0);
	BOOL GetData(CString &strData,int nIndex=0);
	BOOL GetData(long &nData,int nIndex=0);
public:
	void InitRow(CString InData);
public:
	BOOL HasChild();
	CString ReadChild(CString InData ,int nNum,TCHAR chSeparator = _T(','));
	CString Read(CString InData ,int nNum,TCHAR chSeparator = _T(','));
	CString Read(CString InData ,TCHAR chSeparator = _T(','));//得到分割符号前面的字符，返回分割符号后面字符
	void AddChild(RowObject &ref);
	void SetChild(int index,RowObject &ref);
	void ReadChild(CString InData ,TCHAR chSeparator = _T(','));
	CString Save();
	void InitHead(CString InData);
	CString GetData();
	void SetData(CString strData);
	void SetSeparator(TCHAR chSeparator);
	TCHAR GetSeparator();
	void RemoveAll();
public:
	int GetChildNum();
	RowObject();
	virtual ~RowObject();
	RowObject(const RowObject &ref);
	RowObject& operator=(const RowObject &ref);

	
private:
	typedef CArray<RowObject,RowObject&>ChildRow;
	ChildRow m_child;
	CString  m_strData;
	TCHAR    m_chSeparator;
};

inline CString RowObject::GetData()
{
	return m_strData;
}

inline void RowObject::SetData(CString strData)
{
	m_strData = strData;
}

inline void RowObject::SetSeparator(TCHAR chSeparator)
{
	m_chSeparator = chSeparator;
}
inline TCHAR RowObject::GetSeparator()
{
	return m_chSeparator;
}
#endif // !defined(AFX_ROWOBJECT_H__402DAE77_3474_41A2_ADFE_BC7455CAD785__INCLUDED_)
