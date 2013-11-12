/*************************************************
  Copyright (C), 1988-1999, UESOFT Co., Ltd.
  File name:      Quantity.h
  Author:         贺灏、陈勇
  Version:        1.0
  Date:           2006.8.9
  Description:    此头文件主要定义了一个模板类，该类接受三个
				  模板参数；参数T代表物理量的数值类型，T的取值范围
				  是int,long,float,double等；模板参数Dimensions
				  用来限定该物理量的类型，可以是力，速度，质量等等；
				  模板参数DimensionsTrans_Type是该物理量对应的单位转换类
				  该模板类为单位模块与其他模块的接口，主要实现物理量
				  带单位的四则运算。
  Others:         无
  Function List:  
    1. GetDimension():取得该物理量对应的单位向量。
	2. GetPrecision():取得在进行比较相等时用到的精度值。
	3. GetValue():取得该物理量的数值。
	4. IsSameDimensions():判断该物理量与另一物理量是否为同一种物理量
	5. operator !=():判断两个同种物理量是否不相等。
	6. operator * ():对两个物理量进行*操作。
	7. operator + ():对两个同种物理量进行+操作。
	8. operator - ():对两个同种物理量进行-操作。
	9. operator / ():对两个物理量进行/操作。
	10.operator = ():在两个同种物理量中进行赋值。
	11.operator ==():判断两个同种物理量是否相等。
	12.Quantity():构造函数
	13.~Quantity():析构函数
	14.SetDimension():设置单位向量。
	15.SetPrecision():设置比较精度值。
	16.SetValue():设置物理量数值。
  History:        无
*************************************************/

#ifndef _QUANTITY_H
#define _QUANTITY_H


#include <cmath>
#include <assert.h>
#include <string>

#include "UnitHead.h"
#include "Result.h"
using namespace std;
#include "Quantity_share.h"

template<class T>
class Result;//提前声明

//定义物理量模板，包括单位
template <class T,class Dimensions,class DimensionsTrans_Type>
class Quantity
{
public:
	static double precision;

public:
	static const UnitStringSet& UnitString() {
		return DimensionsTrans_Type::UnitString();
	}
private:
	T m_value;//这个数值永远是该物理量在标准单位下的数值
	int m_currentunit;//使用者可以认为该物理量在此单位级别下

	static Dimensions m_dimension;
	double m_precision;

	bool SetQuantity(const T &data, int currentunit)
	{
		bool IsTemp = this->GetDimension().IsTemprature();
		if (IsTemp)
		{
			this->m_value = TemperatureTrans::TemperatureTransToStd(data,currentunit);
		}
		else
		{
			double ratio = DimensionsTrans_Type::TransToStd(currentunit);
			this->m_value = ratio * data;
		}
		return true;
	}

public:
	StdString GetCurrentUnit() const
	{
		return DimensionsTrans_Type::UnitClassToUnitString( m_currentunit );
	}
	
	void SetCurrentUnit( const StdString& strCurrentUnit )
	{
		m_currentunit = DimensionsTrans_Type::UnitStringToUnitClass( strCurrentUnit );
	}

	void SetCurrentUnit( int nCurrentUnit )
	{
		m_currentunit = nCurrentUnit;
	}
	explicit Quantity(double dprecision = Quantity::precision)
	{	
		m_currentunit = DimensionsTrans_Type::GetStdUnitIndex();
		m_precision = dprecision;
		m_value = (T)(0);
	}

	Quantity( const Quantity& quantity )
	{
		*this = quantity;
	}
/*************************************************
  Function:       Quantity(const T &data, int currentunit)
  Description:    构造物理量对象，并将非标准单位级别中数值转换为
				  对应的标准单位级别中数值。
  Calls:          
	1.GetDimension()
	2.TemperatureTransToStd()
	3.TransToStd()
  Called By:      外部其他模块
  Input:          
	1.data:物理量在currentunit单位级别上的数值
	2.currentunit:单位级别，currentunit的取值范围
	在0到该物理量单位级别数-1之间（包括边界值）
  Output:         在内存中参数物理量对象
  Return:         无
  Others:         无
*************************************************/

