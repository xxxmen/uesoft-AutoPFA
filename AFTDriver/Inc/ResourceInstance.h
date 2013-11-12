// ResourceInstance.h: interface for the CResourceInstance class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RESOURCEINSTANCE_H__2734409B_8B30_425D_8C93_8AD7A7212656__INCLUDED_)
#define AFX_RESOURCEINSTANCE_H__2734409B_8B30_425D_8C93_8AD7A7212656__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

extern HINSTANCE _hdllInstance;

class CResourceInstance  
{
public:
	CResourceInstance()
	{
		HINSTANCE m_hOldInstance = AfxGetResourceHandle();
		AfxSetResourceHandle(_hdllInstance);
	}
	virtual ~CResourceInstance()
	{
		AfxSetResourceHandle(m_hOldInstance);
	}
private:
	HINSTANCE m_hOldInstance;
};


#endif // !defined(AFX_RESOURCEINSTANCE_H__2734409B_8B30_425D_8C93_8AD7A7212656__INCLUDED_)
