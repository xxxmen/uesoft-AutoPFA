// PCFFileFace.h: interface for the PCFFileFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFFILEFACE_H__4CB7AA52_BD54_4B5D_BA79_BFB2AC807B9C__INCLUDED_)
#define AFX_PCFFILEFACE_H__4CB7AA52_BD54_4B5D_BA79_BFB2AC807B9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PCFPipeMgrFace.h"
#include "PCFJunMgrFace.h"
#include "PCFSteadyFace.h"
#include "PCFSysPropety.h"


class PCFDriverModel;
class PersistentModel;


class AFX_EXT_CLASS PCFFileFace  
{
public:
	ErrorStatus::FileError Read(PCFDriverModel &Data,PersistentModel& model);
	PCFFileFace();
	virtual ~PCFFileFace();

private:
	PCFPipeMgrFace m_pipeMgrFace;
	PCFJunMgrFace m_junMgrFace;
	PCFSteadyFace m_SteadyFace;
	PCFSysPropety m_SysPropety;
    

};

#endif // !defined(AFX_PCFFILEFACE_H__4CB7AA52_BD54_4B5D_BA79_BFB2AC807B9C__INCLUDED_)
