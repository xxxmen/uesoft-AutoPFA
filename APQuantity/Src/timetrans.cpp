/*************************************************
  Copyright (C), 2005-2006, UESOFT Co., Ltd.
  File name:      // TimeTrans
  Author:         // cy、hh
  Date:           // 2006-7-31
  Description:    // 此程序文件完成的主要功能得到时间常用单位间转换的进制
                  // 值，主要供外部统一时间调用
                  // 
  Function List:  // 主要函数列表，每条记录应包括函数名及功能简要说明
    1. TransToStd(time) 将时间的些常用单位转换为SI制标准时间单位
	2. TransFromStd(time) 将SI制标准时间单位转换为时间的些常用单位
	3. IsSIStd(time) 判断当前单位是否为国际标准单位
 *************************************************/

#include "StdAfx.h"
#include "TimeTrans.h"
#include <assert.h>

IMPLEMENT_UNITSTRING( TimeTrans );
bool TimeTrans::IsSIStd( int orgUnit)
{
	return (orgUnit == TIME_STD_UNIT)?true:false;
}

/*************************************************
  Function:       // TransToStd
  Description:    // 将常用时间单位转换为SI标准单位S
  Input:          // 枚举型的常用单位名称
                  // timeUnit = m..。
  Output:         // 
  Return:         // 返回当前单位到SI标准单位的转换率
				  //出错返回0
*************************************************/
double TimeTrans::TransToStd( int orgUnit)
{
	if (orgUnit < 0 || orgUnit >= TIME_UNIT_NUM)
	{
		assert(0);
		return 0.0;
	}
	else
	{
		return timeTransRatio[orgUnit];
	}
}

/*************************************************
  Function:       // TransFromStd
  Description:    // 将SI标准单位S转换为常用时间单位
  Input:          // 枚举型的常用单位名称
                  // timeUnit = m..。
  Output:         // 
  Return:         // 返回SI标准单位到当前单位的转换率
				  //出错返回0
*************************************************/
double TimeTrans::TransFromStd( int orgUnit)
{
	if (orgUnit < 0 || orgUnit >= TIME_UNIT_NUM)
	{
		assert(0);
		return 0.0;
	}
	else
	{
		return 1.0/timeTransRatio[orgUnit];
	}
}

int TimeTrans::UnitStringToUnitClass(const StdString& UnitString)
{
	for (int i = 0; i < TIME_UNIT_NUM; i++)
	{
		if (UnitString.CompareNoCase( TimeTrans::UnitStringArray[i] ) == 0 )
		{
			return i;
		}
	}
	assert(0);
	return -1;
}

const StdString& TimeTrans::UnitClassToUnitString(int UnitClass)
{
	assert(UnitClass >= 0 && UnitClass <= TIME_UNIT_NUM - 1);
	return TimeTrans::UnitStringArray[UnitClass];
}

//对应枚举型各单位到SI标准单位S的转换率
double TimeTrans::timeTransRatio[TIME_UNIT_NUM] \
				= {			3600,		   60,			1
				};

const StdString TimeTrans::UnitStringArray[TIME_UNIT_NUM] \
				={"h","m","s"			
				};
