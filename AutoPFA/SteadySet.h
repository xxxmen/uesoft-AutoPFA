// SteadySet.h: interface for the SteadySet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STEADYSET_H__7E8F7071_57AC_494B_AA4D_B784B06362A7__INCLUDED_)
#define AFX_STEADYSET_H__7E8F7071_57AC_494B_AA4D_B784B06362A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ScenarioObject.h"
class SteadyPersistent;

class SteadySet : public ScenarioObject  
{
public:
	BOOL Read(SteadyPersistent &persistent);
	BOOL Save(SteadyPersistent &persistent);
	void SaveData();
	void InitData();
	static void Instance();
	NameArray& GetArray();
	int GetType();
	static ScenarioObject* CreatSteadySet();
	SteadySet();
	virtual ~SteadySet();
public:
	BOOL IsDefine();
	int AnalysisType();
	void AnalysisType(int nType);
	static StrFlyWeight ms_AnalysisType;	//计算分析类型数字标记：0：瞬态分析，1：稳态分析
	static StrFlyWeight ms_PresTolType;		//压力公差类型标记：0：绝对公差，1，相对公差2，绝对或相对公差3，绝对和相对公差		
	static NumFlyWeight ms_PresAbsTol;		//压力绝对公差
	static StrFlyWeight ms_PresRelTol;		//压力相对公差
	static StrFlyWeight ms_FlowTolType;		//流量公差类型标记：0：绝对公差，1，相对公差2，绝对或相对公差3，绝对和相对公差
	static NumFlyWeight ms_FlowAbsTol;		//流量绝对公差
	static StrFlyWeight ms_FlowRelTol;		//流量相对公差
	static StrFlyWeight ms_FlowRelaxation;	//流量松弛因子
	static StrFlyWeight ms_PresRelaxation;	//松弛因子值
	static StrFlyWeight ms_MaxIterations;	//最大迭代次数值
	static StrFlyWeight ms_KeepHistory;		//0：不保存迭代历史记录，1，保存迭代历史记录
	static StrFlyWeight ms_MatrixMethod;	//求解线性方程组方法0：高斯消去法，1：选主元素的高斯消去法，2：矩阵的三角分解（LU分解）
	static StrFlyWeight ms_AutoDetect;		//保存迭代历史记录迭代间隔

	static const CmbDataItem ms_Method[3];
private:
    static NameArray s_StateName;
	ScenarioObject* DoClone();
};
inline int SteadySet::GetType()
{
	return 20;
}

inline NameArray& SteadySet::GetArray()
{
	return s_StateName;
}
#endif // !defined(AFX_STEADYSET_H__7E8F7071_57AC_494B_AA4D_B784B06362A7__INCLUDED_)
