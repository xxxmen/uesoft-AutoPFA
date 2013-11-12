// PipeStmOut.cpp: implementation of the PipeStmOut class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PipeStmOut.h"
#include "OutPutSystem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PipeStmOut::PipeStmOut()
{

}

PipeStmOut::~PipeStmOut()
{
	
}

void PipeStmOut::Instance(OutAttrArray &array,UnitSubSystem &unitsys,OutputRefPersist &OutPutData,PipeOutShowArray &ShowPipeArray,OutPutSystem &OutPutSys)
{

	CString str[50];
	CString str1[50];//保存Key;
	CString strTemp;
	CString strTemp1;

	int i = 0;
	int j = 0;
	int n = 0;
	strTemp1=OutPutData.PipeDataOrder();
	strTemp=OutPutData.PipeUnitOrder();

	InitData(strTemp1,str1);
	InitUnit(strTemp,str);
	OutPutSys.InitOutPutSystem();
	OutPutSys.GetPipeOutArray().GetData();
//	OutPutData.PipeDataOrder(str1);
//	OutPutData.PipeUnitOrder(str);

	ComponentStmOut::InitAttr(array,unitsys,0,_T("管道"));
	for (i=0;i<50;i++)
	{
		for (j=0;j<50;j++)
		{
			if (str1[j]!="0"&&str1[j]==OutPutSys.GetPipeOutArray()[i].GetKey())
			{
				n = 1 ; 
				ComponentStmOut::InitAttr(array,unitsys,i,OutPutSys.GetPipeOutArray()[i].GetTypeId(),str[j],OutPutSys.GetPipeOutArray()[i].GetStrName());
				//判断是否为输出项，根据输出要求初始化输出数组
				break;
				//	ComponentStmOut::InitAttr(array,unitsys,i,OutPutSys.GetPipeOutArray()[i].GetTypeId(),OutPutSys.GetPipeOutArray()[i].GetStrName());	
			}
		}
		if (n == 0)
		{
			ComponentStmOut::InitAttr(array,unitsys,i,OutPutSys.GetPipeOutArray()[i].GetTypeId(),OutPutSys.GetPipeOutArray()[i].GetStrName());	
		}
		n=0;
	}
}

/*----------------------------------------------*/
void PipeStmOut::SetMassFlow(double dValue)
{
	SetValue(dValue,1);
}

/*----------------------------------------------*/
void PipeStmOut::SetVolumeFlow(double dValue)
{
	SetValue(dValue,2);
}

/*----------------------------------------------*/
void PipeStmOut::SetVelocity(double dValue)
{
	SetValue(dValue,3);
}

/*----------------------------------------------*/
void PipeStmOut::SetInStagPress(double dValue)
{
	SetValue(dValue,4);
}

/*----------------------------------------------*/
void PipeStmOut::SetOutStagPress(double dValue)
{
	SetValue(dValue,5);
}

/*----------------------------------------------*/
void PipeStmOut::SetStagPressLoss(double dValue)
{
	SetValue(dValue,6);
}

/*----------------------------------------------*/
void PipeStmOut::SetInStaticPress(double dValue)
{
	SetValue(dValue,7);
}

/*----------------------------------------------*/
void PipeStmOut::SetOutStaticPress(double dValue)
{
	SetValue(dValue,8);
}

/*----------------------------------------------*/
void PipeStmOut::SetStaticPressLoss(double dValue)
{
	SetValue(dValue,9);
}

/*----------------------------------------------*/
void PipeStmOut::SetHLoss(double dValue)
{
	SetValue(dValue,10);
}

/*----------------------------------------------*/
void PipeStmOut::SetGLoss(double dValue)
{
	SetValue(dValue,11);
}

/*----------------------------------------------*/
void PipeStmOut::SetFLoss(double dValue)
{
	SetValue(dValue,12);
}

/*----------------------------------------------*/
void PipeStmOut::SetLossFactorF(double dValue)
{
	SetValue(dValue,13);
}

/*----------------------------------------------*/
void PipeStmOut::SetLossFactorT(double dValue)
{
	SetValue(dValue,14);
}

/*----------------------------------------------*/
void PipeStmOut::SetInEGL(double dValue)
{
	SetValue(dValue,15);
}

/*----------------------------------------------*/
void PipeStmOut::SetOutEGL(double dValue)
{
	SetValue(dValue,16);
}

/*----------------------------------------------*/
void PipeStmOut::SetInHGL(double dValue)
{
	SetValue(dValue,17);
}

/*----------------------------------------------*/
void PipeStmOut::SetOutHGL(double dValue)
{
	SetValue(dValue,18);
}


CString PipeStmOut::ReadUnitOrder(LPCTSTR filename)
{
	
	CStdioFile File;
	CString strTemp;
	if (!File.Open(filename,CFile::modeRead|CFile::typeText))
	{
		return strTemp;
	}
	File.ReadString(strTemp);
	File.Close();
	return strTemp;
}



void PipeStmOut::InitUnit(CString InData,CString str[50],TCHAR chSeparator)
{
	InData.TrimLeft();
	int nIdex=0;
	int unitj=0;
	for (int i=0;i<50;i++)
	{
		nIdex=InData.Find(chSeparator);
		unitj++;
		if (nIdex==-1)
		{
			InData.TrimRight();
			str[unitj-1]=InData;
			break;
		}
		if (nIdex==0)
		{
			InData.Delete(0,1);
			continue;
		}

		str[i]=InData.Left(nIdex);
		InData.Delete(0,nIdex+1);
		
	}
	for (;unitj<50;unitj++)
	{
		str[unitj]="None";
	}
	
	
}


void PipeStmOut::InitData(CString InData,CString str[50],TCHAR chSeparator)
{
	InData.TrimLeft();
	int nIdex=0;
	int i;
	int strj=0;
	
	for (i=0;i<50;i++)
	{
		nIdex=InData.Find(chSeparator);
		strj++;
		if (nIdex==-1)
		{
			InData.TrimRight();
			str[strj-1]=InData;
			break;
		}
		if (nIdex==0)
		{
			InData.Delete(0,1);
			continue;
		}

		str[i]=InData.Left(nIdex);
		InData.Delete(0,nIdex+1);		
	}
	for (;strj<50;strj++)
	{
		str[strj]="0";
	}
	
}

