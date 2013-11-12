// GeneralData.cpp: implementation of the GeneralData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GeneralData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GeneralData::GeneralData()
{
	AppendArray();
}

GeneralData::~GeneralData()
{

}

JunctionData* GeneralData::Creator()
{
	GeneralData *pData = new GeneralData;
	return pData;
}

CString GeneralData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,3,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,-1,0,,1,90,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999,\
		0,1,0,None,0,None,-1,1,5,0,0,0,0,0,0,0,0,None");
}

void GeneralData::InitExtra(CString strData)
{
	strData = m_Type.InitData(strData);
	strData = m_Curve.InitData(strData);
	if ( !isImpFile )
	{
		strData = m_Fth2.InitData( strData ) ;
	}
	strData = m_KOrCv.InitData(strData);
	strData = m_BasisArea.InitData(strData);
}

void GeneralData::AppendArray()
{
	RowArrayRef array;
	array.SetSize(4);
	array.SetAt(0,&m_Type.Data());
	array.SetAt(1,&m_Curve.Data());
	array.SetAt(2,&m_KOrCv.Data());
	array.SetAt(3,&m_BasisArea.Data());	
	m_RowArray.Append(array);
}


/*------------------------------------------*/
CString GeneralData::Type()
{
	return m_Type.GetData();
}
void GeneralData::Type(CString strValue)
{
	m_Type.SetData(strValue);
}
/*------------------------------------------*/
inline StrArray<13> GeneralData::Curve()
{
	return m_Curve.GetArray();
}
void GeneralData::Curve(const StrArray<13>& strValue)
{
	m_Curve.SetArray(strValue);
}

/*------------------------------------------*/
CString GeneralData::KOrCv()
{
	return m_KOrCv.GetData();;
}
void GeneralData::KOrCv(CString strValue)
{
	m_KOrCv.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> GeneralData::BasisArea()
{
	return m_BasisArea.GetArray();;
}
void GeneralData::BasisArea(const StrArray<3>& strValue)
{
	m_BasisArea.SetArray(strValue);
}