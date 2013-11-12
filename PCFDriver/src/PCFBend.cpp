// PCFBend.cpp: implementation of the PCFBend class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFBend.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFBend::PCFBend()
{
	m_strName = _T("Bend");
	m_nTypeID = 6;
	m_bPFAJun = TRUE;
}

PCFBend::~PCFBend()
{

}

void PCFBend::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
		SetSEBPoint(wordArray, i, pointNum, m_PointList, m_CenterPt);
		if ( wordArray.GetAt(i) ==_T("ANGLE") )
		{
			m_dAngle=_tcstod( UELPCSTR (wordArray.GetAt( i+1 ) ), NULL );
			i++;
			continue;
		}
	}
}

PCFJun* PCFBend::Creator()
{
	PCFBend *pPCFBend = new PCFBend;
	return pPCFBend;
}