	Quantity(const T &data, int currentunit,double dprecision = Quantity::precision)
	{
		m_currentunit = currentunit;
		m_precision = dprecision;
		SetQuantity(data,currentunit);
	}

/*************************************************
  Function:       Quantity(const T &data, const string currentunitstring)
  Description:    构造物理量对象，并将非标准单位级别数值转换为
				  对应的标准单位级别中数值。
  Calls:          
	1.UnitStringToUnitClass()
	2.Quantity(data,currentunit)
  Called By:      外部其他模块
  Input:          
	1.data:物理量在currentunitstring单位级别上的数值
	2.currentunitstring:单位级别，该参数必须为预先的
	定义好字符串（用来代表一个单位级别，如mm：毫米）
  Output:         在内存中参数物理量对象
  Return:         无
  Others:         无
*************************************************/
	Quantity(const T &data, const StdString& currentunitstring,double dprecision = Quantity::precision)
	{
		int currentunit = DimensionsTrans_Type::UnitStringToUnitClass(currentunitstring);
		m_currentunit = currentunit;
		SetQuantity(data,currentunit);
		m_precision = dprecision;
	}


	//获得非标准单位级别下物理量数值
	T GetValue( const StdString& currentunitstring ) const
	{
		int currentunit = DimensionsTrans_Type::UnitStringToUnitClass( currentunitstring );
		bool IsTemp = this->GetDimension().IsTemprature();
		if (IsTemp)
		{
			return TemperatureTrans::TemperatureTransFromStd( this->m_value,currentunit );
		}
		else
		{
			double ratio = DimensionsTrans_Type::TransFromStd( currentunit );
			return ratio * this->m_value;
		}
	}

	T GetValue( int currentunit ) const
	{
		bool IsTemp = this->GetDimension().IsTemprature();
		if (IsTemp)
		{
			return TemperatureTrans::TemperatureTransFromStd( this->m_value,currentunit );
		}
		else
		{
			double ratio = DimensionsTrans_Type::TransFromStd( currentunit );
			return ratio * this->m_value;
		}
	}

	T GetValueOfCurrentUnit() const//得到当前单位级别下的数值
	{
		return GetValue( m_currentunit );
	}
	//获得单位向量

	DimensionVector GetDimension() const
	{	
		return m_dimension.GetDimension();
	}

	//获得标准单位级别下物理量数值

	T GetValue() const
	{	
		return m_value;
	}
private:
	//设置单位向量
	void SetDimension(const DimensionVector& d)
	{	
		m_dimension.SetDimension(d);
	}
	
	//设置标准单位级别下数值

	void SetValue(T data)
	{	
		m_value = data;	
	}

	//得到精度值
public:

	double GetPrecision() const
	{
		return m_precision;
	}
	
	//设置精度值

	void SetPrecision(double pre)
	{
		m_precision = pre;
	}

	//判断单位是否相同

	bool IsSameDimensions( const Result<T> &q) const
	{
		if (this->GetDimension() == q.GetDimension())
		{
			return true;
		}
		else
		{
			assert(0);
			return false;
		}
	}
	//重载加法运算符
	
	Quantity<T,Dimensions,DimensionsTrans_Type> operator+
		( const Quantity<T,Dimensions,DimensionsTrans_Type> &y) const
	{
		Quantity<T,Dimensions,DimensionsTrans_Type> result;
		result.SetValue(this->GetValue() + y.GetValue());
		return result;
	}

	//重载加法运算符
	
	Quantity<T,Dimensions,DimensionsTrans_Type> operator+
		( const Result<T> &y) const
	{
		Quantity<T,Dimensions,DimensionsTrans_Type> result;
		if (this->IsSameDimensions(y))
		{
			result.SetValue(this->GetValue() + y.GetValue());
		}
		else
		{
			assert(0);	
		}
		return result;
	}

	//重载减法运算符
	
	Quantity<T,Dimensions,DimensionsTrans_Type> operator-
		( const Quantity<T,Dimensions,DimensionsTrans_Type> &y) const
	{
		Quantity<T,Dimensions,DimensionsTrans_Type> result;
		result.SetValue(this->GetValue() - y.GetValue());
		return result;
	}
	
