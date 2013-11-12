// PCFGasket.h: interface for the PCFGasket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFGASKET_H__4EA941A5_3C10_407A_8BC2_AA816FC74266__INCLUDED_)
#define AFX_PCFGASKET_H__4EA941A5_3C10_407A_8BC2_AA816FC74266__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PCFJun.h"
//µÊ»¶
class PCFGasket : public PCFJun  
{
public:
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFGasket();
	virtual ~PCFGasket();

private:
	
};

#endif // !defined(AFX_PCFGASKET_H__4EA941A5_3C10_407A_8BC2_AA816FC74266__INCLUDED_)
