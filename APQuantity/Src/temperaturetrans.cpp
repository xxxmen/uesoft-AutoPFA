/*************************************************
  Copyright (C), 2005-2006, UESOFT Co., Ltd.
  File name:      // DensityTrans
  Author:         // chenyong
  Date:           // 2006-8-1
  Description:    // 此程序文件完成的主要功能将各单位下的温度与标准温度相互转换
                  // 主要供外部统一温度单位调用
                  // 
  Function List:  // 主要函数列表
    1. TransToStd(const double, const temperatureUnit) 将温度的常用单位下的值转换为SI制标准温度单位对应值
	2. TransFromStd(const double, const temperatureUnit) 将SI制标准温度单位下的值转换为温度的常用单位对应值
	3. IsSIStd(const temperatureUnit) 判断当前的温度单位是否是SI制标准单位开尔文
 *************************************************/

#include "StdAfx.h"
#include "TemperatureTrans.h"
#include <assert.h>

IMPLEMENT_UNITSTRING( TemperatureTrans );
bool TemperatureTrans::IsSIStd( int orgUnit)
{
	return (orgUnit == TEMPERATURE_STD_UNIT)?true:false;
}

/*************************************************
  Function:       // TransToStd
  Description:    // 将常用温度单位对应值转换为SI标准单位下对应的值
  Input:          
		double orgvalue 当前单位下的值
		temperatureUnit orgUnit 当前单位
  Output:         // 
  Return:         // 返回对应开尔文单位下的值
*************************************************/
double TemperatureTrans::TemperatureTransToStd( double orgvalue,int orgUnit)
{
	switch (orgUnit)
	{
	case 0:
		//将摄氏度转换为摄氏度,并返回转换后的值
		//return orgvalue + 273.15;
		return orgvalue;
	case 1:
		//将华氏度转换为摄氏度,并返回转换后的值
		//return 5.0 / 9 * (orgvalue + 459.67);
		return ( orgvalue - 32 ) / 1.8;
	case 2:
		//将兰氏① 度转换为摄氏度,并返回转换后的值
		//return 5.0 / 9 * orgvalue;
		return ( orgvalue - 491.67 ) / 1.8;
	case 3:
		//将开尔文转换为摄氏度,并返回转换后的值
		return orgvalue - 273.15;
	default:
		assert(0);
		return SPECIAL;
	}
}


/*************************************************
  Function:       // TransToStd
  Description:    // 将SI标准单位下对应的值转换为常用温度单位对应值
  Input:          
		double orgvalue IS单位下的值
		temperatureUnit orgUnit 转换的对应单位
  Output:         // 
  Return:         // 返回对应转换后单位下的值
*************************************************/
double TemperatureTrans::TemperatureTransFromStd(double orgvalue,int orgUnit)
{
	switch (orgUnit)
	{
	case 0:
		//return orgvalue - 273.15;
		return orgvalue;
	case 1:
		//将摄氏度转换为华氏度,并返回转换后的值
		//return 9.0 / 5 * orgvalue - 459.67;
		return 1.8 * orgvalue + 32;
	case 2:
		//将摄氏度转换为兰氏① 度,并返回转换后的值
		//return 9 / 5.0 * orgvalue;
		return 1.8 * orgvalue + 491.67;
	case 3:
		//将转换为开尔文,并返回转换后的值
		return orgvalue + 273.15;
	default:
		assert(0);
		return SPECIAL;
	}
}

double TemperatureTrans::TransFromStd( int orgUnit)
{
	assert(0);
	return 0;
}

double TemperatureTrans::TransToStd( int orgUnit)
{
	assert(0);
	return 0;
}

int TemperatureTrans::UnitStringToUnitClass(const StdString& UnitString)
{
	for (int i = 0; i < TEMPERATURE_UNIT_NUM; i++)
	{
		if (UnitString.CompareNoCase( TemperatureTrans::UnitStringArray[i] ) == 0 )
		{
			return i;
		}
	}
	assert(0);
	return -1;
}

const StdString& TemperatureTrans::UnitClassToUnitString(int UnitClass)
{
	assert(UnitClass >= 0 && UnitClass <= TEMPERATURE_UNIT_NUM - 1);
	return TemperatureTrans::UnitStringArray[UnitClass];
}

const StdString TemperatureTrans::UnitStringArray[TEMPERATURE_UNIT_NUM]
			={	"C","F","R","K"
			};