	Quantity<T,Dimensions,DimensionsTrans_Type> operator-
		( const Result<T> &y) const
	{
		Quantity<T,Dimensions,DimensionsTrans_Type> result;
		if (this->IsSameDimensions(y))
		{
			result.SetValue(this->GetValue() - y.GetValue());
		}
		else
		{
			assert(0);
		}	
		return result;
	}
	
	//重载乘法运算符

	template<class Dimensions1,class DimensionsTrans_Type1>
	Result<T> operator*( const Quantity<T,Dimensions1,DimensionsTrans_Type1> &y) const
	{
		Result<T> result;
		DimensionVector dVector;

		//设置值
		
		result.SetValue(this->GetValue()*y.GetValue());
		
		//设置单位

		dVector = this->GetDimension() + y.GetDimension();		
		result.SetDimension(dVector);
		
		return result;
	}

	//重载乘法运算符
	
	Result<T> operator*( const Result<T> &y) const
	{
		Result<T> result;
		DimensionVector dVector;
		//设置值
		result.SetValue(this->GetValue()*y.GetValue());
		
		//设置单位
		dVector = this->GetDimension() + y.GetDimension();
		
		result.SetDimension(dVector);
		
		return result;
	}

	//重载除法运算符

	template<class Dimensions1,class DimensionsTrans_Type1>
	Result<T> operator/( const Quantity<T,Dimensions1,DimensionsTrans_Type1> &y) const
	{
		Result<T> result;
		DimensionVector dVector;

		//设置值

		result.SetValue(this->GetValue()/y.GetValue());
		
		//设置单位

		dVector = this->GetDimension() - y.GetDimension();
		result.SetDimension(dVector);
		
		return result;
	}

	Result<T> operator/( const Result<T> &y) const
	{
		Result<T> result;
		DimensionVector dVector;

		//设置值

		result.SetValue(this->GetValue()/y.GetValue());
		
		//设置单位

		dVector = this->GetDimension() - y.GetDimension();
		result.SetDimension(dVector);
		
		return result;
	}

	//重载相等
	
	bool operator==(const Quantity<T,Dimensions,DimensionsTrans_Type> &q) const
	{
		if (fabs(this->GetValue() - q.GetValue()) 
			 <= this->GetPrecision())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//重载相等
	
	bool operator==(const Result<T> &r) const
	{
		if (this->GetDimension() == r.GetDimension())
		{
			if (fabs(this->GetValue() - r.GetValue()) 
				<= this->GetPrecision())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			assert(0);
			return false;
		}
	}

	//重载不等
	
	bool operator != (const Result<T> &r) const
	{
		if (this->GetDimension() == r.GetDimension())
		{
			if (fabs(this->GetValue() - r.GetValue()) 
				> this->GetPrecision())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			assert(0);
			return false;
		}
	}

	//重载不等
	
	bool operator!=( const Quantity<T,Dimensions,DimensionsTrans_Type> &q) const
	{
		if (fabs(this->GetValue()-q.GetValue()) 
			> this->GetPrecision())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//重载赋值

	const Quantity<T,Dimensions,DimensionsTrans_Type>& operator = (const Result<T>& x)
	{
		if (this->IsSameDimensions(x))
		{
			this->SetValue(x.GetValue());
			this->m_currentunit = DimensionsTrans_Type::GetStdUnitIndex();
		}
		else
		{
			assert(0);
		}

		return *this;
	}

	const Quantity& operator=( const Quantity& quantity )
	{
		if ( this == &quantity )
		{
			return *this;
		}
		
		m_value = quantity.m_value;
		m_precision = quantity.m_precision;
		m_currentunit = quantity.m_currentunit;

		return *this;
	}
};

//初始化精度值

template <class T,class Dimensions,class DimensionsTrans_Type>
double Quantity<T,Dimensions,DimensionsTrans_Type>::precision = 1.0e-4;

template <class T,class Dimensions,class DimensionsTrans_Type>
Dimensions Quantity<T,Dimensions,DimensionsTrans_Type>::m_dimension;
#endif
