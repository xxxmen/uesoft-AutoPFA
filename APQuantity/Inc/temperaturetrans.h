#ifndef _TEMPERATURETRANS_H
#define _TEMPERATURETRANS_H

#define SPECIAL 4294967295
//温度常用单位的个数
#define	TEMPERATURE_UNIT_NUM	4


#include <string>
#include "UnitString.h"
using namespace std;
#include "Quantity_share.h"


#define	TEMPERATURE_STD_UNIT	0//标记温度SI标准单位

//定义时间的单位
/*enum	TemperatureUnit
//{
	const int C = 0;//摄氏度(℃)（标准单位）
	const int F = 1;//华氏度(℉)
	const int R = 2;//兰氏① 度(oR)
	const int K	= 3;//开尔文(K)
//};
*/

class QUANTITY_API TemperatureTrans
{
	DECLARE_UNITSTRING( TemperatureTrans, TEMPERATURE_UNIT_NUM );
public:
	static const StdString& UnitClassToUnitString(int UnitClass);
	static int UnitStringToUnitClass( const StdString& );
	static bool	IsSIStd( int );
	static double TemperatureTransToStd( double, int );
	static double TemperatureTransFromStd( double,int );
	static double TransToStd( int );
	static double TransFromStd( int );
	static  int GetStdUnitIndex()
	{
		return TEMPERATURE_STD_UNIT;
	}

private:
	static	const StdString	UnitStringArray[TEMPERATURE_UNIT_NUM];
};

#endif

