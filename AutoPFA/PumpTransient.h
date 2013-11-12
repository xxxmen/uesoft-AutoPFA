// PumpTransient.h: interface for the PumpTransient class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUMPTRANSIENT_H__3575F9CC_126C_4F58_BEDF_0CD279A6E11E__INCLUDED_)
#define AFX_PUMPTRANSIENT_H__3575F9CC_126C_4F58_BEDF_0CD279A6E11E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Transient.h"

class PumpTransient : public Transient  
{
public:
	PumpTransient();
	virtual ~PumpTransient();
	const StrFlyWeight& TranModel();
	void TranModel(const StrFlyWeight& ref);
	const StrFlyWeight& Speed();
	void Speed(const StrFlyWeight& ref);
    const NumFlyWeight& RotateInertia();
	void RotateInertia(const NumFlyWeight& ref);
	const ArrayFlyWeight<3>& FourQuadrantData();
	void FourQuadrantData(const ArrayFlyWeight<3>& ref);
public:
	StrFlyWeight m_TranModel;				//泵瞬变模型
	NumFlyWeight m_RotateInertia;			//转动惯量（泵，电动机，流体）\转动惯量单位
	StrFlyWeight m_Speed;					//泵额定转速
	ArrayFlyWeight<3> m_FourQuadrantData;   // 四象限数据源标记\四象限数据的数量\角度选择0：1 
	TransDataTable<3> m_FourquadTable;

public:
	void InitData(ScenarioObject *pObject);
	BOOL SaveData(ScenarioObject *pObject,int &num1,int &num2,int &num3);
	void Instance(NameArray &array,int nKey);
	BOOL Save(TransDataPersistent &Persistent,int num1,int num2,int num3);
	BOOL Read(TransDataPersistent &Persistent);

};
/*----------------------------------------------*/
inline const StrFlyWeight& PumpTransient::TranModel()
{
	return m_TranModel;
}
/*----------------------------------------------*/
inline void PumpTransient::TranModel(const StrFlyWeight& ref)
{
	m_TranModel = ref;
}

/*----------------------------------------------*/
inline const StrFlyWeight& PumpTransient::Speed()
{
	return m_Speed;
}
/*----------------------------------------------*/
inline void PumpTransient::Speed(const StrFlyWeight& ref)
{
	m_Speed = ref;
}

/*----------------------------------------------*/
inline const NumFlyWeight& PumpTransient::RotateInertia()
{
	return m_RotateInertia;
}
/*----------------------------------------------*/
inline void PumpTransient::RotateInertia(const NumFlyWeight& ref)
{
	m_RotateInertia = ref;
}

/*----------------------------------------------*/
inline const ArrayFlyWeight<3>& PumpTransient::FourQuadrantData()
{
	return m_FourQuadrantData;
}
/*----------------------------------------------*/
inline void PumpTransient::FourQuadrantData(const ArrayFlyWeight<3>& ref)
{
	m_FourQuadrantData = ref;
}
#endif // !defined(AFX_PUMPTRANSIENT_H__3575F9CC_126C_4F58_BEDF_0CD279A6E11E__INCLUDED_)
