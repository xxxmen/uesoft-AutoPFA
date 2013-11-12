// StrFlyWeight.cpp: implementation of the StrFlyWeight class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "StrFlyWeight.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StrFlyWeight::StrFlyWeight()
{
}

StrFlyWeight::StrFlyWeight(const StrFlyWeight &ref):FlyWeight(ref)
{
	m_strValue = ref.m_strValue;
}

StrFlyWeight& StrFlyWeight::operator=(const StrFlyWeight &ref)
{
	//判断自赋值
	if(this == &ref)
		return *this;
    //调用基类赋值
	FlyWeight::operator =(ref);
	//释放堆内存
	//重新分配堆内存
	//赋值
	m_strValue = ref.m_strValue;
	return *this;
}

StrFlyWeight::~StrFlyWeight()
{

}

FlyWeight* StrFlyWeight::CreatStrFlyWeight()
{
	return new StrFlyWeight;
}

FlyWeight* StrFlyWeight::DoClone()
{
	return new StrFlyWeight(*this);
}



BOOL StrFlyWeight::IsEqual(FlyWeight &ref)const
{
	StrFlyWeight *pComp = NULL;
	if(typeid(*this)==typeid(ref))
	{
		pComp = dynamic_cast<StrFlyWeight*>(&ref);
	}
	else
	{
		return FALSE;
	}
	BOOL bRet = TRUE;
	if(m_strValue.CompareNoCase(pComp->m_strValue)!=0)
	{
		bRet = FALSE;
	}
	return bRet;
}

void StrFlyWeight::Assign(FlyWeight *pFly)
{
	assert(typeid(*this)==typeid(*pFly));
	*this = *dynamic_cast<StrFlyWeight*>(pFly);
}


BOOL StrFlyWeight::IsEmpty()const
{
	return m_strValue.IsEmpty();
}

void StrFlyWeight::SetNull()
{
	m_strValue.Empty();
}
