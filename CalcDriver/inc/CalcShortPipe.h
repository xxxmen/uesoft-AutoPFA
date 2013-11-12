// CalcShortPipe.h: interface for the CalcShortPipe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCSHORTPIPE_H__D678D756_7266_4EDD_8F4C_C79898364566__INCLUDED_)
#define AFX_CALCSHORTPIPE_H__D678D756_7266_4EDD_8F4C_C79898364566__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS CalcShortPipe  
{
public:
	CalcShortPipe();
	virtual ~CalcShortPipe();
public:
	void Model(int nValue);
	void Friction(double dValue);
	void Area(double dValue);
	void InDia(double dValue);
	void Len(double dValue);
	void Ele(double dValue);

	int Model();
	double Friction();
	double Area();
	double InDia();
	double Len();
	double Ele();
    friend	ostream& operator<< (ostream &CalcOut,const CalcShortPipe &ref);
private:
	int		m_bModel;				//0：没有选择短管道模型，1：选择短管道模型
	double	m_dFriction;			//短管道摩擦系数
	double	m_dArea;				//短管道面积
	double	m_dInDia;				//短管道内直径
	double	m_dLen;					//短管道长度
	double	m_dEle;					//短管道标高变化
};

#endif // !defined(AFX_CALCSHORTPIPE_H__D678D756_7266_4EDD_8F4C_C79898364566__INCLUDED_)
