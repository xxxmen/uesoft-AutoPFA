// MOCTransOutControl.cpp: implementation of the MOCTransOutControl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTransOutControl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTransOutControl::MOCTransOutControl()
{
	m_bStation = FALSE;
}

MOCTransOutControl::~MOCTransOutControl()
{

}

BOOL MOCTransOutControl::IsOutStation()
{
	return m_bStation;
}
