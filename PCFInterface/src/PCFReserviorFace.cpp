// PCFReserviorFace.cpp: implementation of the PCFReserviorFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFReserviorFace.h"
#include "PCFReservior.h"
#include "reservoirperisist.h"
//#include "AFTTransDataFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFReserviorFace::PCFReserviorFace()
{
	
}

PCFReserviorFace::~PCFReserviorFace()
{
	
}

ErrorStatus::FileError PCFReserviorFace::Read( PCFJun *pData,Junperisist *pModel )
{
	// TODO: Add extra Read here
	PCFReservior *pReserviorData = dynamic_cast< PCFReservior* >( pData );
	ASSERT(pReserviorData != NULL);
	ReservoirPerisist *pReserviorModel = dynamic_cast< ReservoirPerisist*>( pModel );
	ASSERT(pReserviorModel != NULL);
//	pReserviorModel->PipeInfo( pReserviorData->GetPipeInfo() );
 	pReserviorModel->EleOrDepth( pReserviorData->GetEleOrDepth() );
 	pReserviorModel->SurfacePress( pReserviorData->GetSurfacePress() );
// 	pReserviorModel->Teamperature(pReserviorData->Teamperature());
// 	pReserviorModel->Density(pReserviorData->Density());
// 	pReserviorModel->EleOrDepthType(pReserviorData->EleOrDepthType());
	
// 	AFTTransDataFace face;
// 	face.Read(pReserviorData->m_TranData,pReserviorModel->m_TransPersistent);
	return PCFJunFace::Read( pData,pModel );
}

PCFJunFace* PCFReserviorFace::Creator()
{
	static PCFReserviorFace sReservior;
	return &sReservior;
}
