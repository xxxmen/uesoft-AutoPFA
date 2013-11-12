// CalcSurge.cpp: implementation of the CalcSurge class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcSurge.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcSurge::CalcSurge()
{
	m_dSurfacePress = 0;		
	m_dSurgeHeight = 0;			
	m_dConstArea = 0;					
	m_bOneWay = 0;				
	m_dCheckCv = 0;						
	m_nPosition = 0;					
	m_nReOpenPressType = 0;		
	m_dReOpenPress = 0;				
	m_bSelVessel = 0;					
	m_dVesselHeight = 0;				
	m_dPolytropic = 0;				
	m_bSelSurfaceH = 0;			
	m_dInitSurfaceH = 0;
}

CalcSurge::~CalcSurge()
{

}

CalcJun* CalcSurge::Creator()
{
	CalcSurge *pData = new CalcSurge;
	return pData;
}

ostream& CalcSurge::Write(ostream &CalcOut)
{
	CalcOut<<m_nKey<<s_Separator
		   <<m_nTypeID<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<m_PipeInfo<<s_Separator
		   <<m_nSpecialMark<<s_Separator
		   <<m_nInitGuessType<<s_Separator
		   <<m_dInitGuess<<s_Separator
		   <<m_dSurfacePress<<s_Separator
		   <<m_dSurgeHeight<<s_Separator
		   <<m_dConstArea<<s_Separator
		   <<m_AreaTable<<s_Separator
		   <<m_Orifice<<s_Separator
		   <<m_ShortPipe<<s_Separator
		   <<abs(m_bOneWay)<<s_Separator
		   <<m_dCheckCv<<s_Separator
		   <<m_nPosition<<s_Separator
		   <<m_nReOpenPressType<<s_Separator
		   <<m_dReOpenPress<<s_Separator
		   <<abs(m_bSelVessel)<<s_Separator
		   <<m_dVesselHeight<<s_Separator
		   <<m_dPolytropic<<s_Separator
		   <<m_bSelSurfaceH<<s_Separator
		   <<m_dInitSurfaceH<<s_Separator
		   //<<m_TranData
		   <<endl;
	return CalcOut;
}

void CalcSurge::PipeInfo(const ListImp<StrArray<4> >& ref)
{
	m_PipeInfo.SetData(ref);
}

void CalcSurge::AreaTable(const ListImp<StrArray<2> >& ref)
{
	m_AreaTable.SetData(ref);
}

/*------------------------------------------------*/
void CalcSurge::SurfacePress(double dValue)
{
	m_dSurfacePress = dValue;
}
/*------------------------------------------------*/
void CalcSurge::SurgeHeight(double dValue)
{
	m_dSurgeHeight = dValue;
}
/*------------------------------------------------*/
void CalcSurge::ConstArea(double dValue)
{
	m_dConstArea = dValue;
}
/*------------------------------------------------*/
void CalcSurge::OneWay(int nValue)
{
	m_bOneWay = nValue;
}
/*------------------------------------------------*/
void CalcSurge::CheckCv(double dValue)
{
	m_dCheckCv = dValue;
}
/*------------------------------------------------*/
void CalcSurge::Position(int nValue)
{
	m_nPosition = nValue;
}
/*------------------------------------------------*/
void CalcSurge::ReOpenPressType(int nValue)
{
	m_nReOpenPressType = nValue;
}
/*------------------------------------------------*/
void CalcSurge::ReOpenPress(double dValue)
{
	m_dReOpenPress = dValue;
}
/*------------------------------------------------*/
void CalcSurge::SelVessel(int nValue)
{
	m_bSelVessel = nValue;
}
/*------------------------------------------------*/
void CalcSurge::VesselHeight(double dValue)
{
	m_dVesselHeight = dValue;
}
/*------------------------------------------------*/
void CalcSurge::Polytropic(double dValue)
{
	m_dPolytropic = dValue;
}
/*------------------------------------------------*/
void CalcSurge::SelSurfaceH(int nValue)
{
	m_bSelSurfaceH = nValue;
}
/*------------------------------------------------*/
void CalcSurge::InitSurfaceH(double dValue)
{
	m_dInitSurfaceH = dValue;
}

//////////////////////////////////////////////////////
ListImp<StrArray<4> >& CalcSurge::PipeInfo()
{
    return m_PipeInfo.GetData();
}

ListImp<StrArray<2> >& CalcSurge::AreaTable()
{
	return m_AreaTable.GetData();
}

/*------------------------------------------------*/
double CalcSurge::SurfacePress()
{
	return m_dSurfacePress;
}
/*------------------------------------------------*/
double CalcSurge::SurgeHeight()
{
	return m_dSurgeHeight;
}
/*------------------------------------------------*/
double CalcSurge::ConstArea()
{
	return m_dConstArea;
}
/*------------------------------------------------*/
int CalcSurge::OneWay()
{
	return abs(m_bOneWay);
}
/*------------------------------------------------*/
double CalcSurge::CheckCv()
{
	return m_dCheckCv;
}
/*------------------------------------------------*/
int CalcSurge::Position()
{
	return m_nPosition;
}
/*------------------------------------------------*/
int CalcSurge::ReOpenPressType()
{
	return m_nReOpenPressType;
}
/*------------------------------------------------*/
double CalcSurge::ReOpenPress()
{
	return m_dReOpenPress;
}
/*------------------------------------------------*/
int CalcSurge::SelVessel()
{
	return abs(m_bSelVessel);
}
/*------------------------------------------------*/
double CalcSurge::VesselHeight()
{
	return m_dVesselHeight;
}
/*------------------------------------------------*/
double CalcSurge::Polytropic()
{
	return m_dPolytropic;
}
/*------------------------------------------------*/
int CalcSurge::SelSurfaceH()
{
	return abs(m_bSelSurfaceH);
}
/*------------------------------------------------*/
double CalcSurge::InitSurfaceH()
{
	return m_dInitSurfaceH;
}