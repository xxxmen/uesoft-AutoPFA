// NumFlyWeight.cpp: implementation of the NumFlyWeight class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "NumFlyWeight.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NumFlyWeight::NumFlyWeight()
{
	m_strValue = _T("0");
	m_strUnit  = _T("None");
}

NumFlyWeight::NumFlyWeight(const NumFlyWeight &ref):FlyWeight(ref)
{
	m_strValue = ref.m_strValue;
	m_strUnit = ref.m_strUnit;
}

NumFlyWeight& NumFlyWeight::operator=(const NumFlyWeight &ref)
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
	m_strUnit = ref.m_strUnit;
	return *this;
}
NumFlyWeight::~NumFlyWeight()
{

}

FlyWeight* NumFlyWeight::CreatNumFlyWeight()
{
	return new NumFlyWeight;
}

FlyWeight* NumFlyWeight::DoClone()
{
	return new NumFlyWeight(*this);
}


BOOL NumFlyWeight::IsEqual(FlyWeight &ref)const
{
	NumFlyWeight *pComp = NULL;
	if(typeid(*this)==typeid(ref))
	{
		pComp = dynamic_cast<NumFlyWeight*>(&ref);
	}
	else
	{
		return FALSE;
	}
	BOOL bRet = TRUE;
	if(m_strUnit.CompareNoCase(pComp->m_strUnit)!=0)
	{
		bRet = FALSE;
	}
	if(m_strValue.CompareNoCase(pComp->m_strValue)!=0)
	{
		bRet = FALSE;
	}
	return bRet;
}

void NumFlyWeight::Assign(FlyWeight *pFly)
{
	assert(typeid(*this)==typeid(*pFly));
	*this = *dynamic_cast<NumFlyWeight*>(pFly);
}


BOOL NumFlyWeight::IsEmpty()const
{
	if(m_strValue.IsEmpty()
		&&m_strUnit.IsEmpty())
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void NumFlyWeight::SetNull()
{
	m_strValue.Empty();
	m_strUnit.Empty();
}

StrArray<2> NumFlyWeight::GetData()
{
	StrArray<2> ret;
	ret.Data(m_strValue);
	ret.Data(m_strUnit,1);
	return ret;
}

void NumFlyWeight::SetData(const StrArray<2> &ref)
{
	m_strValue = ref.Data();
	m_strUnit  = ref.Data(1);
}

double NumFlyWeight::GetNum() const
{
	double dOut = 0.0;
	TransformToStd(dOut,m_strUnit,GetfValue());
	return dOut;
}
