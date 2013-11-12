// MOCStationMgr.h: interface for the MOCStationMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCSTATIONMGR_H__EDF2C291_EFE5_4D74_9AE3_B0EC84A57AB3__INCLUDED_)
#define AFX_MOCSTATIONMGR_H__EDF2C291_EFE5_4D74_9AE3_B0EC84A57AB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MOCStation.h"
#include "Iterator.h"
class MOCPipe;
class MOCTrans;
class StationOut;

class MOCStationMgr  
{
public:
	void Result(StationOut &out, MOCPipe* pMocPipe=NULL);
	void CalcImpulse(MOCTrans &trans);
	MOCStation* Creator(int nKey);
	MOCStation* LookUp(int nKey);
	Iterator<MOCStation>* CreatIterator();
	BOOL Init(MOCPipe* pPipe,int nSectionNum);
	MOCStationMgr();
	virtual ~MOCStationMgr();

private:
	void Result(StationOut &out,EndInfo *pEnd,int nKey, MOCPipe* pMocPipe = NULL,double dLoss=0);
	void CalcStation(MOCTrans &trans);
	void CalcCB();
	void CalcCB(EndInfo *pInEnd,EndInfo *pOutEnd,double dF,int nSectionNum);
	void Empty();
	void Init(MOCStation *pStation,int nIndex,int nSectionNum);
	MOCPipe *m_pPipe;
	StationMap m_stationMap;
	double m_dHPress;
	double m_dStamR;
};

#endif // !defined(AFX_MOCSTATIONMGR_H__EDF2C291_EFE5_4D74_9AE3_B0EC84A57AB3__INCLUDED_)
