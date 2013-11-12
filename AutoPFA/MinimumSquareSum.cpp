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
#include <algorithm>

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

	// 调用前须对ComManager进行处理，使得图形中没有分支，配水源的流量也计入相应节点中
	double dLengthFactor = 3.0;        // 改进的最小平方和方法中长度的幂次，2.5-3.0之间效果最好
	double dTemp = 0.0;
	Jun* pJun = NULL;
	Component* pJunComponent = NULL;
	Pipe* pPipe = NULL;
	Component* pPipeComponent = NULL; 
	ComMap CloseJuns;              // 例子中的 (3,4,5)
	ComMap ClosePipes;
	vector< double > ModulusVector;// 系数矩阵中的某一行
	CirMatrix JunAndJuns;          // 节点和与节点相连的节点编号
	CirMatrix JunAndPipes;
	int iCountOfJuns = 0;          // 节点的数量
	map< int, double > LengthMap;       // 长度的幂次倒数

	// 把节点和与节点相连的节点编号都放入JunAndJuns
	// 如节点1和节点3，4，5相连，则( 1, ( (3,4,5) )
	JunAndJuns.clear();
	JunAndPipes.clear();
	LengthMap.clear();
	IteratorPtr<Component> JunItPtr( ComManager.CreatJunIterator() );
	for( JunItPtr->Fist(); !JunItPtr->IsDone(); JunItPtr->Next() )
    {
		iCountOfJuns++;
		CloseJuns.clear();
		ClosePipes.clear();
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
				ClosePipes.push_back( pPipe->GetKey() );
			}
			if( pPipe->EndJun() == pJun->GetKey() )	
			{
				CloseJuns.push_back( pPipe->StartJun() );
				ClosePipes.push_back( -1 * pPipe->GetKey() );
			}
		}
		JunAndJuns.insert( CirMatrix::value_type( pJun->GetKey(), CloseJuns ) );
		JunAndPipes.insert( CirMatrix::value_type( pJun->GetKey(), ClosePipes ) );
	}

	ComMap::iterator CloseJunsIt;
	ComMap* pJunVector = NULL;
	CirMatrix::iterator JunsIt;
	ComMap::iterator ClosePipesIt;
	ComMap* pJunAndPipeVector = NULL;
	CirMatrix::iterator JunsAndPipesIt;
	double dTempLength = 0.0; // 长度幂次倒数和
	
	// 计算管道长度的幂次倒数
	IteratorPtr<Component> PipeItPtr( ComManager.CreatPipeIterator() );
	for( PipeItPtr->Fist(); !PipeItPtr->IsDone(); PipeItPtr->Next() )
	{
		pPipeComponent = &PipeItPtr->CurrentItem();
		pPipe = dynamic_cast<Pipe*>( pPipeComponent );
		OptData.GetProperty( pPipe->GetKey(), 2, dTemp );
		if( !( 1e-6 < fabs( dTemp - 1e-6 ) ))
		{
			return false;
		}
		dTemp = pow( dTemp, -1.0 * dLengthFactor );
		LengthMap.insert( map< int, double >::value_type( abs( pPipe->GetKey() ), dTemp ) );
	}

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
		JunsAndPipesIt = JunAndPipes.find( pJun->GetKey() );
 	    pJunVector = ( ComMap* ) &( JunsIt->second );
		pJunAndPipeVector = ( ComMap* ) &( JunsAndPipesIt->second );



		// 节点的系数
		for( ClosePipesIt = pJunAndPipeVector->begin(); pJunAndPipeVector->end() != ClosePipesIt; ClosePipesIt++ )
		{
			map< int, double >::iterator TempIt = LengthMap.find( abs( *ClosePipesIt ) );
			dTemp += TempIt->second;
		}
		//ModulusVector[ pJun->GetKey() - 1 ] = dTemp;                      // 每个节点的系数
		ModulusVector[ pJun->GetKey() - 1 ] = pJunAndPipeVector->size();
		
		// 其他节点的系数
		for( CloseJunsIt = pJunVector->begin(); CloseJunsIt != pJunVector->end(); CloseJunsIt++ )
		{
			for( PipeItPtr->Fist(); !PipeItPtr->IsDone(); PipeItPtr->Next() )
			{
				pPipeComponent = &PipeItPtr->CurrentItem();
		        pPipe = dynamic_cast<Pipe*>( pPipeComponent );
				if( ( pPipe->StartJun() == pJun->GetKey() ) && ( pPipe->EndJun() == *CloseJunsIt ) )
				{
					dTemp = -1 * pow( pPipe->Len(), -1.0 * dLengthFactor );
					break;
				}
				if( ( pPipe->EndJun() == pJun->GetKey() ) && ( pPipe->StartJun() == *CloseJunsIt ) )
				{
					dTemp = pow( pPipe->Len(), -1.0 * dLengthFactor );
					break;
				}
			}
			//ModulusVector[ abs( *CloseJunsIt ) - 1 ] = dTemp;
			ModulusVector[ abs( *CloseJunsIt ) - 1 ] = -1;
		}

		OptData.GetProperty( pJun->GetKey(), 3, ModulusVector[ iCountOfJuns ] );     // 节点的节点流量 ,流入为正，流出为负
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
	
	/*
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
	*/

	// 设置管道虚流量
	for( PipeItPtr->Fist(); !PipeItPtr->IsDone(); PipeItPtr->Next() )
	{
		pPipeComponent = &PipeItPtr->CurrentItem();
		pPipe = dynamic_cast<Pipe*>( pPipeComponent );
		DumIt = DummyFluxMap.find( pPipe->StartJun() );
		dStartDummyFlux = DumIt->second;
		DumIt = DummyFluxMap.find( pPipe->EndJun() );
		dEndDunmmyFlux = DumIt->second;
		dEndDunmmyFlux = dStartDummyFlux - dEndDunmmyFlux;
		if( ( 0 <= iFluxType ) && ( 1 >= iFluxType ) )
		{
			OptData.SetProperty( pPipe->GetKey(), iFluxType, dEndDunmmyFlux );
		}
		
	}
	return true;
}


