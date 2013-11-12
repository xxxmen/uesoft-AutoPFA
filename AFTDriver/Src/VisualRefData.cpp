// VisualRefData.cpp: implementation of the VisualRefData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VisualRefData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

VisualRefData::VisualRefData()
{
	InitArray();
}

VisualRefData::~VisualRefData()
{

}

void VisualRefData::InitRowHead()
{
	SetID("\n[VISUAL PREFERENCES]");
	if ( isImpFile )
	{
		CString strArray[22];
		strArray[0] = _T("VRShowOptions=");
		strArray[1] = _T("VRNumDigits=");
		strArray[2] = _T("VRFont=");
		strArray[3] = _T("VRFontStyle=");
		strArray[4] = _T("VRTitleFont=");
		strArray[5] = _T("VRTitleFontStyle=");
		strArray[6] = _T("VRLegendFont=");
		strArray[7] = _T("VRLegendFontStyle=");
		strArray[8] = _T("VRColorMapOptions=");
		strArray[9] = _T("VRNumColorMaps0=");
		strArray[10] = _T("VRNumColorMaps1=");
		strArray[11] = _T("VRNumColorMaps2=");
		strArray[12] = _T("VRTransientOutputFilter=");
		strArray[13] = _T("VRTransientPipeOutput=");
		strArray[14] = _T("VROutputFilter=");
		strArray[15] = _T("VRPipeOutput=");
		strArray[16] = _T("VRJctOutput=");
		strArray[17] = _T("VRInputFilter=");
		strArray[18] = _T("VRPipeInput=");
		strArray[19] = _T("VRJctInput=");
		strArray[20] = _T("VRTitleLocation=");
		strArray[21] = _T("VRLegendLocation=");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==22);
			m_RowArray.GetAt(i)->InitHead(strArray[i]);
		}
	} 
	else
	{
		CString strArray[19];
		strArray[0] = _T("VRShowOptions= ");
		strArray[1] = _T("VRNumDigits= ");
		strArray[2] = _T("VRFont= ");
		strArray[3] = _T("VRFontStyle= ");
		strArray[4] = _T("VRTitleFont= ");
		strArray[5] = _T("VRTitleFontStyle= ");
		strArray[6] = _T("VRLegendFont= ");
		strArray[7] = _T("VRLegendFontStyle= ");
		strArray[8] = _T("VRColorMapOptions= ");
		strArray[9] = _T("VRNumColorMaps0= ");
		strArray[10] = _T("VRNumColorMaps1= ");
		strArray[11] = _T("VROutputFilter= ");
		strArray[12] = _T("VRPipeOutput= ");
		strArray[13] = _T("VRJctOutput= ");
		strArray[14] = _T("VRInputFilter= ");
		strArray[15] = _T("VRPipeInput= ");
		strArray[16] = _T("VRJctInput= ");
		strArray[17] = _T("VRTitleLocation= ");
		strArray[18] = _T("VRLegendLocation= ");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==19);
			m_RowArray.GetAt(i)->InitHead(strArray[i]);
		}
	}
}

