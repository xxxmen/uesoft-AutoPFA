// UEADORecordset.cpp: implementation of the UEADORecordset class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UEADORecordset.h"
#include "UEADOException.h"
#include "ueassert.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UEADORecordset::UEADORecordset()
{
	this->m_pRecordset = NULL;
}

UEADORecordset::~UEADORecordset()
{
	Close();
}

/*************************************************
  Function:       GetRecordCount
  Description:    获取当前记录集的记录数目
  Calls:          
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  无
  Input:          无
  Output:         无
  Return:         INT值（记录数目）
  Others:         
*************************************************/

INT UEADORecordset::GetRecordCount() const
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	long lcount = 0;
	try
	{
		m_pRecordset->get_RecordCount(&lcount);
		return (INT)lcount;//为什么不把返回值设为INT？
	}
	catch(_com_error e)
	{
		throw new UEADOException(e);
	} 
}


/*************************************************
  Function:       Close
  Description:    关闭当前记录集
  Calls:          ADO方法Close
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  当前记录集
  Input:          无
  Output:         无
  Return:         无
  Others:         
*************************************************/

void UEADORecordset::Close()
{
	try
	{
		if (m_pRecordset != NULL && m_pRecordset->State != adStateClosed)
		{
			SUCCEEDED(m_pRecordset->Close());
			m_pRecordset = NULL;
		}
	}
	catch (_com_error& e)
	{
		throw new UEADOException(e);
	}
}


/*************************************************
  Function:       IsBOF
  Description:    判断是否位于记录集的最开始
  Calls:          
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  无
  Input:          无
  Output:         无
  Return:         BOOL值
  Others:         
*************************************************/

BOOL UEADORecordset::IsBOF() const
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	return m_pRecordset->BOF;
}

/*************************************************
  Function:       IsEOF
  Description:    判断是否位于记录集的最开始
  Calls:          
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  无
  Input:          无
  Output:         无
  Return:         BOOL值
  Others:         
*************************************************/

BOOL UEADORecordset::IsEOF() const
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	return m_pRecordset->adoEOF;
}

/*************************************************
  Function:       IsEmpty
  Description:    判断记录集是否为空
  Calls:          
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  无
  Input:          无
  Output:         无
  Return:         BOOL值
  Others:         
*************************************************/

BOOL UEADORecordset:: IsEmpty() const
{
	return IsEOF() && IsBOF();
}


/*************************************************
  Function:       MoveFirst
  Description:    移动到记录集的最开始
  Calls:          ADO方法MoveFirst
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  无
  Input:          无
  Output:         无
  Return:         无
  Others:         
*************************************************/

void UEADORecordset::MoveFirst()
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		if (m_pRecordset != NULL) 
		{
			SUCCEEDED(m_pRecordset->MoveFirst());
		}
	}
	catch (_com_error e)
	{
		throw new UEADOException(e);
	} 
}


/*************************************************
  Function:       MovePrevious
  Description:    移动到记录集的最开始
  Calls:          ADO方法MovePrevious 
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  无
  Input:          无
  Output:         无
  Return:         无
  Others:         
*************************************************/

void UEADORecordset::MovePrevious()
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		if (m_pRecordset != NULL) 
		{
			SUCCEEDED(m_pRecordset->MovePrevious());
		}
	}
	catch (_com_error e)
	{
		throw new UEADOException(e);
	} 
}


/*************************************************
  Function:       MoveNext
  Description:    移动到当前记录的下一个位置
  Calls:          ADO方法MoveNext
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  无
  Input:          无
  Output:         无
  Return:         无
  Others:         
*************************************************/

void UEADORecordset::MoveNext()
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		if (m_pRecordset != NULL) 
		{
			SUCCEEDED(m_pRecordset->MoveNext());
		}
	}
	catch (_com_error e)
	{
		throw new UEADOException(e);
	}
}


/*************************************************
  Function:       MoveLast
  Description:    移动到记录集的最后
  Calls:          ADO方法MoveLast
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  无
  Input:          无
  Output:         无
  Return:         无
  Others:         
*************************************************/

void UEADORecordset::MoveLast()
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		if (m_pRecordset != NULL) 
		{
			SUCCEEDED(m_pRecordset->MoveLast());
		}
	}
	catch (_com_error e)
	{
		throw new UEADOException(e);
	} 
}


/*************************************************
  Function:       Update
  Description:    对当前记录集进行批更新
  Calls:          ADO方法Update
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  当前记录集
  Input:          无
  Output:         无
  Return:         无
  Others:         
*************************************************/

BOOL UEADORecordset::Update()
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
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
		throw new UEADOException(e);
	} 
	return FALSE;
}


/*************************************************
  Function:       BatchUpdate
  Description:    对当前记录集进行批更新
  Calls:          ADO方法UpdateBatch
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  当前记录集
  Input:          无
  Output:         无
  Return:         无
  Others:         
*************************************************/

