// FCFComponentMgr.cpp: implementation of the FCFComponentMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FCFComponentMgr.h"
#include "PCFPipe.h"
#include "PCFJun.h"
#include "math.h"
#include "PCFJunsMgr.h"
#include "PCFPipesMgr.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#include <vector>
using namespace std;

typedef vector<AcGePoint3d> UnJunPoint;
typedef vector<UnJunPoint> UnJunCon;
UnJunCon UnJun; 

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const CString PCFComponentMgr::m_strKeyWordArray[] =
{
	_T("TEE-SET-ON"),
	_T("SUPPORT"),
	_T("BEND"),
	_T("BEND-TEED"),
	_T("CAP"),
	_T("CLAMP"),
	_T("CONNECTOR"),
	_T("COUPLING"),
	_T("CROSS"),
	_T("CROSS-SET-ON"),
	_T("CROSS-STUB"),
	_T("ELBOLET"),
	_T("ELBOW"),
	_T("FTUBE"),
	_T("BOLT"),
	_T("ELBOW-TEED"),
	_T("FILTER"),
	_T("FILTER-ANGLE"),
	_T("FILTER-OFFSET"),
	_T("FILTER-RETURN"),
	_T("FLANGE"),
	_T("FLANGE-BLIND"),
	_T("FLANGE-REDUCING-CONCENTRIC"),
	_T("FLANGE-REDUCING-ECCENTRIC"),
	_T("GAP"),
	_T("GASKET"),
	_T("INSTRUMENT"),
	_T("INSTRUMENT-3WAY"),
	_T("INSTRUMENT-4WAY"),
	_T("INSTRUMENT-ANGLE"),
	_T("INSTRUMENT-BALLOON"),
	_T("INSTRUMENT-DIAL"),
	_T("INSTRUMENT-OFFSET"),
	_T("INSTRUMENT-RETURN"),
	_T("INSTRUMENT-TEE"),
	_T("LAPJOINT-STUBEND"),
	_T("LAPJOINT-RING"),
    _T("MESSAGE"),
	_T("MISC-COMPONENT"),
	_T("MISC-COMPONENT-ANGLE"),
	_T("MISC-COMPONENT-OFFSET"),
	_T("MISC-COMPONENT-OFFSET"),
	_T("MISC-COMPONENT-RETURN"),
	_T("MISC-HYGENIC"),
	_T("MULTI-PORT-COMPONENT"),
//	_T("NOZZLE"),
	_T("NUT"),
	_T("OLET"),
	_T("PENETRATION-PLATE"),
	_T("PIPE"),
	_T("PIPE-BLOCK-FIXED"),
	_T("PIPE-BLOCK-VARIABLE"),
	_T("PIPE-FIXED"),
	_T("REDUCER-CONCENTRIC"),
	_T("REDUCER-CONCENTRIC-TEED"),
	_T("REDUCER-ECCENTRIC"),
	_T("REDUCER-ECCENTRIC-TEED"),
	_T("REINFORCEMENT-PAD"),
	_T("SAFETY-DISC"),
	_T("TEE"),
	_T("TEE-STUB"),
	_T("TRAP"),
	_T("TRAP-ANGLE"),
	_T("TRAP-OFFSET"),
	_T("TRAP-RETURN"),
	_T("UNION"),
	_T("VALVE"),
	_T("VALVE-3WAY"),
	_T("VALVE-4WAY"),
	_T("VALVE-ANGLE"),
	_T("VALVE-MULTIWAY"),
	_T("WELD"),
	_T("Y-PIECE-FABRICATED"),
	_T("Y-PIECE-FITTING"),
	_T("END-CONNECTION-EQUIPMENT"),
	_T("END-CONNECTION-NULL"),
 	_T("ASSIGNFLOW"),
//	_T("PUMP"),   //暂时不用，使得设备字段读完
	_T("RESERVIOR"),
	_T("ASSIGNPRESS"),
	_T("SURGE"),
	_T("GASACCUM"),
	_T("LIQUIDACCUM"),
	_T("SPRAY"),
	_T("OVER")
};


PCFComponentMgr::PCFComponentMgr()
{

}

PCFComponentMgr::~PCFComponentMgr()
{

}




void PCFComponentMgr::Init(const CStringArray &strSet)
{
	int i=0;
	CStringArray lineHeaderArray ;
	for ( i = 0 ; i< strSet.GetSize() ; i++ )
	{
		if (IsKeyWord(strSet.GetAt(i)))
			break;
		lineHeaderArray.Add(strSet.GetAt(i));
	}
	m_pipeHead.Init(lineHeaderArray);

	CStringArray strPipe ;
	//去除分支头部信息后保存到strPipe中去。
	for( ; i < strSet.GetSize() ; i++)
		strPipe.Add(strSet.GetAt(i)) ;
	strPipe.Add( _T("Over"));

	InitEquipment_PT(strPipe);
  	InitNOZZLE_Ptconcet(strPipe);                 //初始化设备与分支的接点坐标
 // InitJunKey_DelDiscription( strPipe ) ;		//重新设置描述内容；
 // InitJunKey_AddPipeAndAssignFlow( strPipe ) ;	//在非法结束的元件的后面加入PIPE；
//  InitJunKey_AddAssignFlowStartBranch( strPipe ) ;	//在分支头加如指定流量；
//  InitJunKey_AddAssignFlowEndBranch( strPipe ) ;		//在分支尾加入指定流量；
// InitJunKey_NoPCFJuntoPipe( strPipe ) ;		//把不是PCF元件的关键字改为PIPE；
 // InitJunKey_MergePipe( JuntoPipe ) ;			//合并相邻的PIPE（管道）；
 // InitJunKey_KeepPtConcet( MergePipe ) ;		//保证相邻的同一个分支里面的节点相连
//  InitJunKey_DelTeeBranch( MergePipe ) ;		//保证三通cref端相连的是PIPE
//	InitJunKey_AddPipe( strPipe ) ;	//在同一个分支里面焊接的元件加管道，并创建除设备外的其他节点；
 //	InitComponet( ElementBuff1 ) ;				//创建设备节点；
	
	InitElement(strPipe);

	Init_JunPt(m_JunsMgr,m_PipesMgr);                 //初始化管道进出节点
	Init_AddPipetoJun(m_JunsMgr);                        //两个接点相连的情况，中间加管道 

	CombinationPipes(m_PipesMgr);                          // 合并相连的管道
	Init_AddPipe(m_JunsMgr,m_PipesMgr);                     //在非法结束的元件的后面加入PIPE
	InitAddAssignFlow(m_JunsMgr,m_PipesMgr);                    //加入指定流量 

	
	CombinationFit();

	TripJunLen();
	CombinationPipe();


	InitNetLink();

	


	Tran3dTo2d();
	MoveGraph();
	ChangeOrigin();
	
}

void PCFComponentMgr::Init_AddPipetoJun(PCFJunsMgr& pJunMgr)  //节点相连假如管道
{
	PCFJun* PcfJun1 = NULL;
	PCFJun* PcfJun2 = NULL;
	int n = 0;
	int i = 0;
	int j = 0;
	IteratorPtr<PCFJun> JunitPtr(pJunMgr.CreateIt());
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
			n = max(n,JunitPtr->CurrentItem().GetKey());
	}
	
	for (i = 0; i < n+1;i++)
	{
		PcfJun1 = pJunMgr.LookUp(i);
		j = i+1;
		for (;j < n+1;j++)
		{
			PcfJun2 = pJunMgr.LookUp(j);
			if(PcfJun1 == NULL || PcfJun2 == NULL)
				break;
			CampareJJPt(*PcfJun1,*PcfJun2);
		}
	}
}

BOOL PCFComponentMgr::IsKeyWord(const CString &strKeyWord)
{
	int nSize = sizeof( m_strKeyWordArray )/sizeof( CString ) ;
	for( int i = 0 ; i < nSize ; ++i)
	{
		if( !m_strKeyWordArray[i].CompareNoCase( strKeyWord ) )
			return TRUE ;
	}
	return FALSE ;
}

void PCFComponentMgr::InitElement(CStringArray &strSet)
{
	unsigned long wordnum = 0;
	unsigned long wordsize =strSet.GetSize();
	CStringArray CurElementBuff1;
	CStringArray Equipments;
	int i = 0;
	for (wordnum = 0;wordnum < wordsize;wordnum++)
	{
		if (IsKeyWord(strSet.GetAt(wordnum)) && strSet.GetAt(wordnum) != _T("Over") && strSet.GetAt(wordnum) != _T("END-CONNECTION-NULL"))
		{
			int j = wordnum;
			if (strSet.GetAt( wordnum ) == _T("CAP") || strSet.GetAt( wordnum ) == _T("FLANGE") || strSet.GetAt( wordnum ) == _T("GASKET") || strSet.GetAt( wordnum ) == _T("FBLIND") 
				|| strSet.GetAt( wordnum ) == _T("FTUBE") || strSet.GetAt(wordnum) == _T("BOLT"))
				strSet.SetAt(wordnum,_T("PIPE"));  //非PAF元件，暂时做管道处理
				do 
				{
					CurElementBuff1.Add(strSet.GetAt(j));
					j++;
				} while (!IsKeyWord(strSet.GetAt(j)));
			if (strSet.GetAt(wordnum) == _T("END-CONNECTION-EQUIPMENT"))
				InitComponet(CurElementBuff1);
			else
				CreatComponet(CurElementBuff1);
		}
		CurElementBuff1.RemoveAll();
	}
}

void PCFComponentMgr::Init_JunPt(PCFJunsMgr& pJunMgr,PCFPipesMgr& pPipeMgr)
{
	PCFPipe* pPipe = NULL;
	PCFJun* pJun = NULL;
	int k = 0;
	IteratorPtr<PCFPipe> PipeitPtr(pPipeMgr.CreateIt());
	IteratorPtr<PCFJun> JunitPtr(pJunMgr.CreateIt());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pPipe = &PipeitPtr->CurrentItem();
		for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
		{
			pJun = &JunitPtr->CurrentItem();
			k = CamparePt(*pJun,*pPipe);
		}
	}
}

void PCFComponentMgr::Init_AddPipe(PCFJunsMgr& pJunMgr,PCFPipesMgr& pPipeMgr) //非法结束节点加入管道
{
	IteratorPtr<PCFJun> JunitPtr(pJunMgr.CreateIt()); //节点列表
	IteratorPtr<PCFPipe> PipeitPtr(pPipeMgr.CreateIt()); //管道列表
	int k = 0;
	int ChoisePt = 0;
	CStringArray strPipe;
	PCFJun* pJun = NULL;
	PCFPipe *pPipe =NULL;
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next()) //遍历节点
	{
		ChoisePt = 0;
		pJun = &JunitPtr->CurrentItem();
		if(pJun->GetName() == _T("Pump") || pJun->GetName() == _T("Reservior")) //设备结束不算非法
			continue;
		for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
		{
			pPipe = &PipeitPtr->CurrentItem();
			if (pPipe == NULL || pJun == NULL)
				break;
			k = CamparePt(*pJun,*pPipe);
			ChoisePt = ChoisePt+k;
			if (ChoisePt > 2)
				break;
		}
		if (ChoisePt == 3 || ChoisePt ==0 || ChoisePt ==4 || ChoisePt ==5)
			continue;
		else
		{
			AcGePoint3d* AssignPt;
			strPipe.InsertAt(0,_T("PIPE"));
			AssignPt = pJun->GetPtList().GetTail();
			double m_bore = pPipe->Bore();
			CString strx;
			CString stry;
			CString strz;
			CString strbo;
			strx.Format(_T("%f"),AssignPt->x);
			stry.Format(_T("%f"),AssignPt->y);
			strz.Format(_T("%f"),AssignPt->z);
			strbo.Format(_T("%f"),m_bore);
			strPipe.InsertAt(1,_T("END-POINT"));
			strPipe.InsertAt(2,strx);
			strPipe.InsertAt(3,stry);
			strPipe.InsertAt(4,strz);
			strPipe.InsertAt(5,strbo);
			strPipe.InsertAt(6,"END-POINT");
			CString str1;
			CString str2;
			CString str3;
			str1.Format(_T("%f"),AssignPt->x+2);
			str2.Format(_T("%f"),AssignPt->y+2);
			str3.Format(_T("%f"),AssignPt->z+2);
			strPipe.InsertAt(7,str1);
			strPipe.InsertAt(8,str2);
			strPipe.InsertAt(9,str3);
			strPipe.InsertAt(10,strbo);
			CreatComponet(strPipe);
		}
	}
}



