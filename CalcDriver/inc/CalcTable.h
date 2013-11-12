#ifndef CALCTABLE_H
#define CALCTABLE_H

#include "ListFlyWeightImp.h"

template<UINT Size>
class CalcTable
{
public:
	virtual ~CalcTable() {};
	CalcTable(){};
		
public:
    void AddItem(StrArray<Size> &item);
	void DelList();
	friend ostream& operator<< <>(ostream &CalcOut,CalcTable<Size> &ref);
	void SetData(const ListImp<StrArray<Size> > &ref);
	ListImp<StrArray<Size> >& GetData();
	Iterator<StrArray<Size> >* CreatIterator()const;
	int GetCount();
private:
	ListImp<StrArray<Size> > m_list;
	CalcTable(const CalcTable &ref);
	CalcTable& operator=(const CalcTable &ref);
};

template<UINT Size>
void CalcTable<Size>::AddItem(StrArray<Size> &item)
{
	m_list.AddItem(item);
}

template<UINT Size>
void CalcTable<Size>::DelList()
{
	m_list.DelList();
}

template<UINT Size>
void CalcTable<Size>::SetData(const ListImp<StrArray<Size> > &ref)
{
	m_list = ref;
}

template<UINT Size>
ListImp<StrArray<Size> >& CalcTable<Size>::GetData()
{
	return m_list;
}

template<UINT Size>
Iterator<StrArray<Size> >* CalcTable<Size>::CreatIterator()const
{
	return m_list.CreatIterator();
}

template<UINT Size>
int CalcTable<Size>::GetCount()
{
	return m_list.GetCount();
}

template<UINT Size>
ostream& operator<< (ostream &CalcOut,CalcTable<Size> &ref)
{
	CalcOut<<ref.GetCount()<<s_Separator;
	StrArray<Size> Item;
	CString strData;
	IteratorPtr<StrArray<Size> > IdItPtr(ref.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		Item = IdItPtr->CurrentItem();
		for(int i=0;i<Size;i++)
		{
			strData = Item.Data(i);
			if(-1 == strData.Find('.'))
			{
				CalcOut<<_ttoi(strData)<<s_Separator;
			}
			else
			{
				CalcOut<<_tcstod(strData , '\0')<<s_Separator;
			}
			
		}
	}
	return CalcOut;
}


typedef CalcTable<1>  PipeIDList;
typedef CalcTable<2>  TransTable;
#endif