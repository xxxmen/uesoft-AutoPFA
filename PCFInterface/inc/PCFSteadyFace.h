// PCFSteadyFace.h: interface for the PCFSteadyFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFSTEADYFACE_H__3F2F28E7_D2B4_4F13_937B_7D2678D8A3AB__INCLUDED_)
#define AFX_PCFSTEADYFACE_H__3F2F28E7_D2B4_4F13_937B_7D2678D8A3AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class SteadyPersistent;

class AFX_EXT_CLASS PCFSteadyFace  
{
public:
	ErrorStatus::FileError Read(SteadyPersistent& model);
	PCFSteadyFace();
	virtual ~PCFSteadyFace();

};

#endif // !defined(AFX_PCFSTEADYFACE_H__3F2F28E7_D2B4_4F13_937B_7D2678D8A3AB__INCLUDED_)
