// PCFAssignPressFace.cpp: implementation of the PCFAssignPressFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFAssignPressFace.h"
#include "assignpressperisist.h"
#include "PCFAssignPress.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFAssignPressFace::PCFAssignPressFace()
{
	
}

PCFAssignPressFace::~PCFAssignPressFace()
{
	
}

ErrorStatus::FileError PCFAssignPressFace::Read(PCFJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	PCFAssignPress *pAssignPressData = dynamic_cast< PCFAssignPress* >( pData );
	ASSERT( pAssignPressData != NULL );
	AssignPressPerisist *pAssignPressModel = dynamic_cast< AssignPressPerisist* >( pModel );
	ASSERT( pAssignPressModel != NULL );
	pAssignPressModel->DistanceUnit( pAssignPressData->GetDistanceUnit() );
	pAssignPressModel->Pressure( pAssignPressData->GetPressure() );
	
	return PCFJunFace::Read(pData,pModel);
}


PCFJunFace* PCFAssignPressFace::Creator()
{
	static PCFAssignPressFace sPress;
	return &sPress;
}
