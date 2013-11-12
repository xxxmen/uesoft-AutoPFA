// PipePerisist.h: interface for the PipePerisist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIPEPERISIST_H__7FD1C2FB_5E01_4411_B34B_114AB3365892__INCLUDED_)
#define AFX_PIPEPERISIST_H__7FD1C2FB_5E01_4411_B34B_114AB3365892__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PipeIDList.h"

class AFX_EXT_CLASS PipePerisist  
{
public:
	void Name(CString strValue);
	void EndPtX(CString strValue);
	void StartPtX(CString strValue);
	void EndPtY(CString strValue);
	void StartPtY(CString strValue);
	void InJunID(CString strValue);
	void OutJunID(CString strValue);
	void InDia(CString strValue);
	void InDiaUnit(CString strValue);
	void Len(CString strValue);
	void LenUnit(CString strValue);
	void WaveSpeed(CString strValue);
	void WaveSpeedUnit(CString strValue);
	void B(CString strValue);
	void Material(CString strValue);
	void Size(CString strValue);
	void PipeType(CString strValue);
	void Thick(CString strValue);
	void ThickUnit(CString strValue);
	void Elasticity(CString strValue);
	void ElasticityUnit(CString strValue);
	void PossionRatio(CString strValue);
	void InDiaReduce(CString strValue);
	void CalcWave(CString strValue);
	void C1(CString strValue);
	void SupportType(CString strValue);
	void FrictionModel(CString strValue);
	void Friction(CString strValue);
	void FrictionUnit(CString strValue);
	void LocalK(CString strValue);
	void PipeFactor(CString strValue);
	void FitFactor(CString strValue);
	void InitFlow(const StrArray<3>& strValue);
	void SectionNum(CString strValue);
	void ParaNum(CString strValue);
	void PartFull(CString strValue);

