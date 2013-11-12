// Jun.h: interface for the Jun class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：Jun.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUN_H__A42D91AC_827B_4313_8723_18CBD215DF19__INCLUDED_)
#define AFX_JUN_H__A42D91AC_827B_4313_8723_18CBD215DF19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Component.h"
class Transient;
class Junperisist;
typedef CMap<int,int,CString,CString> KeyMap;
class Jun : public Component  
{
public:
	virtual void SaveData();
	virtual void InitData();
	virtual void SaveAllData();
	virtual void InitAllData();
	virtual BOOL Read(Junperisist *pPersistent);
	virtual BOOL Save(Junperisist *pPersistent);
	virtual BOOL Show(UnitSubSystem &UnitSys,ComponentManager *pManager, BOOL bReadOnlyDlg = FALSE)=0;
	int GetID()=0;
	int GetType();
	NameArray& GetArray()=0;
	static void Instance(NameArray &array);
	Jun();
	virtual ~Jun();
	Jun(const Jun &ref);
	Jun& operator=(const Jun &ref);
	
public:
	virtual CBitmap& GetBitMap()=0;
	void Draw(CDC* pDc,WorkSpaceRef &ref);
	BOOL Pick(CRect rc);
	BOOL Pick(CPoint point,int Size=0);
	void CenterPt(CPoint pt);
	CPoint CenterPt();
	Graphics* GetGarph();
	Manipulator* CreatManipulator(ComponentManager *pManager,int Size,BOOL bSingle = TRUE);

public:
	void EmptyLinkPipe(ComponentManager *pManager);
	void EmptyLinkPipe();
	void ChangePosition(ComponentManager *pManager,CPoint pt,int nSize);
	void DelLinkPipe(int nKey);
    BOOL AddLinkPipe(int nKey);
	//如果不存在逻辑连接关系删除连接管道信息
	virtual void DelLinkPipeInfo(UINT nKey)=0;
	static PtFlyWeight  ms_CenterPt;
	static NumFlyWeight ms_InletEle;
	static NumFlyWeight ms_OutletEle;
	static PipeIDFlyWeight ms_PipeID;
	static StrFlyWeight ms_DisignFactor;			//损失设计因子
	static StrFlyWeight ms_RawKey;
	static TransDataTable<2> ms_RawData;
	static ArrayFlyWeight<3> ms_InitGuess;			//初始化流体猜测类型（0，1）\大小\单位
	static ArrayFlyWeight<3> ms_SpecialMark;		//指定特别条件类型标记/默认为空盲管或关闭的阀门默认“J和编号”

public:
	virtual Transient* GetTransient();
	void SetPressType(CString strType);
	virtual void SetDesignFactor(CString strFactor);
	static const CmbDataItem ms_BasisArea[4];
	static const CmbDataItem ms_Condition[5];   //瞬变触发条件
	static const CmbDataItem ms_ValveStatus[4];   //瞬变触发条件
	static const CmbDataItem ms_PipePort[2];   //管道端口
	static const CmbDataItem ms_EventType[24];   //触发事件
	static const CmbDataItem ms_CurveType[2];   //曲线拟合类型
	static KeyMap IDMap;
	
protected:
	int ConnectPipeNum();
	void AddPipeInfo(TableFlyWeight<4> &ref,int Key);
	void DelPipeInfo(TableFlyWeight<4> &ref,int nKey);
	BOOL IsExistOutPipe();
	BOOL IsExistInPipe();
	
private:
	virtual BOOL CanLink(int nMaxLink,int nKey)=0;
	ScenarioObject* DoClone() = 0;
	void MoveLinkPipe(ComponentManager *pManager,CPoint pt);
	void AddLinkPipe(ComponentManager *pManager,int nSize);
	//增加管道与节点连接管口的损失系数等信息
	virtual void AddLinkPipeInfo(UINT nKey)=0;
	//清空连接元件与管道的连接信息
	virtual void EmptyPipeInfo()=0;

protected:
	static void InitCurve(ArrayFlyWeight<13> &ref);
	void SetSpecial(int nSpecial);
	int m_nLinkPipeNum;
	
	template<class T> static int CreatKey(CMap<int,int,T,T>& map)
	{
		T temp;
		int nKey = 1;
		while(map.Lookup(nKey,temp))
			nKey++;
		return nKey;
	}
public:
	void Status(ComponentStatus &ref,BOOL bTrans=TRUE);
	static void AddID(CString ID);
	static CString CreatID();
	static void CreatRawKey();
};

inline int Jun::GetType()
{
	return 2;//连接元件
}


#endif // !defined(AFX_JUN_H__A42D91AC_827B_4313_8723_18CBD215DF19__INCLUDED_)
