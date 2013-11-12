// PipeData.cpp: implementation of the PipeData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PipeData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
PipeData::PipeData()
{
	InitArray();
}

PipeData::~PipeData()
{
	
}

BOOL PipeData::Read(CStdioFile &file)
{
	CString strTemp;
	file.ReadString(strTemp);
	InitData(strTemp);

	return TRUE;
}

BOOL PipeData::Save(CStdioFile &file)
{
	BOOL bRet = TRUE;
	CString strSave;
	int nNum = m_RowArray.GetSize();
	for(int i=0;i<nNum;i++)
	{
		RowObject *pObject = m_RowArray.GetAt(i);
		strSave += pObject->Save();
	}
	file.WriteString(strSave);
	return bRet;
}

void PipeData::Init()
{
	CString strData ;
	if ( isImpFile )
	{
		strData = _T(",,None,None,0,0,0,2,0,0,0,0,0,0,None,0,0,0,0,0,None,None,0,0,None,0,0,None,None,None,0,05 None,1,1,0,0,None,0,None,0,None,0,None,0,None,0,None,0,None,0,None,1,-92.07715,-322.5421,-999999,-999999,1,5,-1,-1,25,-1,-1,-1,0,0,,-1,Arial,9,0,0,0,0,None,0,None,0,0,0,None,0,0,0,0,1,-1,-1,-1,-1,-1,1,-1,0");
	} 
	else
	{
		strData = _T("1,Pipe,feet,feet,0,1,200,0,0,2,1650,1935,0,5175,1935,0,None,-1,-1,1,2,3.068,inches,0,None,0,None,None,4,0.018,None,0,0,Steel,3 inch,schedule 40,3.80776,06 100001:6 800:1:0.58:-1,1,1,0,0,None,0,None,0,None,0,None,0,None,0,None,0,0,None,1,-157.5,-272.9521,-645.5,-765,1,5,-1,-1,25,-1,-1,-1,0,0,None,0,0,None,1,0,0,,1,-1,Arial,9,0,0,10485760,0,None,0,0,-1,None,None,0,0,0,NA,NA,NA,-1,0,0,-1,1,1,%ALL%,4,Percent,1,100,2,100,3,100,0,100,2,years,-9999,-9999");
	}
	InitData(strData);

}


