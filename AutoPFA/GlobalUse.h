#ifndef GLOBALUSE_H
#define GLOBALUSE_H
class PipeIDFlyWeight;
class NumFlyWeight;
class CGridCtrl;
class UnitSubSystem;
template<UINT size>class TransDataTable;
template<UINT size>class ArrayFlyWeight;
template<class Item>class ListImp;
template<UINT size>class StrArray;
class ComponentManager;

class CmbDataItem
{
public:
	CmbDataItem(UINT nKey,CString strText)
	{
		m_nKey = nKey;
		m_strText = strText;
	};
	virtual ~CmbDataItem(){};
	
public:
	UINT m_nKey;
	CString m_strText;
};


void Combine(CDialog *pParent,CWnd& box,CDialog& child);
void InitPipeDir(PipeIDFlyWeight &list,CGridCtrl& grid);
void InitTable(TransDataTable<2> &list,CGridCtrl& grid);
BOOL UpDataTable(TransDataTable<2> &list,CGridCtrl& grid);
void InitTable(TransDataTable<3> &list,CGridCtrl& grid);
BOOL UpDataTable(TransDataTable<3> &list,CGridCtrl& grid);
void InitUnitCbo(UnitSubSystem &system,UnitTypeID id,CComboBox& cboBox,CString &m_strCurSymbol);
UnitTypeID InitFlowUnitCbo(UnitSubSystem &system,int nType,CComboBox& cboBox,CString &m_strCurSymbol);
UnitTypeID InitPressUnitCbo(UnitSubSystem &system,int nType,CComboBox& cboBox,CString &m_strCurSymbol);
UnitTypeID InitPowerUnitCbo(UnitSubSystem &system,int nType,CComboBox& cboBox,CString &m_strCurSymbol);

void InitDataCmb(const CmbDataItem DataItem[],int nNum,CComboBox& cboBox,int nCurSel =0);
BOOL TransformToStd( double& dOut,CString strCurUnit,double d );
BOOL TransformFromStd( double& dOut,CString strDesUnit,double d );
double TransformFromStd(double dIn,CString strCurUnit);
void InitNum(CString &strValue,CString &strUnit,NumFlyWeight &num);
void SetNum(CString strValue,CString strUnit,NumFlyWeight &num);
void InitTypeNum(int &nType,CString &strValue,CString &strUnit,ArrayFlyWeight<3> &num);
void SetTypeNum(int nType,CString strValue,CString strUnit,ArrayFlyWeight<3> &num);
void HScroll(CComboBox& cboBox);
BOOL GetCurKey(CComboBox& cboBox,int &nKey);
BOOL SetSelKey(CComboBox& cboBox,int nKey);
void InitPipeCmb(CComboBox& cboBox,ComponentManager &manager);
void InitJunCmb(CComboBox& cboBox,ComponentManager &manager,int nID = -1);
CString GetCmbText(CComboBox& cboBox);
CString GetTitle(CString strName, CString strUnit);
CString PowerName(int nType);
CString PressName(int nType);
CString FlowName(int nType);


template<UINT size> void InitNum(CString &strValue,CString &strUnit,const ArrayFlyWeight<size> &Array,int Index=0)
{
	ASSERT(Index+1 <size);
	strValue = Array.GetValue(Index);
	CString strTemp = Array.GetValue(Index+1);
	if(!strValue.IsEmpty()
	   && !strTemp.IsEmpty()
	   && strTemp.CompareNoCase(_T("None"))!=0)
		strUnit  = strTemp;
}

template<UINT size> void LoadTable(ListImp<StrArray<size> > &table,CGridCtrl& grid)
{
	StrArray<size> array;
	UINT nRow = 1;
	IteratorPtr<StrArray<size> > IdItPtr(table.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		array = IdItPtr->CurrentItem();
		for(int i = 0; i < size; i++)
		{
			grid.SetItemText(nRow,i,array.Data(i));
		}
		nRow++;
	}
}

template<UINT size> void LoadTable(TransDataTable<size> &list,CGridCtrl& grid,UINT nStart = 1)
{
	StrArray<size> array;
	UINT nRow = 1;
	int nIndex = 0;
	IteratorPtr<StrArray<size> > IdItPtr(list.Data().CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		array = IdItPtr->CurrentItem();
		nIndex = 0;
		for(UINT i = nStart; i < (size+nStart); i++)
		{
			if(array.Data(nIndex++).CompareNoCase(_T("-9E+29")) != 0)
				grid.SetItemText(nRow,i,array.Data(nIndex-1));
		}
		nRow++;
	}
}

template<UINT size>
void TranToCur(ListImp<StrArray<size> > &table,int nIndex,CString strUnit)
{
	ASSERT(size > nIndex);
	double dOut = 0;
	CString strValue;
	IteratorPtr<StrArray<size> > IdItPtr(table.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		StrArray<size> &Item = IdItPtr->CurrentItem();
		strValue = Item.Data(nIndex);
		if(strValue.CollateNoCase(_T("-9E+29"))==0)
			strValue.Empty();
		dOut = TransformFromStd(_tcstod(strValue, NULL),strUnit);
		Item.Data(float(dOut),nIndex);
	}
}

template<UINT size> void SaveTable(ListImp<StrArray<size> > &table,CGridCtrl& grid)
{
	table.DelList();
	CString strData;
	StrArray<size> array;
	UINT n = grid.GetRowCount();
	for(UINT i=1;i<n;i++)
	{
		for(UINT j=0;j<size;j++)
		{
			strData = grid.GetItemText(i,j);
			array.Data(strData,j);
		}
		table.AddItem(array);
	}
}

template<UINT size> BOOL SaveTable(TransDataTable<size> &list,CGridCtrl& grid,UINT nStart = 1,BOOL bALLData = FALSE)
{
	list.m_Data.SetNull();
	CString strData;
	StrArray<size> array;
	UINT n = grid.GetRowCount();
	for(UINT i=1;i<n;i++)
	{
		for(UINT j=nStart;j<(size+nStart);j++)
		{
			strData = grid.GetItemText(i,j);
			if(strData.IsEmpty())
			{
				if(j==nStart && !bALLData)
				{
					return TRUE;
				}
				else
				{
					strData = _T("-9E+29");
				}
			}
			array.Data(strData,j-nStart);
		}
		list.m_Data.AddItem(array);
	}
	return TRUE;
}

//ÇúÏßÄâºÏ
void Polyfit(double *x, double *y, int ndat, double *a,int ma);
void lfit(double *x, double *y, int ndat, double *a,int ma);
void FitFunc(const double x, double *y,int n);
void gaussj(double **a, double **b,int n,int m);
void covsrt(double **covar,int ma, int *ia, const int mfit);

template<class T>
void SWAP(T &a, T &b)
{T dum=a; a=b; b=dum;}
#endif
