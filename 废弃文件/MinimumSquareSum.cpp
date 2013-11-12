// MinimumSquareSum.cpp: implementation of the CMinimumSquareSum class.
// 
//////////////////////////////////////////////////////////////////////
/************************************************************************
版本: 8.0       开发时间: 2008/05/31  作者: COM 

功能: 初始化流量，主要是用来初始化虚流量
                                                             
输入: 
                                                              
输出: PFAOptimitationData& OptData，在OptData中的对应位置记录虚流量  
                                                        
< 修改人 >    < 时间 >     < 版本 >        < 描述 > 
   COM        2008/05/31    8.0                                                                                            
************************************************************************/

#pragma once
#include "stdafx.h"
#include "autopfa.h"
#include "MinimumSquareSum.h"
#include "PFAOptimitationData.h"
#include "Iterator.h"
#include <math.h>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMinimumSquareSum::CMinimumSquareSum()
{

}

CMinimumSquareSum::~CMinimumSquareSum()
{

}

bool CMinimumSquareSum::InitializeModulusMatrix( ComponentManager& ComManager, PFAOptimitationData& OptData, map< int, vector< double > >& ModulusMatrix )
{
	ASSERT( NULL != &ComManager );
	ASSERT( NULL != &OptData );

	Jun* pJun = NULL;
	Component* pJunComponent = NULL;
	Pipe* pPipe = NULL;
	Component* pPipeComponent = NULL; 
	ComMap CloseJuns;              // 例子中的 (3,4,5)
	vector< double > ModulusVector;// 系数矩阵中的某一行
	CirMatrix JunAndJuns;          // 节点和与节点相连的节点编号
	int iCountOfJuns = 0;          // 节点的数量

	// 把节点和与节点相连的节点编号都放入JunAndJuns
	// 如节点1和节点3，4，5相连，则( 1, ( (3,4,5) )
	IteratorPtr<Component> JunItPtr( ComManager.CreatJunIterator() );
	for( JunItPtr->Fist(); !JunItPtr->IsDone(); JunItPtr->Next() )
    {
		iCountOfJuns++;
		CloseJuns.clear();
		pJunComponent = &JunItPtr->CurrentItem();
		pJun = dynamic_cast<Jun*>( pJunComponent );
		IteratorPtr<Component> PipeItPtr( ComManager.CreatPipeIterator() );
		for( PipeItPtr->Fist(); !PipeItPtr->IsDone(); PipeItPtr->Next() )
		{
			pPipeComponent = &PipeItPtr->CurrentItem();
			pPipe = dynamic_cast<Pipe*>( pPipeComponent );
			if( pPipe->StartJun() == pJun->GetKey() )
			{	
				CloseJuns.push_back( pPipe->EndJun() );
			}
			if( pPipe->EndJun() == pJun->GetKey() )	
			{
				CloseJuns.push_back( pPipe->StartJun() );
			}

		}
		JunAndJuns.insert( CirMatrix::value_type( pJun->GetKey(), CloseJuns ) );
	}

	ComMap::iterator CloseJunsIt;
	ComMap* pJunVector;
	CirMatrix::iterator JunsIt;
	for( JunItPtr->Fist(); !JunItPtr->IsDone(); JunItPtr->Next() )
    {
		ModulusVector.clear();
		pJunComponent = &JunItPtr->CurrentItem();
		pJun = dynamic_cast<Jun*>( pJunComponent );	

		// 初始化向量，要初始化iCountOfJuns+1个
		for( int i = 0; i <= iCountOfJuns; i++ )
		{
			ModulusVector.push_back( 0 );
		}

		JunsIt = JunAndJuns.find( pJun->GetKey() );
 	    pJunVector = ( ComMap* ) &( JunsIt->second );
		int j = 0;           // 节点连接数
		for( CloseJunsIt = pJunVector->begin(); CloseJunsIt != pJunVector->end(); CloseJunsIt++ )
		{
			// 如果连接节点是配水源节点的话就不把系数改为-1，但仍然记入节点连接数
			j++;
			int iKeyOfSupplyJun = 0;
			for( int m = 0; m < OptData.GetPropertyCount( 200 ); m++ )
			{
				OptData.GetProperty( m, 200, iKeyOfSupplyJun);
				if( iKeyOfSupplyJun != *CloseJunsIt )
				{
					ModulusVector[ *CloseJunsIt - 1 ] = -1;	
				}
				else
				{
					break;
				}
			}		
		}
		ModulusVector[ pJun->GetKey() - 1 ] = j;                      // 每个节点的节点连接数
		OptData.GetProperty( pJun->GetKey(), 3, ModulusVector[ iCountOfJuns ] );     // 节点的节点流量，Q=1时要先处理一下
		ModulusVector[ iCountOfJuns ] *= -2.0;
		ModulusMatrix.insert( map< int, vector< double > >::value_type( pJun->GetKey(), ModulusVector ) );
	}
	return true;
}

