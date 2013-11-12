/*************************************************
  Copyright (C), 1988-1999, UESOFT Co., Ltd.
  File name:      Result.h
  Author:         贺灏、陈勇
  Version:        1.0
  Date:           2006.8.9
  Description:    此头文件主要定义了一个模板类，该类接受一个
				  模板参数；参数T代表物理量的数值类型，该模板类
				  的存在是为了接受乘除运算的结果（带单位表示）。
  Others:         无
  Function List:  
    1. GetDimension():取得该物理量对应的单位向量。
	2. GetValue():取得该物理量的数值。
	3. IsSameDimensions():判断该物理量与另一物理量是否为同一种物理量
	4. operator * ():对两个物理量进行*操作。
	5. operator + ():对两个同种物理量进行+操作。
	6. operator - ():对两个同种物理量进行-操作。
	7. operator / ():对两个物理量进行/操作。
	8. SetDimension():设置单位向量。
	9. SetValue():设置物理量数值。
  History:        无
*************************************************/
#ifndef _RESULT_H
#define _RESULT_H

#include <assert.h>
#include "DimensionType.h"
#include "Quantity_share.h"

template<class T,class Dimensions,class DimensionsTrans_Type>
class Quantity;//提前声明

template<class T>
class /*QUANTITY_API*/ Result
{
	
public:	

	Result()
	{
		this->m_value = 0;
	}

	~Result()
	{
		
	}

	//得到值

	T GetValue() const
	{	
		return m_value;	
	}
	
	//设置值

	void SetValue(T m)
	{	
		m_value = m;
	}	

	//得到单位

	DimensionVector GetDimension() const
	{	
		return m_dVector;
	}
	//设置单位

	void SetDimension(DimensionVector d)
	{	
		m_dVector = d;
	}
	//判断单位是否相同
	
	template<class Dimensions,class DimensionsTrans_Type>
	bool IsSameDimensions(Quantity<T,Dimensions,DimensionsTrans_Type> &q) const
	{
		if ( this->GetDimension() == q.GetDimension())
		{
			return true;
		}
		else
		{
			assert(0);
			return false;
		}
	}

	//判断单位是否相同

	bool IsSameDimensions(Result<T> &q) const
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

	//重载+
	
	template<class Dimensions,class DimensionsTrans_Type>
	Quantity<T,Dimensions,DimensionsTrans_Type> operator+
	(Quantity<T,Dimensions,DimensionsTrans_Type> &y)
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

	//重载+
	
	Result<T> operator+(Result<T> &y)
	{
		Result<T> result;
		if (this->IsSameDimensions(y))
		{
			result.SetValue(this->GetValue() + y.GetValue());
			result.SetDimension(this->GetDimension());
		}
		else
		{
			assert(0);
		}
		
		return result;
	}

	//重载-

	template<class Dimensions,class DimensionsTrans_Type>
	Quantity<T,Dimensions,DimensionsTrans_Type>  operator-
	(Quantity<T,Dimensions,DimensionsTrans_Type> &y)
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

	//重载-
	
	Result<T>  operator-(Result<T> &y)
	{
		Result<T> result;
		if (this->IsSameDimensions(y))
		{
			result.SetValue(this->GetValue() - y.GetValue());
			result.SetDimension(this->GetDimension());
		}
		else
		{
			assert(0);
		}
		
		return result;
	}

	//重载*

	template<class Dimensions,class DimensionsTrans_Type>
	Result<T> operator*(Quantity<T,Dimensions,DimensionsTrans_Type> &y)
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

	//重载*
	
	Result<T> operator*(Result<T> &y)
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

	//重载/
	
	template<class Dimensions,class DimensionsTrans_Type>
	Result<T> operator/(Quantity<T,Dimensions,DimensionsTrans_Type> &y)
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

	//重载/
	
	Result<T> operator/(Result<T> &y)
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
private:

	T m_value;//数值
	DimensionVector m_dVector;//单位向量
};

#endif