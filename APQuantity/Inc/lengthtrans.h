/*************************************************
	Copyright (C), 1988-2006, UESOFT Co., Ltd.
	File name:LengthTrans.h
	Author:贺灏(lobby)
	Version:1.0
	Date:2006.7.31
	Description:用来完成长度物理量中不同单位与标准单位之间的转换，
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
#ifndef _LENGTHTRANS_H
#define _LENGTHTRANS_H

#include <string>
#include "UnitString.h"
using namespace std;
#include "Quantity_share.h"

#define	LENGTH_UNIT_NUM	9
#define	LENGTH_STD_UNIT	3

/*enum LengthUnit
//{
	const int mm = 0;//毫米
	const int cm = 1;//厘米
	const int dm = 2;//分米
	const int m= 3;//米(标准单位)
	const int km =4;//千米
	const int in = 5;//英寸
	const int ft = 6;//英尺
	const int yd = 7;//码
	const int mile = 8;//英里
//};
*/

class QUANTITY_API LengthTrans
{
	DECLARE_UNITSTRING( LengthTrans, LENGTH_UNIT_NUM );
public:

	static int UnitStringToUnitClass(const StdString& UnitString);
	static const StdString& UnitClassToUnitString(int UnitClass);
	static	bool	IsSIStd( int );
	static	double	TransToStd( int );
	static	double	TransFromStd( int );
	static  int GetStdUnitIndex()
	{
		return LENGTH_STD_UNIT;
	}
protected:
private:
	
	static	double	lengthTransRatio[LENGTH_UNIT_NUM];
	static	const StdString	UnitStringArray[LENGTH_UNIT_NUM];
};

#endif