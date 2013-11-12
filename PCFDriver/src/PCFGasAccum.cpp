// PCFGasAccum.cpp: implementation of the PCFGasAccum class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFGasAccum.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFGasAccum::PCFGasAccum()
{
	m_strName = _T("GASACCUM");
	m_nTypeID = 22;
	m_bPFAJun = TRUE;
	CString strData = _T( "-1,0,None,0,-1,-1,0,None,0,-1,0,None,0,None,0,,0,None,0,0,0,None,-1,-1,0,0,None" );
	strData = m_Polytropic.InitData(strData);
	strData = m_InitVolume.InitData(strData);
	strData = m_Orifice.InitData(strData);
	strData = m_ShortPipe.InitData(strData);
	strData = m_InitPress.InitData(strData);
	strData = m_MaxVolume.InitData(strData);
    strData = m_MinVolume.InitData(strData);
	strData = m_GasVolume.InitData(strData);
}

PCFGasAccum::~PCFGasAccum()
{

}

void PCFGasAccum::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
		SetSEFromBasePt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}

PCFJun* PCFGasAccum::Creator()
{
	PCFGasAccum *pData = new PCFGasAccum;
	return pData;
}


/*------------------------------------------*/
CString PCFGasAccum::Polytropic()
{
	return m_Polytropic.GetData();
}
void PCFGasAccum::Polytropic(CString strValue)
{
	m_Polytropic.SetData(strValue);
}
/*------------------------------------------*/
StrArray<2> PCFGasAccum::InitVolume()
{
	return m_InitVolume.GetArray();
}
void PCFGasAccum::InitVolume(const StrArray<2>& strValue)
{
	m_InitVolume.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<5> PCFGasAccum::Orifice()
{
	return m_Orifice.GetArray();
}
void PCFGasAccum::Orifice(const StrArray<5>& strValue)
{
	m_Orifice.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<10> PCFGasAccum::ShortPipe()
{
	return m_ShortPipe.GetArray();
}
void PCFGasAccum::ShortPipe(const StrArray<10>& strValue)
{
	m_ShortPipe.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<4> PCFGasAccum::InitPress()
{
	return m_InitPress.GetArray();
}
void PCFGasAccum::InitPress(const StrArray<4>& strValue)
{
	m_InitPress.SetArray(strValue);
}
/*------------------------------------------*/
CString PCFGasAccum::MaxVolume()
{
	return m_MaxVolume.GetData();
}
void PCFGasAccum::MaxVolume(CString strValue)
{
	m_MaxVolume.SetData(strValue);
}
/*------------------------------------------*/
CString PCFGasAccum::MinVolume()
{
	return m_MinVolume.GetData();
}
void PCFGasAccum::MinVolume(CString strValue)
{
	m_MinVolume.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> PCFGasAccum::GasVolume()
{
	return m_GasVolume.GetArray();
}
void PCFGasAccum::GasVolume(const StrArray<3>& strValue)
{
	m_GasVolume.SetArray(strValue);
}