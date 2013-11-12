// BendData.h: interface for the BendData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BENDDATA_H__B325A443_4137_4B09_9A73_643D9A6DA350__INCLUDED_)
#define AFX_BENDDATA_H__B325A443_4137_4B09_9A73_643D9A6DA350__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//弯管（弯头）
#include "Junction.h"
#include "RowObjectFace.h"

class AFX_EXT_CLASS BendData : public JunctionData  
{
public:
	static JunctionData* Creator();
	BendData();
	virtual ~BendData();
public:
	CString Type();
	void Type(CString strValue);
    CString Angel();
	void Angel(CString strValue);
	CString RD();
	void RD(CString strValue);
	CString K();
	void K(CString strValue);
	StrArray<2> RestriFlowArea();
	void RestriFlowArea(const StrArray<2>& strValue);
	StrArray<3> BasisArea();
	void BasisArea(const StrArray<3>& strValue);
private:
	void AppendArray();
	void InitExtra(CString strData);
	virtual CString GetDefaultData();

private:
	RowObjectFace<1> m_bendType;   //弯头类型（0，为光滑弯头，1为标准弯头，2为Mitre Bend,3,为用户指定）
    RowObjectFace<1> m_angel;      //角度（为多少度）
	RowObjectFace<1> m_rD;          //r/D
	RowObjectFace<1> m_K;			//阻力损失（K）
    RowObjectFace<2> m_RestriFlowArea;  //精确流体面积（Restricted Flow Area)的数字和单位
	RowObjectFace<3> m_BasisArea;		//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
   
};

#endif // !defined(AFX_BENDDATA_H__B325A443_4137_4B09_9A73_643D9A6DA350__INCLUDED_)
