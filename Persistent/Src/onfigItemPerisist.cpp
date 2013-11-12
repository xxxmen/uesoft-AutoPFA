// onfigItemPerisist.cpp: implementation of the ConfigItemPerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "onfigItemPerisist.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ConfigItemPerisist::ConfigItemPerisist()
{

}

ConfigItemPerisist::~ConfigItemPerisist()
{
	
}

ConfigItemPerisist::ConfigItemPerisist(const ConfigItemPerisist &ref)
{
	ASSERT(FALSE);
}

ConfigItemPerisist& ConfigItemPerisist::operator=(const ConfigItemPerisist &ref)
{
	ASSERT(FALSE);
	//判断自赋值
	if(this == &ref)
		return *this;
    //调用基类赋值
	
	//释放堆内存
	//重新分配堆内存
	//赋值
   
	return *this;
 }