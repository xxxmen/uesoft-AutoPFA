// ControlPerisist.h: interface for the ControlPerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTROLPERISIST_H__5BE02207_70F9_4D10_BFB0_6E0CBE1CA78F__INCLUDED_)
#define AFX_CONTROLPERISIST_H__5BE02207_70F9_4D10_BFB0_6E0CBE1CA78F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junperisist.h"
#include "TransDataPersistent.h"

class AFX_EXT_CLASS ControlPerisist : public Junperisist  
{
public:
	static Junperisist* CreatControlValve();
	ControlPerisist();
	virtual ~ControlPerisist();

public:
	StrArray<5>& ControlSet();
	void ControlSet(const StrArray<5>& strValue);
	CString ModelType();
	void ModelType(CString strValue);
	CString KOrCv();
	void KOrCv(CString strValue);
	StrArray<4>& FailAction();
	void FailAction(const StrArray<4>& strValue);
private:
	StrArray<5> m_ControlSet;					//阀门类型0：PRF 1：PSV 2：FCV 3：PDCV
												//控制点参数类型0：水头/水头损失/体积流量1：压力/压力损失/质量流量
												//0：停滞压力1：静态压力
												//控制点参数值
												//控制点参数单位
	CString		m_ModelType;					//损失模型(0：流量系数模型，1：K系数模型 -2：使用系数表的值)
	CString		m_KOrCv;						//K或Cv系数值
	StrArray<4> m_failAction;					//稳定状态总是控制0：没有选择 1：选择
												//使用默认的行为  0：没有选择 1：选择
												//上游压力不足表现0：全部打开 1：关闭
												//下游压力超过表现0：全部打开 1：关闭
public:

	TransDataPersistent m_TransPersistent;
	TransDataPersistent m_FailTransPersistent;
	ThreeDTablePersistent m_KOrCvData;
};
/*------------------------------------------*/
inline StrArray<5>& ControlPerisist::ControlSet()
{
	return m_ControlSet;
}
inline void ControlPerisist::ControlSet(const StrArray<5>& strValue)
{
	m_ControlSet = strValue;
}
/*------------------------------------------*/
inline CString ControlPerisist::ModelType()
{
	return m_ModelType;
}
inline void ControlPerisist::ModelType(CString strValue)
{
	m_ModelType = strValue;
}
/*------------------------------------------*/
inline CString ControlPerisist::KOrCv()
{
	return m_KOrCv;
}
inline void ControlPerisist::KOrCv(CString strValue)
{
	m_KOrCv = strValue;
}
/*------------------------------------------*/
inline StrArray<4>& ControlPerisist::FailAction()
{
	return m_failAction;
}
inline void ControlPerisist::FailAction(const StrArray<4>& strValue)
{
	m_failAction = strValue;
}
#endif // !defined(AFX_CONTROLPERISIST_H__5BE02207_70F9_4D10_BFB0_6E0CBE1CA78F__INCLUDED_)
