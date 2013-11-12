// CalcPipeFace.h: interface for the CalcPipeFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCPIPEFACE_H__8CFFAEEB_1226_49D7_BEF0_A1F4B4570271__INCLUDED_)
#define AFX_CALCPIPEFACE_H__8CFFAEEB_1226_49D7_BEF0_A1F4B4570271__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcPipe;
class PipePerisist;

class AFX_EXT_CLASS CalcPipeFace  
{
public:
	CalcPipeFace();
	virtual ~CalcPipeFace();
	ErrorStatus::FileError Save(CalcPipe *pData,PipePerisist *pModel);

};

#endif // !defined(AFX_CALCPIPEFACE_H__8CFFAEEB_1226_49D7_BEF0_A1F4B4570271__INCLUDED_)
