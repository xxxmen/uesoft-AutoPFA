// AFTNetModel.cpp: implementation of the AFTNetModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTNetModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTNetModel::AFTNetModel()
{

}

AFTNetModel::~AFTNetModel()
{

}

ErrorStatus::FileError AFTNetModel::Read(NetModelData &Data,NetModelPersist& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	errorMark = m_junMgr.Read(Data.GetJunMgr(),model.GetJunMgr());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	errorMark = m_pipeMgr.Read(Data.GetPipesMgr(),model.GetPipesMgr());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	errorMark = m_sysPropety.Read(Data.GetFluidData(),model.GetSysProperty());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	errorMark = m_SteadyFace.Read(Data.GetSettingData(),model.GetSteady());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	errorMark = m_SectionFace.Read(Data.GetSectionData(),model.GetSectionPipe());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	errorMark = m_TransControlFace.Read(Data.GetTranContorlData(),model.GetTransControl());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	return errorMark;
}

ErrorStatus::FileError AFTNetModel::Save(NetModelData &Data,NetModelPersist& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	errorMark = m_junMgr.Save(Data.GetJunMgr(),model.GetJunMgr());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	errorMark = m_pipeMgr.Save(Data.GetPipesMgr(),model.GetPipesMgr());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	errorMark = m_sysPropety.Save(Data.GetFluidData(),model.GetSysProperty());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	errorMark = m_SteadyFace.Save(Data.GetSettingData(),model.GetSteady());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	errorMark = m_SectionFace.Save(Data.GetSectionData(),model.GetSectionPipe());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	errorMark = m_TransControlFace.Save(Data.GetTranContorlData(),model.GetTransControl());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	return errorMark;
}
