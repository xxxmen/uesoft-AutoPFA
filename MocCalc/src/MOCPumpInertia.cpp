// MOCPumpInertia.cpp: implementation of the MOCPumpInertia class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCPumpInertia.h"
#include "MOCFluid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCPumpInertia::MOCPumpInertia()
{
	m_dRotateInertia = 0;		
	m_dSpeed = 0;		
}

MOCPumpInertia::~MOCPumpInertia()
{

}

double MOCPumpInertia::RotateInertia()
{
	return m_dRotateInertia;
}
