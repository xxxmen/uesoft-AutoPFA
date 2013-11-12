// CalcPipeMgrFace.h: interface for the CalcPipeMgrFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCPIPEMGRFACE_H__D12BFAA9_EECB_491A_96EB_4938B1D1CA32__INCLUDED_)
#define AFX_CALCPIPEMGRFACE_H__D12BFAA9_EECB_491A_96EB_4938B1D1CA32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcPipeMgr;
class PipesManager;

class AFX_EXT_CLASS CalcPipeMgrFace  
{
public:
	CalcPipeMgrFace();
	virtual ~CalcPipeMgrFace();
    ErrorStatus::FileError Save(CalcPipeMgr &Data,PipesManager& model);
};

#endif // !defined(AFX_CALCPIPEMGRFACE_H__D12BFAA9_EECB_491A_96EB_4938B1D1CA32__INCLUDED_)
