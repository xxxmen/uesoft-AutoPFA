/*************************************************
  Copyright (C), 2005-2006, UESOFT Co., Ltd.
  File name:      // SpeedTrans
  Author:         // chenyong
  Date:           // 2006-8-1
  Description:    // 此程序文件完成的主要功能得到速度常用单位间转换率
                  // 主要供外部统一速度单位调用
                  // 
  Function List:  // 主要函数列表
    1. TransToStd(speedUnit) 将速度的些常用单位转换为SI制标准速度单位
	2. TransFromStd(speedUnit) 将SI制标准速度单位转换为速度的常用单位
	3. IsSIStd(speedUnit) 判断当前的速度单位是否是SI制标准单位
 *************************************************/

#include "StdAfx.h"
#include "SpeedTrans.h"
#include <assert.h>

IMPLEMENT_UNITSTRING( SpeedTrans );
bool SpeedTrans::IsSIStd( int orgUnit)
{
	return (orgUnit == SPEED_STD_UNIT)?true:false;
}

/*************************************************
  Function:       // TransToStd
  Description:    // 将常用速度单位转换为SI标准单位速度单位
  Input:          // 枚举型的常用单位名称
                  // speedUnit。
  Output:         // 
  Return:         // 返回速度当前单位到SI标准单位的转换率
				  //出错返回0
*************************************************/
double SpeedTrans::TransToStd( int orgUnit)
{
	if (orgUnit < 0 || orgUnit >= SPEED_UNIT_NUM)
	{
		assert(0);
		return 0.0;
	}
	else
	{
		return speedTransRatio[orgUnit];
	}
}

/*************************************************
  Function:       // TransFromStd
  Description:    // 将SI标准单位速度单位转换为常用速度单位
  Input:          // 枚举型的常用单位名称
                  // speedUnit。
  Output:         // 
  Return:         // 返回速度SI标准单位到当前单位的转换率
				  //出错返回0
*************************************************/
double SpeedTrans::TransFromStd( int orgUnit)
{
	if (orgUnit < 0 || orgUnit >= SPEED_UNIT_NUM)
	{
		assert(0);
		return 0.0;
	}
	else
	{
		return 1.0/speedTransRatio[orgUnit];
	}
}

int SpeedTrans::UnitStringToUnitClass(const StdString& UnitString)
{
	for (int i = 0; i < SPEED_UNIT_NUM; i++)
	{
		if (UnitString.CompareNoCase( SpeedTrans::UnitStringArray[i] ) == 0 )
		{
			return i;
		}
	}
	assert(0);
	return -1;
}

const StdString& SpeedTrans::UnitClassToUnitString(int UnitClass)
{
	assert(UnitClass >= 0 && UnitClass <= SPEED_UNIT_NUM - 1);
	return SpeedTrans::UnitStringArray[UnitClass];
}

//对应枚举型各速度单位到SI标准单位的转换率
double SpeedTrans::speedTransRatio[SPEED_UNIT_NUM] \
				= {			1/3.6, 1.0, 1/3600, 0.01
				};

const StdString SpeedTrans::UnitStringArray[SPEED_UNIT_NUM] \
				={	"km/h","m/s","m/h","cm/s"
				};