// JunOut.cpp: implementation of the JunOut class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JunOut.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

JunOut::JunOut()
{
	m_nStep = 0;
}

JunOut::~JunOut()
{

}

void JunOut::Step(int nStep)
{
	m_nStep = nStep;
}

int JunOut::Step()
{
	return m_nStep;
}

double JunOut::Data(int nKey,int nSubKey)
{
	return GetdValue(nSubKey);
}

void JunOut::SetSpeed(double dValue)
{
	SetValue(dValue,1);
}
void JunOut::SetGasAccumVolume(double dValue)
{
	SetValue(dValue,2);
}
void JunOut::SetGasAccumPress(double dValue)
{
	SetValue(dValue,3);
}
void JunOut::SetSprayMassFlow(double dValue)
{
	SetValue(dValue,4);
}
void JunOut::SetSprayVolumeFlow(double dValue)
{
	SetValue(dValue,5);
}
void JunOut::SetSurgeLiquidH(double dValue)
{
	SetValue(dValue,6);
}
void JunOut::SetSurgeHGL(double dValue)
{
	SetValue(dValue,7);	
}
void JunOut::SetTime(double dValue)
{
	SetValue(dValue,8);
}