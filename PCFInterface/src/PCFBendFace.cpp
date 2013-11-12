// PCFBendFace.cpp: implementation of the PCFBendFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFBendFace.h"
#include "PCFBend.h"
#include "BendPerisist.h"
#include "PCFElbow.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFBendFace::PCFBendFace()
{

}

PCFBendFace::~PCFBendFace()
{

}

PCFJunFace* PCFBendFace::Creator()
{
	static PCFBendFace sBend;
	return &sBend;
}

ErrorStatus::FileError PCFBendFace::Read(PCFJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	if (pData->GetName() == _T("Bend"))
	{
		PCFBend *pBendData = dynamic_cast<PCFBend*>(pData);
		ASSERT(pBendData != NULL);
		BendPerisist *pBendModel = dynamic_cast<BendPerisist*>(pModel);
		ASSERT(pBendModel != NULL);
		
		pBendModel->Type(_T("0"));
		pBendModel->Angle(ftoStr(pBendData->GetAngle()));
		// 	pBendModel->RD(pBendData->RD());
		// 	pBendModel->K(pBendData->K());
		// 	pBendModel->RestriFlowArea(pBendData->RestriFlowArea());
		// 	pBendModel->BasisArea(pBendData->BasisArea());
	}

	if (pData->GetName() == _T("ELBOW"))
	{
		PCFElbow *pBendData = dynamic_cast<PCFElbow*>(pData);
		ASSERT(pBendData != NULL);
		BendPerisist *pBendModel = dynamic_cast<BendPerisist*>(pModel);
		ASSERT(pBendModel != NULL);
		
		pBendModel->Type(_T("1"));
		pBendModel->Angle(ftoStr(pBendData->GetAngle()));
		// 	pBendModel->RD(pBendData->RD());
		// 	pBendModel->K(pBendData->K());
		// 	pBendModel->RestriFlowArea(pBendData->RestriFlowArea());
		// 	pBendModel->BasisArea(pBendData->BasisArea());
		
	}
	
	
	return PCFJunFace::Read(pData,pModel);
}

