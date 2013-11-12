/*************************************************
  Copyright (C), 2005-2006, UESOFT Co., Ltd.
  File name:      // PowerTrans
  Author:         // chenyong
  Date:           // 2006-8-1
  Description:    // 此程序文件完成的主要功能得到功率常用单位间转换率
                  // 主要供外部统一功率单位调用
                  // 
  Function List:  // 主要函数列表
    1. TransToStd(powerUnit) 将功率的些常用单位转换为SI制标准功率单位
	2. TransFromStd(powerUnit) 将SI制标准功率单位转换为功率的常用单位
	3. IsSIStd(powerUnit) 判断当前的功率单位是否是SI制标准单位
 *************************************************/

#include "StdAfx.h"
#include "PowerTrans.h"
#include <assert.h>

IMPLEMENT_UNITSTRING( PowerTrans );

bool PowerTrans::IsSIStd( int orgUnit)
{
	return (orgUnit == POWER_STD_UNIT)?true:false;
}

/*************************************************
  Function:       // TransToStd
  Description:    // 将常用功率单位转换为SI标准单位功率单位
  Input:          // 枚举型的常用单位名称
                  // powerUnit。
  Output:         // 
  Return:         // 返回功率当前单位到SI标准单位的转换率
				  //出错返回0
*************************************************/
double PowerTrans::TransToStd( int orgUnit)
{
	if (orgUnit < 0 || orgUnit >= POWER_UNIT_NUM)
	{
		assert(0);
		return 0.0;
	}
	else
	{
		return powerTransRatio[orgUnit];
	}
}

/*************************************************
  Function:       // TransFromStd
  Description:    // 将SI标准单位功率单位转换为常用功率单位
  Input:          // 枚举型的常用单位名称
                  // powerUnit。
  Output:         // 
  Return:         // 返回功率SI标准单位到当前单位的转换率
				  //出错返回0
*************************************************/
double PowerTrans::TransFromStd( int orgUnit)
{
	if (orgUnit < 0 || orgUnit >= POWER_UNIT_NUM)
	{
		assert(0);
		return 0.0;
	}
	else
	{
		return 1.0/powerTransRatio[orgUnit];
	}
}

//对应枚举型各功率单位到SI标准单位的转换率
double PowerTrans::powerTransRatio[POWER_UNIT_NUM] \
				= {	1.0, 1000, 735.5, 745.7, 9.807, 1.356, 4186, 1055
				};

const StdString	PowerTrans::UnitStringArray[POWER_UNIT_NUM]
					={"w","kw","ps","hp","kgfm/s","ibfft/s"
					,"kcal/s","btu"};

int PowerTrans::UnitStringToUnitClass(const StdString& UnitString)
{
	for (int i = 0;i < POWER_UNIT_NUM;i++)
	{
		if (UnitString.CompareNoCase( PowerTrans::UnitStringArray[i] ) == 0 )
		{
			return i;
		}
	}
	assert(0);
	return -1;
}

const StdString& PowerTrans::UnitClassToUnitString(int UnitClass)
{
	assert(UnitClass >= 0 && UnitClass <= POWER_UNIT_NUM - 1);
	return PowerTrans::UnitStringArray[UnitClass];
}