void PipeData::InitData(CString strData)
{
	int nNum = 0;
	strData = m_Number.InitData(strData);
	strData = m_Name.InitData(strData);
	strData = m_LenUnit.InitData(strData);
	strData = m_EleUnit.InitData(strData);
	strData = m_InEle.InitData(strData);
	strData = m_OutLenEleList.Read(strData);
	if(!m_OutLenEleList.GetData().IsEmpty())
	{
		m_OutLenEleList.GetData(nNum);
		nNum = abs(nNum);
	}
	strData = m_OutLenEleList.ReadChild(strData,nNum*2);
	strData = m_UnKown1.InitData(strData);
	strData = m_PtArray.Read(strData);
	if(!m_PtArray.GetData().IsEmpty())
	{
		m_PtArray.GetData(nNum);
		nNum = abs(nNum);
	}
	strData = m_PtArray.ReadChild(strData,nNum*3);
	strData = m_UnKown2.InitData(strData);
	strData = m_definedMark.InitData(strData);
	strData = m_LockMark.InitData(strData);
	strData = m_InJunID.InitData(strData);
	strData = m_OutJunID.InitData(strData);
	strData = m_InDia.InitData(strData);
	if(!isImpFile)
		strData = m_Fth1.InitData(strData);
	strData = m_FrictionModel.InitData(strData);
	strData = m_UnKown3.InitData(strData);
	strData = m_UnKown4.InitData(strData);
	strData = m_PipeAttr.InitData(strData);
	strData = m_LocalK.InitData(strData);
	strData = m_DisignFactor.InitData(strData);
	strData = m_InitFlow.InitData(strData);
	strData = m_FuildMark.InitData(strData);
	strData = m_FuildAttr.InitData(strData);
	strData = m_SpecialMark.InitData(strData);
	if ( isImpFile )
	{
		strData = m_UnKown5.InitData(strData);
	}	
	strData = m_LabLocation.InitData(strData);
	strData = m_Display.InitData(strData);
	strData = m_UnKown6.InitData(strData);
	strData = m_PipeColor.InitData(strData);
	strData = m_UnKown7.InitData(strData);
	strData = m_LineThick.InitData(strData);
	strData = m_Alerts.Read(strData);
	if(!m_Alerts.GetData().IsEmpty())
	{
		m_Alerts.GetData(nNum);
		nNum = abs(nNum);
	}
	strData = m_Alerts.ReadChild(strData,nNum*4);
	if ( !isImpFile )
	{
		strData = m_Fth2.InitData( strData ) ;
	}
	strData = m_notes.InitData(strData);
	strData = m_UnKown8.InitData(strData);
	strData = m_Font.InitData(strData);
	strData = m_PipeThick.InitData(strData);
	strData = m_ElasModulus.InitData(strData);
	strData = m_PoissonRatio.InitData(strData);
	if ( isImpFile )
	{
		strData = m_WaveSpeed.InitData(strData);
		strData = m_UnKown9.InitData(strData);
		strData = m_UnKown10.InitData(strData);
		strData = m_SectionNum.InitData(strData);
		strData = m_UnKown11.InitData(strData);
		strData = m_UnKown12.InitData(strData);
		strData = m_UnKown13.InitData(strData);
		strData = m_ParaNum.InitData(strData);
		strData = m_PartFull.InitData(strData);
		strData = m_IDReduce.InitData(strData);
	}
	else
	{
		strData = m_Fth3.InitData( strData ) ;
		strData = m_Fth4.InitData( strData ) ;
		if ( m_Fth4.GetData() == _T("None") )
		{
			strData = m_Fth5.ReadChild( strData, 6 ) ;
		} 
		else
		{
			strData = m_Fth5.ReadChild( strData, 13 ) ;
		}
		strData = m_Fth6.InitData( strData ) ;
		strData = m_IDReduce.InitData( strData ) ;
		strData = m_PartFull.InitData(strData);
		strData = m_ParaNum.InitData(strData);
		CString InitWaveData = _T("0,2070,feet/sec,20.47929,10,0,-1") ; //由于Fth6.0没有指定的波速，所以在这里把管道的波速初始化，
		strData = m_WaveSpeed.InitData(InitWaveData);
	}	
}

