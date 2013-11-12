// PFAOptimize.cpp: implementation of the CPFAOptimize class.
//
//////////////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"
#include "autopfa.h"
#include "PFAOptimize.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "AutoPFAView.h"
#include "AutoPFADoc.h"
#include "Scenario.h"
#include "Fuild.h"
#include "QuantityManager.h"
#include "MinimumSquareSum.h"
#include "OutDataAttr.h"
#include "OutPutDataView.h"
#include "ModelDataView.h"


const CString MODULUS_ZERO = "系数为0，请重新设置! ";

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPFAOptimize::CPFAOptimize()
{
	
}

CPFAOptimize::~CPFAOptimize()
{

}


void CPFAOptimize::FindJunOfCircle( Jun& PreJun, Jun& NextJun, ComAndCloseComs&  JunAndCloseJuns, int& iKeyOfChoiceJun )
{
	// 参数有效性判断 
	ASSERT( NULL != &PreJun );
	ASSERT( NULL != &NextJun );
	ASSERT( NULL != &JunAndCloseJuns );

	ComAndCloseComs::iterator JunAndCloseJunsIterator = JunAndCloseJuns.find( NextJun.GetKey() );
	JunAndCenter* pJunAndCenter =  &JunAndCloseJunsIterator->second; 
	// 如果JunAndCloseJuns中只有两个管道， 那么就没必要在判断了，只能指定不是PreJun节点的节点为下一节点
	if( 2 == pJunAndCenter->size() )
	{
		JunAndCenter::const_iterator JunIterator = pJunAndCenter->begin();
		for ( ; JunIterator != pJunAndCenter->end(); JunIterator++ )
		{
			if ( PreJun.GetKey() != JunIterator->first )
			{
				iKeyOfChoiceJun = JunIterator->first;
				return;
			}
		}
	}
	
	CPoint ptPreJun( PreJun.CenterPt() );
	CPoint ptNextJun( NextJun.CenterPt() );
	
	double dMaxTheta = 2 * PI;                         // 最小的相对弧度值，即夹角大小
	double dPre = 0.0;                                 // ptNextJun-》ptPreJun
	double dNext = 0.0;    	                           // ptNextJun->pComJunCenter
	Pipe* pPipe = NULL;
	JunAndCenter JunCenterVector;
	pair<int, CPoint>* pComJunCenter;
	JunAndCenter::iterator JunCenterIt = pJunAndCenter->begin();
	for( ; JunCenterIt != pJunAndCenter->end(); JunCenterIt++ )
	{
		pComJunCenter = ( pair<int, CPoint>* )JunCenterIt;
		
		// 如果节点是PreJun点，则不要计算，直接跳过，计算下一点
		if ( pComJunCenter->first == PreJun.GetKey() )
		{
			continue;
		}
		
		// 把坐标原点移动到ptNextJun
		GetAngle( ( double )( ptPreJun.y - ptNextJun.y ), ( double )( ptPreJun.x - ptNextJun.x ), dPre );
	    GetAngle( ( double )( pComJunCenter->second.y - ptNextJun.y ), ( double )( pComJunCenter->second.x- ptNextJun.x ), dNext );
		dNext = -( dNext - dPre );     // 取负是为了方便理解
		dNext = dNext > 0 ? dNext : dNext + 2 * PI;
		
		// 取最小弧度的管道作为下一根管道
		if( dMaxTheta > dNext )
		{
			dMaxTheta = dNext;
			iKeyOfChoiceJun = pComJunCenter->first;
		}
		
	}
}

void CPFAOptimize::GetAngle( const double& dY, const double& dX, double& dAngle )
{
	ASSERT( NULL != &dY );
	ASSERT( NULL != &dX );

	if( fabs(dX - 1e-6) < 0)
	{
		dAngle = dY > 0 ? PI : -PI;
		return;
	}
	dAngle = atan( dY / dX );
	if( dX < 0  )
	{
		dAngle += PI;
		return;
	} 
	if( ( dX > 0 ) && ( dY < 0 ) )
	{
	    dAngle += 2 * PI;
		return;
	}
	return;
}


void CPFAOptimize::CopyVector( JunAndCenter& DestinationVector, JunAndCenter& SourceVector )
{
	JunAndCenter::iterator SourceIt = SourceVector.begin();
	pair< int, CPoint > Temp;
	pair< int, CPoint >* pSource = NULL;
	for ( ; SourceIt != SourceVector.end(); SourceIt++ )
	{
		pSource = SourceIt;
		Temp.first = SourceIt->first;
		Temp.second.x = ( pSource->second ).x;
		Temp.second.y = ( pSource->second ).y;
		DestinationVector.push_back( Temp );
	}
}



BOOL CPFAOptimize::FindBaseCircle( ComponentManager& ComManager, Pipe& BasePipe, BaseCircleDirection Direction, ComMap& JunKeyMap, ComMap& PipeKeyMap, int iMostCircle[] )
{	
	//参数有效性判断
	ASSERT( NULL != &ComManager );
	ASSERT( NULL != &BasePipe );

	ComAndCloseComs JunAndCloseJuns;
	JunAndCenter CloseJuns;   // 记录节点和节点位置的Vector，形式如(节点编号，节点位置)
	Jun* pJun = NULL;
	Component* pJunComponent = NULL;
	Pipe* pPipe = NULL;
	Component* pPipeComponent = NULL;   
	Jun* pPreJun = NULL;
	Jun* pNextJun = NULL;
	Jun* pStartJun = NULL;
	Jun* pStartNextJun = NULL;

	// 图形的上、左、右、下四个顶点的位置，为确定最大环做准备
	int iTop = 2147483647;                       // 2的32次方减一
	int iLeft = 2147483647;
	int iRight = 0;
	int iBotton = 0;

	IteratorPtr<Component> JunItPtr( ComManager.CreatJunIterator() );

	// 把节点和与节点相连的节点信息都放入JunAndCloseJuns
	// 如节点1和节点3，4，5相连，则( 1, ( (3,节点3位置), (4，节点4位置), (5，节点5位置) ) )
	// 然后把管道和与管道相连的管道编号放入PipeAndClosePipes
	// 如管道1和管道3，4，5相连，则(1,(3,4,5))
	for( JunItPtr->Fist(); !JunItPtr->IsDone(); JunItPtr->Next() )
    {
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
				pair< int , CPoint > Temp( pPipe->EndJun(), pPipe->EndPt() );
				CloseJuns.push_back( Temp );
			}
			if( pPipe->EndJun() == pJun->GetKey() )	
			{
				pair< int , CPoint > Temp( pPipe->StartJun(), pPipe->StartPt() );
				CloseJuns.push_back( Temp );
			}
			if( pPipe->GetKey() == BasePipe.GetKey() )
			{
				if ( DEASIL_DIRECTION == Direction )
				{
					pPreJun = ComManager.LookUpJun( pPipe->StartJun() );
					pNextJun = ComManager.LookUpJun( pPipe->EndJun() );
				}
				else
				{
					pPreJun = ComManager.LookUpJun( pPipe->EndJun() );
					pNextJun = ComManager.LookUpJun( pPipe->StartJun() );
				}
			}
		}
		JunAndCloseJuns.insert( ComAndCloseComs::value_type( pJun->GetKey(), CloseJuns ) );

		// 确定四个顶点
		if( iTop > pJun->CenterPt().y )
		{
			iTop = pJun->CenterPt().y;
			iMostCircle[0] = pJun->GetKey();
		}
		if( iBotton < pJun->CenterPt().y )
		{
			iBotton = pJun->CenterPt().y;
			iMostCircle[1] = pJun->GetKey();
		}
		if( iLeft > pJun->CenterPt().x )
		{
			iLeft = pJun->CenterPt().x;
			iMostCircle[2] = pJun->GetKey();
		}
		if( iRight < pJun->CenterPt().x )
		{
			iRight = pJun->CenterPt().x;
			iMostCircle[3] = pJun->GetKey();
		}
	}

	JunItPtr->Fist();
	pJunComponent = &JunItPtr->CurrentItem();
    pJun = dynamic_cast<Jun*>( pJunComponent );
	CloseJuns.clear();
	ComAndCloseComs::iterator JunIt = JunAndCloseJuns.find( pJun->GetKey() );
	CopyVector( CloseJuns, JunIt->second );  
	
	// 寻找环—节点矩阵
	pStartJun = pPreJun;
	pStartNextJun = pNextJun;
	int iKeyOfChoiceJun = 0;                 // 用来标记哪个节点编号作为基环的下一节点编号
	JunKeyMap.push_back( pNextJun->GetKey() );
	BOOL bFirst = TRUE;
	while( ( pNextJun != pStartNextJun ) || ( pPreJun != pStartJun ) || bFirst )
	{
		bFirst = FALSE;
		FindJunOfCircle( *pPreJun, *pNextJun, JunAndCloseJuns, iKeyOfChoiceJun );
	    pPreJun = pNextJun;
		pNextJun = ComManager.LookUpJun( iKeyOfChoiceJun );
		JunKeyMap.push_back( pNextJun->GetKey() );
	}
	

	// 寻找环—管道矩阵
	ComMap::const_iterator JunKeyNextIterator = NULL;
	int iJunNextkey = 0;                        // 上面的环-节点矩阵中节点的编号， 下面的也一样
	int iJunPreKey = 0;
	map< int, int > PipeOrder;                             // (管道在环中的位置，管道编号)
	int iPipePosition = 0;                      // 管道在环中的位置
	IteratorPtr<Component> PipeItPtr( ComManager.CreatPipeIterator() );
	for( PipeItPtr->Fist(); !PipeItPtr->IsDone(); PipeItPtr->Next() )
	{
		pPipeComponent = &PipeItPtr->CurrentItem();
		pPipe = dynamic_cast<Pipe*>( pPipeComponent );
		JunKeyNextIterator = JunKeyMap.begin();
		iPipePosition = 0;
		iJunPreKey = *JunKeyNextIterator;
		JunKeyNextIterator++;
        for ( ; JunKeyNextIterator != JunKeyMap.end(); JunKeyNextIterator++ )
		{
			iJunNextkey = *JunKeyNextIterator;
			
			// 如果管道和环里的相邻节点相连，那么这根管道肯定是环里的管道
			if( ( ( pPipe->StartJun() == iJunPreKey ) && ( pPipe->EndJun() == iJunNextkey ) ))
			{
				PipeOrder.insert( map<int,int>::value_type( iPipePosition, pPipe->GetKey() ) );	
			}
			if( ( ( pPipe->EndJun() == iJunPreKey ) && ( pPipe->StartJun() == iJunNextkey ) ) )
			{
				int i = -1 * pPipe->GetKey();
                PipeOrder.insert( map<int,int>::value_type( iPipePosition, i ) );
			}
			iJunPreKey = iJunNextkey;
			iPipePosition++;
		}
	}
	
	// 把PipeOrder里的信息放入PipeKeyMap中
    // PipeOrder信息(管道在环中的位置，管道的编号)
	int iCountCircleJun = PipeOrder.size();
	int iPipeKey = 0;
	map< int, int >::iterator PipeIterator = NULL;
	for ( iPipePosition = 0, iPipeKey = 0; iPipePosition < iCountCircleJun; iPipePosition++ )
	{
		PipeIterator = PipeOrder.find( iPipePosition );
		if( PipeIterator == PipeOrder.end() )
		{
			break;
		}
		iPipeKey = PipeIterator->second;
		PipeKeyMap.push_back( iPipeKey );
	}

	return TRUE;
}



