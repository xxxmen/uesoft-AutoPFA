// PFAOptimize.h: interface for the CPFAOptimize class.
// 
//////////////////////////////////////////////////////////////////////
/************************************************************************
版本: 8.0         开发时间: 2008/06  作者: COM
 
功能: 优化模块，用来进行管道模块的优化，具体算法和思路可参考：城镇给排水工程程序设计（王国明）                                                                                                                                             
************************************************************************/


#include "ComponentManager.h"
#include <algorithm>
#include <math.h>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include "PFAOptimitationData.h"
#include "DlgOptProGress.h"
//#include "OptResult.h"
 
using namespace std;
typedef vector<int> ComMap;
typedef map< int, ComMap > CirMatrix;
typedef vector< pair< int, CPoint > > JunAndCenter;
typedef map< int, JunAndCenter > ComAndCloseComs; 




#if !defined(AFX_PFAOPTIMIZE_H__2247B5DD_77CB_40A2_B446_829CC1710856__INCLUDED_)
#define AFX_PFAOPTIMIZE_H__2247B5DD_77CB_40A2_B446_829CC1710856__INCLUDED_



#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
enum BaseCircleDirection{ DEASIL_DIRECTION = 1, ANTICLOCKWISE_DIRECTION };

class CPFAOptimize  
{
public:
	CPFAOptimize();
	virtual ~CPFAOptimize();

	// 寻找基环的下一个节点
	void FindJunOfCircle( Jun& PreJun, Jun& NextJun, ComAndCloseComs&  JunAndCloseJuns, int& iKeyOfChoiceJun );
    
	// 找出包含管道BasePipe的顺时针或逆时针基环，注意现在还只能从单水源无分支管网中找出来
	BOOL FindBaseCircle( ComponentManager& ComManager, Pipe& BasePipe, BaseCircleDirection Direction, ComMap& JunKeyMap, ComMap& PipeKeyMap, int iMostCircle[] );
	
	void CopyVector( JunAndCenter& DestinationVector, JunAndCenter& SourceVector );
	
	// 判断是否是最大环，即最外面的环
	BOOL JudgeMaxCircle( ComMap& JunKeyMap, int iMostCircle[], vector< CString >& JunPointGather, CString& strMaxCircle );
	
	// 信息记录方式转换
	void JunSystemTransformCircleSystem( ComponentManager& ComManager, PFAOptimitationData& OptData );
	
	void DisplayMatrix( const CString& strFileDirectory, const int& iProperty, PFAOptimitationData& OptData );
	bool Example();
	void GetAngle( const double& dX, const double& dY, double& dAngle );
    bool CalOthersVariable( ComponentManager& ComManager, PFAOptimitationData& OptData );
	PFAOptimitationData* GetOptDataPointer();
	


private:
	// 把节点信息批量插入OptData
	bool InsertCircleMatrix( const int& iKeyOfCircle, const int& iProperty, ComMap& ComponentKeyMap, PFAOptimitationData& OptData );
		
	// 计算管道-环矩阵，为各环连续校正法做准备
	bool InitializePipeCircle( PFAOptimitationData& OptData );
	
	// 最短路径,Dijkstra算法
	bool FindShortCut( ComponentManager& ComManager, const int& iKeyOfStartJun, const int& iKeyOfEndJun, vector< int >& JunToJunPipePath );
	bool SetProperties( vector< int >& IntVector, const int& iPosition, const int& iValue );
	int GetProperties( const vector< int >& IntVector, const int& iPosition );
	bool SetProperties( map< int, vector< int > >& IntVecMap, const int& iRow, const int& iLine, const int& iValue );
	int GetProperties( const map< int, vector< int > >& IntVecMap, const int& iRow, const int& iLine );
	
	// 牛顿迭代法解柯尔勃洛克-魏特公式
	bool ColebrookNewton( const double& dAbsoluteRoughness, const double& dDiameter, const double& dRe, double& dResult );


	// 计算管道闭合差
	bool CalPipeCloseSubtract( ComponentManager& ComManager, PFAOptimitationData& OptData, map< int, double >& OptimitationParameterMap, map< int, double >& OptimitationAssistantMap );
	
	bool CalDummyFlux( const double& dDummyPrecision, PFAOptimitationData& OptData );
	double CalStdDiameter( const double& dCalDiameter );
	bool DoOptimitation( ComponentManager& ComManager, PFAOptimitationData& OptData );

	bool DisplayResult( PFAOptimitationData& OptData );
	CDlgOptProGress m_DlgOptProGress;    // 进度条
	PFAOptimitationData OptData;
};


inline PFAOptimitationData* CPFAOptimize::GetOptDataPointer()
{
	return &OptData;
}
#endif // !defined(AFX_PFAOPTIMIZE_H__2247B5DD_77CB_40A2_B446_829CC1710856__INCLUDED_)
