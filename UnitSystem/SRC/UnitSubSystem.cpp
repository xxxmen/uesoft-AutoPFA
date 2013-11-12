// UnitSubSystem.cpp: implementation of the UnitSubSystem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UnitSubSystem.h"
#include "QuantityManager.h"
#include <vector>
#include "UnitSystemShareHeader.h"

using namespace std;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UnitSubSystem::UnitSubSystem():m_Area(_T("面积单位"),Area,_T("Area"))
,m_Density(_T("密度单位"),Density,_T("Density"))	
,m_Diameter(_T("直径单位"),Diameter,_T("Diameter"))	
,m_HeadGradient(_T("水头坡度单位"),HeadGradient,_T("HeadGradient"))
,m_Inertia(_T("惯性单位"),Inertia,_T("Inertia"))		
,m_Length(_T("长度单位"),Length,_T("Length"))	
,m_MassFlow(_T("质量流量单位"),MassFlow,_T("MassFlow"))
,m_Mass(_T("质量单位"),Mass,_T("Mass"))		
,m_PercentFractional(_T("百分数/小数"),PercentFractional,_T("PercentFractional")) 
,m_Power(_T("功率单位"),Power,_T("Power"))			
,m_PressGradient(_T("压力坡度单位"),PressGradient,_T("PressGradient"))
,m_Pressure(_T("压力单位"),Pressure,_T("Pressure"))	
,m_Resistance(_T("阻力单位"),Resistance,_T("Resistance"))		
,m_Temperature(_T("温度单位"),Temperature,_T("Temperature"))
,m_Time(_T("时间单位"),Time,_T("Time"))	
,m_Torque(_T("转矩单位"),Torque,_T("Torque"))		
,m_Velocity(_T("速度单位"),Velocity,_T("Velocity"))
,m_Viscosity(_T("粘度单位"),Viscosity,_T("Viscosity"))	
,m_Volume(_T("体积单位"),Volume,_T("Volume"))	
,m_VolumetricFlow(_T("体积流量单位"),VolumetricFlow,_T("VolumetricFlow"))	
,m_WeightperLength(_T("Weight per Length单位"),WeightperLength,_T("WeightperLength"))
,m_PressPerMeter(_T("Press Per Meter单位"),PressPerMeter,_T("PressPerMeter")) 
{
	InitArrayRef();
}

UnitSubSystem::UnitSubSystem(const UnitSubSystem &ref)
{
	InitArrayRef();
	Assigned(ref.m_arrayRef);
}

UnitSubSystem& UnitSubSystem::operator=(const UnitSubSystem &ref)
{
	//判断自赋值
	if(this == &ref)
		return *this;
    //调用基类赋值
	//释放堆内存
	//重新分配堆内存
	//赋值
	InitArrayRef();
	Assigned(ref.m_arrayRef);
	return *this;
}

UnitSubSystem::~UnitSubSystem()
{
}

//注册所有的单位
void UnitSubSystem::InitArrayRef()
{
	m_arrayRef.SetSize(21);
	m_arrayRef.SetAt(0,&m_Area);
	m_arrayRef.SetAt(1,&m_Density);
	m_arrayRef.SetAt(2,&m_Diameter);
	m_arrayRef.SetAt(3,&m_HeadGradient);
	m_arrayRef.SetAt(4,&m_Inertia);
	m_arrayRef.SetAt(5,&m_Length);
	m_arrayRef.SetAt(6,&m_MassFlow);
	m_arrayRef.SetAt(7,&m_Mass);
	m_arrayRef.SetAt(8,&m_PercentFractional);
	m_arrayRef.SetAt(9,&m_Power);
	m_arrayRef.SetAt(10,&m_PressGradient);
	m_arrayRef.SetAt(11,&m_Pressure);
	m_arrayRef.SetAt(12,&m_Resistance);
	m_arrayRef.SetAt(13,&m_Temperature);
	m_arrayRef.SetAt(14,&m_Time);
	m_arrayRef.SetAt(15,&m_Torque);
	m_arrayRef.SetAt(16,&m_Velocity);
	m_arrayRef.SetAt(17,&m_Viscosity);
	m_arrayRef.SetAt(18,&m_Volume);
	m_arrayRef.SetAt(19,&m_VolumetricFlow);
	m_arrayRef.SetAt(20,&m_WeightperLength);
}

