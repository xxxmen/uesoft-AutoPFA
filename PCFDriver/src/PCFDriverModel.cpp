// PCFDriverModel.cpp: implementation of the PCFDriverModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFDriverModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const CString PCFDriverModel::m_strHeaderSign   = _T("ISOGEN-FILES");
const CString PCFDriverModel::m_strPipelineSign = _T("PIPELINE-REFERENCE");
const CString PCFDriverModel::m_strMaterialSign = _T("MATERIALS");
const CString PCFDriverModel::m_strFileEndSign  = _T("PCF-END");

PCFDriverModel::PCFDriverModel()
{

}

PCFDriverModel::~PCFDriverModel()
{

}

BOOL PCFDriverModel::Read(CStdioFile &file)
{
	DWORD dwFileLength = file.GetLength();
	char* pMemory = (char*)malloc(dwFileLength*sizeof(char));
	ReadFile(file,pMemory);
	ParseStringToWord(pMemory,dwFileLength) ;
	free(pMemory);
	InitModel();
	return TRUE;
}

void PCFDriverModel::ReadFile(CStdioFile &File, char *pMemory)
{
	ASSERT(pMemory != NULL) ;
	DWORD dwLeftFileLength = File.GetLength() ;
	DWORD dwOnceReadLength = 2048;
	while(dwLeftFileLength>0)
	{
		if(dwLeftFileLength<dwOnceReadLength)
			dwOnceReadLength = dwLeftFileLength;
		File.Read(pMemory,dwOnceReadLength);
		pMemory += dwOnceReadLength ;
		dwLeftFileLength -= dwOnceReadLength ;
	}
}

void PCFDriverModel::ParseStringToWord(const char *pMemory, DWORD dwFileLength)
{
	CString strWord ;
	for(DWORD i=0; i<dwFileLength;++i,++pMemory)
	{
		if ((*pMemory != 32)&&(*pMemory != 13)&&(*pMemory != 10))
		{
			strWord += *pMemory;
		}
		else if(*pMemory == 32||*pMemory==13||*pMemory == 10)
		{
			if(!strWord.IsEmpty())
			{
				m_strSetForWord.Add( strWord );
				strWord.Empty() ;
			}
		}
	}

	if(!strWord.IsEmpty())
	{
		m_strSetForWord.Add( strWord );
	}
	m_strSetForWord.Add(m_strFileEndSign) ;
}

BOOL PCFDriverModel::Decompose(const CString strSign,CStringArray& strSet)
{
	strSet.RemoveAll();

	int nStart=0;
	int nEnd = 0;
	if( !FindRange(strSign,nStart,nEnd))
		return FALSE;

	GetSubStringSet(nStart,nEnd,strSet) ;//得到一个分支的信息，同时去除读出的信息
	return TRUE ;
}
BOOL PCFDriverModel::FindRange(const CString &strStart , int &nStart, int &nEnd)
{
	BOOL bFindStart = FALSE ;
	BOOL bFindEnd   = FALSE ;
	for( int i =0 ; i < m_strSetForWord.GetSize() ; ++i)
	{
		CString strTemp = m_strSetForWord[i] ;
		if( !bFindStart )
		{
			if( m_strSetForWord[i] == strStart )
			{
				bFindStart = !bFindStart ;
				nStart = i ;
			}
		}
		else
		{
			if( IsPCFKeyWord( m_strSetForWord[i] ))
			{
				bFindEnd = !bFindEnd ;
				nEnd = i ;
				break;
			}
		}
	}
	return bFindStart && bFindEnd;
}
BOOL PCFDriverModel::IsPCFKeyWord( const CString& strKeyWord ) 
{
	return (m_strHeaderSign   == strKeyWord)
		|| (m_strPipelineSign == strKeyWord) 
		|| (m_strMaterialSign == strKeyWord) 
		|| (m_strFileEndSign  == strKeyWord);
}
void PCFDriverModel::GetSubStringSet(int nStart,int nEnd,CStringArray& strSet)
{
	int i = nStart ;
	do
	{
		strSet.Add(m_strSetForWord[i]) ;
	}
	while(++i < nEnd) ;
	m_strSetForWord.RemoveAt(nStart,nEnd-nStart) ;
}

void PCFDriverModel::InitUnitInfo()
{
	CStringArray strDecompose;
	Decompose(m_strHeaderSign,strDecompose);
	m_unitInfo.Init(strDecompose);
}

void PCFDriverModel::InitModel()
{
	InitUnitInfo();
	InitPipeline();
}

void PCFDriverModel::InitPipeline()
{
	CStringArray strDecompose;
	while(Decompose(m_strPipelineSign,strDecompose))
	{
		m_ComponentMgr.Init(strDecompose);
	}
}

PCFPipesMgr& PCFDriverModel::GetPipeMgr()
{
	return m_ComponentMgr.GetPipeMgr();
}

PCFJunsMgr& PCFDriverModel::GetJunMgr()
{
	return m_ComponentMgr.GetJunMgr();
}