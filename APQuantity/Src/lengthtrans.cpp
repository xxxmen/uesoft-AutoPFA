#include "StdAfx.h"
#include "LengthTrans.h"
#include <assert.h>

/*
SIStd：中文意义是“国际标准”
*/

/****************************************************
lengthTransRatio静态数组存放的是长度物理量中所用到
的所有单位与标准单位之间的比例关系。
****************************************************/

double LengthTrans::lengthTransRatio[LENGTH_UNIT_NUM]
					= {0.001,0.01,0.1,1,1000,0.0254
					,0.3048,0.9144,1609.344};

/****************************************************
UnitStringArray静态数组存放的是单位级别字符串。
****************************************************/

const StdString	LengthTrans::UnitStringArray[LENGTH_UNIT_NUM]
					={_T("mm"),_T("cm"),_T("dm"),_T("m"),_T("km"),_T("in")
					,_T("ft"),_T("yd"),_T("mile")};

IMPLEMENT_UNITSTRING( LengthTrans );
/*************************************************
  Function: TransFromStd
  Description:返回输入参数所代表的单位与标准单位之间的比例关系
  Calls:无
  Called By:      // 调用本函数的函数清单
  Table Accessed: 无
  Table Updated: 无
  Input: LengthUnit desUnit,代表一个长度单位类型，
  参数的正确输入范围是0-8（包括边界）
  Output: 无
  Return: 返回比例关系，一个double型数据
  Others: 无
*************************************************/

double LengthTrans::TransFromStd( int desUnit)
{
	//ASSERT(desUnit >= 0 && desUnit <= 8);
	if (desUnit >= 0 && desUnit <= LENGTH_UNIT_NUM - 1)
	{
		return 1.0/LengthTrans::lengthTransRatio[desUnit];
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
  Input: LengthUnit orgUnit,代表一个长度单位类型，
  参数的正确输入范围是0-8（包括边界）
  Output: 无
  Return: 返回比例关系，一个double型数据
  Others: 无
*************************************************/

double LengthTrans::TransToStd( int orgUnit)
{
	//ASSERT(orgUnit >= 0 && orgUnit <= 8);
	if (orgUnit >= 0 && orgUnit <= LENGTH_UNIT_NUM - 1)
	{
		return LengthTrans::lengthTransRatio[orgUnit];
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
  Input: LengthUnit orgUnit,代表一个长度单位类型，
  参数的正确输入范围是0-8（包括边界）
  Output: 无
  Return: 返回真或假
  Others: 无
*************************************************/

bool LengthTrans::IsSIStd( int orgUnit)
{
	if (orgUnit == LENGTH_STD_UNIT)
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

const StdString& LengthTrans::UnitClassToUnitString(int UnitClass)
{
	assert(UnitClass >= 0 && UnitClass <= LENGTH_UNIT_NUM - 1);
	return LengthTrans::UnitStringArray[UnitClass];
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

int LengthTrans::UnitStringToUnitClass(const StdString& UnitString)
{
	for (int i = 0;i < LENGTH_UNIT_NUM;i++)
	{
		if (UnitString.CompareNoCase( LengthTrans::UnitStringArray[i] ) == 0 )
		{
			return i;
		}
	}
	assert(0);
	return -1;
}
