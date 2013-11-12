// LiquidAccumData.cpp: implementation of the LiquidAccumData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LiquidAccumData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LiquidAccumData::LiquidAccumData()
{
	AppendArray();
}

LiquidAccumData::~LiquidAccumData()
{

}

JunctionData* LiquidAccumData::Creator()
{
	LiquidAccumData *pData = new LiquidAccumData;
	return pData;
}

CString LiquidAccumData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,3,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,0,0,,1,90,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		0,None,0,None");
}

void LiquidAccumData::InitExtra(CString strData)
{
	strData = m_Elastic.InitData(strData);
	strData = m_Volume.InitData(strData);
}

void LiquidAccumData::AppendArray()
{
	RowArrayRef array;
	array.SetSize(2);
	array.SetAt(0,&m_Elastic.Data());
	array.SetAt(1,&m_Volume.Data());
	m_RowArray.Append(array);
}
/*------------------------------------------*/
StrArray<2> LiquidAccumData::Elastic()
{
	return m_Elastic.GetArray(); 
}

void LiquidAccumData::Elastic(StrArray<2>& array)
{
	m_Elastic.SetArray(array);
}
/*------------------------------------------*/
StrArray<2> LiquidAccumData::InitVolume()
{
	return m_Volume.GetArray();
}

void LiquidAccumData::InitVolume(StrArray<2>& array)
{
	m_Volume.SetArray(array);
}
/*------------------------------------------*/