// PipeData.h: interface for the PipeData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIPEDATA_H__A4ABFA5F_1B98_4C9C_8F67_D6EE18E977E2__INCLUDED_)
#define AFX_PIPEDATA_H__A4ABFA5F_1B98_4C9C_8F67_D6EE18E977E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PersistentObj.h"
#include "RowObjectFace.h"

class AFX_EXT_CLASS PipeData:public PersistentObj
{
public:
	void Name(CString strValue);
	void EndPtX(CString strValue);
	void StartPtX(CString strValue);
	void EndPtY(CString strValue);
	void StartPtY(CString strValue);
	void InJunID(CString strValue);
	void OutJunID(CString strValue);
	void InDia(CString strValue);
	void InDiaUnit(CString strValue);
	void Len(CString strValue);
	void LenUnit(CString strValue);
	void WaveSpeed(CString strValue);
	void WaveSpeedUnit(CString strValue);
	void B(CString strValue);
	void Material(CString strValue);
	void Size(CString strValue);
	void PipeType(CString strValue);
	void Thick(CString strValue);
	void ThickUnit(CString strValue);
	void Elasticity(CString strValue);
	void ElasticityUnit(CString strValue);
	void PossionRatio(CString strValue);
	void InDiaReduce(CString strValue);
	void CalcWave(CString strValue);
	void C1(CString strValue);
	void SupportType(CString strValue);
	void FrictionModel(CString strValue);
	void Friction(CString strValue);
	void FrictionUnit(CString strValue);
    void LocalK(CString strValue);
	void PipeFactor(CString strValue);
	void FitFactor(CString strValue);
	void InitFlow(const StrArray<3>& strValue);
	void SectionNum(CString strValue);
	void ParaNum(CString strValue);
	void PartFull(CString strValue);

	CString PartFull();
	CString LocalK();
	CString PipeFactor();
	CString FitFactor();
	StrArray<3> InitFlow();
	CString SectionNum();
	CString ParaNum();
	CString Material();
	CString Size();
	CString PipeType();
	CString Thick();
	CString ThickUnit();
	CString Elasticity();
	CString ElasticityUnit();
	CString PossionRatio();
	CString InDiaReduce();
	CString CalcWave();
	CString C1();
	CString SupportType();
	CString FrictionModel();
	CString Friction();
	CString FrictionUnit();
	CString InDia();
	CString InDiaUnit();
	CString Len();
	CString LenUnit();
	CString WaveSpeed();
	CString WaveSpeedUnit();
	CString B();
	CString InJunID();
	CString OutJunID();
	CString Name();
	CString EndPtX();
	CString StartPtX();
	CString EndPtY();
	CString StartPtY();
	int GetNum();//管道编号
	void SetNum(int nNum);
	
	void Init();
	BOOL Save(CStdioFile &file);
	BOOL Read(CStdioFile &file);
	PipeData();
	virtual ~PipeData();

private:
	void InitData(CString strData);
	void InitArray();
	RowObjectFace<1>  m_Number;             //管道编号
	RowObjectFace<1>  m_Name;				//管道名称
	RowObjectFace<1>  m_LenUnit;			//长度的单位
	RowObjectFace<1>  m_EleUnit;			//标高单位
	RowObjectFace<1>  m_InEle;				//入口标高
	RowObject  m_OutLenEleList;		//管道内部标高加末段标高数量(距离,标高)
	RowObjectFace<1>  m_UnKown1;           //0
	RowObject  m_PtArray;			//管道图形点的个数
	RowObjectFace<1>  m_UnKown2;			//None
	RowObjectFace<1>  m_definedMark;       //管道定义是否完成标记0(为完成)-1(管道定义完成)
	RowObjectFace<1>  m_LockMark;			//0表示锁定图形-1表示锁定图形
	RowObjectFace<1>  m_InJunID;			//入口节点的ID号
	RowObjectFace<1>  m_OutJunID;			//出口节点的ID号
	RowObjectFace<2>  m_InDia;				//管道内径，管道内径单位
	RowObjectFace<4>  m_FrictionModel;		//摩擦力模型、类型、系数、单位
	RowObjectFace<1>  m_UnKown3;			//0
	RowObjectFace<1>  m_UnKown4;			//0
	RowObjectFace<3>  m_PipeAttr;			//管道材料、尺寸、类型
	RowObjectFace<2>  m_LocalK;			//总共局部的K系数,局部阻力件
	RowObjectFace<2>  m_DisignFactor;		//设计因子管道摩擦力\管道附加损失
	RowObjectFace<3>  m_InitFlow;			//初始化流体猜测类型（0，1，2）\大小\单位
	RowObjectFace<1>  m_FuildMark;			//标记是否使用变流体属性
	RowObjectFace<11>  m_FuildAttr;			//流体属性11个数据
	RowObjectFace<2>  m_SpecialMark;		//指定特别条件类型标记（没有为0）\关联的节点的关闭节点
	RowObjectFace<1>  m_UnKown5;			//1		
	RowObjectFace<4>  m_LabLocation;		//工作区文字显示位置(4)
	RowObjectFace<1>  m_Display;			//工作区显示
	RowObjectFace<4>  m_UnKown6;			//5\-1\-1\25
	RowObjectFace<1>  m_PipeColor;			//管道颜色值（-1：引用工作设置）
	RowObjectFace<1>  m_UnKown7;			//-1
	RowObjectFace<1>  m_LineThick;			//管线粗细像素
	RowObject  m_Alerts;					//报警设计的数量类型号\ 最大（2）或最小（1）\数值\单位
	RowObjectFace<2>  m_notes;				//
	RowObjectFace<1>  m_UnKown8;			//-1
	RowObjectFace<5>  m_Font;				//字体设置
	RowObjectFace<2>  m_PipeThick;			//管道壁厚值\单位
	RowObjectFace<2>  m_ElasModulus;		//弹性摸量值\单位
	RowObjectFace<1>  m_PoissonRatio;		//泊松比率
	RowObjectFace<7>  m_WaveSpeed;			//波速(7)
	RowObjectFace<1>  m_UnKown9;			//1
	RowObjectFace<1>  m_UnKown10;			//-1
	RowObjectFace<1>  m_SectionNum;			//管段分段数取整
	RowObjectFace<1>  m_UnKown11;			//-1
	RowObjectFace<1>  m_UnKown12;			//-1
	RowObjectFace<1>  m_UnKown13;			//-1
	RowObjectFace<1>  m_ParaNum;		    //管道并联数
	RowObjectFace<1>  m_PartFull;			//管道流体与满管百分比(-1:表示没有选中这一项)
	RowObjectFace<1>  m_IDReduce;			//内直径减少百分比
	RowObjectFace<4>  m_Fth1;				///对于例子fth29来说是第25~28位未知，None,0,None,None
	RowObjectFace<8>  m_Fth2;	            //对于例子fth29来说是第25~28位未知，0,0,None,1,0,0,,1,
	RowObjectFace<1>   m_Fth3;				//None 未知，
	RowObjectFace<1>  m_Fth4;			//如果为None则，后面跟0,0,;如果不为None，后面跟AFT6.0中insulation的数据
	RowObject m_Fth5;
// 	RowObjectFace<6>  m_Fth5_1;
// 	RowObjectFace<13> m_Fth5_2;
	RowObjectFace<2>  m_Fth6;				//-1,0
};

#endif // !defined(AFX_PIPEDATA_H__A4ABFA5F_1B98_4C9C_8F67_D6EE18E977E2__INCLUDED_)
