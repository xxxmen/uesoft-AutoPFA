// OutputRefPersist.h: interface for the OutputRefPersist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OUTPUTREFPERSIST_H__D0FD93A3_9F23_4116_ABB8_39E1F9A3989E__INCLUDED_)
#define AFX_OUTPUTREFPERSIST_H__D0FD93A3_9F23_4116_ABB8_39E1F9A3989E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS OutputRefPersist  
{
public:
	OutputRefPersist();
	virtual ~OutputRefPersist();

public:
	void Init();
	CString PipeDataOrder();
	void PipeDataOrder(CString strValue);
	CString PipeUnitOrder();
	void PipeUnitOrder(CString strValue);
	CString JunDataOrder();
	void JunDataOrder(CString strValue);
	CString JunUnitOrder();
	void JunUnitOrder(CString strValue);

	CString TranDataOrder();
	void TranDataOrder(CString strValue);
	CString TranUnitOrder();
	void TranUnitOrder(CString strValue);

	CString MaxMinDataOrder();
	void MaxMinDataOrder(CString strValue);
	CString MaxMinUnitOrder();
	void MaxMinUnitOrder(CString strValue);

private:
	CString m_PipeDataOrder;
	CString m_PipeUnitOrder;
	CString m_JunDataOrder;
	CString m_JunUnitOrder;
	CString m_TranDataOrder;
	CString m_TranUnitOrder;
	CString m_MaxMinDataOrder;
	CString m_MaxMinUnitOrder;
};

inline CString OutputRefPersist::PipeDataOrder()
{
	if ( m_PipeDataOrder != _T("") )
	{
		return m_PipeDataOrder ;
	}
	else
	{
		return m_PipeDataOrder = _T("114,4,3,7,11,12,22,8,9,17,31,21,18,99,101,29,30,27,28") ;
	}
}

inline void OutputRefPersist::PipeDataOrder(CString strValue)
{
	m_PipeDataOrder = strValue;
}

inline CString OutputRefPersist::PipeUnitOrder()
{
	if ( m_PipeUnitOrder != _T("") )
	{
		return m_PipeUnitOrder ;
	}
	else
	{
		return m_PipeUnitOrder = _T("None,kg/sec,cm3/sec,meters/sec,Pascals,Pascals,Pascals,Pascals,Pascals,Pascals,meters,Pascals,Pascals,None,None,meters,meters,meters,meters") ;
	}
//	return m_PipeUnitOrder;
}

inline void OutputRefPersist::PipeUnitOrder(CString strValue)
{
	m_PipeUnitOrder=strValue;
}

inline CString OutputRefPersist::JunDataOrder()
{
	if ( m_JunDataOrder != _T("") )
	{
		return m_JunDataOrder ;
	}
	else
	{
		return m_JunDataOrder = _T("40,3,4,1,2,53,27,28,29,30,38,9,10,7,8") ;
	}
//	return m_JunDataOrder;
}

inline void OutputRefPersist::JunDataOrder(CString strValue)
{
	m_JunDataOrder=strValue;
}

inline CString OutputRefPersist::JunUnitOrder()
{
	if ( m_JunUnitOrder != _T("") )
	{
		return m_JunUnitOrder ;
	}
	else
	{
		return m_JunUnitOrder = _T("None,Pascals,Pascals,Pascals,Pascals,Pascals,kg/sec,m3/sec,kg/sec,m3/sec,None,meters,meters,meters,meters") ;
	}
//	return m_JunUnitOrder;
}

inline void OutputRefPersist::JunUnitOrder(CString strValue)
{
	m_JunUnitOrder=strValue;
}


inline CString OutputRefPersist::TranDataOrder()
{
    if ( m_TranDataOrder != _T("") )
    {
		return m_TranDataOrder;
    }
	else
	{
		return m_TranDataOrder = _T("0,29,1,2,3,4,5,6,7,8,9");
	}
}
inline void OutputRefPersist::TranDataOrder(CString strValue)
{
	m_TranDataOrder = strValue;
}
inline CString OutputRefPersist::TranUnitOrder()
{
	if ( m_TranUnitOrder != _T("") )
	{
		return m_TranUnitOrder;
	}
	else
	{
		return m_TranUnitOrder = _T("None,None,Pascals,meters,kg/sec,m3/sec,meters/sec,Pascals,meters,seconds,meters3");
	}
}
inline void OutputRefPersist::TranUnitOrder(CString strValue)
{
    m_TranUnitOrder = strValue;
}

inline CString OutputRefPersist::MaxMinDataOrder()
{
    if ( !m_MaxMinDataOrder.IsEmpty() )
    {
		return m_MaxMinDataOrder;
    }
	else
	{
		return m_MaxMinDataOrder = _T("0,29,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28");
	}
}
inline void OutputRefPersist::MaxMinDataOrder(CString strValue)
{
    m_MaxMinDataOrder = strValue;
}
inline CString OutputRefPersist::MaxMinUnitOrder()
{
	if ( !m_MaxMinUnitOrder.IsEmpty() )
	{
		return m_MaxMinUnitOrder;
	}
	else
	{
		return m_MaxMinUnitOrder = _T("None,None,Pascals,seconds,Pascals,seconds,meters,seconds,meters,seconds,kg/sec,seconds,kg/sec,seconds,m3/sec,seconds,m3/sec,seconds,meters/sec,seconds,meters/sec,seconds,Pascals,seconds,Pascals,seconds,meters,seconds,meters,seconds");
	}
}
inline void OutputRefPersist::MaxMinUnitOrder(CString strValue)
{
    m_MaxMinUnitOrder = strValue;
}

#endif // !defined(AFX_OUTPUTREFPERSIST_H__D0FD93A3_9F23_4116_ABB8_39E1F9A3989E__INCLUDED_)
