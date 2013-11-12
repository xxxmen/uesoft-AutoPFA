// Junction.cpp: implementation of the JunctionData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Junction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

JunctionData::JunctionData()
{
	InitArray();
}

JunctionData::~JunctionData()
{

}

void JunctionData::Init()
{
	InitData(GetDefaultData());
}

BOOL JunctionData::Read(CString strData)
{
	InitData(strData);
	return TRUE;
}
BOOL JunctionData::Read(CStdioFile &file)
{
	CString strTemp;
	file.ReadString(strTemp);
	InitData(strTemp);
	return TRUE;
}
BOOL JunctionData::Save(CStdioFile &file)
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
void JunctionData::InitData(CString strData)
{
    strData = m_TypeID.InitData(strData);
	strData = m_Number.InitData(strData);
	strData = m_UnKown1.InitData(strData);
	strData = m_UnKown2.InitData(strData);
	strData = m_Name.InitData(strData);
	strData = m_PipeNum.InitData(strData);
	strData = m_PipeArray.InitData(strData,PipeNum());
	strData = m_CenterPt.InitData(strData);
	strData = m_JunSize.InitData(strData);
	strData = m_JunState.InitData(strData);
	strData = m_JunPipeMark.InitData(strData);
	strData = m_LockMark.InitData(strData);
	strData = m_EleArray.InitData(strData);
	strData = m_UnKown3.InitData(strData);
	strData = m_DisignFactor.InitData(strData);
	strData = m_InitGuess.InitData(strData);
	strData = m_UnKown4.InitData(strData);
	strData = m_HandBook.InitData(strData);
	strData = m_PumpConfig.InitData(strData);
	strData = m_SpecialMark.InitData(strData);
	strData = m_UnKown5.InitData(strData);
	strData = m_LabLocation.InitData(strData);
	strData = m_Display.InitData(strData);
	strData = m_UnKown6.InitData(strData);
	strData = m_notes.InitData(strData);
	strData = m_UnKown7.InitData(strData);
	strData = m_Font.InitData(strData);

	strData = m_UnKown9.InitData(strData);
	if (!isImpFile)
	{	
		int flage;
		strData = m_Fth1.InitData(strData);
		strData = m_Fth2.InitData(strData);
		m_Fth2.GetData(flage);
		if (flage==1)
		{			
			strData = m_Fth3.InitData(strData);
		}
		if(m_TypeID.GetData()==_T("17"))
		{
			strData = m_Fth4.InitData(strData);
			m_Fth4.GetData(flage);
			if (flage==1)
			{			
				strData = m_Fth5.InitData(strData);
			}
		}
		strData = m_Fth6.InitData(strData);
		strData = m_Fth7.InitData(strData);
		m_Fth6.GetData(flage);
		strData = m_FthArray.InitData(strData,2*flage);
		strData = m_Fth8.InitData(strData);
		strData = m_Fth9.InitData(strData);
	}
	strData = m_UnKown10.InitData(strData);
	InitExtra(strData);
}


void JunctionData::InitArray()
{
	int flage2=0,flage4=0;
	if (isImpFile)
	{
		m_RowArray.SetSize(29);
	}else{
		m_Fth2.GetData(flage2);
		if(m_TypeID.GetData()==_T("17"))
		{
			m_Fth4.GetData(flage4);
			flage4 += 1;
		}
		m_RowArray.SetSize(29+flage2+flage4+5);
	}
	
	m_RowArray.SetAt(0,&m_TypeID.Data());
	m_RowArray.SetAt(1,&m_Number.Data());
	m_RowArray.SetAt(2,&m_UnKown1.Data());
	m_RowArray.SetAt(3,&m_UnKown2.Data());
	m_RowArray.SetAt(4,&m_Name.Data());
	m_RowArray.SetAt(5,&m_PipeNum.Data());
	m_RowArray.SetAt(6,&m_PipeArray.Data());
	m_RowArray.SetAt(7,&m_CenterPt.Data());
	m_RowArray.SetAt(8,&m_JunSize.Data());
	m_RowArray.SetAt(9,&m_JunState.Data());
	m_RowArray.SetAt(10,&m_JunPipeMark.Data());
	m_RowArray.SetAt(11,&m_LockMark.Data());
	m_RowArray.SetAt(12,&m_EleArray.Data());
	m_RowArray.SetAt(13,&m_UnKown3.Data());
	m_RowArray.SetAt(14,&m_DisignFactor.Data());
	m_RowArray.SetAt(15,&m_InitGuess.Data());
	m_RowArray.SetAt(16,&m_UnKown4.Data());
	m_RowArray.SetAt(17,&m_HandBook.Data());
	m_RowArray.SetAt(18,&m_PumpConfig.Data());
	m_RowArray.SetAt(19,&m_SpecialMark.Data());
	m_RowArray.SetAt(20,&m_UnKown5.Data());
	m_RowArray.SetAt(21,&m_LabLocation.Data());
	m_RowArray.SetAt(22,&m_Display.Data());
	m_RowArray.SetAt(23,&m_UnKown6.Data());
	m_RowArray.SetAt(24,&m_notes.Data());
	m_RowArray.SetAt(25,&m_UnKown7.Data());
	m_RowArray.SetAt(26,&m_Font.Data());
	m_RowArray.SetAt(27,&m_UnKown9.Data());
	if (isImpFile)
	{
		m_RowArray.SetAt(28,&m_UnKown10.Data());
	}else{
		if (flage2 == 1)
		{	
			m_RowArray.SetAt(28,&m_Fth3.Data());		
		}
		if (flage4 == 1 )
		{	
			m_RowArray.SetAt(28+flage2,&m_Fth4.Data());		
		}else if (flage4 == 2 ){
			m_RowArray.SetAt(28+flage2,&m_Fth4.Data());
			m_RowArray.SetAt(29+flage2,&m_Fth5.Data());
		}
		m_RowArray.SetAt(28+flage2+flage4,&m_Fth6.Data());
		m_RowArray.SetAt(29+flage2+flage4,&m_Fth7.Data());
		m_RowArray.SetAt(30+flage2+flage4,&m_FthArray.Data());
		m_RowArray.SetAt(31+flage2+flage4,&m_Fth8.Data());
		m_RowArray.SetAt(32+flage2+flage4,&m_Fth9.Data());
		m_RowArray.SetAt(33+flage2+flage4,&m_UnKown10.Data());
	}
}

