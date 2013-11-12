/*************************************************
  Copyright (C), 1988-1999, UESOFT Co., Ltd.
  File name:      dimensiontype.h
  Author:         贺灏、陈勇
  Version:        1.0
  Date:           2006.8.9
  Description:    此头文件定义了一个模板类，和一个普通类。
				  普通类的存在完全是为了实现后面的Result类。
				  模板类代表单位向量，模板参数的不同代表不同
				  的单位。
  Others:         无
  DimensionVector Function List:
	1. IsTemprature():判断是否为单位物理量
	2. operator+():实现单位向量相加
	3. operator-():实现单位向量相减
	4. operator!=():判断亮两个单位向量是否相同
	5. operator==():判断亮两个单位向量是否不相
  DimensionType<> Function List:
	1. GetDimension():得到单位向量值
	2. SetDimension():设置单位向量值
  History:        无
*************************************************/
#ifndef _DIMENSIONTYPE_H
#define _DIMENSIONTYPE_H

//该结构体表示各单位（为了实现Result<T>）

class DimensionVector
{
public:
	
	int mass;
	int length;
	int time;
	int current;
	int temprature;
	int angle;
	int mol;
public:

	bool IsTemprature() const
	{
		if ((this->angle == 0) & (this->current == 0)
			& (this->length == 0) & (this->mass == 0)
			& (this->mol == 0) & (this->time == 0)
			& (this->temprature == 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//重载加法运算，对单位的各量纲进行相加

	DimensionVector operator+(DimensionVector dVector)
	{
		DimensionVector dVecRet;
		dVecRet.mass = this->mass + dVector.mass;
		dVecRet.length = this->length + dVector.length;
		dVecRet.time = this->time + dVector.time;
		dVecRet.current = this->current + dVector.current;
		dVecRet.temprature = this->temprature + dVector.temprature;
		dVecRet.angle = this->angle + dVector.angle;
		dVecRet.mol = this->mol + dVector.mol;
	
		return dVecRet;
	}

	//重载减法运算，对单位的各量纲进行相减

	DimensionVector operator-(DimensionVector dVector)
	{
		DimensionVector dVecRet;
		dVecRet.mass = this->mass - dVector.mass;
		dVecRet.length = this->length - dVector.length;
		dVecRet.time = this->time - dVector.time;
		dVecRet.current = this->current - dVector.current;
		dVecRet.temprature = this->temprature - dVector.temprature;
		dVecRet.angle = this->angle - dVector.angle;
		dVecRet.mol = this->mol - dVector.mol;
	
		return dVecRet;
	}
	//重载!=判断单位的量纲式是否为不等
	
	bool operator != (DimensionVector dVector) const
	{
		if ((this->mass != dVector.mass)
			|| (this->length != dVector.length)
			|| (this->angle != dVector.angle)
			|| (this->temprature != dVector.temprature)
			|| (this->time != dVector.time)
			|| (this->mol != dVector.mol)
			|| (this->current != dVector.current)
			)
		{
			return true;  //是不相等的
		}
		else
		{
			return false; //是相等的
		}
	}

	//重载==判断单位的量纲式是否为相等
	
	bool operator == (DimensionVector dVector) const
	{
		if ((this->mass == dVector.mass)
			&& (this->length == dVector.length)
			&& (this->angle == dVector.angle)
			&& (this->temprature == dVector.temprature)
			&& (this->time == dVector.time)
			&& (this->mol == dVector.mol)
			&& (this->current == dVector.current)
			)
		{
			return true;  //是相等的
		}
		else
		{
			return false; //不是相等的
		}
	}
} ;


//定义单位模板

template <int mass, int length,int time
					,int current,int temprature
					,int angle,int mol>
					
class DimensionType
{
public:

    DimensionType()
	{
		m_dVector.mass = mass;
		m_dVector.length = length;
		m_dVector.time = time;
		m_dVector.current = current;
		m_dVector.temprature = temprature;
		m_dVector.angle = angle;
		m_dVector.mol = mol;
	}

	DimensionVector GetDimension() const
	{
		return m_dVector;
	}
	void SetDimension(DimensionVector d)
	{
		m_dVector = d;
	}
private:
	DimensionVector m_dVector;
};



#endif
