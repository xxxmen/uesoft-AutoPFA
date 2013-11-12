// PFAOptimitationData.cpp: implementation of the PFAOptimitationData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "PFAOptimitationData.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PFAOptimitationData::PFAOptimitationData()
    :dA( 8.4 ), dB( 107 ), dAlfa( 1.64 ), dDisinvestmentTime( 7.0 ), dRepairModulus( 0.033 ), dWorkExpenditure( 1000 ), 
	dKModulus( 1.34e-3 ), dMModulus( 5.33 ), dNModulus( 2 )
{
	
}

PFAOptimitationData::~PFAOptimitationData()
{

}

bool PFAOptimitationData::Initialization()
{
	/*
	// 计算f
	// 保证分母不为0
	if( ( -dAlfa > 0 ) || ( -dB > 0) || ( dRepairModulus < 0 ) || ( -dDisinvestmentTime > 0 ) )
	{
		AfxMessageBox( ECONOMY_FAILE );
		return false;
	}
	dEconomyFactor = 86 * dEletricityPrice * dAsymmetryModulus * dMModulus * dKModulus
		/ ( dAlfa * dB * ( ( dRepairModulus ) + ( 1 / dDisinvestmentTime ) ) );
	if( -dEconomyFactor > 0 )
	{
		return false;
	}

	// 计算k
	if( ( 0 > fabs( dEletricityPrice - 1.0e-6 ) ) && ( 0 > fabs( dAsymmetryModulus - 1.0e-6 ) ) 
		&& ( 0 > fabs( dPumpEfficiency - 1.0e-6 ) ) )
	{
		dWorkExpenditure = 0.0;
		return false;
	}
	else
	{
		dWorkExpenditure = 86000 * dEletricityPrice * dAsymmetryModulus / dPumpEfficiency;
	}
	*/

  
	return true;
}

ComMap* PFAOptimitationData::GetCirPipeMatrix( const int& iKeyOfCircle )
{
	// 环号不在记录的环号范围里
	if( ( 1 > iKeyOfCircle ) && ( CirPipeMatrix.size() < iKeyOfCircle ) )
	{
		return NULL;
	}
	
	CirMatrix::iterator CirMatIt = CirPipeMatrix.find( iKeyOfCircle );
	if( CirMatIt == CirPipeMatrix.end() )
	{
		return NULL;
	}
	return &( CirMatIt->second );
}

ComMap* PFAOptimitationData::GetCirJunMatrix( const int& iKeyOfCircle )
{
	// 环号不在记录的环号范围里
	if( ( 1 > iKeyOfCircle ) && ( CirJunMatrix.size() < iKeyOfCircle ) )
	{
		return NULL;
	}
	

	CirMatrix::iterator CirMatIt = CirJunMatrix.find( iKeyOfCircle );
	if( CirMatIt == CirJunMatrix.end() )
	{
		return NULL;
	}
	return &( CirMatIt->second );
}

bool PFAOptimitationData::GetProperty( const int& iKeyOfComponent, const int& iProperty, double& dValueOfProperty )
{
	return ChangeProperty( iKeyOfComponent, iProperty, true, dValueOfProperty );
}

bool PFAOptimitationData::SetProperty( const int& iKeyOfComponent, const int& iProperty, double& dValueOfProperty )
{
    return ChangeProperty( iKeyOfComponent, iProperty, false, dValueOfProperty );
}

bool PFAOptimitationData::ChangeProperty( const int& iKeyOfComponent, const int& iProperty, const bool bChangeType, double& dValueOfProperty )
{
	//
	// ASSERT( 0 < iKeyOfComponent );
	ASSERT( 0 <= iProperty );

	map< int, double >::iterator ProIt;
    map< int, double >* pIntDoubleMap = NULL;
	vector< int >* pIntVector = NULL;
    switch( iProperty )
	{
	    case 0: pIntDoubleMap = &PipeDummyFluxMap;
		    break;
		
	    case 1: pIntDoubleMap = &PipeFactFluxMap;
		    break;
		
	    case 2: pIntDoubleMap = &PipeLengthMap;
	    	break;

	    case 3: pIntDoubleMap = &JunFluxMap;
		    break;

	    case 4: pIntDoubleMap = &PipeDiameter;
		    break;

	    case 5: pIntDoubleMap = &PipeWaterHammer;
		    break;

		case 6: pIntDoubleMap = &PipeFluxSpeedMap;
			break;

		case 7: pIntDoubleMap = &JunPressureMap;
			break;

		case 8: pIntDoubleMap = &PipeEconomyDiameterMap;
			break;
			
		case 10: pIntDoubleMap = &PipeDummyWaterHammer;
			break;

		case 11: pIntDoubleMap = &PipeFactWaterHammer;
			break;
		//case 200: pIntVector = &SupplyJunVector;
		//	break;

		//case 201: pIntVector = &ControlJunVector;
		//	break;
		
	    default: return false;
	}
	ProIt = pIntDoubleMap->find( abs( iKeyOfComponent ) );  // 取绝对值是因为管道有正负
	if( false == bChangeType)
	{
		if( pIntDoubleMap->end() == ProIt )               // 矩阵里不存在这样的行
		{
			pIntDoubleMap->insert( map< int, double >::value_type( abs( iKeyOfComponent ), dValueOfProperty ) );
			return true;                                   // 矩阵不存在这样的行
		}
		else                                                // 矩阵存在这样的行
		{
			ProIt->second = dValueOfProperty;
		}
		
	}
	else
	{
		if( pIntDoubleMap->end() == ProIt )
		{
			return false;
		}
		else
		{
			dValueOfProperty = ProIt->second;
		}
	}
	return true;
}