// 用截面法分配虚流量
bool CMinimumSquareSum::InitializeDummyFlux( ComponentManager& ComManager, PFAOptimitationData& OptData )
{
	int iCountOfJuns = ComManager.GetJunNum();          // 节点的数量
	
	// 计算总流量，即计算配水源流量总和
	double dFluxSummation = 0.0;
	double dTem = 0.0;
	int iKeyOfJu = 0;
	int k = 0;
	for( k = 1; k <= iCountOfJuns; k++ )
	{
		
		{
			OptData.GetProperty( k, 3, dTem );
		    dFluxSummation += dTem;
		}
	}
    /*
	map< int, vector< double > >::iterator IntVecMapIt = ModulusMatrix.begin();
	for( ; IntVecMapIt != ModulusMatrix.end(); IntVecMapIt++ )
	{
		( IntVecMapIt->second )[ iCountOfJuns ] /= dFluxSummation; 
	}

	//GaussMethod( ModulusMatrix, Variance, ResultMap );
	if( !CholeskyMethod( ModulusMatrix, ResultMap ) )
	{
		return false;
	}
	SetInitializePipeFlux( 0, ComManager, ResultMap, OptData );

   */

	/////////////////////////////
	map< int, vector< int > > JunAndPipesMap;   // <节点，<与节点相连的管道> >
	vector< int > PipesVector;                  // <与节点相连的管道>	
	int i = 0;
	double dTemp = 0.0;
	Component* pComponent = NULL;
	Pipe* pPipe = NULL;
	Jun* pJun = NULL;
	IteratorPtr<Component> JunItPtr( ComManager.CreatJunIterator() );
	JunAndPipesMap.clear();
	for( JunItPtr->Fist(); !JunItPtr->IsDone(); JunItPtr->Next() )
    {
		PipesVector.clear();
		pComponent = &JunItPtr->CurrentItem();
		pJun = dynamic_cast<Jun*>( pComponent );
		IteratorPtr<Component> PipeItPtr( ComManager.CreatPipeIterator() );
		for( PipeItPtr->Fist(); !PipeItPtr->IsDone(); PipeItPtr->Next() )
		{
			pComponent = &PipeItPtr->CurrentItem();
			pPipe = dynamic_cast<Pipe*>( pComponent );
			if( pPipe->StartJun() == pJun->GetKey() )
			{
				PipesVector.push_back( pPipe->GetKey() );
			}
			if( pPipe->EndJun() == pJun->GetKey() )
			{
				PipesVector.push_back( -pPipe->GetKey() );
			}
		}
		JunAndPipesMap.insert( map< int, vector< int > >::value_type( pJun->GetKey(), PipesVector ) );
		
	}

	vector< int > FindJunVector;                // 要搜寻的点  
	vector< int > TempFindJunVector;            // 辅助存储要搜寻的点
	vector< int > FindPipeVector;                   // 要分配虚流量的管道
	vector< int > AllPipesVector;               // 所有管段集合，用来判断虚流量分配是否成功
	
	// 首先把所有管道都放入AllPipesVector
	AllPipesVector.clear();
	int iKeyOfPipe = 0;
	for( i = 0; i < OptData.GetPropertyCount( 102 ); i++ )
	{
		OptData.GetProperty( i, 102, iKeyOfPipe );
		AllPipesVector.push_back( abs( iKeyOfPipe ) );           
	}

	map< int, vector< int > >::iterator IntVecMapIt;
	vector< int >::iterator IntVecIt;
	vector< int >::iterator FindIntVecIt;
	vector< int >::iterator TempIntVecIt;
	int iKeyOfJun = 0;
	int iCountOfPipe = 0;

	// 用配水源节点初始化FindJunVector
	FindJunVector.clear();
	for( i = 0; i < OptData.GetPropertyCount( 200 ); i++ )
	{
		OptData.GetProperty( i, 200, iKeyOfJun );
		FindJunVector.push_back( abs( iKeyOfJun ) );
	}

	TempFindJunVector.clear();
	while( 0 != FindJunVector.size() )
	{
		iCountOfPipe = 0;
		FindPipeVector.clear();
	    FindIntVecIt = FindJunVector.begin();
	    for( ; FindJunVector.end() != FindIntVecIt; FindIntVecIt++ )
		{
		    IntVecMapIt = JunAndPipesMap.find( abs( *FindIntVecIt ) );
	    	IntVecIt = IntVecMapIt->second.begin();
		    for( ; IntVecMapIt->second.end() != IntVecIt; IntVecIt++ )
			{
		    	TempIntVecIt = find( AllPipesVector.begin(), AllPipesVector.end(), abs( *IntVecIt ) );   // 泛型算法
		    	if( AllPipesVector.end() != TempIntVecIt )                 // 如果管道之前未分配虚流量
				{
			    	iCountOfPipe++;
			    	AllPipesVector.erase( TempIntVecIt );   // 删除管道，表明这根管道已处理
					FindPipeVector.push_back( abs( *IntVecIt ) );            // 把将要分配虚流量的管道放入FindPipeVector

					// 把管道的另一个节点放入TempFindJunVector，为下一次FindJunVector分配虚流量作准备
					// 可能会把已经走过的节点也放入了TempFindJunVector，不过不影响最后结果，因为走过节点的相邻管道不在AllPipesVector中
					pPipe = ComManager.LookUpPipe( abs( *IntVecIt ) );
					if( pPipe->StartJun() == *FindIntVecIt )
					{
						TempFindJunVector.push_back( abs( pPipe->EndJun() ) );
					}
					if( pPipe->EndJun() == *FindIntVecIt )
					{
						TempFindJunVector.push_back( abs( pPipe->StartJun() ) );
					}
				}
			}
		}
		
		// 给FindPipeVector中的管道分配虚流量，值为1/TempFindJunVector元素个数,即1/iCountOfPipe
		if( 0 != iCountOfPipe )   
		{
			FindIntVecIt = FindPipeVector.begin();
			dTemp = 1.0 / ( ( double )iCountOfPipe );
			for( ; FindPipeVector.end() != FindIntVecIt; FindIntVecIt++ )
			{		
				OptData.SetProperty( *FindIntVecIt, 0, dTemp );
			}			
		}

		// 把TempFindJunVector放入FindJunVector中
		FindJunVector.clear();
		FindIntVecIt = TempFindJunVector.begin();
		for( ; TempFindJunVector.end() != FindIntVecIt; FindIntVecIt++ )
		{
			FindJunVector.push_back( abs( *FindIntVecIt ) );
		}
		TempFindJunVector.clear();
	}
	
	if( 0 != AllPipesVector.size() )                 // 管道没有完全遍历
	{
		FindIntVecIt = AllPipesVector.begin();
		return false;
	}
	

	for( i = 0; i < OptData.GetPropertyCount( 102 ); i++ )
	{
		OptData.GetProperty( i, 102, iKeyOfPipe );
		OptData.GetProperty( iKeyOfPipe, 0, dTemp );
	}
	return true;
}