bool CMinimumSquareSum::SetInitializePipeFlux( const int& iFluxType,ComponentManager& ComManager, IntDoubleMap& DummyFluxMap, PFAOptimitationData& OptData )
{
	ASSERT( NULL != &ComManager );
	ASSERT( NULL != & DummyFluxMap );

	Pipe* pPipe = NULL;
	Component* pPipeComponent = NULL; 
	IteratorPtr<Component> PipeItPtr( ComManager.CreatPipeIterator() );
	IntDoubleMap::iterator DumIt;
	double dStartDummyFlux = 0.0;
	double dEndDunmmyFlux = 0.0;
	
	// 把配水点的值设置为0
	int iKeyOfSupplyJun = 0;
	for( int m = 0; m < OptData.GetPropertyCount( 200 ); m++ )
	{
		OptData.GetProperty( m, 200, iKeyOfSupplyJun);
		DumIt = DummyFluxMap.find(iKeyOfSupplyJun );
		if( DummyFluxMap.end() != DumIt )
		{
			DumIt->second = 0.0;
		}
	}

	// 设置管道虚流量
	for( PipeItPtr->Fist(); !PipeItPtr->IsDone(); PipeItPtr->Next() )
	{
		pPipeComponent = &PipeItPtr->CurrentItem();
		pPipe = dynamic_cast<Pipe*>( pPipeComponent );
		DumIt = DummyFluxMap.find( pPipe->StartJun() );
		dStartDummyFlux = DumIt->second;
		DumIt = DummyFluxMap.find( pPipe->EndJun() );
		dEndDunmmyFlux = DumIt->second;
		dEndDunmmyFlux = ( dEndDunmmyFlux - dStartDummyFlux ) / 2.0;
		if( ( 0 <= iFluxType ) && ( 1 >= iFluxType ) )
		{
			OptData.SetProperty( pPipe->GetKey(), iFluxType, dEndDunmmyFlux );
		}
		
	}
	return true;
}

bool CMinimumSquareSum::InitializeDummyFlux( ComponentManager& ComManager, PFAOptimitationData& OptData )
{
	double Variance = 0.0001;                              // 精度控制
	map< int, double > ResultMap;                         // 结果向量
	int i = 0;
	map< int, vector< double > > ModulusMatrix;
	InitializeModulusMatrix( ComManager, OptData, ModulusMatrix );

	// 把节点流量变为 Q节点/ Q总流量
	Jun* pJun = NULL;
	Component* pJunComponent = NULL;
	int iCountOfJuns = ComManager.GetJunNum();          // 节点的数量
	
	// 计算总流量
	double dFluxSummation = 0.0;
	double dTemp = 0.0;
	int iKeyOfJun = 0;
	for( i = 0; i < OptData.GetPropertyCount( 200 ); i++ )
	{
		if( false != OptData.GetProperty( i, 200, iKeyOfJun ) )
		{
			OptData.GetProperty( iKeyOfJun, 3, dTemp );
		    dFluxSummation += dTemp;
		}
	}

	map< int, vector< double > >::iterator IntVecMapIt = ModulusMatrix.begin();
	for( ; IntVecMapIt != ModulusMatrix.end(); IntVecMapIt++ )
	{
		( IntVecMapIt->second )[ iCountOfJuns ] /= dFluxSummation; 
	}

	GaussMethod( ModulusMatrix, Variance, ResultMap );
	SetInitializePipeFlux( 0, ComManager, ResultMap, OptData );
	return true;
}


bool CMinimumSquareSum::InitializeFactFlux( ComponentManager& ComManager, PFAOptimitationData& OptData )
{
	double Variance = 0.0001;                              // 精度控制
	map< int, double > ResultMap;                         // 结果向量
	map< int, vector< double > > ModulusMatrix;
	InitializeModulusMatrix( ComManager, OptData, ModulusMatrix );
	GaussMethod( ModulusMatrix, Variance, ResultMap );
	SetInitializePipeFlux( 1, ComManager, ResultMap, OptData );
	return true;
}



// 解N元线性方程组，高斯消元法，网上抄的, 修改了下，可能有点乱
void CMinimumSquareSum::OutputMatrix( double **pMatrix, const int& Size, vector< double >& ResultVector)   //输出矩阵系数
{	
	ResultVector.clear();
	//vector< double >::iterator VecIt = ResultVector.begin();
	for( int i = 0; i < Size; i++ )
	{
		//if( ResultVector.end() == VecIt )
		//{
			ResultVector.push_back( pMatrix[i][Size] );
		//}
		//else
		//{
		//	*VecIt = pMatrix[i][Size];
		//}
		//VecIt++;
	}
}


