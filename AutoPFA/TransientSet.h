// TransientSet.h: interface for the TransientSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSIENTSET_H__72CF4364_9A7B_493D_8625_433A8EF4DF83__INCLUDED_)
#define AFX_TRANSIENTSET_H__72CF4364_9A7B_493D_8625_433A8EF4DF83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ScenarioObject.h"
class TransControlPerisistent;

class TransientSet : public ScenarioObject  
{
public:
	BOOL Read(TransControlPerisistent &persistent);
	BOOL Save(TransControlPerisistent &persistent);
	void SaveData();
	void InitData();
	static void Instance();
	NameArray& GetArray();
	int GetType();
	static ScenarioObject* CreatTransientSet();
	TransientSet();
	virtual ~TransientSet();
public:
	BOOL IsDefine();
	static NumFlyWeight ms_StartTime;				//瞬态模拟开始时间
	static NumFlyWeight ms_StopTime;				//瞬态模拟结束时间
	static StrFlyWeight ms_Frequency;				//计算结果保存的频率
	static StrFlyWeight ms_ModelCavitation;			//0：不考虑气穴存在，1：考虑存在气穴
	static StrFlyWeight ms_VariableR;				//0：管道阻力系数使用稳态阻力系数，1：根据当前瞬态流量计算管道阻力系数
	static StrFlyWeight ms_StopOnArtificialTrans;	//停止运行如果检测到人工瞬变标记0：不检测人工瞬变，1：检测人工瞬变
	static StrFlyWeight ms_Criteria;				//恒定流计算结果与瞬变流初始数据标准允许误差百分数（例如：0.5%用"0.5"表示）
	static NumFlyWeight ms_CriteriaMinFlow;			//忽略流量值标准（当流量低于标准忽略流量存在认为流量为0）
	static StrFlyWeight ms_TotalSteps;				//瞬态模拟总计算步数
private:
    static NameArray s_StateName;
	ScenarioObject* DoClone();
};
inline int TransientSet::GetType()
{
	return 22;
}

inline NameArray& TransientSet::GetArray()
{
	return s_StateName;
}
#endif // !defined(AFX_TRANSIENTSET_H__72CF4364_9A7B_493D_8625_433A8EF4DF83__INCLUDED_)
