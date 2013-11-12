// ParamRef.h: interface for the ParamRef class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARAMREF_H__F20F939E_8C9F_49E8_82E8_2CF2457AEABD__INCLUDED_)
#define AFX_PARAMREF_H__F20F939E_8C9F_49E8_82E8_2CF2457AEABD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PersistentObj.h"

class ParamRef : public PersistentObj  
{
public:
	void InitRowHead();
	void Init();
	BOOL Read(CStdioFile &file);
	BOOL Save(CStdioFile &file);
	ParamRef();
	virtual ~ParamRef();

private:
	void InitArray();
	RowObject  m_HGLoRPres;
	RowObject  m_FlowRate;
	RowObject  m_LossModel;
	RowObject  m_EleSpec;
	RowObject  m_DefaultEle;
	RowObject  m_PipeDesign;
	RowObject  m_PipeDesignLoss;
	RowObject  m_PipeDesignHeatTransfer;
	RowObject  m_JunDesign;
	RowObject  m_PumpDesign;
	RowObject  m_UseLastPipe;
	RowObject  m_LastMaterial;
	RowObject  m_LastSize;
	RowObject  m_LastType;
	RowObject  DefaultMaterial;
};

#endif // !defined(AFX_PARAMREF_H__F20F939E_8C9F_49E8_82E8_2CF2457AEABD__INCLUDED_)
