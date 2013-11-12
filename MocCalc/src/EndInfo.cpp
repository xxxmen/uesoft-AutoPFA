// EndInfo.cpp: implementation of the CEndInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EndInfo.h"
#include "MOCFluid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

EndInfo::EndInfo(Dir emun)
{
	m_emunDir = emun;
	m_nPipeKey =0;
	m_dMass = 0.0;
	m_dPress = 0.0;
	m_dCpm = 0.0;
	m_dBpm = 0.0;
	m_dElevation = 0.0;
	m_dKInPipe = 0.0;
	m_dKOutPipe = 0.0;
	m_dArea = 0.0;
	m_dVaporVolume = 0;
	m_dOldDetalVapor = 0;
	m_bVapor = FALSE;
	m_PipeId[0] = 0;
	m_PipeId[1] = 0;
	m_PipeId[2] = 0;

	m_bZeroMassFlag = FALSE ;
}

EndInfo::~EndInfo()
{

}
BOOL EndInfo::IsVapor()
{
	return m_bVapor;
}
void EndInfo::Vapor(BOOL bVapor)
{
	m_bVapor = bVapor;
}
double EndInfo::VaporVolume()
{
	return m_dVaporVolume;
}
void EndInfo::VaporVolume(double dVaporVolume)
{
	m_dVaporVolume = dVaporVolume;
}
double EndInfo::CalcMass()
{
	if(-0.000001<m_dBpm&&m_dBpm<0.000001)
	{
		ASSERT(FALSE);//m_dBpm = 波速/面积一定大于0
		return 0;
	}
	if(m_emunDir == INJUN) //流入节点
	{
		return((m_dCpm -m_dPress)/m_dBpm);
	}
	else
	{
		return((m_dPress - m_dCpm)/m_dBpm);
	}
}

double EndInfo::CalcPress()
{
	double dPress = 0;
	if(m_emunDir == INJUN) //流入节点
	{
		 dPress = m_dCpm - m_dBpm*m_dMass;
	}
	else
	{
		dPress = m_dCpm + m_dBpm*m_dMass;
	}
	return dPress;
}
double EndInfo::CalcStaicMass(double dPress)
{
 	double dMass = 0;
	double dR = GetStaticR();
 	double dTemp = pow(m_dBpm,2)/pow(dR,2) +4.0*(m_dCpm-dPress)/dR;
	if(m_emunDir == INJUN) //流入节点
	{
		dMass = (-m_dBpm/dR + sqrt(fabs(dTemp)))/2;
	}
	else
	{
		dMass = (m_dBpm/dR - sqrt(fabs(dTemp)))/2;
	}
 	SetPress(dPress+dR*pow(dMass,2));
	return dMass;
}
double  EndInfo::GetStaticR()
{
	return 0.5/MOCFluid::Density()/pow(Area(),2);
}
double EndInfo::CalcEndLoss()
{
	double dV = MOCFluid::TranMassToQ(m_dMass)/m_dArea;
	double dDen = MOCFluid::Density();
	double dK = 0;
	if(m_emunDir == INJUN) //流入节点
	{
		dK = m_dKInPipe;
	}
	else
	{
		dK = m_dKOutPipe;
	}
	return 0.5*dK*dDen*pow(dV,2);
}


double EndInfo::GetEGL()
{
	return MOCFluid::TranPressToHGL(m_dPress)+m_dElevation;
}

double EndInfo::GetHGL()
{
//	double dStaticPress = m_dPress-MOCFluid::CalcPressLoss(m_dMass,m_dArea);
	double dStaticPress = m_dPress;
	return MOCFluid::TranPressToHGL(dStaticPress)+m_dElevation;
}

double EndInfo::GetVolumeFlow()
{
	return MOCFluid::TranMassToQ(GetMass());
}
double EndInfo::GetVelocity()
{
	return GetVolumeFlow()/Area();
}
double EndInfo::GetStagPress()
{
	return GetPress();
}
double EndInfo::GetStaticPress()
{
	return GetStagPress()-MOCFluid::CalcPressLoss(GetMass(),Area());
}

double EndInfo::CheckVaporPress(double dPress,double dMass)
{
	double dDatalPress = MOCFluid::CalcPressLoss(dMass,Area());
	if((dPress-dDatalPress) < MOCFluid::VaporPress()&&MOCFluid::IsVaporModel())
	{
		dPress = MOCFluid::VaporPress();
		m_bVapor = TRUE;
	}
	else
	{
		m_bVapor = FALSE;
	}
	return dPress;
}

double EndInfo::DetalVaporVolume(double dMass)
{
	double dNewMass = 0;
	double dVolume = 0;
	if(m_emunDir == INJUN) //流入节点
	{
		dNewMass = (dMass-m_dMass)/2;
	}
	else
	{
		dNewMass = (m_dMass-dMass)/2;
	}
	dVolume = m_dOldDetalVapor;
	m_dOldDetalVapor =MOCFluid::TranMassToV(dNewMass);
	return (dVolume+m_dOldDetalVapor);
}

void EndInfo::Collapse()
{
	m_dVaporVolume = 0;
	m_dOldDetalVapor = 0;
	m_bVapor = FALSE;
}

double EndInfo::CollapseMass()
{
	double dMass = MOCFluid::TranVToMass(m_dVaporVolume);
	if(m_emunDir == OUTJUN)
		dMass = -dMass;
	return dMass;
}