#include "StdAfx.h"
#include "VolumnTrans.h"
#include <assert.h>
/*
SIStd：中文意// 义是“国际标准”
*/

/****************************************************
volumnTransRatio静态数组存放的是体积物理量中所用到
的所有单位与标准单位之间的比例关系。
****************************************************/

double VolumnTrans::volumnTransRatio[VOLUMN_UNIT_NUM]
					= {1.0,1.0/100000.0
					,1.0/1000.0,3.785/1000.0
					,4.546/1000.0,0.02832,1.639/100000.0};

/****************************************************
UnitStringArray静态数组存放的是单位级别字符串。
****************************************************/

const StdString VolumnTrans::UnitStringArray[VOLUMN_UNIT_NUM]
					={	"m_3",_T("cm_3"),_T("litre"),_T("gallon_a"),
					_T("gallon_e"),_T("ft_3"),_T("in_3")};

IMPLEMENT_UNITSTRING( VolumnTrans );
/*************************************************
  Function: TransFromStd
  Description:返回输入参数所代表的单位与标准单位之间的比例关系
  Calls:无
  Called By:      
  Table Accessed: 无
  Table Updated: 无
  Input: int desUnit,代表一个体积单位类型，
  参数的正确输入范围是0-6（包括边界）
  Output: 无
  Return: 返回比例关系，一个double型数据
  Others: 无
*************************************************/

double VolumnTrans::TransFromStd( int desUnit)
{
	//ASSERT(desUnit >= 0 && desUnit <= 8);
	if (desUnit >= 0 && desUnit <= VOLUMN_UNIT_NUM -1)
	{
		return 1.0/VolumnTrans::volumnTransRatio[desUnit];
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
  Called By:   Quantity(T data,const int currentunit)
  Table Accessed: 无
  Table Updated: 无
  Input: int orgUnit,代表一个体积单位类型，
  参数的正确输入范围是0-6（包括边界）
  Output: 无
  Return: 返回比例关系，一个double型数据
  Others: 无
*************************************************/

double VolumnTrans::TransToStd( int orgUnit)
{
	if (orgUnit >= 0 && orgUnit <= VOLUMN_UNIT_NUM -1)
	{
		return VolumnTrans::volumnTransRatio[orgUnit];
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
  Input: int orgUnit,代表一个体积单位类型，
  参数的正确输入范围是0-6（包括边界）
  Output: 无
  Return: 返回真或假
  Others: 无
*************************************************/

bool VolumnTrans::IsSIStd( int orgUnit)
{
	if (orgUnit == VOLUMN_STD_UNIT)
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

int VolumnTrans::UnitStringToUnitClass(const StdString& UnitString)
{
	for (int i = 0; i < VOLUMN_UNIT_NUM; i++)
	{
		if (UnitString.CompareNoCase( VolumnTrans::UnitStringArray[i] ) == 0 )
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

const StdString& VolumnTrans::UnitClassToUnitString(int UnitClass)
{
	assert(UnitClass >= 0 && UnitClass <= VOLUMN_STD_UNIT - 1);
	return VolumnTrans::UnitStringArray[UnitClass];
}