void PCFComponentMgr::InitAddAssignFlow(PCFJunsMgr& pJunMgr,PCFPipesMgr& pPipeMgr)  //给管道结束加入指定流量
{
	int n = 0;
	int i = 0;
	int m = 0;
	int j = 0;
	int k = 0;
	int ChoisePt = 0;
	IteratorPtr<PCFJun> JunitPtr(pJunMgr.CreateIt()); //节点列表
	IteratorPtr<PCFPipe> PipeitPtr(pPipeMgr.CreateIt()); //管道列表
	CStringArray strAssignFlow;
	PCFPipe* pPipe = NULL;
	PCFJun* pJun = NULL;
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())  //遍历管道
	{
		ChoisePt = 0;
		pPipe = &PipeitPtr->CurrentItem();
		for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next()) //遍历节点
		{
			pJun = &JunitPtr->CurrentItem();
			if(pJun == NULL || pPipe == NULL)
				break;
			k = CamparePt(*pJun,*pPipe);
			ChoisePt = ChoisePt+k;
			if (ChoisePt > 2)
				break;
		}
		if (ChoisePt == 3 || ChoisePt ==0 || ChoisePt ==4 || ChoisePt ==5) //因为三同，可能使得为4，5
			continue;
		else
		{
			AcGePoint3d AssignPt;
			strAssignFlow.InsertAt(0,_T("ASSIGNFLOW"));
			if (ChoisePt ==1)
				AssignPt = pPipe->EndPt();
			else
				AssignPt = pPipe->StartPt();
				double m_bore = pPipe->Bore();
				CString strx;
				CString stry;
				CString strz;
				CString strbo;
				strx.Format(_T("%f"),AssignPt.x);
				stry.Format(_T("%f"),AssignPt.y);
				strz.Format(_T("%f"),AssignPt.z);
				strbo.Format(_T("%f"),m_bore);
				strAssignFlow.InsertAt(1,_T("END-POINT"));
				strAssignFlow.InsertAt(2,strx);
				strAssignFlow.InsertAt(3,stry);
				strAssignFlow.InsertAt(4,strz);
				strAssignFlow.InsertAt(5,strbo);
				strAssignFlow.InsertAt(6,_T("END-POINT"));
				strAssignFlow.InsertAt(7,strx);
				strAssignFlow.InsertAt(8,stry);
				strAssignFlow.InsertAt(9,strz);
				strAssignFlow.InsertAt(10,strbo);
				CreatComponet(strAssignFlow);
		}
	}
}

int PCFComponentMgr::CamparePt(PCFJun& InJun,PCFPipe& InPipe)  //节点与管道比较
{
	AcGePoint3d* InjunPt;
	int ChoisePt = 0;
	int EndPt = 0;
	int StartPt = 0;
	int i = 0;
	AcGePoint3d InPipeStartPt = InPipe.StartPt();
	AcGePoint3d InPipeEndPt = InPipe.EndPt();
	POSITION position = InJun.GetPtList().GetHeadPosition();  //节点坐标列表
	int n = InJun.GetPtList().GetCount();
	for (i = 0;i < n;i++)
	{
		if (position != NULL)
		{
			InjunPt = InJun.GetPtList().GetNext(position);
			if (fabs((*InjunPt).x-InPipeEndPt.x)<0.1 && fabs((*InjunPt).y-InPipeEndPt.y)<0.1 && fabs((*InjunPt).z-InPipeEndPt.z)<0.1)
			{
				EndPt = 2;
				InPipe.EndPt(*InjunPt);  //如果节点与管道相连，初始管道的输入节点
				InPipe.OutJun(InJun.GetKey());
			}
			if (fabs((*InjunPt).x-InPipeStartPt.x)<0.1 && fabs((*InjunPt).y-InPipeStartPt.y)<0.1 && fabs((*InjunPt).z-InPipeStartPt.z)<0.1)
			{
				StartPt = 1;
				InPipe.StartPt(*InjunPt);
				InPipe.InJun(InJun.GetKey());
			}
		}
	}
	ChoisePt = EndPt + StartPt;
	return ChoisePt;
}

void PCFComponentMgr::CombinationPipes(PCFPipesMgr& pPipeMgr)  //合并分段的管道
{
	int i = 0;
	int j = 0;
	int n = 0; 
	IteratorPtr<PCFPipe> PipeitPtr(pPipeMgr.CreateIt());   //管道列表
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
			n = max(n,PipeitPtr->CurrentItem().GetKey());  //获得管道列表中管道ID最大的
	}
	for (i = 0;i < n+1;i++)
	{
		PCFPipe* PcfPipe1 = pPipeMgr.LookUp(i);
		j = i+1;
		for (;j < n+1;j++)
		{
			PCFPipe* PcfPipe2 = pPipeMgr.LookUp(j);  //遍历管道列表
			if(PcfPipe1 == NULL || PcfPipe2 == NULL)
				break;
			if(PcfPipe2->StartPt() == PcfPipe1->EndPt() && PcfPipe2->InJun() == 0)
			{
				PcfPipe1->EndPt(PcfPipe2->EndPt());
				pPipeMgr.Del(PcfPipe2->GetKey());//如果管道与管道相连，合并后删除其中的一个
				i--;
			}
		}
	}

}

void PCFComponentMgr::CampareJJPt(PCFJun& InJun,PCFJun& OutJun)  //节点与节点进行比较
{
	AcGePoint3d* InjunPt;
	int EndPt = 0;
	int StartPt = 0;
	int i = 0;
	int j = 0;
	AcGePoint3d* OutjunPt;
	POSITION positionIn = InJun.GetPtList().GetHeadPosition();
	int n = InJun.GetPtList().GetCount();	
	int m = OutJun.GetPtList().GetCount();           //节点的坐标列表
	for (i = 0;i < n;i++)
	{
		if (positionIn != NULL)
		{
			InjunPt = InJun.GetPtList().GetNext(positionIn);
			POSITION positionOut = OutJun.GetPtList().GetHeadPosition(); //获得节点坐标头指针位置
			for (j = 0;j < m;j++)
			{
				if (positionOut != NULL)
				{
					OutjunPt = OutJun.GetPtList().GetNext(positionOut);
					if (fabs((*InjunPt).x-(*OutjunPt).x)<0.1 && fabs((*InjunPt).y-(*OutjunPt).y)<0.1 && fabs((*InjunPt).z-(*OutjunPt).z)<0.1)
					{
						AcGePoint3d* AssignPt = NULL;               //如果存在节点坐标与节点坐标相等的情况，则插入管道
						AcGePoint3d* outpt = NULL;
						CStringArray strPipe;
						outpt = InjunPt;
						strPipe.RemoveAll();
						strPipe.InsertAt(0,_T("PIPE"));
						AssignPt = OutjunPt;
						double m_bore = 200;
						CString strx = _T(' ');
						CString stry = _T(' ');
						CString strz = _T(' ');
						CString strbo = _T(' ');
						strx.Format(_T("%f"),AssignPt->x);
						stry.Format(_T("%f"),AssignPt->y);
						strz.Format(_T("%f"),AssignPt->z);
						strbo.Format(_T("%f"),m_bore);
						strPipe.InsertAt(1,_T("END-POINT"));
						strPipe.InsertAt(2,strx);
						strPipe.InsertAt(3,stry);
						strPipe.InsertAt(4,strz);
						strPipe.InsertAt(5,strbo);
						strPipe.InsertAt(6,_T("END-POINT"));
						CString str1 = _T(' ');
						CString str2 = _T(' ');
						CString str3 = _T(' ');
						str1.Format(_T("%f"),outpt->x);
						str2.Format(_T("%f"),outpt->y);
						str3.Format(_T("%f"),outpt->z);
						strPipe.InsertAt(7,str1);
						strPipe.InsertAt(8,str2);
						strPipe.InsertAt(9,str3);
						strPipe.InsertAt(10,strbo);
						CreatComponet(strPipe);
						break;
					}
				}
			}
		}
	}
}

void PCFComponentMgr::InitNOZZLE_Ptconcet(CStringArray &strSet)
{
	unsigned long wordnum = 0;
	unsigned long wordsize = strSet.GetSize();
	unsigned long i = 0;
	int j = 0;
	CStringArray temppt;
	bool tempflag = false;
	CString tem1,tem2,tem3;

	for(wordnum = 0;wordnum < wordsize;wordnum++)
	{
		temppt.RemoveAll();
		tempflag = false;
		if (strSet.GetAt( wordnum ) == _T("NOZZLE"))
		{       
			for (i = wordnum;i < wordnum+20;i++)
			{
				if (strSet.GetAt(i) == _T("CO-ORDS"))
				{
					temppt.Add(strSet.GetAt(i+1));
					temppt.Add(strSet.GetAt(i+2));
					temppt.Add(strSet.GetAt(i+3));
					break;
				}
			}
			for (i = wordnum, j = wordnum;i < wordnum+30,j > wordnum-30;i++,j--)
			{
				if (strSet.GetAt(i) == _T("END-CONNECTION-EQUIPMENT"))
				{
					j = i;
					break;
				}
				if (strSet.GetAt(j) == _T("END-CONNECTION-EQUIPMENT"))
				{
					i = j;
					break;
				}
			}
			for (;i < j+30;i++)
			{
				if (strSet.GetAt(i) == _T("CENTRE-POINT"))
				{
					temppt.Add(strSet.GetAt(i+1));
					temppt.Add(strSet.GetAt(i+2));             
					temppt.Add(strSet.GetAt(i+3));
					tempflag = true;
					break;
				}
			}	
		}
		if(tempflag == true)
		{
			for (i = 0;i <wordsize;i++)
			{
				if (strSet.GetAt(i) == _T("END-POINT"))
				{
					if ((temppt.GetAt(0) == strSet.GetAt(i+1))&&(temppt.GetAt(1) == strSet.GetAt(i+2))&&(temppt.GetAt(2) == strSet.GetAt(i+3)))
					{
						tem1 = strSet.GetAt(i+1);
						tem2 = strSet.GetAt(i+2);
						tem3 = strSet.GetAt(i+3);
						strSet.SetAt((i+1),temppt.GetAt(3));
						strSet.SetAt((i+2),temppt.GetAt(4));
						strSet.SetAt((i+3),temppt.GetAt(5));
						tem1 = strSet.GetAt(i+1);
						tem2 = strSet.GetAt(i+2);
						tem3 = strSet.GetAt(i+3);
						break;                                   //寻找分支，将分支坐标改为设备坐标
					}
				}
			}
		}
	}
}

void PCFComponentMgr::InitEquipment_PT(CStringArray &strSet)
{
	unsigned long wordnum = 0;
	unsigned long wordsize = strSet.GetSize();
	AcGePoint3d EquipElement;
	AcGePoint3d NozzleElement;
	CString str;
	unsigned long i = 0;
	int n=0;
	int j=0;
	int m = 0;
	int k = 0;
	CStringArray temppt;
	for (wordnum = 0;wordnum < wordsize;wordnum++)
	{
		if (strSet.GetAt( wordnum ) == _T("NOZZLE"))
		{
			for (i = wordnum; i < wordnum+100; i++)
			{
				if (strSet.GetAt(i) == _T("CO-ORDS"))
				{
					temppt.Add(strSet.GetAt(i+1));
					temppt.Add(strSet.GetAt(i+2));
					temppt.Add(strSet.GetAt(i+3));
				}
				if (strSet.GetAt(i) == _T("CONNECTION-REFERENCE"))
				{
					temppt.Add(strSet.GetAt(i+1));                   //记录设备的名字
					break;
				}
			}
		}
	}
	for (i = 3; i < temppt.GetSize();)
	{
		float k = 1;
		for (j = i+4; j < temppt.GetSize();)
		{
			if(temppt.GetAt(j) == temppt.GetAt(i))
			{
				EquipElement.x = _tcstod( UELPCSTR (temppt.GetAt(j-3)), NULL );
				EquipElement.y = _tcstod( UELPCSTR (temppt.GetAt(j-2)), NULL );
				EquipElement.z = _tcstod( UELPCSTR (temppt.GetAt(j-1)), NULL );
				NozzleElement.x = _tcstod( UELPCSTR (temppt.GetAt(i-3)), NULL );
				NozzleElement.y = _tcstod( UELPCSTR (temppt.GetAt(i-2)), NULL );
				NozzleElement.z = _tcstod( UELPCSTR (temppt.GetAt(i-1)), NULL );
				CString strx;
				CString stry;
				CString strz;
				strx.Format(_T("%f"),EquipElement.x+NozzleElement.x);
				stry.Format(_T("%f"),EquipElement.y+NozzleElement.y);
				strz.Format(_T("%f"),EquipElement.z+NozzleElement.z);
				temppt.SetAt(i-3,strx);
				temppt.SetAt(i-2,stry);
				temppt.SetAt(i-1,strz);
				temppt.RemoveAt(j-3,4);
				k = k+1;
			}
			else
				j=j+4;
		}
		NozzleElement.x = _tcstod( UELPCSTR (temppt.GetAt(i-3)), NULL )/k; //k表示有几个分支即NOZZLE
		NozzleElement.y = _tcstod( UELPCSTR (temppt.GetAt(i-2)), NULL )/k;
		NozzleElement.z = _tcstod( UELPCSTR (temppt.GetAt(i-1)), NULL )/k;    
		CString str1;
		CString str2;
		CString str3;
		str1.Format(_T("%f"),NozzleElement.x);
		str2.Format(_T("%f"),NozzleElement.y);
		str3.Format(_T("%f"),NozzleElement.z);
		temppt.SetAt(i-3,str1);
		temppt.SetAt(i-2,str2);
		temppt.SetAt(i-1,str3);                    //记录设备中心点
		i=i+4;
	}
	for (wordnum = 0;wordnum < wordsize;wordnum++)
	{
		if (strSet.GetAt( wordnum ) == _T("NOZZLE"))
		{
			for (i = 3; i < temppt.GetSize();)
			{
				for (j = wordnum ;j < wordnum+50 ;j++)
				{
					if (strSet.GetAt(j) == temppt.GetAt(i))
					{
						n = wordnum;
						m = wordnum;
						for (k = 0; k < 100;k++)
						{
							n++;
							m--;
							if (strSet.GetAt(m) == _T("END-CONNECTION-EQUIPMENT"))
							{
								n = m;
								break;
							}
							if (strSet.GetAt(n) == _T("END-CONNECTION-EQUIPMENT"))
							{
								m = n;
								break;
							}
						}
						for (n = m;n < m+50;n++)                //重置设备中心点
						{
							if (strSet.GetAt(n) == _T("CENTRE-POINT"))
							{
								strSet.SetAt(n+1,temppt.GetAt(i-3));
								CString str = temppt.GetAt(i-3);
								strSet.SetAt(n+2,temppt.GetAt(i-2));
								strSet.SetAt(n+3,temppt.GetAt(i-1));
								break;
							}
						}
					}
				}
				i=i+4;
			}
		}
	}
	temppt.RemoveAll();
}

