// SteadyPersistent.h: interface for the SteadyPersistent class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：SteadyPersistent.h
  摘要： 恒定流计算控制参数  
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STEADYPERSISTENT_H__F5A87801_8F0B_4008_AC47_557078FB06C6__INCLUDED_)
#define AFX_STEADYPERSISTENT_H__F5A87801_8F0B_4008_AC47_557078FB06C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS SteadyPersistent  
{
public:
	SteadyPersistent();
	virtual ~SteadyPersistent();

	CString AnalysisType();
	void AnalysisType(CString strValue);
	CString PresTolType();
	void PresTolType(CString strValue);
	StrArray<2>& PresAbsTol();
	void PresAbsTol(const StrArray<2>& strValue);
	CString PresRelTol();
	void PresRelTol(CString strValue);
	CString FlowTolType();
	void FlowTolType(CString strValue);
	StrArray<2>& FlowAbsTol();
	void FlowAbsTol(const StrArray<2>& strValue);
	CString FlowRelTol();
	void FlowRelTol(CString strValue);
	CString RelaxationType();
	void RelaxationType(CString strValue);
	CString FlowRelaxation();
	void FlowRelaxation(CString strValue);
	CString PresRelaxation();
	void PresRelaxation(CString strValue);
	CString MaxIterations();
	void MaxIterations(CString strValue);
	CString KeepHistory();
	void KeepHistory(CString strValue);
	CString MatrixMethod();
	void MatrixMethod(CString strValue);
	CString AutoDetect();
	void AutoDetect(CString strValue);

private:
	CString m_AnalysisType;			//计算分析类型数字标记：0：瞬态分析，1：稳态分析
	CString m_PresTolType;			//压力公差类型标记：0：绝对公差，1，相对公差2，绝对或相对公差3，绝对和相对公差		
	StrArray<2> m_PresAbsTol;		//压力绝对公差
	CString m_PresRelTol;			//压力相对公差
	CString m_FlowTolType;			//流量公差类型标记：0：绝对公差，1，相对公差2，绝对或相对公差3，绝对和相对公差
	StrArray<2> m_FlowAbsTol;		//流量绝对公差
	CString m_FlowRelTol;			//流量相对公差
	CString m_RelaxationType;
	CString m_FlowRelaxation;		//流量松弛因子
	CString m_PresRelaxation;		//松弛因子值
	CString m_MaxIterations;		//最大迭代次数值
	CString m_KeepHistory;			//0：不保存迭代历史记录，1，保存迭代历史记录
	CString m_MatrixMethod;			//求解线性方程组方法0：高斯消去法，1：选主元素的高斯消去法，2：矩阵的三角分解（LU分解）
	CString m_AutoDetect;			//保存迭代历史记录迭代间隔

};

/*------------------------------------------*/
inline CString SteadyPersistent::AnalysisType()
{
	return m_AnalysisType;
}
inline void SteadyPersistent::AnalysisType(CString strValue)
{
	m_AnalysisType = strValue;
}
/*------------------------------------------*/
inline CString SteadyPersistent::PresTolType()
{
	return m_PresTolType;
}
inline void SteadyPersistent::PresTolType(CString strValue)
{
	m_PresTolType = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& SteadyPersistent::PresAbsTol()
{
	return m_PresAbsTol;
}
inline void SteadyPersistent::PresAbsTol(const StrArray<2>& strValue)
{
	m_PresAbsTol = strValue;
}
/*------------------------------------------*/
inline CString SteadyPersistent::PresRelTol()
{
	return m_PresRelTol;
}
inline void SteadyPersistent::PresRelTol(CString strValue)
{
	m_PresRelTol = strValue;
}
/*------------------------------------------*/
inline CString SteadyPersistent::FlowTolType()
{
	return m_FlowTolType;
}
inline void SteadyPersistent::FlowTolType(CString strValue)
{
	m_FlowTolType = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& SteadyPersistent::FlowAbsTol()
{
	return m_FlowAbsTol;
}
inline void SteadyPersistent::FlowAbsTol(const StrArray<2>& strValue)
{
	m_FlowAbsTol = strValue;
}
/*------------------------------------------*/
inline CString SteadyPersistent::FlowRelTol()
{
	return m_FlowRelTol;
}
inline void SteadyPersistent::FlowRelTol(CString strValue)
{
	m_FlowRelTol = strValue;
}
/*------------------------------------------*/
inline CString SteadyPersistent::RelaxationType()
{
	return m_RelaxationType;
}
inline void SteadyPersistent::RelaxationType(CString strValue)
{
	m_RelaxationType = strValue;
}
/*------------------------------------------*/
inline CString SteadyPersistent::FlowRelaxation()
{
	return m_FlowRelaxation;
}
inline void SteadyPersistent::FlowRelaxation(CString strValue)
{
	m_FlowRelaxation = strValue;
}
/*------------------------------------------*/
inline CString SteadyPersistent::PresRelaxation()
{
	return m_PresRelaxation;
}
inline void SteadyPersistent::PresRelaxation(CString strValue)
{
	m_PresRelaxation = strValue;
}
/*------------------------------------------*/
inline CString SteadyPersistent::MaxIterations()
{
	return m_MaxIterations;
}
inline void SteadyPersistent::MaxIterations(CString strValue)
{
	m_MaxIterations = strValue;
}
/*------------------------------------------*/
inline CString SteadyPersistent::KeepHistory()
{
	return m_KeepHistory;
}
inline void SteadyPersistent::KeepHistory(CString strValue)
{
	m_KeepHistory = strValue;
}
/*------------------------------------------*/
inline CString SteadyPersistent::MatrixMethod()
{
	return m_MatrixMethod;
}
inline void SteadyPersistent::MatrixMethod(CString strValue)
{
	m_MatrixMethod = strValue;
}
/*------------------------------------------*/
inline CString SteadyPersistent::AutoDetect()
{
	return m_AutoDetect;
}
inline void SteadyPersistent::AutoDetect(CString strValue)
{
	m_AutoDetect = strValue;
}
#endif // !defined(AFX_STEADYPERSISTENT_H__F5A87801_8F0B_4008_AC47_557078FB06C6__INCLUDED_)
