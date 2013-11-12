// NetModelData.h: interface for the NetModelData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETMODELDATA_H__224C3FC6_FC3B_407C_9129_E5F950022D5D__INCLUDED_)
#define AFX_NETMODELDATA_H__224C3FC6_FC3B_407C_9129_E5F950022D5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SettingData.h"
#include "SectionData.h"
#include "TranContorlData.h"
#include "FluidData.h"
#include "OutPutRef.h"
#include "VisualRefData.h"
#include "PipesMgr.h"
#include "JunctionsMgr.h"

class AFX_EXT_CLASS NetModelData  
{
public:
	SectionData& GetSectionData();
	TranContorlData& GetTranContorlData();
	SettingData& GetSettingData();
	FluidData& GetFluidData();
	OutPutRefData& GetOutputRefData();
	VisualRefData& GetVisualRefData();
	JunctionsMgr& GetJunMgr();
	PipesMgr& GetPipesMgr();
	BOOL Read(CStdioFile &file, CString strMark);
	BOOL Save(CStdioFile &file);
	void SetIDSub(CString strMark,CString strName,CString strAncest);
	void Init();
	NetModelData();
	virtual ~NetModelData();

private:
	SettingData      m_settingData;
	SectionData      m_sectionData;
	TranContorlData  m_tranControlData;
	FluidData        m_fluidData;
	OutPutRefData    m_outRefData;
	VisualRefData    m_visualRef;
    PipesMgr         m_pipeMgr;
	JunctionsMgr     m_junMgr;
	ObjectArray      m_objArray;
};

inline SettingData& NetModelData::GetSettingData()
{
	return m_settingData;
}

inline SectionData& NetModelData::GetSectionData()
{
	return m_sectionData;
}

inline TranContorlData& NetModelData::GetTranContorlData()
{
	return m_tranControlData;
}

inline FluidData& NetModelData::GetFluidData()
{
	return m_fluidData;
}

inline OutPutRefData& NetModelData::GetOutputRefData()
{
	return m_outRefData;
}

inline VisualRefData& NetModelData::GetVisualRefData()
{
	return m_visualRef;
}

inline PipesMgr& NetModelData::GetPipesMgr()
{
	return m_pipeMgr;
}

inline JunctionsMgr& NetModelData::GetJunMgr()
{
	return m_junMgr;
}




#endif // !defined(AFX_NETMODELDATA_H__224C3FC6_FC3B_407C_9129_E5F950022D5D__INCLUDED_)
