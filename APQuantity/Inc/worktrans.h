#ifndef _WORKTRANS_H
#define _WORKTRANS_H

#include <string>
#include "UnitString.h"
using namespace std;
#include "Quantity_share.h"

//热功常用单位的个数
#define	WORK_UNIT_NUM	7

#define	WORK_STD_UNIT	0 //J为热功SI标准单位

//定义热功的单位
/*enum	WorkUnit
//{
	const int j = 0;//焦耳（标准单位）
	const int kcal = 1;	//千卡
	const int kgfm = 2;	//千克力.米
	const int kwh = 3;	//千瓦小时
	const int hph = 4;	//公制马力小时
	const int ftlbf = 5;	//英尺磅力
	const int btuw = 6;	//英热单位
//};
*/
class QUANTITY_API WorkTrans
{
	DECLARE_UNITSTRING( WorkTrans, WORK_UNIT_NUM );
public:
	static const StdString& UnitClassToUnitString(int UnitClass);
	static int UnitStringToUnitClass(const StdString&);
	static bool	IsSIStd( int );
	static double TransToStd( int );
	static double TransFromStd( int );
	static  int GetStdUnitIndex()
	{
		return WORK_STD_UNIT;
	}
protected:

private:

	static	double workTransRatio[WORK_UNIT_NUM];
	static	const StdString UnitStringArray[WORK_UNIT_NUM];
};

#endif