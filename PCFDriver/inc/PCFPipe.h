// PCFPipe.h: interface for the PCFPipe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFPIPE_H__B7C20666_ED40_4F2B_A575_5252BD0A6287__INCLUDED_)
#define AFX_PCFPIPE_H__B7C20666_ED40_4F2B_A575_5252BD0A6287__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <gepnt3d.h>

class AFX_EXT_CLASS PCFPipe  
{
public:
	void ChangeOrigin(AcGePoint3d& OriginPt);
	void OffSet(AcGePoint3d& OriginPt);
	void Tran3dTo2d();
	AcGePoint3d& End2dPt();
	AcGePoint3d& Start2dPt();
	AcGePoint3d& EndPt();
	AcGePoint3d& StartPt();
	void EndPt(const AcGePoint3d& pt);
	void StartPt(const AcGePoint3d& pt);
	void Init(const CStringArray& array );

public:
	int GetKey();
	void SetKey(int nKey);
	int InJun();
	int OutJun();
	void InJun(int nID);
	void OutJun(int nID);
	double GetLen();
	double InDia();
	double Thick();
	double Elasticity();
	double PossionRatio();
	double AbsRoughness();
	double Bore();
	PCFPipe();
	virtual ~PCFPipe();
private:
	int m_nKey;
	AcGePoint3d m_StartPt;
	AcGePoint3d m_EndPt;
	AcGePoint3d m_Start2dPt;
	AcGePoint3d m_End2dPt;
	int m_nInJun;
	int m_nOutJun;
	double m_dInDia;
	double m_dThick;
	double m_dElasticity;
	double m_dPossionRatio;
	double m_dabsRoughness;

	double m_dBore;



};

#endif // !defined(AFX_PCFPIPE_H__B7C20666_ED40_4F2B_A575_5252BD0A6287__INCLUDED_)
