// PCFElbow.cpp: implementation of the PCFElbow class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFElbow.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFElbow::PCFElbow()
{
	m_strName = _T("ELBOW");
	m_nTypeID = 6;
	m_bPFAJun = TRUE;
	m_dAngle = 60;
}

PCFElbow::~PCFElbow()
{

}

PCFJun* PCFElbow::Creator()
{
	PCFElbow *pEblow = new PCFElbow;
	return pEblow;
}

void PCFElbow::Init(const CStringArray &wordArray)
{
    PCFElbow *pElbow = new PCFElbow;
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
		CString str1 = wordArray.GetAt(i) ;
		SetSEBPoint(wordArray, i, pointNum, m_PointList, m_CenterPt);
		if ( wordArray.GetAt(i) ==_T("ANGLE") )
		{
			double angle;
		    angle=_tcstod( UELPCSTR (wordArray.GetAt( i+1 ) ), NULL );
			//pElbow->SetAngle(angle);	
			angle=angle*90/1.570796;
			this->SetAngle(angle);
			i++;
			continue;
		}
	}
}

void PCFElbow::SetAngle( double dAngle )
{
	m_dAngle = dAngle;
}

double PCFElbow::GetAngle()
{
	//m_dAngle = m_dAngle*80 ;
//	if( abs(m_dAngle-90)<0.1 )
	//	return m_dAngle;
//	else
		return m_dAngle;
}


