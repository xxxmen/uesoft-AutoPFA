// FCFComponentMgr.h: interface for the FCFComponentMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FCFCOMPONENTMGR_H__0325095A_8AA1_4836_83E6_CDB0FE64F4A7__INCLUDED_)
#define AFX_FCFCOMPONENTMGR_H__0325095A_8AA1_4836_83E6_CDB0FE64F4A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PipeLineHead.h"
#include "PCFJunsMgr.h"
#include "PCFPipesMgr.h"

class AFX_EXT_CLASS PCFComponentMgr  
{
public:
	
	PCFJunsMgr& GetJunMgr();
	PCFPipesMgr& GetPipeMgr();
	void Init(const CStringArray &strSet);
	PCFComponentMgr();
	virtual ~PCFComponentMgr();
	CStringArray ElementBuff1 ;

private:
	BOOL IsKeyWord( const CString& strKeyWord  );
	PipeLineHead m_pipeHead;
	PCFPipesMgr m_PipesMgr;
	PCFJunsMgr  m_JunsMgr;


private:
	void ChangeOrigin();
	void CombinationFit();
	void InitNetLink();
	void CombinationPipe();
	void Tran3dTo2d();
	void TripJunLen();
	void OffSet(AcGePoint3d& OriginPt);//移动坐标原点到最小X,Y坐标
	void MoveGraph();// 移动图形坐标点使坐标大于0
	void GetMinXY(double &dMinX,double &dMinY);//得到最小X,Y坐标值
	void CreatComponet(CStringArray &strSet);		//创建PCF的元件，通过单个PCF文件中的信息来创建；
	void InitComponet(CStringArray &strSet);  //对ElementBuff1中的关键字END-CONNECTION-EQUIPMENT变为SKEY之后的那个关键字的字符串数组；并把其表示为PFA可以识别的类型；
	static const CString m_strKeyWordArray[] ;		//PFA中可以识别的关键字，这个可以扩充；

	void InitNOZZLE_Ptconcet(CStringArray &strSet);                 //保持设备与分支相连
	void InitEquipment_PT(CStringArray &strSet);                    //保持设备中心点与分支相距不太远
	void InitJunKey_KeepPtConcet( CStringArray &strConectPt ) ;		//保持各个节点的坐标是相互连接的。
	void InitJunKey_DelTeeBranch( CStringArray &strDelBranch ) ;	//处理三通连接的分支不是官道的情况。
	void InitJunKey_NoPCFJuntoPipe( const CStringArray &strSet );//处理节点关键字，把不是节点的元件都变为管道。
	void InitJunKey_MergePipe( const CStringArray &strMerge );//处理节点关键字，合并连续的关键字都是PIPE的节点。
	void InitJunKey_AddPipe( const CStringArray &strAdd );	//对于焊接的元件（即两个元件不通过PIPE相连）中间加一段管件；并创建元件。
	void InitJunKey_AddAssignFlowStartBranch( CStringArray &strAssignFlow ) ;	//分支头如果没有元件，则加入指定流量
	void InitJunKey_DelDiscription( CStringArray &strDelDiscription ) ;  //由于描述关键字后面的字符有可能是元件关键字，所以要重新设置描述内容；
	void InitJunKey_AddAssignFlowEndBranch( CStringArray &strAssignFlow ) ;	//分支尾如果没有元件，则也加入指定流量。
	void InitJunKey_AddPipeAndAssignFlow( CStringArray &strPipeAndAssignFlow ) ;  //在非法结束的元件的分支尾加上PIPE；
	void InitElement(CStringArray &strSet);               //建设备
	void InitAddAssignFlow(PCFJunsMgr& pJunMgr,PCFPipesMgr& pPipeMgr);  //非法结束的管道加入指定流量
	void Init_AddPipe(PCFJunsMgr& pJunMgr,PCFPipesMgr& pPipeMgr);   //非法结束的节点加入管道
	int CamparePt(PCFJun& InJun,PCFPipe& InPipe);           //比较节点与管道坐标
	void CampareJJPt(PCFJun& InJun,PCFJun& OutJun);          //比较节点与节点坐标
	void CombinationPipes(PCFPipesMgr& pPipeMgr);           //合并相连的管道
	void Init_JunPt(PCFJunsMgr& pJunMgr,PCFPipesMgr& pPipeMgr);         //初始化节点进出节点ID  
	void Init_AddPipetoJun(PCFJunsMgr& pJunMgr);                       //节点相连的时候插入管道
//	void Del_AddJun(PCFJunsMgr& pJunMgr,PCFPipesMgr& pPipeMgr);
	
	CStringArray JuntoPipe ;   //对节点关键字处理之后，所有的关键字都是PCF的节点关键字；其保存在字符串数组JuntoPipe中；
	CStringArray MergePipe ;	//对JuntoPipe中的关键字是PIPE的节点合并后，得到的信息保存在MergePipe中；
	//在ElementBuff1中对两个元件之间不是PIPE的关键字处理；

};

#endif // !defined(AFX_FCFCOMPONENTMGR_H__0325095A_8AA1_4836_83E6_CDB0FE64F4A7__INCLUDED_)
