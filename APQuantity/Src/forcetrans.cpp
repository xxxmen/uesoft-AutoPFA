#include "StdAfx.h"
#include "ForceTrans.h"
#include <assert.h>

/*
SIStd：中文意义是“国际标准”
*/

/****************************************************
forceTransRatio静态数组存放的是力物理量中所用到
的所有单位与标准单位之间的比例关系。
****************************************************/

double ForceTrans::forceTransRatio[FORCE_UNIT_NUM]
					= {1.0,9.807/1000.0,9.80665
					,4.448,1.0/100000.0,4.44822};

/****************************************************
UnitStringArray静态数组存放的是单位级别字符串。
****************************************************/

const StdString ForceTrans::UnitStringArray[FORCE_UNIT_NUM]
					={_T("N"),_T("gf"),_T("kgf"),_T("lbf"),_T("dyn"),_T("lb")};

IMPLEMENT_UNITSTRING( ForceTrans );
/*************************************************
  Function: TransFromStd
  Description:返回输入参数所代表的单位与标准单位之间的比例关系
  Calls:无
  Called By:      
  Table Accessed: 无
  Table Updated: 无
  Input: int desUnit,代表一个力单位类型，
  参数的正确输入范围是0-4（包括边界）
  Output: 无
  Return: 返回比例关系，一个double型数据
  Others: 无
*************************************************/

double ForceTrans::TransFromStd( int desUnit)
{
	//ASSERT(desUnit >= 0 && desUnit <= 8);
	if (desUnit >= 0 && desUnit <= FORCE_UNIT_NUM - 1)
	{
		return 1.0/ForceTrans::forceTransRatio[desUnit];
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
  Called By:      Quantity(T data,const int currentunit)
  Table Accessed: 无
  Table Updated: 无
  Input: int orgUnit,代表一个力度单位类型，
  参数的正确输入范围是0-4（包括边界）
  Output: 无
  Return: 返回比例关系，一个double型数据
  Others: 无
*************************************************/

double ForceTrans::TransToStd( int orgUnit)
{
	//ASSERT(orgUnit >= 0 && orgUnit <= 8);
	if (orgUnit >= 0 && orgUnit <= FORCE_UNIT_NUM - 1)
	{
		return ForceTrans::forceTransRatio[orgUnit];
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
  Called By:      
  Table Accessed: 无
  Table Updated: 无
  Input: int orgUnit,代表一个力单位类型，
  参数的正确输入范围是0-4（包括边界）
  Output: 无
  Return: 返回真或假
  Others: 无
*************************************************/

bool ForceTrans::IsSIStd( int orgUnit)
{
	if (orgUnit == FORCE_STD_UNIT)
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

const StdString& ForceTrans::UnitClassToUnitString(int UnitClass)
{
	assert(UnitClass >= 0 && UnitClass <= FORCE_UNIT_NUM - 1);
	return ForceTrans::UnitStringArray[UnitClass];
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

int ForceTrans::UnitStringToUnitClass(const StdString& UnitString)
{
	for (int i = 0; i < FORCE_UNIT_NUM; i++)
	{
		if (UnitString.CompareNoCase( ForceTrans::UnitStringArray[i] ) == 0 )
		{
			return i;
		}
	}
	assert(0);
	return -1;
}