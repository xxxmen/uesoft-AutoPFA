/*************************************************
  Copyright (C), 1988-2006, UESOFT Co., Ltd.
  File name:      UEADORecordset.h
  Author:         贺灏
  Version:        1.0
  Date:           2006.8.22
  Description:    UEADORecordset代表一个用ADO方法
				  从数据库文件中读出的记录集。
  Others:         
  Function List:  
    1. BatchUpdate:对记录进行批更新。
	2. Close:关闭记录集
	3. Delete:删除当前记录
	4. GetBool:从当前记录中读取一个BOOL值
	5. GetDouble:从当前记录中读取一个Double值
	6. GetFloat:从当前记录中读取一个Float值
	7. GetLong:从当前记录中读取一个Long值
	8. GetRecordCount:获取当前记录集的记录数
	9. GetShort:从当前记录中读取一个Short值
	10.GetString:从当前记录中读取一个字符串值
	11.Get_variant_t从当前记录中读取一个变体值
	12.IsBOF:判断是否位于记录集的最开始
	13.IsEOF:判断是否位于记录集的最末尾
	14.IsEmpty:判断记录集是否为空
	15.MoveFirst:移动到记录集的最开始位置
	16.MoveLast:移动到记录集的最后位置
	17.MoveNext:移动到记录集中当前记录的下一个位置
	18.MovePrevious:移动到记录集中当前记录的前一个位置
	19.NewRecord:向记录集中增加一条内容为空的新记录
	20.SetBool:向记录集当前位置写一个BOOL值
	21.SetDouble:向记录集当前位置写一个Double值
	22.SetFloat:向记录集当前位置写一个Float值
	23.SetLong:向记录集当前位置写一个Long值
	24.SetShort:向记录集当前位置写一个short值
	25.SetString:向记录集当前位置写一个字符串
	26.Set_variant_t:向记录集当前位置写一个变体值
	27.Update:更新当前记录
*************************************************/

// UEADORecordset.h: interface for the UEADORecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UEADORECORDSET_H__2CE0052C_1060_423F_9513_7FF5AC552648__INCLUDED_)
#define AFX_UEADORECORDSET_H__2CE0052C_1060_423F_9513_7FF5AC552648__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UEADO.h"
#include "UERecordset.h"
#include "DataBaseDriverHeader.h"

class DataBaseDriver_Exp  UEADORecordset : public UERecordset  
{
public:

	UEADORecordset(_RecordsetPtr m_pRecordset);
	UEADORecordset();
	virtual ~UEADORecordset();
public:
	void Delete();

	BOOL GetBool(const StdString& strIndex) const;
	StdString GetString(const StdString& strIndex) const;
	FLOAT GetFloat(const StdString& strIndex) const;
	DOUBLE GetDouble(const StdString& strIndex) const;
	LONG GetLong(const StdString& strIndex) const;
	short GetShort(const StdString& strIndex) const;
	_variant_t Get_variant_t(const StdString& strIndex) const;

	void NewRecord();
	
	void SetBool(const StdString& strIndex, bool bValue);
	void SetString(const StdString& strIndex, const StdString& strValue);
	void SetFloat(const StdString& strIndex, FLOAT fValue);
	void SetDouble(const StdString& strIndex, DOUBLE dbValue);
	void SetLong(const StdString& strIndex, LONG nValue);
	void SetShort(const StdString& strIndex, SHORT nValue);
	void Set_variant_t(const StdString& strIndex,_variant_t vr);
	
	void BatchUpdate();
	BOOL Update();

	void MovePrevious();
	void MoveLast();
	void MoveNext();
	void MoveFirst();

	BOOL IsEOF() const;
	BOOL IsBOF() const;
	BOOL IsEmpty() const;
	void Close();
	
	INT GetRecordCount() const;

private:
	_RecordsetPtr m_pRecordset;//包装了_Recordset的智能指针
};

#endif // !defined(AFX_UEADORECORDSET_H__2CE0052C_1060_423F_9513_7FF5AC552648__INCLUDED_)
