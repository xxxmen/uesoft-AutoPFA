// CalcJunFace.h: interface for the CalcJunFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCJUNFACE_H__121FFD1F_0150_4325_8279_22EDD22381AC__INCLUDED_)
#define AFX_CALCJUNFACE_H__121FFD1F_0150_4325_8279_22EDD22381AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcJun;
class Junperisist;

class AFX_EXT_CLASS CalcJunFace  
{
public:
	CalcJunFace();
	virtual ~CalcJunFace();
	virtual ErrorStatus::FileError Save(CalcJun *pData,Junperisist* pModel);

protected:
	void GetTypeAndValue(StrArray<3> &ref,int &ntype,double &dValue);
};

#endif // !defined(AFX_CALCJUNFACE_H__121FFD1F_0150_4325_8279_22EDD22381AC__INCLUDED_)
