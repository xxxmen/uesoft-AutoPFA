// EndListRef.cpp: implementation of the EndListRef class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EndListRef.h"
#include "BrachJunStrategy.h"
#include "FlowJunStrategy.h"
#include "LocalRStrategy.h"
#include "PressDropStrategy.h"
#include "PressJunStrategy.h"
#include "SurgeStrategy.h"
#include "GasAccumStrategy.h"
#include "BreckerStrategy.h"
#include "LiquidAccumStrategy.h"
#include "MOCFluid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

EndListRef::EndListRef()
{
	m_dOldDetalVapor = 0;
}

EndListRef::~EndListRef()
{

}

void EndListRef::AddEnd(EndInfo *pEnd)
{
	ASSERT(pEnd != NULL);
	m_list.AddTail(pEnd);
}

Iterator<EndInfo>* EndListRef::CreatEndIt()
{
	return new ListIterator<EndInfo>(&m_list);
}

EndInfo* EndListRef::GetInEnd()
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		if(pEnd->Type()==INJUN)
			return pEnd;
	}
	return NULL;
}

EndInfo* EndListRef::GetOutEnd()
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		if(pEnd->Type()==OUTJUN)
			return pEnd;
	}
	return NULL;
}

void EndListRef::SetMass(double dMass)
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		pEnd->SetMass(dMass);
	}
}

void EndListRef::SetPress(double dPress)
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		pEnd->SetPress(dPress);
	}
}
double EndListRef::GetEGL()
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		return pEnd->GetEGL();
	}
	ASSERT(FALSE);
	return 0;
}
double EndListRef::GetDetalPress()
{
	EndInfo *pEndIn = GetInEnd();
	EndInfo *pEndOut = GetOutEnd();
	if(pEndIn!=NULL && pEndOut!=NULL)
		return fabs(pEndIn->GetPress()-pEndOut->GetPress());
	return -1;
}
double EndListRef::GetPress()
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		return pEnd->GetPress();
	}
	ASSERT(FALSE);
	return 0;
}
double EndListRef::GetStaticPress()
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		return pEnd->GetStaticPress();
	}
	ASSERT(FALSE);
	return 0;
}
double EndListRef::GetOneEndArea()
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		return pEnd->Area();
	}
	ASSERT(FALSE);
	return 1;
}
double EndListRef::GetInMass()
{
	return GetMass(INJUN);
}

double EndListRef::GetOutMass()
{
	return GetMass(OUTJUN);
}

double EndListRef::GetMass(Dir type)
{
	double dMassFlow = 0;
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		if(pEnd->Type()==type)
		{
			dMassFlow += pEnd->GetMass(); 
		}	
	}	
	return dMassFlow;
}

EndInfo* EndListRef::Find(int nKey)
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		if(abs(pEnd->Key())==abs(nKey))
			return pEnd;
	}
	return NULL;
}

void EndListRef::SetZ(double dInZ,double dOutZ)
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		if(pEnd->Type()==INJUN)
		{
			pEnd->SetZ(dInZ);
		}
		else
		{
			pEnd->SetZ(dOutZ);
		}
	}	
}

BOOL EndListRef::IsVapor()
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		if (pEnd->IsVapor())
			return TRUE;
	}
	return FALSE;
}
void EndListRef::Vapor(BOOL bVapor)
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		pEnd->Vapor(bVapor);
	}
}
double EndListRef::VaporVolume()
{
	double dVaporVolume = 0;
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		dVaporVolume += pEnd->VaporVolume();
	}
	return dVaporVolume;
}
void EndListRef::VaporVolume(double dVolume)
{
	double n = m_list.GetCount();
	dVolume = dVolume/n;
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		pEnd->VaporVolume(dVolume);
	}
}

double EndListRef::Sc()
{
	double dSc = 0;
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		if(-0.000001<pEnd->GetBpm()&&pEnd->GetBpm()<0.000001)
		{
			ASSERT(FALSE);//波速大于0所以B大于0
			return 0;
		}
		dSc += pEnd->GetCpm()/pEnd->GetBpm();
	}
	return dSc;
}

