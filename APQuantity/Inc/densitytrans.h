#ifndef _DENSITYTRANS_H
#define _DENSITYTRANS_H

#include <string>
#include "UnitString.h"
using namespace std;
#include "Quantity_share.h"

//密度常用单位的个数
#define	DENSITY_UNIT_NUM	6

#define	DENSITY_STD_UNIT	1//标记密度SI标准单位

//定义密度的单位
/*enum	DensityUnit
//{
	const int g_cm3 = 0;	//克每立方厘米
	const int kg_m3 = 1;	//千克每立方米（标准单位）
	const int lb_ft3 = 2;	//磅/英尺3
	const int lb_USgal =3;//磅/美加仑
//};
*/
class QUANTITY_API DensityTrans
{
	DECLARE_UNITSTRING( DensityTrans, DENSITY_UNIT_NUM );
public:
	
	static const StdString& UnitClassToUnitString(int UnitClass);
	static int UnitStringToUnitClass(const StdString&);
	static bool	IsSIStd( int );
	static double TransToStd( int );
	static double TransFromStd( int );
	static  int GetStdUnitIndex()
	{
		return DENSITY_STD_UNIT;
	}
protected:

private:

	static	double densityTransRatio[DENSITY_UNIT_NUM];
	static	const StdString	UnitStringArray[DENSITY_UNIT_NUM];

};

#endif
