// PFAOptimitationData.h: interface for the PFAOptimitationData class.
//
//////////////////////////////////////////////////////////////////////
/************************************************************************

版本: 8.0  开发时间: 2008/06  作者: COM 

功能: 优化过程中所需要的绝大部分数据, 感觉显得有些臃肿,      
                                                                                                                                        
************************************************************************/

#if !defined(AFX_PFAOPTIMITATIONDATA_H__3FB00A99_D0F1_49CD_8DE1_16288CF29DA5__INCLUDED_)
#define AFX_PFAOPTIMITATIONDATA_H__3FB00A99_D0F1_49CD_8DE1_16288CF29DA5__INCLUDED_


#pragma  once
#include <vector>
#include <map>
using namespace std;
typedef vector<int> ComMap;
typedef map< int, ComMap > CirMatrix;
const CString ECONOMY_FAILE = "经济因素计算失败，请检查参数是否设置错误！";

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum PropertyType
{ 
	OPT_PIPEDUMMYFLUX = 0, OPT_PIPEFACTFLUX, OPT_PIPELENGTH, OPT_JUNFLUX, OPT_PIPEDIAMETER, OPT_PIPEWATERHAMMER, 
	OPT_PIPEFLUXSPEED, OPT_JUNPRESSURE, OPT_PIPEECONOMYDIAMETER,
	OPT_PIPEDUMMYWATERHAMMER = 10, OPT_PIPEFACTWATERHAMMER,

    OPT_CIRPIPE = 100, OPT_CIRJUN, OPT_PIPECIR, OPT_PIPEKEY,

    OPT_SUPPLYJUN = 200, OPT_CONTROLJUN, OPT_DUMMYCIRCLE, OPT_DUMMYJUNANDPIPE,

    OPT_A = 300, OPT_B, OPT_ALFA, OPT_DISINVESTMENTTIME, OPT_REPAIRMODULUS, OPT_WORKEXPENDITURE, OPT_ELETRICITYPRICE, 
	OPT_ASYMMETRYMODULUS, OPT_PUMPEFFICIENCY, OPT_K, OPT_M, OPT_N, OPT_ECONOMYFACTOR,OPT_FLUXSUMMATION, OPT_CONSTRUCTEXPENDITURE,
	OPT_YCONVERTEXPENDITURE, 

	OPT_NULL = 2000
};

class PFAOptimitationData  
{
public:
	PFAOptimitationData();
	virtual ~PFAOptimitationData();
	bool Initialization();
	void RemoveAll();

	inline bool SetCirJunMatrix( const int& iKeyOfCircle, const ComMap& CircleJunOrder );
    inline CirMatrix* GetCirJunMatrix();
	ComMap* GetCirJunMatrix( const int& iKeyOfCircle );
	inline int GetCirJunMatrixCount();

	inline bool SetCirPipeMatrix( const int& iKeyOfCircle, const ComMap& CirclePipeOrder );
	inline CirMatrix* GetCirPipeMatrix();
	ComMap* GetCirPipeMatrix( const int& iKeyOfCircle );
	inline int GetCirPipeMatrixCount();

	inline CirMatrix* GetPipeCirMatrix();

	// 0+
	bool GetProperty( const int& iKeyOfComponent, const int& iProperty, double& dValueOfProperty );  // 若找不到则返回FALSE；
	bool SetProperty( const int& iKeyOfComponent, const int& iProperty, double& dValueOfProperty );
	
	// 100+
	bool GetProperty( const int& iKeyOfComponent, const int& iProperty, const int& iPosition, int& iValueOfProperty );  // 若找不到则返回FALSE；
	bool SetProperty( const int& iKeyOfComponent, const int& iProperty, const int& iPosition, int& iValueOfProperty );

	// 200+
	bool GetProperty( const int& iKeyOfComponent, const int& iProperty, int& iValueOfProperty );
	bool SetProperty( const int& iKeyOfComponent, const int& iProperty, int& iValueOfProperty );

	// 300+
	double GetProperty( const PropertyType& eProperty );
	bool SetProperty( const PropertyType& eProperty, const double& dValueOfProperty );
	
	int GetPropertyCount( const int& iProperty );                                    // 取得行个数
	int GetPropertyCount( const int& iKeyOfComponent, const int& iProperty );        // 取得对应行的列数

	inline double GetAModulus();
	inline double GetBModulus();
	inline double GetAlfaModulus();
	inline double GetDisinvestmentTime();
	inline double GetRepairModulus();
	inline double GetWorkExpenditure();
	inline double GetEletricityPrice();
	inline double GetAsymmetryModulus();
	inline double GetPumpEfficiency();
	inline double GetKModulus();
	inline double GetMModulus();
	inline double GetNModulus();
	inline double GetEconomyFactor();
	inline double GetFluxSummation();
	inline double GetConstructExpenditure();
	inline double GetYConvertExpenditure();
	

