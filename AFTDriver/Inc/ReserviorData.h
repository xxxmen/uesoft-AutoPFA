// ReserviorData.h: interface for the ReserviorData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RESERVIORDATA_H__656463BB_6674_44FE_986F_9F5AF78E7037__INCLUDED_)
#define AFX_RESERVIORDATA_H__656463BB_6674_44FE_986F_9F5AF78E7037__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//水库
#include "Junction.h"
#include "JunTransData.h"

class AFX_EXT_CLASS ReserviorData : public JunctionData  
{
public:
	static JunctionData* Creator();
	ReserviorData();
	virtual ~ReserviorData();
public:
	ListImp<StrArray<6> > PipeInfo();
	void PipeInfo(const ListImp<StrArray<6> >& strValue);
	StrArray<2> EleOrDepth();
	void EleOrDepth(const StrArray<2>& strValue);
	StrArray<2> SurfacePress();
	void SurfacePress(const StrArray<2>& strValue);
	StrArray<2> Teamperature();
	void Teamperature(const StrArray<2>& strValue);
	StrArray<2> Density();
	void Density(const StrArray<2>& strValue);
	CString EleOrDepthType();
	void EleOrDepthType(CString strValue);
private:
	void AppendArray();
	void InitExtra(CString strData);
	virtual CString GetDefaultData();
public:
	JunTransData m_TranData;	
private:
	TableData<5> m_linkPipeK;			//流体从节点流入管道时管道端口k系数
										//流体从节点流出管道时管道端口k系数
										//管口类型（0：用户，1：锐角出口，2：圆角出口，3：锐角突边出口）
										//r/d
										//管道标高或深度值
	RowObjectFace<2> m_EleOrDepth;		//管道标高或深度\单位
	RowObjectFace<2> m_SurfacePress;	//表面压力值\单位
	RowObjectFace<2> m_Teamperature;	//流体温度\单位
	RowObjectFace<2> m_Density;			//流体密度\单位
	RowObjectFace<2> m_UnKown;			//0（未知）\0（未知）
	RowObjectFace<1> m_EleOrDepthType;	//管道标高或深度(-1,0)
	//JunTransData m_TranData;			//没有周期函数RowObjectFace<5> m_Periodic;
	RowObjectFace<5>  m_Fth2_1;         //
	RowObjectFace<14> m_Fth2;           //和上面的这两个中间的数据记录了水库的标高.
	RowObjectFace<2>  m_Fth3;

};

#endif // !defined(AFX_RESERVIORDATA_H__656463BB_6674_44FE_986F_9F5AF78E7037__INCLUDED_)
