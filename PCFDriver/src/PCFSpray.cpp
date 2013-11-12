// PCFSpray.cpp: implementation of the PCFSpray class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFSpray.h"
#include "PCFJun.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFSpray::PCFSpray()
{	
	m_strName = _T("SPRAY");
	m_nTypeID = 16;
	m_bPFAJun = TRUE;
	CString strData = _T( "0,0,0,None,0,None,-1,1,5,0,0,0,0,0,0,None,0,1,1,1,None,1,0,0,0,0,-1,-1,0,None,-1,-1,-1,-1,-1,-1,0,None,-1,-1,-1,-1,None,1,0,seconds,None,None,1,0,seconds,None" );
	strData = m_Type.InitData(strData);
	strData = m_Curve.InitData(strData);
	strData = m_SprayArea.InitData(strData);
	strData = m_KOrCv.InitData(strData);
	strData = m_ExitPress.InitData(strData);
}

PCFSpray::~PCFSpray()
{

}

PCFJun* PCFSpray::Creator()
{
	PCFSpray *pData = new PCFSpray;
	return pData;
}

/*------------------------------------------*/
CString PCFSpray::Type()
{
	return m_Type.GetData();
}
void PCFSpray::Type(CString strValue)
{
	m_Type.SetData(strValue);
}
/*------------------------------------------*/
StrArray<13> PCFSpray::Curve()
{
	return m_Curve.GetArray();
}
void PCFSpray::Curve(const StrArray<13>& strValue)
{
	m_Curve.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<3> PCFSpray::ExitArea()
{
	return m_SprayArea.GetArray();
}
void PCFSpray::ExitArea(const StrArray<3>& strValue)
{
	m_SprayArea.SetArray(strValue);
}

/*------------------------------------------*/
CString PCFSpray::KOrCv()
{
	return m_KOrCv.GetData();
}
void PCFSpray::KOrCv(CString strValue)
{
	m_KOrCv.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> PCFSpray::ExitPress()
{
	return m_ExitPress.GetArray();
}
void PCFSpray::ExitPress(const StrArray<3>& strValue)
{
	m_ExitPress.SetArray(strValue);
}

void PCFSpray::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
		SetSEFromBasePt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}