void CMinimumSquareSum::InputMatrix( const map< int, vector< double > >& ModulusMatrix, double **pMatrix )
{
	int i = 0;
	int j = 0;
	map< int, vector< double > >::const_iterator ConstMapIt = ModulusMatrix.begin();
	for( ; ConstMapIt != ModulusMatrix.end(); ConstMapIt++ )
	{
		j = 0;
		vector< double >::const_iterator ConstVecIt = ( ConstMapIt->second ).begin();
		for( ; ConstVecIt != ( ConstMapIt->second ).end(); ConstVecIt++ )
		{
			pMatrix[i][j] = *ConstVecIt;
			j++;
		}
		i++;
	}
}
//实现选择最大主元及消元
bool CMinimumSquareSum::VanishElement( double **pMatrix, int RowSize, int ColumnSize, double Var )
{	
	int iTemp,k;	
	double dTemp;	
	bool Exclusive;	
	for (int i=0; i<RowSize-1; i++)		
	{		
		iTemp=i;		
		for (k=i+1; k<RowSize; k++)//从aii，ai+1,i，…，ani中选择最大主元 			
			if(fabs(pMatrix[iTemp][i])<fabs(pMatrix[k][i]))				
				iTemp=k;			
			if(pMatrix[iTemp][iTemp]>Var)  				
			{				
				Exclusive=true;				
				if( iTemp!=i)					
				{					
					for(int j=i; j<ColumnSize; j++)						
					{						
						dTemp=pMatrix[iTemp][j];						
						pMatrix[iTemp][j]=pMatrix[i][j];						
						pMatrix[i][j]=dTemp;						
					}					
				}
				
				//消元过程				
				for (k=i+1; k<RowSize; k++)					
				{					
					pMatrix[k][i]=pMatrix[k][i]/pMatrix[i][i];					
					for (int j=i+1; j<ColumnSize; j++)						
						pMatrix[k][j]=pMatrix[k][j]-pMatrix[k][i] * pMatrix[i][j];					
				}				
			}			
			else				
			{				
				Exclusive=false;				
				break;     //方程组无唯一解，结束循环					
			}			
	}	
	return Exclusive;	
}

//反转矩阵，求末知向量X，X的值求解后放在b位置上。
void CMinimumSquareSum::MatrixInvers( double **pMatrix, int RowSize, int ColumnSize)
{	
	for ( int i=RowSize-1; i>=0; i-- )		
	{		
		double sum=0;		
		for (int j=i+1; j<ColumnSize-1; j++)			
			sum += pMatrix[i][j] * pMatrix[j][ColumnSize-1];		
		pMatrix[i][ColumnSize-1]=(pMatrix[i][ColumnSize-1]-sum)/pMatrix[i][i];		
	}	
}

bool CMinimumSquareSum::GaussMethod( const map< int, vector< double > >& ModulusMatrix , const double& dVariance, map< int, double >& ResultMap )
{	
	ASSERT( NULL != &ModulusMatrix );
	ASSERT( 0 < dVariance );
	// 变量Variance为误差控制量，通常为比较小的正实数，		
    // 当某个选出的主元小于该数，就认为该方程组无唯一解。
	
	//输入线性方程组阶数：";	矩阵A和右端向量b合成一个矩阵，故行数为Size，列数为Size＋1。
	int Size = ModulusMatrix.size(); 
	vector< double > ResultVector;
	
	//定义动态二维数组。	
	double* *Matrix=new double *[Size];	
	for (int n=0; n<Size; n++)		
		Matrix[n]=new double [Size+1];	
	InputMatrix( ModulusMatrix, Matrix ); 	
	if( VanishElement( Matrix, Size, Size+1, dVariance ))		
	{		
		MatrixInvers( Matrix, Size, Size+1 );		
		OutputMatrix( Matrix, Size, ResultVector ); //变量向量x的值在Matrix矩阵的最后一列,即存放在原来的b向量上。		
	}	
	else		
	{		
		return false;	
	}


	map< int, vector< double > >::const_iterator ConstMapIt = ModulusMatrix.begin();
	vector< double >::iterator VecIt = ResultVector.begin();
	for( ; ModulusMatrix.end() != ConstMapIt; ConstMapIt++, VecIt++ )
	{
		ResultMap.insert( map< int, double >::value_type( ConstMapIt->first, *VecIt ) );
	}
	// 释放内存
	for( int i = 0; i < Size; i++ )
	{
		delete[] Matrix[i];

	}
	return true;
}

