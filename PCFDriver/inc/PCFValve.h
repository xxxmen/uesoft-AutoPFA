// PCFValve.h: interface for the PCFValve class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFVALVE_H__0FDFA2E8_FE7A_4EC3_82CF_F723D760335A__INCLUDED_)
#define AFX_PCFVALVE_H__0FDFA2E8_FE7A_4EC3_82CF_F723D760335A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PCFJun.h"
//∑ß√≈
class PCFValve : public PCFJun  
{
public:
	static PCFJun* Creator();
	void Init(const CStringArray& wordArray );
	PCFValve();
	virtual ~PCFValve();

private:
	
};

#endif // !defined(AFX_PCFVALVE_H__0FDFA2E8_FE7A_4EC3_82CF_F723D760335A__INCLUDED_)