void PipeData::InitArray()
{
	if ( isImpFile )
	{
		m_RowArray.SetSize(48);
		m_RowArray.SetAt(0,&m_Number.Data());
		m_RowArray.SetAt(1,&m_Name.Data());
		m_RowArray.SetAt(2,&m_LenUnit.Data());
		m_RowArray.SetAt(3,&m_EleUnit.Data());
		m_RowArray.SetAt(4,&m_InEle.Data());
		m_RowArray.SetAt(5,&m_OutLenEleList);
		m_RowArray.SetAt(6,&m_UnKown1.Data());
		m_RowArray.SetAt(7,&m_PtArray);
		m_RowArray.SetAt(8,&m_UnKown2.Data());
		m_RowArray.SetAt(9,&m_definedMark.Data());
		m_RowArray.SetAt(10,&m_LockMark.Data());
		m_RowArray.SetAt(11,&m_InJunID.Data());
		m_RowArray.SetAt(12,&m_OutJunID.Data());
		m_RowArray.SetAt(13,&m_InDia.Data());
		m_RowArray.SetAt(14,&m_FrictionModel.Data());
		m_RowArray.SetAt(15,&m_UnKown3.Data());
		m_RowArray.SetAt(16,&m_UnKown4.Data());
		m_RowArray.SetAt(17,&m_PipeAttr.Data());
		m_RowArray.SetAt(18,&m_LocalK.Data());
		m_RowArray.SetAt(19,&m_DisignFactor.Data());
		m_RowArray.SetAt(20,&m_InitFlow.Data());
		m_RowArray.SetAt(21,&m_FuildMark.Data());
		m_RowArray.SetAt(22,&m_FuildAttr.Data());
		m_RowArray.SetAt(23,&m_SpecialMark.Data());
		m_RowArray.SetAt(24,&m_UnKown5.Data());
		m_RowArray.SetAt(25,&m_LabLocation.Data());
		m_RowArray.SetAt(26,&m_Display.Data());
		m_RowArray.SetAt(27,&m_UnKown6.Data());
		m_RowArray.SetAt(28,&m_PipeColor.Data());
		m_RowArray.SetAt(29,&m_UnKown7.Data());
		m_RowArray.SetAt(30,&m_LineThick.Data());
		m_RowArray.SetAt(31,&m_Alerts);
		m_RowArray.SetAt(32,&m_notes.Data());
		m_RowArray.SetAt(33,&m_UnKown8.Data());
		m_RowArray.SetAt(34,&m_Font.Data());
		m_RowArray.SetAt(35,&m_PipeThick.Data());
		m_RowArray.SetAt(36,&m_ElasModulus.Data());
		m_RowArray.SetAt(37,&m_PoissonRatio.Data());
		m_RowArray.SetAt(38,&m_WaveSpeed.Data());
		m_RowArray.SetAt(39,&m_UnKown9.Data());
		m_RowArray.SetAt(40,&m_UnKown10.Data());
		m_RowArray.SetAt(41,&m_SectionNum.Data());
		m_RowArray.SetAt(42,&m_UnKown11.Data());
		m_RowArray.SetAt(43,&m_UnKown12.Data());
		m_RowArray.SetAt(44,&m_UnKown13.Data());
		m_RowArray.SetAt(45,&m_ParaNum.Data());
		m_RowArray.SetAt(46,&m_PartFull.Data());
		m_RowArray.SetAt(47,&m_IDReduce.Data());
	} 
	else
	{
		m_RowArray.SetSize(47);
		m_RowArray.SetAt(0,&m_Number.Data());
		m_RowArray.SetAt(1,&m_Name.Data());
		m_RowArray.SetAt(2,&m_LenUnit.Data());
		m_RowArray.SetAt(3,&m_EleUnit.Data());
		m_RowArray.SetAt(4,&m_InEle.Data());
		m_RowArray.SetAt(5,&m_OutLenEleList);
		m_RowArray.SetAt(6,&m_UnKown1.Data());
		m_RowArray.SetAt(7,&m_PtArray);
		m_RowArray.SetAt(8,&m_UnKown2.Data());
		m_RowArray.SetAt(9,&m_definedMark.Data());
		m_RowArray.SetAt(10,&m_LockMark.Data());
		m_RowArray.SetAt(11,&m_InJunID.Data());
		m_RowArray.SetAt(12,&m_OutJunID.Data());
		m_RowArray.SetAt(13,&m_InDia.Data());
		m_RowArray.SetAt(14,&m_Fth1.Data());
		m_RowArray.SetAt(15,&m_FrictionModel.Data());
		m_RowArray.SetAt(16,&m_UnKown3.Data());
		m_RowArray.SetAt(17,&m_UnKown4.Data());
		m_RowArray.SetAt(18,&m_PipeAttr.Data());
		m_RowArray.SetAt(19,&m_LocalK.Data());
		m_RowArray.SetAt(20,&m_DisignFactor.Data());
		m_RowArray.SetAt(21,&m_InitFlow.Data());
		m_RowArray.SetAt(22,&m_FuildMark.Data());
		m_RowArray.SetAt(23,&m_FuildAttr.Data());
		m_RowArray.SetAt(24,&m_SpecialMark.Data());

		m_RowArray.SetAt(25,&m_LabLocation.Data());
		m_RowArray.SetAt(26,&m_Display.Data());
		m_RowArray.SetAt(27,&m_UnKown6.Data());
		m_RowArray.SetAt(28,&m_PipeColor.Data());
		m_RowArray.SetAt(29,&m_UnKown7.Data());
		m_RowArray.SetAt(30,&m_LineThick.Data());
		m_RowArray.SetAt(31,&m_Alerts);
		m_RowArray.SetAt(32,&m_Fth2.Data());

		m_RowArray.SetAt(33,&m_notes.Data());
		m_RowArray.SetAt(34,&m_UnKown8.Data());
		m_RowArray.SetAt(35,&m_Font.Data());
		m_RowArray.SetAt(36,&m_PipeThick.Data());
		m_RowArray.SetAt(37,&m_ElasModulus.Data());
		m_RowArray.SetAt(38,&m_PoissonRatio.Data());

		m_RowArray.SetAt(39,&m_Fth3.Data());
		m_RowArray.SetAt(40,&m_Fth4.Data());
		m_RowArray.SetAt(41,&m_Fth5);
		m_RowArray.SetAt(42,&m_Fth6.Data());
		m_RowArray.SetAt(43,&m_IDReduce.Data());
		m_RowArray.SetAt(44,&m_PartFull.Data());
		m_RowArray.SetAt(45,&m_ParaNum.Data());		
		m_RowArray.SetAt(46,&m_WaveSpeed.Data());
		
// 		m_RowArray.SetAt(39,&m_UnKown9.Data());
// 		m_RowArray.SetAt(40,&m_UnKown10.Data());
// 		m_RowArray.SetAt(41,&m_SectionNum.Data());
// 		m_RowArray.SetAt(42,&m_UnKown11.Data());
// 		m_RowArray.SetAt(43,&m_UnKown12.Data());
// 		m_RowArray.SetAt(44,&m_UnKown13.Data());
		
		
		
	}
}

