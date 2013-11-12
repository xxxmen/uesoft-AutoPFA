#ifndef _TIMETRANS_H
#define _TIMETRANS_H

#include <string>
#include "UnitString.h"
using namespace std;
#include "Quantity_share.h"

//时间常用单位的个数
#define	TIME_UNIT_NUM	3
#define	TIME_STD_UNIT	2//秒为SI标准单位

//定义时间的单位
/*enum	TimeUnit
//{
	const int h = 0;//小时
	const int m = 1;//分钟
	const int s = 2;//秒（标准单位）
//};
*/
class QUANTITY_API TimeTrans
{
	DECLARE_UNITSTRING( TimeTrans, TIME_UNIT_NUM );
public:
	static const StdString& UnitClassToUnitString( int UnitClass );
	static int UnitStringToUnitClass( const StdString& );
	static bool	IsSIStd( int );
	static double TransToStd( int );
	static double TransFromStd( int );
	static  int GetStdUnitIndex()
	{
		return TIME_STD_UNIT;
	}
protected:

private:

	static	double timeTransRatio[TIME_UNIT_NUM];
	static	const StdString	UnitStringArray[TIME_UNIT_NUM];
};

#endif