void UEADORecordset::BatchUpdate()
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		m_pRecordset->UpdateBatch(adAffectAll);//默认方式
	}
	catch (_com_error e) 
	{
		throw new UEADOException(e);
	}
}

UEADORecordset::UEADORecordset(_RecordsetPtr m_pRecordset)
{
	this->m_pRecordset = m_pRecordset;
}


/*************************************************
  Function:       SetShort(const StdString &strIndex, SHORT nValue)
  Description:    向当前记录strIndex所代表列写SHORT值
  Calls:          ADO方法PutCollect
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  当前记录集
  Input:          const StdString &strIndex:列名
				  SHORT nValue:待设置的值
  Output:         无
  Return:         无
  Others:         
*************************************************/

void UEADORecordset::SetShort(const StdString &strIndex, SHORT nValue)
{
	UEASSERT( m_pRecordset != NULL, _T ( "很简单，不解释了" ) );
	try
	{
		m_pRecordset->PutCollect(_variant_t(strIndex),_variant_t(nValue));
	}
	catch (_com_error e)
	{
		throw new UEADOException(e);
	}
}


/*************************************************
  Function:       SetLong(const StdString &strIndex, LONG nValue)
  Description:    向当前记录strIndex所代表列写LONG值
  Calls:          ADO方法PutCollect
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  当前记录集
  Input:          const StdString &strIndex:列名
				  LONG nValue:待设置的值
  Output:         无
  Return:         无
  Others:         
*************************************************/

void UEADORecordset::SetLong(const StdString &strIndex, LONG nValue)
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		m_pRecordset->PutCollect(_variant_t(strIndex),_variant_t(nValue));
	}
	catch (_com_error e)
	{
		throw new UEADOException(e);
	}
}


/*************************************************
  Function:       SetDouble(const StdString &strIndex, DOUBLE dbValue)
  Description:    向当前记录strIndex所代表列写Double值
  Calls:          ADO方法PutCollect
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  当前记录集
  Input:          const StdString &strIndex:列名
				  DOUBLE dbValue:待设置的值
  Output:         无
  Return:         无
  Others:         
*************************************************/

void UEADORecordset::SetDouble(const StdString &strIndex, DOUBLE dbValue)
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		m_pRecordset->PutCollect(_variant_t(strIndex),_variant_t(dbValue));
	}
	catch (_com_error e)
	{
		throw new UEADOException(e);
	}
}


/*************************************************
  Function:       SetFloat(const StdString &strIndex, FLOAT fValue)
  Description:    向当前记录strIndex所代表列写FLOAT值
  Calls:          ADO方法PutCollect
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  当前记录集
  Input:          const StdString &strIndex:列名
				  FLOAT fValue:待设置的值
  Output:         无
  Return:         无
  Others:         
*************************************************/

void UEADORecordset::SetFloat(const StdString &strIndex, FLOAT fValue)
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		m_pRecordset->PutCollect(_variant_t(strIndex),_variant_t(fValue));
	}
	catch (_com_error e)
	{
		throw new UEADOException(e);
	}
}


/*************************************************
  Function:       SetString(const StdString &strIndex, const StdString &strValue)
  Description:    向当前记录strIndex所代表列写字符串
  Calls:          ADO方法PutCollect
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  当前记录集
  Input:          const StdString &strIndex:列名
				  const StdString &strValue:待设置的值
  Output:         无
  Return:         无
  Others:         
*************************************************/

void UEADORecordset::SetString(const StdString &strIndex, const StdString &strValue)
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		m_pRecordset->PutCollect(_variant_t(strIndex),_variant_t(strValue));
	}
	catch (_com_error e)
	{
		throw new UEADOException(e);
	}
}


/*************************************************
  Function:       SetBool(const StdString &strIndex, BOOL bValue)
  Description:    向当前记录strIndex所代表列写BOOL值
  Calls:          ADO方法PutCollect
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  当前记录集
  Input:          const StdString &strIndex:列名
				  BOOL bValue:待设置的值
  Output:         无
  Return:         无
  Others:         
*************************************************/

void UEADORecordset::SetBool(const StdString &strIndex, bool bValue)
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		m_pRecordset->PutCollect(_variant_t(strIndex),_variant_t(bValue));
	}
	catch (_com_error e)
	{
		throw new UEADOException(e);
	}
}


/*************************************************
  Function:       NewRecord
  Description:    向当前记录集增加一个空白记录，必须在
				  以后某个时候设置该记录的内容
  Calls:          ADO方法Supports，AddNew
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  当前记录集
  Input:          无
  Output:         无
  Return:         无
  Others:         
*************************************************/

void UEADORecordset::NewRecord()
{
	UEASSERT( m_pRecordset != NULL, _T ( "很简单，不解释了" ) );
	try
	{
		if (m_pRecordset->Supports(adAddNew))
		{
			m_pRecordset->AddNew();//只产生一条新记录，没有填充值。
		}
		else
		{
			AfxMessageBox("不能插入");
		}
	}
	catch (_com_error e)
	{
		throw new UEADOException(e);
	}
}


