
#include "stdafx.h"
#include "resource.h"
#include "GlobalUse.h"
#include "PipeIDFlyWeight.h"
#include "GridCtrl.h"
#include "UnitSubSystem.h"
#include "NumFlyWeight.h"
#include "ArrayFlyWeight.h"
#include "ComponentManager.h"
#include "TransDataTable.h"
#include "QuantityManager.h"
#include <vector>

#define SQR(a) (a==0.0 ? 0.0:a*a)

void Combine(CDialog *pParent,CWnd& box,CDialog& child)
{
	CRect rc;
	box.GetWindowRect(&rc);
	pParent->ScreenToClient(&rc);
	rc.DeflateRect(3,3,3,3);
	child.MoveWindow(rc);
	child.ShowWindow(SW_SHOW);
}

void InitPipeDir(PipeIDFlyWeight &list,CGridCtrl& grid)
{
	int nID =0;
	CString strTemp;
	int nRow=0;
	IteratorPtr<int> IdItPtr(list.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		nID = IdItPtr->CurrentItem();
		strTemp.Format(_T("%d"),abs(nID));
		nRow = grid.InsertRow(strTemp);
		if(nID>0)
		{
			grid.SetItemText(nRow,1,_T("流入"));
		}
		else
		{
			grid.SetItemText(nRow,1,_T("流出"));
		}
	}
}
void InitTable(TransDataTable<3> &list,CGridCtrl& grid)
{
	LoadTable(list,grid,0);
}

BOOL UpDataTable(TransDataTable<3> &list,CGridCtrl& grid)
{
	return SaveTable(list,grid,0,TRUE);
}
void InitTable(TransDataTable<2> &list,CGridCtrl& grid)
{
	LoadTable(list,grid);
}

BOOL UpDataTable(TransDataTable<2> &list,CGridCtrl& grid)
{
	return SaveTable(list,grid);
}
void InitUnitCbo(UnitSubSystem &system,UnitTypeID id,CComboBox& cboBox,CString &m_strCurSymbol)
{
	cboBox.ResetContent();
	SymbolArray array;
	system.FindSymbolArray(id,array);
	for(int i=0;i<array.GetSize();i++)
	{
		cboBox.AddString(array.GetAt(i));
	}
	if( CB_ERR  == cboBox.SelectString(-1,m_strCurSymbol))
	{
		m_strCurSymbol = system.FindCurSymbol(id);
		cboBox.SelectString(-1,m_strCurSymbol);
	}
	
}
UnitTypeID InitFlowUnitCbo(UnitSubSystem &system,int nType,CComboBox& cboBox,CString &m_strCurSymbol)
{
	//流量类型0：体积流量，1：质量流量
	switch(nType) {
	case 0:
		InitUnitCbo(system,VolumetricFlow,cboBox,m_strCurSymbol);
		return VolumetricFlow;
		break;
	case 1:
		InitUnitCbo(system,MassFlow,cboBox,m_strCurSymbol);
		return MassFlow;
		break;
	default:
		cboBox.ResetContent();
		return VolumetricFlow;
		break;
	}
}
UnitTypeID InitPressUnitCbo(UnitSubSystem &system,int nType,CComboBox& cboBox,CString &m_strCurSymbol)
{
	//压力类型0：水头1：压力
	switch(nType) {
	case 0:
	case 2:
		InitUnitCbo(system,Length,cboBox,m_strCurSymbol);
		return Length;
		break;
	case 1:
	case 3:
		InitUnitCbo(system,Pressure,cboBox,m_strCurSymbol);
		return Pressure;
		break;
	default:
		cboBox.ResetContent();
		return Pressure;
		break;
	}
}
UnitTypeID InitPowerUnitCbo(UnitSubSystem &system,int nType,CComboBox& cboBox,CString &m_strCurSymbol)
{
	switch(nType) {
	case 0:
		InitUnitCbo(system,PercentFractional,cboBox,m_strCurSymbol);
		return PercentFractional;
		break;
	case 1:
		InitUnitCbo(system,Power,cboBox,m_strCurSymbol);
		return Power;
		break;
	default:
		cboBox.ResetContent();
		return PercentFractional;
		break;
	}
}
CString PowerName(int nType)
{
	CString strRet;
	switch(nType) {
	case 0:
		strRet.LoadString(IDS_STREFFICENCY);
		break;
	case 1:
		strRet.LoadString(IDS_STRPOWER);
		break;
	default:
		ASSERT(FALSE);
		break;
	}
	return strRet;
}
CString PressName(int nType)
{
	CString strRet;
	switch(nType) {
	case 0:
	case 2:
		strRet.LoadString(IDS_STRHEAD);
		break;
	case 1:
	case 3:
		strRet.LoadString(IDS_STRPRESSURE);
		break;
	default:
		ASSERT(FALSE);
		break;
	}
	return strRet;
}