BOOL CPFAOptimize::JudgeMaxCircle( ComMap& JunKeyMap, int iMostCircle[], vector< CString >& JunPointGather, CString& strMaxCircle )
{
	// 
	ASSERT( NULL != &JunKeyMap );
	ASSERT( NULL != iMostCircle );
	ComMap TempKeyMap;                                  // 辅助元素
	ComMap::iterator ComIt;
    CString strCircle = "";                               // 环的节点信息，节点编号已经排列好了
	CString strTemp = "";
	int i = 0;
	// 把环JunKeyMap中的第二个到最后一个元素节点信息拷贝到TempKeyMap
	// 因为JunKeyMap中的环节点信息重复了开始点， 例如(5,4,6,1,5)
    for( ComIt = JunKeyMap.begin(), ComIt++; ComIt != JunKeyMap.end(); ComIt++ )
    {
		TempKeyMap.push_back( *ComIt );
    }

	sort( TempKeyMap.begin(), TempKeyMap.end() );     // 泛型算法，从小到大把TempKeyMap排序

    // 把排列好的环节点信息放入strCircle中， 例如(1,4,5,6)
	for( ComIt = TempKeyMap.begin(); ComIt != TempKeyMap.end(); ComIt++ )
	{
		strCircle = strCircle + COMPARTMENTATION + _itoa( *ComIt, strTemp.GetBuffer( 4 ), 10 );
	}
		
	// 如果最大环没找到，则要判断现在的环是不是最大环
	if( strMaxCircle.IsEmpty() )
	{
		BOOL bFindMaxCircle = TRUE;

		// 此环是最大环，记下节点信息，直接返回
		if( ( 0 < strCircle.Find( itoStr( iMostCircle[0] ).GetBuffer( 4 ) ) ) && ( 0 < strCircle.Find( itoStr( iMostCircle[1] ).GetBuffer( 4 ) ) )
			&& ( 0 < strCircle.Find( itoStr( iMostCircle[2] ).GetBuffer( 4 ) ) ) && ( 0 < strCircle.Find( itoStr( iMostCircle[3] ).GetBuffer( 4 ) ) ) )
		{
			strMaxCircle = strCircle;
			return TRUE;
		}

	}

	// 如果此环为最大环，那么没必要进行下面的操作了，直接返回
	if( strCircle == strMaxCircle )
	{
		return TRUE;
	}

	for( vector< CString >::const_iterator GatherIt = JunPointGather.begin(); GatherIt != JunPointGather.end(); GatherIt++ )
	{
		if( *GatherIt == strCircle)
		{
			return TRUE;
		}
	}
	
	// 如果此环节点信息没在JunPointGather中， 即这个环没暂时没有重复环
    JunPointGather.push_back( strCircle );
	
	return FALSE;
}


bool CPFAOptimize::InsertCircleMatrix( const int& iKeyOfCircle, const int& iProperty, ComMap& ComponentKeyMap, PFAOptimitationData& OptData )
{
	ComMap::iterator ConstComIt = ComponentKeyMap.begin();
	int iPosition = 0;
	for( ; ConstComIt != ComponentKeyMap.end(); ConstComIt++ )
	{
		if( !OptData.SetProperty( iKeyOfCircle, iProperty, iPosition, *ConstComIt ) )
		{
			return false;
		}
		iPosition++;
	}
	return true;
}

void CPFAOptimize::JunSystemTransformCircleSystem( ComponentManager& ComManager, PFAOptimitationData& OptData )
{
	//
	ASSERT( NULL != &ComManager );
	vector< CString > JunPointGather;                       // 用来存放环的节点信息， 节点编号已经按从小到大排列好了
	                                                        // 作用是用来找出最大环
	BOOL bMaxCircle = FALSE;                                // 最大环是否找到。FALSE：没有找到
	Pipe* pPipe = NULL;
	Component* pPipeComponent = NULL;
	ComMap JunKeyMap;                                       // 环的节点信息
	ComMap PipeKeyMap;                                      // 环的管道信息
	IteratorPtr<Component> PipeItPtr( ComManager.CreatPipeIterator() );
	int iKeyOfCircle = 0;                                  // 环的编号,环编号是从1开始编
	int iMostCircle[4] = { 0, 0, 0, 0 };
	CString  strMaxCircle;
	for( PipeItPtr->Fist(); !PipeItPtr->IsDone(); PipeItPtr->Next() )
	{
		pPipeComponent = &PipeItPtr->CurrentItem();
		pPipe = dynamic_cast<Pipe*>( pPipeComponent );	
		
		// 顺时针的基环
		JunKeyMap.clear();
		PipeKeyMap.clear();
		ASSERT( FindBaseCircle( ComManager, *pPipe, DEASIL_DIRECTION, JunKeyMap, PipeKeyMap, iMostCircle ) );
        bMaxCircle = JudgeMaxCircle( JunKeyMap, iMostCircle, JunPointGather, strMaxCircle );
		if( bMaxCircle == FALSE )     // 最大环没有找到  
		{
			iKeyOfCircle++;
			InsertCircleMatrix( iKeyOfCircle, 101, JunKeyMap, OptData );
			InsertCircleMatrix( iKeyOfCircle, 100, PipeKeyMap, OptData );

		}

		// 逆时针的基环
		JunKeyMap.clear();
		PipeKeyMap.clear();
		ASSERT( FindBaseCircle( ComManager, *pPipe, ANTICLOCKWISE_DIRECTION, JunKeyMap, PipeKeyMap, iMostCircle ) );
        bMaxCircle = JudgeMaxCircle( JunKeyMap, iMostCircle, JunPointGather, strMaxCircle );
        if( bMaxCircle == FALSE )                   // 最大环没有找到
		{
			iKeyOfCircle++;
			InsertCircleMatrix( iKeyOfCircle, 101, JunKeyMap, OptData );
			InsertCircleMatrix( iKeyOfCircle, 100, PipeKeyMap, OptData );
		}
	}	
}


void CPFAOptimize::DisplayMatrix( const CString& strFileDirectory, const int& iProperty, PFAOptimitationData& OptData )
{
	ofstream fout( strFileDirectory );
	if( !fout )
	{
		return;
	}
	for( int i = 1; i <= OptData.GetPropertyCount( iProperty ); i++ )
	{
		// MatrixDisplay里环是从0开始编号，显示的时候从1开始编号
		fout<< "\n====================\n" <<"环编号："<< i <<"\n";

		int iPosition = 0;
		int iKeyOfCom = 0;
		int iTempCirKey = 0;
		if( !OptData.GetProperty( i, iProperty, 0, iKeyOfCom ) )          // 获取指定行指定列属性失败 
		{
			return;
		}
		else
		{
			fout<< iKeyOfCom; 
		}
		for( int j = 1; j< OptData.GetPropertyCount( i, iProperty ); j++ )
		{	
			if( !OptData.GetProperty( i, iProperty, j, iKeyOfCom ) )          // 获取指定行指定列属性失败 
			{
				return;
			}
			else
			{
				fout<< "=>" << abs( iKeyOfCom );
			}
		}
		fout<< "\n";
	}
	fout.close();
}


