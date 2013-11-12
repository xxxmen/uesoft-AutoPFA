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


bool CPFAOptimize::CalEconomyDiameterAndWaterHarmer( ComponentManager& ComManager, const double& dPrecision, const long& lMaxIterative, PFAOptimitationData& OptData )
{
	// 
	ASSERT( NULL != & ComManager );
	ASSERT( 0 < dPrecision );
	ASSERT( 0 < lMaxIterative );

	vector< double > TempVector;
	vector< int >* pPipeVector = NULL;
	vector< int >* pJunVector = NULL;
	map< int, double > OptimitationParameterMap;                 // 管段的闭合差，用来计算环的闭合差
	map< int, double > OptimitationAssistantMap;                 // 用在平差的时候
	int i = 0;
	int j = 0;
	double dTemp = 0.0;
	double dTempDummyFlux = 0.0;
	double dTempFactFlux = 0.0;
	double dTempLength = 0.0;
	bool bPrecisionFlag = false;                // 精度要求标志，为true表示全部计算参数都符合精度要求
	long lIterativeTime = 0;                    // 精度迭代次数
	Pipe* pPipe = NULL;
    CalPipeCloseSubtract( ComManager, OptData, OptimitationParameterMap, OptimitationAssistantMap );

	// 计算每个环的参数，如果有环参数大于精度要求dPrecision，则调整虚流量，直到每个环参数都小于精度要求dPrecision或迭代次数超过限制
	while( ( false == bPrecisionFlag ) && ( lMaxIterative > lIterativeTime ) )
	{
		bPrecisionFlag = true;                   // 每次迭代都先设置迭代成功标志为true，如果有某环精度不够，则置为false
		map< int, double >::iterator OptIt;
		vector< int >::iterator PipeIt;
		double dParameterTemp = 0.0;            // 环的闭合差
		double dAssistantTemp = 0.0;            // 虚流量修正时用的辅助变量


		// 哈代-克罗斯法，即把基环单独考虑，不考虑其他环对此基环造成的影响
		for( int i = 1; i <= OptData.GetCirPipeMatrixCount(); i++ )
		{
			dParameterTemp = 0.0;
			dAssistantTemp = 0.0;
			pPipeVector = OptData.GetCirPipeMatrix( i );
			pJunVector = OptData.GetCirJunMatrix( i );
			PipeIt = pPipeVector->begin();

			// 计算每个环的参数
			for( ; PipeIt != pPipeVector->end(); PipeIt++ )
			{
				pPipe = ComManager.LookUpPipe( abs( *PipeIt ) );
				if( 0 < *PipeIt )
				{
					OptIt = OptimitationParameterMap.find( abs( *PipeIt ) );
					dTemp = OptIt->second;
					dParameterTemp += OptIt->second;
					OptIt = OptimitationAssistantMap.find( abs( *PipeIt ) );
					dAssistantTemp += OptIt->second;
				}
				
				else
				{
					OptIt = OptimitationParameterMap.find( abs( *PipeIt ) );
					dTemp = OptIt->second;
					dParameterTemp -= fabs( OptIt->second );
					OptIt = OptimitationAssistantMap.find( abs( *PipeIt ) );
					dAssistantTemp -= fabs( OptIt->second );
				}
			}

			// 如果此环计算出来的结果不符合精度要求,因为是double，所以没加等号，把逻辑判断倒过来？
			if( dPrecision < fabs( dParameterTemp ) )
			{
				bPrecisionFlag = false;             // 要重新迭代

				// 防止分母为0，但这个断言还是不够全面，以后需要改进
				ASSERT( 0 < fabs( ( OptData.GetMModulus() * dAssistantTemp - 1e-9 ) ) );

				// 此环的虚流量校正流量
				dTemp = ( OptData.GetAlfaModulus() + OptData.GetMModulus() ) * dParameterTemp /
					( OptData.GetMModulus() * dAssistantTemp );

				// 修正此环上所有的管道虚流量,注意正负
				// 这里的修正方法是单一环修正，即只考虑了本环的影响，没有考虑邻环的影响，在精度上会造成一定损失，
				// 以后会考虑在PFAOptimitationData中加入属性，来把这个方法改为联立环修正
				PipeIt = pPipeVector->begin();
				for( ; PipeIt != pPipeVector->end(); PipeIt++ )
				{
				    pPipe = ComManager.LookUpPipe( abs( *PipeIt ) );
					OptData.GetProperty( *PipeIt, 0, dAssistantTemp );
					
					if( 0 > dParameterTemp )
					{
						if( 0 < *PipeIt )
						{
							dAssistantTemp -= dTemp;
						}
						else
						{
							dAssistantTemp += dTemp;
						}
						dAssistantTemp = fabs( dAssistantTemp );
					}
					else
					{
						if( 0 < *PipeIt)
						{
							dAssistantTemp += dTemp;
						}
						else
						{
							dAssistantTemp -= dTemp;
						}
						dAssistantTemp = fabs( dAssistantTemp );
					}

 
					// dAssistantTemp += dTemp;
					OptData.SetProperty( *PipeIt, 0, dAssistantTemp );
				}
				// 重新计算管道的闭合差
				
			}
		}
		CalPipeCloseSubtract( ComManager, OptData, OptimitationParameterMap, OptimitationAssistantMap );
        lIterativeTime++;              // 迭代次数加一
	}

	// 如果虚流量平差成功
	if( ( false != bPrecisionFlag ) && ( lMaxIterative > lIterativeTime ) )
	{
		// 计算经济管径和水头损失
		ASSERT( 0 < OptData.GetEconomyFactor() );
		int iKeyOfPipe = 0;	
		Pipe* pPipe = NULL;
		Component* pPipeComponent = NULL; 
      
		// 遍历所有管道
        IteratorPtr<Component> PipeItPtr( ComManager.CreatPipeIterator() );
		for( PipeItPtr->Fist(); !PipeItPtr->IsDone(); PipeItPtr->Next() )
		{
			pPipeComponent = &PipeItPtr->CurrentItem();
	        pPipe = dynamic_cast<Pipe*>( pPipeComponent );
			if( NULL == pPipe )
			{
				return false;       // 找不到管道，是否应该发送个自定义消息或错误？
			}
			OptData.GetProperty( pPipe->GetKey(), 0, dTempDummyFlux );
			OptData.GetProperty( pPipe->GetKey(), 1, dTempFactFlux );
			OptData.GetProperty( pPipe->GetKey(), 2, dTempLength );
			dTemp = OptData.GetEconomyFactor() * OptData.GetFluxSummation() * dTempDummyFlux 
				* dTempFactFlux*dTempFactFlux;
			
			// 经济管径
			if( 0 > fabs( ( OptData.GetAlfaModulus() + OptData.GetMModulus() ) - 1e-6 ) )
			{
				AfxMessageBox( MODULUS_ZERO );
				return false;
			}
			double dDiameter = pow( fabs( dTemp ), 1.0 / ( OptData.GetAlfaModulus() + OptData.GetMModulus() ) );
			OptData.SetProperty( pPipe->GetKey(), 4, dDiameter );
			
			// 水头损失
			double dWater = OptData.GetKModulus() * pow( fabs( dTempFactFlux ), OptData.GetNModulus() ) * dTempLength 
				/ pow( fabs( dTemp ), OptData.GetMModulus() );
			OptData.SetProperty( pPipe->GetKey(), 5, dWater );
		}
	}
	return bPrecisionFlag;
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





bool CPFAOptimize::CalFactFlux( ComponentManager& ComManager, const double& dPrecision, const long& lMaxIterative, PFAOptimitationData& OptData )
{
	// 
	ASSERT( NULL != & ComManager );
	ASSERT( 0 < dPrecision );
	ASSERT( 0 < lMaxIterative );

	vector< double > TempVector;
	vector< int >* pPipeVector = NULL;
	vector< int >* pJunVector = NULL;
	map< int, double > OptimitationParameterMap;                 // 管段的闭合差，用来计算环的闭合差
	map< int, double > PTempMap;                                 // 环的Sq_2，有正负的
	map< int, double > ATempMap;                                 // 环的Sq
	map< int, double > ResultMap;                                // 校正流量，int表示环
	double dTemp = 0.0;
	double dTempDiameter = 0.0;
	double dTempFactFlux = 0.0;
	double dTempLength = 0.0;
	bool bPrecisionFlag = false;                // 精度要求标志，为true表示全部计算参数都符合精度要求
	long lIterativeTime = 0;                    // 精度迭代次数
	Pipe* pPipe = NULL;
	Component* pPipeComponent = NULL; 
	IteratorPtr<Component> PipeItPtr( ComManager.CreatPipeIterator() );

	map< int, double > CircleCloseSubtract;                // 环的闭合差
	map< int, double > CircleMiddleVariable;               // 中间变量 
	map< int, vector< double > > FluxModulusMetrix;        // 求解流量的系数矩阵
    
	
	int i = 0;
	int j = 0;
	
	// 初始化流量系数矩阵,矩阵是从1开始的
	for( i = 0; i <= OptData.GetPropertyCount( 100 ); i++ )
	{
		vector< double > DoubleVector;
		for( j = 0; j <= OptData.GetPropertyCount( 100 ); j++ )
		{
			DoubleVector.push_back( 0.0 );
		}
		FluxModulusMetrix.insert( map< int, vector< double > >::value_type( i+1, DoubleVector ) );
	}

	// 计算每根管道
	for( PipeItPtr->Fist(); !PipeItPtr->IsDone(); PipeItPtr->Next() )
	{
		pPipeComponent = &PipeItPtr->CurrentItem();
	    pPipe = dynamic_cast<Pipe*>( pPipeComponent );

		// 管道的属性：管道流量和管道长度，如果其中有一个属性不存在
		if( !OptData.GetProperty( pPipe->GetKey(), 1, dTempFactFlux ) && !OptData.GetProperty( pPipe->GetKey(), 2, dTempLength) 
		    && !OptData.GetProperty( pPipe->GetKey(), 4, dTempDiameter ) )
		{
			return false;
		}

		// 每根管道的计算参数
		// 如果k和m都设置了值，就直接计算
		if( ( 0 > fabs( OptData.GetKModulus() - 1.0e-13 ) ) && ( 0 > fabs( OptData.GetMModulus() - 1.0e-6 ) ) )
		{
			if( 0 < fabs( dTempDiameter -1e-6 ) )               // 分母不能为0
			{
				dTemp = OptData.GetKModulus() * dTempLength / pow( fabs( dTempDiameter ), 5.3 );  // 公式？
			}
		}
		// Re
		if( 0 > fabs( dTempDiameter - 1e-6) )                   // 防止下面公式分母为0，而且直径为0也没意义
		{
			return false;
		}	
		double dSpeed = 4.0 * dTempFactFlux / ( PI * dTempDiameter * dTempDiameter );  // 每根管道的流速
        QuantityManager& qm = QuantityManager::Instance();     
		NumFlyWeight DynamicViscosity = ( ComManager.SysProperty().GetFuild() )->ms_Viscos; // 流体的动力粘度
		double dDynamicViscosity = DynamicViscosity.GetfValue();
		if( "kg/sec-m" != DynamicViscosity.GetUnit() )         // 转换到标准单位
		{	
			qm.TransformFromStd( dDynamicViscosity, DynamicViscosity.GetUnit().GetBuffer( 15 ), DynamicViscosity.GetfValue() );
		}
		if( 0 > fabs( dDynamicViscosity - 1e-6) )              // 动力粘度不能为0
		{
			return false;
		}
		double dRe = dSpeed * dTempDiameter / dDynamicViscosity;

		// 牛顿迭代法解柯尔勃洛克-魏特公式
		if( !ColebrookNewton( 4.572e-5, dTempDiameter, dRe, dTemp ) )       // 牛顿法迭代失败
		{
			return false;                               
		}
		dTemp = dTemp * 8.0 * dTempLength / ( 9.8 * PI * PI * pow( fabs( dTempDiameter ), 5 ) ); // S的计算，跟选的摩擦阻力公式有关
		
		OptimitationParameterMap.insert( map< int, double >::value_type( pPipe->GetKey(), dTemp ) );
	}


	// 为实际流量平差做准备
	map< int, vector< double > >::iterator FluxModMetIt = FluxModulusMetrix.begin();
	for( i = 1; i <= OptData.GetPropertyCount( 100 ); i++ )   // 从1号环开始
	{
		double dPTemp = 0.0;
		double dATemp = 0.0;
		int iKeyOfPipe = 0;                                   // 管道编号
		double dSTemp = 0.0;                                  // 上面算出来的OptimitationParameterMap中的值，即水管摩阻  
		vector< double >::iterator DouVecIt = ( FluxModMetIt->second ).begin();
		for( j = 0; j < OptData.GetPropertyCount( i, 100 ); j++ )  // 遍历每个环的管道
		{
			OptData.GetProperty( i, 100, j, iKeyOfPipe);
			OptData.GetProperty( abs( iKeyOfPipe ), 1, dTemp );         // 管道实际流量
			map< int, double >::iterator IntDoubleIt = OptimitationParameterMap.find( abs( iKeyOfPipe ) );
			dSTemp = IntDoubleIt->second;
			dPTemp = dPTemp + ( iKeyOfPipe > 0 ? 1 : -1) * dSTemp * dTemp * dTemp; 
			dATemp = dATemp + dSTemp * dTemp;
		}
		PTempMap.insert( map< int, double >::value_type( i, dPTemp ) );
		ATempMap.insert( map< int, double >::value_type( i, dATemp ) );
	}

	// 计算每个环的参数，如果有环参数大于精度要求dPrecision，则调整实际流量，直到每个环参数都小于精度要求dPrecision或迭代次数超过限制
	while( ( false == bPrecisionFlag ) && ( lMaxIterative > lIterativeTime ) )
	{
		bPrecisionFlag = true;                   // 每次迭代都先设置迭代成功标志为true，如果有某环精度不够，则置为false
		double dParameterTemp = 0.0;            
		map< int, vector< double > >::iterator FluxModMetIt = FluxModulusMetrix.begin();
		vector< double >::iterator DouVecIt;
		map< int, double >::iterator IntDouIt;
		for( i = 1; i <= OptData.GetPropertyCount( 100 ); i++ )   // 从1号环开始
		{
			dParameterTemp = 0.0;
			DouVecIt = ( FluxModMetIt->second ).begin(); 
			
			double dModulus = 0.0;
			*DouVecIt = 1.0;	
			for( j = 0; j < OptData.GetPropertyCount( i, 100 ); j++ )   // 遍历每个环的管道
			{
				DouVecIt = ( FluxModMetIt->second ).begin();
	            int iKeyOfPipe = 0;
				int iCloseCircle = 0;
				int n = 0;
				OptData.GetProperty( i, 100, j, iKeyOfPipe );
				while( OptData.GetProperty( iKeyOfPipe, 102, n, iCloseCircle ) )
				{
					if( abs( iCloseCircle ) == i )            // 如果是本环则跳过
					{
						n++;
						continue;
					}			
					double dATemp = 0.0;                               
					double dSTemp = 0.0;     
					IntDouIt = OptimitationParameterMap.find( abs( iKeyOfPipe ) );
					dSTemp = IntDouIt->second;                               // S
					OptData.GetProperty( abs( iKeyOfPipe ), 1, dTemp );      // 实际流量
					IntDouIt = ATempMap.find( i );
					dATemp = IntDouIt->second;                               // 环的Sq和
					if( 0 > fabs( dATemp - 1e-6) )                           // 防止下面表达式的分母为0
					{
						return false;
					}
					dModulus = -1 * dSTemp * fabs( dTemp ) / dATemp;

					// 把系数写入矩阵
					for( int m = 1; m < iCloseCircle; m++ )                   
					{
						DouVecIt++;
					}
					if( ( FluxModMetIt->second ).end() == DouVecIt )           // 防止越界写入数值
					{
						return false;
					}
					*DouVecIt = dModulus;
					n++;
				}
			}

			// 把常量向量也放入矩阵中，即等式的右边：AX=B中的B
			IntDouIt = PTempMap.find( i );
			dTemp = -1 * IntDouIt->second ;
			IntDouIt = ATempMap.find( i );
			if( 0 > fabs( IntDouIt->second - 1e-6 ) )            // 防止分母为0
			{
				return false;
			}
			dModulus = dTemp / ( 2 * IntDouIt->second );
			DouVecIt = ( FluxModMetIt->second ).begin(); 
			for(int k = 0; k <= OptData.GetPropertyCount( 100 ); k++ ) // 移动到每行最后一个位置，即移动 行数+1 个位置
			{
				DouVecIt++;
			}
			*DouVecIt = dModulus;

			FluxModMetIt++;                                  // 移动到下一行
		}

		// 解FluxModulusMetrix线性方程组，结果放入向量ResultMap
		//////////////////////////

		// 遍历所有环，
		IntDouIt = ResultMap.begin();
		for( ; ResultMap.end() != IntDouIt; IntDouIt++ )
		{
			dTemp = IntDouIt->second;
		    if( dPrecision < fabs( dTemp ) )   // 如果有环计算出来的校正流量不符合精度要求
			{
		    	bPrecisionFlag = false;             // 要重新迭代

			    // 修正此环上所有的管道实际流量,注意正负
				int iKeyOfPipe = 0;
				for( i = 1; i <= OptData.GetPropertyCount( 100 ); i++ )
				{
					for( j = 0; j < OptData.GetPropertyCount( i, 100); j++ )
					{
						OptData.GetProperty( i, 100, j, iKeyOfPipe );             // 取得环中的管道编号
						OptData.GetProperty( iKeyOfPipe, 1, dParameterTemp );     // 取的管道对应的实际流量
						dParameterTemp += dTemp;                                  // 修正流量
						OptData.SetProperty( iKeyOfPipe, 1, dParameterTemp );
					}
				}
			}
		}
		lIterativeTime++;              // 迭代次数加一
	}
	return bPrecisionFlag;
}

// 根据经济管径寻找标准管径，本来应该是按照传进来的数据找的，现在简化下，以50mm为一个档次
bool CPFAOptimize::FindStandardDiameter( PFAOptimitationData& OptData )
{
	bool bFlag = true;
	double dEconomyDiameter = 0.0;                // 经济管径
	double dStandardDiameter = 0.0;               // 要取得的标准管径
	int iKeyOfPipe = 1;                           // 管道编号
	int i = 0;
	while( i < OptData.GetPropertyCount( 2 ) )
	{
		// 管道编号有可能不是连续的
		if( !OptData.GetProperty( iKeyOfPipe, 2 , dEconomyDiameter ) )
		{
			iKeyOfPipe++;
			if( iKeyOfPipe > 500000 ) // 防止进入死循环，管道编号如果超过500000
			{
				return false;
			}
		}

		int iBottonDiameter = ( int )( dEconomyDiameter / 0.05 );

		// 如果离( iBottonDiameter + 1 ) * 0.05 的标准管径比较近
		if( ( dEconomyDiameter - iBottonDiameter * 0.05 ) > ( ( iBottonDiameter + 1 ) * 0.05 - dEconomyDiameter ) )
		{
			dStandardDiameter = ( iBottonDiameter + 1 ) * 0.05;
		}
		else         // 如果离iBottonDiameter * 0.05的标准管径比较近
		{
			if( 0 != iBottonDiameter )
			{
                dStandardDiameter = iBottonDiameter * 0.05;
			}
			else     // 不能因为管道经济管径太小而设置为0
			{
				dStandardDiameter = ( iBottonDiameter + 1 ) * 0.05;
			}
			
		}
		if( !OptData.SetProperty( iKeyOfPipe, 2, dStandardDiameter ) )  // 把标准管径写进去
		{
			return false;                                               // 写入失败则返回
		} 
		i++;
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
		}
		IntVecIt++;
		IntVecNextIt++;
	}
	*IntVecIt = iValue;
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
	JunSystemTransformCircleSystem( *pComManager, OptData );
	DisplayMatrix( "F://CirPipe.txt", 100, OptData );
	InitializePipeCircle( OptData );
	DisplayMatrix( "F://Pipe.txt", 102, OptData );

	// 从pComManager中初始化OptData的 初始实际流量，管道长度，节点流量，配水源，控制点，
	// 先手动设置配水源和控制点
	int iTemp = 1;
	OptData.SetProperty( 0, 200, iTemp );          // 节点1为配水源
	iTemp = 6;
	OptData.SetProperty( 0, 201, iTemp );         // 节点10为控制点

	CMinimumSquareSum MinSquSum;

	//MinSquSum.InitializeFactFlux( *pComManager, OptData );   //  初始实际流量
	///////////////////////////////////////
	int i = 0;
	int iKeyOfPipe = 0;
	double Temp = 0.0;
    Temp = 0.025;	
	OptData.SetProperty( 3, 1, Temp );
	OptData.SetProperty( 7, 1, Temp );
	OptData.SetProperty( 2, 1, Temp );
	OptData.SetProperty( 5, 1, Temp );
	OptData.SetProperty( 6, 1, Temp );
	OptData.SetProperty( 1, 1, Temp );
	////////////////////////////////////////

	double dTemp = 0.0;
	Pipe* pPipe = NULL;
	Component* pComponent = NULL; 
	map< int, double > BeforeDiameterMap;                     // 存储了上一次计算的直径
	int iIteratorTime = 0;                                    // 迭代次数
	IteratorPtr<Component> PipeItPtr( pComManager->CreatPipeIterator() );
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
	IteratorPtr<Component> JunItPtr( pComManager->CreatJunIterator() );
	for( JunItPtr->Fist(); !JunItPtr->IsDone(); JunItPtr->Next() )
	{
		pComponent = &JunItPtr->CurrentItem();
	    pJun = dynamic_cast<Jun*>( pComponent );	
		strUnit = pJun->ms_InitGuess.GetValue( 2 );                            // 获得单位
		strValue = pJun->ms_InitGuess.GetValue( 1 );
		TCHAR* pChar = NULL;
		qm.TransformToStd( dTemp, strUnit.GetBuffer( 32 ), _tcstod( strValue.GetBuffer( 32 ), &pChar ) ); // 转化成标准单位
		if( IDS_STRVOLUMEFLOW != _ttoi( pJun->ms_InitGuess.GetValue( 0 ).GetBuffer( 32 ) ) )            // 质量流量，要转化为体积流量
		{
			double dTempDensity = 0.0;
			NumFlyWeight *pDensity = &( ( pComManager->SysProperty().GetFuild() )->ms_Density );
			dTemp *= pDensity->GetNum();                                       // GetNum返回标准单位数
		}
		OptData.SetProperty( pJun->GetKey(), 3, dTemp );
	}

	////////////
	dTemp = 0.05;
	OptData.SetProperty( 1, 3, dTemp );
	dTemp = -0.05;
	OptData.SetProperty( 6, 3, dTemp );
	////////////


    // 初始化经济参数
	OptData.SetAModulus( 8.4 );
	OptData.SetBModulus( 107 );
	OptData.SetAlfaModulus( 1.6 );
	OptData.SetDisinvestmentTime( 3.0 );
	OptData.SetRepairModulus( 3.3 );
	OptData.SetEletricityPrice( 0.5 );
	OptData.SetAsymmetryModulus( 1.0 );
	OptData.SetPumpEfficiency( 0.7 );
	OptData.SetKModulus( 1.34e-10 );
	OptData.SetMModulus( 5.3 );
	OptData.SetNModulus( 2 );
	OptData.Initialization();
	
	BeforeDiameterMap.clear();
	iIteratorTime = 0;
	do
	{
	    // 初始化虚流量
	    MinSquSum.InitializeDummyFlux( *pComManager, OptData );

	    // 虚流量平差
	    CalEconomyDiameterAndWaterHarmer( *pComManager, 0.0001, 5000, OptData );

	    // 通过经济管径计算标准管径
	    FindStandardDiameter( OptData );

        // 实际流量平差
	    CalFactFlux( *pComManager, 0.0001, 5000, OptData );

	   // 迭代次数加一
		iIteratorTime++;
		
	}
	while( !DiameterIsEqual( OptData, BeforeDiameterMap ) && ( 5000 > iIteratorTime ) ); // 比较前后管径，不相等则跳到 初始化虚流量

	// 计算其他要素
    CalOthersVariable( *pComManager, OptData );

	// 输出结果
}

