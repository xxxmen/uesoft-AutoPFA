// ComponentManager.cpp: implementation of the ComponentManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "ComponentManager.h"
#include "FlyWeight.h"
#include "DrawJunTool.h"
#include "DrawPipeTool.h"
#include "MacroManipulator.h"
#include "JunManager.h"
#include "PipesManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ComponentManager::ComponentManager()
{
	m_pipeMap.RemoveAll();
	m_junMap.RemoveAll();
	m_factory = ComponentFactory::Instance();
}
ComponentManager::ComponentManager(const ComponentManager &ref)
{
	Clone(m_pipeMap,ref.m_pipeMap);
	Clone(m_junMap,ref.m_junMap);
	m_factory = ref.m_factory;
	m_sysProperties = ref.m_sysProperties;
}

ComponentManager& ComponentManager::operator=(const ComponentManager &ref)
{
	if(this == &ref)
		return *this;

	DelMap<Component>(m_pipeMap);
    DelMap<Component>(m_junMap);

    Clone(m_pipeMap,ref.m_pipeMap);
	Clone(m_junMap,ref.m_junMap);
	m_factory = ref.m_factory;
	m_sysProperties = ref.m_sysProperties;
	
	return *this;
}
ComponentManager::~ComponentManager()
{
	DelMap<Component>(m_pipeMap);
    DelMap<Component>(m_junMap);
}

void ComponentManager::DelState()
{
	DelState(m_pipeMap);
	DelState(m_junMap);
	m_sysProperties.DelState();	
}

FlyWeight* ComponentManager::LookUp(int nObjectType,int nObjectKey, int nStateKey)
{
	if(nObjectType > 9)
	{
		return m_sysProperties.LookUp(nObjectType,nObjectKey,nStateKey);
	}
	else
	{
		Component *pTemp = LookUp(nObjectType,nObjectKey);
		if(pTemp != NULL)
		{
			return pTemp->GetPrivate(nStateKey);
		}
		else
		{
			return NULL;
		}
	}
}

Component* ComponentManager::LookUp(int nObjectType,int nObjectKey)
{
	switch(nObjectType) 
	{
	case 1 :
		return LookMap<Component>(m_pipeMap,nObjectKey);
		break;
	case 2 :
		return LookMap<Component>(m_junMap,nObjectKey);
		break;
	default:
		return NULL;
		break;
	}
}

void ComponentManager::Delete(int nObjectType,int nObjectKey)
{
	Component *pComponent = LookUp(nObjectType,nObjectKey);
	if(pComponent != NULL)
	{
		switch(nObjectType) 
		{
		case 1 :
			m_pipeMap.RemoveKey(nObjectKey);
			break;
		case 2 :
			m_junMap.RemoveKey(nObjectKey);
			break;
		default:
			break;
		}
		delete pComponent;
	}
}

void ComponentManager::InitState(Scenario *pCurScenario)
{
	m_sysProperties.InitState(pCurScenario);
	InitState(m_pipeMap,pCurScenario);
	InitState(m_junMap,pCurScenario);
}

void ComponentManager::CloneChild(const ComponentManager &parent)
{
	m_sysProperties.CloneChild(parent.m_sysProperties);
	CloneChild(m_pipeMap,parent.m_pipeMap);
	CloneChild(m_junMap,parent.m_junMap);
	m_factory = parent.m_factory;
}

void ComponentManager::Promote(const ComponentManager &parent)
{
	m_sysProperties.Promote(parent.m_sysProperties);
	Promote(m_pipeMap,parent.m_pipeMap);
	Promote(m_junMap,parent.m_junMap);
}

void ComponentManager::Clone(ComponentMap &toMap,const ComponentMap &fromMap)
{
	POSITION pos = fromMap.GetStartPosition();
	Component *pTemp = NULL;
	int nKey;
	while(pos)
	{
		fromMap.GetNextAssoc(pos,nKey,pTemp);
		toMap.SetAt(nKey,dynamic_cast<Component*>(pTemp->Clone()));
	}
}

void ComponentManager::CloneChild(ComponentMap &toMap,const ComponentMap &fromMap)
{
	POSITION pos = fromMap.GetStartPosition();
	Component *pTemp = NULL;
	int nKey;
	while(pos)
	{
		fromMap.GetNextAssoc(pos,nKey,pTemp);
		toMap.SetAt(nKey,dynamic_cast<Component*>(pTemp->CloneChild()));
	}
}