bool CPFAOptimize::CalPipeCloseSubtract( ComponentManager& ComManager, PFAOptimitationData& OptData, map< int, double >& OptimitationParameterMap, map< int, double >& OptimitationAssistantMap )
{
	//
	ASSERT( NULL != &ComManager );
	ASSERT( NULL != &OptData );

	double dTemp = 0.0;
	double dTempDummyFlux = 0.0;
	double dTempFactFlux = 0.0;
	double dTempLength = 0.0;
	Pipe* pPipe = NULL;
	Component* pPipeComponent = NULL; 
	map< int, double >::iterator IntDouMap;
	IteratorPtr<Component> PipeItPtr( ComManager.CreatPipeIterator() );
	for( PipeItPtr->Fist(); !PipeItPtr->IsDone(); PipeItPtr->Next() )
	{
		pPipeComponent = &PipeItPtr->CurrentItem();
		pPipe = dynamic_cast<Pipe*>( pPipeComponent );
		
		// 管道的属性：管道虚流量、管道流量和管道长度，如果其中有一个属性不存在
		if( !OptData.GetProperty( pPipe->GetKey(), 1, dTempFactFlux ) || !OptData.GetProperty( pPipe->GetKey(), 2, dTempLength) 
			|| !OptData.GetProperty( pPipe->GetKey(), 0, dTempDummyFlux ) )
		{
			return false;
		}
		
		// 每根管道的计算参数，都取绝对值是为了避免pow出现错误
		dTemp = pow( ( dTempFactFlux ), 2.0 * OptData.GetAlfaModulus() / ( OptData.GetAlfaModulus() + OptData.GetMModulus() ) )
			* fabs( dTempLength ) 
			* pow( ( dTempDummyFlux ), -1.0 * OptData.GetMModulus() / ( OptData.GetAlfaModulus() + OptData.GetMModulus() ) );
		dTemp = fabs( dTemp );
		IntDouMap = OptimitationParameterMap.find( pPipe->GetKey() );
		if( OptimitationParameterMap.end() == IntDouMap )
		{
			OptimitationParameterMap.insert( map< int, double >::value_type( pPipe->GetKey(), dTemp ) );
		}
		else
		{
			IntDouMap->second = dTemp;
		}
		
		// 就最后虚流量的指数不同
		dTemp /= dTempDummyFlux;
		IntDouMap = OptimitationAssistantMap.find( pPipe->GetKey() );
		if( OptimitationAssistantMap.end() == IntDouMap )
		{
			OptimitationAssistantMap.insert( map< int, double >::value_type( pPipe->GetKey(), dTemp ) );
		}
		else
		{
			IntDouMap->second = dTemp;
		}
	}
	return true;
}





bool CPFAOptimize::InitializePipeCircle( PFAOptimitationData& OptData )
{
	// i:环号，j：环中管道的位置
	for( int i = 1; i <= OptData.GetPropertyCount( 100 ); i++ )
	{
		int iPosition = 0;
		int iKeyOfPipe = 0;
		int iTempCirKey = 0;
		for( int j = 0; j< OptData.GetPropertyCount( i, 100 ); j++ )
		{
			if( !OptData.GetProperty( i, 100, j, iKeyOfPipe ) )          // 获取指定行指定列属性失败 
			{
				return false;
			}

			// 设定环的正负，用来表示管道与环的方向是否相反
			iTempCirKey = iKeyOfPipe > 0 ? i : -i;

			iPosition = OptData.GetPropertyCount( iKeyOfPipe, 102 );
			if( !OptData.SetProperty( iKeyOfPipe, 102, iPosition, iTempCirKey ) )  // 设置指定行指定列值失败 
			{
				return false;
			}
		}
	}
	return true;
}



bool CPFAOptimize::CalOthersVariable( ComponentManager& ComManager, PFAOptimitationData& OptData )
{
	int i = 0;
	int iKeyOfPipe = 0;
	double dTemp = 0.0;
	double dTempFactFlux = 0.0;
	double dTempLength = 0.0;
	double dTempDiameter = 0.0;
	double dTempWaterHammer = 0.0;
	double dTempJunWater = 0.0;               // 节点水头
	double dA = 0.0;
	double dB = 0.0;
	double dAlfa = 0.0;
	double dDisinvestmentTime = 0.0;
	double dRepairModulus = 0.0;
	double dWorkExpenditure = 0.0;
	double dKModulus = 0.0; 
	double dMModulus = 0.0;
	double dNModulus = 0.0; 
	double dFluxSummation = 0.0;
	double dYConvertExpenditure = 0.0;          // 年折算费用
	vector< int > JunToJunPipePath;
	dA = OptData.GetAModulus();
	dB = OptData.GetBModulus();
	dAlfa = OptData.GetAlfaModulus();
	dKModulus = OptData.GetKModulus();
	dMModulus = OptData.GetMModulus();
	dNModulus = OptData.GetNModulus();

	// 计算平差后的水头损失 
	dTemp = 0.0;
	for( i = 0; i < OptData.GetPropertyCount( 102 ); i++ )
	{
		OptData.GetProperty( i, 102, iKeyOfPipe );
		OptData.GetProperty( iKeyOfPipe, 1, dTempFactFlux );
		OptData.GetProperty( iKeyOfPipe, 2, dTempLength );
		OptData.GetProperty( iKeyOfPipe, 4, dTempDiameter );
		dTempWaterHammer = dKModulus * pow( fabs( dTempFactFlux ), dNModulus ) * dTempLength / pow( fabs( dTempDiameter ), dMModulus );
	    OptData.SetProperty( iKeyOfPipe, 5, dTempWaterHammer );

		// 为计算建造费用作准备
		dTemp = dTemp + ( dA + dB * pow( fabs( dTempDiameter ), dAlfa ) ) * dTempLength;
	}

	// 计算建造费用
	dRepairModulus = OptData.GetRepairModulus();
	dDisinvestmentTime = OptData.GetDisinvestmentTime();
	dYConvertExpenditure = ( dRepairModulus / 100 + 1 / dDisinvestmentTime ) * dTemp;
	OptData.SetConstructExpenditure( dYConvertExpenditure );

	// 计算节点水头
	Jun* pJun = NULL;
	Component *pComponent = NULL;
	int iKeyOfControlJun = 0;
	int iCountControlJun = OptData.GetPropertyCount( 201 );
	if( 0 == iCountControlJun )                                         // 控制点数不能为0
	{
		return false;
	}
	OptData.GetProperty( 0, 201, iKeyOfControlJun );                    // 选取控制点集合中的第一个
	double dControlJunWater = 0.0;
    OptData.GetProperty( iKeyOfControlJun, 6, dControlJunWater );       // 获取控制点水头
	vector< int >::iterator IntVecIt;
	IteratorPtr< Component > JunitPtr( ComManager.CreatJunIterator() );
	for( JunitPtr->Fist(); !JunitPtr->IsDone(); JunitPtr->Next() )      // 遍历所有节点
	{
		pComponent = &( JunitPtr->CurrentItem() );
		pJun = dynamic_cast< Jun* > (pComponent);
		JunToJunPipePath.clear();
		FindShortCut( ComManager, pJun->GetKey(), iKeyOfControlJun, JunToJunPipePath ); 
		IntVecIt = JunToJunPipePath.begin();
		dTemp = 0.0;
		for( ; JunToJunPipePath.end() != IntVecIt; IntVecIt++ )
		{
			i = *IntVecIt > 0 ? 1 : -1;
			OptData.GetProperty( abs( *IntVecIt), 5, dTempWaterHammer );
			dTemp = dTemp + i * dTempWaterHammer;                        // 计算节点到控制点的总的水头损失
		}
		dTemp += dTempJunWater;                                          // 节点的水头
		OptData.SetProperty( pJun->GetKey(), 6, dTemp );
	}

	// 计算年运营费用
	dWorkExpenditure = OptData.GetWorkExpenditure();
	dFluxSummation = OptData.GetFluxSummation();
	int iCountSupplyJun = OptData.GetPropertyCount( 200 );
	if( ( 0 == iCountSupplyJun ) || ( 0 == iCountControlJun ) )          // 配水源或控制点没定义
	{
		return false;
	}
	if( 0 > fabs( dWorkExpenditure - 1e-6 ) )                            // 管网是重力流管网
	{
		OptData.SetYConvertExpenditure( dYConvertExpenditure );
		return true;
	}
	iKeyOfControlJun = 0;
	int iKeyOfSupplyJun = 0;
	OptData.GetProperty( 0, 201, iKeyOfControlJun );                      // 选取第一个控制点为我们所要的点
	dTemp = 0.0;
	for( i = 0; i < iCountSupplyJun; i++ )
	{
		OptData.GetProperty( i, 200, iKeyOfSupplyJun );                   //  获取第i个配水源节点编号

		// 找到从配水源到控制点的最短路径，并放入JunToJunPipePath中
		JunToJunPipePath.clear();
		FindShortCut( ComManager, iKeyOfSupplyJun, iKeyOfControlJun, JunToJunPipePath ); 

		IntVecIt = JunToJunPipePath.begin();
		for( ; JunToJunPipePath.end() != IntVecIt; IntVecIt++ )
		{
			OptData.GetProperty( abs( *IntVecIt ), 5, dTempWaterHammer );
			dTemp += dTempWaterHammer;                                     // 计算配水源到控制点的总水头损失
		}
		OptData.GetProperty( iKeyOfControlJun, 6, dTempJunWater );         // 获取控制点水头
		dTemp +=  dTempJunWater;                                           // 配水源的水头
	}
	dTemp = dTemp * dWorkExpenditure * dFluxSummation;                     // 年运营费用

	// 年折算费用
	dYConvertExpenditure += dTemp;                                         // 年折算费用 = 建造费用 + 年运营费用
	OptData.SetYConvertExpenditure( dYConvertExpenditure );
	
	return true;
}


