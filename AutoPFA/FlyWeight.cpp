// FlyWeight.cpp: implementation of the FlyWeight class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "FlyWeight.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FlyWeight::FlyWeight()
{

}

FlyWeight::FlyWeight(const FlyWeight &ref)
{
	
}

FlyWeight& FlyWeight::operator=(const FlyWeight &ref)
{
	return *this;
}

FlyWeight::~FlyWeight()
{

}

FlyWeight* FlyWeight::Clone()
{
	FlyWeight* pClone = DoClone();
	assert(typeid(*this)==typeid(*pClone));
	return pClone;
}


