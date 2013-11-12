// PCFAssignFlow.cpp: implementation of the PCFAssignFlow class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFAssignFlow.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFAssignFlow::PCFAssignFlow()
{

	m_strName = _T("ASSIGNFLOW");
	m_nTypeID = 3;
	m_bPFAJun = TRUE;
//	m_FlowDir = 0;
//	m_K = 0.0001;
	
// 	CString strData = _T("0,10,m3/h,0.001,,0,0,0,-1,0,24,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,0,0,,1,142.5,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,10,\
// 		m3/sec,0,0.001,0,0,0,0,0,0,0,0,0,-1,0,None,-1,-1,0,None,-1,-1,-1,-1,-1,-1,0,None,-1,-1,-1,-1,None,1,0,seconds,None,None,1,0,seconds,None,0,0,0,None") ;
//	strData = m_Flow.InitData( strData );
	m_Flow.InitData( _T( "0,1.48,m3/sec" ) );
	m_FlowDir.InitData( _T( "0" ) );
	m_K.InitData( _T( "0" ) );
// 	strData = m_TranData.ValueTypeData().InitData(strData);
// 	strData = m_TranData.SpecialData().InitData(strData);
// 	strData = m_TranData.Repeat1Data().InitData(strData);
// 	strData = m_TranData.Repeat2Data().InitData(strData);
// 	strData = m_TranData.TransTypeData().InitData(strData);
// 	strData = m_TranData.PeriodicData().InitData(strData);
// 	strData = m_TranData.TranTriger1Data().InitData(strData);
// 	strData = m_TranData.TranTriger2Data().InitData(strData);
// 	strData = m_TranData.m_Trans1Table.InitData(strData);
// 	strData = m_TranData.m_Trans2Table.InitData(strData);
// 	strData = m_InitPress.InitData(strData);

}

PCFAssignFlow::~PCFAssignFlow()
{

}

PCFJun* PCFAssignFlow::Creator()
{
	PCFAssignFlow *pPCFAssignFlow = new PCFAssignFlow;
	return pPCFAssignFlow;
}

void PCFAssignFlow::Init( const CStringArray& wordArray )
{
	int wordNum = wordArray.GetSize();
	int pointNum = 0 ;
	for(int i = 0; i < wordNum; i++)
	{
		SetBFromSEPt(wordArray, i, pointNum, m_PointList, m_CenterPt);
	}
}

StrArray<3> PCFAssignFlow::GetAssignFlow()
{
	return m_Flow.GetArray();
}

void PCFAssignFlow::SetAssignFlow(const StrArray<3>& strValue)
{
	m_Flow .SetArray(strValue);
}


/*------------------------------------------*/
CString PCFAssignFlow::GetAssignFlowDir()
{
	return m_FlowDir.GetData();
}
void PCFAssignFlow::SetAssignFlowDir(CString strValue)
{
	m_FlowDir.SetData(strValue);
}
/*------------------------------------------*/
CString PCFAssignFlow::GetK()
{
	return m_K.GetData();
}
void PCFAssignFlow::SetK(CString strValue)
{
	m_K.SetData(strValue);
}
/*------------------------------------------*/
// StrArray<4> PCFAssignFlow::GetAssignInitPress()
// {
// 	return m_InitPress.GetArray();
// }
// void PCFAssignFlow::SetAssignInitPress(const StrArray<4>& strValue)
// {
// 	m_InitPress.SetArray(strValue);
// }