// 最短路径,Dijkstra算法，网上抄的， 可能有点乱
bool CPFAOptimize::FindShortCut( ComponentManager& ComManager, const int& iKeyOfStartJun, const int& iKeyOfEndJun, vector< int >& JunToJunPipePath )
{
	map< int, vector< int > > AbutMatrix;           //图的邻接矩
	vector< int > MarkVector;                       //标记数组
	vector< int > DistanceVector;                   //距离数组
	vector< int > TempVector;                       //前缀节点
	vector< int > PipePathVector;                   //临时路径存放数组
	int iCountOfJun = ComManager.GetJunNum();
	int iCountOfPipe = ComManager.GetPipeNum();
	int iTemp = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int iMinDistance = 0;

	//读入数据
	Component *pComponent = NULL;
	Pipe *pPipe = NULL;
	int iStartJun = 0;
	int iEndJun = 0;
	IteratorPtr<Component> PipeItPtr( ComManager.CreatPipeIterator() );
	for( PipeItPtr->Fist(); !PipeItPtr->IsDone(); PipeItPtr->Next() )
    {
		pComponent = &PipeItPtr->CurrentItem();
	    pPipe = dynamic_cast<Pipe*>(pComponent);
		iStartJun = pPipe->StartJun();
		iEndJun = pPipe->EndJun();
		SetProperties( AbutMatrix, iStartJun, iEndJun, 1 );
		SetProperties( AbutMatrix, iEndJun, iStartJun, 1);
	}
	
    //赋初值	
	for( i = 1; i <= iCountOfJun; i++ )
	{
		MarkVector.push_back( 0 );
		TempVector.push_back( 0 );
	}
	SetProperties( MarkVector, iKeyOfStartJun, 1 );
	SetProperties( TempVector, iKeyOfStartJun, 0 );
	for( i = 1; i <= iCountOfJun; i++ )
	{
		iTemp = GetProperties( AbutMatrix, 1, i );
		SetProperties( DistanceVector, i, iTemp );
		if( 0 < iTemp )
		{
			SetProperties( TempVector, i, 1 );
		}
	}

    //Dijkstra
	for( i = 0; i <= iCountOfJun; i++ )
	{
		//找到没有标号的最小dist下标
		iMinDistance = 32000;
		k = 0;
		for( j = 1; j <= iCountOfJun; j++ )
		{
			if( ( 0 == GetProperties( MarkVector, j ) ) && ( 0 < GetProperties( DistanceVector, j ) )
				&& ( iMinDistance > GetProperties( DistanceVector, j ) ) )
			{
				k = j;
				iMinDistance = GetProperties( DistanceVector, j );
			}
		}
		if( 0 == k )                                           //如果找不到就直接退出
		{
			break;
		}
		SetProperties( MarkVector, k, 1 );                      //标记

        //修改最短值和路径
		for( j = 1; j <= iCountOfJun; j++ )
		{
			if( ( 0 == GetProperties( MarkVector, j ) ) && ( 0 < GetProperties( AbutMatrix, k, j ) )
				&& ( ( 0 == GetProperties( DistanceVector, j ) ) 
				|| ( GetProperties( DistanceVector, k ) + GetProperties( AbutMatrix, k, j ) < GetProperties( DistanceVector, j ) ) ) )
			{
				iTemp = GetProperties( DistanceVector, k ) + GetProperties( AbutMatrix, k, j );
				SetProperties( DistanceVector, j, iTemp );
				SetProperties( TempVector, j, k );
			}
		}
	}
	
    //输出值和路径
	k = iKeyOfEndJun;
	i = 0;
	while( 0 < GetProperties( TempVector, k ) )
	{
		SetProperties( PipePathVector, i++, k );
		k = GetProperties( PipePathVector, k );
	}
	SetProperties( PipePathVector, i, 1 );

	// 根据节点把管道编号写进里，负号表示管道方向与前进方向相反
	JunToJunPipePath.clear();
	vector< int >::iterator IntVecIt = PipePathVector.begin();
	iStartJun = *IntVecIt;
	IntVecIt++;
	for( ; PipePathVector.end() != IntVecIt; IntVecIt++ )
	{
		iEndJun = *IntVecIt;
		for( PipeItPtr->Fist(); !PipeItPtr->IsDone(); PipeItPtr->Next() )
		{
			pComponent = &PipeItPtr->CurrentItem();
	        pPipe = dynamic_cast<Pipe*>(pComponent);
			if( ( pPipe->StartJun() == iStartJun ) && ( pPipe->EndJun() == iEndJun ) )
			{
				JunToJunPipePath.push_back( pPipe->GetKey() );
				break;
			}
			if( ( pPipe->StartJun() == iEndJun ) && ( pPipe->EndJun() == iStartJun ) )
			{
				JunToJunPipePath.push_back( -1 * pPipe->GetKey() );
				break;
			}
		}
		iStartJun = iEndJun;
	}
	return true;
}

bool CPFAOptimize::SetProperties( vector< int >& IntVector, const int& iPosition, const int& iValue )
{
	ASSERT( NULL != &IntVector );
	vector< int >::iterator IntVecIt = IntVector.begin();
	vector< int >::iterator IntVecNextIt = IntVecIt;
	IntVecNextIt++;
	for( int i = 1; i < iPosition; i++ )             // iPosition是从1开始编号的，不是从0开始
	{	
		if( IntVector.end() == IntVecNextIt )
		{
			IntVector.push_back( 0 );
			IntVecNextIt = IntVecIt;
			IntVecNextIt++;
			continue;
		}
		IntVecIt++;
		IntVecNextIt++;
	}
	if( 0 == IntVector.size() )
	{
		IntVector.push_back( iValue );
	}
	else
	{
		*IntVecIt = iValue;
	}	
	return true;
}

int CPFAOptimize::GetProperties( const vector< int >& IntVector, const int& iPosition )
{
	vector< int >::const_iterator IntVecIt = IntVector.begin();
	for( int i = 1; i < iPosition; i++ ) 
	{
		if ( IntVector.end() == IntVecIt )
		{
			return 0;
		}
		IntVecIt++;
	}
	return *IntVecIt;
}

bool CPFAOptimize::SetProperties( map< int, vector< int > >& IntVecMap, const int& iRow, const int& iLine, const int& iValue )
{
	map< int, vector< int > >::iterator IntVecMapIt = IntVecMap.find( iRow );
	if( IntVecMap.end() == IntVecMapIt )
	{
		vector< int > TempVector;
		for( int i = 1; i < iLine; i++ )
		{
			TempVector.push_back( 0 );
		}
		IntVecMap.insert( map< int, vector< int > >::value_type( iRow, TempVector ) );
		return true;
	}
	return SetProperties( IntVecMapIt->second, iLine, iValue );
}

int CPFAOptimize::GetProperties( const map< int, vector< int > >& IntVecMap, const int& iRow, const int& iLine )
{
	map< int, vector< int > >::const_iterator IntVecMapIt = IntVecMap.find( iRow );
	if( IntVecMap.end() == IntVecMapIt )
	{
		return 0;
	}
	return GetProperties( IntVecMapIt->second, iLine );
}



// 牛顿迭代法解柯尔勃洛克-魏特公式，注意没有详细讨论，可能出现不收敛的情况
bool CPFAOptimize::ColebrookNewton( const double& dAbsoluteRoughness, const double& dDiameter, const double& dRe, double& dResult )
{
	int iIterativeTime = 0;                                    // 迭代次数
	double dXFirst = 1.0;                                      // 初始值设置为1.0
	double dTemp = 0.0;
	double dX = 0.0;
	while( 5000 > iIterativeTime )                             // 迭代次数不能超过5000
	{
		double dTemp = dAbsoluteRoughness / ( 3.76 * dDiameter ) + 2.51 / ( dRe * dXFirst );
		double dFirst = pow( fabs( -2 * log( fabs( dTemp ) ) ), -2 );
		double dSecond = -2 * pow( -2 * log10( dTemp ), -3 ) 
			* ( -2 ) * log( 10 ) / dTemp
			* 2.51 * ( -0.5 ) * pow( dXFirst, -1.5 ) / dRe;    // 偏导数
		if( 0 > fabs( dSecond - 1e-6 ) )                       // 分母不能为0
		{
			return false;
		}
		dX = dXFirst - dFirst / dSecond;
		if( 0.0001 > fabs( dX - dXFirst ) )                     // 满足精度要求：0.0001
		{
			dResult = dX;
			return true;
		}
		dXFirst = dX;
		iIterativeTime++;
	}
	return false;                                               // 超过迭代次数
}