CString FlowName(int nType)
{
	CString strRet;
	switch(nType) {
	case 0:
		strRet.LoadString(IDS_STRVOLUMEFLOW);
		break;
	case 1:
		strRet.LoadString(IDS_STRMASSFLOW);
		break;
	default:
		ASSERT(FALSE);
		break;
	}
	return strRet;
}

void InitNum(CString &strValue,CString &strUnit,NumFlyWeight &num)
{
	strValue = num.GetValue();
	CString strTemp = num.GetUnit();
	if(!strValue.IsEmpty()
	   && !strTemp.IsEmpty()
	   && strTemp.CompareNoCase(_T("None"))!=0)
		strUnit  = strTemp;
}

BOOL TransformToStd( double& dOut,CString strCurUnit,double d )
{
	QuantityManager& qm = QuantityManager::Instance();
	if(!qm.TransformToStd(dOut,strCurUnit.GetBuffer(0),d))
	{
		dOut = d;
	}
	return TRUE;
}
BOOL TransformFromStd( double& dOut,CString strDesUnit,double d )
{
	QuantityManager& qm = QuantityManager::Instance();
	if(!qm.TransformFromStd(dOut,strDesUnit.GetBuffer(0),d))
	{
		dOut = d;
	}
	return TRUE;
}
double TransformFromStd(double dIn,CString strCurUnit)
{
	double dOut =0;
	TransformFromStd(dOut,strCurUnit,dIn);
	return dOut;
}
void SetNum(CString strValue,CString strUnit,NumFlyWeight &num)
{
	num.SetValue(strValue);
	num.SetUnit(strUnit);
}
void InitTypeNum(int &nType,CString &strValue,CString &strUnit,ArrayFlyWeight<3> &num)
{
	nType = num.GetnValue();
	strValue = num.GetValue(1);
	CString strTemp = num.GetValue(2);
	if(!strValue.IsEmpty()
	   && !strTemp.IsEmpty()
	   && strTemp.CompareNoCase(_T("None"))!=0)
		strUnit  = strTemp;
}
void SetTypeNum(int nType,CString strValue,CString strUnit,ArrayFlyWeight<3> &num)
{
	CString strTemp;
	strTemp.Format(_T("%d"),nType);
	num.SetValue(strTemp);
	num.SetValue(strValue,1);
	num.SetValue(strUnit,2);
}
void InitDataCmb(const CmbDataItem DataItem[],int nNum,CComboBox& cboBox,int nCurSel)
{
	cboBox.ResetContent();
	int nIndex = 0;
	for(int i=0; i<nNum; i++)
	{
		nIndex = cboBox.InsertString(i,DataItem[i].m_strText);
		cboBox.SetItemData(i,DataItem[i].m_nKey);
		if(nCurSel == DataItem[i].m_nKey)
			cboBox.SetCurSel(nIndex);
	}
	HScroll(cboBox);
}

void HScroll(CComboBox& cboBox)
{
	CDC * dc=cboBox.GetDC();

    int maxLen=0;
	CString str ;
    for(int i=0;i<cboBox.GetCount();i++)
    {
		cboBox.GetLBText(i,str);
		CSize size=dc->GetTextExtent( str );
		if(size.cx>maxLen)
			maxLen=size.cx;
    }
	cboBox.ReleaseDC(dc);
	cboBox.SetHorizontalExtent(maxLen);
}

