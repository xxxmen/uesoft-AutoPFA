// Transient.h: interface for the Transient class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSIENT_H__B0917ED4_96B0_4518_8594_49E6CA326280__INCLUDED_)
#define AFX_TRANSIENT_H__B0917ED4_96B0_4518_8594_49E6CA326280__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "StrFlyWeight.h"
#include "TransDataTable.h"
#include "TransDataPersistent.h"
#include "ScenarioObject.h"

class Transient  
{
public:
	Transient();
	virtual ~Transient();
public:
	const StrFlyWeight& ValueType();
	void ValueType(const StrFlyWeight& ref);
	const StrFlyWeight& Special();
	void Special(const StrFlyWeight& ref);
	const StrFlyWeight& Repeat1();
	void Repeat1(const StrFlyWeight& ref);
	const StrFlyWeight& Repeat2();
	void Repeat2(const StrFlyWeight& ref);
	const StrFlyWeight& TranType();
	void TranType(const StrFlyWeight& ref);
    const ArrayFlyWeight<5>& Periodic();
	void Periodic(const ArrayFlyWeight<5>& ref);
	const ArrayFlyWeight<8>& TranTriger1();
	void TranTriger1(const ArrayFlyWeight<8>& ref);
	const ArrayFlyWeight<8>& TranTriger2();
	void TranTriger2(const ArrayFlyWeight<8>& ref);

public:
	StrFlyWeight m_ValueType;				//1、0:绝对值，1：相对恒定流的值
	StrFlyWeight m_Special;					//2、0：瞬态特别条件选中“没有”，1：瞬态特别条件选“忽略瞬态数据”（针对具体节点特别条件多于2个分别查看特别条件对应的数字）
	StrFlyWeight m_Repeat1;					//3、0：第一次瞬变重复没选中，-1选中：
	StrFlyWeight m_Repeat2;					//4、0：第二次瞬变重复没选中，-1选中：
	StrFlyWeight m_TranType;					//5、0:时间，1：单个事件，2：两个事件循环3：两个连续事件
	ArrayFlyWeight<5> m_Periodic;				//1、0：周期性没有选择，-1：流量周期性选择
										//2、0：没有选择使用正弦函数的绝对值，-1：选择使用正弦函数的绝对值
										//3、正弦函数频率
										//4、正弦函数振幅
										//5、正弦函数振幅单位
	ArrayFlyWeight<8> m_TranTriger1;			 //事件类型
										//条件类型
										//值
										//单位
										//管道入口触发事件为1；管道出口触发事件为2（第一根管道）
										//触发事件的管道编号（第一根管道）
										//管道入口触发事件为1；管道出口触发事件为2（第二根管道）
										//触发事件的管道编号（第二根管道）
	ArrayFlyWeight<8> m_TranTriger2;
public:
	void InitData(ScenarioObject *pObject);
	BOOL SaveData(ScenarioObject *pObject,int &num1,int &num2);
	int Instance(NameArray &array,int nKey);
	BOOL Save(TransDataPersistent &Persistent,int num1,int num2);
	BOOL Read(TransDataPersistent &Persistent);
	TransDataTable<2> m_Trans1Table;									
	TransDataTable<2> m_Trans2Table;
protected:
	
	void InitData(ScenarioObject *pObject,int &nKey);
	BOOL SaveData(ScenarioObject *pObject,int &num1,int &num2,int &nKey);
	int m_nKey;

};

/*----------------------------------------------*/
inline const StrFlyWeight& Transient::ValueType()
{
	return m_ValueType;
}
/*----------------------------------------------*/
inline void Transient::ValueType(const StrFlyWeight& ref)
{
	m_ValueType = ref;
}

/*----------------------------------------------*/
inline const StrFlyWeight& Transient::Special()
{
	return m_Special;
}
/*----------------------------------------------*/
inline void Transient::Special(const StrFlyWeight& ref)
{
	m_Special = ref;
}

/*----------------------------------------------*/
inline const StrFlyWeight& Transient::Repeat1()
{
	return m_Repeat1;
}
/*----------------------------------------------*/
inline void Transient::Repeat1(const StrFlyWeight& ref)
{
	m_Repeat1 = ref;
}

/*----------------------------------------------*/
inline const StrFlyWeight& Transient::Repeat2()
{
	return m_Repeat2;
}
/*----------------------------------------------*/
inline void Transient::Repeat2(const StrFlyWeight& ref)
{
	m_Repeat2 = ref;
}

/*----------------------------------------------*/
inline const StrFlyWeight& Transient::TranType()
{
	return m_TranType;
}
/*----------------------------------------------*/
inline void Transient::TranType(const StrFlyWeight& ref)
{
	m_TranType = ref;
}

/*----------------------------------------------*/
inline const ArrayFlyWeight<5>& Transient::Periodic()
{
	return m_Periodic;
}
/*----------------------------------------------*/
inline void Transient::Periodic(const ArrayFlyWeight<5>& ref)
{
	m_Periodic = ref;
}

/*----------------------------------------------*/
inline const ArrayFlyWeight<8>& Transient::TranTriger1()
{
	return m_TranTriger1;
}
/*----------------------------------------------*/
inline void Transient::TranTriger1(const ArrayFlyWeight<8>& ref)
{
	m_TranTriger1 = ref;
}

/*----------------------------------------------*/
inline const ArrayFlyWeight<8>& Transient::TranTriger2()
{
	return m_TranTriger2;
}
/*----------------------------------------------*/
inline void Transient::TranTriger2(const ArrayFlyWeight<8>& ref)
{
	m_TranTriger2 = ref;
}
#endif // !defined(AFX_TRANSIENT_H__B0917ED4_96B0_4518_8594_49E6CA326280__INCLUDED_)
