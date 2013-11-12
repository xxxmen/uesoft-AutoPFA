// VisualRefData.h: interface for the VisualRefData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VISUALREFDATA_H__0D4D5F0B_A7B4_4D3D_8618_336C9C02446E__INCLUDED_)
#define AFX_VISUALREFDATA_H__0D4D5F0B_A7B4_4D3D_8618_336C9C02446E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "persistentObj.h"

class VisualRefData : public PersistentObj  
{
public:
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	void Init();
	VisualRefData();
	virtual ~VisualRefData();

private:
	void InitArray();
	void InitRowHead();
	RowObject  m_ShowOptions;
	RowObject  m_NumDigits;
	RowObject  m_Font;
	RowObject  m_FontStyle;
	RowObject  m_TitleFont;
	RowObject  m_TitleFontStyle;
	RowObject  m_LegendFont;
	RowObject  m_LegendFontStyle;
	RowObject  m_ColorMapOptions;
	RowObject  m_NumColorMaps0;
	RowObject  m_NumColorMaps1;
	RowObject  m_NumColorMaps2;
	RowObject  m_TransientOutputFilter;
	RowObject  m_TransientPipeOutput;
	RowObject  m_OutputFilter;
	RowObject  m_PipeOutput;
	RowObject  m_JunOutput;
	RowObject  m_InputFilter;
	RowObject  m_PipeInput;
	RowObject  m_JunInput;
	RowObject  m_TitleLocation;
	RowObject  m_LegendLocation;

	void InitShowOptions(CString InData);
	void InitNumDigits(CString InData);
	void InitFont(CString InData);
	void InitFontStyle(CString InData);
	void InitTitleFont(CString InData);
	void InitTitleFontStyle(CString InData);
	void InitLegendFont(CString InData);
	void InitLegendFontStyle(CString InData);
	void InitColorMapOptions(CString InData);
	void InitNumColorMaps0(CString InData);
	void InitNumColorMaps1(CString InData);
	void InitOutputFilter(CString InData);
	void InitPipeOutput(CString InData);
	void InitJunOutput(CString InData);
	void InitInputFilter(CString InData);
	void InitPipeInput(CString InData);
	void InitJunInput(CString InData);
	void InitTitleLocation(CString InData);
	void InitLegendLocation(CString InData);
};

#endif // !defined(AFX_VISUALREFDATA_H__0D4D5F0B_A7B4_4D3D_8618_336C9C02446E__INCLUDED_)