BOOL GetCurKey(CComboBox& cboBox,int &nKey)
{
	int Index = cboBox.GetCurSel();
	if(CB_ERR == Index)
		return FALSE;
	nKey = cboBox.GetItemData(Index);
	return TRUE;
}
BOOL SetSelKey(CComboBox& cboBox,int nKey)
{
	for(int i=0;i<cboBox.GetCount();i++)
	{
		if(nKey == cboBox.GetItemData(i))
		{
			cboBox.SetCurSel(i);
			return TRUE;
		}
	}
	return FALSE;
}
void InitPipeCmb(CComboBox& cboBox,ComponentManager &manager)
{
	cboBox.ResetContent();
	Component *pTemp;
	CString strText;
	CString strName;
	int nKey;
	int nIndex;
	IteratorPtr<Component> iteratorPtr(manager.CreatPipeIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pTemp = &iteratorPtr->CurrentItem();
		nKey = pTemp->GetKey();
		strName = pTemp->GetName();
		strText.Format(_T("%d(%s)"),nKey,strName);
		nIndex = cboBox.AddString(strText);
		cboBox.SetItemData(nIndex,nKey);
	}
	cboBox.SetCurSel(0);
}

void InitJunCmb(CComboBox& cboBox,ComponentManager &manager,int nID)
{
	cboBox.ResetContent();
	Component *pTemp;
	CString strText;
	CString strName;
	int nKey;
	int nIndex;
	IteratorPtr<Component> iteratorPtr(manager.CreatJunIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pTemp = &iteratorPtr->CurrentItem();
		if(nID == pTemp->GetID() || -1 == nID)
		{
			nKey = pTemp->GetKey();
			strName = pTemp->GetName();
			strText.Format(_T("%d(%s)"),nKey,strName);
			nIndex = cboBox.AddString(strText);
			cboBox.SetItemData(nIndex,nKey);
		}
	}
	cboBox.SetCurSel(0);
}
CString GetCmbText(CComboBox& cboBox)
{
	CString	 strRet;
	int nIndex = cboBox.GetCurSel();
	if(CB_ERR != nIndex)
	{
		cboBox.GetLBText(nIndex,strRet);
	}
	return strRet;
}


CString GetTitle(CString strName, CString strUnit)
{
	CString strHeader;
	if(strUnit.IsEmpty())
	{
		strHeader = strName;
	}
	else
	{
		strHeader = strName +_T("\n(") + strUnit+_T(")");
	}
	return strHeader;
}

/***************************************************************************/

void Polyfit(double *x, double *y, int ndat, double *a,int ma)
{
	lfit(x,y,ndat,a,ma);
	for(int i=0;i<ma/2;i++)
	{
		SWAP(*(a+i),*(a+ma-i-1));
	}
}
void lfit(double *x, double *y, int ndat, double *a,int ma)
{
	int i,j,k,l,m,mfit=0;
	double ym,wt,sum,sig2i;
	double chisq;

	double *afunc;		//(ma);
	afunc = new double[ma];

	double  **beta;		//(ma,1)
	beta = new double*[ma];
	int loop;
	for( loop=0; loop<ma; loop++)
		beta[loop] = new double[1];

	double *sig;		//(ndat);
	sig = new double[ndat];
	// 误差未知，置为1.0
	for(i=0; i<ndat; i++)
	{
		sig[i] = 1.0;
	}

	int *ia;
	ia = new int[ma];
	// 不固定，所有分量都拟合
	for(i=0; i<ma; i++)
	{
		ia[i] = 1;
	}
	
	// 协方差矩阵，不输出
	double  **covar;		//(ma,1)
	covar = new double*[ma];
	for(loop=0; loop<ma; loop++)
		covar[loop] = new double[ma];
	
	for (j=0;j<ma;j++)
		if (ia[j]) mfit++;
	if (mfit == 0) 
	{
		AfxMessageBox(_T("lfit: no parameters to be fitted"));
		return;
	}
	for (j=0;j<mfit;j++) {
		for (k=0;k<mfit;k++) covar[j][k]=0.0;
		beta[j][0]=0.0;
	}
	for (i=0;i<ndat;i++) {
		FitFunc(x[i],afunc,ma);
		ym=y[i];
		if (mfit < ma) {
			for (j=0;j<ma;j++)
				if (!ia[j]) ym -= a[j]*afunc[j];
		}
		sig2i=1.0/SQR(sig[i]);
		for (j=0,l=0;l<ma;l++) {
			if (ia[l]) {
				wt=afunc[l]*sig2i;
				for (k=0,m=0;m<=l;m++)
					if (ia[m]) covar[j][k++] += wt*afunc[m];
				beta[j++][0] += ym*wt;
			}
		}
	}
	for (j=1;j<mfit;j++)
		for (k=0;k<j;k++)
			covar[k][j]=covar[j][k];
	gaussj(covar,beta,mfit,1);
	for (j=0,l=0;l<ma;l++)
		if (ia[l]) a[l]=beta[j++][0];
	chisq=0.0;
	for (i=0;i<ndat;i++) {
		FitFunc(x[i],afunc,ma);
		sum=0.0;
		for (j=0;j<ma;j++) sum += a[j]*afunc[j];
		chisq += SQR((y[i]-sum)/sig[i]);
	}
	covsrt(covar,ma,ia,mfit);

	//释放内存
	if(afunc != NULL)
	{
		delete[] afunc;
	}
	if(sig != NULL)
	{
		delete[] sig;
	}
	if(ia != NULL)
	{
		delete[] ia;
	}
	if(beta != NULL)
	{
		for(loop=0; loop<ma; loop++)
		{
			delete[] beta[loop];
		}
		delete[] beta;
	}	
	if(covar != NULL)
	{
		for(loop=0; loop<ma; loop++)
		{
			delete[] covar[loop];
		}
		delete[] covar;
	}
}