bool CPFAOptimize::DiameterIsEqual( PFAOptimitationData& OptData, map< int, double >& BeforeDiameterMap )
{
	double dTempDiameter = 0.0;
	int iKeyOfPipe = 0;
	bool bFlag = true;
	if( 0 == BeforeDiameterMap.size() )                      // 第一次
	{
		for( int i = 0; i < OptData.GetPropertyCount( 102 ); i++ )  // 遍历所有管道
		{
			OptData.GetProperty( i, 102, iKeyOfPipe );
			OptData.GetProperty( iKeyOfPipe, 4, dTempDiameter );
			BeforeDiameterMap.insert( map< int, double >::value_type( iKeyOfPipe, dTempDiameter ) );
		}
		bFlag = true;
	}
	else                                                    // 非第一次
	{
		map< int, double >::iterator IntDouMapIt;
		for( int i = 0; i < OptData.GetPropertyCount( 102 ); i++ )
		{
			OptData.GetProperty( i, 102, iKeyOfPipe );
			OptData.GetProperty( iKeyOfPipe, 4, dTempDiameter );
			IntDouMapIt = BeforeDiameterMap.find( iKeyOfPipe );
			if( 0 < fabs( IntDouMapIt->second - dTempDiameter) )    // 计算出来的标准管径和上次计算的不同
			{
				IntDouMapIt->second = dTempDiameter;                // 把这次计算出来的标准管径放入BeforeDiameterMap
				return false;
			}
		}
	}
	return bFlag;
}

void CPFAOptimize::Example()
{
	
	CMainFrame* pMainFrame = NULL; 
	pMainFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CChildFrame* pChildFrame = NULL;
	pChildFrame = (CChildFrame*)pMainFrame->GetActiveFrame();
	CAutoPFAView* pAutoView = NULL;
	pAutoView = (CAutoPFAView*)pChildFrame->GetActiveView();
	ComponentManager* pComManager = pAutoView->GetDocument()->m_scenarioManager.GetCurScenario()->GetCompManager();
	ComponentManager ComManager( *pComManager );

	// 先手动设置配水源和控制点
	int iTemp = 1;
	OptData.SetProperty( 0, 200, iTemp );          // 节点1为配水源
	iTemp = 23;
	OptData.SetProperty( 0, 201, iTemp );         // 节点12为控制点

	// 对ComManager进行处理
	//DisposeManager( OptData, ComManager );

	JunSystemTransformCircleSystem( ComManager, OptData );
	DisplayMatrix( "F://CirPipe.txt", 100, OptData );
	InitializePipeCircle( OptData );
	DisplayMatrix( "F://Pipe.txt", 102, OptData );

	// 从pComManager中初始化OptData的 初始实际流量，管道长度，节点流量，配水源，控制点，
	CMinimumSquareSum MinSquSum;

	//MinSquSum.InitializeFactFlux( *pComManager, OptData );   //  初始实际流量
	///////////////////////////////////////
	int i = 0;
	int iKeyOfPipe = 0;
	double Temp = 0.0;
	double dTemp = 0.0;
	Pipe* pPipe = NULL;
	Component* pComponent = NULL; 


	// 设置直径
	IteratorPtr<Component> PipeItPtr( ComManager.CreatPipeIterator() );
	for( PipeItPtr->Fist(); !PipeItPtr->IsDone(); PipeItPtr->Next() )
	{
		pComponent = &PipeItPtr->CurrentItem();
	    pPipe = dynamic_cast<Pipe*>( pComponent );
		dTemp = pPipe->Len();
		OptData.SetProperty( pPipe->GetKey(), 2, dTemp );    
		dTemp = pPipe->InDia();
		OptData.SetProperty( pPipe->GetKey(), 4, dTemp );
	}

	// 节点流量
	QuantityManager& qm = QuantityManager::Instance();
	CString strUnit = "";
	CString strValue = "";
	Jun* pJun = NULL;
	Branch* pBranch = NULL;
	IteratorPtr<Component> JunItPtr( ComManager.CreatJunIterator() );
	for( JunItPtr->Fist(); !JunItPtr->IsDone(); JunItPtr->Next() )
	{
		pComponent = &JunItPtr->CurrentItem();
	    pJun = dynamic_cast<Jun*>( pComponent );
		pBranch = dynamic_cast<Branch*>( pComponent );
		//pJun->GetValue(24)->GetValue( strUnit,strValue);                            // 获得单位
		strValue = pBranch->ms_ImposeFlow.GetValue( 1 );
		TCHAR* pChar = NULL;
		qm.TransformToStd( dTemp, strUnit.GetBuffer( 32 ), _tcstod( strValue.GetBuffer( 32 ), &pChar ) ); // 转化成标准单位
		int iType = pBranch->ms_ImposeFlow.GetnValue();
		if( 0 !=  iType )            // 质量流量，要转化为体积流量
		{
			double dTempDensity = 0.0;
			NumFlyWeight *pDensity = &( ( ComManager.SysProperty().GetFuild() )->ms_Density );
			dTemp *= pDensity->GetNum();                                       // GetNum返回标准单位数
		}
		OptData.SetProperty( pJun->GetKey(), 3, dTemp );
	}

	////////////
	////////////


    // 初始化经济参数
	OptData.SetAModulus( 8.4 );
	OptData.SetBModulus( 107 );
	OptData.SetAlfaModulus( 1.6 );
	OptData.SetDisinvestmentTime( 7.0 );
	OptData.SetRepairModulus( 0.033 );
	OptData.SetEletricityPrice( 0.5 );
	OptData.SetAsymmetryModulus( 0.3 );
	OptData.SetPumpEfficiency( 0.7 );
	OptData.SetKModulus( 1.34e-3 );
	OptData.SetMModulus( 5.3 );
	OptData.SetNModulus( 2 );
	OptData.Initialization();
	OptData.SetEconomyFactor( 1.694 );
	

	////
	Temp = 1.01227;	
	OptData.SetProperty( 1, 3, Temp );
	Temp = -0.12271;	
	OptData.SetProperty( 2, 3, Temp );
	Temp = -0.07552;	
	OptData.SetProperty( 3, 3, Temp );
	Temp = -0.01765;	
	OptData.SetProperty( 4, 3, Temp );
	Temp = -0.01551;	
	OptData.SetProperty( 5, 3, Temp );
	Temp = -0.01139;	
	OptData.SetProperty( 6, 3, Temp );
	Temp = -0.01608;	
	OptData.SetProperty( 7, 3, Temp );
	Temp = -0.02106;	
	OptData.SetProperty( 8, 3, Temp );
	Temp = -0.07901;	
	OptData.SetProperty( 9, 3, Temp );
	Temp = -0.07339;	
	OptData.SetProperty( 10, 3, Temp );
	Temp = -0.04901;	
	OptData.SetProperty( 11, 3, Temp );
	Temp = -0.01680;	
	OptData.SetProperty( 12, 3, Temp );
	Temp = -0.02341;	
	OptData.SetProperty( 13, 3, Temp );
	Temp = -0.01324;	
	OptData.SetProperty( 14, 3, Temp );
	Temp = -0.02064;	
	OptData.SetProperty( 15, 3, Temp );
	Temp = -0.03231;	
	OptData.SetProperty( 16, 3, Temp );
	Temp = -0.02889;	
	OptData.SetProperty( 17, 3, Temp );
	Temp = -0.02178;	
	OptData.SetProperty( 18, 3, Temp );
	Temp = -0.02348;	
	OptData.SetProperty( 19, 3, Temp );
	Temp = -0.06303;	
	OptData.SetProperty( 20, 3, Temp );
	Temp = -0.11953;	
	OptData.SetProperty( 21, 3, Temp );
	Temp = -0.01537;	
	OptData.SetProperty( 22, 3, Temp );
	Temp = -0.15246;	
	OptData.SetProperty( 23, 3, Temp );
	
	//////////////////
	dTemp = 50.0;
	OptData.SetProperty( 1, 7, dTemp );

	// 计算总流量，从流出的流量（流出为负）统计
	double dFluxSummation = 0.0;
	IteratorPtr< Component > JunitPtr( ComManager.CreatJunIterator() );
	for( JunitPtr->Fist(); !JunitPtr->IsDone(); JunitPtr->Next() )      // 遍历所有节点
	{
		pComponent = &( JunitPtr->CurrentItem() );
		pJun = dynamic_cast< Jun* > (pComponent);
		OptData.GetProperty( pJun->GetKey(), 3, dTemp );
		if( 0 > dTemp )             // 为流出节点
		{
			dFluxSummation += dTemp;
		}	
	}
    OptData.SetFluxSummation( fabs( dFluxSummation ) );

	MinSquSum.InitializeDummyFlux( ComManager, OptData );   // 初始虚流量分配用截面法
	MinSquSum.InitializeFactFlux( ComManager, OptData );    // 初始实流量分配用最小平方和法
	m_ProGress.Create( IDD_DLGPROGRESS, ( CWnd* )pAutoView );
	m_ProGress.ShowWindow( SW_SHOW );
	
	if( !DoOptimitation( ComManager, OptData ) )
	{
		return ;
	}

	
	// 计算其他要素
    //CalOthersVariable( *pComManager, OptData );
    

	// 输出结果
	DisplayResult( OptData );
	
}

