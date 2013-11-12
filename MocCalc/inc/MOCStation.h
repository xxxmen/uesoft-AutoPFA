// MOCStation.h: interface for the MOCStation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCSTATION_H__B1F7C2D1_B714_418E_B6FB_1450828B42EC__INCLUDED_)
#define AFX_MOCSTATION_H__B1F7C2D1_B714_418E_B6FB_1450828B42EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "EndListRef.h"
class MOCTrans;

class MOCStation  
{
public:
	void CalcImpulse(MOCTrans &trans);
	EndInfo* GetOutEnd();
	EndInfo* GetInEnd();
	void SetArea(double dArea);
	static MOCStation* Creator();
	void SetZ(double dZ);
	void SetPress(double dPress);
	void SetMass(double dMass);
	void Key(int nKey);
	int Key();
	MOCStation();
	virtual ~MOCStation();
public:
	double GetCm();
	double GetCp();
	double GetBm();
	double GetBp();
private:
	int m_nKey;
	EndInfo m_InEnd;
	EndInfo m_OutEnd;
	EndListRef m_EndList;
};

typedef CMap<int,int,MOCStation*,MOCStation*> StationMap;
#endif // !defined(AFX_MOCSTATION_H__B1F7C2D1_B714_418E_B6FB_1450828B42EC__INCLUDED_)
