// CalcFileFace.h: interface for the CalcFileFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCFILEFACE_H__3E5B7EAE_72C2_47F2_AC34_5A342CBB5259__INCLUDED_)
#define AFX_CALCFILEFACE_H__3E5B7EAE_72C2_47F2_AC34_5A342CBB5259__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CalcFuildFace.h"
#include "CalcSteadyFace.h"
#include "CalcTransFace.h"
#include "CalcPipeMgrFace.h"
#include "CalcJunMgrFace.h"

class CalcDriverMgr;
class NetModelPersist;
class PersistentModel;

class AFX_EXT_CLASS CalcFileFace  
{
public:
	CalcFileFace();
	virtual ~CalcFileFace();
	ErrorStatus::FileError Save(CalcDriverMgr &Data,PersistentModel& model);

private:
	ErrorStatus::FileError Save(CalcDriverMgr &Data,NetModelPersist& model);
	CalcFuildFace m_fuild;
	CalcSteadyFace m_steady;
	CalcTransFace m_trans;
	CalcPipeMgrFace m_pipeMgr;
	CalcJunMgrFace  m_junMgr;

};

#endif // !defined(AFX_CALCFILEFACE_H__3E5B7EAE_72C2_47F2_AC34_5A342CBB5259__INCLUDED_)
