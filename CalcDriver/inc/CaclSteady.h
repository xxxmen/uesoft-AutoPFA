// CaclSteady.h: interface for the CaclSteady class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CACLSTEADY_H__E2CEC3AA_ECC3_4D29_95D0_AD323F9F2C3B__INCLUDED_)
#define AFX_CACLSTEADY_H__E2CEC3AA_ECC3_4D29_95D0_AD323F9F2C3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS CalcSteady  
{
public:
	CalcSteady();
	virtual ~CalcSteady();

public:
	int AnalysisType();
	void AnalysisType(int nValue);
	void PresTolType(int nValue);
	void PresAbsTolType(int nValue);
	void PresAbsTol(double dValue);
	void PresRelTol(double dValue);
	void FlowTolType(int nValue);
	void FlowAbsTolType(int nValue);
	void FlowAbsTol(double dValue);
	void FlowRelTol(double dValue);
	void MaxIterations(int nValue);
	void KeepHistory(int nValue);
	void FlowRelaxation(double dValue);
	void PresRelaxation(double dValue);

	double FlowRelaxation();
	double PresRelaxation();
	int PresTolType();
	int PresAbsTolType();
	double PresAbsTol();
	double PresRelTol();
	int FlowTolType();
	int FlowAbsTolType();
	double FlowAbsTol();
	double FlowRelTol();
	int MaxIterations();
	int KeepHistory();
	friend ostream& operator<< (ostream &CalcOut,const CalcSteady &ref);
	
private:
	int m_AnalysisType;			//计算分析类型数字标记：0：瞬态分析，1：稳态分析
	int m_PresTolType;			//压力公差类型标记：0：绝对公差，1，相对公差2，绝对或相对公差3，绝对和相对公差
	int m_PresAbsTolType;        //压力类型
	double m_PresAbsTol;		//压力绝对公差
	double m_PresRelTol;	    //压力相对公差
	int m_FlowTolType;		    //流量公差类型标记：0：绝对公差，1，相对公差2，绝对或相对公差3，绝对和相对公差
	int m_FlowAbsTolType;        //流量类型
	double m_FlowAbsTol;		//流量绝对公差
	double m_FlowRelTol;		//流量相对公差
//	int m_RelaxationType;
	double m_FlowRelaxation;	//流量松弛因子
	double m_PresRelaxation;	//压力松弛因子值
	int m_MaxIterations;		//最大迭代次数值
	int m_KeepHistory;			//0：不保存迭代历史记录，1，保存迭代历史记录
//	int m_MatrixMethod;			//求解线性方程组方法0：高斯消去法，1：选主元素的高斯消去法，2：矩阵的三角分解（LU分解）
//	int m_AutoDetect;			//保存迭代历史记录迭代间隔
	int m_bUserGiveSteadyInitValue;

};

#endif // !defined(AFX_CACLSTEADY_H__E2CEC3AA_ECC3_4D29_95D0_AD323F9F2C3B__INCLUDED_)
