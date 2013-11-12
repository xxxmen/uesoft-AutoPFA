// PCFSurge.h: interface for the SurgeData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SURGEDATA_H__D101EBE3_BFC2_4B5A_9C19_6E86EE4A9C29__INCLUDED_)
#define AFX_SURGEDATA_H__D101EBE3_BFC2_4B5A_9C19_6E86EE4A9C29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Junction.h"
#include "PCFJun.h"
//调压塔
class AFX_EXT_CLASS PCFSurge: public PCFJun   
{
public:
	static PCFJun* Creator();
	PCFSurge();
	virtual ~PCFSurge();
public:
	CString DistanceUnit();
	void DistanceUnit(CString strValue);
	StrArray<2> SurgeHeight();
	void SurgeHeight(const StrArray<2>& strValue);
	StrArray<2> ConstArea();
	void ConstArea(const StrArray<2>& strValue);
	StrArray<2> SurfacePress();
	void SurfacePress(const StrArray<2>& strValue);
	StrArray<5> Orifice();
	void Orifice(const StrArray<5>& strValue);
	StrArray<10> ShortPipe();
	void ShortPipe(const StrArray<10>& strValue);
	CString OneWay();
	void OneWay(CString strValue);
	StrArray<4> Vessel();
	void Vessel(const StrArray<4>& strValue);
	CString Variable();
	void Variable(CString strValue);
	StrArray<3> InitSurfaceH();
	void InitSurfaceH(const StrArray<3>& strValue);
	StrArray<5> Check();
	void Check(const StrArray<5>& strValue);

	void Init( const CStringArray& wordArray );
private:
//	void AppendArray();
//	void InitExtra(CString strData);
//	virtual CString GetDefaultData();
public:
//	TwoDTable m_AreaTable;
//	JunTransData m_TranData;	
private:
//	TableData<3> m_linkPipeK;			//流体从节点流入管道时管道端口k系数
										//流体从节点流出管道时管道端口k系数
										//管道端口与节点标高距离
	RowObjectFace<1> m_EleUnit;			//管道端口与节点标高距离单位
	RowObjectFace<2> m_SurgeHeight;			//调压塔的高度\单位
	RowObjectFace<2> m_ConstArea;		//底面积值\单位
	RowObjectFace<2> m_SurfacePress;	//表面压力\单位
	RowObjectFace<5> m_Orifice;			//选中节流孔板模型标记\入流量系数\出流量系数\面积值\单位
	RowObjectFace<10> m_ShortPipe;		    //0：没有选择短管道模型，-1：选择短管道模型
										//短管道摩擦系数
										//短管道内直径
										//短管道内直径单位
										//短管道面积
										//短管道面积单位
										//短管道长度
										//短管道长度单位
										//短管道标高变化
										//短管道标高单位
	RowObjectFace<1> m_OneWay;			//“One-Way Surge Tank”0：没有选择，-1选择来建模有止回阀特征的缓冲罐。
	RowObjectFace<4> m_Vessel;			//模拟文丘里管0：没有选择，-1：选择
										//文丘里管到管道的高度
										//文丘里管高度单位
										//多变的常量
	RowObjectFace<1> m_Variable;		//标记：选择面积恒定0，面积变化1
	//TwoDTable m_AreaTable;				//None（未知）\1（未知）
										//变化面积的数量
										//高度单位\面积单位
										//高度和面积
	RowObjectFace<3> m_InitSurfaceH;	//稳定状态初始化流体高度0：没有选择-1：选择
										//高度值
										//高度单位
	//JunTransData m_TranData;			//没有周期函数RowObjectFace<5> m_Periodic;
    									//没有RowObjectFace<1> m_ValueType;
										//没有RowObjectFace<1> m_Special;
										//没有RowObjectFace<1> m_Repeat1;
										//没有RowObjectFace<1> m_Repeat2
										//没有RowObjectFace<1> m_TranType;
	                                    //AFT文件的Bug界面上数据不能保存到文件
	RowObjectFace<5> m_CheckValve;		//止回阀流量系数
										//止回阀初始位置0：打开1：关闭
										//打开阀门Delta压力或水头的压力类型0：水头1：压力
										//压力值
										//压力单位


};

#endif // !defined(AFX_SURGEDATA_H__D101EBE3_BFC2_4B5A_9C19_6E86EE4A9C29__INCLUDED_)
