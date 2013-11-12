// AFTConfigFace.cpp: implementation of the AFTConfigFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTConfigFace.h"
#include "AFTConfigItemFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTConfigFace::AFTConfigFace()
{

}

AFTConfigFace::~AFTConfigFace()
{

}

ErrorStatus::FileError AFTConfigFace::Read(PumpConfig &Data,ConfigPerisist &Model)
{
	// TODO: Add extra Read here
	Model.PressType(Data.PressType());
	Model.PressUnit(Data.PressUnit());
	Model.FlowType(Data.FlowType());
	Model.FlowUnit(Data.FlowUnit());
	Model.PowerType(Data.PowerType());
	Model.PowerUnit(Data.PowerUnit());
	Model.Type(Data.Type());

	AFTConfigItemFace face;
	PumpConfigData *pConfigData = NULL;
	ConfigItemPerisist *pConfigItem = NULL;
	IteratorPtr<PumpConfigData> ItPtr(Data.CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pConfigData = &ItPtr->CurrentItem();
		pConfigItem = Model.CreatConfigItem();
		ASSERT(pConfigItem != NULL);
		face.Read(pConfigData,pConfigItem);
	}
	return ErrorStatus::eFileOK;
}
ErrorStatus::FileError AFTConfigFace::Save(PumpConfig &Data,ConfigPerisist &Model)
{
	// TODO: Add extra Save here
	Data.PressType(Model.PressType());
	Data.PressUnit(Model.PressUnit());
	Data.FlowType(Model.FlowType());
	Data.FlowUnit(Model.FlowUnit());
	Data.PowerType(Model.PowerType());
	Data.PowerUnit(Model.PowerUnit());
	Data.Type(Model.Type());
	Data.Num(Model.GetCount());

	AFTConfigItemFace face;
	PumpConfigData *pConfigData = NULL;
	ConfigItemPerisist *pConfigItem = NULL;
	IteratorPtr<ConfigItemPerisist> ItPtr(Model.CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pConfigItem = &ItPtr->CurrentItem();
		pConfigData = Data.CreatConfigData();
		ASSERT(pConfigData != NULL);
		face.Save(pConfigData,pConfigItem);
		pConfigData->InitObject();
		Data.m_Num.Data().AddChild(pConfigData->GetObject());
	}
	return ErrorStatus::eFileOK;
}