// MOCSteady.h: interface for the MOCSteady class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCSTEADY_H__CD3C2D89_B8AE_4A7D_922A_4CFEEB2ACCF0__INCLUDED_)
#define AFX_MOCSTEADY_H__CD3C2D89_B8AE_4A7D_922A_4CFEEB2ACCF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcSteady;
class MOCComponentMgr;
class SteadyOutModel;

class MOCSteady  
{
public:
	
	void CheckPress(double dOld, double &dNew);
	void CheckFlow(double dOld,double &dNew);
	void CalcStm(MOCComponentMgr &mgr,SteadyOutModel &model);
	BOOL Read(CalcSteady &data);
	MOCSteady();
	virtual ~MOCSteady();

private:
	BOOL CheckRel(double dOld, double dNew,double dEps);
	BOOL CheckAbs(double dOld, double dNew,double dEps);

private:
	void Result(SteadyOutModel &model,int n);
	void Relaxation(double dOld,double &dNew,double dRax);
	int m_PresTolType;			//压力公差类型标记：0：绝对公差，1，相对公差2，绝对或相对公差3，绝对和相对公差
	double m_PresAbsTol;		//压力绝对公差
	double m_PresRelTol;	    //压力相对公差
	int m_FlowTolType;		    //流量公差类型标记：0：绝对公差，1，相对公差2，绝对或相对公差3，绝对和相对公差
	double m_FlowAbsTol;		//流量绝对公差
	double m_FlowRelTol;		//流量相对公差
	double m_FlowRelaxation;	//流量松弛因子
	double m_PresRelaxation;	//压力松弛因子值
	int m_MaxIterations;		//最大迭代次数值
	BOOL m_bOk;

};

#endif // !defined(AFX_MOCSTEADY_H__CD3C2D89_B8AE_4A7D_922A_4CFEEB2ACCF0__INCLUDED_)
