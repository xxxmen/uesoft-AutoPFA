// Pipe.cpp: implementation of the Pipe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "Pipe.h"
#include "PipeGraphics.h"
#include "PipeManipulator.h"
#include "PtFlyWeight.h"
#include "NumFlyWeight.h"
#include "DlgCommon.h"
#include "PipePerisist.h"
#include"WavespeedCalc.h"
#include "FuildDataMgr.h"
#include "Fuild.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const CmbDataItem  Pipe::ms_supportTypeArray[]=
{
	    CmbDataItem(0,"用户指定"),
		CmbDataItem(1,"薄壁圆管只在上游端固定"),
		CmbDataItem(2,"薄壁圆管全管固定无轴向运动"),
		CmbDataItem(3,"薄壁圆管全部用膨胀接头连接"),
		CmbDataItem(4,"厚壁圆管只在上游端固定"),
		CmbDataItem(5,"厚壁圆管全管固定无轴向运动"),
		CmbDataItem(6,"厚壁圆管全部用膨胀接头连接"),
		CmbDataItem(7,"圆隧道")
};

const CmbDataItem  Pipe::ms_frictionModel[]=
{
	    CmbDataItem(0,"绝对粗糙度"),
		CmbDataItem(4,"摩擦系数"),
		CmbDataItem(7,"无摩擦阻力"),
		CmbDataItem(3,"海曾-威廉公式"),
		CmbDataItem(2,"水力光滑"),
		CmbDataItem(5,"MIT Equation"),
		CmbDataItem(6,"Miller Turbulent "),
		CmbDataItem(1,"相对粗糙度")
};
const CmbDataItem  Pipe::ms_FlowType[]=
{
	    CmbDataItem(0,"体积流量"),
		CmbDataItem(1,"质量流量"),
		CmbDataItem(2,"流速")
};

NameArray Pipe::s_StateName;
const int Pipe::m_nTypeID = 0;
CString Pipe::s_typeName;

PtFlyWeight  Pipe::ms_StartPt;
PtFlyWeight  Pipe::ms_EndPt;
StrFlyWeight Pipe::ms_InJun;
StrFlyWeight Pipe::ms_OutJun;
StrFlyWeight Pipe::ms_Material;
StrFlyWeight Pipe::ms_Size;
StrFlyWeight Pipe::ms_PipeType;
NumFlyWeight Pipe::ms_InDia;
NumFlyWeight Pipe::ms_Thick;
NumFlyWeight Pipe::ms_Elasticity;
StrFlyWeight Pipe::ms_PossionRatio;
StrFlyWeight Pipe::ms_InDiaReduce;
NumFlyWeight Pipe::ms_Len;
StrFlyWeight Pipe::ms_CalcWave;
StrFlyWeight Pipe::ms_SupportType;
StrFlyWeight Pipe::ms_C1;
NumFlyWeight Pipe::ms_WaveSpeed;
StrFlyWeight Pipe::ms_LossType;
NumFlyWeight Pipe::ms_Friction;
StrFlyWeight Pipe::ms_LocalK;	
StrFlyWeight Pipe::ms_PipeFactor;	
StrFlyWeight Pipe::ms_FitFactor;
ArrayFlyWeight<3> Pipe::ms_InitFlow;
StrFlyWeight Pipe::ms_SectionNum;	
StrFlyWeight Pipe::ms_ParaNum;	
StrFlyWeight Pipe::ms_B;
StrFlyWeight Pipe::ms_PartFull;

Pipe::Pipe()
{

}

Pipe::~Pipe()
{

}


void Pipe::Instance()
{
	Component::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,IDS_STRINDIA,9,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRLEN,14,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRWAVESPEED,18,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STARTPT,2,3,FALSE);
	ScenarioObject::InitAttr(s_StateName,IDS_ENDPT,3,3,FALSE);
	ScenarioObject::InitAttr(s_StateName,IDS_INJUNNUM,4,1);
	ScenarioObject::InitAttr(s_StateName,IDS_OUTJUNNUM,5,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRMATERIAL,6,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRSIZE,7,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRPIPETYPE,8,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRTHICK,10,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRELASTICITY,11,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRPOSSIONRATIO,12,1);
	ScenarioObject::InitAttr(s_StateName,13,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRCALCWAVE,15,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRSUPPORT,16,1);
	ScenarioObject::InitAttr(s_StateName,17,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRFRICTIONMODEL,19,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRFRICTION,20,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRFITLOSS,21,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRFRICTIONFACTOR,22,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRFITLOSSFACTOR,23,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRFLOWGUESS,24,13);
	ScenarioObject::InitAttr(s_StateName,25,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRPARAMUN,26,1);
	ScenarioObject::InitAttr(s_StateName,27,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRPARTFULL,28,1);
	
	s_typeName.LoadString(IDS_STRPIPE);
}


