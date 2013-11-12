// Exception.h: interface for the Exception class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXCEPTION_H__CE954799_A966_4CA4_8E5B_1F9FC32A159F__INCLUDED_)
#define AFX_EXCEPTION_H__CE954799_A966_4CA4_8E5B_1F9FC32A159F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Exception  
{
public:
	Exception();
	virtual ~Exception(); 
public:

	virtual void ReportError() = 0;
	//这个函数干什么用的？
	virtual void Delete() = 0;
	virtual CString Description() = 0;

};

#endif // !defined(AFX_EXCEPTION_H__CE954799_A966_4CA4_8E5B_1F9FC32A159F__INCLUDED_)
