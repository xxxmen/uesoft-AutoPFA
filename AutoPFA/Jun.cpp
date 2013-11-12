// Jun.cpp: implementation of the Jun class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "Jun.h"
#include "JunGraphics.h"
#include "JunManipulator.h"
#include "PtFlyWeight.h"
#include "ComponentManager.h"
#include "Junperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const CmbDataItem  Jun::ms_BasisArea[]=
{
	    CmbDataItem(0,"上游管道面积"),
		CmbDataItem(1,"下游管道面积"),
		CmbDataItem(2,"用户指定面积"),
		CmbDataItem(3,"用户指定直径")
};
/*-------------------------------------------------*/
const CmbDataItem  Jun::ms_EventType[]=
{
	    CmbDataItem(8,"止回阀状态"),
		CmbDataItem(10,"控制阀状态"),
		CmbDataItem(6,"管道能量坡度线"),
		CmbDataItem(14,"节点能量坡度线差"),
		CmbDataItem(18,"管道能量坡度线差"),
		CmbDataItem(5,"管道水头坡度线"),
		CmbDataItem(13,"节点坡度线差"),
		CmbDataItem(17,"管道水头坡度线差"),
		CmbDataItem(3,"管道质量流量"),
		CmbDataItem(12,"节点滞止压力差"),
		CmbDataItem(16,"管道滞止压力差"),
		CmbDataItem(2,"节点滞止压力"),
		CmbDataItem(1,"管道滞止压力"),
		CmbDataItem(11,"节点静止压力差"),
		CmbDataItem(15,"管道静止压力差"),
		CmbDataItem(7,"泵转速"),
		CmbDataItem(9,"安全阀状态"),
		CmbDataItem(19,"喷嘴管口流量"),
		CmbDataItem(20,"调压塔坡度线"),
		CmbDataItem(21,"调压塔流体高度"),
		CmbDataItem(0,"绝对时间"),
		CmbDataItem(23,"相对时间"),
		CmbDataItem(22,"管道流速"),
		CmbDataItem(4,"管道体积流量")
};
/*-------------------------------------------------*/
const CmbDataItem  Jun::ms_Condition[]=
{
	    CmbDataItem(0,"大于"),
		CmbDataItem(1,"大于或等于"),
		CmbDataItem(2,"等于"),
		CmbDataItem(3,"小于或等于"),
		CmbDataItem(4,"小于")
};
/*-------------------------------------------------*/
const CmbDataItem  Jun::ms_ValveStatus[]=
{
	    CmbDataItem(0,"打开"),
		CmbDataItem(1,"关闭"),
		CmbDataItem(3,"开始打开"),
		CmbDataItem(4,"开始关闭")
};
/*-------------------------------------------------*/
const CmbDataItem  Jun::ms_PipePort[]=
{
		CmbDataItem(1,"入口端"),
		CmbDataItem(2,"出口端"),
};
/*-------------------------------------------------*/

const CmbDataItem  Jun::ms_CurveType[]=
{
		CmbDataItem(1,"多项式"),
		CmbDataItem(2,"内插值"),
};
/*-------------------------------------------------*/
KeyMap Jun::IDMap;
PtFlyWeight  Jun::ms_CenterPt;
NumFlyWeight Jun::ms_InletEle;
NumFlyWeight Jun::ms_OutletEle;
PipeIDFlyWeight Jun::ms_PipeID;
StrFlyWeight Jun::ms_DisignFactor;
StrFlyWeight Jun::ms_RawKey;
TransDataTable<2> Jun::ms_RawData;		
ArrayFlyWeight<3> Jun::ms_InitGuess;
ArrayFlyWeight<3> Jun::ms_SpecialMark;		


void Jun::Instance(NameArray &array)
{
	Component::Instance(array);
	ScenarioObject::InitAttr(array,IDS_JUNPOINT,2,3,FALSE);
	ScenarioObject::InitAttr(array,IDS_STRINELE,3,2);
	ScenarioObject::InitAttr(array,IDS_STROUTELE,4,2);
	ScenarioObject::InitAttr(array,IDS_STRCONECTPIPE,5,4);
	//以下key从100开始编号
	ScenarioObject::InitAttr(array,IDS_STRDESIGNFACTOR,100,1);
	ScenarioObject::InitAttr(array,IDS_STRINITGUESS,101,13);
	ScenarioObject::InitAttr(array,IDS_STRSPECIALMARK,102,13);
	ScenarioObject::InitAttr(array,103,1);
	ScenarioObject::InitAttr(array,104,12);//m_RawData.Unit
	ScenarioObject::InitAttr(array,105,32);//m_RawData.Data
}