	inline void SetAModulus( const double& dTempAModulus );
	inline void SetBModulus( const double& dTempBModulus );
	inline void SetAlfaModulus( const double& dTempAlfaModulus );
	inline void SetDisinvestmentTime( const double& dTempDisinvestmentTime );
	inline void SetRepairModulus( const double& dTempRepairModulus );
	inline void SetWorkExpenditure(const double& dTempWorkExpenditure );
	inline void SetEletricityPrice( const double& dTempEletricityPrice );
	inline void SetAsymmetryModulus( const double& dTempAsymmetryModulus );
	inline void SetPumpEfficiency( const double& dTempPumpEfficiency );
	inline void SetKModulus( const double& dTempKModulus );
	inline void SetMModulus( const double& dTempMModulus );
	inline void SetNModulus( const double& dTempNModulus );
	inline void SetEconomyFactor( const double& dTempEconomyFactor );
	inline void SetFluxSummation( const double& dTempFluxSummation );
	inline void SetConstructExpenditure( const double& dTempConstructExpenditure );
    inline void SetYConvertExpenditure( const double& dTempYConvertExpenditure );
	
private:
	// 存储环-管道矩阵:100
	CirMatrix CirPipeMatrix;
	
	// 存储环-节点矩阵:101     
	CirMatrix CirJunMatrix;

	// 存储管道-环矩阵:102
	CirMatrix PipeCirMatrix;


	// 可以从这两个基本矩阵中推出其他矩阵
	
	// 记录管道的虚流量:0
	map< int, double > PipeDummyFluxMap;
	
	// 记录管道的实际流量:1
	map< int, double > PipeFactFluxMap;
	
	// 记录管道的长度:2
	map< int, double > PipeLengthMap;

	// 记录节点流量：3
	map< int, double > JunFluxMap;

	// 记录优化后的管径：4
	map< int, double > PipeDiameter;

	// 记录优化后的水头损失：5
	map< int, double > PipeWaterHammer;

	// 记录管道流速: 6
	map< int, double > PipeFluxSpeedMap;

	// 记录节点相对水压: 7
	map< int, double > JunPressureMap;

	// 记录计算出来的经济管径：8
	map< int, double > PipeEconomyDiameterMap;

	// 记录管道虚水头损失: 10
	map< int, double > PipeDummyWaterHammer;

	// 记录管道实际水头损失: 11
	map< int, double > PipeFactWaterHammer;

	// 记录配水源节点:200
	vector< int > SupplyJunVector;

	// 记录控制点节点：201
	vector< int > ControlJunVector;

	// 记录虚环编号 : 202
	vector< int > DummyCircleVector;

	// 记录虚节点和虚管道，只可能有一个虚节点，把他放在第一个位置： 203
	vector< int > DummyJunAndPipeVector;

	// 还有个方案是把double换成一个类，这个类里面放了dDummyFlux, dFactFlux, dLength三个成员变量，然后为这三个成员变量提供接口，
	// 供集中存储类调用，具体哪个方式好些，现在无法判断，只能在以后的设计中寻求答案。
	// 在类中提供一个访问接口BOOL GetPipeProperty( int iKeyOfPipe, int iProperty )，使得即使以后改变了DummyFlux, FactFlux, Length的存储方式，也不用改变外面的代码。
	
	// 水管建造费用（包括水管材料费用和埋管施工等费用，单位元/m）中的a:300
	double dA;

	// 水管建造费用中的b: 301
	double dB;

	// 水管建造费用中的指数α:302
	double dAlfa;

	// 基建投资回收期,单位：年。基建投资效果系数E=1/dDisinvestmentTime。:303
	double dDisinvestmentTime;
	
	// p:管网每年折旧和大修百分率，以管网建造费用的%计算 : 304
	double dRepairModulus;

	// K:与抽水有关的经济指标，即输送1m~3/s 的水到1m高度的每年电费; :305
	double dWorkExpenditure;

	// 电价，用来计算K的 :306
	double dEletricityPrice;

	// 计算年限内供水能量不均匀系数, 用来计算K :307
	double dAsymmetryModulus;

	// 泵效率,用来计算K :308
	double dPumpEfficiency;

	// k,m,n:系数，取决于所采用的水力阻力计算公式,n一般取2.0  :309
	double dKModulus; 
	double dMModulus;                 // 310
	double dNModulus;                 // 311

	// f:经济因素  :312
	double dEconomyFactor;

	// Q:进入管网的总流量 : 313
	double dFluxSummation;

	// 建设费用 : 314
	double dConstructExpenditure;

	// W:年折算费用 : 315
	double dYConvertExpenditure;

	// 成员变量的访问接口，保证代码的独立性.TRUE表示Get；FALSE表示Set
    bool ChangeProperty( const int& iKeyOfComponent, const int& iProperty, const bool bChangeType, double& dValueOfProperty );
	bool ChangeProperty( const int& iKeyOfComponent, const int& iProperty, const int& iPosition, const bool bChangeType, int& iValueOfProperty );
	bool ChangeProperty( const int& iKeyOfComponent, const int& iProperty, const bool bChangeType, int& iValueOfProperty );
};

inline bool PFAOptimitationData::SetCirPipeMatrix( const int& iKeyOfCircle, const ComMap& CirclePipeOrder )
{
	CirPipeMatrix.insert( CirMatrix::value_type( iKeyOfCircle, CirclePipeOrder ) );
    return true; 
}

