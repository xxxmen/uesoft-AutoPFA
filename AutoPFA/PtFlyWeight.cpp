// PtFlyWeight.cpp: implementation of the PtFlyWeight class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "PtFlyWeight.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PtFlyWeight::PtFlyWeight()
{

}

PtFlyWeight::PtFlyWeight(const PtFlyWeight &ref):FlyWeight(ref)
{
	m_strValue1 = ref.m_strValue1;
	m_strValue2 = ref.m_strValue2;
	m_strValue3 = ref.m_strValue3;
}

PtFlyWeight& PtFlyWeight::operator=(const PtFlyWeight &ref)
{
	//判断自赋值
	if(this == &ref)
		return *this;
    //调用基类赋值
	FlyWeight::operator =(ref);
	//释放堆内存
	//重新分配堆内存
	//赋值
   	m_strValue1 = ref.m_strValue1;
	m_strValue2 = ref.m_strValue2;
	m_strValue3 = ref.m_strValue3;
	return *this;
}
PtFlyWeight::~PtFlyWeight()
{

}

FlyWeight* PtFlyWeight::CreatPtFlyWeight()
{
	return new PtFlyWeight;
}

FlyWeight* PtFlyWeight::DoClone()
{
	return new PtFlyWeight(*this);
}


BOOL PtFlyWeight::IsEqual(FlyWeight &ref)const
{
	PtFlyWeight *pComp = NULL;
	if(typeid(*this)==typeid(ref))
	{
		pComp = dynamic_cast<PtFlyWeight*>(&ref);
	}
	else
	{
		return FALSE;
	}
	BOOL bRet = TRUE;
	if(m_strValue1.CompareNoCase(pComp->m_strValue1)!=0
		||m_strValue2.CompareNoCase(pComp->m_strValue2)!=0
		||m_strValue3.CompareNoCase(pComp->m_strValue3)!=0)
	{
		bRet = FALSE;
	}
	return bRet;
}

void PtFlyWeight::Assign(FlyWeight *pFly)
{
	assert(typeid(*this)==typeid(*pFly));
	*this = *dynamic_cast<PtFlyWeight*>(pFly);
}

BOOL PtFlyWeight::IsEmpty()const
{
	if(m_strValue1.IsEmpty()
		&&m_strValue2.IsEmpty()
		&&m_strValue3.IsEmpty())
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void PtFlyWeight::SetNull()
{
	m_strValue1.Empty();
	m_strValue2.Empty();
	m_strValue3.Empty();
}