Jun::Jun()
{
	m_nLinkPipeNum = 0;
}
Jun::Jun(const Jun &ref):Component(ref)
{
	m_nLinkPipeNum = ref.m_nLinkPipeNum;
}

Jun& Jun::operator=(const Jun &ref)
{
	//判断自赋值
	if(this == &ref)
		return *this;
    //调用基类赋值
	Component::operator =(ref);
	//释放堆内存
	//重新分配堆内存
	//赋值
	m_nLinkPipeNum = ref.m_nLinkPipeNum;
	return *this;
}
Jun::~Jun()
{

}

Graphics* Jun::GetGarph()
{
	return JunGraphics::Instance(this);
}

Manipulator* Jun::CreatManipulator(ComponentManager *pManager,int Size,BOOL bSingle)
{
	return JunManipulator::Instance(this,pManager,Size,bSingle);
}

BOOL Jun::Pick(CPoint point,int Size)
{
	return GetGarph()->Pick(point,Size);
}

BOOL Jun::Pick(CRect rc)
{
	return rc.PtInRect(CenterPt());
}

void Jun::Draw(CDC *pDc, WorkSpaceRef &ref)
{
	int nJunStyle = PS_SOLID;
	int nJunThick = 0;
	int nSize = ref.GetJunSize();
	COLORREF JunColor = RGB(255,255,255);
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
	GetGarph()->Draw(pDc,JunColor,nJunStyle,nJunThick,nSize);
}

CPoint Jun::CenterPt()
{
	CPoint pt;
	GetValue(ms_CenterPt,2);
	pt.x = _ttoi(ms_CenterPt.GetValue1());
	pt.y = _ttoi(ms_CenterPt.GetValue2());
	return pt;
}

void Jun::CenterPt(CPoint pt)
{
	ms_CenterPt.SetValue1(pt.x);
	ms_CenterPt.SetValue2(pt.y);
	SetValue(ms_CenterPt,2);
}
void Jun::InitAllData()
{
	//只在读文件调用
	GetValue(ms_CenterPt,2);
	GetValue(ms_PipeID,5);
	InitData();
}

void Jun::SaveAllData()
{
	//只在写文件调用
	SetValue(ms_CenterPt,2);
	SetValue(ms_PipeID,5);
	SaveData();
	m_nLinkPipeNum = ms_PipeID.GetCount();
}
void Jun::InitData()
{
	GetValue(ms_Name,1);
	GetValue(ms_InletEle,3);
	GetValue(ms_OutletEle,4);
	GetValue(ms_DisignFactor,100);
	GetValue(ms_InitGuess,101);
	GetValue(ms_SpecialMark,102);
	GetValue(ms_RawKey,103);
	GetValue(ms_RawData.m_Unit,104);
	GetValue(ms_RawData.m_Data,105);
}

void Jun::SaveData()
{
	SetValue(ms_Name,1);
	SetValue(ms_InletEle,3);
	SetValue(ms_OutletEle,4);
	SetValue(ms_DisignFactor,100);
	SetValue(ms_InitGuess,101);
	SetValue(ms_SpecialMark,102);
	SetValue(ms_RawKey,103);
	SetValue(ms_RawData.m_Unit,104);
	SetValue(ms_RawData.m_Data,105);
}

BOOL Jun::Read(Junperisist *pPerisist)
{
	ms_Name.SetValue(pPerisist->Name());
	ms_CenterPt.SetValue1(pPerisist->CenterPtX());
	ms_CenterPt.SetValue2(pPerisist->CenterPtY());
	ms_InletEle.SetValue(pPerisist->InEle());
	ms_InletEle.SetUnit(pPerisist->InEleUnit());
	ms_OutletEle.SetValue(pPerisist->OutEle());
	ms_OutletEle.SetUnit(pPerisist->OutEleUnit());
	ms_PipeID.SetData(pPerisist->m_list.GetData());
	ms_DisignFactor.SetValue(pPerisist->DesignFactor());
	ms_RawKey.SetValue(pPerisist->RawKey());
	ms_InitGuess.SetData(pPerisist->InitGuess());
	ms_SpecialMark.SetData(pPerisist->SpecialMark());
	ms_RawData.Read(pPerisist->m_RawData);
	AddID(pPerisist->RawKey());
	SaveAllData();
	return TRUE;
}

