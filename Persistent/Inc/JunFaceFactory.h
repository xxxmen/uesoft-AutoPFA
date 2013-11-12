// JunFaceFactory.h: interface for the JunFaceFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUNFACEFACTORY_H__E5F0D57A_A680_42A5_A3D9_83492D298DE8__INCLUDED_)
#define AFX_JUNFACEFACTORY_H__E5F0D57A_A680_42A5_A3D9_83492D298DE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Factory.h"
class AFTJunFace;

class JunFaceFactory:public CFactory<AFTJunFace,int>  
{
public:
	static JunFaceFactory* Instance();
	virtual ~JunFaceFactory();
	
protected:
	JunFaceFactory();
	
private:
	JunFaceFactory(const JunFaceFactory &ref);
	JunFaceFactory& operator=(const JunFaceFactory &ref);

};

#endif // !defined(AFX_JUNFACEFACTORY_H__E5F0D57A_A680_42A5_A3D9_83492D298DE8__INCLUDED_)