// void PCFComponentMgr::InitJunKey_DelDiscription( CStringArray &strDelDiscription )		//重新设置描述问题；
// {
// 	unsigned long wordnum ;
// 	for ( wordnum = 0; wordnum < strDelDiscription.GetSize(); wordnum ++ )		//遍历数组；
// 	{
// 		//对分之内的元件的描述内容进行遍历修改；
// 		if ( IsKeyWord( strDelDiscription.GetAt( wordnum ) ) && strDelDiscription.GetAt( wordnum ) != _T("NOZZLE")
// 			&& strDelDiscription.GetAt( wordnum ) != _T("END-CONNECTION-EQUIPMENT") && strDelDiscription.GetAt( wordnum ) != _T("END-CONNECTION-NULL") 
// 			&& strDelDiscription.GetAt( wordnum ) != _T("Over") && strDelDiscription.GetAt( wordnum ) != _T("INSTRUMENT")
// 			&& strDelDiscription.GetAt( wordnum ) != _T("FTUBE") && strDelDiscription.GetAt( wordnum ) != _T("CLOS")
// 			&& strDelDiscription.GetAt( wordnum ) != _T("WELD"))
// 		{
// 			int k = wordnum;
// 			int p = 0;
// 			int q = 0;
// 			do 
// 			{
// 				if ( strDelDiscription.GetAt( k ) == _T("PUMP") || strDelDiscription.GetAt( k ) == _T("VESS") )
// 				{
// 					break ;
// 				}
// 				if ( strDelDiscription.GetAt( k ) == _T("ITEM-DESCRIPTION") )
// 				{
// 					p = k ;		//记录ITEM-DESCRIPTION的位置
// 				}
// 				else
// 				{
// 					if ( strDelDiscription.GetAt( k ) == _T("INSULATION") )
// 					{
// 						q = k ;	//记录INSULATION的位置
// 						break ;	//跳出循环
// 					}
// 				}
// 				k ++ ;
// 			} while ( 1 );		//因为每一个元件都有上面的两个属性，所以并不会进入死循环；
// 			
// 			strDelDiscription.SetAt( ( p + 1 ), _T("unset") ) ;		//把描述的内容设置为unset；
// 			int des_size = q - p ;
// 			for ( int m = 2; m< des_size;m ++ )				//移除中间多余的字节；
// 			{				
// 				strDelDiscription.RemoveAt( ( p + m ) ) ;
// 			}
// 			wordnum = k ;    //遍历下一个元件；
// 		}
// 	}
// }
// 
// void PCFComponentMgr::InitJunKey_AddAssignFlowStartBranch( CStringArray &strAssignFlow )		//在没有连接元件的分支头加入指定流量；
// {
// 	CStringArray AddAssignFlow ;
// 	CStringArray CurCapMsg ;
// 	unsigned long wordnum ;
// 	for ( wordnum = 0; wordnum < strAssignFlow.GetSize(); wordnum ++ )		//对数组进行遍历，数组为动态的；
// 	{		//分支头为CAP开头的元件，因为在以后要把CAP变为PIPE
// 		if ( IsKeyWord( strAssignFlow.GetAt( wordnum ) ) && strAssignFlow.GetAt( wordnum ) == _T("END-CONNECTION-NULL") 
// 			 && strAssignFlow.GetAt( wordnum + 7 ) == _T("CAP") )
// 		{
// 			int m = wordnum + 7 ;
// 			int k = wordnum + 7 ;
// 			CurCapMsg.RemoveAll() ;		//在使用之前清空数组；
// 			do 
// 			{
// 				CurCapMsg.Add( strAssignFlow.GetAt( m ) ) ;
// 				m ++ ;
// 			} while ( !IsKeyWord( strAssignFlow.GetAt( m ) ) );
// 			strAssignFlow.InsertAt( k, _T("ASSIGNFLOW") ) ;			//插入指定流量
// 			strAssignFlow.InsertAt( ( k + 1 ),_T("END-POINT") ) ;
// 			strAssignFlow.InsertAt( ( k + 2 ), CurCapMsg.GetAt( 2 ) ) ;
// 			strAssignFlow.InsertAt( ( k + 3 ), CurCapMsg.GetAt( 3 ) ) ;
// 			strAssignFlow.InsertAt( ( k + 4 ), CurCapMsg.GetAt( 4 ) ) ;
// 			strAssignFlow.InsertAt( ( k + 5 ), CurCapMsg.GetAt( 5 ) ) ;
// 			strAssignFlow.InsertAt( ( k + 6 ),_T("END-POINT") ) ;
// 			strAssignFlow.InsertAt( ( k + 7 ), CurCapMsg.GetAt( 2 ) ) ;
// 			strAssignFlow.InsertAt( ( k + 8 ), CurCapMsg.GetAt( 3 ) ) ;
// 			strAssignFlow.InsertAt( ( k + 9 ), CurCapMsg.GetAt( 4 ) ) ;
// 			strAssignFlow.InsertAt( ( k + 10 ), CurCapMsg.GetAt( 5 ) ) ;
// 
// 			wordnum = 0 ;		//重新开始遍历；
// 		}
// 	}
// 
// 	for ( wordnum = 0; wordnum < strAssignFlow.GetSize(); wordnum ++ )		//对数组进行遍历；为动态的数组；
// 	{		//如果是PIPE开始的分支；
// 		if ( IsKeyWord( strAssignFlow.GetAt( wordnum ) ) && strAssignFlow.GetAt( wordnum ) == _T("END-CONNECTION-NULL") 
// 			&& strAssignFlow.GetAt( wordnum + 7 ) == _T("PIPE") )
// 		{
// 			int m = wordnum + 7 ;
// 			int k = wordnum + 7 ;
// 			bool b_conentbranch = FALSE ;
// 			CurCapMsg.RemoveAll() ;			//清空临时数组；
// 			do 
// 			{
// 				CurCapMsg.Add( strAssignFlow.GetAt( m ) ) ;
// 				m ++ ;
// 			} while ( !IsKeyWord( strAssignFlow.GetAt( m ) ) );
// 			for ( int p = 0 ;p < strAssignFlow.GetSize()-3; p ++ )		//判段是否连接了其它的分支；
// 			{
// 				double strAssignFlow1 = _tcstod( UELPCSTR (strAssignFlow.GetAt( p+1 ) ) ) ;
// 				double strAssignFlow2 = _tcstod( UELPCSTR (strAssignFlow.GetAt( p+2 ) ) ) ;
// 				double strAssignFlow3 = _tcstod( UELPCSTR (strAssignFlow.GetAt( p+3 ) ) ) ;
// 				double CurCapMsg1 = _tcstod( UELPCSTR (CurCapMsg.GetAt( 2 ) ) ) ;
// 				double CurCapMsg2 = _tcstod( UELPCSTR (CurCapMsg.GetAt( 3 ) ) ) ;
// 				double CurCapMsg3 = _tcstod( UELPCSTR (CurCapMsg.GetAt( 4 ) ) ) ;
// 				unsigned long StrminusCurCap1 = fabs( strAssignFlow1 - CurCapMsg1 ) ;
// 				unsigned long StrminusCurCap2 = fabs( strAssignFlow2 - CurCapMsg2 ) ;
// 				unsigned long StrminusCurCap3 = fabs( strAssignFlow3 - CurCapMsg3 ) ;
// 				if ( strAssignFlow.GetAt( p ) == "BRANCH1-POINT" && StrminusCurCap1 < 0.01
// 					&& StrminusCurCap2 < 0.01 && StrminusCurCap3 < 0.01 )
// 				{
// 					b_conentbranch = TRUE ;		//连接了其他的分支为真
// 					break ;
// 				}
// 			}
// 			if ( !b_conentbranch )		//如果没有连接其它的分支则插入指定流量；
// 			{
// 				strAssignFlow.InsertAt( k, _T("ASSIGNFLOW") ) ;
// 				strAssignFlow.InsertAt( ( k + 1 ),_T("END-POINT") ) ;
// 				strAssignFlow.InsertAt( ( k + 2 ), CurCapMsg.GetAt( 2 ) ) ;
// 				strAssignFlow.InsertAt( ( k + 3 ), CurCapMsg.GetAt( 3 ) ) ;
// 				strAssignFlow.InsertAt( ( k + 4 ), CurCapMsg.GetAt( 4 ) ) ;
// 				strAssignFlow.InsertAt( ( k + 5 ), CurCapMsg.GetAt( 5 ) ) ;
// 				strAssignFlow.InsertAt( ( k + 6 ),_T("END-POINT") ) ;
// 				strAssignFlow.InsertAt( ( k + 7 ), CurCapMsg.GetAt( 2 ) ) ;
// 				strAssignFlow.InsertAt( ( k + 8 ), CurCapMsg.GetAt( 3 ) ) ;
// 				strAssignFlow.InsertAt( ( k + 9 ), CurCapMsg.GetAt( 4 ) ) ;
// 				strAssignFlow.InsertAt( ( k + 10 ), CurCapMsg.GetAt( 5 ) ) ;
// 
// 				wordnum = 0 ;		//重新开始遍历；
// 			}
// 		}
// 	}
// }
// 
// void PCFComponentMgr::InitJunKey_AddAssignFlowEndBranch( CStringArray &strAssignFlow )		//在分支尾加入指定流量；
// {
// 	CStringArray AddAssignFlow ;
// 	CStringArray CurCapMsg ;
// 	unsigned long wordnum ;
//     for ( wordnum = 0; wordnum < strAssignFlow.GetSize(); wordnum ++ )	//遍历数组 ；
// 	{	//以CAP结尾时，加指定流量
// 		if ( IsKeyWord( strAssignFlow.GetAt( wordnum ) ) && strAssignFlow.GetAt( wordnum ) == _T("CAP") 
// 			&& strAssignFlow.GetAt( wordnum + 28 ) == _T("END-CONNECTION-NULL") )
// 		{
// 			int m = wordnum ;
// 			int k ;
// 			CurCapMsg.RemoveAll() ;		//清空临时数组；
// 			do 
// 			{
// 				CurCapMsg.Add( strAssignFlow.GetAt( m ) ) ;
// 				m ++ ;
// 			} while ( !IsKeyWord( strAssignFlow.GetAt( m ) ) );
// 			k = m ;
// 			strAssignFlow.InsertAt( k, _T("ASSIGNFLOW") ) ;		//插入指定流量；
// 			strAssignFlow.InsertAt( ( k + 1 ),_T("END-POINT") ) ;
// 			strAssignFlow.InsertAt( ( k + 2 ), CurCapMsg.GetAt( 7 ) ) ;
// 			strAssignFlow.InsertAt( ( k + 3 ), CurCapMsg.GetAt( 8 ) ) ;
// 			strAssignFlow.InsertAt( ( k + 4 ), CurCapMsg.GetAt( 9 ) ) ;
// 			strAssignFlow.InsertAt( ( k + 5 ), CurCapMsg.GetAt( 5 ) ) ;
// 			strAssignFlow.InsertAt( ( k + 6 ),_T("END-POINT") ) ;
// 			strAssignFlow.InsertAt( ( k + 7 ), CurCapMsg.GetAt( 7 ) ) ;
// 			strAssignFlow.InsertAt( ( k + 8 ), CurCapMsg.GetAt( 8 ) ) ;
// 			strAssignFlow.InsertAt( ( k + 9 ), CurCapMsg.GetAt( 9 ) ) ;
// 			strAssignFlow.InsertAt( ( k + 10 ), CurCapMsg.GetAt( 5 ) ) ;
// 
// 			wordnum = 0 ;		//重新开始遍历 ；
// 		}
// 	}
// 	
// 	for ( wordnum = 0; wordnum < strAssignFlow.GetSize(); wordnum ++ )		//遍历数组 ；
// 	{		//如果以PIPE结尾，则加入指定流量；
// 		if ( IsKeyWord( strAssignFlow.GetAt( wordnum ) ) && strAssignFlow.GetAt( wordnum ) == _T("PIPE") 
// 			&& strAssignFlow.GetAt( wordnum + 26 ) == _T("END-CONNECTION-NULL") )
// 		{
// 			int m = wordnum ;
// 			int k ;
// 			bool b_conentbranch = FALSE ;
// 			CurCapMsg.RemoveAll() ;			//清空临时数组 ；
// 			do 
// 			{
// 				CurCapMsg.Add( strAssignFlow.GetAt( m ) ) ;
// 				m ++ ;
// 			} while ( !IsKeyWord( strAssignFlow.GetAt( m ) ) );
// 			k = m ;
// 			for ( int p = 0 ;p < strAssignFlow.GetSize()-3; p ++ )	//判断是否接了其他的分支 ；
// 			{
// 				if ( strAssignFlow.GetAt( p ) == "BRANCH1-POINT" && strAssignFlow.GetAt( p + 1 ) == CurCapMsg.GetAt( 7 )
// 					&& strAssignFlow.GetAt( p + 2 ) == CurCapMsg.GetAt( 8 ) && strAssignFlow.GetAt( p + 3 ) == CurCapMsg.GetAt( 9 ) )
// 				{
// 					b_conentbranch = TRUE ;		//如果接了其它的分支则为真；
// 					break ;
// 				}
// 			}
// 			if ( !b_conentbranch )		//如果没有接其他的分支则插入指定流量 ；
// 			{
// 				strAssignFlow.InsertAt( k, "ASSIGNFLOW" ) ;
// 				strAssignFlow.InsertAt( ( k + 1 ),"END-POINT" ) ;
// 				strAssignFlow.InsertAt( ( k + 2 ), CurCapMsg.GetAt( 7 ) ) ;
// 				strAssignFlow.InsertAt( ( k + 3 ), CurCapMsg.GetAt( 8 ) ) ;
// 				strAssignFlow.InsertAt( ( k + 4 ), CurCapMsg.GetAt( 9 ) ) ;
// 				strAssignFlow.InsertAt( ( k + 5 ), CurCapMsg.GetAt( 10 ) ) ;
// 				strAssignFlow.InsertAt( ( k + 6 ),"END-POINT" ) ;
// 				strAssignFlow.InsertAt( ( k + 7 ), CurCapMsg.GetAt( 7 ) ) ;
// 				strAssignFlow.InsertAt( ( k + 8 ), CurCapMsg.GetAt( 8 ) ) ;
// 				strAssignFlow.InsertAt( ( k + 9 ), CurCapMsg.GetAt( 9 ) ) ;
// 				strAssignFlow.InsertAt( ( k + 10 ), CurCapMsg.GetAt( 10 ) ) ;
// 
// 				wordnum = 0 ;		//重新开始遍历 ；
// 			}
// 
// 		}
// 	}
// }
// 
// void PCFComponentMgr::InitJunKey_AddPipeAndAssignFlow( CStringArray &strPipeAndAssignFlow )  //在非法的元件的后面加入关键字；
// {
// 	CStringArray CurElement ;    //搜索到的非法结束的元件的信息 ；
// 	unsigned long wordnum = 0 ;
// 	for ( wordnum = 0; wordnum < strPipeAndAssignFlow.GetSize(); wordnum ++ )  //对数组进行遍历 ；
// 	{		//不是下面这些元件；即如果是非法元件结尾 ；
// 		if ( IsKeyWord( strPipeAndAssignFlow.GetAt( wordnum ) ) && strPipeAndAssignFlow.GetAt( wordnum ) != "PIPE"
// 			 && strPipeAndAssignFlow.GetAt( wordnum ) != "END-CONNECTION-NULL" && strPipeAndAssignFlow.GetAt( wordnum ) != "END-CONNECTION-EQUIPMENT" 
// 			 && strPipeAndAssignFlow.GetAt( wordnum ) != "Over" && strPipeAndAssignFlow.GetAt( wordnum ) != "CAP"
// 			 && strPipeAndAssignFlow.GetAt( wordnum ) != "NOZZLE" && strPipeAndAssignFlow.GetAt( wordnum ) != "VALVE"
// 			 && strPipeAndAssignFlow.GetAt( wordnum ) != "ASSIGNFLOW" && strPipeAndAssignFlow.GetAt( wordnum ) != "PUMP"
// 			 && strPipeAndAssignFlow.GetAt( wordnum ) != "VESS" && strPipeAndAssignFlow.GetAt( wordnum ) != "FLANGE" )
// 		{
// 			CurElement.RemoveAll() ;		//清空临时数组 ；
// 			int m = wordnum ;
// 			do		//保存当前节点的信息；
// 			{
// 				CurElement.Add( strPipeAndAssignFlow.GetAt( m ) ) ;
// 				m ++ ;
// 				if ( strPipeAndAssignFlow.GetAt( m ) == "PUMP" || strPipeAndAssignFlow.GetAt( m ) == "VESS" )	//遇到设备信息时继续；
// 				{
// 					continue ;
// 				}
// 			} while ( !IsKeyWord( strPipeAndAssignFlow.GetAt( m ) ) );
// 			if ( strPipeAndAssignFlow.GetAt( m ) == "END-CONNECTION-NULL" )		//如果是分支尾 ；
// 			{
// 				bool b_ConenctBranch = FALSE ;		//判断是否连接有分支 ；
// 				for ( int p = 0; p < strPipeAndAssignFlow.GetSize()-3; p ++ )
// 				{
// 					if ( ( strPipeAndAssignFlow.GetAt( p ) == "BRANCH1-POINT" || strPipeAndAssignFlow.GetAt( p ) == "END-POINT" ) && strPipeAndAssignFlow.GetAt( p + 1 ) == CurElement.GetAt( 7 )
// 						 && strPipeAndAssignFlow.GetAt( p + 2 ) == CurElement.GetAt( 8 ) && strPipeAndAssignFlow.GetAt( p + 3 ) == CurElement.GetAt( 9 ) )
// 					{
// 						b_ConenctBranch = TRUE ;	//连接了分支则为真；
// 						break ;
// 					}
// 				}
// 				if ( !b_ConenctBranch )		//如果没有连接分支，则加入管道信息；
// 				{
// 					strPipeAndAssignFlow.InsertAt( m,"PIPE" ) ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 1 ),"END-POINT" ) ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 2 ),CurElement.GetAt( 7 ) ) ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 3 ),CurElement.GetAt( 8 ) ) ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 4 ),CurElement.GetAt( 9 ) ) ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 5 ),CurElement.GetAt( 10 ) ) ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 6 ),"END-POINT" ) ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 7 ),CurElement.GetAt( 7 ) ) ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 8 ),CurElement.GetAt( 8 ) ) ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 9 ),CurElement.GetAt( 9 ) ) ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 10 ),CurElement.GetAt( 10 ) ) ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 11 ), "ITEM-CODE") ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 12 ), "PA200") ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 13 ), "FABRICATION-ITEM") ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 14 ), "WEIGHT") ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 15 ), "0.000000") ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 16 ), "ITEM-DESCRIPTION") ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 17 ), "unset") ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 18 ), "INSULATION") ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 19 ), "OFF") ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 20 ), "INSULATION-SPEC") ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 21 ), "unset") ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 22 ), "TRACING") ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 23 ), "OFF") ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 24 ), "TRACING-SPEC") ;
// 					strPipeAndAssignFlow.InsertAt( ( m + 25 ), "unset") ;
// 					wordnum = 0 ;     //重新开始遍历 ；
// 				}
// 			}
// 		}
// 	}
// 
// }
// 
// 
// void PCFComponentMgr::InitJunKey_KeepPtConcet( CStringArray &strConectPt )		//使相邻的节点之间是相连的；
// {
// 	AcGePoint3d CurElement ;	//当前节点坐标；
// 	AcGePoint3d AfterElement ;	//后一个节点坐标
// 	unsigned long wordnum ;
// 
// 	int p ;
// 	int q ;
// 	int r ;
// 
// 	double minlength = 0.5 ;
// 
// 	for ( wordnum = 0 ; wordnum < strConectPt.GetSize(); wordnum ++ )	//对数组进行遍历
// 	{
// 		if ( IsKeyWord( strConectPt.GetAt( wordnum ) ) && strConectPt.GetAt( wordnum ) != "END-CONNECTION-NULL" && strConectPt.GetAt( wordnum ) != "END-CONNECTION-EQUIPMENT" && strConectPt.GetAt( wordnum ) != "NOZZLE" )
// 		{									//当前节点保证在同一个分支中；
// 			int m = wordnum ;
// 			int num = 0 ;
// 
// 			if ( strConectPt.GetAt( wordnum ) == "Over" )	//如果是结尾则跳出循环，结束遍历；
// 			{
// 				break ;
// 			}
// 
// 			do			//保存当前节点的信息；
// 			{
// 				if ( strConectPt.GetAt( m ) == _T("END-POINT") && num == 0 )
// 				{	
// 					num++;
// 					m = m+5;
// 				
// 				}
// 				
// 				if ( strConectPt.GetAt( m ) == _T("END-POINT") && num == 1 )
// 				{			
// 					CurElement.x = _tcstod( UELPCSTR (strConectPt.GetAt( m+1 ) ) );
// 					CurElement.y = _tcstod( UELPCSTR (strConectPt.GetAt( m+2 ) ) );
// 					CurElement.z = _tcstod( UELPCSTR (strConectPt.GetAt( m+3 ) ) );
// 
// 					m = m + 5 ; 
// 				}
// 				m++ ;
// 			}while( !IsKeyWord( strConectPt.GetAt( m ) ) ); 
// 
// 			if ( strConectPt.GetAt( m ) != "END-CONNECTION-NULL" && strConectPt.GetAt( m ) != "END-CONNECTION-EQUIPMENT" && strConectPt.GetAt( m ) != "NOZZLE" )
// 			{												//下一个节点保证在一个分支中；
// 				if ( strConectPt.GetAt( m ) == "Over" )		//结束标志则退出循环；
// 				{
// 					break ;
// 				}
// 
// 				int j = m ;
// 				int k = 0 ;
// 				do			//保存下一个节点的信息；
// 				{
// 					if ( strConectPt.GetAt( j ) == _T("END-POINT") && k == 0 )
// 					{	
// 						AfterElement.x = _tcstod( UELPCSTR (strConectPt.GetAt( j+1 ) ) );
// 						AfterElement.y = _tcstod( UELPCSTR (strConectPt.GetAt( j+2 ) ) );
// 						AfterElement.z = _tcstod( UELPCSTR (strConectPt.GetAt( j+3 ) ) );
// 						p = j + 1 ;
// 						q = j + 2 ;
// 						r = j + 3 ;
// 						k++;
// 						j = j+5;
// 					
// 					}
// 				
// 					if ( strConectPt.GetAt( j ) == _T("END-POINT") && k == 1 )
// 					{			
// 						j = j+5; 
// 					}
// 
// 					j++ ;
// 				} while ( !IsKeyWord( strConectPt.GetAt( j ) ) );
// 					//当两个节点的坐标相差很小的时候就认为是相连的；
// 				if ( CurElement.x != AfterElement.x && fabs( CurElement.x - AfterElement.x ) < minlength  )
// 				{				
// 					AfterElement.x = CurElement.x ;	
// 					CString str ;
// 					str.Format( "%f",AfterElement.x ) ;
// 					strConectPt.SetAt( p, str ) ; 
// 				} 
// 
// 				if ( CurElement.y != AfterElement.y && fabs( CurElement.y - AfterElement.y ) < minlength  )
// 				{				
// 					AfterElement.y = CurElement.y ;	
// 					CString str ;
// 					str.Format( "%f",AfterElement.y ) ;
// 					strConectPt.SetAt( q, str ) ; 
// 				} 
// 
// 				if ( CurElement.z != AfterElement.z && fabs( CurElement.z - AfterElement.z ) < minlength  )
// 				{				
// 					AfterElement.z = CurElement.z ;	
// 					CString str ;
// 					str.Format( "%f",AfterElement.z ) ;
// 					strConectPt.SetAt( r, str ) ; 
// 				} 
// 
// 			
// 			}
// 			wordnum = m - 1 ;
// 		}
// 	}
// }
// 
// void PCFComponentMgr::InitJunKey_NoPCFJuntoPipe( const CStringArray &strSet )    //不是PCF节点的元件都变为PIPE
// {
// 	unsigned long wordnum = 0 ;
// 	unsigned long wordsize = strSet.GetSize() ;
// 
// 	for ( wordnum = 0 ; wordnum < wordsize ; wordnum ++ )
// 	{
// 		if ( IsKeyWord( strSet.GetAt( wordnum ) ) )    //如果当前节点是关键字且字符数组不为空;
// 		{
// 			if ( strSet.GetAt( wordnum ) == "NOZZLE" )		//由于现在不认识NOZZLE，所以在字符串中把它屏蔽掉！12/11/2008
// 			{
// 				wordnum = wordnum + 6 ;
// 				continue ;
// 			}
// 			if ( strSet.GetAt( wordnum ) == "WELD" )		//由于现在不认识NOZZLE，所以在字符串中把它屏蔽掉！12/11/2008
// 			{
// 				wordnum = wordnum + 27 ;
// 				continue ;
// 			}
// 			if ( strSet.GetAt( wordnum ) == "SUPPORT" )
// 			{
// 				wordnum = wordnum + 6 ;
// 				continue ;
// 			}
// 			if (strSet.GetAt( wordnum ) == "CAP" || strSet.GetAt( wordnum ) == "FLANGE" || strSet.GetAt( wordnum ) == "GASKET" || strSet.GetAt( wordnum ) == "FBLIND" 
// 				 || strSet.GetAt( wordnum ) == "FTUBE" )
// 			{
// 				JuntoPipe.Add( "PIPE" ) ;		//如果节点的关键字不是PCF的节点,则使其关键字为PIPE,保存到JuntoPipe字符数组中;
// 			}
// 			else
// 			{
// 				if ( strSet.GetAt( wordnum ) == "BEND" )		//如果关键字是BEND则把其统一改为ELBOW
// 				{
// 					JuntoPipe.Add( "ELBOW" ) ;
// 				}
// 				else
// 				{
// 					JuntoPipe.Add( strSet.GetAt( wordnum ) ) ;//是PCF的关键字则不做改变,保存到JuntoPipe
// 				}
// 			}
// 		}
// 		else
// 		{
// 			JuntoPipe.Add( strSet.GetAt( wordnum ) ) ;//不是关键字则保存到JuntoPipe
// 		}
// 	}
// }
// 
// void PCFComponentMgr::InitJunKey_MergePipe( const CStringArray &strMerge )
// {
// 	CStringArray MergePipe1 ;
// 	CStringArray MergePipe2 ;
// 	CStringArray strSet ;
// 	unsigned long wordnum = 0 ;
// 	unsigned long wordsize = strMerge.GetSize() ;
// 	int i = 0 ;
// 
// 	for ( wordnum = 0 ; wordnum < wordsize ; wordnum ++ )
// 	{
// 		strSet.Add( strMerge.GetAt( wordnum ) ) ;  //由于后面要对字符数组进行SetAt操作,而传过来的数组为const格式，所以要把该字符数组保存到另外一个中，以便操作；
// 	}
// 	for ( wordnum = 0 ; wordnum < strSet.GetSize() ; wordnum ++ )
// 	{
// 		if ( IsKeyWord( strSet.GetAt( wordnum ) ) && strSet.GetSize() != 0 )
// 		{
// 			if ( strSet.GetAt( wordnum ) == "PIPE" )   //如果当前关键字是PIPE
// 			{
// 				int i = wordnum ;
// 				
// 				do								//先把当前的元件的信息保存到MergePipe1中
// 				{
// 					MergePipe1.Add( strSet.GetAt( i ) ) ;
// 					i++ ;
// 				} while ( !IsKeyWord( strSet.GetAt( i ) ) ) ;
// 				
// 				if ( strSet.GetAt( i ) == _T("PIPE") )  //如果下一个关键字也是PIPE
// 				{
// 					int j = i ;
// 					do								//先把下一个元件的信息保存到MergePipe2
// 					{
// 						MergePipe2.Add( strSet.GetAt( j ) ) ;
// 						j++ ;
// 					} while ( !IsKeyWord( strSet.GetAt( j ) ) ) ;
// 					//把当前的PIPE元件的第二个坐标值改为下一个PIPE元件的第二个坐标值，即合并两个相连的PIPE
// 					strSet.SetAt( ( wordnum+7 ), MergePipe2.GetAt( 7 ) ) ;  //x坐标
// 					strSet.SetAt( ( wordnum+8 ), MergePipe2.GetAt( 8 ) ) ;  //y坐标
// 					strSet.SetAt( ( wordnum+9 ), MergePipe2.GetAt( 9 ) ) ;  //z坐标
// 					strSet.SetAt( ( wordnum+10 ), MergePipe2.GetAt( 10 ) ) ; //PIPE内径
// 
// 					int m = i ;
// 					do         //删除第二个PIPE元件的信息；
// 					{
// 						strSet.RemoveAt( m ) ;
// 						m++ ;
// 					} while ( !IsKeyWord( strSet.GetAt( m ) ) );
// 
// 					wordnum = wordnum - 1 ;  //计数减1，下一次循环还从当前节点开始，可以合并连续的多个PIPE节点；
// 					MergePipe1.RemoveAll() ; //清空MergePipe1、MergePipe2，下次再使用；
// 					MergePipe2.RemoveAll() ;
// 				}
// 				else     //下一个不是PIPE关键字则不变；
// 				{
// 					MergePipe.Add( strSet.GetAt( wordnum ) ) ;
// 				}
// 			}
// 			else    //当前不是PIPE关键字则不变；
// 			{
// 				MergePipe.Add( strSet.GetAt( wordnum ) ) ;
// 			}
// 			
// 		} 
// 		else   //不是关键字则不变；
// 		{
// 			MergePipe.Add( strSet.GetAt( wordnum ) ) ;
// 		}
// 	} 
// 		
// }

