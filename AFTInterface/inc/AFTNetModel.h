// AFTNetModel.h: interface for the AFTNetModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTNETMODEL_H__057CEBB0_59F8_4621_A1D0_6544A7059D2C__INCLUDED_)
#define AFX_AFTNETMODEL_H__057CEBB0_59F8_4621_A1D0_6544A7059D2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "NetModelData.h"
#include "NetModelPersist.h"
#include "AFTPipeMgr.h"
#include "AFTJunMgr.h"
#include "AFTSysPropety.h"
#include "AFTSteadyFace.h"
#include "AFTSectionPipeFace.h"
#include "AFTTransControlFace.h"
#include "AFTOutputRef.h"


class AFX_EXT_CLASS AFTNetModel  
{
public:
	AFTNetModel();
	virtual ~AFTNetModel();
	ErrorStatus::FileError Read(NetModelData &Data,NetModelPersist& model);
	ErrorStatus::FileError Save(NetModelData &Data,NetModelPersist& model);

private:
	AFTJunMgr     m_junMgr;
	AFTPipeMgr    m_pipeMgr;
	AFTSysPropety m_sysPropety;
	AFTSteadyFace m_SteadyFace;
	AFTSectionPipeFace m_SectionFace;
	AFTTransControlFace m_TransControlFace;
	AFTOutputRef m_OutPutFace;
};

#endif // !defined(AFX_AFTNETMODEL_H__057CEBB0_59F8_4621_A1D0_6544A7059D2C__INCLUDED_)
