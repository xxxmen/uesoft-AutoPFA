/*************************************************
	Copyright (C), 1988-2006, UESOFT Co., Ltd.
	File name:PressureTrans.h
	Author:贺灏(lobby)
	Version:1.0
	Date:2006.7.31
	Description:用来完成压强物理量中不同单位与标准单位之间的转换，
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
#ifndef _PRESSURETRANS_H
#define _PRESSURETRANS_H
#include <string>
#include "UnitString.h"
#include "Quantity_share.h"
using namespace std;


#define	PRESSURE_UNIT_NUM	14
#define	PRESSURE_STD_UNIT	0

/*enum PressureUnit
//{
	const int Pa = 0;//帕斯卡(标准单位)
	const int KPa = 1;//千帕斯卡
	const int MPa = 2;//兆帕斯卡
	const int kgf_m = 3;//千克力/米2（由于标识符无法写成kgf/m2形式，
	//所以将“/”改为“_”2次方改为2，kgf_cm与此相同）
	const int kgf_cm = 4;//千克力/厘米2
	const int bar = 5;//巴
	const int atm = 6;//标准大气压
	const int mmH2o = 7;//毫米水柱
	const int mmHg = 8;//毫米水银柱
	const int psi = 9;//磅/英寸2（lb/in2）
//};
*/

class QUANTITY_API PressureTrans
{
	DECLARE_UNITSTRING( PressureTrans, PRESSURE_UNIT_NUM );
public:
	static int UnitStringToUnitClass(const StdString& UnitString);
	static const StdString& UnitClassToUnitString(int UnitClass);
	static	bool	IsSIStd( int );
	static	double	TransToStd( int );
	static	double	TransFromStd( int );
	static  int GetStdUnitIndex()
	{
		return PRESSURE_STD_UNIT;
	}
protected:
private:
	static const StdString UnitStringArray[PRESSURE_UNIT_NUM];
	static	double	pressureTransRatio[PRESSURE_UNIT_NUM];
};

#endif