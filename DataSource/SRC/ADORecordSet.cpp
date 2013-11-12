// ADORecordSet.cpp: implementation of the ADORecordSet class.
/************************************************************************
版本: 8.0  开发时间: 2008/12/18  作者:  denglb 评审人:
功能:        实现对数据集的操作                                                      
输入:                                                               
输出:                                                              
< 修改人 >    < 时间 >     < 版本 >        < 描述 >                                                                               
************************************************************************/

#include "stdafx.h"
#include "ADORecordSet.h"
#include "ADOException.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ADORecordSet::ADORecordSet()
{
	this->m_pRecordset = NULL;
}

ADORecordSet::~ADORecordSet()
{
	Close();
}

INT ADORecordSet::GetRecordCount() const
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	long lcount = 0;
	try
	{
		m_pRecordset->get_RecordCount(&lcount);
		return (INT)lcount;//为什么不把返回值设为INT？
	}
	catch(_com_error&)
	{
		//throw new UEADOException(e);
	}
	
}

void ADORecordSet::Close()
{
	try
	{
		if (m_pRecordset != NULL && m_pRecordset->State != adStateClosed)
		{
			SUCCEEDED(m_pRecordset->Close());
			m_pRecordset = NULL;
		}
	}
	catch (_com_error&)
	{
		//throw new UEADOException(e);
	}
}

BOOL ADORecordSet::IsBOF() const
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	return m_pRecordset->BOF;
}

BOOL ADORecordSet::IsEOF() const
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	return m_pRecordset->adoEOF;
}

BOOL ADORecordSet:: IsEmpty() const
{
	return IsEOF() && IsBOF();
}

void ADORecordSet::MoveFirst()
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		if (m_pRecordset != NULL) 
		{
			SUCCEEDED(m_pRecordset->MoveFirst());
		}
	}
	catch (_com_error e)
	{
		//throw new UEADOException(e);
	} 
}

void ADORecordSet::MovePrevious()
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		if (m_pRecordset != NULL) 
		{
			SUCCEEDED(m_pRecordset->MovePrevious());
		}
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	} 
}

void ADORecordSet::MoveNext()
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		if (m_pRecordset != NULL) 
		{
			SUCCEEDED(m_pRecordset->MoveNext());
		}
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	}
}

void ADORecordSet::MoveLast()
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		if (m_pRecordset != NULL) 
		{
			SUCCEEDED(m_pRecordset->MoveLast());
		}
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	} 
}

BOOL ADORecordSet::Update()
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		if (m_pRecordset != NULL) 
		{
			HRESULT hr = m_pRecordset->Update();
			if (SUCCEEDED(hr))
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}
		}
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	} 
	return FALSE;
}

void ADORecordSet::BatchUpdate()
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		m_pRecordset->UpdateBatch(adAffectAll);//默认方式
	}
	catch (_com_error e) 
	{
		//throw new UEADOException(e);
	}
}

//ADORecordSet::ADORecordSet(_RecordsetPtr m_pRecordset)
//{
//	this->m_pRecordset = m_pRecordset;
//}

void ADORecordSet::SetShort(const CString &strIndex, SHORT nValue)
{
	// 	UEASSERT( m_pRecordset != NULL, _T ( "很简单，不解释了" ) );
	try
	{
		m_pRecordset->PutCollect(_variant_t(strIndex),_variant_t(nValue));
	}
	catch (_com_error e)
	{
		//throw new UEADOException(e);
	}
}

void ADORecordSet::SetLong(const CString &strIndex, LONG nValue)
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		m_pRecordset->PutCollect(_variant_t(strIndex),_variant_t(nValue));
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	}
}

void ADORecordSet::SetDouble(const CString &strIndex, DOUBLE dbValue)
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		m_pRecordset->PutCollect(_variant_t(strIndex),_variant_t(dbValue));
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	}
}

void ADORecordSet::SetFloat(const CString &strIndex, FLOAT fValue)
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		m_pRecordset->PutCollect(_variant_t(strIndex),_variant_t(fValue));
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	}
}