int PipeData::GetNum()
{
	int nNum=0;
	m_Number.GetData(nNum);
	return nNum;
}
void PipeData::SetNum(int nNum)
{
	m_Number.SetData(nNum);
}

/*------------------------------------------*/
CString PipeData::Name()
{
	return m_Name.GetData();
}
void PipeData::Name(CString strValue)
{
	m_Name.SetData(strValue);
}
/*------------------------------------------*/
CString PipeData::StartPtX()
{
	CString strRet;
	m_PtArray.GetData(strRet,1);
	strRet.TrimRight();
	if(strRet.IsEmpty())
	{
		return strRet;
	}
	int n = _ttoi(strRet);
	n = n/10;
	strRet.Format(_T("%d"),n);
	return strRet;
}
void PipeData::StartPtX(CString strValue)
{
	strValue.TrimRight();
	if(!strValue.IsEmpty())
	{
		strValue = strValue +_T("0");
	}
	m_PtArray.SetData(strValue,1);
}
/*------------------------------------------*/
CString PipeData::EndPtX()
{
	CString strRet;
	int nNum=0;
	m_PtArray.GetData(nNum);
	m_PtArray.GetData(strRet,(nNum-1)*3+1);
	if(strRet.IsEmpty())
	{
		return strRet;
	}
	int n = _ttoi(strRet);
	n = n/10;
	strRet.Format(_T("%d"),n);
	return strRet;
}
void PipeData::EndPtX(CString strValue)
{
	strValue.TrimRight();
	if(!strValue.IsEmpty())
	{
		strValue = strValue +_T("0");
	}
	m_PtArray.SetData(strValue,4);
}
/*------------------------------------------*/
CString PipeData::StartPtY()
{
	CString strRet;
	m_PtArray.GetData(strRet,2);
	if(strRet.IsEmpty())
	{
		return strRet;
	}
	int n = _ttoi(strRet);
	n = n/10;
	strRet.Format(_T("%d"),n);
	return strRet;
}
void PipeData::StartPtY(CString strValue)
{
	strValue.TrimRight();
	if(!strValue.IsEmpty())
	{
		strValue = strValue +_T("0");
	}
	m_PtArray.SetData(strValue,2);
}
/*------------------------------------------*/

CString PipeData::EndPtY()
{
	CString strRet;
	int nNum=0;
	m_PtArray.GetData(nNum);
	m_PtArray.GetData(strRet,(nNum-1)*3+2);
	if(strRet.IsEmpty())
	{
		return strRet;
	}
	int n = _ttoi(strRet);
	n = n/10;
	strRet.Format(_T("%d"),n);
	return strRet;
}
void PipeData::EndPtY(CString strValue)
{
	strValue.TrimRight();
	if(!strValue.IsEmpty())
	{
		strValue = strValue +_T("0");
	}
	m_PtArray.SetData(strValue,5);
}
/*------------------------------------------*/

