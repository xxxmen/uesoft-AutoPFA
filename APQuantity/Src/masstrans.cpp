/*************************************************
  Copyright (C), 2005-2006, UESOFT Co., Ltd.
  File name:      // MassTrans
  Author:         // chenyong
  Date:           // 2006-8-1
  Description:    // 此程序文件完成的主要功能得到质量常用单位间转换率
                  // 主要供外部统一质量单位调用
                  // 
  Function List:  // 主要函数列表
    1. TransToStd(massUnit) 将质量的些常用单位转换为SI制标准质量单位
	2. TransFromStd(massUnit) 将SI制标准质量单位转换为质量的常用单位
	3. IsSIStd(massUnit) 判断当前的质量单位是否是SI制标准单位
 *************************************************/

#include "StdAfx.h"
#include "MassTrans.h"
#include <assert.h>

bool MassTrans::IsSIStd( int orgUnit)
{
	return (orgUnit == MASS_STD_UNIT)?true:false;
}

/*************************************************
  Function:       // TransToStd
  Description:    // 将常用质量单位转换为SI标准单位质量单位
  Input:          // 枚举型的常用单位名称
                  // massUnit。
  Output:         // 
  Return:         // 返回质量当前单位到SI标准单位的转换率
				  //出错返回0
*************************************************/
double MassTrans::TransToStd( int orgUnit)
{
	if (orgUnit < 0 || orgUnit >= MASS_UNIT_NUM)
	{
		assert(0);
		return 0.0;
	}
	else
	{
		return massTransRatio[orgUnit];
	}
}

/*************************************************
  Function:       // TransFromStd
  Description:    // 将SI标准单位质量单位转换为常用质量单位
  Input:          // 枚举型的常用单位名称
                  // massUnit。
  Output:         // 
  Return:         // 返回质量SI标准单位到当前单位的转换率
				  //出错返回0
*************************************************/
double MassTrans::TransFromStd( int orgUnit)
{
	if (orgUnit < 0 || orgUnit >= MASS_UNIT_NUM)
	{
		assert(0);
		return 0.0;
	}
	else
	{
		return 1.0/massTransRatio[orgUnit];
	}
}

//对应枚举型各质量单位到SI标准单位的转换率
double MassTrans::massTransRatio[MASS_UNIT_NUM] \
					= {	1000.0, 907.1847, 1.0, 0.001, 0.454,0.10204
					};

const StdString MassTrans::UnitStringArray[MASS_UNIT_NUM]
					={"t","at","kg","g","lb","N"};

IMPLEMENT_UNITSTRING( MassTrans );
const StdString& MassTrans::UnitClassToUnitString(int UnitClass)
{
	assert(UnitClass >= 0 && UnitClass <= MASS_UNIT_NUM - 1);
	return MassTrans::UnitStringArray[UnitClass];
}

int MassTrans::UnitStringToUnitClass(const StdString& UnitString)
{
	for (int i = 0;i < MASS_UNIT_NUM;i++)
	{
		if (UnitString.CompareNoCase( MassTrans::UnitStringArray[i] ) == 0 )
		{
			return i;
		}
	}
	assert(0);
	return -1;
}
