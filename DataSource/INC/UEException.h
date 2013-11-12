/*************************************************
  Copyright (C), 1988-2006, UESOFT Co., Ltd.
  File name:      UEException.h
  Author:         贺灏
  Version:        1.0
  Date:           2006.8.22
  Description:    UEException是一个抽象基类，代表一个异常，
				  它是所有异常类的基类。
  Others:         
  Function List:  
    1. Delete:删除被抛出的异常（它自己）
	2. Description:获取异常的描述信息
	3. ReportError:向用户报告错误，以警告对话框的形式
*************************************************/

// UEException.h: interface for the UEException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UEEXCEPTION_H__D8F112C6_C529_43C4_9BCD_89638140AC07__INCLUDED_)
#define AFX_UEEXCEPTION_H__D8F112C6_C529_43C4_9BCD_89638140AC07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class _declspec ( dllexport )   UEException  
{
public:

	UEException();
	virtual ~UEException();
public:

	virtual void ReportError() = 0;
	//这个函数干什么用的？
	virtual void Delete() = 0;
	virtual CString Description() = 0;
	

};

#endif // !defined(AFX_UEEXCEPTION_H__D8F112C6_C529_43C4_9BCD_89638140AC07__INCLUDED_)
