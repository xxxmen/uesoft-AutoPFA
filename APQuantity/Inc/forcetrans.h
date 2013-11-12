/*************************************************
	Copyright (C), 1988-2006, UESOFT Co., Ltd.
	File name:ForceTrans.h
	Author:贺灏(lobby)
	Version:1.0
	Date:2006.8.1
	Description:用来完成力物理量中不同单位与标准单位之间的转换，
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
#ifndef _FORCETRANS_H
#define _FORCETRANS_H
#include <string>
#include "UnitString.h"
using namespace std;
#include "Quantity_share.h"


#define	FORCE_UNIT_NUM	6
#define	FORCE_STD_UNIT	0

/*enum ForceUnit
//{
	const int N = 0;//牛顿(标准单位)
	const int gf = 1;//克力
	const int kgf = 2;//千克力
	const int lbf = 3;//磅力
	const int dyn = 4;//达因
//};
*/
class QUANTITY_API ForceTrans
{
	DECLARE_UNITSTRING( ForceTrans, FORCE_UNIT_NUM );
public:

	static const StdString& UnitClassToUnitString(int UnitClass);
	static int UnitStringToUnitClass(const StdString& UnitString);
	static	bool	IsSIStd( int );
	static	double	TransToStd( int );
	static	double	TransFromStd( int );
	static  int GetStdUnitIndex()
	{
		return FORCE_STD_UNIT;
	}
protected:
private:

	static	const StdString UnitStringArray[FORCE_UNIT_NUM];
	static	double	forceTransRatio[FORCE_UNIT_NUM];
};

#endif