void ComponentManager::Promote(ComponentMap &toMap,const ComponentMap &fromMap)
{
	POSITION pos = fromMap.GetStartPosition();
	Component *pParent = NULL;
	Component *pTemp = NULL;
	int nKey;
	while(pos)
	{
		fromMap.GetNextAssoc(pos,nKey,pParent);
		if(toMap.Lookup(nKey,pTemp))
		{
			pTemp->Promote(pParent);
		}
	}
}

void ComponentManager::DelState(ComponentMap &map)
{
	POSITION pos = map.GetStartPosition();
	Component *pTemp = NULL;
	int nKey;
	while(pos)
	{
		map.GetNextAssoc(pos,nKey,pTemp);
		pTemp->DelShareState();
	}
}

void ComponentManager::InitState(ComponentMap &map,Scenario *pCurScenario)
{
	POSITION pos = map.GetStartPosition();
	Component *pTemp = NULL;
	int nKey;
	while(pos)
	{
		map.GetNextAssoc(pos,nKey,pTemp);
		pTemp->InitState(pCurScenario);
	}
}

Manipulator* ComponentManager::CreatManipulator(int nID,CPoint point,int Size)
{
	Component *pComponent = NULL;
	Manipulator *pManipulator = NULL;
	switch(nID)
	{
		//选择存在的组件
	case -1:
		pComponent = Pick(point,Size);
		if(pComponent != NULL)
		{
			pManipulator = pComponent->CreatManipulator(this,Size);
		}
		break;
		//选择存在的多个组件
	case 101:
		pManipulator = CreatSelectTool(Size);
		break;
		//放大选择窗口
	case 102:
		break;
		//画管道
	case 0:
		pManipulator = CreatPipeTool(nID,Size);
		break;
		//画节点
	default:
		pManipulator = CreatJunTool(nID,Size);
		break;
	}

	return pManipulator;		
}

Manipulator* ComponentManager::CreatSelectTool(int Size)
{
	return MacroManipulator::Instance(this,Size);
}

void ComponentManager::InitSelectTool(CRect rc,MacroManipulator *pManipulator)
{
	POSITION  pos = m_junMap.GetStartPosition();
    Component *pComponent = NULL;
	int nKey;
	while(pos)
	{
		m_junMap.GetNextAssoc(pos,nKey,pComponent);
		if(pComponent->Pick(rc))
			pManipulator->Add(pComponent);
	}
	
	pos = m_pipeMap.GetStartPosition();
	while(pos)
	{
		m_pipeMap.GetNextAssoc(pos,nKey,pComponent);
		if(pComponent->Pick(rc))
			pManipulator->Add(pComponent);
	}
}

Manipulator* ComponentManager::CreatPipeTool(int nID,int Size)
{
	return DrawPipeTool::Instance(this,Size,nID);
}

Manipulator* ComponentManager::CreatJunTool(int nID,int Size)
{
	return DrawJunTool::Instance(this,Size,nID);
}
Component* ComponentManager::CreatComponent(Component* pPrototype)
{
	Component *pComponent = dynamic_cast<Component*>(pPrototype->Clone());
	pComponent->CloneShare(pPrototype);
	if(pComponent!=NULL)
	{
		Add(pComponent);
	}
	return pComponent;

}
Component* ComponentManager::CreatComponent(int nID)
{
	Component *pComponent = m_factory->CreatObject(nID);
	if(pComponent!=NULL)
	{
		Add(pComponent);
		InitComponent(pComponent);
	}
	return pComponent;
}

Iterator<Component>* ComponentManager::CreatPipeIterator()
{
	return new MapIterator<Component>(&m_pipeMap);
}

Iterator<Component>* ComponentManager::CreatJunIterator()
{
	return new MapIterator<Component>(&m_junMap);
}

int ComponentManager::GetPipeNum()
{
	return m_pipeMap.GetCount();
}

int ComponentManager::GetJunNum()
{
	return m_junMap.GetCount();
}

