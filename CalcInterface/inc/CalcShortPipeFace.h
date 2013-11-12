// CalcShortPipeFace.h: interface for the CalcShortPipeFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCSHORTPIPEFACE_H__01B716CA_AC48_463B_8873_1A73D3F11A07__INCLUDED_)
#define AFX_CALCSHORTPIPEFACE_H__01B716CA_AC48_463B_8873_1A73D3F11A07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcShortPipe;

class AFX_EXT_CLASS CalcShortPipeFace  
{
public:
	CalcShortPipeFace();
	virtual ~CalcShortPipeFace();
	ErrorStatus::FileError Save(CalcShortPipe &Data,StrArray<10> &Model);
};

#endif // !defined(AFX_CALCSHORTPIPEFACE_H__01B716CA_AC48_463B_8873_1A73D3F11A07__INCLUDED_)
