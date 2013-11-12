// PCFSurge.cpp: implementation of the PCFSurge class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFSurge.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFSurge::PCFSurge()
{
	m_strName = _T("SURGE");
	m_nTypeID = 24;
	m_bPFAJun = TRUE;

	CString strData = _T( "meters,10,meters,2,mm2,3,atm,-1,1,2,3,mm2,-1,1,2,cm,3,cm2,4,meters,2,cm,0,0,0,0,3,meters,1,1,0,3,atm" );
	strData = m_EleUnit.InitData(strData);
	strData = m_SurgeHeight.InitData(strData);
	strData = m_ConstArea.InitData(strData);
	strData = m_SurfacePress.InitData(strData);
	strData = m_Orifice.InitData(strData);
	strData = m_ShortPipe.InitData(strData);
	strData = m_OneWay.InitData(strData);
	strData = m_Vessel.InitData(strData);
	strData = m_Variable.InitData(strData);
	strData = m_InitSurfaceH.InitData(strData);
	strData = m_CheckValve.InitData(strData);
}

PCFSurge::~PCFSurge()
{

}

PCFJun* PCFSurge::Creator()
{
	PCFSurge *pData = new PCFSurge;
	return pData;
}

/*------------------------------------------*/
CString PCFSurge::DistanceUnit()
{
	return m_EleUnit.GetData();
}
void PCFSurge::DistanceUnit(CString strValue)
{
	m_EleUnit.SetData(strValue);
}
/*------------------------------------------*/
StrArray<2> PCFSurge::SurgeHeight()
{
	return m_SurgeHeight.GetArray();
}
void PCFSurge::SurgeHeight(const StrArray<2>& strValue)
{
	m_SurgeHeight.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<2> PCFSurge::ConstArea()
{
	return m_ConstArea.GetArray();
}
void PCFSurge::ConstArea(const StrArray<2>& strValue)
{
	m_ConstArea.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<2> PCFSurge::SurfacePress()
{
	return m_SurfacePress.GetArray();
}
void PCFSurge::SurfacePress(const StrArray<2>& strValue)
{
	m_SurfacePress.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<5> PCFSurge::Orifice()
{
	return m_Orifice.GetArray();
}
void PCFSurge::Orifice(const StrArray<5>& strValue)
{
	m_Orifice.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<10> PCFSurge::ShortPipe()
{
	return m_ShortPipe.GetArray();
}
void PCFSurge::ShortPipe(const StrArray<10>& strValue)
{
	m_ShortPipe.SetArray(strValue);
}
/*------------------------------------------*/
CString PCFSurge::OneWay()
{
	return m_OneWay.GetData();
}
void PCFSurge::OneWay(CString strValue)
{
	m_OneWay.SetData(strValue);
}
/*------------------------------------------*/
StrArray<4> PCFSurge::Vessel()
{
	return m_Vessel.GetArray();
}
void PCFSurge::Vessel(const StrArray<4>& strValue)
{
	m_Vessel.SetArray(strValue);
}

/*------------------------------------------*/
CString PCFSurge::Variable()
{
	return m_Variable.GetData();
}
void PCFSurge::Variable(CString strValue)
{
	m_Variable.SetData(strValue);
}

/*------------------------------------------*/
StrArray<3> PCFSurge::InitSurfaceH()
{
	return m_InitSurfaceH.GetArray();
}
void PCFSurge::InitSurfaceH(const StrArray<3>& strValue)
{
	m_InitSurfaceH.SetArray(strValue);
}
/*------------------------------------------*/
StrArray<5> PCFSurge::Check()
{
	return m_CheckValve.GetArray();
}
void PCFSurge::Check(const StrArray<5>& strValue)
{
	m_CheckValve.SetArray(strValue);
}

void PCFSurge::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
		SetSEFromBasePt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}