// JunStmOut.cpp: implementation of the JunStmOut class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JunStmOut.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

JunStmOut::JunStmOut()
{
	
}

JunStmOut::~JunStmOut()
{

}

void JunStmOut::InitUnit(CString InData,CString str[50],TCHAR chSeparator)
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
		str[unitj]=_T("None");
	}
		
}

void JunStmOut::InitData(CString InData,CString str[50],TCHAR chSeparator)
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
		str[strj]=_T("0");
	}
	
}


void JunStmOut::Instance(OutAttrArray &array,UnitSubSystem &unitsys,OutputRefPersist &OutPutData,JunOutShowArray &ShowJunArray,OutPutSystem &OutPutSys)
{
	CString str[50];
	CString str1[50];//±£´æKey;
	CString strTemp1;
	CString strTemp;	
	int i = 0;
	int j = 0;
	int n = 0;
	strTemp1=OutPutData.JunDataOrder();
	strTemp=OutPutData.JunUnitOrder();
	
	InitData(strTemp1,str1);
	InitUnit(strTemp,str);
	OutPutSys.InitOutPutSystem();
	OutPutSys.GetJunOutArray().GetData();

	ComponentStmOut::InitAttr(array,unitsys,0,_T("½Úµã"));
//	for (i = 1;i < 50;i++)
//	{
//		ComponentStmOut::InitAttr(array,unitsys,i,OutPutSys.GetJunOutArray()[i].GetTypeId(),OutPutSys.GetJunOutArray()[i].GetStrName());
//	}

	for (i=0;i<50;i++)
	{
		for (j=0;j<50;j++)
		{
			if (str1[j]!=_T("0")&&str1[j]==OutPutSys.GetJunOutArray()[i].GetKey())
			{
				n = 1;
				ComponentStmOut::InitAttr(array,unitsys,i,OutPutSys.GetJunOutArray()[i].GetTypeId(),str[j],OutPutSys.GetJunOutArray()[i].GetStrName());
				break;
				//ComponentStmOut::InitAttr(array,unitsys,i,OutPutSys.GetJunOutArray()[i].GetTypeId(),OutPutSys.GetJunOutArray()[i].GetStrName());
			}
		}
		if (n == 0)
		{
			ComponentStmOut::InitAttr(array,unitsys,i,OutPutSys.GetJunOutArray()[i].GetTypeId(),OutPutSys.GetJunOutArray()[i].GetStrName());
		}
		n = 0;
	}
}


/*----------------------------------------------*/
void JunStmOut::SetInStagPress(double dValue)
{
	SetValue(dValue,1);
}

/*----------------------------------------------*/
void JunStmOut::SetOutStagPress(double dValue)
{
	SetValue(dValue,2);
}


/*----------------------------------------------*/
void JunStmOut::SetInStaticPress(double dValue)
{
	SetValue(dValue,3);
}

/*----------------------------------------------*/
void JunStmOut::SetOutStaticPress(double dValue)
{
	SetValue(dValue,4);
}

/*----------------------------------------------*/
void JunStmOut::SetGLoss(double dValue)
{
	SetValue(dValue,5);
}
/*----------------------------------------------*/
void JunStmOut::SetInMassFlow(double dValue)
{
	SetValue(dValue,6);
}

/*----------------------------------------------*/
void JunStmOut::SetInVolumeFlow(double dValue)
{
	SetValue(dValue,7);
}

/*----------------------------------------------*/
void JunStmOut::SetThruMassFlow(double dValue)
{
	SetValue(dValue,8);
}

/*----------------------------------------------*/
void JunStmOut::SetThruVolumeFlow(double dValue)
{
	SetValue(dValue,9);
}

/*----------------------------------------------*/
void JunStmOut::SetLossK(double dValue)
{
	SetValue(dValue,10);
}

/*----------------------------------------------*/
void JunStmOut::SetInEGL(double dValue)
{
	SetValue(dValue,11);
}

/*----------------------------------------------*/
void JunStmOut::SetOutEGL(double dValue)
{
	SetValue(dValue,12);
}

/*----------------------------------------------*/
void JunStmOut::SetInHGL(double dValue)
{
	SetValue(dValue,13);
}

/*----------------------------------------------*/
void JunStmOut::SetOutHGL(double dValue)
{
	SetValue(dValue,14);
}