double EndListRef::Sb()
{
	double dSb = 0;
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		if(-0.000001<pEnd->GetBpm()&&pEnd->GetBpm()<0.000001)
		{
			ASSERT(FALSE);//波速大于0所以B大于0
			return 0;
		}
		dSb += 1.0 /pEnd->GetBpm();
	}
	return dSb;
}

double EndListRef::SunBpm()
{
	double dSb = 0;
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		dSb += pEnd->GetBpm();
	}
	return dSb;
}
double EndListRef::SunCpm()
{
	double dSc = 0;
	double dCpm = 0;
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		dCpm = pEnd->GetCpm();
		if(pEnd->Type()==OUTJUN)
			dCpm = -dCpm;
		dSc += dCpm;
	}
	return dSc;
}
double EndListRef::CheckVaporPress(double dPress)
{
	double dTempPress=0;
	double dOldPress = 0;
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		dOldPress = pEnd->GetPress();
		pEnd->SetPress(dPress);
		dTempPress = pEnd->CheckVaporPress(dPress,pEnd->CalcMass());
		pEnd->SetPress(dOldPress);
		if (pEnd->IsVapor())
			return dTempPress;
	}
	return dPress;
}
double EndListRef::DetalVaporVolume(double dOutMass)
{
	double dVolume = 0;
	double dNewMass = (GetOutMass()-GetInMass()-dOutMass)/2;
	dVolume = m_dOldDetalVapor;
	m_dOldDetalVapor =MOCFluid::TranMassToV(dNewMass);
	return (dVolume+m_dOldDetalVapor);
}
double EndListRef::OldDetalVaporVolume()
{
	return m_dOldDetalVapor;
}
double EndListRef::CollapseMass()
{
	double dV = VaporVolume();
	return MOCFluid::TranVToMass(dV);
}
void EndListRef::Collapse()
{
	VaporVolume(0);
	m_dOldDetalVapor = 0;
	Vapor(FALSE);
}
////////////////////////////////////////////////////////////

void EndListRef::BranchStrategy(double dOutMass)
{
	BrachJunStrategy *pStrategy = BrachJunStrategy::Instance();
	pStrategy->Calc(*this,dOutMass);
}

void EndListRef::FlowStrategy(double dMass)
{
	FlowJunStrategy *pStrategy = FlowJunStrategy::Instance();
	pStrategy->Calc(*this,dMass);
}
void EndListRef::FlowStrategy(EndInfo &end,double dMass)
{
	FlowJunStrategy *pStrategy = FlowJunStrategy::Instance();
	pStrategy->Calc(*this,end,dMass);
}
void EndListRef::DeadStrategy()
{
	FlowJunStrategy *pStrategy = FlowJunStrategy::Instance();
	pStrategy->Calc(*this,0);
}

void EndListRef::StaticPressStrategy(double dStaticPress)
{
	PressJunStrategy *pStrategy = PressJunStrategy::Instance();
	pStrategy->CalcStatic(*this,dStaticPress);
}

void EndListRef::StagPressStrategy(double dStagPress)
{
	PressJunStrategy *pStrategy = PressJunStrategy::Instance();
	pStrategy->CalcStag(*this,dStagPress);
}
void EndListRef::StagPressStrategy()
{
	PressJunStrategy *pStrategy = PressJunStrategy::Instance();
	pStrategy->CalcStag(*this);
}
void EndListRef::StaticPressStrategy(EndInfo &end,double dStaticPress)
{
	PressJunStrategy *pStrategy = PressJunStrategy::Instance();
	pStrategy->CalcStatic(end,dStaticPress);
}
void EndListRef::StagPressStrategy(EndInfo &end,double dStagPress)
{
	PressJunStrategy *pStrategy = PressJunStrategy::Instance();
	pStrategy->CalcStag(end,dStagPress);
}

