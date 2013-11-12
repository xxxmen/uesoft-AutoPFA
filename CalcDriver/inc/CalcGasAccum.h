// CalcGasAccum.h: interface for the CalcGasAccum class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCGASACCUM_H__8E4F8A55_1BC8_4BB4_87F4_59FC4A5F8381__INCLUDED_)
#define AFX_CALCGASACCUM_H__8E4F8A55_1BC8_4BB4_87F4_59FC4A5F8381__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"
#include "CalcOrifice.h"
#include "CalcShortPipe.h"

class AFX_EXT_CLASS CalcGasAccum : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcGasAccum();
	virtual ~CalcGasAccum();
public:
	void Polytropic(double dValue);
	void Type(int nValue);
	void InitVolume(double dValue);
	void RefPress(double dValue);
	void MaxVolume(double dValue);
	void MinVolume(double dValue);
	void SelInitPress(int nValue);
	void InitPressType(int nValue);
	void InitPress(double dValue);

	double Polytropic();
	int Type();
	double InitVolume();
	double RefPress();
	double MaxVolume();
	double MinVolume();
	int SelInitPress();
	int InitPressType();
	double InitPress();
private:
	double		  m_dPolytropic;					//变化的常量
	int           m_nType;						    //类型（0：初始化指定体积，1：初始化指定压力）
	double	      m_dInitVolume;					//初始化气体体
	double        m_dRefPress;				        //参考气体压力
	double		  m_dMaxVolume;					    //最大体积
	double		  m_dMinVolume;					    //最小体积											
	int			  m_bSelInitPress;					//静态流初试压力（0，没有选，1选中）
	int           m_nInitPressType;					//压力类型（0水头，1：压力）
	double        m_dInitPress;					    //初始化压力

public:
	CalcOrifice   m_Orifice;					
	CalcShortPipe m_ShortPipe;	
};

#endif // !defined(AFX_CALCGASACCUM_H__8E4F8A55_1BC8_4BB4_87F4_59FC4A5F8381__INCLUDED_)
