// CalcFuildFace.h: interface for the CalcFuildFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCFUILDFACE_H__C0D223EC_1ABE_42E5_A1B9_2B8F72FB620C__INCLUDED_)
#define AFX_CALCFUILDFACE_H__C0D223EC_1ABE_42E5_A1B9_2B8F72FB620C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcFuild;
class PropertyPersistent;

class AFX_EXT_CLASS CalcFuildFace  
{
public:
	CalcFuildFace();
	virtual ~CalcFuildFace();
	ErrorStatus::FileError Save(CalcFuild &Data,PropertyPersistent& model);

};

#endif // !defined(AFX_CALCFUILDFACE_H__C0D223EC_1ABE_42E5_A1B9_2B8F72FB620C__INCLUDED_)
