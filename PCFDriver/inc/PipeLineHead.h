// PipeLineHeadList.h: interface for the PipeLineHeadList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIPELINEHEADLIST_H__1EA0BFE4_FEEE_43DE_B502_1462ABE804ED__INCLUDED_)
#define AFX_PIPELINEHEADLIST_H__1EA0BFE4_FEEE_43DE_B502_1462ABE804ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <map>
class AFX_EXT_CLASS PipeLineHead 
{
public:
	PipeLineHead();
	virtual ~PipeLineHead(); 
public:
	typedef std::map<CString , CStringArray*> Container ;
	typedef Container::iterator   Iterator ;

public:
	CStringArray* Find( const CString& strKey );
	void Add   ( const CString& strKey , CStringArray* wordArray ) ;
	void Remove( const CString& strKey ) ;
	void ClearAll() ;
	int  GetSize() ;

private:
	Container m_Container; 	
public:
	void Init(const CStringArray& array );
	static BOOL IsKeyWord( const CString& strKeyWord ) ;

private:
	static const CString m_strKeyWordArray[] ;

};

#endif // !defined(AFX_PIPELINEHEADLIST_H__1EA0BFE4_FEEE_43DE_B502_1462ABE804ED__INCLUDED_)
