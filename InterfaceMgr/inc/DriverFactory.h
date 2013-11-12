// DriverFactory.h: interface for the DriverFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRIVERFACTORY_H__2C8E7DBB_7E74_4898_987F_5956265CC22A__INCLUDED_)
#define AFX_DRIVERFACTORY_H__2C8E7DBB_7E74_4898_987F_5956265CC22A__INCLUDED_
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：DriverFactory.h
  摘要： 文件驱动工厂，根据文件扩展名创建不同的文件驱动   
  author  : LSP          
*/
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Factory.h"
class Driver;

class DriverFactory :public CFactory<Driver,CString>   
{
public:
	static DriverFactory* Instance();
	virtual ~DriverFactory();
	
protected:
	DriverFactory();
	
private:
	DriverFactory(const DriverFactory &ref);
	DriverFactory& operator=(const DriverFactory &ref);
};

#endif // !defined(AFX_DRIVERFACTORY_H__2C8E7DBB_7E74_4898_987F_5956265CC22A__INCLUDED_)