Component* Pipe::CreatPipe()
{
	Pipe *pPipe = new Pipe;
	pPipe->Init();
	return pPipe;
}

ScenarioObject* Pipe::DoClone()
{
	return new Pipe(*this);
}


int Pipe::GetID()
{
	return m_nTypeID;
}

CString Pipe::GetTypeName()
{
	return s_typeName;
}

Graphics* Pipe::GetGarph()
{
	return PipeGraphics::Instance(this);
}

Manipulator* Pipe::CreatManipulator(ComponentManager *pManager,int Size,BOOL bSingle)
{
	return PipeManipulator::Instance(this,pManager,Size,bSingle);
}

BOOL Pipe::Pick(CPoint point,int Size)
{
	return GetGarph()->Pick(point,Size);
}

BOOL Pipe::Pick(CRect rc)
{
	if(rc.PtInRect(StartPt()) && rc.PtInRect(EndPt()))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
void Pipe::Draw(CDC *pDc, WorkSpaceRef &ref)
{
	int nPipeStyle = PS_SOLID;
	int nPipeThick = ref.GetPipeThick();
	COLORREF pipeColor = ref.GetPipeColor();
	COLORREF textColor;
	if(IsDefine(ref.Trans()))
	{
		textColor = ref.GetPipeText();
	}
	else
	{
		textColor = ref.GetUndefineText();
	}
	pDc->SetTextColor(textColor);
	GetGarph()->Draw(pDc,pipeColor,nPipeStyle,nPipeThick);
}

CPoint Pipe::StartPt()
{
	CPoint pt;
	GetValue(ms_StartPt,2);
	pt.x = _ttoi(ms_StartPt.GetValue1());
	pt.y = _ttoi(ms_StartPt.GetValue2());
	return pt;
}
int Pipe::StartJun()
{
	GetValue(ms_InJun,4);
	return ms_InJun.GetnValue();
}
void Pipe::StartJun(int nKey)
{
	ms_InJun.SetValue(nKey);
	SetValue(ms_InJun,4);
}
void Pipe::StartPt(CPoint pt)
{
    ms_StartPt.SetValue1(pt.x);
	ms_StartPt.SetValue2(pt.y);
	SetValue(ms_StartPt,2);

}

CPoint Pipe::EndPt()
{
	CPoint pt;
	GetValue(ms_EndPt,3);
	pt.x = _ttoi(ms_EndPt.GetValue1());
	pt.y = _ttoi(ms_EndPt.GetValue2());
	return pt;
}
int Pipe::EndJun()
{
	GetValue(ms_OutJun,5);
	return ms_OutJun.GetnValue();
}
void Pipe::EndJun(int nKey)
{
	ms_OutJun.SetValue(nKey);
	SetValue(ms_OutJun,5);
}
void Pipe::EndPt(CPoint pt)
{
    ms_EndPt.SetValue1(pt.x);
	ms_EndPt.SetValue2(pt.y);
	SetValue(ms_EndPt,3); 
}


BOOL Pipe::Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bReadOnly)
{
	DlgPipe dlg(UnitSys,*pManager,this);
	dlg.ReadOnly(bReadOnly);
	if(IDOK == dlg.DoModal())
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL Pipe::Read(PipePerisist *pPerisist)
{
	ms_Name.SetValue(pPerisist->Name());
    ms_StartPt.SetValue1(pPerisist->StartPtX());
	ms_StartPt.SetValue2(pPerisist->StartPtY());
	ms_EndPt.SetValue1(pPerisist->EndPtX());
	ms_EndPt.SetValue2(pPerisist->EndPtY());
	ms_InJun.SetValue(pPerisist->InJunID());
	ms_OutJun.SetValue(pPerisist->OutJunID());
	ms_InDia.SetValue(pPerisist->InDia());
	ms_InDia.SetUnit(pPerisist->InDiaUnit());
	ms_Len.SetValue(pPerisist->Len());
	ms_Len.SetUnit(pPerisist->LenUnit());
	ms_WaveSpeed.SetValue(pPerisist->WaveSpeed());
	ms_WaveSpeed.SetUnit(pPerisist->WaveSpeedUnit());
	ms_Material.SetValue(pPerisist->Material());
	ms_Size.SetValue(pPerisist->Size());
	ms_PipeType.SetValue(pPerisist->PipeType());
	ms_Thick.SetValue(pPerisist->Thick());
	ms_Thick.SetUnit(pPerisist->ThickUnit());
	ms_Elasticity.SetValue(pPerisist->Elasticity());
	ms_Elasticity.SetUnit(pPerisist->ElasticityUnit());
	ms_PossionRatio.SetValue(pPerisist->PossionRatio());
	ms_InDiaReduce.SetValue(pPerisist->InDiaReduce());
	ms_CalcWave.SetValue(pPerisist->CalcWave());
	ms_SupportType.SetValue(pPerisist->SupportType());
	ms_C1.SetValue(pPerisist->C1());
	ms_LossType.SetValue(pPerisist->FrictionModel());
	ms_Friction.SetValue(pPerisist->Friction());
	ms_Friction.SetUnit(pPerisist->FrictionUnit());
	ms_LocalK.SetValue(pPerisist->LocalK());
	ms_PipeFactor.SetValue(pPerisist->PipeFactor());
	ms_FitFactor.SetValue(pPerisist->FitFactor());
	ms_InitFlow.SetData(pPerisist->InitFlow());
	ms_SectionNum.SetValue(pPerisist->SectionNum());
	ms_ParaNum.SetValue(pPerisist->ParaNum());
	ms_PartFull.SetValue(pPerisist->PartFull());
	SetB(pPerisist->B());
	SaveAllData();
	return TRUE;
}

BOOL Pipe::Save(PipePerisist *pPerisist)
{	
	InitAllData();
	pPerisist->Key(GetKey());
	pPerisist->Name(ms_Name.GetValue());
	pPerisist->StartPtX(ms_StartPt.GetValue1());
    pPerisist->StartPtY(ms_StartPt.GetValue2());
	pPerisist->EndPtX(ms_EndPt.GetValue1());
    pPerisist->EndPtY(ms_EndPt.GetValue2());
	pPerisist->InJunID(ms_InJun.GetValue());
	pPerisist->OutJunID(ms_OutJun.GetValue());
	pPerisist->InDia(ms_InDia.GetValue());
	pPerisist->InDiaUnit(ms_InDia.GetUnit());
	pPerisist->Len(ms_Len.GetValue());
	pPerisist->LenUnit(ms_Len.GetUnit());
	pPerisist->WaveSpeed(ms_WaveSpeed.GetValue());
	pPerisist->WaveSpeedUnit(ms_WaveSpeed.GetUnit());
	pPerisist->Material(ms_Material.GetValue());
	pPerisist->Size(ms_Size.GetValue());
	pPerisist->PipeType(ms_PipeType.GetValue());
	pPerisist->Thick(ms_Thick.GetValue());
	pPerisist->ThickUnit(ms_Thick.GetUnit());
	pPerisist->Elasticity(ms_Elasticity.GetValue());
	pPerisist->ElasticityUnit(ms_Elasticity.GetUnit());
	pPerisist->PossionRatio(ms_PossionRatio.GetValue());
	pPerisist->InDiaReduce(ms_InDiaReduce.GetValue());
	pPerisist->CalcWave(ms_CalcWave.GetValue());
	pPerisist->SupportType(ms_SupportType.GetValue());
	pPerisist->C1(ms_C1.GetValue());
	pPerisist->FrictionModel(ms_LossType.GetValue());
	pPerisist->Friction(ms_Friction.GetValue());
	pPerisist->FrictionUnit(ms_Friction.GetUnit());
	pPerisist->LocalK(ms_LocalK.GetValue());
	pPerisist->PipeFactor(ms_PipeFactor.GetValue());
	pPerisist->FitFactor(ms_FitFactor.GetValue());
	pPerisist->InitFlow(ms_InitFlow.GetData());
	pPerisist->SectionNum(ms_SectionNum.GetValue());
	pPerisist->ParaNum(ms_ParaNum.GetValue());
	pPerisist->PartFull(ms_PartFull.GetValue());
	pPerisist->B(GetB());
	return TRUE;
}

void Pipe::InitData()
{
	GetValue(ms_Name,1);
	GetValue(ms_Material,6);
	GetValue(ms_Size,7);
	GetValue(ms_PipeType,8);
	GetValue(ms_InDia,9);
	GetValue(ms_Thick,10);
	GetValue(ms_Elasticity,11);
	GetValue(ms_PossionRatio,12);
	GetValue(ms_InDiaReduce,13);
    GetValue(ms_Len,14);
	GetValue(ms_CalcWave,15);
	GetValue(ms_SupportType,16);
	GetValue(ms_C1,17);
	GetValue(ms_WaveSpeed,18);
	GetValue(ms_LossType,19);
	GetValue(ms_Friction,20);
	GetValue(ms_LocalK,21);
	GetValue(ms_PipeFactor,22);
	GetValue(ms_FitFactor,23);
	GetValue(ms_InitFlow,24);
	GetValue(ms_SectionNum,25);
	GetValue(ms_ParaNum,26);
	GetValue(ms_PartFull,28);
}
void Pipe::InitAllData()
{
	GetValue(ms_StartPt,2);
	GetValue(ms_EndPt,3);
	GetValue(ms_InJun,4);
	GetValue(ms_OutJun,5);
	InitData();
}
void Pipe::SaveData()
{
	SetValue(ms_Name,1);
	SetValue(ms_Material,6);
	SetValue(ms_Size,7);
	SetValue(ms_PipeType,8);
	SetValue(ms_InDia,9);
	SetValue(ms_Thick,10);
	SetValue(ms_Elasticity,11);
	SetValue(ms_PossionRatio,12);
	SetValue(ms_InDiaReduce,13);
    SetValue(ms_Len,14);
	SetValue(ms_CalcWave,15);
	SetValue(ms_SupportType,16);
	SetValue(ms_C1,17);
	SetValue(ms_WaveSpeed,18);
	SetValue(ms_LossType,19);
	SetValue(ms_Friction,20);
	SetValue(ms_LocalK,21);
	SetValue(ms_PipeFactor,22);
	SetValue(ms_FitFactor,23);
	SetValue(ms_InitFlow,24);
	SetValue(ms_SectionNum,25);
	SetValue(ms_ParaNum,26);
	SetValue(ms_PartFull,28);
}

void Pipe::SaveAllData()
{
	SetValue(ms_StartPt,2);
	SetValue(ms_EndPt,3);
	SetValue(ms_InJun,4);
	SetValue(ms_OutJun,5);
	SaveData();
}

void Pipe::ChangePosition(ComponentManager *pManager,CPoint &sPt,CPoint &ePt,int nSize)
{
	ASSERT(pManager != NULL);
	CSize sz(16,16);
	sz.cx = sz.cx * (float(nSize)/100);
	sz.cy = sz.cy * (float(nSize)/100);
	Jun  *pInJun = pManager->LookUpJun(StartJun());
	Jun  *pOutJun = pManager->LookUpJun(EndJun());
	EmptyJunLink(pManager);
	MoveStartPt(pManager,sPt,sz);
	MoveEndPt(pManager,ePt,sz);
	//如果管道和节点的连接关系清除就删除节点的连接信息
	if(pInJun != NULL)
	{
		pInJun->DelLinkPipeInfo(GetKey());
	}
	if(pOutJun != NULL)
	{
		pOutJun->DelLinkPipeInfo(GetKey());
	}
}

void Pipe::MoveStartPt(ComponentManager *pManager,CPoint &Pt,CSize sz)
{
	CPoint centerPt;
	CRect rc;
	StartPt(Pt);
	Component *pComponent = NULL;
	Jun      *pJun = NULL;
	IteratorPtr<Component> JunItPtr(pManager->CreatJunIterator());
	for(JunItPtr->Fist();!JunItPtr->IsDone();JunItPtr->Next())
	{
		pComponent = &JunItPtr->CurrentItem();
		pJun = dynamic_cast<Jun*>(pComponent);
		centerPt = pJun->CenterPt();
		rc.SetRect(centerPt-sz,centerPt+sz);
		if(rc.PtInRect(Pt))
		{
			if(pJun->AddLinkPipe(-GetKey()))
			{
				StartPt(centerPt);
				StartJun(pJun->GetKey());
			}
		}
	}
}

void Pipe::MoveEndPt(ComponentManager *pManager,CPoint &Pt,CSize sz)
{
	CPoint centerPt;
	CRect rc;
	EndPt(Pt);
	Component *pComponent = NULL;
	Jun      *pJun = NULL;
	IteratorPtr<Component> JunItPtr(pManager->CreatJunIterator());
	for(JunItPtr->Fist();!JunItPtr->IsDone();JunItPtr->Next())
	{
		pComponent = &JunItPtr->CurrentItem();
		pJun = dynamic_cast<Jun*>(pComponent);
		centerPt = pJun->CenterPt();
		rc.SetRect(centerPt-sz,centerPt+sz);
		if(rc.PtInRect(Pt))
		{
			if(pJun->AddLinkPipe(GetKey()))
			{
				EndPt(centerPt);
				EndJun(pJun->GetKey());
			}
		}
	}
}

void Pipe::MoveLinkJun(ComponentManager *pManager,int nKey)
{
	Jun  *pJun = pManager->LookUpJun(nKey);
	if(NULL != pJun)
	{
		pJun->DelLinkPipe(GetKey());
		pJun->DelLinkPipe(-GetKey());
	}
}

void Pipe::EmptyJunLink()
{
	StartJun(0);
	EndJun(0);
}

void Pipe::EmptyJunLink(ComponentManager *pManager)
{
	int nKey = StartJun();
	MoveLinkJun(pManager,nKey);
	nKey = EndJun();
	MoveLinkJun(pManager,nKey);
	EmptyJunLink();
}

void Pipe::DelJunLink(ComponentManager *pManager)
{
	//清除连接信息
	int nKey = StartJun();
	Jun  *pInJun = pManager->LookUpJun(nKey);
	nKey = EndJun();
	Jun  *pOutJun = pManager->LookUpJun(nKey);
	//清除逻辑连接
	EmptyJunLink(pManager);
	if(pInJun != NULL)
	{
		pInJun->DelLinkPipeInfo(GetKey());
	}
	if(pOutJun != NULL)
	{
		pOutJun->DelLinkPipeInfo(GetKey());
	}
	
}

void Pipe::SetDesignFactor(CString strFactor)
{
	ms_PipeFactor.SetValue(strFactor);
	ms_FitFactor.SetValue(strFactor);
	ms_ParaNum.SetValue(strFactor);
	SetValue(ms_PipeFactor,22);
	SetValue(ms_FitFactor,23);
	SetValue(ms_ParaNum,26);
	
}

void Pipe::SetPressType(CString strType)
{

}

double Pipe::StepTime()
{
	if( !( 1e-6 < fabs( WaveSpeed() - 1e-6) ) || WaveSpeed() < 0 )
	{
		return -1;
	}
	return Len()/WaveSpeed();
}

double Pipe::Len()
{
	GetValue(ms_Len,14);
	return ms_Len.GetNum();
}

double Pipe::WaveSpeed()
{
	GetValue(ms_WaveSpeed,18);
	return ms_WaveSpeed.GetNum();
}
void Pipe::WaveSpeed(double dValue)
{
	CString strUnit = ms_WaveSpeed.GetUnit();
	double dOut = 0;
	TransformFromStd(dOut,strUnit,dValue);
	ms_WaveSpeed.SetValue(dOut);
	ms_WaveSpeed.SetUnit(strUnit);
	SetValue(ms_WaveSpeed,18);
}

double Pipe::InDia()
{
	GetValue(ms_InDia,9);
	return ms_InDia.GetNum();
}

void Pipe::SetB(CString strB)
{
	ms_B.SetValue(strB);
	SetValue(ms_B,27);
}

CString Pipe::GetB()
{
	GetValue(ms_B,27);
	return ms_B.GetValue();
}

int Pipe::SectionNum()
{
	GetValue(ms_SectionNum,25);
	return ms_SectionNum.GetnValue();
}
void Pipe::SectionNum(int nNum)
{
	ms_SectionNum.SetValue(nNum);
	SetValue(ms_SectionNum,25);
}

double Pipe::CalcSection(double dTimeStep)
{
	ASSERT(dTimeStep != 0);
	return StepTime()/dTimeStep;
}
//--------------------------------------------
//Parameters:	 nNum[OUT]          管道分段数取整
//               dError[OUT]        误差
//               dTimeStep[IN]      理想分段时间步长         
//               dMaxError[IN]	    允许最大误差            
//    return:    如果误差小于等于最大误差返回TURE                                    
//      Memo:	
//				
//---------------------------------------------
BOOL Pipe::CalcSection(int &nNum,double &dError,double dTimeStep,double dMaxError)
{
	double dSectoin = CalcSection(dTimeStep);
	if(dSectoin - int(dSectoin) >= 0.5)
	{
		nNum = int(dSectoin) + 1;
	}
	else
	{
		nNum = int(dSectoin);
	}
	
	dError = (nNum - dSectoin)*100 / nNum;
	if(fabs(dError) <= dMaxError)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void Pipe::SectionInfo(StrArray<8> &array,double dTime)
{
	array.Data(GetKey(),0);
	array.Data(float(Len()),1);
	array.Data(float(WaveSpeed()),2);
	array.Data(float(CalcSection(dTime)),3);
	int nNum = 0;
	double dError = 0;
	double dWave = 0;
	CalcSection(nNum,dError,dTime);
	dWave = (Len()/nNum) / dTime;
	array.Data(nNum,4);
	array.Data(float(dError),5);
	array.Data(float(dWave),6);
}

double Pipe::CalcArea()
{
	return PI*pow(InDia(),2)/4;
}

void Pipe::CalcWave(double dDen, double dK)
{
	InitData();
	if(_ttoi(ms_CalcWave.GetValue()) != 0)
	{
		WavespeedCalc calc;
		calc.SupportType(ms_SupportType.GetnValue());
		calc.Den(dDen);
		calc.K(dK);
		calc.Dia(ms_InDia.GetNum());
		calc.e(ms_Thick.GetNum());
		calc.E(ms_Elasticity.GetNum());
		calc.u(ms_PossionRatio.GetfValue());
		if(ms_SupportType.GetnValue()!=0)
		{//修正系数计算得到
			ms_C1.SetValue(float(calc.CalcC1()));
		}
		double dWave = calc.GetWave(ms_C1.GetfValue(),ms_WaveSpeed.GetUnit());
		ms_WaveSpeed.SetValue(dWave);
		SetValue(ms_C1,17);
	    SetValue(ms_WaveSpeed,18);
	}
}

void Pipe::CalcWaveSpeed(double dDen, double dK)
{
	if(_ttoi(ms_CalcWave.GetValue()) != 0)
	{
		WavespeedCalc calc;
		calc.SupportType(ms_SupportType.GetnValue());
		calc.Den(dDen);
		calc.K(dK);
		calc.Dia(ms_InDia.GetNum());
		calc.e(ms_Thick.GetNum());
		calc.E(ms_Elasticity.GetNum());
		calc.u(ms_PossionRatio.GetfValue());
		if(ms_SupportType.GetnValue()!=0)
		{//修正系数计算得到
			ms_C1.SetValue(float(calc.CalcC1()));
		}
		double dWave = calc.GetWave(ms_C1.GetfValue(),ms_WaveSpeed.GetUnit());
		ms_WaveSpeed.SetValue(dWave);
	}
}

void Pipe::Status(ComponentStatus &ref, BOOL bTrans)
{
	if(StartJun()==0)
		ref.Add(4);
	if(EndJun()==0)
		ref.Add(5);
	if(ms_InDia.GetfValue()<=0)
		ref.Add(9);
	if(ms_Len.GetfValue()<=0)
		ref.Add(14);
	if(ms_WaveSpeed.GetfValue()<=0)//因为稳态算法使用特征线所以只计算稳态也需要输入波速与aft不同
		ref.Add(18);
	switch(ms_LossType.GetnValue()) {
	case 0:
	case 1:
	case 3:
	case 4:
		if(ms_Friction.GetfValue()<=0)
			ref.Add(19);
		break;
	default:
		break;
	}
}