void PCFComponentMgr::InitComponet(CStringArray &strSet)
{
	CStringArray ElemeneBuff;
	unsigned long wordnum = 0 ;
	unsigned long wordsize ;
	bool PerFlag = FALSE ;
	wordsize = strSet.GetSize() ;
	int q = 0 ; 
	int b=0;
	bool tempflag=true;
			
	if ( strSet.GetSize() != 0 )		//对保存的设备节点信息进行处理；
	{
		int j;
		tempflag=true;
		for ( j = 0; j < strSet.GetSize(); j++ )		//对ElemeneBuff进行遍历，
		{
			if ( strSet.GetAt( j ) == _T("SKEY") )			//SKEY字符串后面的那个字符串即为设备关键字。
			{
				if ( strSet.GetAt( j+1 ) != _T("UNKNOW") )		//如果该字符串不为UNKNOW
				{
					if ( strSet.GetAt( j+1 ) == _T("PUMP") )
					{
						strSet.SetAt( 0, strSet.GetAt( j+1 ) ) ;  //把该节点的第一个字符串信息改为关键字
					}
					if ( strSet.GetAt( j+1 ) == _T("VESS") )
					{
						strSet.SetAt( 0, _T("RESERVIOR") ) ; 
					}					
				} 
				else		//如果为UNKNOW，则表明没有设置设备的关键字，要设置之后重新导出系统才能解析。
				{
					AfxMessageBox( _T("请检查是否所有的设备都有关键字导出，请重新导出PCF才能包含所有的设备！") ) ;
				}						
			}
		}
		for ( j = 0; j < strSet.GetSize(); j++ )
		{					
			if ( strSet.GetAt( j ) == _T("SKEY") )			//把SKEY后面的字符串信息内容改变，一个节点只有一个关键字供解析；
			{
				strSet.SetAt( ( j+1 ),_T("HAVECHANGE") ) ;
			}
		} 
		for (j=0;j<strSet.GetSize();j++)              //对设备进行遍历,对同一设备只创建一个
		{
			if (strSet.GetAt(j)==_T("CENTRE-POINT"))
			{
				ElementBuff1.Add(strSet.GetAt(j+1));
				ElementBuff1.Add(strSet.GetAt(j+2));
				ElementBuff1.Add(strSet.GetAt(j+3));
				CString str1 = strSet.GetAt(j+1);
				CString str2 = strSet.GetAt(j+2);
				CString str3 = strSet.GetAt(j+3);
				break;
			}
		}
		b=ElementBuff1.GetSize();
		if (b!=3)
		{
			for (j=0;j<b-3;)
			{
				if ((ElementBuff1.GetAt(b-3)==ElementBuff1.GetAt(j))&&(ElementBuff1.GetAt(b-2)==ElementBuff1.GetAt(j+1))&&(ElementBuff1.GetAt(b-1)==ElementBuff1.GetAt(j+2)))
				{
					tempflag=false;
					break;
				}
				j=j+3;
			}
		}
		if (tempflag==true)
		{
			CreatComponet( strSet ) ;          //创建设备节点；
		}
				//ElemeneBuff.RemoveAll() ;
	}
			//JuntoPipe.RemoveAll() ;			//清空临时数组，以备下次用
		//	MergePipe.RemoveAll() ;
			//ElementBuff1.RemoveAll() ;
}

