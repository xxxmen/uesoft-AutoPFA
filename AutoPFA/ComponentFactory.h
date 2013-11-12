// ComponentFactory.h: interface for the ComponentFactory class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：ComponentFactory.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OMPONENTFACTORY_H__E53216E1_F026_4CD7_AB1B_D80F02063E66__INCLUDED_)
#define AFX_OMPONENTFACTORY_H__E53216E1_F026_4CD7_AB1B_D80F02063E66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Factory.h"
#include "Pipe.h"
#include "AreaChange.h"
#include "AssignedFlow.h"
#include "AssignedPressure.h"
#include "CheckValve.h"
#include "Branch.h"
#include "ControlValve.h"
#include "DeadEnd.h"
#include "ReliefValve.h"
#include "Reservoir.h"
#include "SprayDischarge.h"
#include "Surge.h"
#include "Pump.h"
#include "GasAccumulator.h"
#include "General.h"
#include "LiquidAccumulator.h"
#include "TeeWye.h"
#include "VacuumBreaker.h"
#include "Valve.h"
#include "Bend.h"

class Component;
class ComponentFactory:public CFactory<Component,int>  
{
public:
	static ComponentFactory* Instance();
	virtual ~ComponentFactory();
	
protected:
	ComponentFactory();
	
private:
	ComponentFactory(const ComponentFactory &ref);
	ComponentFactory& operator=(const ComponentFactory &ref);

};

#endif // !defined(AFX_OMPONENTFACTORY_H__E53216E1_F026_4CD7_AB1B_D80F02063E66__INCLUDED_)
