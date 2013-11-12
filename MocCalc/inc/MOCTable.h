#ifndef MOCTABLE_H
#define MOCTABLE_H

#include "ListFlyWeightImp.h"
#include "UeChartHeader.h"
typedef double (*PFUNTRAN)(double);
typedef double (*PFUNTRAN2)(double,double);

template<UINT Size>
class MOCTable
{
public:
	virtual ~MOCTable() {};
	MOCTable(){};
	MOCTable(const MOCTable &ref);
	MOCTable& operator=(const MOCTable &ref);
	BOOL HasData();
	void SetData(const ListImp<StrArray<Size> > &ref);
	ListImp<StrArray<Size> >& GetData();
	double GetValue(double dXValue,BOOL bRepeat = FALSE,int nIndex = 1,int nXIndex=0);
	double GetSetpValue(double dXValue,int nIndex = 1);
	void Tran(PFUNTRAN pTran,int nIndex = 1);
	void Tran(PFUNTRAN2 pTran,double d,int nIndex = 1);
	BOOL GetMaxMin(double &dMax,double &dMin,int nIndex = 0);
private:
	double GetY(double dXValue,int nIndex,int nXIndex);
	ListImp<StrArray<Size> > m_list;	
};

template<UINT Size>
MOCTable<Size>::MOCTable(const MOCTable &ref)
{
	m_list = ref.m_list;
}

template<UINT Size>
MOCTable<Size>& MOCTable<Size>::operator=(const MOCTable &ref)
{
	m_list = ref.m_list;
	return *this;
}

template<UINT Size>
BOOL MOCTable<Size>::HasData()
{
	return !m_list.IsEmpty();
}
 
template<UINT Size>
void MOCTable<Size>::SetData(const ListImp<StrArray<Size> > &ref)
{
	m_list = ref;
}

template<UINT Size>
ListImp<StrArray<Size> >& MOCTable<Size>::GetData()
{
	return m_list;
}

template<UINT Size>
double MOCTable<Size>::GetSetpValue(double dXValue,int nIndex)
{
	double dY = 0;
	int nNum = m_list.GetCount();
	double dXArray[100]={0};
	double dYArray[100]={0};
	m_list.ToDuoble(dXArray,0);
	m_list.ToDuoble(dYArray,nIndex);
	StepValue(dXArray,dYArray,nNum,dXValue,dY);
	return dY;
}

template<UINT Size>
double MOCTable<Size>::GetY(double dXValue,int nIndex,int nXIndex)
{
	double dY = 0;
	int nNum = m_list.GetCount();
	double dXArray[100]={0};
	double dYArray[100]={0};
	m_list.ToDuoble(dXArray,nXIndex);
	m_list.ToDuoble(dYArray,nIndex);
	LinearValue(dXArray,dYArray,nNum,dXValue,dY);
	return dY;
}

template<UINT Size>
double MOCTable<Size>::GetValue(double dXValue,BOOL bRepeat,int nIndex,int nXIndex)
{
	if(bRepeat)
	{
		double dMinX = 0;
		double dMaxX = 0;
		m_list.GetMaxMin(dMaxX,dMinX);
		double dPeriod = dMaxX-dMinX;
		while(dXValue > dMaxX)
		{
			dXValue -= dPeriod;
		}
	}
	return GetY(dXValue,nIndex,nXIndex);
}

template<UINT Size>
void MOCTable<Size>::Tran(PFUNTRAN pTran,int nIndex)
{
	ASSERT(Size>nIndex);
	CString strData;
	IteratorPtr<StrArray<Size> > IdItPtr(m_list.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		StrArray<Size> &Item = IdItPtr->CurrentItem();
		Item.Data(pTran(double(Item.fData(nIndex))),nIndex);
	}
}

template<UINT Size>
void MOCTable<Size>::Tran(PFUNTRAN2 pTran,double d,int nIndex)
{
	ASSERT(Size>nIndex);
	CString strData;
	IteratorPtr<StrArray<Size> > IdItPtr(m_list.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		StrArray<Size> &Item = IdItPtr->CurrentItem();
		Item.Data(pTran(double(Item.fData(nIndex)),d),nIndex);
	}
}

template<UINT Size>
BOOL MOCTable<Size>::GetMaxMin(double &dMax,double &dMin,int nIndex)
{
	return m_list.GetMaxMin(dMax,dMin,nIndex);
}
typedef MOCTable<2> MOCCurveData;
typedef MOCTable<2> DataTable;
#endif