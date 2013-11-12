#ifndef PFAQHEADER_H
#define PFAQHEADER_H

#include <string>
#include <UTILITY>
#include <vector>
#include "Quantity_share.h"

#ifdef UNICODE
typedef std::wifstream Ueistream;
typedef std::wstring UeStdString;
#define UELPCSTR LPCWSTR
#else
typedef std::ifstream Ueistream;
typedef std::string UeStdString;
#define UELPCSTR LPCTSTR
#endif

#ifdef UNICODE
typedef std::wifstream Ueistream;
#else
typedef std::ifstream Ueistream;
#endif

using namespace std;
typedef vector< UeStdString > InputSet;
typedef vector< vector< UeStdString > > TypeStringSet;
typedef TypeStringSet SysSet;
typedef pair< double,double > RateAndDelta;//一个单位与另一个单位之间的比例
typedef pair< UeStdString,RateAndDelta > TransPair;//一个单位名称与其转换率组成的pair
typedef vector< TransPair > TransPairSetOfOneType;//一种单位的所有转换
typedef pair<UeStdString,pair< UeStdString,TransPairSetOfOneType > > QuantityType;//一种物理量,第一个UeStdString表示物理量名称（如：长度）
//第二个UeStdString表示默认单位（如：米）
typedef vector< QuantityType > QuantityTypeSet;//所有的物理量集合
typedef pair< UeStdString,QuantityTypeSet > Qsys;//一个单位制
typedef vector< Qsys > QSysSet;//所有的单位制集合
#endif