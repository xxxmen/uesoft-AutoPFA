// PCFReduceFace.cpp: implementation of the PCFReduceFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFReduceFace.h"
#include "PCFReduce.h"
#include "AreaChangePerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFReduceFace::PCFReduceFace()
{
	
}

PCFReduceFace::~PCFReduceFace()
{

}
PCFJunFace* PCFReduceFace::Creator()
{
	static PCFReduceFace sReduce;
	return &sReduce;
}

ErrorStatus::FileError PCFReduceFace::Read(PCFJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	PCFReduce *pAreaChangeData = dynamic_cast<PCFReduce*>(pData);
	ASSERT(pAreaChangeData != NULL);
	AreaChangePerisist *pAreaChangeModel = dynamic_cast<AreaChangePerisist*>(pModel);
	ASSERT(pAreaChangeModel != NULL);
	pAreaChangeModel->Type(_T("0"));
	//pAreaChangeModel->K(pAreaChangeData->K());
	//pAreaChangeModel->Dir(pAreaChangeData->Dir());
	//pAreaChangeModel->Angle(ftoStr(pAreaChangeData->GetAngle());
	//pAreaChangeModel->BasisArea(pAreaChangeData->BasisArea());
	return PCFJunFace::Read(pData,pModel);
}