void UnitSubSystem::Init()
{
	TCHAR exeFullPath[MAX_PATH];
	::GetModuleFileName(NULL,exeFullPath,MAX_PATH);
	CString strPath(exeFullPath);
	int index = strPath.ReverseFind('\\');
	ASSERT(index != -1);
	strPath = strPath.Left(index+1);
	strPath += _T("QuantityConfig.txt");
	
	QuantityManager& qm = QuantityManager::Instance();
	qm.SetConfigFilePathCString( strPath );
	//string strTemp = strPath.GetBuffer( 0 );   // 原来的方案，会引起访问越界
	//qm.SetConfigFilePath( strTemp );
	qm.Init();
	vector< UeStdString > set;
	UeStdString strdefault;
	UeStdString  strQuantity;
    vector<UeStdString>* pSetVector = NULL; 
	UnitType *pUnitType = NULL;
	for(int i=0;i<m_arrayRef.GetSize();i++)
	{
	    pUnitType = m_arrayRef.GetAt(i);
	    ASSERT(pUnitType != NULL);
	    set.clear();
	    strQuantity = pUnitType->GetStrID().GetBuffer(0);
	    pSetVector = qm.GetPFASet(strQuantity);
        vector< UeStdString >::iterator iter = pSetVector->begin();
	    for (;iter != pSetVector->end(); iter++)
	    {
		set.push_back(*iter);
	    }
		pSetVector = NULL;
	    qm.GetDefaultUnitString(strdefault,strQuantity);
	    pUnitType->InitSymbol(set);
	    pUnitType->SetCurSymbol(strdefault.c_str());
	    pUnitType->SetStdSymbol(strdefault.c_str());
		
	}
	
}

BOOL UnitSubSystem::FindUnit(UnitTypeID id,UnitType *&pUnitType)
{
	for(int i=0;i<m_arrayRef.GetSize();i++)
	{
		pUnitType = m_arrayRef.GetAt(i);
		ASSERT(pUnitType != NULL);
		if(id == pUnitType->GetTypeID())
		{
			return TRUE;
		}
	}
	return FALSE;
}

BOOL UnitSubSystem::FilterString(UnitTypeID id,CString strSymbol,BOOL bUsed)
{
	UnitType *pUnitType = NULL;
	if(FindUnit(id,pUnitType))
	{
		return pUnitType->FilterString(strSymbol,bUsed);
	}
	else
	{
		return FALSE;
	}
}
BOOL UnitSubSystem::SetDefUnitString(UnitTypeID id,CString strSymbol)
{
	UnitType *pUnitType = NULL;
	if(FindUnit(id,pUnitType))
	{
		pUnitType->SetCurSymbol(strSymbol);
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}


UnitTypeArrayRef& UnitSubSystem::GetUnitArray()
{
	return m_arrayRef;
}

void UnitSubSystem::Assigned(const UnitTypeArrayRef &ref)
{
	UnitType *pUnitRef = NULL;
	UnitType *pUnitType = NULL;
	for(int i=0;i<ref.GetSize();i++)
	{
		pUnitRef = ref.GetAt(i);
		pUnitType = m_arrayRef.GetAt(i);
		ASSERT(pUnitType != NULL);
		ASSERT(pUnitRef != NULL);
		*pUnitType = *pUnitRef;	
	}
}

BOOL UnitSubSystem::FindSymbolArray(UnitTypeID id,SymbolArray &array)
{
	UnitType *pUnitType = NULL;
	if(FindUnit(id,pUnitType))
	{
		pUnitType->GetUsedArray(array);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
//用户设置输入数据的默认单位。
CString UnitSubSystem::FindCurSymbol(UnitTypeID id)
{
	CString strRet;
	UnitType *pUnitType = NULL;
	if(FindUnit(id,pUnitType))
	{
		ASSERT(pUnitType != NULL);
		strRet = pUnitType->GetCurSymbol();
	}
	return strRet;
}
//计算使用的标准单位
CString UnitSubSystem::FindStdSymbol(UnitTypeID id)
{
	CString strRet;
	UnitType *pUnitType = NULL;
	if(FindUnit(id,pUnitType))
	{
		ASSERT(pUnitType != NULL);
		strRet = pUnitType->GetStdSymbol();
	}
	return strRet;
}

double UnitSubSystem::StdToCur(UnitTypeID id,double d)
{
	CString strCurUnit = FindCurSymbol(id);
	return StdToSelUnit(d,strCurUnit);
}

double UnitSubSystem::StdToSelUnit(double d,CString strUnit)
{
	double dOut = 0.0;
	QuantityManager& qm = QuantityManager::Instance();
	if(!qm.TransformFromStd(dOut,strUnit.GetBuffer(0),d))
	{
		dOut = d;
	}
	return dOut;
}
