// AssignFlowPerisist.h: interface for the AssignFlowPerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ASSIGNFLOWPERISIST_H__EA75D8C4_CFC6_4A36_A33B_76CD6904369A__INCLUDED_)
#define AFX_ASSIGNFLOWPERISIST_H__EA75D8C4_CFC6_4A36_A33B_76CD6904369A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junperisist.h"
#include "TransDataPersistent.h"

class AFX_EXT_CLASS AssignFlowPerisist : public Junperisist  
{
public:
	static Junperisist* CreatAssignedFlow();
	AssignFlowPerisist();
	virtual ~AssignFlowPerisist();
public:
	StrArray<3>& Flow();
	void Flow(const StrArray<3>& strValue);
	CString FlowDir();
	void FlowDir(CString strValue);
	CString K();
	void K(CString strValue);
	StrArray<4>& InitPress();
	void InitPress(const StrArray<4>& strValue);
private:
	StrArray<3>  m_Flow;				//流量类型\大小\单位
	CString      m_FlowDir;				//0：流体流入，1：流体流出
	CString      m_K;					//损失系数K值
	StrArray<4>  m_InitPress;			////恒定流量为0的初始化压力（0，没有选，-1选中）\压力类型（0水头，1：压力）\压力值\单

public:
	TransDataPersistent m_TransPersistent;
};
/*------------------------------------------*/
inline StrArray<3>& AssignFlowPerisist::Flow()
{
	return m_Flow;
}
inline void AssignFlowPerisist::Flow(const StrArray<3>& strValue)
{
	m_Flow = strValue;
}

/*------------------------------------------*/
inline CString AssignFlowPerisist::FlowDir()
{
	return m_FlowDir;
}
inline void AssignFlowPerisist::FlowDir(CString strValue)
{
	m_FlowDir = strValue;
}
/*------------------------------------------*/
inline CString AssignFlowPerisist::K()
{
	return m_K;
}
inline void AssignFlowPerisist::K(CString strValue)
{
	m_K = strValue;
}
/*------------------------------------------*/
inline StrArray<4>& AssignFlowPerisist::InitPress()
{
	return m_InitPress;
}
inline void AssignFlowPerisist::InitPress(const StrArray<4>& strValue)
{
	m_InitPress = strValue;
}
#endif // !defined(AFX_ASSIGNFLOWPERISIST_H__EA75D8C4_CFC6_4A36_A33B_76CD6904369A__INCLUDED_)
