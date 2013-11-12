//速度常用单位的个数

#ifndef _SPEEDTRANS_H
#define _SPEEDTRANS_H

#include <string>
#include "UnitString.h"
using namespace std;
#include "Quantity_share.h"

#define	SPEED_UNIT_NUM	4

#define	SPEED_STD_UNIT	1//标记速度的SI标准单位

//定义速度的单位
/*/enum	SpeedUnit
//{
	const int km_h = 0;	//km/h
	const int m_s = 1;//m/s（标准单位）
	const int m_h = 2;//m/h
	const int cm_s = 3;//cm/s
//};
*/
class QUANTITY_API SpeedTrans
{
	DECLARE_UNITSTRING( SpeedTrans, SPEED_UNIT_NUM );
public:
	static const StdString& UnitClassToUnitString(int UnitClass);
	static int UnitStringToUnitClass(const StdString&);
	static bool	IsSIStd( int );
	static double TransToStd( int );
	static double TransFromStd( int );
	static  int GetStdUnitIndex()
	{
		return SPEED_STD_UNIT;
	}
protected:

private:

	static	double speedTransRatio[SPEED_UNIT_NUM];
	static	const StdString	UnitStringArray[SPEED_UNIT_NUM];
};

#endif
