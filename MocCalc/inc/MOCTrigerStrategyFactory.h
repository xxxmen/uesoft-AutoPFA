// MOCTrigerStrategyFactory.h: interface for the MOCTrigerStrategyFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERSTRATEGYFACTORY_H__17E64F5F_F3AC_4E73_B181_A8C92163654E__INCLUDED_)
#define AFX_MOCTRIGERSTRATEGYFACTORY_H__17E64F5F_F3AC_4E73_B181_A8C92163654E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Factory.h"
class MOCTrigerStrategy;

class MOCTrigerStrategyFactory:public CFactory<MOCTrigerStrategy,int>   
{
public:
	static MOCTrigerStrategyFactory* Instance();
	virtual ~MOCTrigerStrategyFactory();
	
protected:
	MOCTrigerStrategyFactory();
	
private:
	MOCTrigerStrategyFactory(const MOCTrigerStrategyFactory &ref);
	MOCTrigerStrategyFactory& operator=(const MOCTrigerStrategyFactory &ref);
};
/*
   0,"绝对时间"
   1,"管道滞止压力"
   2,"节点滞止压力"
   3,"管道质量流量"
   4,"管道体积流量"
   5,"管道水头坡度线"
   6,"管道能量坡度线"
   7,"泵转速"
   8,"止回阀状态"
   9,"安全阀状态"
   10,"控制阀状态"
   11,"节点静止压力差"
   12,"节点滞止压力差"
   13,"节点坡度线差"
   14,"节点能量坡度线差"
   15,"管道静止压力差"
   16,"管道滞止压力差"
   17,"管道水头坡度线差"
   18,"管道能量坡度线差"
   19,"喷嘴管口流量"
   20,"调压塔坡度线"
   21,"调压塔流体高度"
   22,"管道流速"
   23,"相对时间"
*/
#endif // !defined(AFX_MOCTRIGERSTRATEGYFACTORY_H__17E64F5F_F3AC_4E73_B181_A8C92163654E__INCLUDED_)