	CString PartFull();
	CString LocalK();
	CString PipeFactor();
	CString FitFactor();
	StrArray<3>& InitFlow();
	CString SectionNum();
	CString ParaNum();
	CString Material();
	CString Size();
	CString PipeType();
	CString Thick();
	CString ThickUnit();
	CString Elasticity();
	CString ElasticityUnit();
	CString PossionRatio();
	CString InDiaReduce();
	CString CalcWave();
	CString C1();
	CString SupportType();
	CString FrictionModel();
	CString Friction();
	CString FrictionUnit();
	CString InDia();
	CString InDiaUnit();
	CString Len();
	CString LenUnit();
	CString WaveSpeed();
	CString WaveSpeedUnit();
	CString B();
	CString InJunID();
	CString OutJunID();
	CString Name();
	CString EndPtX();
	CString StartPtX();
	CString EndPtY();
	CString StartPtY();
	int Key();
	void Key(int iKey);
	PipePerisist();
	virtual ~PipePerisist();

private:
	int m_iKey;
	CString m_strName;
	CString m_strStartX;
	CString m_strStartY;
	CString m_strEndX;
	CString m_strEndY;
	CString m_strInJunID;
	CString m_strOutJunID;
	CString m_strInDia;
	CString m_strInDiaUnit;
	CString m_strLen;
	CString m_strLenUnit;
	CString m_strWaveSpeed;
	CString m_strWaveSpeedUnit;
	CString m_strB;
	CString m_strMaterial;
	CString m_strSize;
	CString m_strType;
	CString m_strThick;
	CString m_strThickUnit;
	CString m_strElasticity;
	CString m_strElasticityUnit;
	CString m_strPossionRatio;
	CString m_strInDiaReduce;
	CString m_strCalcwave;
	CString m_strC1;
	CString m_strSupportType;
	CString m_strFrictionModel;
	CString m_strFriction;
	CString m_strFrictionUnit;
	CString m_strLocalK;	
	CString m_strPipeFactor;	
	CString m_strFitFactor;
    StrArray<3> m_InitFlow;
	CString m_strSectionNum;	
	CString m_strParaNum;
	CString m_strPartFull;
};
/*------------------------------------------*/
inline void PipePerisist::Key(int iKey)
{
	m_iKey = iKey;
}
inline int PipePerisist::Key()
{
	return m_iKey;
}
/*------------------------------------------*/
inline CString PipePerisist::Name()
{
	return m_strName;
}
inline void PipePerisist::Name(CString strValue)
{
	m_strName = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::StartPtX()
{
	return m_strStartX;
}
inline void PipePerisist::StartPtX(CString strValue)
{
	m_strStartX = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::EndPtX()
{
	return m_strEndX;
}
inline void PipePerisist::EndPtX(CString strValue)
{
	m_strEndX = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::StartPtY()
{
	return m_strStartY;
}
inline void PipePerisist::StartPtY(CString strValue)
{
	m_strStartY = strValue;
}
/*------------------------------------------*/

inline CString PipePerisist::EndPtY()
{
	return m_strEndY;
}
inline void PipePerisist::EndPtY(CString strValue)
{
	m_strEndY = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::InJunID()
{
	return m_strInJunID;
}
inline void PipePerisist::InJunID(CString strValue)
{
	m_strInJunID = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::OutJunID()
{
	return m_strOutJunID;
}
inline void PipePerisist::OutJunID(CString strValue)
{
	m_strOutJunID = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::InDia()
{
	return m_strInDia;
}
inline void PipePerisist::InDia(CString strValue)
{
	m_strInDia = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::InDiaUnit()
{
	return m_strInDiaUnit;
}
inline void PipePerisist::InDiaUnit(CString strValue)
{
	m_strInDiaUnit = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::Len()
{
	return m_strLen;
}
inline void PipePerisist::Len(CString strValue)
{
	m_strLen = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::LenUnit()
{
	return m_strLenUnit;
}
inline void PipePerisist::LenUnit(CString strValue)
{
	m_strLenUnit = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::WaveSpeed()
{
	return m_strWaveSpeed;
}
inline void PipePerisist::WaveSpeed(CString strValue)
{
	m_strWaveSpeed = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::WaveSpeedUnit()
{
	return m_strWaveSpeedUnit;
}
inline void PipePerisist::WaveSpeedUnit(CString strValue)
{
	m_strWaveSpeedUnit = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::B()
{
	return m_strB;
}
inline void PipePerisist::B(CString strValue)
{
	m_strB = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::Material()
{
	return m_strMaterial;
}
inline void PipePerisist::Material(CString strValue)
{
	m_strMaterial = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::Size()
{
	return m_strSize;
}
inline void PipePerisist::Size(CString strValue)
{
	m_strSize = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::PipeType()
{
	return m_strType;
}
inline void PipePerisist::PipeType(CString strValue)
{
	m_strType = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::Thick()
{
	return m_strThick;
}
inline void PipePerisist::Thick(CString strValue)
{
	m_strThick = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::ThickUnit()
{
	return m_strThickUnit;
}
inline void PipePerisist::ThickUnit(CString strValue)
{
	m_strThickUnit = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::Elasticity()
{
	return m_strElasticity;
}
inline void PipePerisist::Elasticity(CString strValue)
{
	m_strElasticity = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::ElasticityUnit()
{
	return m_strElasticityUnit;
}
inline void PipePerisist::ElasticityUnit(CString strValue)
{
	m_strElasticityUnit = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::PossionRatio()
{
	return m_strPossionRatio;
}
inline void PipePerisist::PossionRatio(CString strValue)
{
	m_strPossionRatio = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::InDiaReduce()
{
	return m_strInDiaReduce;
}
inline void PipePerisist::InDiaReduce(CString strValue)
{
	m_strInDiaReduce = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::SupportType()
{
	return m_strSupportType;
}
inline void PipePerisist::SupportType(CString strValue)
{
	m_strSupportType = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::CalcWave()
{
	return m_strCalcwave;
}
inline void PipePerisist::CalcWave(CString strValue)
{
	m_strCalcwave = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::C1()
{
	return m_strC1;
}
inline void PipePerisist::C1(CString strValue)
{
	m_strC1 = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::FrictionModel()
{
	return m_strFrictionModel;
}
inline void PipePerisist::FrictionModel(CString strValue)
{
	m_strFrictionModel = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::Friction()
{
	return m_strFriction;
}
inline void PipePerisist::Friction(CString strValue)
{
	m_strFriction = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::FrictionUnit()
{
	return m_strFrictionUnit;
}
inline void PipePerisist::FrictionUnit(CString strValue)
{
	m_strFrictionUnit = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::LocalK()
{
	return m_strLocalK;
}
inline void PipePerisist::LocalK(CString strValue)
{
	m_strLocalK = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::PipeFactor()
{
	return m_strPipeFactor;
}
inline void PipePerisist::PipeFactor(CString strValue)
{
	m_strPipeFactor = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::FitFactor()
{
	return m_strFitFactor;
}
inline void PipePerisist::FitFactor(CString strValue)
{
	m_strFitFactor = strValue;
}
/*------------------------------------------*/
inline StrArray<3>& PipePerisist::InitFlow()
{
	return m_InitFlow;
}
inline void PipePerisist::InitFlow(const StrArray<3>& strValue)
{
	m_InitFlow = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::SectionNum()
{
	return m_strSectionNum;
}
inline void PipePerisist::SectionNum(CString strValue)
{
	m_strSectionNum = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::ParaNum()
{
	return m_strParaNum;
}
inline void PipePerisist::ParaNum(CString strValue)
{
	m_strParaNum = strValue;
}
/*------------------------------------------*/
inline CString PipePerisist::PartFull()
{
	return m_strPartFull;
}
inline void PipePerisist::PartFull(CString strValue)
{
	m_strPartFull = strValue;
}
/*------------------------------------------*/
#endif // !defined(AFX_PIPEPERISIST_H__7FD1C2FB_5E01_4411_B34B_114AB3365892__INCLUDED_)
