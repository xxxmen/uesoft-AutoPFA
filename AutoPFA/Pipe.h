// Pipe.h: interface for the Pipe class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：Pipe.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIPE_H__01F128E0_0681_4939_B20B_0C4508CC9A83__INCLUDED_)
#define AFX_PIPE_H__01F128E0_0681_4939_B20B_0C4508CC9A83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Component.h"
class PipePerisist;

class Pipe : public Component  
{	
public:
	Graphics* GetGarph();
	Manipulator* CreatManipulator(ComponentManager *pManager,int Size,BOOL bSingle = TRUE);
	int GetID();
	static void Instance();
	NameArray& GetArray();
	int GetType();
	static Component* CreatPipe();
	Pipe();
	virtual ~Pipe();


private:
	ScenarioObject* DoClone();
public:
	BOOL Read(PipePerisist *pPerisist);
	BOOL Save(PipePerisist *pPerisist);
	BOOL Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bDlgReadOnly = FALSE);
	BOOL Pick(CRect rc);
	void EndPt(CPoint pt);
	CPoint EndPt();
	int EndJun();
	void EndJun(int nKey);
	void StartPt(CPoint pt);
	CPoint StartPt();
	int StartJun();
	void StartJun(int nKey);
	void Draw(CDC *pDc, WorkSpaceRef &ref);
	BOOL Pick(CPoint point,int Size);
	CString GetTypeName();
	static const int m_nTypeID;
public:
	void EmptyJunLink();
	void EmptyJunLink(ComponentManager *pManager);
	void DelJunLink(ComponentManager *pManager);
	void ChangePosition(ComponentManager *pManager,CPoint &sPt,CPoint &ePt,int nSize);
	void SaveData();
	void InitData();
	void SaveAllData();
	void InitAllData();
	static PtFlyWeight ms_StartPt;
	static PtFlyWeight ms_EndPt;
	static StrFlyWeight ms_InJun;
	static StrFlyWeight ms_OutJun;
	static StrFlyWeight ms_Material;
	static StrFlyWeight ms_Size;
	static StrFlyWeight ms_PipeType;
	static NumFlyWeight ms_InDia;
	static NumFlyWeight ms_Thick;
	static NumFlyWeight ms_Elasticity;
	static StrFlyWeight ms_PossionRatio;
	static StrFlyWeight ms_InDiaReduce;
	static NumFlyWeight ms_Len;
	static StrFlyWeight ms_CalcWave;
	static StrFlyWeight ms_SupportType;
	static StrFlyWeight ms_C1;
	static NumFlyWeight ms_WaveSpeed;
	static StrFlyWeight ms_LossType;
	static NumFlyWeight ms_Friction;
	static StrFlyWeight ms_LocalK;		//总共局部的K系数
	static StrFlyWeight ms_PipeFactor;	//设计因子管道摩擦力
	static StrFlyWeight ms_FitFactor;	//设计因子管道附加损失
	static ArrayFlyWeight<3> ms_InitFlow;//初始化流体猜测
	static StrFlyWeight ms_SectionNum;	//管段分段数取整
	static StrFlyWeight ms_ParaNum;		//管道并联数
	static StrFlyWeight ms_B;
	static StrFlyWeight ms_PartFull;    //排空管满管率


private:
	void MoveEndPt(ComponentManager *pManager,CPoint &Pt,CSize sz);
	void MoveStartPt(ComponentManager *pManager,CPoint &Pt,CSize sz);
	void MoveLinkJun(ComponentManager *pManager,int nKey);

	void WaveSpeed(double dValue);
	
private:
	static CString s_typeName;
	static NameArray s_StateName;
	
public:
	void Status(ComponentStatus &ref, BOOL bTrans= TRUE);
	static void CalcWaveSpeed(double dDen,double dK);
	void CalcWave(double dDen,double dK);
	double CalcArea();
	void SectionInfo(StrArray<8> &array,double dTime);
	double CalcSection(double dTimeStep);
	BOOL CalcSection(int &nNum,double &dError,double dTimeStep,double dMaxError=100);
	int SectionNum();
	void SectionNum(int nNum);
	CString GetB();
	void SetB(CString strB);
	double InDia();
	double WaveSpeed();
	double Len();
	double StepTime();
	void SetPressType(CString strType);
	virtual void SetDesignFactor(CString strFactor);
	static	const CmbDataItem ms_supportTypeArray[8];
	static	const CmbDataItem ms_frictionModel[8];
	static const CmbDataItem  ms_FlowType[3];



};

inline int Pipe::GetType()
{
	return 1;
}

inline NameArray& Pipe::GetArray()
{
	return s_StateName;
}
#endif // !defined(AFX_PIPE_H__01F128E0_0681_4939_B20B_0C4508CC9A83__INCLUDED_)