bool PFAOptimitationData::GetProperty( const int& iKeyOfComponent, const int& iProperty, int& iValueOfProperty )
{
	return ChangeProperty( iKeyOfComponent, iProperty, true, iValueOfProperty );
}

bool PFAOptimitationData::SetProperty( const int& iKeyOfComponent, const int& iProperty, int& iValueOfProperty )
{
    return ChangeProperty( iKeyOfComponent, iProperty, false, iValueOfProperty );
}

bool PFAOptimitationData::ChangeProperty( const int& iKeyOfComponent, const int& iProperty, const bool bChangeType, int& iValueOfProperty )
{
	// 这个函数主要是改变100+和200+的属性
	ASSERT( 100 <= iProperty );     
	ASSERT( 0 <= iKeyOfComponent );


	// 100+
	if( ( 100 <= iProperty ) && ( 200 > iProperty ) )
	{
		if( false == bChangeType )
		{
			return false;
		}
		else
		{
			CirMatrix* pCirMatrix = NULL;
			switch( iProperty )
			{
			    case 100: pCirMatrix = &CirPipeMatrix;
				    break;
				case 101: pCirMatrix = &CirJunMatrix;
					break;
				case 102: pCirMatrix = &PipeCirMatrix;
					break;
				case 103: pCirMatrix = &PipeCirMatrix;
					break;
				default: return false;
			}
			CirMatrix::iterator IntVecMapIt = pCirMatrix->begin();
			for( int i = 0; i < iKeyOfComponent; i++, IntVecMapIt++ )
			{
				if( pCirMatrix->end() == IntVecMapIt )
				{
					return false;
				}
			}
			iValueOfProperty = IntVecMapIt->first;
			return true;
		}
	}


	// 200+
	if( ( 200 <= iProperty ) && ( 300 > iProperty ) )
	{
		vector< int >* pIntVector = NULL;
		switch( iProperty )
		{
		    case 200: pIntVector = &SupplyJunVector;
			    break;
			
		    case 201: pIntVector = &ControlJunVector;
			    break;
			
	    	case 202: pIntVector = &DummyCircleVector;
			    break;

		    case 203: pIntVector = &DummyJunAndPipeVector;
			    break;
			
	    	default: return false;
			    break;
		}
		vector< int >::iterator IntVecIt = pIntVector->begin();
		vector< int >::iterator IntVecNextIt = IntVecIt;
		IntVecNextIt++;
		if( false == bChangeType )
		{
			for( int i = 0; i < iKeyOfComponent; i++ )             
			{	
				if( pIntVector->end() == IntVecNextIt )
				{
					pIntVector->push_back( 0 );
					IntVecNextIt = IntVecIt;
					IntVecNextIt++;
				}
				IntVecIt++;
				IntVecNextIt++;
			}
			pIntVector->push_back( iValueOfProperty );
		}
		else
		{
			for( int i = 0; i < iKeyOfComponent; i++ )             
			{	
				if( pIntVector->end() == IntVecNextIt )
				{
					return false;
				}
				IntVecIt++;
			}
			iValueOfProperty = *IntVecIt;
		}
	}

	return true;
}