void PCFComponentMgr::InitJunKey_DelTeeBranch( CStringArray &strDelBranch )		//保证三通连接的分支是用管道连接的；
{
	unsigned long wordnum ;
	CStringArray BranchPt ;   //三通的cref端点信息；
	CStringArray AddBranchPipe ;	//三通cref端所接元件的信息；
	CStringArray TeeStartPt ;		//三通的起点坐标信息
	CStringArray TeeEndPt ;			//三通的终点坐标信息；
//	unsigned long wordsize = strDelBranch.GetSize() ;
	for ( wordnum = 0; wordnum < strDelBranch.GetSize(); wordnum++ )	//对数组进行遍历；
	{
		BranchPt.RemoveAll() ;    //清空临时数组；
		AddBranchPipe.RemoveAll() ;
		
		if ( strDelBranch.GetAt( wordnum ) == _T("TEE") )		//如果是三通
		{
			int j ;
			j = wordnum ;

			TeeStartPt.RemoveAll() ;		//在下次使用之前清空数组；
			TeeEndPt.RemoveAll() ;
			BranchPt.RemoveAll() ;
			do 
			{
				int num = 0 ;
				if ( strDelBranch.GetAt( j ) == _T("END-POINT") && num == 0 )		//保存三通的起点坐标
				{
					TeeStartPt.Add( strDelBranch.GetAt( j ) ) ;
					TeeStartPt.Add( strDelBranch.GetAt( j + 1 ) ) ;
					TeeStartPt.Add( strDelBranch.GetAt( j + 2 ) ) ;
					TeeStartPt.Add( strDelBranch.GetAt( j + 3 ) ) ;
					num ++ ;
					j = j + 5 ;
				}
				if ( strDelBranch.GetAt( j ) == _T("END-POINT") && num == 1 )		//保存三通的终点坐标
				{
					TeeEndPt.Add( strDelBranch.GetAt( j ) ) ;
					TeeEndPt.Add( strDelBranch.GetAt( j + 1 ) ) ;
					TeeEndPt.Add( strDelBranch.GetAt( j + 2 ) ) ;
					TeeEndPt.Add( strDelBranch.GetAt( j + 3 ) ) ;
					j = j + 5 ;
				}

				if ( strDelBranch.GetAt( j ) == _T("BRANCH1-POINT") )		//保存三通的cref端坐标
				{
					BranchPt.Add( _T("END-POINT") ) ;
					BranchPt.Add( strDelBranch.GetAt( j+1 ) ) ;
					BranchPt.Add( strDelBranch.GetAt( j+2 ) ) ;
					BranchPt.Add( strDelBranch.GetAt( j+3 ) ) ;
					break ;
				}
				j++ ;
			} while ( !IsKeyWord( strDelBranch.GetAt( j ) ) );

// 			for ( int m = 0 ; m < 4 ; m ++ )		//判断起点是否等于cref端的坐标
// 			{
// 				if ( TeeStartPt.GetAt( m )  == BranchPt.GetAt( m ) )
// 				{
// 					strDelBranch.SetAt( wordnum, _T("TEECURRENT") ) ;	//如果等于表示三通是本身，改变三通的关键字，以便下次遍历数组时不会出错；
// 				}
// 			}
			//判断起点是否等于cref端的坐标
			if ( TeeStartPt.GetAt( 0 ) == BranchPt.GetAt( 0 ) && TeeStartPt.GetAt( 1 ) == BranchPt.GetAt( 1 )
				 && TeeStartPt.GetAt( 2 ) == BranchPt.GetAt( 2 ) && TeeStartPt.GetAt( 3 ) == BranchPt.GetAt( 3 ) )
			{
				strDelBranch.SetAt( wordnum, _T("TEECURRENT") ) ;	//如果等于表示三通是本身，改变三通的关键字，以便下次遍历数组时不会出错；
			}

			for ( int q = 0; q < strDelBranch.GetSize(); q++ )		//遍历数组，strDelBranch是动态的，
			{
				if ( strDelBranch.GetAt( q ) == BranchPt.GetAt( 0 ) && strDelBranch.GetAt( q + 1 ) == BranchPt.GetAt( 1 )
					 && strDelBranch.GetAt( q +2 ) == BranchPt.GetAt( 2 ) && strDelBranch.GetAt( q +3 ) == BranchPt.GetAt( 3 ) )
				{		//三通的cref端连接的其他的分支是否存在；
					if ( IsKeyWord( strDelBranch.GetAt( q - 1 ) ) && strDelBranch.GetAt( q - 1 ) != _T("PIPE") )	//连接的分支不为PIPE，并且是分支头；
					{
						int k = q - 1 ;		//记住分支头的位置
						int p = q - 1 ;
						do			//三通cref端所接元件的信息；
						{
							AddBranchPipe.Add( strDelBranch.GetAt( k ) );
							k++ ;
						} while ( !IsKeyWord( strDelBranch.GetAt( k ) ) );

						AcGePoint3d StartCurPt,EndCurPt,BaseCurPt,StartAddPt,EndAddPt;

						double long InitPipeData = 0.0 ;
						bool CurHaveBasePt = FALSE ;
						for (int m=0;m<AddBranchPipe.GetSize();m++)//得到所接节点的坐标信息
						{
							int num=0;
							if ( AddBranchPipe.GetAt(m) == _T("END-POINT") && num == 0 )  //起点坐标信息
							{	
								StartCurPt.x = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+1 ) ), NULL );
								StartCurPt.y = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+2 ) ), NULL );
								StartCurPt.z = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+3 ) ), NULL );
								InitPipeData = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+4 ) ), NULL );
								num++;
								m = m+5;
								
							}
							
							if ( AddBranchPipe.GetAt(m) == _T("END-POINT") && num == 1 )		//终点坐标信息
							{
								
								EndCurPt.x = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+1 ) ), NULL  );
								EndCurPt.y = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+2 ) ), NULL  );
								EndCurPt.z = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+3 ) ), NULL  );
								m = m+5;
							}
							
							if (AddBranchPipe.GetAt(m) == _T("CENTRE-POINT") ) //中心点坐标信息
							{
								BaseCurPt.x = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+1 ) ), NULL  );
								BaseCurPt.y = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+2 ) ), NULL  );
								BaseCurPt.z = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+3 ) ), NULL  );
								m = m+5;
								CurHaveBasePt = TRUE ;		//判断是否有中心点
							}
						}
						
						if ( !CurHaveBasePt )	//所接节点没有中心点，就在其前面加一根管道
						{
							StartAddPt = StartCurPt ; //所加管道的起点为当前节点的起点
							if ( fabs( StartCurPt.x - EndCurPt.x ) < 1 )//终点为当前节点减去一段管子的点
							{
								EndAddPt.x = StartCurPt.x ;
							} 
							else
							{
								if ( StartCurPt.x > EndCurPt.x )
								{
									EndAddPt.x = StartCurPt.x - 1 ;
								} 
								else
								{
									EndAddPt.x = StartCurPt.x + 1 ;
								}
							}
							if ( fabs( StartCurPt.y - EndCurPt.y ) < 1 )
							{
								EndAddPt.y = StartCurPt.y ;
							} 
							else
							{
								if ( StartCurPt.y > EndCurPt.y )
								{
									EndAddPt.y = StartCurPt.y - 1 ;
								} 
								else
								{
									EndAddPt.y = StartCurPt.y + 1 ;
								}
							}
							if ( fabs( StartCurPt.z - EndCurPt.z ) < 1 )
							{
								EndAddPt.z = StartCurPt.z ;
							} 
							else
							{
								if ( StartCurPt.z > EndCurPt.z )
								{
									EndAddPt.z = StartCurPt.z - 1 ;
								} 
								else
								{
									EndAddPt.z = StartCurPt.z + 1 ;
								}
							}
							StartCurPt = EndAddPt ; //当前节点的起点为所加管道的终点
							CString str ;
							str.Format(_T("%f"),StartCurPt.x ) ;		//重新设置变化的当前节点的信息
							strDelBranch.SetAt( ( p + 2 ),str ) ;
							str.Format(_T("%f"),StartCurPt.y ) ;
							strDelBranch.SetAt( ( p + 3 ),str ) ;
							str.Format(_T("%f"),StartCurPt.z ) ;
							strDelBranch.SetAt( ( p + 4 ),str ) ;

							strDelBranch.InsertAt( p,_T("PIPE") ) ;     //插入管道的信息
							strDelBranch.InsertAt( ( p + 1 ),_T("END-POINT") ) ;
							str.Format(_T("%f"),StartAddPt.x ) ;
							strDelBranch.InsertAt( ( p + 2 ),str ) ;
							str.Format(_T("%f"),StartAddPt.y ) ;
							strDelBranch.InsertAt( ( p + 3 ),str ) ;
							str.Format(_T("%f"),StartAddPt.z ) ;
							strDelBranch.InsertAt( ( p + 4 ),str ) ;
							str.Format(_T("%f"),InitPipeData ) ;
							strDelBranch.InsertAt( ( p + 5 ),str ) ;
							strDelBranch.InsertAt( ( p + 6 ),_T("END-POINT") ) ;
							str.Format(_T("%f"),EndAddPt.x ) ;
							strDelBranch.InsertAt( ( p + 7 ),str ) ;
							str.Format(_T("%f"),EndAddPt.y ) ;
							strDelBranch.InsertAt( ( p + 8 ),str ) ;
							str.Format(_T("%f"),EndAddPt.z ) ;
							strDelBranch.InsertAt( ( p + 9 ),str ) ;
							str.Format(_T("%f"),InitPipeData ) ;
							strDelBranch.InsertAt( ( p + 10 ),str ) ;
							strDelBranch.InsertAt( ( p + 11 ), _T("ITEM-CODE")) ;
							strDelBranch.InsertAt( ( p + 12 ), _T("PA150")) ;
							strDelBranch.InsertAt( ( p + 13 ), _T("FABRICATION-ITEM")) ;
							strDelBranch.InsertAt( ( p + 14 ), _T("WEIGHT")) ;
							strDelBranch.InsertAt( ( p + 15 ), _T("0.000000")) ;
							strDelBranch.InsertAt( ( p + 16 ), _T("ITEM-DESCRIPTION")) ;
							strDelBranch.InsertAt( ( p + 17 ), _T("unset")) ;
							strDelBranch.InsertAt( ( p + 18 ), _T("INSULATION")) ;
							strDelBranch.InsertAt( ( p + 19 ), _T("OFF")) ;
							strDelBranch.InsertAt( ( p + 20 ), _T("INSULATION-SPEC")) ;
							strDelBranch.InsertAt( ( p + 21 ), _T("unset")) ;
							strDelBranch.InsertAt( ( p + 22 ), _T("TRACING")) ;
							strDelBranch.InsertAt( ( p + 23 ), _T("OFF")) ;
							strDelBranch.InsertAt( ( p + 24 ), _T("TRACING-SPEC")) ;
							strDelBranch.InsertAt( ( p + 25 ), _T("unset")) ;						
						}
						else		//如果当前节点有中心点，也是在其前面加入一根管道
						{
							StartAddPt = StartCurPt ;  //起点为当前节点的起点
							if ( fabs( StartCurPt.x - BaseCurPt.x ) < 1 )	//终点为当前节点减去一小段管子；
							{
								EndAddPt.x = StartCurPt.x ; 
							} 
							else
							{
								if ( StartCurPt.x > BaseCurPt.x )
								{
									EndAddPt.x = StartCurPt.x - 1 ;
								} 
								else
								{
									EndAddPt.x = StartCurPt.x + 1 ;
								}
							}
							if ( fabs( StartCurPt.y - BaseCurPt.y ) < 1 )
							{
								EndAddPt.y = StartCurPt.y ; 
							} 
							else
							{
								if ( StartCurPt.y > BaseCurPt.y )
								{
									EndAddPt.y = StartCurPt.y - 1 ;
								} 
								else
								{
									EndAddPt.y = StartCurPt.y + 1 ;
								}
							}
							if ( fabs( StartCurPt.z - BaseCurPt.z ) < 1 )
							{
								EndAddPt.z = StartCurPt.z ; 
							} 
							else
							{
								if ( StartCurPt.z > BaseCurPt.z )
								{
									EndAddPt.z = StartCurPt.z - 1 ;
								} 
								else
								{
									EndAddPt.z = StartCurPt.z + 1 ;
								}
							}
							StartCurPt = EndAddPt ;	//当前节点的起点为所加管道的终点；
							CString str ;
							str.Format(_T("%f"),StartCurPt.x ) ;	//重新设置改变的当前节点的信息；
							strDelBranch.SetAt( ( p + 2 ),str ) ;
							str.Format(_T("%f"),StartCurPt.y ) ;
							strDelBranch.SetAt( ( p + 3 ),str ) ;
							str.Format(_T("%f"),StartCurPt.z ) ;
							strDelBranch.SetAt( ( p + 4 ),str ) ;
							
							strDelBranch.InsertAt( p,_T("PIPE") ) ;		//插入管道的信息；
							strDelBranch.InsertAt( ( p + 1 ),_T("END-POINT") ) ;
							str.Format(_T("%f"),StartAddPt.x ) ;
							strDelBranch.InsertAt( ( p + 2 ),str ) ;
							str.Format(_T("%f"),StartAddPt.y ) ;
							strDelBranch.InsertAt( ( p + 3 ),str ) ;
							str.Format(_T("%f"),StartAddPt.z ) ;
							strDelBranch.InsertAt( ( p + 4 ),str ) ;
							str.Format(_T("%f"),InitPipeData ) ;
							strDelBranch.InsertAt( ( p + 5 ),str ) ;
							strDelBranch.InsertAt( ( p + 6 ),_T("END-POINT") ) ;
							str.Format(_T("%f"),EndAddPt.x ) ;
							strDelBranch.InsertAt( ( p + 7 ),str ) ;
							str.Format(_T("%f"),EndAddPt.y ) ;
							strDelBranch.InsertAt( ( p + 8 ),str ) ;
							str.Format(_T("%f"),EndAddPt.z ) ;
							strDelBranch.InsertAt( ( p + 9 ),str ) ;
							str.Format(_T("%f"),InitPipeData ) ;
							strDelBranch.InsertAt( ( p + 10 ),str ) ;
							strDelBranch.InsertAt( ( p + 11 ), _T("ITEM-CODE")) ;
							strDelBranch.InsertAt( ( p + 12 ), _T("PA150")) ;
							strDelBranch.InsertAt( ( p + 13 ), _T("FABRICATION-ITEM")) ;
							strDelBranch.InsertAt( ( p + 14 ), _T("WEIGHT")) ;
							strDelBranch.InsertAt( ( p + 15 ), _T("0.000000")) ;
							strDelBranch.InsertAt( ( p + 16 ), _T("ITEM-DESCRIPTION")) ;
							strDelBranch.InsertAt( ( p + 17 ), _T("unset")) ;
							strDelBranch.InsertAt( ( p + 18 ), _T("INSULATION")) ;
							strDelBranch.InsertAt( ( p + 19 ), _T("OFF")) ;
							strDelBranch.InsertAt( ( p + 20 ), _T("INSULATION-SPEC")) ;
							strDelBranch.InsertAt( ( p + 21 ), _T("unset")) ;
							strDelBranch.InsertAt( ( p + 22 ), _T("TRACING")) ;
							strDelBranch.InsertAt( ( p + 23 ), _T("OFF")) ;
							strDelBranch.InsertAt( ( p + 24 ), _T("TRACING-SPEC")) ;
							strDelBranch.InsertAt( ( p + 25 ), _T("unset")) ;
						}
 						wordnum = 0 ;		//把wordnum设置为0重新循环遍历
 						break ;
					}
									//如果所接节点为分支尾的处理；
					if ( IsKeyWord( strDelBranch.GetAt( q - 6 ) ) && strDelBranch.GetAt( q - 6 ) != _T("PIPE") )
					{
						int k = q - 6 ;//记录该节点的位置；
						int p = q - 6 ;
						do		//得到该节点的信息；
						{
							AddBranchPipe.Add( strDelBranch.GetAt( k ) );
							k++ ;
						} while ( !IsKeyWord( strDelBranch.GetAt( k ) ) );
						
						AcGePoint3d StartCurPt,EndCurPt,BaseCurPt,StartAddPt,EndAddPt;
						
						double long InitPipeData = 0.0 ;
						bool CurHaveBasePt = FALSE ;
						for (int m=0;m<AddBranchPipe.GetSize();m++)		//对当前节点的坐标信息遍历；
						{
							int num=0;
							if ( AddBranchPipe.GetAt(m) == _T("END-POINT") && num == 0 )	//起点坐标
							{	
								StartCurPt.x = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+1 ) ), NULL );
								StartCurPt.y = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+2 ) ), NULL );
								StartCurPt.z = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+3 ) ), NULL );								
								num++;
								m = m+5;
								
							}
							
							if ( AddBranchPipe.GetAt(m) == _T("END-POINT") && num == 1 )	//终点坐标
							{
								
								EndCurPt.x = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+1 ) ), NULL );
								EndCurPt.y = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+2 ) ), NULL );
								EndCurPt.z = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+3 ) ), NULL );
								InitPipeData = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+4 ) ), NULL );
								m = m+5;
							}
							
							if (AddBranchPipe.GetAt(m) == _T("CENTRE-POINT"))		//中心点坐标
							{
								BaseCurPt.x = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+1 ) ), NULL );
								BaseCurPt.y = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+2 ) ), NULL );
								BaseCurPt.z = _tcstod( UELPCSTR (AddBranchPipe.GetAt( m+3 ) ), NULL );
								m = m+5;
								CurHaveBasePt = TRUE ;		//判断是否有中心点
							}
						}
						if ( !CurHaveBasePt )		//没有中心点，在当前节点的后面加一根管道
						{
							EndAddPt = EndCurPt ;	//所加管道的终点为当前节点的终点
							if ( fabs( StartCurPt.x - EndCurPt.x ) < 1 )		//所加管道的起点为当前节点的起点减去一小部分
							{
								StartAddPt.x = StartCurPt.x ;
							} 
							else
							{
								if ( StartCurPt.x > EndCurPt.x )
								{
									StartAddPt.x = EndCurPt.x + 1 ;
								} 
								else
								{
									StartAddPt.x = EndCurPt.x - 1 ;
								}
							}
							if ( fabs( StartCurPt.y - EndCurPt.y ) < 1 )
							{
								StartAddPt.y = StartCurPt.y ;
							} 
							else
							{
								if ( StartCurPt.y > EndCurPt.y )
								{
									StartAddPt.y = EndCurPt.y + 1 ;
								} 
								else
								{
									StartAddPt.y = EndCurPt.y - 1 ;
								}
							}
							if ( fabs( StartCurPt.z - EndCurPt.z ) < 1 )
							{
								StartAddPt.z = StartCurPt.z ;
							} 
							else
							{
								if ( StartCurPt.z > EndCurPt.z )
								{
									StartAddPt.z = EndCurPt.z + 1 ;
								} 
								else
								{
									StartAddPt.z = EndCurPt.z - 1 ;
								}
							}
							EndCurPt = StartAddPt ;		//当前节点的终点坐标为所加管段的开始坐标
							CString str ;
							str.Format(_T("%f"),EndCurPt.x ) ;	//重新设置一下改变了的当前节点改变了的坐标
							strDelBranch.SetAt( ( p + 7 ),str ) ;
							str.Format(_T("%f"),EndCurPt.y ) ;
							strDelBranch.SetAt( ( p + 8 ),str ) ;
							str.Format(_T("%f"),EndCurPt.z ) ;
							strDelBranch.SetAt( ( p + 9 ),str ) ;
							
							strDelBranch.InsertAt( k,_T("PIPE") ) ;	//插入所加管道的信息
							strDelBranch.InsertAt( ( k + 1 ),_T("END-POINT") ) ;
							str.Format(_T("%f"),StartAddPt.x ) ;
							strDelBranch.InsertAt( ( k + 2 ),str ) ;
							str.Format(_T("%f"),StartAddPt.y ) ;
							strDelBranch.InsertAt( ( k + 3 ),str ) ;
							str.Format(_T("%f"),StartAddPt.z ) ;
							strDelBranch.InsertAt( ( k + 4 ),str ) ;
							str.Format(_T("%f"),InitPipeData ) ;
							strDelBranch.InsertAt( ( k + 5 ),str ) ;
							strDelBranch.InsertAt( ( k + 6 ),_T("END-POINT") ) ;
							str.Format(_T("%f"),EndAddPt.x ) ;
							strDelBranch.InsertAt( ( k + 7 ),str ) ;
							str.Format(_T("%f"),EndAddPt.y ) ;
							strDelBranch.InsertAt( ( k + 8 ),str ) ;
							str.Format(_T("%f"),EndAddPt.z ) ;
							strDelBranch.InsertAt( ( k + 9 ),str ) ;
							str.Format(_T("%f"),InitPipeData ) ;
							strDelBranch.InsertAt( ( k + 10 ),str ) ;
							strDelBranch.InsertAt( ( k + 11 ), _T("ITEM-CODE")) ;
							strDelBranch.InsertAt( ( k + 12 ), _T("PA150")) ;
							strDelBranch.InsertAt( ( k + 13 ), _T("FABRICATION-ITEM")) ;
							strDelBranch.InsertAt( ( k + 14 ), _T("WEIGHT")) ;
							strDelBranch.InsertAt( ( k + 15 ), _T("0.000000")) ;
							strDelBranch.InsertAt( ( k + 16 ), _T("ITEM-DESCRIPTION")) ;
							strDelBranch.InsertAt( ( k + 17 ), _T("unset")) ;
							strDelBranch.InsertAt( ( k + 18 ), _T("INSULATION")) ;
							strDelBranch.InsertAt( ( k + 19 ), _T("OFF")) ;
							strDelBranch.InsertAt( ( k + 20 ), _T("INSULATION-SPEC")) ;
							strDelBranch.InsertAt( ( k + 21 ), _T("unset")) ;
							strDelBranch.InsertAt( ( k + 22 ), _T("TRACING")) ;
							strDelBranch.InsertAt( ( k + 23 ), _T("OFF")) ;
							strDelBranch.InsertAt( ( k + 24 ), _T("TRACING-SPEC")) ;
							strDelBranch.InsertAt( ( k + 25 ), _T("unset")) ;	

						} 
						else		//如果有中心点，也在当前节点的后面加一根管道；
						{
							EndAddPt = EndCurPt ;	//所加管道的终点坐标为当前节点的终点坐标
							if ( fabs( EndCurPt.x - BaseCurPt.x ) < 1 )		//所加管道的起点坐标为当前节点的终点坐标减去一小段；
							{
								StartAddPt.x = EndCurPt.x ; 
							} 
							else
							{
								if ( EndCurPt.x > BaseCurPt.x )
								{
									StartAddPt.x = EndCurPt.x - 1 ;
								} 
								else
								{
									StartAddPt.x = EndCurPt.x + 1 ;
								}
							}
							if ( fabs( EndCurPt.y - BaseCurPt.y ) < 1 )
							{
								StartAddPt.y = EndCurPt.y ; 
							} 
							else
							{
								if ( EndCurPt.y > BaseCurPt.y )
								{
									StartAddPt.y = EndCurPt.y - 1 ;
								} 
								else
								{
									StartAddPt.y = EndCurPt.y + 1 ;
								}
							}
							if ( fabs( EndCurPt.z - BaseCurPt.z ) < 1 )
							{
								StartAddPt.z = EndCurPt.z ; 
							} 
							else
							{
								if ( EndCurPt.z > BaseCurPt.z )
								{
									StartAddPt.z = EndCurPt.z - 1 ;
								} 
								else
								{
									StartAddPt.z = EndCurPt.z + 1 ;
								}
							}
							EndCurPt = StartAddPt ;		//当前节点的终点坐标为所加管道的起点坐标
							CString str ;
							str.Format(_T("%f"),EndCurPt.x ) ;		//重新设置当前节点改变了的终点的坐标；
							strDelBranch.SetAt( ( p + 7 ),str ) ;
							str.Format(_T("%f"),EndCurPt.y ) ;
							strDelBranch.SetAt( ( p + 8 ),str ) ;
							str.Format(_T("%f"),EndCurPt.z ) ;
							strDelBranch.SetAt( ( p + 9 ),str ) ;
							
							strDelBranch.InsertAt( k,_T("PIPE") ) ;		//插入所加管道的信息
							strDelBranch.InsertAt( ( k + 1 ),_T("END-POINT") ) ;
							str.Format(_T("%f"),StartAddPt.x ) ;
							strDelBranch.InsertAt( ( k + 2 ),str ) ;
							str.Format(_T("%f"),StartAddPt.y ) ;
							strDelBranch.InsertAt( ( k + 3 ),str ) ;
							str.Format(_T("%f"),StartAddPt.z ) ;
							strDelBranch.InsertAt( ( k + 4 ),str ) ;
							str.Format(_T("%f"),InitPipeData ) ;
							strDelBranch.InsertAt( ( k + 5 ),str ) ;
							strDelBranch.InsertAt( ( k + 6 ),_T("END-POINT") ) ;
							str.Format(_T("%f"),EndAddPt.x ) ;
							strDelBranch.InsertAt( ( k + 7 ),str ) ;
							str.Format(_T("%f"),EndAddPt.y ) ;
							strDelBranch.InsertAt( ( k + 8 ),str ) ;
							str.Format(_T("%f"),EndAddPt.z ) ;
							strDelBranch.InsertAt( ( k + 9 ),str ) ;
							str.Format(_T("%f"),InitPipeData ) ;
							strDelBranch.InsertAt( ( k + 10 ),str ) ;
							strDelBranch.InsertAt( ( k + 11 ), _T("ITEM-CODE")) ;
							strDelBranch.InsertAt( ( k + 12 ), _T("PA150")) ;
							strDelBranch.InsertAt( ( k + 13 ), _T("FABRICATION-ITEM")) ;
							strDelBranch.InsertAt( ( k + 14 ), _T("WEIGHT")) ;
							strDelBranch.InsertAt( ( k + 15 ), _T("0.000000")) ;
							strDelBranch.InsertAt( ( k + 16 ), _T("ITEM-DESCRIPTION")) ;
							strDelBranch.InsertAt( ( k + 17 ), _T("unset")) ;
							strDelBranch.InsertAt( ( k + 18 ), _T("INSULATION")) ;
							strDelBranch.InsertAt( ( k + 19 ), _T("OFF")) ;
							strDelBranch.InsertAt( ( k + 20 ), _T("INSULATION-SPEC")) ;
							strDelBranch.InsertAt( ( k + 21 ), _T("unset")) ;
							strDelBranch.InsertAt( ( k + 22 ), _T("TRACING")) ;
							strDelBranch.InsertAt( ( k + 23 ), _T("OFF")) ;
							strDelBranch.InsertAt( ( k + 24 ), _T("TRACING-SPEC")) ;
							strDelBranch.InsertAt( ( k + 25 ), _T("unset")) ;	

						}

						wordnum = 0 ;		//把wordnum设置为0，退出循环重新遍历；
						break ;
					}


				}
				
			}
		}
	}
	for (int m = 0 ; m < strDelBranch.GetSize(); m ++ )		//如果有当前节点则把当前节点的关键字重新改为TEE
	{
		if ( strDelBranch.GetAt( m ) == _T("TEECURRENT") )
		{
			strDelBranch.SetAt( m, _T("TEE") ) ;
		}
	} 
}
/*
void PCFComponentMgr::InitJunKey_BranchtoPipe( CStringArray &strBranch )
{
	unsigned long wordnum ;
	CStringArray branch ;
	CStringArray ElementBranch ;

	for ( wordnum = 0; wordnum < strBranch.GetSize(); wordnum++ )
	{
		if ( IsKeyWord( strBranch.GetAt( wordnum ) ) && ElementBranch.GetSize() != 0 )
		{
			CreatComponet( ElementBranch ) ;
			ElementBranch.RemoveAll() ;
		}
		ElementBranch.Add( strBranch.GetAt( wordnum ) ) ;
	}
}
*/
// void PCFComponentMgr::InitJunKey_SearchAndAdd( CStringArray &strSearchadd )
// {
// 	CStringArray TeeBranch ;
// 	unsigned long wordnum ;
// 	for ( wordnum = 0; wordnum < strSearchadd.GetSize() wordnum ++ )
// 	{
// 		
// 	}
// }

