// PCFAssignFlow.h: interface for the AssignFlowData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFASSIGNFLOW_H__AFC48AF4_8E07_46C7_B693_1640110329E9__INCLUDED_)
#define AFX_PCFASSIGNFLOW_H__AFC48AF4_8E07_46C7_B693_1640110329E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//指定流量
#include "PCFJun.h"
#include "RowObjectFace.h"
#include "JunTransData.h"
#include "Junction.h"

class AFX_EXT_CLASS PCFAssignFlow : public PCFJun  
{
public:
// 	void SetFlowDir( bool dFlowDir );
// 	bool GetFlowDir();
// 	void SetK( double dK );
// 	double GetK();
	CString GetK();
	void SetK(CString strValue);
	StrArray<4> GetAssignInitPress();
	void SetAssignInitPress(const StrArray<4>& strValue);
	CString GetAssignFlowDir();
	void SetAssignFlowDir(CString strValue);

	StrArray<3> GetAssignFlow();
	void SetAssignFlow(const StrArray<3>& strValue);

	static PCFJun* Creator();
	PCFAssignFlow();
	virtual ~PCFAssignFlow();
	void Init( const CStringArray& wordArray );

//	JunTransData m_TranData;
private:
	RowObjectFace<3> m_Flow;				//流量类型\大小\单位
//	bool m_FlowDir;				//0：流体流入，1：流体流出
//	double m_K;					//损失系数；
	RowObjectFace<1> m_FlowDir;				//0：流体流入，1：流体流出
	RowObjectFace<1> m_K;					//损失系数K值	
	//m_TranData
//	RowObjectFace<4> m_InitPress;			//恒定流量为0的初始化压力（0，没有选，-1选中）\压力类型（0水头，1：压力）\压力值\单位
};
#endif // !defined(AFX_PCFASSIGNFLOW_H__AFC48AF4_8E07_46C7_B693_1640110329E9__INCLUDED_)


