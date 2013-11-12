/*************************************************
	Copyright (C), 1988-2006, UESOFT Co., Ltd.
	File name:VolumnTrans.h
	Author:贺灏(lobby)
	Version:1.0
	Date:2006.7.31
	Description:用来完成体积物理量中不同单位与标准单位之间的转换，
				它提供给其他模块使用的是一个比例因子，反应某单位
				与标准单之间的数量关系。
	Function List:  
    1. TransToStd
	接受一个int型变量作为参数，
	返回该单位与标准单位之间的比例系数。
	2. TransFromStd
	接受一个int型变量作为参数，
	返回标准单位与该单位之间的比例系数。
	3.IsSIStd
	接受一个int型变量作为参数，
	返回布尔值，代表是否该单位是标准单位
	4.UnitClassToUnitString
	接受一个int型变量作为参数,
	返回该单位级别对应的单位字符串
	5.UnitStringToUnitClass
	接受一个string型变量作为参数,
	返回该单位字符串对应的单位级别
*************************************************/
#ifndef _VOLUMNTRANS_H
#define _VOLUMNTRANS_H

#include <string>
#include "UnitString.h"
using namespace std;
#include "Quantity_share.h"

#define	VOLUMN_UNIT_NUM	7
#define	VOLUMN_STD_UNIT	0

/*enum VolumnUnit
//{
	const int m3 = 0;//立方米（标准单位）
	const int cm3 = 1;//立方厘米
	const int litre = 2;//升（立方分米）
	const int gallon_a = 3;//美制加仑
	const int gallon_e = 4;//英制加仑
	const int ft3 = 5;//立方英尺
	const int in3 = 6;//立方英寸
//};
*/
class QUANTITY_API VolumnTrans
{
	DECLARE_UNITSTRING( VolumnTrans, VOLUMN_UNIT_NUM );
public:

	static const StdString& UnitClassToUnitString(int UnitClass);
	static int UnitStringToUnitClass( const StdString& );
	static	bool	IsSIStd( int );
	static	double	TransToStd( int );
	static	double	TransFromStd( int );
	static  int GetStdUnitIndex()
	{
		return VOLUMN_STD_UNIT;
	}
protected:
private:

	static	double	volumnTransRatio[VOLUMN_UNIT_NUM];
	static	const StdString	UnitStringArray[VOLUMN_UNIT_NUM];
};

#endif