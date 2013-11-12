/*************************************************
  Copyright (C), 1988-1999, UESOFT Co., Ltd.
  File name:      Unit.h
  Author:         陈勇，贺灏
Version:          1.0
Date:             2006.8.10
  Description:    这个头文件中主要定义了一些供外部其他模块调用的
                  物理量（数据类型）
  Function List:  无
    1. ....
  History:        无 
*************************************************/

#ifndef _UNIT_H
#define _UNIT_H

#include "quantity.h"

//定义常用单位

typedef DimensionType<0,0,0,0,0,1,0> AngleDimension;
typedef DimensionType<0,2,0,0,0,0,0> AreaDimension;
typedef DimensionType<1,-3,0,0,0,0,0> DensityDimension;
typedef DimensionType<1,1,-2,0,0,0,0> ForceDimension;
typedef DimensionType<0,1,0,0,0,0,0> LengthDimension;
typedef DimensionType<1,0,0,0,0,0,0> MassDimension;
typedef DimensionType<1,2,-3,0,0,0,0> PowerDimension;
typedef DimensionType<1,-1,-2,0,0,0,0> PressureDimension;
typedef DimensionType<0,1,-1,0,0,0,0> SpeedDimension;
typedef DimensionType<0,0,0,0,1,0,0> TemperatureDimension;
typedef DimensionType<0,0,1,0,0,0,0> TimeDimension;
typedef DimensionType<0,3,0,0,0,0,0> VolumnDimension;
typedef DimensionType<1,2,-2,0,0,0,0> WorkDimension;
typedef DimensionType<1,1,-1,0,0,0,0> MomentumDimension;
typedef DimensionType<0,0,0,0,-1,0,0> ExpansionCoefDimension;
typedef DimensionType<1,0,-2,0,0,0,0> RigidityDimension;
typedef DimensionType<1,2,-2,0,0,-1,0> RSFDimension;


//定义常用物理量
typedef Quantity<double,AngleDimension,AngleTrans> AngleUnit;//角度
typedef AngleUnit AngleDisplaceUnit;//角度偏移量

typedef Quantity<double,AreaDimension,AreaTrans> AreaUnit;//面积

typedef Quantity<double,DensityDimension,DensityTrans> DensityUnit;//密度
typedef DensityUnit InsulationDensityUnit;//保温层密度
typedef DensityUnit FluidDensityUnit;//流体密度
typedef DensityUnit PipeDensityUnit;//管道密度

typedef Quantity<double,ForceDimension,ForceTrans> ForceUnit;//力

typedef Quantity<double,LengthDimension,LengthTrans> LengthUnit;//长度
typedef LengthUnit ThicknessUnit;//壁厚
typedef LengthUnit DiameterUnit;//直径
typedef LengthUnit CLenUnit;//合成长成？？
typedef LengthUnit EleUnit;//标高
typedef LengthUnit LineDisplaceUnit;//线位移

typedef Quantity<double,MassDimension,MassTrans> MassUnit;//质量
typedef MassUnit WeightUnit;//重量

typedef Quantity<double,PowerDimension,PowerTrans> PowerUnit;//功率
typedef Quantity<double,PressureDimension,PressureTrans> PressureUnit;//压强
typedef PressureUnit WindForceUnit;//风荷载
typedef PressureUnit StressUnit;//应力
typedef PressureUnit PreUnit;//压力单位比例
typedef PressureUnit EModulusUnit;//弹性模量单位比例

typedef Quantity<double,SpeedDimension,SpeedTrans> SpeedUnit;//速度
typedef Quantity<double,TemperatureDimension,TemperatureTrans> TemperatureUnit;//温度
typedef Quantity<double,TimeDimension,TimeTrans> TimeUnit;//时间
typedef Quantity<double,VolumnDimension,VolumnTrans> VolumnUnit;//体积
typedef Quantity<double,WorkDimension,WorkTrans> WorkUnit;//功


typedef Quantity<double,MomentumDimension,MomentTrans> MomentUnit;
typedef MomentUnit OutMomentUnit;//输出力矩

typedef Quantity<double,ExpansionCoefDimension,ExpansionCoefTrans> ExpansionCoefUnit;//线膨胀系数

typedef Quantity<double,RigidityDimension,RigidityTrans> TSFUnit;//平动刚量
typedef TSFUnit AverageForceUnit;//均匀载荷

typedef Quantity<double,RSFDimension,RSFTrans> RSFUnit;//转动刚量








//非常见单位

typedef DimensionType<0,1,-2,0,0,0,0> AccelerationDimension;
typedef DimensionType<0,0,-1,0,0,1,0> RadSpeedDimension;
typedef DimensionType<0,0,-1,0,0,0,0> FrequencyDimension;
typedef DimensionType<0,0,0,1,0,0,0> CurrentDimension;
typedef DimensionType<0,0,0,0,0,0,1> MolDimension;
typedef DimensionType<0,2,-2,0,-1,0,0> SpecificHeatDimension;//比热容
typedef DimensionType<1,0,0,0,0,0,-1> MolMassDimension;		//摩尔质量
typedef DimensionType<0,3,0,0,0,0,-1> MolVolumnDimension;		//摩尔体积
#endif