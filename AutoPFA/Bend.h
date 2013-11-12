// Bend.h: interface for the Bend class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BEND_H__27584C15_B212_4B0C_9AA9_43987634D5AC__INCLUDED_)
#define AFX_BEND_H__27584C15_B212_4B0C_9AA9_43987634D5AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Jun.h"

class Bend : public Jun  
{
public:
	CBitmap& GetBitMap();
	static void Instance();
	NameArray& GetArray();
	static Component* CreatBend();
	Bend();
	virtual ~Bend();
	
private:
	ScenarioObject* DoClone();

public:
	void Status(ComponentStatus &ref,BOOL bTrans=TRUE);
	void DelLinkPipeInfo(UINT nKey);
	void AddLinkPipeInfo(UINT nKey);
	void SaveData();
	void InitData();
	BOOL Save(Junperisist *pPersistent);
	BOOL Read(Junperisist *pPersistent);
	BOOL Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bDlgReadOnly = FALSE);
	CString GetTypeName();
	int GetID();
	static const int m_nTypeID;
public:
	static StrFlyWeight ms_Type;					 //弯头类型（0，为光滑弯头，1为标准弯头，2为Mitre Bend,3,为用户指定）
	static StrFlyWeight ms_AngleType;
	static StrFlyWeight ms_Angle;					//角度
	static StrFlyWeight ms_RD;
	static StrFlyWeight ms_K;						//K系数值
	static NumFlyWeight ms_RestriFlowArea;			//精确流体面积（Restricted Flow Area)的数字和单位
	static ArrayFlyWeight<3> ms_BasisArea;			//损失模型的面积引用
private:
	BOOL CanLink(int nMaxLink,int nKey);
	void EmptyPipeInfo();
private:
	static NameArray s_StateName;
    static CBitmap m_bitmap;
	static CString s_typeName;

};
inline CBitmap& Bend::GetBitMap()
{
	return m_bitmap;
}

inline NameArray& Bend::GetArray()
{
	return s_StateName;
}
#endif // !defined(AFX_BEND_H__27584C15_B212_4B0C_9AA9_43987634D5AC__INCLUDED_)
