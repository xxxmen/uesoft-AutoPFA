// CalcJunFaceFactory.h: interface for the CalcJunFaceFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCJUNFACEFACTORY_H__7EB3B965_0FB0_4145_872E_5463F2A8D0EB__INCLUDED_)
#define AFX_CALCJUNFACEFACTORY_H__7EB3B965_0FB0_4145_872E_5463F2A8D0EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Factory.h"
class CalcJunFace;

class CalcJunFaceFactory:public CFactory<CalcJunFace,int>  
{
public:
	static CalcJunFaceFactory* Instance();
	virtual ~CalcJunFaceFactory();
	
protected:
	CalcJunFaceFactory();
	
private:
	CalcJunFaceFactory(const CalcJunFaceFactory &ref);
	CalcJunFaceFactory& operator=(const CalcJunFaceFactory &ref);

};

#endif // !defined(AFX_CALCJUNFACEFACTORY_H__7EB3B965_0FB0_4145_872E_5463F2A8D0EB__INCLUDED_)
