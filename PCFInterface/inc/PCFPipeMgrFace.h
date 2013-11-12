// PCFPipeMgrFace.h: interface for the PCFPipeMgrFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFPIPEMGRFACE_H__B68DCC9A_8CD7_4ADC_B28F_531D69654735__INCLUDED_)
#define AFX_PCFPIPEMGRFACE_H__B68DCC9A_8CD7_4ADC_B28F_531D69654735__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PCFPipesMgr;
class PipesManager;

class AFX_EXT_CLASS PCFPipeMgrFace  
{
public:
	ErrorStatus::FileError Read(PCFPipesMgr &Data, PipesManager &model);
	PCFPipeMgrFace();
	virtual ~PCFPipeMgrFace();

};

#endif // !defined(AFX_PCFPIPEMGRFACE_H__B68DCC9A_8CD7_4ADC_B28F_531D69654735__INCLUDED_)
