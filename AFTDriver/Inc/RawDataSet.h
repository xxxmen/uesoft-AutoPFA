// RawDataSet.h: interface for the RawDataSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RAWDATASET_H__2C5A6FDC_0451_4FD3_BF2E_956D083D613E__INCLUDED_)
#define AFX_RAWDATASET_H__2C5A6FDC_0451_4FD3_BF2E_956D083D613E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "persistentObj.h"
#include "RawDataTable.h"
#include "TableBase.h"

class  AFX_EXT_CLASS RawDataSet : public PersistentObj  
{
public:

	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	void Init();
	int GetRawDataNum();
	void SetRawDataNum(int nNum);
	Iterator<TableBase>* CreatIterator()const;
	
    template<UINT size> void CreatRawData(RawDataTable<size> *&pObj)
	{
		pObj = RawDataTable<size>::CreatRawDataTable();
		m_list.AddItem(pObj);
	};
	
	template<UINT size> BOOL FindRawData(RawDataTable<size> *&pData,CString strKey)
	{
		TableBase *pObj = NULL;
		IteratorPtr<TableBase> ItPtr(m_list.CreatIterator());
		for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
		{
			pObj = &ItPtr->CurrentItem();
			if(strKey.CompareNoCase(pObj->GetKey()) == 0)
			{
				ASSERT(size == pObj->GetColNum()+1);
				pData = dynamic_cast<RawDataTable<size>* >(pObj);
				return TRUE;
			}
		}
		return FALSE;
	};

public:
	void RemoveAll();
	RawDataSet();
	virtual ~RawDataSet();

private:
	RawDataSet(const RawDataSet &ref);
	RawDataSet& operator=(const RawDataSet &ref);
	RowObject m_NumOfRawData;
	ListImp<TableBase> m_list;

};

#endif // !defined(AFX_RAWDATASET_H__2C5A6FDC_0451_4FD3_BF2E_956D083D613E__INCLUDED_)
