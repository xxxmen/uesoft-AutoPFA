#ifndef _POWERTRANS_H
#define _POWERTRANS_H

#include <string>
#include "UnitString.h"
using namespace std;
#include "Quantity_share.h"

//功率常用单位的个数
#define	POWER_UNIT_NUM	8

#define	POWER_STD_UNIT	0//标记功率的SI标准单位

//定义功率的单位
/*
	const int w = 0;//瓦（标准单位）
	const int kw = 1;//千瓦
	const int ps = 2;//马力
	const int hp = 3;//英马力
	const int kgfm_s = 4;//千克力/秒
	const int ibfft_s = 5;//英尺磅力/秒
	const int kcal_s = 6;//千卡/秒
	const int btu = 7;//英热单位/秒
*/

class QUANTITY_API PowerTrans
{
	DECLARE_UNITSTRING( PowerTrans, POWER_UNIT_NUM );
public:
	static const StdString& UnitClassToUnitString(int UnitClass);
	static int UnitStringToUnitClass(const StdString& UnitString);
	static bool	IsSIStd( int );
	static double TransToStd( int );
	static double TransFromStd( int );
	static  int GetStdUnitIndex()
	{
		return POWER_STD_UNIT;
	}
protected:

private:
	static const StdString UnitStringArray[POWER_UNIT_NUM];

	static double powerTransRatio[POWER_UNIT_NUM];
};

#endif
