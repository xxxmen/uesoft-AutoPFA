/*************************************************
  Copyright (C), 1988-2006, UESOFT Co., Ltd.
  File name:      UERecordset.h
  Author:         贺灏
  Version:        1.0
  Date:           2006.8.22
  Description:    UERecordset是一个抽象基类，代表一个
				  从数据库文件中读出的记录集
				  （不管你是用什么方法ODBC,ADO,DAO都可以）
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

// UERecordset.h: interface for the UERecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UERECORDSET_H__09C0D072_B717_4F35_9298_704C992A6CC2__INCLUDED_)
#define AFX_UERECORDSET_H__09C0D072_B717_4F35_9298_704C992A6CC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//#include <Afx.h>
#include "SmartPointer.h"
#include <COMUTIL.H>
#include "DataBaseDriverHeader.h"

class DataBaseDriver_Exp   UERecordset  
{
public:

	UERecordset();
	virtual ~UERecordset();
public:
	//删除当前位置记录

	virtual void Delete() = 0;

	virtual void Close() = 0;
	//是否在记录集的最开始位置

	virtual BOOL IsBOF() const = 0;
	// 记录集是否为空
	virtual BOOL IsEmpty() const = 0;

	//是否在记录集的末尾
	virtual BOOL IsEOF() const = 0;
	//得到该记录集中记录的个数

	virtual INT GetRecordCount() const= 0;
	virtual void MoveNext() = 0;
	virtual void MovePrevious() = 0;
	virtual void MoveLast() = 0;
	virtual void MoveFirst() = 0;
	virtual void SetShort(const StdString& strIndex, SHORT nValue) = 0;
	virtual void SetLong(const StdString& strIndex, LONG nValue) = 0;
	virtual void SetDouble(const StdString& strIndex, DOUBLE dbValue) = 0;
	virtual void SetFloat(const StdString& strIndex, FLOAT fValue) = 0;
	virtual void SetString(const StdString& strIndex, const StdString& strValue) = 0;
	virtual void Set_variant_t(const StdString& strIndex,_variant_t vr) = 0;
	virtual void SetBool(const StdString& strIndex, bool bValue) = 0;
	//ADO中有UpdateBatch方法对应此功能。

	virtual void BatchUpdate() = 0;
	virtual BOOL Update() = 0;
	
	virtual void NewRecord() = 0;
	virtual BOOL GetBool(const StdString& strIndex) const= 0;
	virtual short GetShort(const StdString& strIndex) const= 0;
	virtual LONG GetLong(const StdString& strIndex) const= 0;
	virtual DOUBLE GetDouble(const StdString& strIndex) const= 0;
	virtual FLOAT GetFloat(const StdString& strIndex) const= 0;
	virtual StdString GetString(const StdString& strIndex) const= 0;
	virtual _variant_t Get_variant_t(const StdString& strIndex) const = 0;

};

typedef UeSmartPtr<UERecordset> UERecordsetPtr;

#endif // !defined(AFX_UERECORDSET_H__09C0D072_B717_4F35_9298_704C992A6CC2__INCLUDED_)
