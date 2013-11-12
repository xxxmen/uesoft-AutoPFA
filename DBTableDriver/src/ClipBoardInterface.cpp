// ClipBoardInterface.cpp: implementation of the CClipBoardInterface class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClipBoardInterface.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClipBoardInterface::CClipBoardInterface()
{

}

CClipBoardInterface::~CClipBoardInterface()
{

}

void CClipBoardInterface::CopyFromClipBoard(CalcTable<2> &DBTable)
{
	m_ClipBoardManager.CopyFromClipBoard(DBTable);
}

void CClipBoardInterface::SaveToClipboard(CalcTable<2> &DBTable)
{
	m_ClipBoardManager.SaveToClipboard(DBTable);
}

CClipBoardInterface& CClipBoardInterface::Instance()
{
	static CClipBoardInterface Interface;
	return Interface;
}