bool CPFAOptimize::DoOptimitation( ComponentManager& ComManager, PFAOptimitationData& OptData )
{
	double dWaterHammer = 0.0;
	double dTempCloseSubtract = 0.0;      // 用来计算环的校正流量
	double dCloseSubtract = 0.0;          // 环校正流量
	double dPipeDiameter = 0.0;
	double dPipeFactFlux = 0.0;
	double dPipeLength = 0.0;
	double dTemp = 0.0;
	double dFactPrecision = 0.00001;
	bool bFlagFactCloseSubtract = true;
	long lTimes = 0;
	int iKeyOfPipe = 0;
	int i = 0;
	int j = 0;
	int iFlagCircleOver = 0;                        // 如果iFlagCircleOver等于环数，则表示所有环都平差完成
	map< int, double > PipeWaterHammerMap;          // 管道水头损失
	map< int, double > CirReviseValueMap;           // 环校正流量
	map< int, double > PipeTempDiameterMap;         // 上次计算的直径
	lTimes = 0;
	m_ProGress.ProssMove( 1, 0, 0 );                // 父进度条移动0步，从0开始
	do
	{	
		m_ProGress.ProssMove( 0, 0, 0 );            // 子进度条移动0步，从0开始
		long lCount = 0;
		bFlagFactCloseSubtract = true;	
		CalDummyFlux( 0.0001, OptData );
		while ( true )
		{
			lCount++;
			iFlagCircleOver = 0;
			PipeWaterHammerMap.clear();
			CirReviseValueMap.clear();
			for ( i = 1; i <= OptData.GetPropertyCount( 100 ); i++ )         // 遍历所有环
			{
				dWaterHammer = 0.0;                    
				dTempCloseSubtract = 0.0;
				for ( j = 0; j < OptData.GetPropertyCount( i, 100 ); j++ )     // 遍历环中的所有管道
				{
					double dTempOne = 0.0;
					OptData.GetProperty( i, 100, j, iKeyOfPipe );
					OptData.GetProperty( iKeyOfPipe, 4, dPipeDiameter );
					OptData.GetProperty( iKeyOfPipe, 1, dPipeFactFlux );
					OptData.GetProperty( iKeyOfPipe, 2, dPipeLength );
					if( 0.3 < dPipeDiameter )          // 应该是阻力计算公式，但没查到，按管道直径来选择公式
					{
						// 管道水头损失 h = k*q`2*l / d`m
						dTemp = 0.002021 * dPipeLength * dPipeFactFlux * fabs( dPipeFactFlux ) / pow( dPipeDiameter, 5.33 );					  
					}
					else
					{
						dTemp = 0.000915 * dPipeLength * dPipeFactFlux * pow( fabs( dPipeFactFlux ), 0.774 ) / pow( dPipeDiameter, 4.774 );
					}
					if( 1.0e-6 < fabs( dPipeFactFlux - 1.0e-6 ) )    // 判断F是否为0
					{
						// 用来求校正流量的
						dTempCloseSubtract = dTemp / dPipeFactFlux + dTempCloseSubtract;
					}
					else
					{
						dTempCloseSubtract += 1.0;
					}
					
					// 
					PipeWaterHammerMap.insert( map< int, double >::value_type( abs( iKeyOfPipe ), dTemp ) );
					OptData.SetProperty( iKeyOfPipe, 11, dTemp );
					dTemp = ( iKeyOfPipe / abs( iKeyOfPipe ) ) * dTemp;					
					dWaterHammer += dTemp;                           // 环的管道水头损失和	                   		
				}	
				dCloseSubtract = dWaterHammer;                       // 环的闭合差 
				if( dFactPrecision > fabs( dCloseSubtract ) )            // 如果环的水头损失闭合差小于控制精度
				{
					iFlagCircleOver++;   
				}
				dTemp = -1.0 * OptData.GetPumpEfficiency() * dCloseSubtract / dTempCloseSubtract;  // 环的校正流量 = -泵站效率 * 环水头损失 / S
				dTemp *= 0.4;                                                                      // 0.4为松弛因子，0.2-1都可以，用来改善收敛情况
				CirReviseValueMap.insert( map< int, double >::value_type( i, dTemp ) ); 
			}
        
			if( 1 == ( iFlagCircleOver / OptData.GetPropertyCount( 101 ) ) )               // 所有的环都平差完成  
			{
				break;
			}

			// 修正管道流量
			int iKeyOfCir = 1;
			int iTempCir = 0;
			map< int, int > FinishPipeKeyMap;
			for ( i = 1; i <= OptData.GetPropertyCount( 100 ); i++, iKeyOfCir++ )  // 遍历所有环
			{
				dTemp = 0.0;
				for( j = 0; j < OptData.GetPropertyCount( i, 100 ); j++ )
				{
					long lMaxCirCount = 0;
					if( !OptData.GetProperty( iKeyOfCir, 100, j, iKeyOfPipe ) )
					{
						iKeyOfCir++;
						lMaxCirCount++;
						if( 5000 < lMaxCirCount )
						{
							return false;
						}
					}
					
					// 判断是否计算过
					if( FinishPipeKeyMap.end() != FinishPipeKeyMap.find( abs( iKeyOfPipe ) ) )
					{
						continue;
					}
					else
					{
						FinishPipeKeyMap.insert( map< int, int >::value_type( abs( iKeyOfPipe ), i ) );
					}

					OptData.GetProperty( iKeyOfPipe, 1, dPipeFactFlux );				
					dPipeFactFlux = ( iKeyOfPipe / abs( iKeyOfPipe ) ) * dPipeFactFlux;
					for( int k = 0; k < OptData.GetPropertyCount( iKeyOfPipe, 102 ); k++ )
					{
						if( !OptData.GetProperty( iKeyOfPipe, 102, k, iTempCir ) )
						{
							break;
						}
						
						map< int, double >::iterator IntDouMapIt = CirReviseValueMap.find( abs( iTempCir ) );
						if( CirReviseValueMap.end() == IntDouMapIt )
						{
							return false;                       // 环没有对应的修正流量
						}
						else
						{
							dTemp = IntDouMapIt->second;
						}
						
						if( abs( iTempCir ) == iKeyOfCir )
						{
							dPipeFactFlux += dTemp;
						}
						else
						{
							dPipeFactFlux -= dTemp;
						}
					}
					dPipeFactFlux = ( iKeyOfPipe / abs( iKeyOfPipe ) ) * dPipeFactFlux;
				    OptData.SetProperty( iKeyOfPipe, 1, dPipeFactFlux );
				}
			}

			m_ProGress.ProssMove( 0 );              // 子进度条移动1步
			// 如果迭代次数超过5000次仍没有算出来
			if( 5000 < lCount )
			{
				return false;
			}
		}
	
	
		m_ProGress.ProssMove( 0, 0, 10000 );        // 子进度条移动到10000
		// 判断前后2次计算的管径相差是否小于45，
		map< int, double >::iterator IntDouMap;
		int iKeyOfCir = 1;
		bool bFlagInit = 0 < PipeTempDiameterMap.size();       // 是否第一次，fasle的话就是第一次
		for ( i = 1; i <= OptData.GetPropertyCount( 100 ); i++, iKeyOfCir++ )           // 遍历环
		{	
			for ( j = 0; j < OptData.GetPropertyCount( i, 100 ); j++ )   // 遍历环中管道
			{
				long lMaxCirCount = 0;
				if( !OptData.GetProperty( iKeyOfCir, 100, j, iKeyOfPipe ) )
				{
					iKeyOfCir++;
					lMaxCirCount++;
					if( 5000 < lMaxCirCount )
					{
						return false;
					}
				}	
				OptData.GetProperty( iKeyOfPipe, 4, dPipeDiameter );
				if( bFlagInit )
				{
			     	IntDouMap = PipeTempDiameterMap.find( abs( iKeyOfPipe ) );				
			    	double dTempDiameter = IntDouMap->second;				
			    	if( 45.0 < fabs( dTempDiameter - dPipeDiameter ) )
					{
					    bFlagFactCloseSubtract = false;
					}
			    	IntDouMap->second = dPipeDiameter;		
				}
				else
				{
					PipeTempDiameterMap.insert( map< int, double >::value_type( abs( iKeyOfPipe ), dPipeDiameter ) );
					bFlagFactCloseSubtract = false;
				}
			}
		}

		m_ProGress.ProssMove( 1 );             // 父进度条移动1步
		lTimes++;
		if( 5000 < lTimes )
		{
			return false;
		}
	}while( bFlagFactCloseSubtract == false );

	


	// 管道流速
	map< int, vector< int > >* pMap = OptData.GetCirPipeMatrix();
	map< int, vector< int > >::iterator IntVecMapIt = pMap->begin();              
	double dConstructExpense = 0.0;                       // 建造费用 
	
	// 计算建造费用的系数
	double dTempConstruct = ( OptData.GetRepairModulus() + 1.0 / OptData.GetDisinvestmentTime() ) * OptData.GetBModulus();
	for ( ; pMap->end() != IntVecMapIt; IntVecMapIt++ )   // 遍历环
	{
		int iKeyOfCir = IntVecMapIt->first;
		vector< int >::iterator IntVecIt = IntVecMapIt->second.begin();
		for ( ; IntVecMapIt->second.end() != IntVecIt; IntVecIt++ )    // 遍历管道
		{
			OptData.GetProperty( *IntVecIt, 1, dPipeFactFlux );
			OptData.GetProperty( *IntVecIt, 4, dPipeDiameter );
			OptData.GetProperty( *IntVecIt, 2, dPipeLength );
			dTemp = 4.0 * dPipeFactFlux / ( PI * dPipeDiameter * dPipeDiameter );
			OptData.SetProperty( *IntVecIt, 6, dTemp );

			dConstructExpense = dConstructExpense + dPipeDiameter * dPipeLength * dTempConstruct; // 计算建造费用		
		}
	}
	
	/*
	// 计算节点水压
	POINT( 1 )=43.0+8;          // 第1节点的绝对水压,应该是指配水源
	for ( i = 0; i < OptData.GetPropertyCount( 101 ); i++ )     // 遍历环
	{
		HH=POINT( KL( I, 1 ) );     // HH = 第I环第1个节点水压
		for ( J = 1; J < LOTN( 1 ); J++ )  // 从环的第2个节点开始遍历
		{
			K=KL( I, J );                // K = 第I环第J个节点编号
			HH=HH-H( I, J-1 );           // HH = 第I环第J个节点的水压
			POINT( K )=HH;               // 设置编号为K（即第I环第J个节点）的节点的绝对水压
			KJ( K )=K;                   // 标记K节点 
		}
	}
	
	// 把节点的绝对水压转成相对水压 
	for ( I = 0; I < 23; I++ )   // 遍历所有节点，节点数总共23个
	{
		if( KJ( I )==0 )
		{
			WRITE( *, * );
		}
		HCP( I )=POINT( I )-BIAO( I );       // 设置I节点的相对水压
	}	

  
	*/
	dTemp = 0.0;
	double dYConvertExpenditure = 0.0;
	double dWorkExpenditure = OptData.GetWorkExpenditure();
	double dFluxSummation = OptData.GetFluxSummation();
	double dK = OptData.GetKModulus();
	double dAlfa = OptData.GetAlfaModulus();
	double dM = OptData.GetMModulus();
	double dN = OptData.GetNModulus();
	int iCountSupplyJun = OptData.GetPropertyCount( 200 );
	int iCountControlJun = OptData.GetPropertyCount( 201 );
	vector< int > JunToJunPipePath;
	vector< int >::iterator IntVecIt;

	// 管网建造费用
	CirMatrix* pCirMatrix = OptData.GetPipeCirMatrix();
	IntVecMapIt = pCirMatrix->begin();

	if( ( 0 == iCountSupplyJun ) || ( 0 == iCountControlJun ) )          // 配水源或控制点没定义
	{
		return false;
	}

	dYConvertExpenditure = dConstructExpense;
	if( 0 > fabs( dWorkExpenditure - 1e-6 ) )                            // 管网是重力流管网
	{
		OptData.SetYConvertExpenditure( dYConvertExpenditure );
		return true;
	}

	int iKeyOfControlJun = 0;
	int iKeyOfSupplyJun = 0;
	double dPipeDummyWaterHammer = 0.0;
	double dJunWater = 0.0;
	double dJunFlux = 0.0;
	double dTempWork = 0.0;
	OptData.GetProperty( 0, 201, iKeyOfControlJun );                      // 选取第一个控制点为我们所要的点
	dTemp = 0.0;
	for( i = 0; i < iCountSupplyJun; i++ )
	{
		OptData.GetProperty( i, 200, iKeyOfSupplyJun );                   //  获取第i个配水源节点编号
			
		// 找到从配水源到控制点的最短路径，并放入JunToJunPipePath中
		JunToJunPipePath.clear();
		//FindShortCut( ComManager, iKeyOfSupplyJun, iKeyOfControlJun, JunToJunPipePath ); 	
		/////////////
		JunToJunPipePath.push_back( 3 );
		JunToJunPipePath.push_back( 6 );
		JunToJunPipePath.push_back( 9 );
		JunToJunPipePath.push_back( 12 );
		////////////////////////
		IntVecIt = JunToJunPipePath.begin();
		for( ; JunToJunPipePath.end() != IntVecIt; IntVecIt++ )
		{
			OptData.GetProperty( abs( *IntVecIt ), 10, dPipeDummyWaterHammer );
			dPipeDummyWaterHammer = ( *IntVecIt / abs( *IntVecIt ) ) * dPipeDummyWaterHammer;
			dTemp += dPipeDummyWaterHammer;                                     // 计算配水源到控制点的总水头损失
		}
		dPipeDummyWaterHammer = dTemp;                                     // dPipeDummyWaterHammer为配水源到控制点的虚水头损失
		
		OptData.GetProperty( iKeyOfSupplyJun, 7, dJunWater );             // 获取配水源水头
		OptData.GetProperty( iKeyOfSupplyJun, 3, dJunFlux );               // 获取配水源节点流量
		if( ( 1e-6 > fabs( dJunWater - 1e-6 ) ) || ( 1e-6 > fabs( dJunFlux - 1e-6 ) ) )
		{
			return false;
		}
		dWorkExpenditure = pow( dK * dPipeDummyWaterHammer / dJunWater, 1.0 / ( dAlfa + dM ) ) / dJunFlux;
		dTempWork = dTempWork + dTemp * dWorkExpenditure * fabs( dJunFlux ); // 年运营费用
	}
                 
		
	// 年折算费用
	dYConvertExpenditure += dTempWork;                                         // 年折算费用 = 建造费用 + 年运营费用
	OptData.SetYConvertExpenditure( dYConvertExpenditure );
	
    return true;
	
}


