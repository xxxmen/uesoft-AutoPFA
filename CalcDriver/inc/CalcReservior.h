// CalcReservior.h: interface for the CalcReservior class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCRESERVIOR_H__1860353A_C9A0_4EA6_9BFD_4F1E22BBAC44__INCLUDED_)
#define AFX_CALCRESERVIOR_H__1860353A_C9A0_4EA6_9BFD_4F1E22BBAC44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CalcTable.h"
#include "CalcJun.h"
#include "CalcTransData.h"

class AFX_EXT_CLASS CalcReservior : public CalcJun  
{
public:
	ostream& Write(ostream& CalcOut);
	static CalcJun* Creator();
	CalcReservior();
	virtual ~CalcReservior();

public:
	void EleOrDepthType(int nValue);
	void SurfacePress(double dValue);
	void PipeInfo(const ListImp<StrArray<6> >& ref);

	int EleOrDepthType();
	double SurfacePress();
	ListImp<StrArray<6> >& PipeInfo();
private:
	double		 m_dSurfacePress;				//表面压力值
	int			 m_nEleOrDepthType;			    //管道与水库连接点标高或深度
	CalcTable<6> m_PipeInfo;					//<根据数量读入>
												//1、连接管道的数字编号（从节点流出加负号）
												//2  类型
												//2、流体从节点流入管道时管道端口k系数
												//3、流体从节点流出管道时管道端口k系数
												//4、r/d（端口的园整度）
												//5、管道标高或深度

public:
	CalcTransData m_TranData;
};


#endif // !defined(AFX_CALCRESERVIOR_H__1860353A_C9A0_4EA6_9BFD_4F1E22BBAC44__INCLUDED_)
