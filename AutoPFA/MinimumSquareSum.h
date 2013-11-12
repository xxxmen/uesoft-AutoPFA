// MinimumSquareSum.h: interface for the CMinimumSquareSum class.
//
//////////////////////////////////////////////////////////////////////
/************************************************************************
版本: 8.0       开发时间: 2008/05/31  作者: COM 

功能: 流量初始化中的最小平方和方法,其中有高斯消主元法和 Cholesky法,但最后选择了Cholesky
                                                                                                                                         
************************************************************************/


#if !defined(AFX_MINIMUMSQUARESUM_H__C94D9225_38C9_4B44_9CF5_003057D18ABA__INCLUDED_)
#define AFX_MINIMUMSQUARESUM_H__C94D9225_38C9_4B44_9CF5_003057D18ABA__INCLUDED_

#include <map>
#include "ComponentManager.h"
#include "PFAOptimitationData.h"
using namespace std;
typedef map< int, double > IntDoubleMap;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMinimumSquareSum  
{
public:
	CMinimumSquareSum();
	virtual ~CMinimumSquareSum();

    bool InitializeDummyFlux( ComponentManager& ComManager, PFAOptimitationData& OptData );
	bool InitializeFactFlux( ComponentManager& ComManager, PFAOptimitationData& OptData );
private:

	// 从线性方程组中提取系数，放到系数矩阵ModulusMatrix中
	bool InitializeModulusMatrix( ComponentManager& ComManager, PFAOptimitationData& OptData, map< int, vector< double > >& ModulusMatrix );
    
	// 把用最小平方和方法获得的初始虚流量放入PFAOptimitationData& OptData中
	bool SetInitializePipeFlux( const int& iFluxType, ComponentManager& ComManager, IntDoubleMap& DummyFluxMap, PFAOptimitationData& OptData );
	
	// 高斯消主元法, 有一定的局限性
	bool GaussMethod( const map< int, vector< double > >& ModulusMatrix , const double& dVariance, map< int, double >& ResultMap );

	// Cholesky法,用来解对称稀疏非奇异矩阵, 适用范围比高斯消主元法广
	bool CholeskyMethod( map< int, vector< double > >& ModulusMatrix, map< int, double >& ResultMap );

	void MatrixInvers( double **pMatrix, int RowSize, int ColumnSize);
	bool VanishElement( double **pMatrix, int RowSize, int ColumnSize, double Var );
	void InputMatrix( const map< int, vector< double > >& ModulusMatrix, double **pMatrix );
	void OutputMatrix( double **pMatrix, const int& Size, vector< double >& ResultVector);

	bool Chobsb(double a[], int n, double d[], double b[]);
	bool Chodcm(double a[], int n, double d[], double t[]);
};

#endif // !defined(AFX_MINIMUMSQUARESUM_H__C94D9225_38C9_4B44_9CF5_003057D18ABA__INCLUDED_)