/*************************************************
  Function:       GetShort(const StdString &strIndex)
  Description:    从当前记录得到一个BOOL值
  Calls:          ADO方法GetCollect
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  无
  Input:          const StdString &strIndex:代表要取的列
  Output:         无
  Return:         Short值
  Others:         
*************************************************/

short UEADORecordset::GetShort(const StdString &strIndex) const
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
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
		throw new UEADOException(e);
	}
	return 0;
}


/*************************************************
  Function:       GetLong(const StdString &strIndex)
  Description:    从当前记录得到一个BOOL值
  Calls:          ADO方法GetCollect
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  无
  Input:          const StdString &strIndex:代表要取的列
  Output:         无
  Return:         Long值
  Others:         
*************************************************/

LONG UEADORecordset::GetLong(const StdString &strIndex) const
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
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
		throw new UEADOException(e);
	}
	return 0;
}


/*************************************************
  Function:       GetDouble(const StdString &strIndex)
  Description:    从当前记录得到一个BOOL值
  Calls:          ADO方法GetCollect
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  无
  Input:          const StdString &strIndex:代表要取的列
  Output:         无
  Return:         Double值
  Others:         
*************************************************/

DOUBLE UEADORecordset::GetDouble(const StdString &strIndex) const
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
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
		throw new UEADOException(e);
	}
	return 0;
}


/*************************************************
  Function:       GetFloat(const StdString &strIndex)
  Description:    从当前记录得到一个BOOL值
  Calls:          ADO方法GetCollect
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  无
  Input:          const StdString &strIndex:代表要取的列
  Output:         无
  Return:         Float值
  Others:         
*************************************************/

FLOAT UEADORecordset::GetFloat(const StdString &strIndex) const
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
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
		throw new UEADOException(e);
	}
	return 0;
}


/*************************************************
  Function:       GetString(const StdString &strIndex)
  Description:    从当前记录得到一个BOOL值
  Calls:          ADO方法GetCollect
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  无
  Input:          const StdString &strIndex:代表要取的列
  Output:         无
  Return:         字符串
  Others:         
*************************************************/

StdString UEADORecordset::GetString(const StdString &strIndex) const
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		_variant_t var;
		StdString strdefault = "";
		var = m_pRecordset->GetCollect(_variant_t(strIndex));
		if (var.vt == VT_NULL)
		{
			return strdefault;
		}
		return (LPCSTR)_bstr_t(var);
	}
	catch (_com_error e)
	{
		throw new UEADOException(e);
	}
	return "";
}


/*************************************************
  Function:       Delete
  Description:    删除当前记录
  Calls:          ADO方法Delete，Update
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  当前记录集
  Input:          无
  Output:         无
  Return:         无
  Others:         
*************************************************/

void UEADORecordset::Delete()
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		m_pRecordset->Delete(adAffectCurrent);//默认。仅删除当前记录。
		m_pRecordset->Update();//更新。要还是不要呢？
	}
	catch (_com_error e)
	{
		throw new UEADOException(e);
	}
}


/*************************************************
  Function:       GetBool(const StdString &strIndex)
  Description:    从当前记录得到一个BOOL值
  Calls:          ADO方法GetCollect
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  无
  Input:          const StdString &strIndex:代表要取的列
  Output:         无
  Return:         BOOL值
  Others:         
*************************************************/

BOOL UEADORecordset::GetBool(const StdString &strIndex) const
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
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
		throw new UEADOException(e);
	}
	return false;
}

/*************************************************
  Function:       Get_variant_t(const StdString &strIndex)
  Description:    从当前记录得到一个_variant_t值
  Calls:          ADO方法GetCollect
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  无
  Input:          const StdString &strIndex:代表要取的列
  Output:         无
  Return:         _variant_t值
  Others:         
*************************************************/

_variant_t UEADORecordset::Get_variant_t(const StdString& strIndex) const
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
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
		throw new UEADOException(e);
	}
	return false;
}

/*************************************************
  Function:       Set_variant_t(const StdString& strIndex,_variant_t vr)
  Description:    向当前记录strIndex所代表列写_variant_t值
  Calls:          ADO方法PutCollect
  Called By:      该类对象
  Table Accessed: 当前记录集
  Table Updated:  当前记录集
  Input:          const StdString &strIndex:列名
				  _variant_t vr:待设置的值
  Output:         无
  Return:         无
  Others:         
*************************************************/

void UEADORecordset::Set_variant_t(const StdString& strIndex,_variant_t vr)
{
	UEASSERT(m_pRecordset != NULL, _T ( "很简单，不解释了" ));
	try
	{
		m_pRecordset->PutCollect(_variant_t(strIndex),vr);
	}
	catch (_com_error e)
	{
		throw new UEADOException(e);
	}
}