int PFAOptimitationData::GetPropertyCount( const int& iProperty )
{
	switch( iProperty )
	{
	    case 0: return PipeDummyFluxMap.size();
		    break;
    	case 1: return PipeFactFluxMap.size();
			break;
		case 2: return PipeLengthMap.size();
			break;
		case 3: return JunFluxMap.size();
			break;
		case 4: return PipeDiameter.size();
			break;
		case 5: return PipeWaterHammer.size();
			break;
		case 6: return PipeFluxSpeedMap.size();
			break;
		case 7: return JunPressureMap.size();
			break;
		case 8: return PipeEconomyDiameterMap.size();
			break;
		case 10: return PipeDummyWaterHammer.size();
			break;
		case 11: return PipeFactWaterHammer.size();
			break;
		case 100: return CirPipeMatrix.size();
			break;
		case 101: return CirJunMatrix.size();
			break;
		case 102: return PipeCirMatrix.size();
			break;
		case 103: return PipeCirMatrix.size();
			break;
		case 200: return SupplyJunVector.size();
			break;
		case 201: return ControlJunVector.size();
			break;
		case 202: return DummyCircleVector.size();
			break;
		case 203: return DummyJunAndPipeVector.size();
			break;
		default: break;
	}
    return -1;
}

int  PFAOptimitationData::GetPropertyCount( const int& iKeyOfComponent, const int& iProperty )
{
	// ASSERT( 0 <= iKeyOfComponent );
	ASSERT( 0 <= iProperty );

	CirMatrix::iterator CirMatIt;
	CirMatrix* pCirMatrix = NULL;
	map< int, double >::iterator IntDoubleIt;
    map< int, double >* pIntDoubel = NULL;
	ComMap* pIntVector = NULL;
	switch( iProperty )
	{
	    case 0: pIntDoubel = &PipeDummyFluxMap;
			break;
		case 1: pIntDoubel = &PipeFactFluxMap;
		    break;
		case 2: pIntDoubel = &PipeLengthMap;
			break;
		case 3: pIntDoubel = &JunFluxMap;
			break;
		case 4: pIntDoubel = &PipeDiameter;
		    break;
		case 5: pIntDoubel = &PipeWaterHammer;
			break;
		case 100: pCirMatrix = &CirPipeMatrix;
			break;
		case 101: pCirMatrix = &CirJunMatrix;
			break;
		case 102: pCirMatrix = &PipeCirMatrix;
			break;
		default: return -1;
			break;
	}
	if( 5 >= iProperty)
	{
		IntDoubleIt = pIntDoubel->find( abs( iKeyOfComponent ) );
		if( pIntDoubel->end() == IntDoubleIt )
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		//CirMatIt = pCirMatrix->begin();
		CirMatIt = pCirMatrix->find( abs( iKeyOfComponent ) );
		if( pCirMatrix->end() == CirMatIt )
		{
			return 0;
		}
		pIntVector = & ( CirMatIt->second );
		return pIntVector->size();
	}
    return 0;
}


bool PFAOptimitationData::GetProperty( const int& iKeyOfComponent, const int& iProperty, const int& iPosition, int& iValueOfProperty )
{
	return ChangeProperty( iKeyOfComponent, iProperty, iPosition, true, iValueOfProperty );
}

bool PFAOptimitationData::SetProperty( const int& iKeyOfComponent, const int& iProperty, const int& iPosition, int& iValueOfProperty )
{
	return ChangeProperty( iKeyOfComponent, iProperty, iPosition, false, iValueOfProperty );
}

bool PFAOptimitationData::ChangeProperty( const int& iKeyOfComponent, const int& iProperty, const int& iPosition, const bool bChangeType, int& iValueOfProperty )
{
	// ASSERT( 0 <= iKeyOfComponent );
	ASSERT( 0 <= iProperty );
	ASSERT( 0 <= iPosition );

	ComMap* pIntVector = NULL;
	CirMatrix* pCirMat = NULL; 
	ComMap::iterator IntIt;
	CirMatrix::iterator CirMatrixIt;
	switch( iProperty )
	{
	    case 100: pCirMat = &CirPipeMatrix;
			break;
		case 101: pCirMat = &CirJunMatrix;
			break;
	    case 102: pCirMat = &PipeCirMatrix;          
	  	    break;
    	default: return false;            // 属性类型找不到
			break;
	}

	CirMatrixIt = pCirMat->find( abs( iKeyOfComponent ) ); 
	pIntVector = (ComMap*) &( CirMatrixIt->second );
	IntIt = pIntVector->begin();
	//if( GetPropertyCount( 102 ) <= iPosition)       // 管道没有对应的环
	//{                     
	//	return false;
	//}
	if( false == bChangeType )
	{
		if( pCirMat->end() == CirMatrixIt )	       // 属性的行不存在
		{
			ComMap TempVector;
			TempVector.push_back( iValueOfProperty );
			pCirMat->insert( map< int, ComMap >::value_type( abs( iKeyOfComponent ), TempVector ) );
			return true;
		}
		else
		{
			for( int i = 0; i < iPosition; i++ )     // 把迭代器移动到对应位置
			{
				IntIt++;
			}
			if( pIntVector->end() == IntIt )          // 指定的位置不存在
			{
				pIntVector->push_back( iValueOfProperty );
				return true;
			}
			else
			{
				*IntIt = iValueOfProperty;
				return true;
			}	
		}
	}
	else
	{
		if( pCirMat->end() == CirMatrixIt )
		{
			return false;
		}
		else
		{
			for( int i = 0; i < iPosition; i++ )
			{
				IntIt++;
			}
			if( pIntVector->end() == IntIt )           // 要获取的属性列不存在
			{
				return false;
			}
			else
			{
		    	iValueOfProperty = *IntIt;
				return true;
			}
		}
	}
	return true;
}