void PCFComponentMgr::InitJunKey_AddPipe(const CStringArray &strSet)
{
	CStringArray PerElement;
	CStringArray CurElement;
	CStringArray AddPerElement;
	CStringArray AddCurElement;
	CStringArray PipeAftElement;

	CStringArray ElementBuff;
	
	unsigned long wordnum = 0;
	unsigned long wordsize ;
	wordsize = strSet.GetSize();
	BOOL PerFlag=FALSE;
	BOOL PipeFlag=FALSE;
	for ( wordnum = 0; wordnum < wordsize; wordnum++ )
	{
		ElementBuff1.Add( strSet.GetAt( wordnum ) ) ;
	}

	for( wordnum = 0; wordnum < ElementBuff1.GetSize(); wordnum++)
	{
	
		if( IsKeyWord(ElementBuff1.GetAt(wordnum) ) && ElementBuff1.GetAt( wordnum ) != _T("PUMP") && ElementBuff1.GetAt( wordnum ) != _T("VESS")
			&& ( ElementBuff.GetSize() != 0 ) )					//因为在数组中PUMP和VESS都是关键字，所以先要排除，以后要有什么设备也要排除，否则会多建几个设备的；
		{	
			
			if (PerFlag) //如果前一个不是节点则把前一个创建元件。
 			{
				CreatComponet(ElementBuff);
				PerFlag=FALSE;
 			}


			BOOL flag=FALSE;
			double MinPipeLength=0.01;
			double MinLength=0.001;
			if ( ElementBuff1.GetAt(wordnum)==_T("PIPE") || ElementBuff1.GetAt(wordnum)==_T("END-CONNECTION-EQUIPMENT") || ElementBuff1.GetAt(wordnum)==_T("END-CONNECTION-NULL")
				 || ElementBuff1.GetAt(wordnum)==_T("ASSIGNFLOW") )
			{
				flag=TRUE;//当前的是不是节点，不是(TRUE)，是(FALSE)
			}

			if (!flag&&ElementBuff1.GetAt(wordnum)!=_T("Over"))//如果是节点并且没有到.pcf文件的结束标志则保存为要创建管段所需要的信息（后面将判断是否创建管段）
			{


				for (int i=0;i<ElementBuff.GetSize();i++)
				{
					PerElement.Add(ElementBuff.GetAt(i));
				}
				
				int j=wordnum;
				
				do 
				{
					CurElement.Add(ElementBuff1.GetAt(j));
					j++;
				} while (!IsKeyWord(ElementBuff1.GetAt(j)));
				
			
				AcGePoint3d StartPerPt;
				AcGePoint3d EndPerPt;
				AcGePoint3d StartCurPt;
				AcGePoint3d EndCurPt;
		
				AcGePoint3d StartPerPipePt;
				AcGePoint3d EndPerPipept;

				AcGePoint3d BasePerPt;
				AcGePoint3d BaseCurPt;

				BOOL PerHaveBasePt=FALSE;
				BOOL CurHaveBasePt=FALSE;

				double InPipeData=0.0;//得到当前节点的内径
				for (int m=0;m<PerElement.GetSize();m++)//得到前一个节点的坐标信息
				{
					int num=0;
 					if ( PerElement.GetAt(m) == _T("END-POINT") && num == 0 )
					{	
						StartPerPt.x = _tcstod( UELPCSTR (PerElement.GetAt( m+1 ) ), NULL );
						StartPerPt.y = _tcstod( UELPCSTR (PerElement.GetAt( m+2 ) ), NULL );
						StartPerPt.z = _tcstod( UELPCSTR (PerElement.GetAt( m+3 ) ), NULL );
					
						num++;
						m = m+5;
				 				
					}
				 				
					if ( PerElement.GetAt(m) == _T("END-POINT") && num == 1 )
					{

						EndPerPt.x = _tcstod( UELPCSTR (PerElement.GetAt( m+1 ) ), NULL );
					 	EndPerPt.y = _tcstod( UELPCSTR (PerElement.GetAt( m+2 ) ), NULL );
						EndPerPt.z = _tcstod( UELPCSTR (PerElement.GetAt( m+3 ) ), NULL );
						m = m+5;
					}

					if (PerElement.GetAt(m) == _T("CENTRE-POINT") )
					{
						BasePerPt.x = _tcstod( UELPCSTR (PerElement.GetAt( m+1 ) ), NULL );
						BasePerPt.y = _tcstod( UELPCSTR (PerElement.GetAt( m+2 ) ), NULL );
						BasePerPt.z = _tcstod( UELPCSTR (PerElement.GetAt( m+3 ) ), NULL );
						m = m+5;
						PerHaveBasePt=TRUE;
					}
				}

				
				for (int mTemp =0; mTemp<CurElement.GetSize(); mTemp++)  //得到当前节点的坐标信息
				{
					int num=0;
					if ( CurElement.GetAt(mTemp) == _T("END-POINT") && num == 0 )
					{	
						StartCurPt.x = _tcstod( (UELPCSTR)(CurElement.GetAt( mTemp+1 ) ), NULL );
						StartCurPt.y = _tcstod( (UELPCSTR)(CurElement.GetAt( mTemp+2 ) ), NULL );
						StartCurPt.z = _tcstod( (UELPCSTR)(CurElement.GetAt( mTemp+3 ) ), NULL );
						InPipeData = _tcstod( (UELPCSTR)(CurElement.GetAt( mTemp+4 ) ), NULL );
						num++;
						mTemp = mTemp+5;
						
					}
				
					if ( CurElement.GetAt(mTemp) == _T("END-POINT") && num == 1 )
					{			
						EndCurPt.x = _tcstod( (UELPCSTR)(CurElement.GetAt( mTemp+1 ) ), NULL );
						EndCurPt.y = _tcstod( (UELPCSTR)(CurElement.GetAt( mTemp+2 ) ), NULL );
						EndCurPt.z = _tcstod( (UELPCSTR)(CurElement.GetAt( mTemp+3 ) ), NULL );
						mTemp = mTemp+5; 
					}

					if (CurElement.GetAt(mTemp) == _T("CENTRE-POINT"))
					{
						BaseCurPt.x = _tcstod( (UELPCSTR)(CurElement.GetAt( mTemp+1 ) ), NULL );
						BaseCurPt.y = _tcstod( (UELPCSTR)(CurElement.GetAt( mTemp+2 ) ), NULL );
						BaseCurPt.z = _tcstod( (UELPCSTR)(CurElement.GetAt( mTemp+3 ) ), NULL );
						CurHaveBasePt=TRUE;
					}
				}

				
					//(1,都没基点；2,当前的没，前一个有；3，都有基点；4，当前的有，前一个没)
					if(!PerHaveBasePt&&CurHaveBasePt)//4，如果当前的节点有基点，前一个节点没有基点，就加一个管段，
					{
						StartPerPipePt=StartCurPt;   //管段的起点为当前节点的起点，
						if (abs(StartPerPt.x-EndPerPt.x)<MinLength)    //终点为前一个节点的终点(其实和当前节点的起点坐标相同，但如果用当前节点的起点所加管段的流向就会相反，不知为什么)减去所加的管段。
						{
							EndPerPipept.x=EndPerPt.x;
						}
						else
						{
							if (EndPerPt.x>0)
							{
								EndPerPipept.x=EndPerPt.x+MinPipeLength;
							} 
							else
							{
								EndPerPipept.x=EndPerPt.x-MinPipeLength;
							}
							
						}
						
						if (abs(StartPerPt.y-EndPerPt.y)<MinLength)
						{
							EndPerPipept.y=EndPerPt.y;
						}
						else
						{
							
							if (EndPerPt.y>0)
							{
								EndPerPipept.y=EndPerPt.y+MinPipeLength;
							} 
							else
							{
								EndPerPipept.y=EndPerPt.y-MinPipeLength;
							}
							
						}
						
						if (abs(StartPerPt.z-EndPerPt.z)<MinLength)
						{
							EndPerPipept.z=EndPerPt.z;
						} 
						else
						{
							if (EndPerPt.z>0)
							{
								EndPerPipept.z=EndPerPt.z-MinPipeLength;
							} 
							else
							{
								EndPerPipept.z=EndPerPt.z-MinPipeLength;
							}
							
						}
						StartCurPt=EndPerPipept;     //则当前的节点的起点坐标为所加管段的终点坐标。
					}
					else         //1，2，3的情况也要加管段。
					{
						if (PerHaveBasePt&&!CurHaveBasePt)  //2，如果前一个节点有基点，当前节点没有基点。(这一步主要是保证不在弯头上取管段，使流向不会相反)
						{
							StartPerPipePt=StartCurPt;      //所加管段的起点为当前节点的起点
							if (abs(StartPerPt.x-EndPerPt.x)<MinLength)  //终点为前一个节点的终点(其实和当前节点的起点坐标相同，但如果用当前节点的起点所加管段的流向就会相反，不知为什么)减去所加的管段。
							{
								EndPerPipept.x=EndPerPt.x;
							}
							else
							{
								if (EndPerPt.x>0)
								{
									EndPerPipept.x=EndPerPt.x+MinPipeLength;
								} 
								else
								{
									EndPerPipept.x=EndPerPt.x-MinPipeLength;
								}
								
							}
							
							if (abs(StartPerPt.y-EndPerPt.y)<MinLength)
							{
								EndPerPipept.y=EndPerPt.y;
							}
							else
							{
								
								if (EndPerPt.y>0)
								{
									EndPerPipept.y=EndPerPt.y+MinPipeLength;
								} 
								else
								{
									EndPerPipept.y=EndPerPt.y-MinPipeLength;
								}
								
							}
							
							if (abs(StartPerPt.z-EndPerPt.z)<MinLength)
							{
								EndPerPipept.z=EndPerPt.z;
							} 
							else
							{
								if (EndPerPt.z>0)
								{
									EndPerPipept.z=EndPerPt.z-MinPipeLength;
								} 
								else
								{
									EndPerPipept.z=EndPerPt.z-MinPipeLength;
								}
								
							}
						StartCurPt=EndPerPipept;   //则当前的节点的起点坐标为所加管段的终点坐标。
						}
						else           //1，都没基点；3，都有基点
						{
							if (!PerHaveBasePt&&!CurHaveBasePt)  //1，都没基点；
							{
								StartPerPipePt=StartCurPt;      //所加管段的起点为当前节点的起点
								if (abs(StartCurPt.x-EndPerPt.x)<MinLength)  //终点为前一个节点的终点减去所加的管段。
								{
									EndPerPipept.x=StartCurPt.x;
								}
								else
								{
									if (StartCurPt.x>0)
									{
										EndPerPipept.x=StartCurPt.x+MinPipeLength;
									} 
									else
									{
										EndPerPipept.x=StartCurPt.x-MinPipeLength;
									}
									
								}
								
								if (abs(StartCurPt.y-EndPerPt.y)<MinLength)
								{
									EndPerPipept.y=StartCurPt.y;
								}
								else
								{
									
									if (StartCurPt.y>0)
									{
										EndPerPipept.y=StartCurPt.y+MinPipeLength;
									} 
									else
									{
										EndPerPipept.y=StartCurPt.y-MinPipeLength;
									}
									
								}
								
								if (abs(StartCurPt.z-EndPerPt.z)<MinLength)
								{
									EndPerPipept.z=StartCurPt.z;
								} 
								else
								{
									if (StartCurPt.z>0)
									{
										EndPerPipept.z=StartCurPt.z-MinPipeLength;
									} 
									else
									{
										EndPerPipept.z=StartCurPt.z-MinPipeLength;
									}
									
								}
								StartCurPt=EndPerPipept;   //则当前的节点的起点坐标为所加管段的终点坐标。								
							} 
							else   //3，都有基点							
							{
								EndPerPipept=StartCurPt;  //管段的终点为当前节点的起点
								if (abs(BasePerPt.x-StartCurPt.x)<MinLength)  //终点为当前节点的起点减去所加的管段
								{
									StartPerPipePt.x=StartCurPt.x;
								}
								else
								{
									if (StartCurPt.x>0)
									{
										StartPerPipePt.x=EndPerPt.x+MinPipeLength;
									} 
									else
									{
										StartPerPipePt.x=EndPerPt.x-MinPipeLength;
									}
									
								}
								
								if (abs(BasePerPt.y-StartCurPt.y)<MinLength)
								{
									StartPerPipePt.y=EndPerPt.y;
								}
								else
								{
									if (StartCurPt.y>0)
									{
										StartPerPipePt.y=EndPerPt.y+MinPipeLength;
									} 
									else
									{
										StartPerPipePt.y=EndPerPt.y-MinPipeLength;
									}
									
								}
								
								if (abs(BasePerPt.z-StartCurPt.z)<MinLength)
								{
									StartPerPipePt.z=EndPerPt.z;
								} 
								else
								{
									if (StartCurPt.z>0)
									{
										StartPerPipePt.z=EndPerPt.z+MinPipeLength;
									} 
									else
									{
										StartPerPipePt.z=EndPerPt.z-MinPipeLength;
									}
									
								}
								EndPerPt=StartPerPipePt;  //当前节点的起点变为所加管道的终点。
							}
						}

					}
				
 				

				CString str;         //所加管道的信息
				AddPerElement.Add(_T("PIPE"));
				AddPerElement.Add(_T("END-POINT"));
				str.Format(_T("%f"),StartPerPipePt.x);
				AddPerElement.Add(str);
				str.Format(_T("%f"),StartPerPipePt.y);
				AddPerElement.Add(str);
				str.Format(_T("%f"),StartPerPipePt.z);
				AddPerElement.Add(str);
				str.Format(_T("%f"),InPipeData);
				AddPerElement.Add(str);
				AddPerElement.Add(_T("END-POINT"));
				str.Format(_T("%f"),EndPerPipept.x);
				AddPerElement.Add(str);
				str.Format(_T("%f"),EndPerPipept.y);
				AddPerElement.Add(str);
				str.Format(_T("%f"),EndPerPipept.z);
				AddPerElement.Add(str);
				str.Format(_T("%f"),InPipeData);
				AddPerElement.Add(str);
				AddPerElement.Add(_T("ITEM-CODE"));
				AddPerElement.Add(_T("PA150"));
				AddPerElement.Add(_T("FABRICATION-ITEM"));
				AddPerElement.Add(_T("WEIGHT"));
				AddPerElement.Add(_T("0.000000"));
				AddPerElement.Add(_T("ITEM-DESCRIPTION"));
				AddPerElement.Add(_T("unset"));
				AddPerElement.Add(_T("INSULATION"));
				AddPerElement.Add(_T("OFF"));
				AddPerElement.Add(_T("INSULATION-SPEC"));
				AddPerElement.Add(_T("unset"));
				AddPerElement.Add(_T("TRACING"));
				AddPerElement.Add(_T("OFF"));
				AddPerElement.Add(_T("TRACING-SPEC"));
				AddPerElement.Add(_T("unset"));


				AddCurElement.Add(CurElement.GetAt(0));//减去所加管道后，当前节点的信息
				AddCurElement.Add(_T("END-POINT"));
				str.Format(_T("%f"),StartCurPt.x);
				AddCurElement.Add(str);
				str.Format(_T("%f"),StartCurPt.y);
				AddCurElement.Add(str);
				str.Format(_T("%f"),StartCurPt.z);
				AddCurElement.Add(str);
				for ( int mIndex =5;mIndex<CurElement.GetSize();mIndex++)
				{
					AddCurElement.Add(CurElement.GetAt(mIndex));				
				}
				
				if (PipeFlag)  //如果节点前一个元件是管道则只创建当前的元件节点，
				{
					CreatComponet(CurElement);
					PipeFlag=FALSE;
				} 
				else      //如果前一个不是管道，即这两个节点是直接相连的则创建管道和当前元件节点。
				{
					CreatComponet(AddPerElement);
					CreatComponet(AddCurElement);
				}
 			}
			ElementBuff.RemoveAll();//清空所有临时的数组
			PerElement.RemoveAll();
			CurElement.RemoveAll();
			AddCurElement.RemoveAll();
			AddPerElement.RemoveAll();

		}
		ElementBuff.Add(ElementBuff1.GetAt( wordnum ));

		if (ElementBuff1.GetAt(wordnum)==_T("PIPE")||ElementBuff1.GetAt(wordnum)==_T("END-CONNECTION-EQUIPMENT")||ElementBuff1.GetAt(wordnum)==_T("END-CONNECTION-NULL") || ElementBuff1.GetAt(wordnum)==_T("ASSIGNFLOW") )
		{
			PerFlag=TRUE;  //判断前一个是不是节点，不是(TRUE),是(FALSE)
		}
		if (ElementBuff1.GetAt(wordnum)==_T("PIPE")) //判断前一个是不是管道
		{
			PipeFlag=TRUE;
		}
	}

}

