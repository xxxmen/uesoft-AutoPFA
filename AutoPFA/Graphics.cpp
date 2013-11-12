// Graphics.cpp: implementation of the Graphics class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "Graphics.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Graphics::Graphics()
{

}

Graphics::~Graphics()
{

}

void Graphics::DrawText(CDC *pDc, CString strText, CPoint point)
{
	pDc->TextOut(point.x,point.y,strText);
}
