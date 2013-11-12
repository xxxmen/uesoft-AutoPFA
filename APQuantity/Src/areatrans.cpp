#include "StdAfx.h"
#include "AreaTrans.h"
#include <assert.h>

/*
SIStd：中文意义是“国际标准”
*/

/****************************************************
areaTransRatio静态数组存放的是面积物理量中所用到
的所有单位与标准单位之间的比例关系。
****************************************************/

double AreaTrans::areaTransRatio[AREA_UNIT_NUM]
					= {1.0,0.01
					,1.0/10000.0,0.0929
					,0.8361274,6.452/10000.0,1.0/1000000};

/****************************************************
UnitStringArray静态数组存放的是单位级别字符串。
****************************************************/

const StdString AreaTrans::UnitStringArray[AREA_UNIT_NUM]
					= {_T("m_2"),_T("dm_2"),_T("cm_2"),_T("ft_2")
					,_T("yd_2"),_T("in_2"),_T("mm_2")};

IMPLEMENT_UNITSTRING( AreaTrans );
/*************************************************
  Function: TransFromStd
  Description:返回输入参数所代表的单位与标准单位之间的比例关系
  Calls:无
  Called By:      
  Table Accessed: 无
  Table Updated: 无
  Input: int desUnit,代表一个面积单位类型，
  参数的正确输入范围是0-5（包括边界）
  Output: 无
  Return: 返回比例关系，一个double型数据
  Others: 无
*************************************************/

double AreaTrans::TransFromStd( int desUnit)
{
	//ASSERT(desUnit >= 0 && desUnit <= 8);
	if (desUnit >= 0 && desUnit <= AREA_UNIT_NUM - 1)
	{
		return 1.0/AreaTrans::areaTransRatio[desUnit];
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
  Called By:      Quantity(T data,const string currentunitstring)
  Table Accessed: 无
  Table Updated: 无
  Input: int orgUnit,代表一个面积单位类型，
  参数的正确输入范围是0-5（包括边界）
  Output: 无
  Return: 返回比例关系，一个double型数据
  Others: 无
*************************************************/

double AreaTrans::TransToStd( int orgUnit)
{
	//ASSERT(orgUnit >= 0 && orgUnit <= 8);
	if (orgUnit >= 0 && orgUnit <= AREA_UNIT_NUM - 1)
	{
		return AreaTrans::areaTransRatio[orgUnit];
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
  Input: int orgUnit,代表一个面积单位类型，
  参数的正确输入范围是0-5（包括边界）
  Output: 无
  Return: 返回真或假
  Others: 无
*************************************************/

bool AreaTrans::IsSIStd( int orgUnit)
{
	if (orgUnit == AREA_STD_UNIT)
	{
		return true;
	}
	else
	{
		return false;
	}
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

int AreaTrans::UnitStringToUnitClass(const StdString& UnitString)
{
	for (int i = 0;i < AREA_UNIT_NUM;i++)
	{
		if ( UnitString.CompareNoCase( AreaTrans::UnitStringArray[i] ) == 0 )
		{
			return i;
		}
	}
	assert(0);
	return -1;
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

const StdString& AreaTrans::UnitClassToUnitString(int UnitClass)
{
	assert(UnitClass >= 0 && UnitClass <= AREA_UNIT_NUM - 1);
	return AreaTrans::UnitStringArray[UnitClass];
}