/*------------------------------------------*/
int JunctionData::Key()
{
	int iKey=0;
	m_Number.GetData(iKey);
	return iKey;
}
void JunctionData::Key(int iKey)
{
	m_Number.SetData(iKey);
}
/*------------------------------------------*/
int JunctionData::ID()
{
	int iID=0;
	m_TypeID.GetData(iID);
	return iID;
}
void JunctionData::ID(int iID)
{
	m_TypeID.SetData(iID);
}
int JunctionData::PipeNum()
{
	int iKey=0;
	m_PipeNum.GetData(iKey);
	return abs(iKey);
}
/*------------------------------------------*/
CString JunctionData::Name()
{
	return m_Name.GetData();
}
void JunctionData::Name(CString strValue)
{
	m_Name.SetData(strValue);
}
/*------------------------------------------*/
CString JunctionData::CenterPtX()
{
	CString strRet;
	m_CenterPt.GetData(strRet);
	strRet.TrimRight();
	if(strRet.IsEmpty())
	{
		return strRet;
	}
	int n = _ttoi(strRet);
	n = n/10+24;
	strRet.Format(_T("%d"),n);
	return strRet;
}
void JunctionData::CenterPtX(CString strValue)
{
	strValue.TrimRight();
	if(!strValue.IsEmpty())
	{
		int n = _ttoi(strValue);
		n = (n-24)*10;
		strValue.Format(_T("%d"),n);
	}
	m_CenterPt.SetData(strValue);
}
/*------------------------------------------*/
CString JunctionData::CenterPtY()
{
	CString strRet;
	m_CenterPt.GetData(strRet,1);
	strRet.TrimRight();
	if(strRet.IsEmpty())
	{
		return strRet;
	}
	int n = _ttoi(strRet);
	n = n/10+24;
	strRet.Format(_T("%d"),n);
	return strRet;
}

void JunctionData::CenterPtY(CString strValue)
{
	strValue.TrimRight();
	if(!strValue.IsEmpty())
	{
		int n = _ttoi(strValue);
		n = (n-24)*10;
		strValue.Format(_T("%d"),n);
	}
	m_CenterPt.SetData(strValue,1);
}
/*------------------------------------------*/
ListImp<StrArray<1> > JunctionData::PipeID()
{
	return m_PipeArray.GetData();
}

void JunctionData::PipeID(ListImp<StrArray<1> >& list)
{
	m_PipeNum.SetData(list.GetCount());
	m_PipeArray.SetData(list);
}

/*------------------------------------------*/
CString JunctionData::InEle()
{
	return m_EleArray.GetData();
}
void JunctionData::InEle(CString strValue)
{
	m_EleArray.SetData(strValue);
}
/*------------------------------------------*/
CString JunctionData::OutEle()
{
	CString strValue;
	m_EleArray.GetData(strValue,1);
	if(IsSameInEle())
	{
		return InEle();
	}
	else
	{
		return strValue;
	}
}
void JunctionData::OutEle(CString strValue)
{
	m_EleArray.SetData(strValue,1);
}
BOOL JunctionData::IsSameInEle()
{
	int bSame = 0;
	m_UnKown3.GetData(bSame);
	if(bSame==0)
		return TRUE;
	return FALSE;
}
/*------------------------------------------*/
CString JunctionData::EleUnit()
{
	CString strValue;
	m_EleArray.GetData(strValue,2);
	return strValue;
}
void JunctionData::EleUnit(CString strValue)
{
	m_EleArray.SetData(strValue,2);
}
/*------------------------------------------*/
CString JunctionData::DesignFactor()
{
	return m_DisignFactor.GetData();
}
void JunctionData::DesignFactor(CString strValue)
{
	m_DisignFactor.SetData(strValue);
}
/*------------------------------------------*/
StrArray<3> JunctionData::InitGuess()
{
	return m_InitGuess.GetArray();
}
void JunctionData::InitGuess(const StrArray<3>& strValue)
{
	m_InitGuess.SetArray(strValue);
}

/*------------------------------------------*/
StrArray<3> JunctionData::SpecialMark()
{
	return m_SpecialMark.GetArray();
}
void JunctionData::SpecialMark(const StrArray<3>& strValue)
{
	m_SpecialMark.SetArray(strValue);
}

/*------------------------------------------*/
CString JunctionData::RawKey()
{
	return m_PumpConfig.GetData();
}
void JunctionData::RawKey(CString strValue)
{
	m_PumpConfig.SetData(strValue);
}