bool CPFAOptimize::CalDummyFlux( const double& dDummyPrecision, PFAOptimitationData& OptData )
{
	long lTimes = 0;
	int i = 0;
	int j = 0;
	int iFlagCircleOver = 0; // 如果iFlagCircleOver等于环数，则表示所有环都平差完成
	//////////////////////////////////////////////////////////////////////////
	double dWaterHammer = 0.0;
	double dTempCloseSubtract = 0.0;      // 用来计算环的校正流量
	double dCloseSubtract = 0.0;          // 环校正流量
	double dPipeDiameter = 0.0;
	double dPipeDummyFlux = 0.0;
	double dPipeLength = 0.0;
	double dPipeFactFlux = 0.0;
	double dTemp = 0.0;
	double dM = OptData.GetMModulus();
	double dAlfa = OptData.GetAlfaModulus();
	double dN = OptData.GetNModulus();
	bool bFlagDummyCloseSubtract = false;
	int iKeyOfPipe = 0;
	map< int, double > PipeDummyWaterHammerMap; // 管道水头损失
	map< int, double > CirCloseSubtract;
	map< int, double > CirReviseValueMap;      // 环校正流量
	map< int, double > PipeTempDiameterMap;      // 上次计算的直径
	/////////////////
	while( false == bFlagDummyCloseSubtract )
	{
		bFlagDummyCloseSubtract = false;
		iFlagCircleOver = 0; 
		lTimes++;
		PipeDummyWaterHammerMap.clear();
		CirCloseSubtract.clear();
		CirReviseValueMap.clear();
		for ( i = 1; i <= OptData.GetPropertyCount( 100 ); i++ )  // 遍历环
		{
			dCloseSubtract = 0.0;
			dTempCloseSubtract = 0.0;
			for ( j = 0; j < OptData.GetPropertyCount( i, 100 ); j++ )  // 遍历环中所有管道
			{
				OptData.GetProperty( i, 100, j, iKeyOfPipe );
				OptData.GetProperty( iKeyOfPipe, 0, dPipeDummyFlux );
				dTemp = ( dPipeDummyFlux / fabs( dPipeDummyFlux ) ) * pow( 1.0 / fabs( dPipeDummyFlux ), dM / ( dAlfa + dM ) );
				OptData.GetProperty( iKeyOfPipe, 1, dPipeFactFlux );
				OptData.GetProperty( iKeyOfPipe, 2, dPipeLength );
				dTemp = pow( fabs( dPipeFactFlux ), dN * dAlfa / ( dAlfa + dM ) ) * dPipeLength * dTemp;// 虚流量水头损失,单位米 
				PipeDummyWaterHammerMap.insert( map< int, double >::value_type( abs( iKeyOfPipe ), dTemp ) );  
				OptData.SetProperty( iKeyOfPipe, 10, dTemp );
				if( !(1.0e-6 > fabs( dPipeDummyFlux - 1.0e-6 ) ) )
				{
					dTempCloseSubtract = dTempCloseSubtract + fabs( dTemp ) / fabs( dPipeDummyFlux );// 用来求环校正流量的 
				}
				else
				{
					dTempCloseSubtract = dTempCloseSubtract + 1.0;
				}
				dTemp = ( iKeyOfPipe / abs( iKeyOfPipe ) ) * fabs( dTemp );
				dCloseSubtract += dTemp;           // 环水头损失和
			}    
			CirCloseSubtract.insert( map< int, double >::value_type( i, dCloseSubtract ) );    // 第I环虚流量水头损失闭合差     
			if( dDummyPrecision > fabs( dCloseSubtract ) )            // 如果虚流量闭合差小于指定精度
			{
				iFlagCircleOver++; 
			}
			dTemp = 0.15 * dCloseSubtract / ( ( dM / ( dAlfa + dM ) ) * dTempCloseSubtract );
			CirReviseValueMap.insert( map< int, double >::value_type( i, dTemp ) );   // 环I校正流量，0.15松弛因子	
		}
		
		if( 1 == ( iFlagCircleOver / OptData.GetPropertyCount( 100 ) ) )  // 如果所有的环都平差完成
		{
			bFlagDummyCloseSubtract = true;
			break;
		}
		
		long lTime = 0;
		int iKeyOfCir = 1;
		int iTempCir = 0;
		map< int, int > FinishPipeKeyMap;

		for ( i = 1; i <= OptData.GetPropertyCount( 100 ); i++, iKeyOfCir++ )  // 遍历所有环
		{
			dTemp = 0.0;
			for( j = 0; j < OptData.GetPropertyCount( i, 100 ); j++ )
			{
				if( !OptData.GetProperty( iKeyOfCir, 100, j, iKeyOfPipe ) )
				{
					iKeyOfCir++;
					lTime++;
					if( 5000 < lTime )
					{
						return false;
					}
				}

				// 判断是否计算过
				if( FinishPipeKeyMap.end() != FinishPipeKeyMap.find( abs( iKeyOfPipe ) ) )
				{
					continue;
				}
				else
				{
					FinishPipeKeyMap.insert( map< int, int >::value_type( abs( iKeyOfPipe ), i ) );
				}

				OptData.GetProperty( iKeyOfPipe, 0, dPipeDummyFlux );				
				dPipeDummyFlux = ( iKeyOfPipe / abs( iKeyOfPipe ) ) * dPipeDummyFlux;
				for( int k = 0; k < OptData.GetPropertyCount( iKeyOfPipe, 102 ); k++ )
				{
				    if( !OptData.GetProperty( iKeyOfPipe, 102, k, iTempCir ) )
					{
					    break;
					}

				   	map< int, double >::iterator IntDouMapIt = CirReviseValueMap.find( abs( iTempCir ) );
					if( CirReviseValueMap.end() == IntDouMapIt )
					{
						return false;                       // 环没有对应的修正流量
					}
					else
					{
						dTemp = IntDouMapIt->second;
					}

					if( abs( iTempCir ) == iKeyOfCir )
					{
						dPipeDummyFlux += dTemp;
					}
					else
					{
						dPipeDummyFlux -= dTemp;
					}
				}
				dPipeDummyFlux = fabs( dPipeDummyFlux );
				OptData.SetProperty( iKeyOfPipe, 0, dPipeDummyFlux );
			}
		}

		m_ProGress.ProssMove( 0 );              // 子进度条移动1步
		if( 5000 < lTimes )       // 迭代次数超过最大次数限制仍未平差好虚流量
		{
			return false;
		}
	}

	int iKeyOfCir = 1;
	long lCount = 0;
	for( i = 1; i <= OptData.GetPropertyCount( 100 ); i++, iKeyOfCir++ )       // 遍历所有环
	{
		lCount = 0;
		if( !OptData.GetProperty( iKeyOfCir, 100, 0, iKeyOfPipe ) )
		{
			iKeyOfCir++;
			lCount++;
			if( 5000 < lCount )
			{
				return false;
			}
		}

		for ( j = 0; j < OptData.GetPropertyCount( iKeyOfCir, 100 ); j++ )    // 遍历环中所有管道
		{
			if( !OptData.GetProperty( iKeyOfCir, 100, j, iKeyOfPipe ) )
			{
				return false;
			}
			OptData.GetProperty( iKeyOfPipe, 0, dPipeDummyFlux );
			OptData.GetProperty( iKeyOfPipe, 1, dPipeFactFlux );
			dTemp = pow( OptData.GetEconomyFactor() * OptData.GetFluxSummation() * dPipeDummyFlux * dPipeFactFlux *dPipeFactFlux,
				1.0 / ( dAlfa + dM ) );      // 计算经济管径
			OptData.SetProperty( iKeyOfPipe, OPT_PIPEECONOMYDIAMETER, dTemp );       // 存储经济管径
			dPipeDiameter = CalStdDiameter( dTemp );   // 应该是取标准管径
			OptData.SetProperty( iKeyOfPipe, 4, dPipeDiameter );
		}
	}

	m_ProGress.ProssMove( 0, 0, 5000 );       // 子进度条移动到5000
	return bFlagDummyCloseSubtract;
}
                                      
