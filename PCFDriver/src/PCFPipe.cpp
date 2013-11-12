// PCFPipe.cpp: implementation of the PCFPipe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFPipe.h"
#include "ProjectionInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFPipe::PCFPipe()
{
	m_nInJun = 0;
	m_nOutJun = 0;
	m_dInDia = 0;
	m_dThick = 0;
	m_dElasticity = 0;
	m_dPossionRatio = 0;
	m_dabsRoughness = 0.0018;
	m_dBore = 0;
}

PCFPipe::~PCFPipe()
{

}

void PCFPipe::SetKey(int nKey)
{
	m_nKey = nKey;
}

int PCFPipe::GetKey()
{
	return m_nKey;
}
int PCFPipe::InJun()
{
	return m_nInJun;
}
int PCFPipe::OutJun()
{
	return m_nOutJun;
}
void PCFPipe::InJun(int nID)
{
	m_nInJun = nID;
}
void PCFPipe::OutJun(int nID)
{
	m_nOutJun = nID;
}
void PCFPipe::Init(const CStringArray &array)
{
	int wordNum = array.GetSize();
	int pointNum = 0 ;	
	for(int i = 1; i < wordNum; i++)
	{
		if ( array.GetAt(i) == _T("END-POINT") && pointNum == 0 )
		{
			m_StartPt.x = _tcstod( UELPCSTR (array.GetAt( i+1 ) ), NULL );
			m_StartPt.y = _tcstod( UELPCSTR (array.GetAt( i+2 ) ), NULL );
			m_StartPt.z = _tcstod( UELPCSTR (array.GetAt( i+3 ) ), NULL );
			m_dBore = _tcstod( UELPCSTR (array.GetAt( i+4 ) ), NULL ) ;
			pointNum++;
			i= i+4;
			continue;
		}
		if ( array.GetAt(i) == _T("END-POINT") && pointNum == 1 )
		{
			m_EndPt.x = _tcstod( UELPCSTR (array.GetAt( i+1 ) ), NULL );
			m_EndPt.y = _tcstod( UELPCSTR (array.GetAt( i+2 ) ), NULL );
			m_EndPt.z = _tcstod( UELPCSTR (array.GetAt( i+3 ) ), NULL );		
			pointNum++;
			i= i+4;
			continue;
		}
		if ( array.GetAt(i) == _T("IN-DIA"))
		{
			m_dInDia = _tcstod( UELPCSTR (array.GetAt( i+1 ) ), NULL );
			i++;
			continue;
		}
		if ( array.GetAt(i) == _T("WALL-THICH"))
		{
			m_dThick = _tcstod( UELPCSTR (array.GetAt( i+1 ) ), NULL );
			i++;
			continue;
		}
		if ( array.GetAt(i) == _T("MODULUS-ELASTIC"))
		{
			m_dElasticity = _tcstod( UELPCSTR (array.GetAt( i+1 ) ), NULL );
			i++;
			continue;
		}
		if ( array.GetAt(i) == _T("POISSON-RATIO"))
		{
			m_dPossionRatio = _tcstod( UELPCSTR (array.GetAt( i+1 ) ), NULL );
			i++;
			continue;
		}
		if ( array.GetAt(i) == _T("ABS-ROUGHNESS"))
		{
			m_dabsRoughness = _tcstod( UELPCSTR (array.GetAt( i+1 ) ), NULL );
			i++;
			continue;
		}
	}
}

AcGePoint3d& PCFPipe::StartPt()
{
	return m_StartPt;
}

AcGePoint3d& PCFPipe::EndPt()
{
	return m_EndPt;
}
void PCFPipe::EndPt(const AcGePoint3d& pt)
{
	m_EndPt = pt;
}
void PCFPipe::StartPt(const AcGePoint3d& pt)
{
	m_StartPt = pt;
}
AcGePoint3d& PCFPipe::Start2dPt()
{
	return m_Start2dPt;
}

AcGePoint3d& PCFPipe::End2dPt()
{
	return m_End2dPt;
}

void PCFPipe::Tran3dTo2d()
{
	m_Start2dPt = ::Tran3dTo2d(m_StartPt);
	m_End2dPt = ::Tran3dTo2d(m_EndPt);
}

void PCFPipe::OffSet(AcGePoint3d &OriginPt)
{
	m_Start2dPt.x -= OriginPt.x;
	m_Start2dPt.y -= OriginPt.y;
	m_End2dPt.x -= OriginPt.x;
	m_End2dPt.y -= OriginPt.y;
	m_Start2dPt.x += 20;
	m_Start2dPt.y += 20;
	m_End2dPt.x += 20;
	m_End2dPt.y += 20;

}

double PCFPipe::GetLen()
{
	AcGeVector3d vOffset = m_EndPt - m_StartPt;
	return vOffset.length() ;
}
double PCFPipe::InDia()
{
	return m_dInDia;
}
double PCFPipe::Thick()
{
	return m_dThick;
}
double PCFPipe::Elasticity()
{
	return m_dElasticity;
}
double PCFPipe::PossionRatio()
{
	return m_dPossionRatio;
}
double PCFPipe::AbsRoughness()
{
	return m_dabsRoughness;
}
double PCFPipe::Bore()
{
	return m_dBore;
}
void PCFPipe::ChangeOrigin(AcGePoint3d &OriginPt)
{
	m_Start2dPt.y = OriginPt.y-m_Start2dPt.y;
	m_End2dPt.y = OriginPt.y-m_End2dPt.y;
}