void ADORecordSet::SetString(const CString &strIndex, const CString &strValue)
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		m_pRecordset->PutCollect(_variant_t(strIndex),_variant_t(strValue));
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	}
}

void ADORecordSet::SetBool(const CString &strIndex, bool bValue)
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		m_pRecordset->PutCollect(_variant_t(strIndex),_variant_t(bValue));
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	}
}

void ADORecordSet::NewRecord()
{
	// 	UEASSERT( m_pRecordset != NULL, _T ( "很简单，不解释了" ) );
	try
	{
		if (m_pRecordset->Supports(adAddNew))
		{
			m_pRecordset->AddNew();//只产生一条新记录，没有填充值。
		}
		else
		{
			AfxMessageBox(_T("不能插入"));
		}
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	}
}

short ADORecordSet::GetShort(const CString &strIndex) const
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		short sdefault = 0;
		_variant_t var;
		var = m_pRecordset->GetCollect(_variant_t(strIndex));
		if (var.vt == VT_NULL)
		{
			return sdefault;
		}
		return short(var);
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	}
	return 0;
}

LONG ADORecordSet::GetLong(const CString &strIndex) const
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		LONG ldefault = 0;
		_variant_t var;
		var = m_pRecordset->GetCollect(_variant_t(strIndex));
		if (var.vt == VT_NULL)
		{
			return ldefault;
		}
		return long(var);
	}
	catch (_com_error e)
	{
		//throw new UEADOException(e);
	}
	return 0;
}

DOUBLE ADORecordSet::GetDouble(const CString &strIndex) const
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		double ddefault = 0;
		_variant_t var;
		var = m_pRecordset->GetCollect(_variant_t(strIndex));
		if (var.vt == VT_NULL)
		{
			return ddefault;
		}
		return double(var);
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	}
	return 0;
}

FLOAT ADORecordSet::GetFloat(const CString &strIndex) const
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		float fdefault = 0;
		_variant_t var;
		var = m_pRecordset->GetCollect(_variant_t(strIndex));
		if (var.vt == VT_NULL)
		{
			return fdefault;
		}
		return float(var);
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	}
	return 0;
}

CString ADORecordSet::GetString(const CString &strIndex) const
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		_variant_t var;
		CString strdefault = _T("");
		var = m_pRecordset->GetCollect(_variant_t(strIndex));
		if (var.vt == VT_NULL)
		{
			return strdefault;
		}
		return (LPCSTR)_bstr_t(var);
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	}
	return _T("");
}

void ADORecordSet::Delete()
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		m_pRecordset->Delete(adAffectCurrent);//默认。仅删除当前记录。
		m_pRecordset->Update();//更新。要还是不要呢？
	}
	catch (_com_error e)
	{
		//throw new UEADOException(e);
	}
}

BOOL ADORecordSet::GetBool(const CString &strIndex) const
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		BOOL bdefault = FALSE;
		_variant_t var;
		var = m_pRecordset->GetCollect(_variant_t(strIndex));
		if (var.vt == VT_NULL)
		{
			return bdefault;
		}
		return bool(var);
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	}
	return false;
}

_variant_t ADORecordSet::Get_variant_t(const CString& strIndex) const
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		_variant_t vdefault;
		_variant_t var;
		var = m_pRecordset->GetCollect(_variant_t(strIndex));
		if (var.vt == VT_NULL)
		{
			return vdefault;
		}
		return var;
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	}
	return false;
}

void ADORecordSet::Set_variant_t(const CString& strIndex,_variant_t vr)
{
	// 	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		m_pRecordset->PutCollect(_variant_t(strIndex),vr);
	}
	catch (_com_error e)
	{
	//	throw new UEADOException(e);
	}
}

ADORecordSet::ADORecordSet(_RecordsetPtr m_pRecordset)
{
	this->m_pRecordset = m_pRecordset;
}