void EndListRef::CvStrategy(double dCv,double dArea)
{
	LocalRStrategy *pStrategy = LocalRStrategy::Instance();
	pStrategy->CalcCv(*this,dCv,dArea);
}
void EndListRef::KStrategy(double dK,double dArea)
{
	LocalRStrategy *pStrategy = LocalRStrategy::Instance();
	pStrategy->CalcK(*this,dK,dArea);
}
void EndListRef::RStrategy(double dR)
{
	LocalRStrategy *pStrategy = LocalRStrategy::Instance();
	pStrategy->CalcR(*this,dR);
}
void EndListRef::CvStrategy(double dPress,double dCv,double dArea,double &dOutMass)
{
	LocalRStrategy *pStrategy = LocalRStrategy::Instance();
	pStrategy->CalcCv(*this,dPress,dCv,dArea,dOutMass);
}
void EndListRef::RStrategy(double dPress,double dR,double &dOutMass)
{
	LocalRStrategy *pStrategy = LocalRStrategy::Instance();
	pStrategy->CalcR(*this,dPress,dR,dOutMass);
}
void EndListRef::KStrategy(double dPress,double dK,double dArea,double &dOutMass)
{
	LocalRStrategy *pStrategy = LocalRStrategy::Instance();
	pStrategy->CalcK(*this,dPress,dK,dArea,dOutMass);
}
double EndListRef::FixDropStrategy(double dPressDelta)
{
	PressDropStrategy *pStrategy = PressDropStrategy::Instance();
	return pStrategy->Calc(*this,dPressDelta);
}
double EndListRef::FixDropStrategy(double dPressUp,double dPressDelta)
{
	PressDropStrategy *pStrategy = PressDropStrategy::Instance();
	return pStrategy->Calc(*this,dPressUp,dPressDelta);
}
double EndListRef::FixDropMass(double dPressDelta)
{
	PressDropStrategy *pStrategy = PressDropStrategy::Instance();
	return pStrategy->CalcMass(*this,dPressDelta);
}
double EndListRef::FixDropMass(double dPressUp,double dPressDelta)
{
	PressDropStrategy *pStrategy = PressDropStrategy::Instance();
	return pStrategy->CalcMass(*this,dPressUp,dPressDelta);
}
double EndListRef::FixRiseStrategy(double dPressDelta)
{
	return FixDropStrategy(-dPressDelta);
}
double EndListRef::FixRiseStrategy(double dPressUp,double dPressDelta)
{
	return FixDropStrategy(dPressUp,-dPressDelta);
}
double EndListRef::FixRiseMass(double dPressDelta)
{
	return FixDropMass(-dPressDelta);
}
double EndListRef::FixRiseMass(double dPressUp,double dPressDelta)
{
	return FixDropMass(dPressUp,-dPressDelta);
}

void EndListRef::SurgeJunStrategy(MOCLumpedInertia &Inertia,double dSurfacePress,double dArea,double &dH,double &dMass)
{
	SurgeStrategy *pStrategy = SurgeStrategy::Instance();
	pStrategy->Calc(*this,Inertia,dSurfacePress,dArea,dH,dMass);
}

void EndListRef::GasJunStrategy(MOCLumpedInertia &Inertia,double dPolytropic,double dCA,double &dMass,double &dPress,double &dVolume)
{
	GasAccumStrategy *pStrategy = GasAccumStrategy::Instance();
	pStrategy->Calc(*this,Inertia,dPolytropic,dCA,dMass,dPress,dVolume);
}

void EndListRef::BreakerJunStrategy(int nType,GasProperty &gas,double dCdAIn,double dCdAOut)
{
	double dTemp = gas.GasPress() - Sc()/Sb();
	if((1==nType)&&(dTemp<0)
		||(2==nType)&&(dTemp>0))
	{
		BranchStrategy(0);
	}
	BreckerStrategy *pStrategy = BreckerStrategy::Instance();
	pStrategy->Calc(*this,gas,dCdAIn,dCdAOut);
}

void EndListRef::LiquidJunStrategy(double dK,double &dVolume,double &dMass)
{
	LiquidAccumStrategy *pStrategy = LiquidAccumStrategy::Instance();
	pStrategy->Calc(*this,dK,dVolume,dMass);
}