BOOL Jun::Save(Junperisist *pPerisist)
{	
 	InitAllData();
	pPerisist->ID(GetID());
	pPerisist->Key(GetKey());
	pPerisist->Name(ms_Name.GetValue());
	pPerisist->CenterPtX(ms_CenterPt.GetValue1());
    pPerisist->CenterPtY(ms_CenterPt.GetValue2());
	pPerisist->InEle(ms_InletEle.GetValue());
	pPerisist->InEleUnit(ms_InletEle.GetUnit());
	pPerisist->OutEle(ms_OutletEle.GetValue());
	pPerisist->OutEleUnit(ms_InletEle.GetUnit());
	ListImp<StrArray<1> > array;
	ms_PipeID.GetData(array);
	pPerisist->m_list.SetData(array,m_nLinkPipeNum);
	pPerisist->DesignFactor(ms_DisignFactor.GetValue());
	pPerisist->RawKey(ms_RawKey.GetValue());
	pPerisist->InitGuess(ms_InitGuess.GetData());
	pPerisist->SpecialMark(ms_SpecialMark.GetData());
	ms_RawData.Save(pPerisist->m_RawData,pPerisist->m_RawData.Data().GetCount());
	return TRUE;
}

void Jun::AddLinkPipe(ComponentManager *pManager,int nSize)
{
	//检查连接组件是否超过与管道的连接数量
	//如果没有超过与管道的连接数量设置连接关系
	CSize sz(16,16);
	sz.cx = sz.cx * (float(nSize)/100);
	sz.cy = sz.cy * (float(nSize)/100);

	CPoint pt = CenterPt();
	CRect rc(pt-sz,pt+sz);

	int nKey = 0;
	Component *pComponent = NULL;
	Pipe *pPipe = NULL;
	IteratorPtr<Component> PipeItPtr(pManager->CreatPipeIterator());
	for(PipeItPtr->Fist();!PipeItPtr->IsDone();PipeItPtr->Next())
	{
		pComponent = &PipeItPtr->CurrentItem();
		pPipe = dynamic_cast<Pipe*>(pComponent);
		if(0 ==pPipe->StartJun()
			&&rc.PtInRect(pPipe->StartPt()))
		{
			if(AddLinkPipe(-pPipe->GetKey()))
			{
				pPipe->StartPt(pt);
				pPipe->StartJun(GetKey());
			}
			return;
		}
		if(0 == pPipe->EndJun()
			&&rc.PtInRect(pPipe->EndPt()))
		{
			if(AddLinkPipe(pPipe->GetKey()))
			{
				pPipe->EndPt(pt);
				pPipe->EndJun(GetKey());
			}
		}
	}
}

void Jun::DelLinkPipe(int nKey)
{
	GetValue(ms_PipeID,5);
	ms_PipeID.DelItem(nKey);
	SetValue(ms_PipeID,5);
}
BOOL Jun::AddLinkPipe(int nKey)
{
	GetValue(ms_PipeID,5);
	int nNum = ms_PipeID.GetCount();
	if(CanLink(nNum,nKey))
	{
		ms_PipeID.AddItem(nKey);
		SetValue(ms_PipeID,5);
		AddLinkPipeInfo(abs(nKey));
		return TRUE;
	}
	return FALSE;
}
void Jun::ChangePosition(ComponentManager *pManager, CPoint pt, int nSize)
{
	ASSERT(pManager != NULL);
	GetValue(ms_PipeID,5);
	MoveLinkPipe(pManager,pt);
	CenterPt(pt);
	AddLinkPipe(pManager,nSize);
	SetValue(ms_PipeID,5);
}

