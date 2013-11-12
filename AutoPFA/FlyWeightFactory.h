// FlyWeightFactory.h: interface for the FlyWeightFactory class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：FlyWeightFactory.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLYWEIGHTFACTORY_H__5B326FF3_C4E9_4C53_9AA9_86E1C542C6CF__INCLUDED_)
#define AFX_FLYWEIGHTFACTORY_H__5B326FF3_C4E9_4C53_9AA9_86E1C542C6CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Factory.h"
#include "StrFlyWeight.h"
#include "NumFlyWeight.h"
#include "PtFlyWeight.h"
#include "PipeIDFlyWeight.h"
#include "TableFlyWeigh.h"
#include "ArrayFlyWeight.h"

class FlyWeightFactory:public CFactory<FlyWeight,int>  
{
public:
	static FlyWeightFactory* Instance();
	virtual ~FlyWeightFactory();

	
protected:
	FlyWeightFactory();

private:
	FlyWeightFactory(const FlyWeightFactory &ref);
	FlyWeightFactory& operator=(const FlyWeightFactory &ref);
};

#endif // !defined(AFX_FLYWEIGHTFACTORY_H__5B326FF3_C4E9_4C53_9AA9_86E1C542C6CF__INCLUDED_)
