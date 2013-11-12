/*************************************************
  Copyright (C), 2005-2006, UESOFT Co., Ltd.
  File name:      // WorkTrans
  Author:         // chenyong
  Date:           // 2006-8-1
  Description:    // 此程序文件完成的主要功能得到热功常用单位间转换率
                  // 主要供外部统一热功单位调用
                  // 
  Function List:  // 主要函数列表
    1. TransToStd(workUnit) 将热功的些常用单位转换为SI制标准热功单位
	2. TransFromStd(workUnit) 将SI制标准热功单位转换为热功的常用单位
	3. IsSIStd(workUnit) 判断当前的热功单位是否是SI制标准单位
 *************************************************/

#include "StdAfx.h"
#include "WorkTrans.h"
#include <assert.h>

IMPLEMENT_UNITSTRING( WorkTrans );
bool WorkTrans::IsSIStd( int orgUnit)
{
	return (orgUnit == WORK_STD_UNIT)?true:false;
}

/*************************************************
  Function:       // TransToStd
  Description:    // 将常用热功单位转换为SI标准单位热功单位J
  Input:          // 枚举型的常用单位名称
                  // workUnit。
  Output:         // 
  Return:         // 返回热功当前单位到SI标准单位的转换率
				  //出错返回0
*************************************************/
double WorkTrans::TransToStd( int orgUnit)
{
	if (orgUnit < 0 || orgUnit >= WORK_UNIT_NUM)
	{
		assert(0);
		return 0.0;
	}
	else
	{
		return workTransRatio[orgUnit];
	}
}

/*************************************************
  Function:       // TransFromStd
  Description:    // 将SI标准单位热功单位J转换为常用热功单位
  Input:          // 枚举型的常用单位名称
                  // workUnit。
  Output:         // 
  Return:         // 返回热功SI标准单位到当前单位的转换率
				  //出错返回0
*************************************************/
double WorkTrans::TransFromStd( int orgUnit)
{
	if (orgUnit < 0 || orgUnit >= WORK_UNIT_NUM)
	{
		assert(0);
		return 0.0;
	}
	else
	{	
		return 1.0/workTransRatio[orgUnit];
	}
}

int WorkTrans::UnitStringToUnitClass(const StdString& UnitString)
{
	for (int i = 0; i < WORK_UNIT_NUM; i++)
	{
		if ( UnitString.CompareNoCase( WorkTrans::UnitStringArray[i] ) == 0 )
		{
			return i;
		}
	}
	assert(0);
	return -1;
}

const StdString& WorkTrans::UnitClassToUnitString(int UnitClass)
{
	assert(UnitClass >= 0 && UnitClass <= WORK_UNIT_NUM - 1);
	return WorkTrans::UnitStringArray[UnitClass];
}

//对应枚举型各热功单位到SI标准单位的转换率
double WorkTrans::workTransRatio[WORK_UNIT_NUM] \
				= {	1.0,
					4186.75,
					9.80665,
					3600000,
					2648000,
					1.35582,
					1055.06
				};

const StdString WorkTrans::UnitStringArray[WORK_UNIT_NUM] \
				={	"j","kcal","kgfm","kwh","hph","ftlbf","btuw"
				};