CRect ComponentManager::GetRect()
{
	int nMinx=0;
	int nMiny=0;
	int nMaxx=0;
	int nMaxy=0;
	CPoint junCenter;
	CPoint startPt;
	CPoint endPt;
	POSITION pos = m_pipeMap.GetStartPosition();
	Component *pComponent = NULL;
    Pipe *pPipe = NULL;
	int nKey;
	if(pos)
	{
		m_pipeMap.GetNextAssoc(pos,nKey,pComponent);
		pPipe = dynamic_cast<Pipe*>(pComponent);
        startPt = pPipe->StartPt();
		endPt   = pPipe->EndPt();
		nMinx =startPt.x;
		nMiny =startPt.y;
		nMinx =min(nMinx,endPt.x);
		nMiny =min(nMiny,endPt.y);
		nMaxx =max(nMaxx,startPt.x);
		nMaxy =max(nMaxy,startPt.y);
		nMaxx =max(nMaxx,endPt.x);
		nMaxy =max(nMaxy,endPt.y);
	}
	while(pos)
	{
		m_pipeMap.GetNextAssoc(pos,nKey,pComponent);
		pPipe = dynamic_cast<Pipe*>(pComponent);
        startPt = pPipe->StartPt();
		endPt   = pPipe->EndPt();
		nMinx =min(nMinx,startPt.x);
		nMiny =min(nMiny,startPt.y);
		nMaxx =max(nMaxx,startPt.x);
		nMaxy =max(nMaxy,startPt.y);
		nMinx =min(nMinx,endPt.x);
		nMiny =min(nMiny,endPt.y);
		nMaxx =max(nMaxx,endPt.x);
		nMaxy =max(nMaxy,endPt.y);
	}

	Jun *pJun = NULL;
	pos = m_junMap.GetStartPosition();
	if(pos)
	{
		m_junMap.GetNextAssoc(pos,nKey,pComponent);
        pJun = dynamic_cast<Jun*>(pComponent);
		junCenter = pJun->CenterPt();
		
		if(nMinx == nMiny && nMinx ==0)
		{
			nMinx =junCenter.x;
			nMiny =junCenter.y;	
		}
		else
		{
			nMinx =min(nMinx,junCenter.x);
			nMiny =min(nMiny,junCenter.y);
		}
		nMaxx =max(nMaxx,junCenter.x);
		nMaxy =max(nMaxy,junCenter.y);
	}
	while(pos)
	{
		m_junMap.GetNextAssoc(pos,nKey,pComponent);
        pJun = dynamic_cast<Jun*>(pComponent);
		junCenter = pJun->CenterPt();
		
		nMinx =min(nMinx,junCenter.x);
		nMiny =min(nMiny,junCenter.y);
		nMaxx =max(nMaxx,junCenter.x);
		nMaxy =max(nMaxy,junCenter.y);
	}
    CRect rc(nMinx,nMiny,nMaxx,nMaxy);
	return rc;
}

Component* ComponentManager::Pick(CPoint point,int Size)
{
	POSITION  pos = m_junMap.GetStartPosition();
    Component *pComponent = NULL;
	int nKey;
	while(pos)
	{
		m_junMap.GetNextAssoc(pos,nKey,pComponent);
		if(pComponent->Pick(point,Size))
		     return pComponent;
	}
	
	pos = m_pipeMap.GetStartPosition();
	while(pos)
	{
		m_pipeMap.GetNextAssoc(pos,nKey,pComponent);
		if(pComponent->Pick(point))
			return pComponent;
	}
	return NULL;
}

void ComponentManager::Draw(CDC *pDc,WorkSpaceRef &ref)
{
	POSITION pos = m_pipeMap.GetStartPosition();
    Component *pComponent = NULL;
	int nKey;
	while(pos)
	{
		m_pipeMap.GetNextAssoc(pos,nKey,pComponent);
		pComponent->Draw(pDc,ref);
	}

	pos = m_junMap.GetStartPosition();
	while(pos)
	{
		m_junMap.GetNextAssoc(pos,nKey,pComponent);
		pComponent->Draw(pDc,ref);
	}
}


void ComponentManager::Add(Component* pComponent)
{
	int nKey;
	int nID = pComponent->GetType();
	if(1 == nID)
	{
		nKey = CreatKey<Component>(m_pipeMap);
		pComponent->SetKey(nKey);
		m_pipeMap.SetAt(nKey,pComponent);
	}
	else
	{
		nKey = CreatKey<Component>(m_junMap);
		pComponent->SetKey(nKey);
		m_junMap.SetAt(nKey,pComponent);
	}
}

