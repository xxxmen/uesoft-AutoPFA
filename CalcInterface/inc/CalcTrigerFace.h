// CalcTrigerFace.h: interface for the CalcTrigerFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCTRIGERFACE_H__4EE0F3C1_997B_4E7E_A9BB_010D55853447__INCLUDED_)
#define AFX_CALCTRIGERFACE_H__4EE0F3C1_997B_4E7E_A9BB_010D55853447__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcTriger;

class AFX_EXT_CLASS CalcTrigerFace  
{
public:
	CalcTrigerFace();
	virtual ~CalcTrigerFace();
	ErrorStatus::FileError Save(CalcTriger &Data,StrArray<8> &Model);

};

#endif // !defined(AFX_CALCTRIGERFACE_H__4EE0F3C1_997B_4E7E_A9BB_010D55853447__INCLUDED_)
