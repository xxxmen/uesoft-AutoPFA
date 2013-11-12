// CalcPumpConfigFace.h: interface for the CalcPumpConfigFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCPUMPCONFIGFACE_H__A2E77F4C_ED12_42AE_BC0D_C4AF9809BD28__INCLUDED_)
#define AFX_CALCPUMPCONFIGFACE_H__A2E77F4C_ED12_42AE_BC0D_C4AF9809BD28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcPumpConfig;
class ConfigPerisist;

class AFX_EXT_CLASS CalcPumpConfigFace  
{
public:
	CalcPumpConfigFace();
	virtual ~CalcPumpConfigFace();
	ErrorStatus::FileError Save(CalcPumpConfig &Data,ConfigPerisist &Model);
};

#endif // !defined(AFX_CALCPUMPCONFIGFACE_H__A2E77F4C_ED12_42AE_BC0D_C4AF9809BD28__INCLUDED_)
