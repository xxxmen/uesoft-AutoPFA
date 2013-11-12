// PipeIDFlyWeight.h: interface for the PipeIDFlyWeight class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIPEIDFLYWEIGHT_H__782B3DE9_5473_463D_9F29_3CBA84F5D7A4__INCLUDED_)
#define AFX_PIPEIDFLYWEIGHT_H__782B3DE9_5473_463D_9F29_3CBA84F5D7A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FlyWeight.h"
#include "ListFlyWeightImp.h"

class PipeIDFlyWeight : public FlyWeight  
{
public:
	void SetNull();
	void SetData(const ListImp<StrArray<1> > &ref);
	void GetData(ListImp<StrArray<1> >&ref);
	BOOL IsExist(int nKey);
	int GetCount()const;
	void Empty();
	void DelItem(int nKey);
	void AddItem(CString strKey);
	void AddItem(int nKey);
	BOOL GetValue(CString &StrValue,CString &strUnit)const;
	BOOL GetValue(CString &strValue)const;
	virtual BOOL IsEqual(FlyWeight &ref)const;
	virtual void Assign(FlyWeight *pFly);
	virtual BOOL IsEmpty()const;
	static FlyWeight* CreatPipeIDFlyWeight();
	Iterator<int>* CreatIterator()const;
	PipeIDFlyWeight();
	virtual ~PipeIDFlyWeight();
	PipeIDFlyWeight(const PipeIDFlyWeight &ref);
	PipeIDFlyWeight& operator=(const PipeIDFlyWeight &ref);

private:
	virtual FlyWeight*  DoClone();
	ListImp<int> m_list;
};


#endif // !defined(AFX_PIPEIDFLYWEIGHT_H__782B3DE9_5473_463D_9F29_3CBA84F5D7A4__INCLUDED_)