CString PipeData::InJunID()
{
	return m_InJunID.GetData();
}
void PipeData::InJunID(CString strValue)
{
	m_InJunID.SetData(strValue);
}
/*------------------------------------------*/
CString PipeData::OutJunID()
{
	return m_OutJunID.GetData();
}
void PipeData::OutJunID(CString strValue)
{
	m_OutJunID.SetData(strValue);
}
/*------------------------------------------*/
CString PipeData::InDia()
{
	return m_InDia.GetData();
}
void PipeData::InDia(CString strValue)
{
	m_InDia.SetData(strValue);
}
/*------------------------------------------*/
CString PipeData::InDiaUnit()
{
	CString strUnit;
	m_InDia.GetData(strUnit,1);
	return strUnit;
}
void PipeData::InDiaUnit(CString strValue)
{
	m_InDia.SetData(strValue,1);
}
/*------------------------------------------*/
CString PipeData::Len()
{
	CString strLen;
	double fLen = 0;
	int nNum = 0;
	m_OutLenEleList.GetData(nNum);
	nNum = abs(nNum);
	double fTemp;
	for(int i=1;i<=nNum;i++)
	{
		fTemp = 0;
		m_OutLenEleList.GetData(fTemp,2*i-1);
		fLen += fTemp;
	}
	if(fLen !=0)
	{
		strLen.Format(_T("%f"),fLen);
		if(-1 != strLen.Find('.'))
		{
			strLen.TrimRight('0');
			strLen.TrimRight('.');
		}
	}
	return strLen;

}
void PipeData::Len(CString strValue)
{
	m_OutLenEleList.SetData(_T("1"));
	if(!m_OutLenEleList.SetData(strValue,1))
	{
		m_OutLenEleList.ReadChild(_T("0,0,"),2);
		m_OutLenEleList.SetData(strValue,1);
	}
}
/*------------------------------------------*/
inline CString PipeData::LenUnit()
{
	return m_LenUnit.GetData();
}
void PipeData::LenUnit(CString strValue)
{
	m_LenUnit.SetData(strValue);
}
/*------------------------------------------*/
CString PipeData::WaveSpeed()
{
	CString strValue;
	m_WaveSpeed.GetData(strValue,1);
	return strValue;
}
void PipeData::WaveSpeed(CString strValue)
{
	m_WaveSpeed.SetData(strValue,1);
}
/*------------------------------------------*/
CString PipeData::WaveSpeedUnit()
{
	CString strUnit;
	m_WaveSpeed.GetData(strUnit,2);
	return strUnit;
}
void PipeData::WaveSpeedUnit(CString strValue)
{
	m_WaveSpeed.SetData(strValue,2);
}
/*------------------------------------------*/

CString PipeData::B()
{
	CString strValue;
	m_WaveSpeed.GetData(strValue,3);
	return strValue;
}
void PipeData::B(CString strValue)
{
	m_WaveSpeed.SetData(strValue,3);
}
/*------------------------------------------*/
CString PipeData::Material()
{
	CString strValue;
	m_PipeAttr.GetData(strValue);
	return strValue;
}
void PipeData::Material(CString strValue)
{
	m_PipeAttr.SetData(strValue);
}
/*------------------------------------------*/
CString PipeData::PipeType()
{
	CString strValue;
	m_PipeAttr.GetData(strValue,1);
	return strValue;
}
void PipeData::PipeType(CString strValue)
{
	m_PipeAttr.SetData(strValue,1);
}
/*------------------------------------------*/
CString PipeData::Size()
{
	CString strValue;
	m_PipeAttr.GetData(strValue,2);
	return strValue;
}
void PipeData::Size(CString strValue)
{
	m_PipeAttr.SetData(strValue,2);
}
/*------------------------------------------*/
CString PipeData::Thick()
{
	CString strValue;
	m_PipeThick.GetData(strValue);
	return strValue;
}
void PipeData::Thick(CString strValue)
{
	m_PipeThick.SetData(strValue);
}
/*------------------------------------------*/
CString PipeData::ThickUnit()
{
	CString strValue;
	m_PipeThick.GetData(strValue,1);
	return strValue;
}
void PipeData::ThickUnit(CString strValue)
{
	m_PipeThick.SetData(strValue,1);
}
/*------------------------------------------*/
CString PipeData::Elasticity()
{
	CString strValue;
	m_ElasModulus.GetData(strValue);
	return strValue;
}
void PipeData::Elasticity(CString strValue)
{
	m_ElasModulus.SetData(strValue);
}
/*------------------------------------------*/
CString PipeData::ElasticityUnit()
{
	CString strValue;
	m_ElasModulus.GetData(strValue,1);
	return strValue;
}
void PipeData::ElasticityUnit(CString strValue)
{
	m_ElasModulus.SetData(strValue,1);
}
/*------------------------------------------*/
CString PipeData::PossionRatio()
{
	CString strValue;
	m_PoissonRatio.GetData(strValue);
	return strValue;
}
void PipeData::PossionRatio(CString strValue)
{
	m_PoissonRatio.SetData(strValue);
}
/*------------------------------------------*/
CString PipeData::InDiaReduce()
{
	CString strValue;
	m_IDReduce.GetData(strValue);
	return strValue;
}
void PipeData::InDiaReduce(CString strValue)
{
	m_IDReduce.SetData(strValue);
}
/*------------------------------------------*/
CString PipeData::SupportType()
{
	CString strValue;
	m_WaveSpeed.GetData(strValue,5);
	return strValue;
}
void PipeData::SupportType(CString strValue)
{
	m_WaveSpeed.SetData(strValue,5);
}
/*------------------------------------------*/
CString PipeData::CalcWave()
{
	CString strValue;
	m_WaveSpeed.GetData(strValue);
	return strValue;
}
void PipeData::CalcWave(CString strValue)
{
	m_WaveSpeed.SetData(strValue);
}
/*------------------------------------------*/
CString PipeData::C1()
{
	CString strValue;
	m_WaveSpeed.GetData(strValue,6);
	return strValue;
}
void PipeData::C1(CString strValue)
{
	m_WaveSpeed.SetData(strValue,6);
}
/*------------------------------------------*/