void gaussj(double **a, double **b,int n,int m)
{
	int i,icol,irow,j,k,l,ll;
	double big,dum,pivinv;

	std::vector<int> indxc(n),indxr(n),ipiv(n);
	for (j=0;j<n;j++) ipiv[j]=0;
	for (i=0;i<n;i++) {
		big=0.0;
		for (j=0;j<n;j++)
			if (ipiv[j] != 1)
				for (k=0;k<n;k++) {
					if (ipiv[k] == 0) {
						if (fabs(a[j][k]) >= big) {
							big=fabs(a[j][k]);
							irow=j;
							icol=k;
						}
					}
				}
		++(ipiv[icol]);
		if (irow != icol) {
			for (l=0;l<n;l++) SWAP(a[irow][l],a[icol][l]);
			for (l=0;l<m;l++) SWAP(b[irow][l],b[icol][l]);
		}
		indxr[i]=irow;
		indxc[i]=icol;
		if (a[icol][icol] == 0.0) 
		{
			AfxMessageBox(_T("gaussj: Singular Matrix"));
			return;
		}
		pivinv=1.0/a[icol][icol];
		a[icol][icol]=1.0;
		for (l=0;l<n;l++) a[icol][l] *= pivinv;
		for (l=0;l<m;l++) b[icol][l] *= pivinv;
		for (ll=0;ll<n;ll++)
			if (ll != icol) {
				dum=a[ll][icol];
				a[ll][icol]=0.0;
				for (l=0;l<n;l++) a[ll][l] -= a[icol][l]*dum;
				for (l=0;l<m;l++) b[ll][l] -= b[icol][l]*dum;
			}
	}
	for (l=n-1;l>=0;l--) {
		if (indxr[l] != indxc[l])
			for (k=0;k<n;k++)
				SWAP(a[k][indxr[l]],a[k][indxc[l]]);
	}
}

void covsrt(double **covar,int ma, int *ia, const int mfit)
{
	int i,j,k;

	for (i=mfit;i<ma;i++)
		for (j=0;j<i+1;j++) covar[i][j]=covar[j][i]=0.0;
	k=mfit-1;
	for (j=ma-1;j>=0;j--) {
		if (ia[j]) {
			for (i=0;i<ma;i++) SWAP(covar[i][k],covar[i][j]);
			for (i=0;i<ma;i++) SWAP(covar[k][i],covar[j][i]);
			k--;
		}
	}
}

void FitFunc(const double x, double *y,int n)
{
	for(int i=0; i<n; i++)
	{
		y[i] = pow(x,n-1-i);
	}
}