void PCFComponentMgr::CreatComponet(CStringArray &strSet)
{
	CString strKey = strSet.GetAt(0) ;
	strKey.MakeUpper() ;
	if (strKey.CompareNoCase(_T("NOZZLE"))==0)
		return;
	if(strKey.CompareNoCase(_T("PIPE"))==0)
	{
		PCFPipe *pPipe = m_PipesMgr.Creator();
		if(pPipe != NULL)
			pPipe->Init(strSet);
	}
	else
	{
		PCFJun *pJun = m_JunsMgr.Creator(strKey);
		if(pJun != NULL)
			pJun->Init(strSet);
	}
}
PCFJunsMgr& PCFComponentMgr::GetJunMgr()
{
	return m_JunsMgr;
}
PCFPipesMgr& PCFComponentMgr::GetPipeMgr()
{
	return m_PipesMgr;
}
//将三维坐标投影到二维坐标
void PCFComponentMgr::Tran3dTo2d()
{
	m_PipesMgr.Tran3dTo2d();
	m_JunsMgr.Tran3dTo2d();
}

void PCFComponentMgr::MoveGraph()
{
	double dMinX=0;
	double dMinY=0;
	GetMinXY(dMinX,dMinY);
	AcGePoint3d OriginPt(dMinX,dMinY,0);
	OffSet(OriginPt);

}
//得到最小的x轴y轴坐标值。
void PCFComponentMgr::GetMinXY(double &dMinX, double &dMinY)
{
	m_PipesMgr.GetMinXY(dMinX,dMinY);
}