Component* ComponentManager::CreatComponent(int nID,int nKey)
{
	Component *pComponent = m_factory->CreatObject(nID);
	if(pComponent!=NULL)
	{
		pComponent->SetKey(nKey);
		int nID = pComponent->GetType();
		if(1 == nID)
		{
			m_pipeMap.SetAt(nKey,pComponent);
		}
		else
		{
			m_junMap.SetAt(nKey,pComponent);
		}
	}
	return pComponent;
}

BOOL ComponentManager::Read(JunManager &junMgr)
{
	Component *pComponent = NULL;
	Jun *pJun = NULL;
	Junperisist *pJunPerisit = NULL;
	int iID =-1;
	int iKey = -1;
	
	IteratorPtr<Junperisist> JunitPtr(junMgr.CreateIt());
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
		pJunPerisit = &JunitPtr->CurrentItem();
		iID = pJunPerisit->ID();
		iKey = pJunPerisit->Key();
		pComponent = LookUp(2,iKey);//查找iKey对应的节点
		if(pComponent == NULL)
		{
			pComponent = CreatComponent(iID,iKey);
		}
		if(pComponent != NULL)
		{
			pJun = dynamic_cast<Jun*>(pComponent);
			pJun->Read(pJunPerisit);
		}
	}
	return TRUE;
}

BOOL ComponentManager::Read(PipesManager &PipesMgr)
{
	Component *pComponent = NULL;
	Pipe *pPipe = NULL;
	PipePerisist *pPipePerisit = NULL;
	int iKey = -1;
	
	IteratorPtr<PipePerisist> PipeitPtr(PipesMgr.CreateIt());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pPipePerisit = &PipeitPtr->CurrentItem();
		iKey = pPipePerisit->Key();
		pComponent = LookUp(1,iKey);//查找iKey对应的管道
		if(pComponent == NULL)
		{
			pComponent = CreatComponent(0,iKey);
		}
		if(pComponent != NULL)
		{
			pPipe = dynamic_cast<Pipe*>(pComponent);
			pPipe->Read(pPipePerisit);
		}
	}
	return TRUE;
}

BOOL ComponentManager::Read(PropertyPersistent &sysProperty)
{
	return m_sysProperties.Read(sysProperty);
}

BOOL ComponentManager::Save(JunManager &junMgr)
{
	Component *pComponent = NULL;
	Jun *pJun = NULL;
	Junperisist *pJunPerisit = NULL;
	
	IteratorPtr<Component> JunitPtr(CreatJunIterator());
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
		pComponent = &JunitPtr->CurrentItem();
		if(pComponent->IsEmpty())
		{
			continue;
		}
		pJun = dynamic_cast<Jun*>(pComponent);
        pJunPerisit = junMgr.CreatJunperisist(pJun->GetID());
		if(NULL != pJunPerisit)
		{
			pJun->Save(pJunPerisit);
		}
		else
		{
			return FALSE;
		}
	}
	return TRUE;
}

BOOL ComponentManager::Save(PipesManager &PipesMgr)
{
	Component *pComponent = NULL;
	Pipe *pPipe = NULL;
	PipePerisist *pPipePerisit = NULL;
	
	IteratorPtr<Component> PipeitPtr(CreatPipeIterator());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pComponent = &PipeitPtr->CurrentItem();
		if(pComponent->IsEmpty())
		{
			continue;
		}
		pPipe = dynamic_cast<Pipe*>(pComponent);
		pPipePerisit = PipesMgr.CreatPipePerisit();
		pPipe->Save(pPipePerisit);
	}
	return TRUE;
}

BOOL ComponentManager::Save(PropertyPersistent &sysProperty)
{
	return m_sysProperties.Save(sysProperty);
}

Pipe* ComponentManager::LookUpPipe(int nObjectKey)
{
	Component *pComponent = LookUp(1,nObjectKey);
	if(NULL !=pComponent)
	{
		return dynamic_cast<Pipe*>(pComponent);	
	}
	else
	{
		return NULL;
	}
}