void Jun::MoveLinkPipe(ComponentManager *pManager, CPoint pt)
{
	int nID = 0;
	int nKey = 0;
	Pipe *pPipe = NULL;
	IteratorPtr<int> IdItPtr(ms_PipeID.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		nID = IdItPtr->CurrentItem();
		nKey = abs(nID);
		pPipe = pManager->LookUpPipe(nKey);
		if(NULL != pPipe)
		{
			if(nID <0)
			{
				pPipe->StartPt(pt);
				pPipe->StartJun(GetKey());
			}
			else
			{
				pPipe->EndPt(pt);
				pPipe->EndJun(GetKey());
			}
		}
	}
}

BOOL Jun::IsExistInPipe()
{
	int nID = 0;
	IteratorPtr<int> IdItPtr(ms_PipeID.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		nID = IdItPtr->CurrentItem();
		if(nID >0)
		{
			return TRUE;
		}
	}
	return FALSE;
}

BOOL Jun::IsExistOutPipe()
{
	int nID = 0;
	IteratorPtr<int> IdItPtr(ms_PipeID.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		nID = IdItPtr->CurrentItem();
		if(nID < 0)
		{
			return TRUE;
		}
	}
	return FALSE;
}

void Jun::EmptyLinkPipe()
{
	ms_PipeID.Empty();
	SetValue(ms_PipeID,5);
	EmptyPipeInfo();
}

void Jun::EmptyLinkPipe(ComponentManager *pManager)
{
	GetValue(ms_PipeID,5);
	int nID = 0;
	int nKey = 0;
	Pipe *pPipe = NULL;
	IteratorPtr<int> IdItPtr(ms_PipeID.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		nID = IdItPtr->CurrentItem();
		nKey = abs(nID);
		pPipe = pManager->LookUpPipe(nKey);
		if(NULL != pPipe)
		{
			if(nID <0)
			{
				pPipe->StartJun(0);
			}
			else
			{
				pPipe->EndJun(0);
			}
		}
	}
	EmptyLinkPipe();
}

void Jun::AddPipeInfo(TableFlyWeight<4> &ref, int Key)
{
	Key = abs(Key);
	StrArray<4> item(Key);
	ref.AddItem(item,Key);
}

void Jun::DelPipeInfo(TableFlyWeight<4> &ref,int nKey)
{
	if(!(ms_PipeID.IsExist(nKey)||ms_PipeID.IsExist(-nKey)))
	{
		nKey = abs(nKey);
		ref.DelItem(nKey);
		ref.DelItem(-nKey);
	}
}

int Jun::ConnectPipeNum()
{
	GetValue(ms_PipeID,5);
	return ms_PipeID.GetCount();
}

void Jun::SetDesignFactor(CString strFactor)
{
	ms_DisignFactor.SetValue(strFactor);
	SetValue(ms_DisignFactor,100);
}

void Jun::SetPressType(CString strType)
{
	ms_InitGuess.SetValue(strType);
	SetValue(ms_InitGuess,101);
}

void Jun::SetSpecial(int nSpecial)
{
	ms_SpecialMark.SetValue(nSpecial);
	SetValue(ms_SpecialMark,102);
}

void Jun::InitCurve(ArrayFlyWeight<13> &ref)
{
	ref.SetValue(0,0);
	ref.SetValue(0,1);
	ref.SetValue(_T("None"),2);
	ref.SetValue(0,3);
	ref.SetValue(_T("None"),4);
	ref.SetValue(-1,5);
	ref.SetValue(1,6);
	ref.SetValue(5,7);
	ref.SetValue(0,8);
	ref.SetValue(0,9);
	ref.SetValue(0,10);
	ref.SetValue(0,11);
	ref.SetValue(0,12);
}

Transient* Jun::GetTransient()
{
	return NULL;//数据模型使用
}


void Jun::AddID(CString ID)
{
	if(ID.IsEmpty())//子工况
		return;
	CString strTemp(ID.GetAt(3));
	int nNum = _ttoi(strTemp);
	Jun::IDMap.SetAt(nNum,ID);
}

CString Jun::CreatID()
{
	int nNum = CreatKey(IDMap);
	CString strId;
	strId.Format(_T("RDS%d"),nNum);
	IDMap.SetAt(nNum,strId);
	return strId;
}
void Jun::CreatRawKey()
{
	ms_RawKey.SetValue(CreatID());
}

void Jun::Status(ComponentStatus &ref, BOOL bTrans)
{
	GetValue(ms_PipeID,5);
}
