// PCFReduceFace.h: interface for the PCFReduceFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFREDUCEFACE_H__04938495_881B_47B6_9744_9F9A422DCD43__INCLUDED_)
#define AFX_PCFREDUCEFACE_H__04938495_881B_47B6_9744_9F9A422DCD43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJunFace.h"

class PCFReduceFace : public PCFJunFace  
{
public:
	ErrorStatus::FileError Read(PCFJun *pData,Junperisist* pModel);
	static PCFJunFace* Creator();
	PCFReduceFace();
	virtual ~PCFReduceFace();

private:
	double m_InLetDia;
	double m_OutLetDia;
};

#endif // !defined(AFX_PCFREDUCEFACE_H__04938495_881B_47B6_9744_9F9A422DCD43__INCLUDED_)