//移动这个管系使所有2维坐标大于0
void PCFComponentMgr::OffSet(AcGePoint3d& OriginPt)
{
	m_PipesMgr.OffSet(OriginPt);
	m_JunsMgr.OffSet(OriginPt);
}

//根据节点坐标找到连接管道并将节点的长度加到管道上。
void PCFComponentMgr::TripJunLen()
{
	m_JunsMgr.TripLen(m_PipesMgr);
}

//剔除某些节点并合并两根管段
void PCFComponentMgr::CombinationPipe()
{
	m_JunsMgr.CombinationPipe(m_PipesMgr);
}
//建立管道和节点的连接关系
void PCFComponentMgr::InitNetLink()
{
	m_JunsMgr.InitNetLink(m_PipesMgr);
}
//
void PCFComponentMgr::CombinationFit()
{
	m_JunsMgr.CombinationFit(m_PipesMgr);
}

void PCFComponentMgr::ChangeOrigin()
{
	double dMaxX=0;
	double dMaxY=0;
	m_PipesMgr.GetMaxXY(dMaxX,dMaxY);
	AcGePoint3d OriginPt(dMaxX+100,dMaxY+100,0);
	m_PipesMgr.ChangeOrigin(OriginPt);
	m_JunsMgr.ChangeOrigin(OriginPt);
}
