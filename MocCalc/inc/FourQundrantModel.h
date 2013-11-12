// FourQundrantModel.h: interface for the FourQundrantModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FOURQUNDRANTMODEL_H__E43454ED_2593_4A18_9459_03D953390E09__INCLUDED_)
#define AFX_FOURQUNDRANTMODEL_H__E43454ED_2593_4A18_9459_03D953390E09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class PumpTransModelMgr;
class MOCFourQuadrantData;

class FourQundrantModel  
{
public:
	double CalcdH(MOCFourQuadrantData &data,double da,double dv);
	double CalcdBf(MOCFourQuadrantData &data,double da,double dv);
	double Calcfunv(PumpTransModelMgr &mgr,double dMr,double dPr,double da,double dv,int nSet);
	double Calcfuna(PumpTransModelMgr &mgr,double dTr,double dNr,double da0,double dB0,double da,double dv);
	double Calcv(PumpTransModelMgr &mgr,double dMr,double dPr,double da,double dv,int nSet);
	double Calca(PumpTransModelMgr &mgr,double dTr,double dNr,double da0,double dB0,double da,double dv);
	double Calca(PumpTransModelMgr &mgr,double dTr,double dNr,double da0,double dBf0,double dBm0,double dBm,double da,double dv);
	static FourQundrantModel* Instance();
	virtual ~FourQundrantModel();
	
protected:
	FourQundrantModel();
	
private:
	FourQundrantModel(const FourQundrantModel &ref);
	FourQundrantModel& operator=(const FourQundrantModel &ref);

};

#endif // !defined(AFX_FOURQUNDRANTMODEL_H__E43454ED_2593_4A18_9459_03D953390E09__INCLUDED_)