bool CMinimumSquareSum::InitializeFactFlux( ComponentManager& ComManager, PFAOptimitationData& OptData )
{
	double Variance = 0.0001;                              // 精度控制
	map< int, double > ResultMap;                         // 结果向量
	map< int, vector< double > > ModulusMatrix;
	InitializeModulusMatrix( ComManager, OptData, ModulusMatrix );
	//GaussMethod( ModulusMatrix, Variance, ResultMap );
	if( !CholeskyMethod( ModulusMatrix, ResultMap ) )
	{
		return false;
	}
	SetInitializePipeFlux( 1, ComManager, ResultMap, OptData );
	return true;
}


////////////////////////////////////////////////////////////////
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


////////////////////////////////////////////////////////////////////////////////////////////
// Cholesky方法，用来解一维线性方程组，要求矩阵是非奇异对称矩阵，比高斯消元法的数值稳定性要好

bool CMinimumSquareSum::Chobsb(double a[], int n, double d[], double b[])
{
	int i,j;
	double sum;
    for (i = 1; i<=n; i++)
	{
        sum = b[i];
        for (j = 1; j<=i - 1; j++)
		{
            sum = sum - a[(i-1)*n+j] * b[j];
        }
        b[i] = sum;
    }
    for (i = n; i>=1; i--)
	{
        if (d[i] == 0.0)
		{
            return false;
		}
        else
		{
            sum = b[i] / d[i];
        }
        for (j = i + 1; j<=n; j++)
		{
            sum = sum - a[(j-1)*n+i] * b[j];
        }
        b[i] = sum;
    }
	return true;
}

