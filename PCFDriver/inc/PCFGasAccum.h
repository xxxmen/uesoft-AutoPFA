// PCFGasAccum.h: interface for the PCFGasAccum class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFGASACCUM_H__84567B8D_01F4_4FBE_AE5A_2CEA60C6E13E__INCLUDED_)
#define AFX_PCFGASACCUM_H__84567B8D_01F4_4FBE_AE5A_2CEA60C6E13E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//空气罐
#include "Junction.h"
#include "PCFJun.h"

class AFX_EXT_CLASS PCFGasAccum : public PCFJun  
{
public:
	static PCFJun* Creator();
	PCFGasAccum();
	virtual ~PCFGasAccum();
public:
	CString Polytropic();
	void Polytropic(CString strValue);
	StrArray<2> InitVolume();
	void InitVolume(const StrArray<2>& strValue);
	StrArray<5> Orifice();
	void Orifice(const StrArray<5>& strValue);
	StrArray<10> ShortPipe();
	void ShortPipe(const StrArray<10>& strValue);
	StrArray<4> InitPress();
	void InitPress(const StrArray<4>& strValue);
	CString MaxVolume();
	void MaxVolume(CString strValue);
	CString MinVolume();
	void MinVolume(CString strValue);
	StrArray<3> GasVolume();
	void GasVolume(const StrArray<3>& m_GasVolume);

	void Init( const CStringArray& wordArray );
private:
	
private:
	RowObjectFace<1> m_Polytropic;			//变化的常量
	RowObjectFace<2> m_InitVolume;			//初始化气体体积
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
	RowObjectFace<4> m_InitPress;       //0:没有选中设置静态流初试压力，-1:没有选中设置静态流初试压力
	//0：压力类型为水头，1：压力类型为压力
	//压力大小\单位
	RowObjectFace<1> m_MaxVolume;		//最大体积
	RowObjectFace<1> m_MinVolume;		//最小体积
	RowObjectFace<3> m_GasVolume;		//类型（0：初始化指定体积，1：初始化指定压力）
	//初始化气体压力
	//初始化气体压力单位
};

#endif // !defined(AFX_PCFGASACCUM_H__84567B8D_01F4_4FBE_AE5A_2CEA60C6E13E__INCLUDED_)