Jun* ComponentManager::LookUpJun(int nObjectKey)
{
	Component *pComponent = LookUp(2,nObjectKey);
	if(NULL !=pComponent)
	{
		return dynamic_cast<Jun*>(pComponent);	
	}
	else
	{
		return NULL;
	}
}


void ComponentManager::InitComponent(Component* pComponent)
{
	pComponent->SetName(pComponent->GetTypeName());
	pComponent->SetDesignFactor(_T("1"));
	pComponent->SetPressType(_T("0"));
}

BOOL ComponentManager::SearchControlPipe(Pipe *&pControlPipe)
{
	if(!IsAllPipeDefine(TRUE))
	{
		return FALSE;
	}

	Component *pComponent = NULL;
	Pipe *pPipe = NULL;
	double dStepTime = 9E+29;
	double dTemp = 0;
	IteratorPtr<Component> PipeitPtr(CreatPipeIterator());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pComponent = &PipeitPtr->CurrentItem();
		pPipe = dynamic_cast<Pipe*>(pComponent);
		dTemp = pPipe->StepTime();
		if(dTemp < dStepTime)
		{
			dStepTime = dTemp;
			pControlPipe = pPipe;
		}
	}
	return TRUE;
}

BOOL ComponentManager::IsAllJunDefine(BOOL bTrans)
{
	if(GetJunNum() < 2)
	{
		return FALSE;
	}
	Component *pComponent = NULL;
	IteratorPtr<Component> JunitPtr(CreatJunIterator());
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
		pComponent = &JunitPtr->CurrentItem();
		if(!pComponent->IsDefine(bTrans))
		{
			return FALSE;
		}
	}
	return TRUE;
}

BOOL ComponentManager::IsAllPipeDefine(BOOL bTrans)
{
	if(GetPipeNum() < 1)
	{
		return FALSE;
	}
	Component *pComponent = NULL;
	IteratorPtr<Component> PipeitPtr(CreatPipeIterator());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pComponent = &PipeitPtr->CurrentItem();
		if(!pComponent->IsDefine(bTrans))
		{
			return FALSE;
		}
	}
	return TRUE;
}

void ComponentManager::GetAllUndefinedPipes( ComponentMap* pUndefinedPipesMap )
{
	Component *pComponent = NULL;
	IteratorPtr<Component> PipeitPtr(CreatPipeIterator());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pComponent = &PipeitPtr->CurrentItem();
		if(!pComponent->IsDefine())
		{
			pUndefinedPipesMap->SetAt( pComponent->GetKey() , pComponent );
		}
	}
}

void ComponentManager::GetAllUndefinedJuns( ComponentMap* pUndefinedJunsMap)
{
   	Component *pComponent = NULL;
	IteratorPtr<Component> JunitPtr(CreatJunIterator());
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
		pComponent = &JunitPtr->CurrentItem();
		if(!pComponent->IsDefine())
		{
			pUndefinedJunsMap->SetAt( pComponent->GetKey() , pComponent );
		}
	}
}

void ComponentManager::SectionTable(ListImp<StrArray<8> > &table,double dStepTime)
{
	table.DelList();
	Component *pComponent = NULL;
	Pipe *pPipe = NULL;
	float dB = 0;
	StrArray<8> array;
	IteratorPtr<Component> PipeitPtr(CreatPipeIterator());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pComponent = &PipeitPtr->CurrentItem();
		pPipe = dynamic_cast<Pipe*>(pComponent);
		pPipe->SectionInfo(array,dStepTime);
		
		dB = array.fData(6)/(pPipe->CalcArea() * m_sysProperties.Gravity());
		array.Data(dB,7);
		table.AddItem(array);
	}
}

void ComponentManager::SaveSection(ListImp<StrArray<8> > &table)
{
	Pipe *pPipe = NULL;
	StrArray<8> array;
	IteratorPtr<StrArray<8> > itPtr(table.CreatIterator());
	for(itPtr->Fist();!itPtr->IsDone();itPtr->Next())
	{
		array = itPtr->CurrentItem();
		pPipe = LookUpPipe(array.nData());
		ASSERT(pPipe != NULL);
		{
			pPipe->SectionNum(array.nData(4));
			pPipe->SetB(array.Data(7));
		}
	}
}

