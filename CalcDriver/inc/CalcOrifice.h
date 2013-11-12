// CalcOrifice.h: interface for the CalcOrifice class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCORIFICE_H__EB3C8E89_264E_4708_98F4_13D4A0284240__INCLUDED_)
#define AFX_CALCORIFICE_H__EB3C8E89_264E_4708_98F4_13D4A0284240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS CalcOrifice  
{
public:
	CalcOrifice();
	virtual ~CalcOrifice();
public:
	void Model(int nValue);
	void InFlowCD(double dValue);
	void OutFlowCD(double dValue);
	void Area(double dValue);
	
	int Model();
	double InFlowCD();
	double OutFlowCD();
	double Area();
    friend	ostream& operator<< (ostream &CalcOut,const CalcOrifice &ref);

private:
	int	    m_bModel;					//0：没有选择节流孔板模型，1：选择节流孔板模型
	double	m_dInFlowCD;				//孔口输入流量系数
	double	m_dOutFlowCD;				//孔口输出流量系数
	double	m_dArea;					//孔口面积值
	
};

#endif // !defined(AFX_CALCORIFICE_H__EB3C8E89_264E_4708_98F4_13D4A0284240__INCLUDED_)
