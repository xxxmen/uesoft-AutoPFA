/*************************************************
  Copyright (C), 2005-2006, UESOFT Co., Ltd.
  File name:      // DensityTrans
  Author:         // chenyong
  Date:           // 2006-8-1
  Description:    // 此程序文件完成的主要功能得到密度常用单位间转换率
                  // 主要供外部统一密度单位调用
                  // 
  Function List:  // 主要函数列表
    1. TransToStd(densityUnit) 将密度的些常用单位转换为SI制标准密度单位
	2. TransFromStd(densityUnit) 将SI制标准密度单位转换为密度的常用单位
	3. IsSIStd(densityUnit) 判断当前的密度单位是否是SI制标准单位
 *************************************************/

#include "StdAfx.h"
#include "DensityTrans.h"
#include <assert.h>

bool DensityTrans::IsSIStd( int orgUnit )
{
	return (orgUnit == DENSITY_STD_UNIT)?true:false;
}

/*************************************************
  Function:       // TransToStd
  Description:    // 将常用密度单位转换为SI标准单位密度单位
  Input:          // 枚举型的常用单位名称
                  // densityUnit。
  Output:         // 
  Return:         // 返回密度当前单位到SI标准单位的转换率
				  //出错返回0
*************************************************/
double DensityTrans::TransToStd( int orgUnit)
{
	if (orgUnit < 0 || orgUnit >= DENSITY_UNIT_NUM)
	{
		assert(0);
		return 0.0;
	}
	else
	{
		return densityTransRatio[orgUnit];
	}
}

/*************************************************
  Function:       // TransFromStd
  Description:    // 将SI标准单位密度单位转换为常用密度单位
  Input:          // 枚举型的常用单位名称
                  // densityUnit。
  Output:         // 
  Return:         // 返回密度SI标准单位到当前单位的转换率
				  //出错返回0
*************************************************/
double DensityTrans::TransFromStd( int orgUnit)
{
	if (orgUnit < 0 || orgUnit >= DENSITY_UNIT_NUM)
	{
		assert(0);
		return 0.0;
	}
	else
	{
		return 1.0/densityTransRatio[orgUnit];
	}
}

int DensityTrans::UnitStringToUnitClass(const StdString& UnitString)
{
	for (int i = 0; i < DENSITY_UNIT_NUM; i++)
	{
		if (UnitString.CompareNoCase( DensityTrans::UnitStringArray[i] ) == 0 )
		{
			return i;
		}
	}
	assert(0);
	return -1;
}

const StdString& DensityTrans::UnitClassToUnitString(int UnitClass)
{
	assert(UnitClass >= 0 && UnitClass <= DENSITY_UNIT_NUM - 1);
	return DensityTrans::UnitStringArray[UnitClass];
}

//对应枚举型各密度单位到SI标准单位的转换率
double DensityTrans::densityTransRatio[DENSITY_UNIT_NUM] \
				= {		1000, 1.0, 16.02, 119.8,1E+6,27679.899
				};

const StdString DensityTrans::UnitStringArray[DENSITY_UNIT_NUM] \
				={	"g/cm_3","kg/m_3","lb/ft_3","lb/USgal","kg/cu.cm","lb/cu.in"
				};

IMPLEMENT_UNITSTRING( DensityTrans );