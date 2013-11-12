// SysProperty.h: interface for the SysProperty class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYSPROPERTY_H__44BF292B_B610_45E9_A0F7_8DECBB8AA0C3__INCLUDED_)
#define AFX_SYSPROPERTY_H__44BF292B_B610_45E9_A0F7_8DECBB8AA0C3__INCLUDED_
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：SysProperty.h
  摘要： 系统流体属性和环境条件  
  author  : LSP          
*/
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS PropertyPersistent  
{
public:
	CString Name();
	void Name(CString strValue);
	StrArray<2>& Density();
	void Density(const StrArray<2>& strValue);
	StrArray<2>& Viscos();
	void Viscos(const StrArray<2>& strValue);
	StrArray<2>& Modulus();
	void Modulus(const StrArray<2>& strValue);
	StrArray<2>& VaporPress();
	void VaporPress(const StrArray<2>& strValue);
	StrArray<2>& Temperature();
	void Temperature(const StrArray<2>& strValue);
	CString Gravity();
	void Gravity(CString strValue);
	void ReTransLam(CString strValue);
	CString ReTransLam();
	void ReTransTurb(CString strValue);
	CString ReTransTurb();
	StrArray<2>& AtmosphericPress();
	void AtmosphericPress(const StrArray<2>& strValue);
	StrArray<2>& AtmosphericTemp();
	void AtmosphericTemp(const StrArray<2>& strValue);
	PropertyPersistent();
	virtual ~PropertyPersistent();

private:
	CString  m_strName;
	StrArray<2>  m_strDensity;
	StrArray<2>  m_strViscos;
	StrArray<2>  m_strModulus;
	StrArray<2>  m_strVaporPress;
	StrArray<2>  m_strTemperature;
	CString      m_strGravity;
	CString      m_strReTransLam;
	CString      m_strReTransTurb;
	StrArray<2>  m_strAtmosphericPress;
	StrArray<2>  ms_strAtmosphericTemp;
};
/*------------------------------------------*/
inline CString PropertyPersistent::Name()
{
	return m_strName;
}
inline void PropertyPersistent::Name(CString strValue)
{
	m_strName = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& PropertyPersistent::Density()
{
	return m_strDensity;
}
inline void PropertyPersistent::Density(const StrArray<2>& strValue)
{
	m_strDensity = strValue;
}
/*------------------------------------------*/

inline StrArray<2>& PropertyPersistent::Viscos()
{
	return m_strViscos;
}
inline void PropertyPersistent::Viscos(const StrArray<2>& strValue)
{
	m_strViscos = strValue;
}
/*------------------------------------------*/
inline StrArray<2>& PropertyPersistent::Modulus()
{
	return m_strModulus;
}
inline void PropertyPersistent::Modulus(const StrArray<2>& strValue)
{
	m_strModulus = strValue;
}
/*------------------------------------------*/

inline StrArray<2>& PropertyPersistent::VaporPress()
{
	return m_strVaporPress;
}
inline void PropertyPersistent::VaporPress(const StrArray<2>& strValue)
{
	m_strVaporPress = strValue;
}
/*------------------------------------------*/

inline StrArray<2>& PropertyPersistent::Temperature()
{
	return m_strTemperature;
}
inline void PropertyPersistent::Temperature(const StrArray<2>& strValue)
{
	m_strTemperature = strValue;
}
/*------------------------------------------*/

inline CString PropertyPersistent::Gravity()
{
	return m_strGravity;
}
inline void PropertyPersistent::Gravity(CString strValue)
{
	m_strGravity = strValue;
}
/*------------------------------------------*/

inline CString PropertyPersistent::ReTransLam()
{
	return m_strReTransLam;
}
inline void PropertyPersistent::ReTransLam(CString strValue)
{
	m_strReTransLam = strValue;
}
/*------------------------------------------*/

inline CString PropertyPersistent::ReTransTurb()
{
	return m_strReTransTurb;
}
inline void PropertyPersistent::ReTransTurb(CString strValue)
{
	m_strReTransTurb = strValue;
}
/*------------------------------------------*/

inline StrArray<2>& PropertyPersistent::AtmosphericPress()
{
	return m_strAtmosphericPress;
}
inline void PropertyPersistent::AtmosphericPress(const StrArray<2>& strValue)
{
	m_strAtmosphericPress = strValue;
}
/*------------------------------------------*/

inline StrArray<2>& PropertyPersistent::AtmosphericTemp()
{
	return ms_strAtmosphericTemp;
}
inline void PropertyPersistent::AtmosphericTemp(const StrArray<2>& strValue)
{
	ms_strAtmosphericTemp = strValue;
}
#endif // !defined(AFX_SYSPROPERTY_H__44BF292B_B610_45E9_A0F7_8DECBB8AA0C3__INCLUDED_)