CString PipeData::FrictionModel()
{
	CString strValue;
	m_FrictionModel.GetData(strValue,1);
	return strValue;
}
void PipeData::FrictionModel(CString strValue)
{
	m_FrictionModel.SetData(strValue,1);
}
/*------------------------------------------*/

CString PipeData::Friction()
{
	CString strValue;
	m_FrictionModel.GetData(strValue,2);
	return strValue;
}
void PipeData::Friction(CString strValue)
{
	m_FrictionModel.SetData(strValue,2);
}
/*------------------------------------------*/

CString PipeData::FrictionUnit()
{
	CString strValue;
	m_FrictionModel.GetData(strValue,3);
	return strValue;
}
void PipeData::FrictionUnit(CString strValue)
{
	m_FrictionModel.SetData(strValue,3);
}
/*------------------------------------------*/
CString PipeData::LocalK()
{
	CString strValue;
	m_LocalK.GetData(strValue);
	return strValue;
}
void PipeData::LocalK(CString strValue)
{
	m_LocalK.SetData(strValue);
}
/*------------------------------------------*/
CString PipeData::PipeFactor()
{
	CString strValue;
	m_DisignFactor.GetData(strValue);
	return strValue;
}
void PipeData::PipeFactor(CString strValue)
{
	m_DisignFactor.SetData(strValue);
}
/*------------------------------------------*/
CString PipeData::FitFactor()
{
	CString strValue;
	m_DisignFactor.GetData(strValue,1);
	return strValue;
}
void PipeData::FitFactor(CString strValue)
{
	m_DisignFactor.SetData(strValue,1);
}
/*------------------------------------------*/
StrArray<3> PipeData::InitFlow()
{
	return m_InitFlow.GetArray();
}
void PipeData::InitFlow(const StrArray<3>& strValue)
{
	m_InitFlow.SetArray(strValue);
}
/*------------------------------------------*/
CString PipeData::SectionNum()
{
	CString strValue;
	m_WaveSpeed.GetData(strValue,4);
	return strValue;
}
void PipeData::SectionNum(CString strValue)
{
	m_SectionNum.SetData(strValue);
	m_WaveSpeed.SetData(strValue,4);
}
/*------------------------------------------*/
CString PipeData::ParaNum()
{
	return m_ParaNum.GetData();
}
void PipeData::ParaNum(CString strValue)
{
	m_ParaNum.SetData(strValue);
}

/*------------------------------------------*/
CString PipeData::PartFull()
{
	return m_PartFull.GetData();
}
void PipeData::PartFull(CString strValue)
{
	m_PartFull.SetData(strValue);
}