inline CirMatrix* PFAOptimitationData::GetCirPipeMatrix()
{
	return &CirPipeMatrix;
} 

inline int PFAOptimitationData::GetCirPipeMatrixCount()
{
	return CirPipeMatrix.size();
}

inline bool PFAOptimitationData::SetCirJunMatrix( const int& iKeyOfCircle, const ComMap& CircleJunOrder )
{
    CirJunMatrix.insert( CirMatrix::value_type( iKeyOfCircle, CircleJunOrder ) );
    return true;
}

inline CirMatrix* PFAOptimitationData::GetCirJunMatrix()
{
	return &CirJunMatrix;
} 

inline int PFAOptimitationData::GetCirJunMatrixCount()
{
	return CirJunMatrix.size();
}

inline CirMatrix* PFAOptimitationData::GetPipeCirMatrix()
{
	return &PipeCirMatrix;
}


///////////////////////////////////////////////////////
inline double PFAOptimitationData::GetAModulus()
{
	return dA;
}

inline double PFAOptimitationData::GetBModulus()
{
	return dB;
}

inline double PFAOptimitationData::GetAlfaModulus()
{
	return dAlfa;
}

inline double PFAOptimitationData::GetDisinvestmentTime()
{
	return dDisinvestmentTime;
}

inline double PFAOptimitationData::GetRepairModulus()
{
	return dRepairModulus;
}

inline double PFAOptimitationData::GetWorkExpenditure()
{
	return dWorkExpenditure;
}

inline double PFAOptimitationData::GetEletricityPrice()
{
	return dEletricityPrice;
}

inline double PFAOptimitationData::GetAsymmetryModulus()
{
    return dAsymmetryModulus;
}

inline double PFAOptimitationData::GetPumpEfficiency()
{
	return dPumpEfficiency;
}

inline double PFAOptimitationData::GetKModulus()
{
	return dKModulus;
}
inline double PFAOptimitationData::GetMModulus()
{
	return dMModulus;
}

inline double PFAOptimitationData::GetNModulus()
{
	return dNModulus;
}

inline double PFAOptimitationData::GetEconomyFactor()
{
	return dEconomyFactor;
}

inline double PFAOptimitationData::GetFluxSummation()
{
	return dFluxSummation;
}

inline double PFAOptimitationData::GetConstructExpenditure()
{
	return dConstructExpenditure;
}

inline void PFAOptimitationData::SetConstructExpenditure( const double& dTempConstructExpenditure )
{
	dConstructExpenditure = dTempConstructExpenditure;
}


inline double PFAOptimitationData::GetYConvertExpenditure()
{
	return dYConvertExpenditure;
}

inline void PFAOptimitationData::SetYConvertExpenditure( const double& dTempYConvertExpenditure )
{
	dYConvertExpenditure = dTempYConvertExpenditure;
}

inline void PFAOptimitationData::SetAModulus( const double& dTempAModulus )
{
	dA =dTempAModulus;
}

inline void PFAOptimitationData::SetBModulus( const double& dTempBModulus )
{
	dB = dTempBModulus;
}

inline void PFAOptimitationData::SetAlfaModulus( const double& dTempAlfaModulus )
{
	dAlfa = dTempAlfaModulus;
}

inline void PFAOptimitationData::SetDisinvestmentTime( const double& dTempDisinvestmentTime )
{
	dDisinvestmentTime = dTempDisinvestmentTime;
}

inline void PFAOptimitationData::SetRepairModulus( const double& dTempRepairModulus )
{
	dRepairModulus = dTempRepairModulus;
}

inline void PFAOptimitationData::SetWorkExpenditure(const double& dTempWorkExpenditure )
{
	dWorkExpenditure = dTempWorkExpenditure;
}

inline void PFAOptimitationData::SetEletricityPrice( const double& dTempEletricityPrice )
{
	dEletricityPrice = dTempEletricityPrice;
}

inline void PFAOptimitationData::SetAsymmetryModulus( const double& dTempAsymmetryModulus )
{
    dAsymmetryModulus = dTempAsymmetryModulus;
}

inline void PFAOptimitationData::SetPumpEfficiency( const double& dTempPumpEfficiency )
{
	dPumpEfficiency = dTempPumpEfficiency;
}

inline void PFAOptimitationData::SetKModulus( const double& dTempKModulus )
{
	dKModulus = dTempKModulus;
}
inline void PFAOptimitationData::SetMModulus( const double& dTempMModulus )
{
	dMModulus = dTempMModulus;
}

inline void PFAOptimitationData::SetNModulus( const double& dTempNModulus )
{
	dNModulus = dTempNModulus;
}

inline void PFAOptimitationData::SetEconomyFactor( const double& dTempEconomyFactor )
{
	dEconomyFactor = dTempEconomyFactor;
}

inline void PFAOptimitationData::SetFluxSummation( const double& dTempFluxSummation )
{
	dFluxSummation = dTempFluxSummation;
}

#endif // !defined(AFX_PFAOPTIMITATIONDATA_H__3FB00A99_D0F1_49CD_8DE1_16288CF29DA5__INCLUDED_)
