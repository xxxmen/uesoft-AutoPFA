// BrachData.h: interface for the BrachData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BRACHDATA_H__6F8FC7E4_7841_4B83_9626_773A27530C7C__INCLUDED_)
#define AFX_BRACHDATA_H__6F8FC7E4_7841_4B83_9626_773A27530C7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Junction.h"
#include "JunTransData.h"
//分支元件
class AFX_EXT_CLASS BrachData : public JunctionData  
{
public:
	static JunctionData* Creator();
	BrachData();
	virtual ~BrachData();
public:
	ListImp<StrArray<4> > PipeInfo();
	void PipeInfo(const ListImp<StrArray<4> >& strValue);
	StrArray<3> ImposeFlow();
	void ImposeFlow(const StrArray<3>& strValue);
	CString DistanceUnit();
	void DistanceUnit(CString strValue);

private:
	void AppendArray();
	void InitExtra(CString strData);
	virtual CString GetDefaultData();

public:
    JunTransData m_TranData;			//没有周期函数RowObjectFace<5> m_Periodic;
private:
	TableData<3> m_linkPipeK;			//52、流体从节点流入管道时管道端口k系数
										//53、流体从节点流出管道时管道端口k系数
										//54、管道端口与节点标高距离
	RowObjectFace<3> m_ImposeFlow;		//流量类型\大小\单位
	RowObjectFace<1> m_EleUnit;			//管道端口与节点标高距离单位
	//JunTransData m_TranData;			//没有周期函数RowObjectFace<5> m_Periodic;
	RowObjectFace<3> m_FthSourceTempture;  //是否选择/大小/单位
	RowObjectFace<1> m_FthUnknow;          //none


	
};

#endif // !defined(AFX_BRACHDATA_H__6F8FC7E4_7841_4B83_9626_773A27530C7C__INCLUDED_)
