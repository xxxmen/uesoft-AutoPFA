// CalcFileFace.cpp: implementation of the CalcFileFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcFileFace.h"
#include "CaclDriverMgr.h"
#include "netmodelpersist.h"
#include "persistenmodel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcFileFace::CalcFileFace()
{

}

CalcFileFace::~CalcFileFace()
{

}

ErrorStatus::FileError CalcFileFace::Save(CalcDriverMgr &Data,NetModelPersist& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	errorMark = m_junMgr.Save(Data.GetJunMgr(),model.GetJunMgr());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	errorMark = m_pipeMgr.Save(Data.GetPipeMgr(),model.GetPipesMgr());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	errorMark = m_fuild.Save(Data.GetFuild(),model.GetSysProperty());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	errorMark = m_steady.Save(Data.GetSteady(),model.GetSteady());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	Data.GetTrans().TimeStep(_tcstod(model.GetSectionPipe().TimeStep() , '\0'));
	errorMark = m_trans.Save(Data.GetTrans(),model.GetTransControl());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	return errorMark;
}
ErrorStatus::FileError CalcFileFace::Save(CalcDriverMgr &Data,PersistentModel& model)
{
	NetModelPersist *pModel = model.GetScenarioPersist().GetBase();
	if(pModel == NULL)
	{
		ASSERT(FALSE);
		return ErrorStatus::eSaveFileError;
	}
	return Save(Data,*pModel);
}