bool CMinimumSquareSum::Chodcm(double a[], int n, double d[], double t[])
{
	bool bFlag = true;
	int i,j,k;
	double sum;
    for (i = 1; i<=n; i++)
	{
        sum = a[(i-1)*n+i];
        for (j = 1; j<=i - 1; j++)
		{
            t[j] = a[(j-1)*n+i];
            for (k = 1; k<=j - 1; k++)
			{
                t[j] = t[j] - t[k] * a[(j-1)*n+k];
            }
            if (d[j] == 0.0)
			{
                if (t[j] != 0.0)
				{
                    bFlag = false;
				}
                else
				{
                    a[(i-1)*n+j] = 1.0;
                }
			}
            else
			{
                a[(i-1)*n+j] = t[j] / d[j];
            }
            sum = sum - t[j] * a[(i-1)*n+j];
        }
        d[i] = sum;
    }
	return bFlag;
}

// N为方程数，在函数中自动把第一行第一列省略了
bool CMinimumSquareSum::CholeskyMethod( map< int, vector< double > >& ModulusMatrix, map< int, double >& ResultMap )
{
	ASSERT( NULL != &ModulusMatrix );

	bool bFlag = true;
	int iNumber = ModulusMatrix.size(); 
	int i = 0;
	int j = 0;

	// 右边常量向量
	map< int, vector< double > >::iterator ConstIntVecMapIt = ModulusMatrix.begin();
	vector< double >::iterator ConstDouVecIt;
	double* pB = new double[iNumber];	// 右边向量，最后结果放在此数组中
	for( i = 1; i <= iNumber; i++ )
	{
		const vector< double >* pDouVec = &( ConstIntVecMapIt->second );	
		*(pB + i - 1) = pDouVec->back();
		ConstIntVecMapIt++;
	}

	// 因为只有J-1个独立方程，所以去掉第一行和第一列,pC也是从1开始
	double* pC = new double[( iNumber - 1 ) * ( iNumber - 1 ) + 1];    // 辅助单元， 依次存放A中的元素
	ConstIntVecMapIt = ModulusMatrix.begin();
	ConstIntVecMapIt++;                        // 去掉第一行
	for( i = 1; i < iNumber; i++, ConstIntVecMapIt++ )
	{
		ConstDouVecIt = ConstIntVecMapIt->second.begin();
		ConstDouVecIt++;                       // 去掉第一列
		for( j = 1; j < iNumber; j++, ConstDouVecIt++ )
		{
			*( pC + ( i - 1 ) * ( iNumber - 1 ) + j) = *ConstDouVecIt;
		}
	}
	
	// 解方程组，结果放在了pB中
	double* pD = new double[iNumber];    // 存放分解中对角矩阵D的对角元素
	double* pT = new double[iNumber];    // 辅助单元
	if( !Chodcm( pC, iNumber - 1, pD, pT ) )
	{
		return false;
	}
	if( !Chobsb( pC, iNumber - 1, pD, pB ) )
	{
		return false;
	}

	// 计算第一行的解
	ConstIntVecMapIt = ModulusMatrix.begin();
	double dTempFlux = ConstIntVecMapIt->second.back();
	double dTemp = dTempFlux;
	vector< double >::iterator DouVecIt = ConstIntVecMapIt->second.begin();
	DouVecIt++;                              
	for( i = 1; i < iNumber; i++, DouVecIt++ )
	{	
		dTemp = dTemp - ( *DouVecIt ) * pB[i];
	}
	
	ConstDouVecIt = ConstIntVecMapIt->second.begin();
	dTemp = dTemp / *ConstDouVecIt;
	pB[0] = dTemp;

	// 把结果放入ResultMap
	ResultMap.clear();
	for( i = 0; i < iNumber; i++ )
	{
		ResultMap.insert( map< int, double >::value_type( i + 1, pB[i] ) );
	}

	// 回收内存
	delete[] pB;
	delete[] pC;
	delete[] pD;
	delete[] pT;
	
	return true;
}
