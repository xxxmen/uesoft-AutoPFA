// DeadEndData.cpp: implementation of the DeadEndData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DeadEndData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DeadEndData::DeadEndData()
{
	AppendArray();
}

DeadEndData::~DeadEndData()
{

}

JunctionData* DeadEndData::Creator()
{
	DeadEndData *pData = new DeadEndData;
	return pData;
}

CString DeadEndData::GetDefaultData()
{
	return _T(",,9,1,,0,0,0,-1,0,3,0,0,0,1E+31,feet,0,0,0,0,None,1,0,0,None,0,None,0,None,None,-1,0,,1,90,-285,-999999,-999999,1,5,-1,-1,25,0,,1,-1,Arial,9,0,0,0,0,-999");
}

void DeadEndData::InitExtra(CString strData)
{

}

void DeadEndData::AppendArray()
{

}
