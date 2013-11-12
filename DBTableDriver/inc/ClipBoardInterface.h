// ClipBoardInterface.h: interface for the CClipBoardInterface class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIPBOARDINTERFACE_H__64B592CD_4BAF_4BBE_AEE7_DB327B977C67__INCLUDED_)
#define AFX_CLIPBOARDINTERFACE_H__64B592CD_4BAF_4BBE_AEE7_DB327B977C67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ClipboardManage.h"

class AFX_EXT_CLASS CClipBoardInterface  
{
public:
	CClipBoardInterface& Instance();
	void SaveToClipboard(CalcTable<2> &DBTable);
	void CopyFromClipBoard(CalcTable<2> &DBTable);
	CClipBoardInterface();
	virtual ~CClipBoardInterface();
private:
	CClipboardManage m_ClipBoardManager;

};

#endif // !defined(AFX_CLIPBOARDINTERFACE_H__64B592CD_4BAF_4BBE_AEE7_DB327B977C67__INCLUDED_)
