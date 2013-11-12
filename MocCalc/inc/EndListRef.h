// EndListRef.h: interface for the EndListRef class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：EndListRef.h.h
  摘要：    在特征线计算瞬变流中节点引用所连接管道的端口信息的一个类。
  author  : LSP           
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENDLISTREF_H__A76A0547_A0B8_4B34_B4F8_FEE00C863676__INCLUDED_)
#define AFX_ENDLISTREF_H__A76A0547_A0B8_4B34_B4F8_FEE00C863676__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Iterator.h"
#include "EndInfo.h"
#include "MOCLumpedInertia.h"
#include "GasProperty.h"

class EndListRef  
{
public:
	void AddEnd(EndInfo *pEnd);
	Iterator<EndInfo>* CreatEndIt();
	EndInfo* GetInEnd();
	EndInfo* GetOutEnd();
	EndInfo* Find(int nKey);
	EndListRef();
	virtual ~EndListRef();

public:
	void SetZ(double dInZ,double dOutZ);
	void SetMass(double dMass);
	void SetPress(double dPress);
	double GetPress();
	double GetDetalPress();
	double GetEGL();
	double GetOneEndArea();
	double GetStaticPress();
	double GetInMass();
	double GetOutMass();
	BOOL IsVapor();
	void Vapor(BOOL bVapor);
	double VaporVolume();
	void VaporVolume(double dVolume);
public:
	void BranchStrategy(double dOutMass);
	void FlowStrategy(double dMass);//设置端点的流量并计算压力
	void FlowStrategy(EndInfo &end,double dMass);
	void DeadStrategy();
	void StaticPressStrategy(double dStaticPress);
	void StagPressStrategy();
	void StagPressStrategy(double dStagPress);//设置端点的滞止压力并计算
	void StaticPressStrategy(EndInfo &end,double dStaticPress);
	void StagPressStrategy(EndInfo &end,double dStagPress);//设置端点的滞止压力并计算
	void CvStrategy(double dCv,double dArea);
	void KStrategy(double dK,double dArea);
	void RStrategy(double dR);
	void CvStrategy(double dPress,double dCv,double dArea,double &dOutMass);
	void RStrategy(double dPress,double dR,double &dOutMass);
	void KStrategy(double dPress,double dK,double dArea,double &dOutMass);
	double FixDropStrategy(double dPressDelta);
	double FixDropStrategy(double dPressUp,double dPressDelta);
	double FixDropMass(double dPressDelta);
	double FixDropMass(double dPressUp,double dPressDelta);
	double FixRiseStrategy(double dPressDelta);
	double FixRiseStrategy(double dPressUp,double dPressDelta);
	double FixRiseMass(double dPressDelta);
	double FixRiseMass(double dPressUp,double dPressDelta);

	void SurgeJunStrategy(MOCLumpedInertia &Inertia,double dSurfacePress,double dArea,double &dH,double &dMass);
	void GasJunStrategy(MOCLumpedInertia &Inertia,double dPolytropic,double dCA,double &dMass,double &dPress,double &dVolume);
	void BreakerJunStrategy(int nType,GasProperty &gas,double dCdAIn,double dCdAOut);
	void LiquidJunStrategy(double dK,double &dVolume,double &dMass);
public:
	double Sb();
	double SunBpm();
	double Sc();
	double SunCpm();
	double CollapseMass();
	void Collapse();
	double DetalVaporVolume(double dOutMass);
	double OldDetalVaporVolume();
	double CheckVaporPress(double dPress);
private:
	double GetMass(Dir type);
private:
	typedef CList<EndInfo*,EndInfo*> EndRef;
	EndRef m_list;
	double m_dOldDetalVapor;
};


#endif // !defined(AFX_ENDLISTREF_H__A76A0547_A0B8_4B34_B4F8_FEE00C863676__INCLUDED_)
