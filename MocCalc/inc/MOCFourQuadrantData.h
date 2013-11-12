// MOCFourQuadrantData.h: interface for the MOCFourQuadrantData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCFOURQUADRANTDATA_H__57E2F2CB_64A7_4D77_B998_A8C8ECDDFB04__INCLUDED_)
#define AFX_MOCFOURQUADRANTDATA_H__57E2F2CB_64A7_4D77_B998_A8C8ECDDFB04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MOCTable.h"

class MOCFourQuadrantData  
{
public:
	void FB(const ListImp<StrArray<2> > &ref);
	void FH(const ListImp<StrArray<2> > &ref);
	void AngleType(int nValue);
	MOCFourQuadrantData();
	virtual ~MOCFourQuadrantData();
public:
	double GetFB(double da,double dv);
	double GetFH(double da,double dv);
private:
	double CalcAngel(double da,double dv);
	double GetFB(double dAngel);
	double GetFH(double dAngel);
private:
	int m_nAngelType;
	DataTable m_tableFH;
	DataTable m_tableFB;

};

#endif // !defined(AFX_MOCFOURQUADRANTDATA_H__57E2F2CB_64A7_4D77_B998_A8C8ECDDFB04__INCLUDED_)
