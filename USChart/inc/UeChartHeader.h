// UeChartHeader.h: interface for the UeChartHeader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UECHARTHEADER_H__D833A76D_1DA2_40F1_959E_CD19373A8665__INCLUDED_)
#define AFX_UECHARTHEADER_H__D833A76D_1DA2_40F1_959E_CD19373A8665__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//计算多项式的值 

template<class T> void PolyValve(T dParme[],int ma,T dX,T &dY)
{
	dY = 0.0;
	for(int i=0;i<ma;i++)
	{
		dY+= pow(dX,i)*dParme[i];
	}
}
//得到线性插值
template<class T> BOOL LinearValue(T dXArray[],T dYArray[],int nDat,T dX,T &dY)
{
	if(nDat <=1)
		return FALSE;
	int nIndex1 = 0;
	int nIndex2 = nDat-1;
	for(int loop=0; loop<nDat; loop++)
	{
		if(dXArray[loop] <= dX)
		{//得到第一个小于dX的值的下标
			nIndex1 = loop;
			break;
		}
	}

	for( int iloop=nIndex1+1; iloop<nDat; iloop++)
	{
		if(dXArray[iloop]<=dX && dXArray[nIndex1] < dXArray[iloop])
		{//得到小于dX且更接近dX的下标
			nIndex1 = iloop;
		}
	}

	for( int nloop=nDat-1; nloop>=0; nloop--)
	{
		if(dXArray[nloop] >= dX)
		{//得到第一个大于dX的值的下标
			nIndex2 = nloop;
			break;
		}
	}
	for(int iloopTemp = nIndex2-1;  iloopTemp >= 0; iloopTemp--)
	{
		if(dXArray[iloopTemp]>=dX && dXArray[nIndex2] > dXArray[iloopTemp])
		{//得到大于dX且更接近dX的下标
			nIndex2 = iloopTemp;
		}
	}
	
	if(dX > dXArray[nIndex1] && dX < dXArray[nIndex2])
	{
		dY = dYArray[nIndex1] *(dX - dXArray[nIndex2])/(dXArray[nIndex1] - dXArray[nIndex2])
			+ dYArray[nIndex2] *(dX - dXArray[nIndex1])/(dXArray[nIndex2] - dXArray[nIndex1]);
		return TRUE;
	}
	if(nIndex1 == nIndex2)
	{
		dY = dYArray[nIndex1];
		return TRUE;
	}
	return FALSE;
}

//得到阶梯值
template<class T> BOOL StepValue(T dXArray[],T dYArray[],int nDat,T dX,T &dY)
{
	if(nDat <=1)
		return FALSE;
	int nIndex1 = 0;
	int nIndex2 = nDat-1;
	int loop = 0;
	for(loop=0; loop<nDat; loop++)
	{
		if(dXArray[loop] <= dX)
		{//得到第一个小于dX的值的下标
			nIndex1 = loop;
			break;
		}
	}
	for(loop=nIndex1+1; loop<nDat; loop++)
	{
		if(dXArray[loop]<=dX && dXArray[nIndex1] < dXArray[loop])
		{//得到小于dX且更接近dX的下标
			nIndex1 = loop;
		}
	}
	dY = dYArray[nIndex1];
	return TRUE;
}
template<class T> void MaxMin(T dArray[],int nDat,T &Max,T &Min)
{
	Max  = dArray[0];
	Min  = dArray[0];
	for(int i=1;i<nDat;i++)
	{
		Max = max(Max,dArray[i]);
		Min = min(Min,dArray[i]);
	}
}
#endif // !defined(AFX_UECHARTHEADER_H__D833A76D_1DA2_40F1_959E_CD19373A8665__INCLUDED_)