void VisualRefData::InitArray()
{
	if ( isImpFile )
	{
		m_RowArray.SetSize(22);
		m_RowArray.SetAt(0,&m_ShowOptions);
		m_RowArray.SetAt(1,&m_NumDigits);
		m_RowArray.SetAt(2,&m_Font);
		m_RowArray.SetAt(3,&m_FontStyle);
		m_RowArray.SetAt(4,&m_TitleFont);
		m_RowArray.SetAt(5,&m_TitleFontStyle);
		m_RowArray.SetAt(6,&m_LegendFont);
		m_RowArray.SetAt(7,&m_LegendFontStyle);
		m_RowArray.SetAt(8,&m_ColorMapOptions);
		m_RowArray.SetAt(9,&m_NumColorMaps0);
		m_RowArray.SetAt(10,&m_NumColorMaps1);
		m_RowArray.SetAt(11,&m_NumColorMaps2);
		m_RowArray.SetAt(12,&m_TransientOutputFilter);
		m_RowArray.SetAt(13,&m_TransientPipeOutput);
		m_RowArray.SetAt(14,&m_OutputFilter);
		m_RowArray.SetAt(15,&m_PipeOutput);
		m_RowArray.SetAt(16,&m_JunOutput);
		m_RowArray.SetAt(17,&m_InputFilter);
		m_RowArray.SetAt(18,&m_PipeInput);
		m_RowArray.SetAt(19,&m_JunInput);
		m_RowArray.SetAt(20,&m_TitleLocation);
		m_RowArray.SetAt(21,&m_LegendLocation);
	} 
	else
	{
		m_RowArray.SetSize(19);
		m_RowArray.SetAt(0,&m_ShowOptions);
		m_RowArray.SetAt(1,&m_NumDigits);
		m_RowArray.SetAt(2,&m_Font);
		m_RowArray.SetAt(3,&m_FontStyle);
		m_RowArray.SetAt(4,&m_TitleFont);
		m_RowArray.SetAt(5,&m_TitleFontStyle);
		m_RowArray.SetAt(6,&m_LegendFont);
		m_RowArray.SetAt(7,&m_LegendFontStyle);
		m_RowArray.SetAt(8,&m_ColorMapOptions);
		m_RowArray.SetAt(9,&m_NumColorMaps0);
		m_RowArray.SetAt(10,&m_NumColorMaps1);
		m_RowArray.SetAt(11,&m_OutputFilter);
		m_RowArray.SetAt(12,&m_PipeOutput);
		m_RowArray.SetAt(13,&m_JunOutput);
		m_RowArray.SetAt(14,&m_InputFilter);
		m_RowArray.SetAt(15,&m_PipeInput);
		m_RowArray.SetAt(16,&m_JunInput);
		m_RowArray.SetAt(17,&m_TitleLocation);
		m_RowArray.SetAt(18,&m_LegendLocation);
	}
	
	InitRowHead();
}

void VisualRefData::Init()
{
	if ( isImpFile )
	{
		CString strArray[22];
		strArray[0] = _T("0,0,0,0,-1,-1,0,0,0,-1,-1,0,0,-1");
		strArray[1] = _T("2");
		strArray[2] = _T("Arial");
		strArray[3] = _T("9,0,0");
		strArray[4] = _T("Arial");
		strArray[5] = _T("12.6,0,0");
		strArray[6] = _T("Arial");
		strArray[7] = _T("9,0,0");
		strArray[8] = _T("5");
		strArray[9] = _T("0");
		strArray[10] = _T("0");
		strArray[11] = _T("0");
		strArray[12] = _T("0");
		strArray[13] = _T("0");
		strArray[14] = _T("0");
		strArray[15] = _T("0");
		strArray[16] = _T("0");
		strArray[17] = _T("1");
		strArray[18] = _T("0");
		strArray[19] = _T("0");
		strArray[20] = _T("-1,-1");
		strArray[21] = _T("-1,-1");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==22);
			m_RowArray.GetAt(i)->ReadChild(strArray[i]);
		}
	} 
	else
	{
		CString strArray[19];
		strArray[0] = _T("0,0,0,0,-1,0,0,-1,0,-1,-1,0,0,-1,0");
		strArray[1] = _T("4");
		strArray[2] = _T("Arial");
		strArray[3] = _T("9,0,0");
		strArray[4] = _T("Arial");
		strArray[5] = _T("13,0,0");
		strArray[6] = _T("Arial");
		strArray[7] = _T("9,0,0");
		strArray[8] = _T("5");
		strArray[9] = _T("0");
		strArray[10] = _T("0");
		strArray[11] = _T("0");
		strArray[12] = _T("1,3");
		strArray[13] = _T("1,9");
		strArray[14] = _T("1");
		strArray[15] = _T("0");
		strArray[16] = _T("0");
		strArray[17] = _T("555,855");
		strArray[18] = _T("7290,240");
		for(int i=0;i<m_RowArray.GetSize();i++)
		{
			ASSERT(m_RowArray.GetSize()==19);
			m_RowArray.GetAt(i)->ReadChild(strArray[i]);
		}
	}
}

