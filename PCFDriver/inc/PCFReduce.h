// PCFReduce.h: interface for the PCFReduce class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFREDUCE_H__C01ED98F_1CBD_474F_AACC_93F366E4CE41__INCLUDED_)
#define AFX_PCFREDUCE_H__C01ED98F_1CBD_474F_AACC_93F366E4CE41__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJun.h"
//¥Û–°Õ∑
class PCFReduce : public PCFJun  
{
public:
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFReduce();
	virtual ~PCFReduce();

private:
	
};

#endif // !defined(AFX_PCFREDUCE_H__C01ED98F_1CBD_474F_AACC_93F366E4CE41__INCLUDED_)
