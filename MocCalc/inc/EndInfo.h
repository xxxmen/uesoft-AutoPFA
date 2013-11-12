// EndInfo.h: interface for the CEndInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENDINFO_H__5879521D_2E06_4E30_8BF8_2D1F697C5983__INCLUDED_)
#define AFX_ENDINFO_H__5879521D_2E06_4E30_8BF8_2D1F697C5983__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：EndInfo.h
  摘要：    在特征线计算瞬变流中做为管段和节点交换信息的一个类。
  author  : LSP           
*/
typedef enum DirType { INJUN =1,OUTJUN,} Dir;
class EndInfo  
{
public:
	double GetHGL();
	double GetEGL();
	double CalcEndLoss();
	double GetBpm();
	double GetCpm();
	double GetPress();
	double GetZ();
	double GetMass();
	DirType GetEmunDir();
	double InJunK();
	double OutJunK();
	double Area();
	void SetPipeID(double ID[]);
	void GetPipeId(int ID[]);
	int Key();
	Dir Type();

	void InJunK(double dK);	
	void OutJunK(double dK);
	void SetBpm(double dBpm);
	void SetCpm(double dCpm);
	void SetZ(double dZ);
	void SetPress(double dPress);
	void SetMass(double dMass);
	void Area(double dArea);
	void Key(int nKey);
	
	BOOL IsVapor();
	void Vapor(BOOL bVapor);
	double VaporVolume();
	void VaporVolume(double dVaporVolume);
	double CheckVaporPress(double dPress,double dMass);
	double DetalVaporVolume(double dMass);
	void Collapse();
	double CollapseMass();
	EndInfo(Dir emun);
	virtual ~EndInfo();

	//Add by Liuck [4/27/2009] 修改0流量标记
	void SetZeroMassFlag( BOOL bFlag )
	{
		m_bZeroMassFlag = bFlag ;
	}
	BOOL GetZeroMassFlag()
	{
		return m_bZeroMassFlag ;
	}

public:
	double CalcPress();
	double CalcMass();
	double CalcStaicMass(double dPress);
	double GetVolumeFlow();
	double GetVelocity();
	double GetStagPress();
	double GetStaticPress();

private:
	double GetStaticR();
	int  m_PipeId[3];
	int m_nPipeKey;
	DirType  m_emunDir;
	double m_dMass;
	double m_dPress;
	double m_dCpm;
	double m_dBpm;
	double m_dElevation;
	double m_dKInPipe;
	double m_dKOutPipe;
	double m_dArea;
	double m_dVaporVolume;
	double m_dOldDetalVapor;
	BOOL m_bVapor;

	//Add by Liuck [4/27/2009] 当管道流量计算允许为0或者说是正常结果就是0
	//（比如盲端、安全阀），这时候计算上游的压力就没有意义，设置此情况时标记
	//使在管道的CheckTol时可以直接将其上下游的流量均设置为0，不再另外计算
	BOOL m_bZeroMassFlag ;
};

inline double EndInfo::Area()
{
	 return m_dArea;
}
inline void EndInfo::Area(double dArea)
{
	m_dArea = dArea;
}

inline void EndInfo::GetPipeId(int ID[])
{
	for (int i=0; i<3;i++)
	{
		ID[i] = m_PipeId[i];
	}
}

inline void EndInfo::SetPipeID(double ID[])
{
	for(int i=0;i<3;i++)
	{
		m_PipeId[i] = int(ID[i]);
	}
}

inline DirType EndInfo::GetEmunDir()
{
	return m_emunDir;
}

inline double EndInfo::GetMass()
{
	return m_dMass;
}

inline double EndInfo::GetZ()
{
	return m_dElevation;
}

inline double EndInfo::GetPress()
{
	return m_dPress;
}
inline void EndInfo::SetPress(double dPress)
{
	m_dPress = dPress;
}
inline void EndInfo::SetMass(double dMass)
{
	m_dMass = dMass;
}

inline void EndInfo::SetZ(double dZ)
{
	m_dElevation = dZ;
}

inline void EndInfo::SetCpm(double dCpm)
{
	m_dCpm = dCpm;
}

inline double EndInfo::GetCpm()
{
	return m_dCpm;
}

inline void EndInfo::SetBpm(double dBpm)
{
	m_dBpm = dBpm;
}

inline double EndInfo::GetBpm()
{
	 return m_dBpm;
}
inline void EndInfo::InJunK(double dK)
{
	m_dKInPipe = dK;
}

inline double EndInfo::InJunK()
{
	return m_dKInPipe;
}

inline void EndInfo::OutJunK(double dK)
{
	m_dKOutPipe = dK;
}

inline double EndInfo::OutJunK()
{
	 return m_dKOutPipe;
}

inline void EndInfo::Key(int nKey)
{
	m_nPipeKey = nKey;
}

inline int EndInfo::Key()
{
	 return m_nPipeKey;
}
inline Dir EndInfo::Type()
{
	return m_emunDir;
}


#endif // !defined(AFX_ENDINFO_H__5879521D_2E06_4E30_8BF8_2D1F697C5983__INCLUDED_)
