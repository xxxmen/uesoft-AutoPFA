#include "StdAfx.h"
#include "AngleTrans.h"
#include "assert.h"

/*
SIStd：中文意义是“国际标准”
*/

/****************************************************
angleTransRatio静态数组存放的是角度物理量中所用到
的所有单位与标准单位之间的比例关系。
****************************************************/

double AngleTrans::angleTransRatio[ANGLE_UNIT_NUM]
					= {0.017453292,2.909/10000.0
					,4.848/1000000.0,1
					,6.283};

/****************************************************
UnitStringArray静态数组存放的是单位级别字符串。
****************************************************/

const StdString AngleTrans::UnitStringArray[ANGLE_UNIT_NUM]
					= {_T("deg"),_T("sec"),_T("min"),_T("rad")
					,_T("rotation")};

IMPLEMENT_UNITSTRING( AngleTrans );
/*************************************************
  Function: TransFromStd
  Description:返回输入参数所代表的单位与标准单位之间的比例关系
  Calls:无
  Called By:      
  Table Accessed: 无
  Table Updated: 无
  Input: int desUnit,代表一个角度单位类型，
  参数的正确输入范围是0-4（包括边界）
  Output: 无
  Return: 返回比例关系，一个double型数据
  Others: 无
*************************************************/

double AngleTrans::TransFromStd( int desUnit )
{
	if (desUnit >= 0 && desUnit <= ANGLE_UNIT_NUM - 1)
	{
		return 1.0/AngleTrans::angleTransRatio[desUnit];
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
  Input: int orgUnit,代表一个角度单位类型，
  参数的正确输入范围是0-4（包括边界）
  Output: 无
  Return: 返回比例关系，一个double型数据
  Others: 无
*************************************************/

double AngleTrans::TransToStd( int orgUnit )
{
	if (orgUnit >= 0 && orgUnit <= ANGLE_UNIT_NUM - 1)
	{
		return AngleTrans::angleTransRatio[orgUnit];
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
  Input: int orgUnit,代表一个角度单位类型，
  参数的正确输入范围是0-4（包括边界）
  Output: 无
  Return: 返回真或假
  Others: 无
*************************************************/

bool AngleTrans::IsSIStd( int orgUnit )
{
	if (orgUnit == ANGLE_STD_UNIT)
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

int AngleTrans::UnitStringToUnitClass(const StdString& UnitString)
{
	for (int i = 0;i < ANGLE_UNIT_NUM;i++)
	{
		if ( UnitString.CompareNoCase( AngleTrans::UnitStringArray[i] ) == 0 )
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

const StdString& AngleTrans::UnitClassToUnitString(int UnitClass)
{
	assert(UnitClass >= 0 && UnitClass <= ANGLE_UNIT_NUM - 1);
	return AngleTrans::UnitStringArray[UnitClass];
}
