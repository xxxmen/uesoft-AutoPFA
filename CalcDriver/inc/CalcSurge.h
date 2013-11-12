// CalcSurge.h: interface for the CalcSurge class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCSURGE_H__871F151C_432F_441D_B83C_90D5C5559CC4__INCLUDED_)
#define AFX_CALCSURGE_H__871F151C_432F_441D_B83C_90D5C5559CC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalcJun.h"
#include "CalcOrifice.h"
#include "CalcShortPipe.h"
#include "CalcTransData.h"

class AFX_EXT_CLASS CalcSurge : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcSurge();
	virtual ~CalcSurge();
public:
	void PipeInfo(const ListImp<StrArray<4> >& ref);
	void AreaTable(const ListImp<StrArray<2> >& ref);
	void SurfacePress(double dValue);
	void SurgeHeight(double dValue);
	void ConstArea(double dValue);
	void OneWay(int nValue);
	void CheckCv(double dValue);
	void Position(int nValue);
	void ReOpenPressType(int nValue);
	void ReOpenPress(double dValue);
	void SelVessel(int nValue);
	void VesselHeight(double dValue);
	void Polytropic(double dValue);
	void SelSurfaceH(int nValue);
	void InitSurfaceH(double dValue);


	ListImp<StrArray<4> >& PipeInfo();
	ListImp<StrArray<2> >& AreaTable();
	double SurfacePress();
	double SurgeHeight();
	double ConstArea();
	int OneWay();
	double CheckCv();
	int Position();
	int ReOpenPressType();
	double ReOpenPress();
	int SelVessel();
	double VesselHeight();
	double Polytropic();
	int SelSurfaceH();
	double InitSurfaceH();
private:
    CalcTable<4>	 m_PipeInfo;
	double			 m_dSurfacePress;				//表面压力
	double			 m_dSurgeHeight;				//调压塔的高度
	double			 m_dConstArea;					//底面积值
	CalcTable<2>     m_AreaTable;			
	int 			 m_bOneWay;						//“One-Way Surge Tank”0：没有选择，1选择来建模有止回阀特征的缓冲罐。
	double           m_dCheckCv;						//止回阀流量系数
	int              m_nPosition;					//止回阀初始位置0：打开1：关闭
	int				 m_nReOpenPressType;			//重新打开阀门Delta(压力或水头)0：水头1：压力
	double	         m_dReOpenPress;				//压力值         
	int     		 m_bSelVessel;					//模拟文丘里管0：没有选择，1：选择
	double           m_dVesselHeight;				//文丘里管到管道的高度
	double			 m_dPolytropic;					//多变的常量
	int              m_bSelSurfaceH;				//稳定状态初始化流体高度0：没有选择1：选择
	double			 m_dInitSurfaceH;	        	//高度值	
													
public:
	CalcOrifice		 m_Orifice;					
	CalcShortPipe	 m_ShortPipe;
	CalcTransData	 m_TranData;
										
};

#endif // !defined(AFX_CALCSURGE_H__871F151C_432F_441D_B83C_90D5C5559CC4__INCLUDED_)
