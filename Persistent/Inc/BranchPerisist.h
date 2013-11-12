// BranchPerisist.h: interface for the BranchPerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BRANCHPERISIST_H__DAE2F2A5_7062_45B1_BE7E_966562E988C7__INCLUDED_)
#define AFX_BRANCHPERISIST_H__DAE2F2A5_7062_45B1_BE7E_966562E988C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junperisist.h"
#include "TransDataPersistent.h"

class AFX_EXT_CLASS BranchPerisist : public Junperisist  
{
public:
	static Junperisist* CreatBranch();
	BranchPerisist();
	virtual ~BranchPerisist();
public:
	ListImp<StrArray<4> >& PipeInfoToStd();
	ListImp<StrArray<4> >& PipeInfo();
	void PipeInfo(const ListImp<StrArray<4> >& strValue,int nCount);
	void PipeInfo(const ListImp<StrArray<4> >& strValue);
	StrArray<3>& ImposeFlow();
	void ImposeFlow(const StrArray<3>& strValue);
	CString DistanceUnit();
	void DistanceUnit(CString strValue);

private:
	TablePerisist<4> m_PipeInfo;
	StrArray<3>		 m_ImposeFlow;				//流量类型（0：体积流量，1：质量流量）\大小\单位
	CString			 m_DistanceUnit;
public:
	TransDataPersistent m_TransPersistent;


};
inline ListImp<StrArray<4> >& BranchPerisist::PipeInfo()
{
	return m_PipeInfo.GetData();
}
inline void BranchPerisist::PipeInfo(const ListImp<StrArray<4> >& strValue,int nCount)
{
	m_PipeInfo.SetData(strValue,nCount);
}
inline void BranchPerisist::PipeInfo(const ListImp<StrArray<4> >& strValue)
{
	m_PipeInfo.SetData(strValue);
}
/*------------------------------------------*/
inline CString BranchPerisist::DistanceUnit()
{
	return m_DistanceUnit;
}
inline void BranchPerisist::DistanceUnit(CString strValue)
{
	m_DistanceUnit = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& BranchPerisist::ImposeFlow()
{
	return m_ImposeFlow;
}
inline void BranchPerisist::ImposeFlow(const StrArray<3>& strValue)
{
	m_ImposeFlow = strValue;
}
#endif // !defined(AFX_BRANCHPERISIST_H__DAE2F2A5_7062_45B1_BE7E_966562E988C7__INCLUDED_)
