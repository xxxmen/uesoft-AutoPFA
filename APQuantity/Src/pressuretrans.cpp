#include "StdAfx.h"
#include "PressureTrans.h"
#include <assert.h>

/*
SIStd：中文意义是“国际标准”
*/

/****************************************************
pressureTransRatio静态数组存放的是压强物理量中所用到
的所有单位与标准单位之间的比例关系。
****************************************************/

IMPLEMENT_UNITSTRING( PressureTrans );

double PressureTrans::pressureTransRatio[PRESSURE_UNIT_NUM]
					= {1.0,1000.0,1000000.0
					,9.80665,98066.5,100000.0
					,101325,9.80665,133.322
					,6894.76,6894.76,1E+9,9.80665E+10,47.88};

const StdString PressureTrans::UnitStringArray[PRESSURE_UNIT_NUM]
					={_T("Pa"),_T("KPa"),_T("MPa"),_T("kgf/m_2"),_T("kgf/cm_2"),_T("bar"),
					_T("atm"),_T("mmH2o"),_T("mmHg"),_T("psi"),_T("lb/sq.in"),_T("kN/mm_2"),
					_T("1E+6kgf/cm_2"),_T("lb/sq.ft")};


/*************************************************
  Function: TransFromStd
  Description:返回输入参数所代表的单位与标准单位之间的比例关系
  Calls:无
  Called By:      // 调用本函数的函数清单
  Table Accessed: 无
  Table Updated: 无
  Input: PressureUnit desUnit,代表一个压强单位类型，
  参数的正确输入范围是0-9（包括边界）
  Output: 无
  Return: 返回比例关系，一个double型数据
  Others: 无
*************************************************/

double PressureTrans::TransFromStd( int desUnit)
{
	//ASSERT(desUnit >= 0 && desUnit <= 8);
	if (desUnit >= 0 && desUnit <= PRESSURE_UNIT_NUM - 1)
	{
		return 1.0/PressureTrans::pressureTransRatio[desUnit];
	}
	else
	{
		assert(0);
		return 0;
	}
}

/*************************************************
  Function: TransToStd
  Description:返回标准单位与输入参数所代表的单位之间的比例关系
  Calls:无
  Called By:      // 调用本函数的函数清单
  Table Accessed: 无
  Table Updated: 无
  Input: LengthUnit orgUnit,代表一个压强单位类型，
  参数的正确输入范围是0-9（包括边界）
  Output: 无
  Return: 返回比例关系，一个double型数据
  Others: 无
*************************************************/

double PressureTrans::TransToStd( int orgUnit)
{
	//ASSERT(orgUnit >= 0 && orgUnit <= 8);
	if (orgUnit >= 0 && orgUnit <= PRESSURE_UNIT_NUM - 1)
	{
		return PressureTrans::pressureTransRatio[orgUnit];
	}
	else
	{
		assert(0);
		return 0;
	}
}

/*************************************************
  Function: IsSIStd
  Description:返回输入参数所代表的单位是否为该物理量
  的标准单位
  Calls:无
  Called By:      // 调用本函数的函数清单
  Table Accessed: 无
  Table Updated: 无
  Input: PressureUnit orgUnit,代表一个压强单位类型，
  参数的正确输入范围是0-9（包括边界）
  Output: 无
  Return: 返回真或假
  Others: 无
*************************************************/

bool PressureTrans::IsSIStd( int orgUnit)
{
	if (orgUnit == PRESSURE_STD_UNIT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*************************************************
  Function: UnitClassToUnitString
  Description:返回输入参数所代表的单位级别
  所对应的单位级别字符串
  Calls:无
  Called By:   
  Table Accessed: 无
  Table Updated: 无
  Input: int UnitClass,代表一个单位级别，
  Output: 无
  Return: 对应的单位级别字符串
  Others: 无
*************************************************/

const StdString& PressureTrans::UnitClassToUnitString(int UnitClass)
{
	assert(UnitClass >= 0 && UnitClass <= PRESSURE_UNIT_NUM - 1);
	return PressureTrans::UnitStringArray[UnitClass];
}

/*************************************************
  Function: UnitStringToUnitClass
  Description:返回输入参数所代表的单位级别字符串
  所对应的单位级别
  Calls:无
  Called By:  Quantity(T data,const string currentunitstring) 
  Table Accessed: 无
  Table Updated: 无
  Input: const string UnitString,代表一个单位级别字符串，
  Output: 无
  Return: 对应的单位级别
  Others: 无
*************************************************/

int PressureTrans::UnitStringToUnitClass(const StdString& UnitString)
{
	for (int i = 0; i < PRESSURE_UNIT_NUM; i++)
	{
		if (UnitString.CompareNoCase( PressureTrans::UnitStringArray[i] ) == 0 )
		{
			return i;
		}
	}
	assert(0);
	return -1;
}

/****************************************************
UnitStringArray静态数组存放的是单位级别字符串。
****************************************************/

