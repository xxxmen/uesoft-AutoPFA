// CalcTrans.h: interface for the CalcTrans class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCTRANS_H__A8977787_23E2_46CD_AF15_F18C10ACAB45__INCLUDED_)
#define AFX_CALCTRANS_H__A8977787_23E2_46CD_AF15_F18C10ACAB45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS CalcTrans  
{
public:
	CalcTrans();
	virtual ~CalcTrans();

public:
	void StartTime(double dValue);
	void StopTime(double dValue);
	void TimeStep(double dValue);
	void Frequency(int nValue);
	void Cavitation(int nValue);
	void VariableR(int nValue);
	void Artificial(int nValue);
	void Criteria(double dValue);
	void MinFlow(double dValue);
	void TotalSteps(int nValue);

	double StartTime();
	double StopTime();
	double TimeStep();
	int Frequency();
	int Cavitation();
	int VariableR();
	int Artificial();
	double Criteria();
	double MinFlow();
	int TotalSteps();
	friend ostream& operator<< (ostream &CalcOut,const CalcTrans &ref);
private:
	double m_StartTime;				    //瞬态模拟开始时间
	double m_StopTime;					//瞬态模拟结束时间
	int m_Frequency;					//计算结果保存的频率
	int m_Cavitation;					//0：不考虑气穴存在，1：考虑存在气穴
	int m_VariableR;					//0：管道阻力系数使用稳态阻力系数，1：根据当前瞬态流量计算管道阻力系数
	int m_Artificial;					//停止运行如果检测到人工瞬变标记0：不检测人工瞬变，1：检测人工瞬变
	double m_Criteria;					//恒定流计算结果与瞬变流初始数据标准允许误差百分数（例如：0.5%用"0.5"表示）
	double m_MinFlow;					//忽略流量值标准（当流量低于标准忽略流量存在认为流量为0）
	int m_TotalSteps;					//瞬态模拟总计算步数
	double m_TimeStep;					//控制管道时间步长	

};

#endif // !defined(AFX_CALCTRANS_H__A8977787_23E2_46CD_AF15_F18C10ACAB45__INCLUDED_)
