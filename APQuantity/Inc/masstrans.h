#ifndef _MASSTRANS_H
#define _MASSTRANS_H
#include <string>
#include "UnitString.h"
using namespace std;
#include "Quantity_share.h"

//质量常用单位的个数
#define	MASS_UNIT_NUM	6

#define	MASS_STD_UNIT	2//千克为质量SI标准单位

//定义质量的单位

/*const int t = 0;//吨
const int at = 1;//美吨
const int kg = 2;//千克（标准单位）
const int g = 3;//克
const int lb = 4;//磅	
*/	

class QUANTITY_API MassTrans
{
	DECLARE_UNITSTRING( MassTrans, MASS_UNIT_NUM );
public:
	static int UnitStringToUnitClass(const StdString& UnitString);
	static const StdString& UnitClassToUnitString(int UnitClass);
	static bool	IsSIStd( int );
	static double TransToStd( int );
	static double TransFromStd( int );
	static  int GetStdUnitIndex()
	{
		return MASS_STD_UNIT;
	}
protected:

private:
	static const StdString UnitStringArray[MASS_UNIT_NUM];

	static double massTransRatio[MASS_UNIT_NUM];
};

#endif