double CPFAOptimize::CalStdDiameter( const double& dCalDiameter ) // 取标准管径的函数
{
	int iFactor = int( dCalDiameter * 100 / 5 );

	// 当取的直径和原来的直径小于5%，例如301的话iFactor=6，而301-300=1小于301的5%，故iFactor= 6；
	// 如果是320，则iFactor=6，而320-300=20大于320的5%，故iFactor=7，
	if( ( dCalDiameter * 0.05 ) < fabs( dCalDiameter - iFactor * 0.05 ) )
	{	
		iFactor++;
	}
	
	if( 0.3 < dCalDiameter )               // 直径300mm以上就不取中间值，例如算出来是7就取8，6就取6
	{
		iFactor = iFactor % 2 + iFactor;      
	}
	return iFactor * 0.05;
}

bool CPFAOptimize::DisposeManager( const PFAOptimitationData& OptData, ComponentManager& ComManager )
{
	/*
	Jun* pJun = NULL;
	Pipe* pPipe = NULL;
	int iKeyOfJun = 0;
	int i = 0;
	int iCountOfSupplyJun = OptData.GetPropertyCount( OPT_SUPPLYJUN );
	if( 1 >= iCountOfSupplyJun ) // 只有一个配水源，不需要加虚节点和虚管道
	{
		return true;
	}
	else
	{
		pJun = dynamic_cast< Jun* >( ComManager.CreatComponent( 0 ) );
		OptData.SetProperty( 0, OPT_DUMMYJUNANDPIPE, pJun->GetKey() );  // 把虚节点编号放入

		// 在ComManager增加J个虚管道(J为配水源数)
		for( i = 0; i < iCountOfSupplyJun ; i++ )
		{
			OptData.GetProperty( i, OPT_SUPPLYJUN, iKeyOfJun );
			pPipe = dynamic_cast< Pipe* >( ComManager.CreatComponent( 1 ) );
			OptData.SetProperty( i + 1, OPT_DUMMYJUNANDPIPE, pPipe->GetKey() );

			// 虚管道都是从虚节点流向配水源
			pPipe->StartJun( pJun->GetKey() );
			pPipe->EndJun( abs( iKeyOfJun ) );
		}
	}
	*/
	return true;
}


bool CPFAOptimize::DisplayResult( PFAOptimitationData& OptData )
{
	CMainFrame* pMainFrame = NULL; 
	pMainFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CChildFrame* pChildFrame = NULL;
	pChildFrame = (CChildFrame*)pMainFrame->GetActiveFrame();
	CAutoPFADoc* pAutoDoc = NULL;
	pAutoDoc = (CAutoPFADoc*)pChildFrame->GetActiveDocument();
	NetModel* pNetModel = pAutoDoc->m_scenarioManager.GetCurScenario()->GetNetModel();
	PFAOutModel &outModel = pAutoDoc->m_OutModel; 
	PipeStmOutMgr &PipeStmOutMgrTemp = outModel.SteadyOut().ComponentOutMgr().PipeOutMgr();   
	OutMgr* pOutMgr = &PipeStmOutMgrTemp;                        // 数据写入的地方

	PipeStmOutMgrTemp.EmptyOut();
	int iKeyOfPipe = 0;
	int i = 0;
	double dTemp = 0.0;

	// 标题行  
	pOutMgr->GetArray().RemoveAll();
	pOutMgr->GetArray().Add( OutDataAttr( pAutoDoc->m_unitSystem, 0, None, _T( "编号" ) ) );      // 编号	
	pOutMgr->GetArray().Add( OutDataAttr( pAutoDoc->m_unitSystem, 1, None, _T( "虚流量" ) ) );    // 虚流量
	pOutMgr->GetArray().Add( OutDataAttr( pAutoDoc->m_unitSystem, 2, VolumetricFlow, _T( "实流量" ) ) );    // 实流量
	pOutMgr->GetArray().Add( OutDataAttr( pAutoDoc->m_unitSystem, 3, Diameter, _T( "经济管径" ) ) );  // 
	pOutMgr->GetArray().Add( OutDataAttr( pAutoDoc->m_unitSystem, 4, Diameter, _T( "标准管径" ) ) );
	pOutMgr->GetArray().Add( OutDataAttr( pAutoDoc->m_unitSystem, 5, Length, _T( "管道长度" ) ) );
	
	ComponentStmOut* pComOut = NULL;
	for( i = 0; i < OptData.GetPropertyCount( OPT_PIPECIR ); i++ )
	{
		if( !OptData.GetProperty( i, OPT_PIPECIR, iKeyOfPipe ) )
		{
			return false;
		}
		pComOut = PipeStmOutMgrTemp.CreatorComponent( i + 1 );
		pComOut->SetValue( iKeyOfPipe, 0 );
		OptData.GetProperty( iKeyOfPipe, OPT_PIPEDUMMYFLUX, dTemp );
		pComOut->SetValue( dTemp, 1 );
		OptData.GetProperty( iKeyOfPipe, OPT_PIPEFACTFLUX, dTemp );
		pComOut->SetValue( dTemp, 2 );
		OptData.GetProperty( iKeyOfPipe, OPT_PIPEECONOMYDIAMETER, dTemp );
		pComOut->SetValue( dTemp, 3);
		OptData.GetProperty( iKeyOfPipe, OPT_PIPEDIAMETER, dTemp );
		pComOut->SetValue( dTemp, 4);
		OptData.GetProperty( iKeyOfPipe, OPT_PIPELENGTH, dTemp );
		pComOut->SetValue( dTemp, 5 );
	}
	pAutoDoc->OutMutex(TRUE);//更新输出窗口
    pAutoDoc->ActiveView(RUNTIME_CLASS(OutPutDataView));
	return true;
}