BOOL ComponentManager::SearchSection(StrArray<5> &array,double dStepTime,double dMaxError)
{
	Component *pComponent = NULL;
	Pipe *pPipe = NULL;
	float dSum = 0;
	float dAverage = 0;
	float dMax = 0;
	double dError = 0;
	int nKey = 0;
	int nNum = 0;
	IteratorPtr<Component> PipeitPtr(CreatPipeIterator());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pComponent = &PipeitPtr->CurrentItem();
		pPipe = dynamic_cast<Pipe*>(pComponent);
		if(pPipe->CalcSection(nNum,dError,dStepTime,dMaxError))
		{
			if(fabs(dError) > dMax)
			{
				dMax = fabs(dError);
				nKey = pPipe->GetKey();
			}
			dSum += fabs(dError);
		}
		else
		{
			return FALSE;
		}
	}
	ASSERT(GetPipeNum() >0);
	dAverage = dSum / GetPipeNum();
	array.Data(dAverage,2);
	array.Data(dMax,3);
	array.Data(nKey,4);
	return TRUE;
}

void ComponentManager::CalcWave()
{
	Component *pComponent = NULL;
	Pipe *pPipe = NULL;
	IteratorPtr<Component> PipeitPtr(CreatPipeIterator());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pComponent = &PipeitPtr->CurrentItem();
		pPipe = dynamic_cast<Pipe*>(pComponent);
		pPipe->CalcWave(m_sysProperties.Density(),m_sysProperties.BulkModulus());
	}
}

double ComponentManager::GetPipeArea(int nKey)
{
	double dArea = 0;
	Pipe *pPipe = LookUpPipe(nKey);
	if(pPipe != NULL)
	{
		dArea = pPipe->CalcArea();
	}
	return dArea;
}

/************************************************************************
版本: 8.0  注释时间: [2009/3/25]  作者: [Zhufy] 评审人: 
功能:     根据所以管子的起点和终点的坐标来确定画缩略图矩形的大小                                                         
输入:                                                               
输出:     rect 得到的矩形的大小                                                         
< 修改人 >    < 时间 >     < 版本 >        < 描述 >                                                                               
************************************************************************/
void ComponentManager::GetSmallViewRect( CRect& rect )
{
	POSITION pos = m_pipeMap.GetStartPosition();
    Component *pComponent = NULL;
	int nKey;
	while(pos)
	{
		m_pipeMap.GetNextAssoc(pos,nKey,pComponent);
		Pipe* pPipe = ( Pipe* )pComponent;
		CPoint ptStart = pPipe->StartPt();
		CPoint ptEnd = pPipe->EndPt();
        if ( rect.IsRectNull() )
        {
			if ( ptStart.x > ptEnd.x )
			{
				rect.left = ptEnd.x;
			    rect.right = ptStart.x;
			}
			else
			{
				rect.left = ptStart.x;
			    rect.right = ptEnd.x;
			}

			if ( ptStart.y > ptEnd.y )
			{
				rect.top = ptEnd.y;
				rect.bottom = ptStart.y;
			}
			else
			{
				rect.top = ptStart.y;
				rect.bottom = ptEnd.y;
			}   
			continue;
        }
		if ( !rect.PtInRect( ptStart ) )
		{
			//判断起点的X坐标
			if ( ptStart.x < rect.left )
			{
				rect.left = ptStart.x;
			}
			else if ( ptStart.x > rect.right )
			{
				rect.right = ptStart.x;
			}
            //判断起点的Y坐标
			if ( ptStart.y < rect.top )
			{
				rect.top = ptStart.y;
			}
			else if ( ptStart.y > rect.bottom )
			{
				rect.bottom = ptStart.y;
			}
		}
		if ( !rect.PtInRect( ptEnd ) )
		{
			
			//判断终点的X坐标
			if ( ptEnd.x < rect.left )
			{
				rect.left = ptEnd.x;
			}
			else if ( ptEnd.x > rect.right )
			{
				rect.right = ptEnd.x;
			}
            //判断终点的Y坐标
			if ( ptEnd.y < rect.top )
			{
				rect.top = ptEnd.y;
			}
			else if ( ptEnd.y > rect.bottom )
			{
				rect.bottom = ptEnd.y;
			}
		}
	}

	//为图形居中显示设置上下和左右对称
	rect.bottom += rect.top;
	rect.right += rect.left;
	rect.left = 0;
	rect.top = 0;
}
