// PCFPipeFace.h: interface for the PCFPipeFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFPIPEFACE_H__56019BE7_0E1B_43A3_AC97_B3576BC8CB32__INCLUDED_)
#define AFX_PCFPIPEFACE_H__56019BE7_0E1B_43A3_AC97_B3576BC8CB32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class PCFPipe;
class PipePerisist;

class AFX_EXT_CLASS PCFPipeFace  
{
public:
	ErrorStatus::FileError Read(PCFPipe *pData,PipePerisist *pModel);
	PCFPipeFace();
	virtual ~PCFPipeFace();

};

#endif // !defined(AFX_PCFPIPEFACE_H__56019BE7_0E1B_43A3_AC97_B3576BC8CB32__INCLUDED_)
