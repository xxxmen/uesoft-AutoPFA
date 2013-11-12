// FuildDataMgr.cpp: implementation of the FuildDataMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FuildDataMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FuildDataMgr::FuildDataMgr()
{

}

FuildDataMgr::~FuildDataMgr()
{
	POSITION pos = m_fuildMap.GetStartPosition();
	FuildDatabase* pTemp = NULL;
	int nKey;
	while(pos)
	{
		m_fuildMap.GetNextAssoc(pos,nKey,pTemp);
		delete pTemp;
	}
}

void FuildDataMgr::Init(CStdioFile &File)
{
	CString strTemp;
	FuildDatabase *pFuild = NULL;
	while(File.ReadString(strTemp))
	{
		if(!strTemp.IsEmpty())
		{
			pFuild = Creator();
			pFuild->Init(strTemp);
		}
	}
}

FuildDatabase* FuildDataMgr::Creator()
{
	FuildDatabase *pFuild = FuildDatabase::Creator();
	int nKey = CreatKey<FuildDatabase>(m_fuildMap);
	pFuild->Key(nKey);
	m_fuildMap.SetAt(nKey,pFuild);
	return pFuild;
}

Iterator<FuildDatabase>* FuildDataMgr::CreateIt()
{
	return new MapIterator<FuildDatabase>(&m_fuildMap);
}

FuildDatabase* FuildDataMgr::LookUp(int nKey)
{
	return LookMap<FuildDatabase>(m_fuildMap,nKey);
}