double PFAOptimitationData::GetProperty( const PropertyType& eProperty )
{
	switch( eProperty )
	{
	    case OPT_A: return dA;
			break;
		case OPT_B: return dB;
			break;
		case OPT_ALFA: return dAlfa;
			break;
		case OPT_DISINVESTMENTTIME: return dDisinvestmentTime;
			break;
		case OPT_REPAIRMODULUS: return dRepairModulus;
			break;
		case OPT_WORKEXPENDITURE: return dWorkExpenditure;
			break;
		case OPT_ELETRICITYPRICE: return dEletricityPrice;
			break;
		case OPT_ASYMMETRYMODULUS: return dAsymmetryModulus;
			break;
		case OPT_PUMPEFFICIENCY: return dPumpEfficiency;
			break;
		case OPT_K: return dKModulus;
			break;
		case OPT_M: return dMModulus;
			break;
		case OPT_N: return dNModulus;
			break;		
		case OPT_ECONOMYFACTOR: return dEconomyFactor;
			break;
		case OPT_FLUXSUMMATION: return dFluxSummation;
			break;		
		case OPT_CONSTRUCTEXPENDITURE: return dConstructExpenditure;
			break;		
		case OPT_YCONVERTEXPENDITURE : return dYConvertExpenditure;
			break;
		default: return -1.0;
			break;
	}
}

bool PFAOptimitationData::SetProperty( const PropertyType& eProperty, const double& dValueOfProperty )
{
	switch( eProperty )
	{
	    case OPT_A: dA = dValueOfProperty;
		    break;
		case OPT_B: dB = dValueOfProperty;
			break;
		case OPT_ALFA: dAlfa = dValueOfProperty;
			break;
		case OPT_DISINVESTMENTTIME: dDisinvestmentTime = dValueOfProperty;
			break;
		case OPT_REPAIRMODULUS: dRepairModulus = dValueOfProperty;
			break;
		case OPT_WORKEXPENDITURE: dWorkExpenditure = dValueOfProperty;
			break;
		case OPT_ELETRICITYPRICE: dEletricityPrice = dValueOfProperty;
			break;
		case OPT_ASYMMETRYMODULUS: dAsymmetryModulus = dValueOfProperty;
			break;
		case OPT_PUMPEFFICIENCY: dPumpEfficiency = dValueOfProperty;
			break;
		case OPT_K: dKModulus = dValueOfProperty;
			break;
		case OPT_M: dMModulus = dValueOfProperty;
			break;
		case OPT_N: dNModulus = dValueOfProperty;
			break;		
		case OPT_ECONOMYFACTOR: dEconomyFactor = dValueOfProperty;
			break;
		case OPT_FLUXSUMMATION: dFluxSummation = dValueOfProperty;
			break;		
		case OPT_CONSTRUCTEXPENDITURE: dConstructExpenditure = dValueOfProperty;
			break;		
		case OPT_YCONVERTEXPENDITURE : dYConvertExpenditure = dValueOfProperty;
			break;
		default: return false;
			break;
	}
	return true;
}


void PFAOptimitationData::RemoveAll()
{
	CirPipeMatrix.clear();     
	CirJunMatrix.clear();
	PipeCirMatrix.clear();
	PipeDummyFluxMap.clear();
	PipeFactFluxMap.clear();
	PipeLengthMap.clear();
	JunFluxMap.clear();
	PipeDiameter.clear();
	PipeWaterHammer.clear();
	PipeFluxSpeedMap.clear();
	JunPressureMap.clear();
	PipeEconomyDiameterMap.clear();
	PipeDummyWaterHammer.clear();
	PipeFactWaterHammer.clear();
	SupplyJunVector.clear();
	ControlJunVector.clear();
	DummyCircleVector.clear();
	DummyJunAndPipeVector.clear();
}