BOOL VisualRefData::Save(CStdioFile &file)
{
	if ( isImpFile )
	{
		return SaveData(file);
	} 
	else
	{
		SaveMark(file);
		file.WriteString( m_ShowOptions.Save() ) ;
		file.WriteString( m_NumDigits.Save() ) ;
		file.WriteString( m_Font.Save() ) ;
		file.WriteString( m_FontStyle.Save() ) ;
		file.WriteString( m_TitleFont.Save() ) ;
		file.WriteString( m_TitleFontStyle.Save() ) ;
		file.WriteString( m_LegendFont.Save() ) ;
		file.WriteString( m_LegendFontStyle.Save() ) ;
		file.WriteString( m_ColorMapOptions.Save() ) ;
		file.WriteString( m_NumColorMaps0.Save() ) ;
		file.WriteString( m_NumColorMaps1.Save() ) ;
		file.WriteString( m_OutputFilter.Save() ) ;
		file.WriteString( m_PipeOutput.Save() ) ;
		file.WriteString( m_JunOutput.Save() ) ;
		file.WriteString( m_InputFilter.Save() ) ;
		file.WriteString( m_PipeInput.Save() ) ;
		file.WriteString( m_JunInput.Save() ) ;
		file.WriteString( m_TitleLocation.Save() ) ;
		file.WriteString( m_LegendLocation.Save() ) ;
		
		return TRUE ;
	}
//	return SaveData(file);
}

BOOL VisualRefData::Read(CStdioFile &file)
{
	if ( isImpFile )
	{
		return ReadData(file);
	} 
	else
	{
		CString strTemp ;
		file.ReadString( strTemp ) ;
		InitShowOptions( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitNumDigits( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitFont( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitFontStyle( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitTitleFont( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitTitleFontStyle( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitLegendFont( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitLegendFontStyle( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitColorMapOptions( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitNumColorMaps0( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitNumColorMaps1( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitOutputFilter( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitPipeOutput( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitJunOutput( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitInputFilter( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitPipeInput( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitJunInput( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitTitleLocation( strTemp ) ;
		file.ReadString( strTemp ) ;
		InitLegendLocation( strTemp ) ;
	
		return TRUE;
	}
//	return ReadData(file);
}





void VisualRefData::InitShowOptions(CString InData)
{
	m_ShowOptions.InitRow(InData) ;
}
void VisualRefData::InitNumDigits(CString InData)
{
	m_NumDigits.InitRow(InData) ;
}
void VisualRefData::InitFont(CString InData)
{
	m_Font.InitRow(InData) ;
}
void VisualRefData::InitFontStyle(CString InData)
{
	m_FontStyle.InitRow(InData) ;
}
void VisualRefData::InitTitleFont(CString InData)
{
	m_TitleFont.InitRow(InData) ;
}
void VisualRefData::InitTitleFontStyle(CString InData)
{
	m_TitleFontStyle.InitRow(InData) ;
}
void VisualRefData::InitLegendFont(CString InData)
{
	m_LegendFont.InitRow(InData) ;
}
void VisualRefData::InitLegendFontStyle(CString InData)
{
	m_LegendFontStyle.InitRow(InData) ;
}
void VisualRefData::InitColorMapOptions(CString InData)
{
	m_ColorMapOptions.InitRow(InData) ;
}
void VisualRefData::InitNumColorMaps0(CString InData)
{
	m_NumColorMaps0.InitRow(InData) ;
}
void VisualRefData::InitNumColorMaps1(CString InData)
{
	m_NumColorMaps1.InitRow(InData) ;
}
void VisualRefData::InitOutputFilter(CString InData)
{
	m_OutputFilter.InitRow(InData) ;
}
void VisualRefData::InitPipeOutput(CString InData)
{
	m_PipeOutput.InitRow(InData) ;
}
void VisualRefData::InitJunOutput(CString InData)
{
	m_JunOutput.InitRow(InData) ;
}
void VisualRefData::InitInputFilter(CString InData)
{
	m_InputFilter.InitRow(InData) ;
}
void VisualRefData::InitPipeInput(CString InData)
{
	m_PipeInput.InitRow(InData) ;
}
void VisualRefData::InitJunInput(CString InData)
{
	m_JunInput.InitRow(InData) ;
}
void VisualRefData::InitTitleLocation(CString InData)
{
	m_TitleLocation.InitRow(InData) ;
}
void VisualRefData::InitLegendLocation(CString InData)
{
	m_LegendLocation.InitRow(InData) ;
}