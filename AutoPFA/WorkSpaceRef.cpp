// WorkSpaceRef.cpp: implementation of the WorkSpaceRef class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "WorkSpaceRef.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WorkSpaceRef::WorkSpaceRef()
{
	m_Lf.lfHeight = 20;
	m_Lf.lfWidth = 0;
	m_Lf.lfEscapement = 0;
	m_Lf.lfOrientation = 0;
	m_Lf.lfWeight = FW_NORMAL;
	m_Lf.lfItalic = FALSE;
	m_Lf.lfUnderline = FALSE;
	m_Lf.lfStrikeOut = FALSE;
	m_Lf.lfCharSet = ANSI_CHARSET;
	m_Lf.lfOutPrecision = OUT_STROKE_PRECIS;
	m_Lf.lfClipPrecision = CLIP_STROKE_PRECIS;
	m_Lf.lfQuality = DRAFT_QUALITY;
	m_Lf.lfPitchAndFamily = VARIABLE_PITCH|FF_MODERN;
	
	_tcscpy(m_Lf.lfFaceName,_T("Arial") );
	m_JunCloseColor    = RGB(255,0,0);
	m_JunTextColor     = RGB(0,0,0);
	m_PipeTextColor    = RGB(0,0,0);
    m_UndefineTextColor= RGB(255,0,0);
    m_PipeColor        = RGB(127,127,127);
    m_SelectItemColor  = RGB(255,0,0);
    m_bkColor          = RGB(255,255,255);

	m_nJunSize = 100;
	m_nPipeThick = 3;
	m_bTrans = TRUE;
}

WorkSpaceRef::~WorkSpaceRef()
{

}
