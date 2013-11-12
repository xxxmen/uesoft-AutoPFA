// PipeOutShow.cpp: the source file of output control.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OutDataAttr.h"
#include "UnitSubSystem.h"
#include "PipeOutShow.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
PipeOutShow::PipeOutShow()
{

}
PipeOutShow::~PipeOutShow()
{

}

CString PipeOutShow::GetKey()
{
	return m_Key;
}

void PipeOutShow::SetKey(CString nkey)
{
	m_Key=nkey;
}

UnitTypeID PipeOutShow::GetTypeId()
{
	return m_TypeId;
}

void PipeOutShow::SetTypeId(UnitTypeID nTypeId)
{
	m_TypeId=nTypeId;
}

CString PipeOutShow::GetStrName()
{
	return m_StrName;
}

void PipeOutShow::SetStrName(CString nStrName)
{
	m_StrName=nStrName;
}

CString PipeOutShow::GetStrUnit()
{
	return m_StrUnit;
}

void PipeOutShow::SetStrUnit(CString nStrUnit)
{
	m_StrUnit=nStrUnit;
}

BOOL PipeOutShow::GetShow()
{
	return m_Show;
}

void PipeOutShow::SetShow(BOOL nShow)
{
	m_Show=nShow;
}


// PipeOutShow& PipeOutShow::operator=(const PipeOutShow &ref)
// {
// 	//判断自赋值
// 	if(this == &ref)
// 		return *this;
//     //调用基类赋值
// 	//释放堆内存
// 	//重新分配堆内存
// 	//赋值
// 	//	InitArrayRef();
// 	//	Assigned(ref.m_PipeOutArray);
// 	//	Assigned(ref.m_JunOutArray);
// 	return *this;
// }

// void PipeOutShow::InitAttrPipe(PipeOutShowArray &array,CString strTemp,CString strTemp1)
// {
// 	CString str[50];//保存单位；
// 	CString str1[50];//保存Key;
// 	
// 	InitUnit(strTemp,str);
// 	InitData(strTemp1,str1);
// 	
// 	for (int i=0;i<50;i++)
// 	{
// 		array[i].SetKey(str1[i]);
// 		
// 		switch (str1[i])
// 		{
// 		case (str1[i]=="114"||str1[i]=="110"||str1[i]=="109"||str1[i]=="86"||str1[i]=="100"||str1[i]=="99"||str1[i]=="101"//
// 			||str1[i]=="111"||str1[i]=="112"||str1[i]=="115"||str1[i]=="113"||str1[i]=="89"||str1[i]=="105"):
// 			{
// 				array[i].SetTypeId(None);
// 				array[i].SetShow(TRUE);
// 				break;
// 			}
// 		case (str1[i]=="3"):
// 			{
// 				array[i].SetTypeId(VolumetricFlow);
// 				array[i].SetShow(TRUE);
// 				break;
// 			}
// 		case (str1[i]=="7"||str1[i]=="132"):
// 			{
// 				array[i].SetTypeId(Velocity);
// 				array[i].SetShow(TRUE);
// 				break;
// 			}
// 		case (str1[i]=="14"||str1[i]=="15"||str1[i]=="22"||str1[i]=="17"||str1[i]=="21"||str1[i]=="8"||str1[i]=="9"||str1[i]=="11"/
// 			str1[i]=="12"||str1[i]=="16"||str1[i]=="19"||str1[i]=="18"||str1[i]=="68"):
// 			{
// 				array[i].SetTypeId(Pressure);
// 				array[i].SetShow(TRUE);
// 				break;
// 			}
// 		case (str1[i]=="130"||str1[i]=="131"||str1[i]=="31"||str1[i]=="129"||str1[i]=="29"||str1[i]=="30"||str1[i]=="27"||str1[i]=="28"/
// 			str1[i]=="127"||str1[i]=="102"):
// 			{	
// 				array[i].SetTypeId(Length);
// 				array[i].SetShow(TRUE);
// 				break;
// 			}
// 		case (str1[i]=="52"):
// 			{
// 				array[i].SetTypeId(Density);
// 				array[i].SetShow(TRUE);
// 				break;
// 			}
// 		case (str1[i]=="103"):
// 			{
// 				array[i].SetTypeId(Diameter);
// 				array[i].SetShow(TRUE);
// 				break;
// 			}
// 		case (str1[i]=="104"):
// 			{
// 				array[i].SetTypeId(Area);
// 				array[i].SetShow(TRUE);
// 				break;
// 			}
// 		case (str1[i]=="4"):
// 			{
// 				array[i].SetTypeId(MassFlow);
// 				array[i].SetShow(TRUE);
// 				break;
// 			}
// 		case (str1[i]=="24"||str1[i]=="25"||str1[i]=="23"):
// 			{
// 				array[i].SetTypeId(PressPerMeter);
// 				array[i].SetShow(TRUE);
// 				break;
// 			}
// 		case (str1[i]=="74"):
// 			{
// 				array[i].SetTypeId(Resistance);
// 				array[i].SetShow(TRUE);
// 				break;
// 			}
// 		case (str[i]=="61"):
// 			{
// 				array[i].SetTypeId(Viscosity);
// 				array[i].SetShow(TRUE);
// 				break;
// 			}
// 		default:
// 			break;
// 		}
// 
// 		array[i].SetStrUnit(str[i]);
// 	}
// 	
// }