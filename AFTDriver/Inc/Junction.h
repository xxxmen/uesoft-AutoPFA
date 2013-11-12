// Junction.h: interface for the JunctionData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUNCTION_H__C69BB6F7_C789_4A29_92EC_342E3829BA9B__INCLUDED_)
#define AFX_JUNCTION_H__C69BB6F7_C789_4A29_92EC_342E3829BA9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PersistentObj.h"
#include "ListFlyWeightImp.h"
#include "RowObjectFace.h"

class AFX_EXT_CLASS JunctionData: public PersistentObj
{
public:
	ListImp<StrArray<1> > PipeID();
	void PipeID(ListImp<StrArray<1> >& list);
	int Key();
	int ID();
	CString Name();
	CString CenterPtX();
	CString CenterPtY();
	CString InEle();
	CString OutEle();
	CString EleUnit();
	CString RawKey();

	void RawKey(CString strValue);
	void InEle(CString strValue);
	void OutEle(CString strValue);
	void EleUnit(CString strValue);
	void Key(int iKey);
	void ID(int iID);
	void Name(CString strValue);
	void CenterPtX(CString strValue);
	void CenterPtY(CString strValue);
	CString DesignFactor();
	void DesignFactor(CString strValue);
	StrArray<3> InitGuess();
	void InitGuess(const StrArray<3>& strValue);
	StrArray<3> SpecialMark();
	void SpecialMark(const StrArray<3>& strValue);
public:
	void Init();
	BOOL Save(CStdioFile &file);
	BOOL Read(CStdioFile &file);
	BOOL Read(CString strData);
	JunctionData();
	virtual ~JunctionData();
protected:
	int PipeNum();
private:
	BOOL IsSameInEle();
	void InitData(CString strData);
	virtual void InitExtra(CString strData)=0;
	virtual CString GetDefaultData()=0;
	void InitArray();
	RowObjectFace<1>  m_TypeID;			//节点类型标记ID
	RowObjectFace<1>  m_Number;            //节点元件编号
	RowObjectFace<1>  m_UnKown1;           //9
	RowObjectFace<1>  m_UnKown2;			//1
	RowObjectFace<1>  m_Name;				//名称
	RowObjectFace<1>  m_PipeNum;            //连接管道数量
	TableData<1>      m_PipeArray;		    //与节点连接的管道表
	RowObjectFace<2>  m_CenterPt;			//坐标
	RowObjectFace<1>  m_JunSize;			//图形尺寸
	RowObjectFace<2>  m_JunState;		    //位图的方向\在一系列图标中的位置
	RowObjectFace<1>  m_JunPipeMark;       //管道连接完成
	RowObjectFace<1>  m_LockMark;			//0表示没有锁定图形-1表示锁定图形
public:
	RowObjectFace<3>  m_EleArray;			//节点入口\出口标高\单位
	//读fth文件时,水库中的标高不是公共数据,要在水库里面读取这里设为public使其可以在ReserviorData里面访问.
	//change by wenzk
private:
	RowObjectFace<5>  m_UnKown3;           //0\0\0\0\none(第一个参数为出口标高是否与入口标高相同)
	RowObjectFace<1>  m_DisignFactor;		//设计因子损失
	RowObjectFace<3>  m_InitGuess;			//初始化流体猜测类型（0，1）\大小\单位
	RowObjectFace<3>  m_UnKown4;           //0\none\0
	RowObjectFace<1>  m_HandBook;			//阀门数据库手册数据
	RowObjectFace<1>  m_PumpConfig;		    //[RAW DATA SETS]和[RAW DATA REFERENCES]的标记
	RowObjectFace<3>  m_SpecialMark;		//指定特别条件类型标记(3)
	RowObjectFace<1>  m_UnKown5;			//1		
	RowObjectFace<4>  m_LabLocation;		//工作区文字显示位置(4)
	RowObjectFace<1>  m_Display;			//工作区显示
	RowObjectFace<4>  m_UnKown6;			//5\-1\-1\25
	RowObjectFace<2>  m_notes;				//notes字符的个数\notes的内容
	RowObjectFace<2>  m_UnKown7;			//1\-1
	RowObjectFace<5>  m_Font;				//字体设置5

	RowObjectFace<1>  m_UnKown9;			//0/2  未知
	RowObjectFace<1>  m_UnKown10;			//999  未知
	RowObjectFace<2> m_Fth1;                // 未知 -1 3
	RowObjectFace<1> m_Fth2; 				//数据库费用 0 选中数据库; 1 所有数据库(默认)
	RowObjectFace<1> m_Fth3; 				//%ALL% 所有数据库(只有m_Fth2为1时才会多这一项)
	RowObjectFace<1> m_Fth4; 				//虚拟数据库费用 0 选中数据库; 1 所有数据库(默认) (如果是泵则才会多这一项)
	RowObjectFace<1> m_Fth5; 				//%ALL% 所有数据库(只有m_Fth4为1时才会多这一项) (如果是泵则才会多这一项)
	RowObjectFace<1> m_Fth6; 				//增效器显示行数 3 其它元件; 4 泵时
	RowObjectFace<1> m_Fth7; 				//增效器度量单位 Decimal/Percent
	TableData<1>     m_FthArray;		    //跟据m_Fth6项的值的2倍而定共有几项 即 3*2/4*2,为对应增效器行的里数据
	RowObjectFace<1> m_Fth8;                //未知 0
	RowObjectFace<4> m_Fth9;                //服务期限 计时单位 开始时间 结束时间
};

#endif // !defined(AFX_JUNCTION_H__C69BB6F7_C789_4A29_92EC_342E3829BA9B__INCLUDED_)
