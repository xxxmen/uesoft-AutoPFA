// CalcTransFace.h: interface for the CalcTransFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCTRANSFACE_H__22575B44_9F38_4441_99C4_BEDE4EF633A5__INCLUDED_)
#define AFX_CALCTRANSFACE_H__22575B44_9F38_4441_99C4_BEDE4EF633A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcTrans;
class TransControlPerisistent;

class AFX_EXT_CLASS CalcTransFace  
{
public:
	CalcTransFace();
	virtual ~CalcTransFace();
    ErrorStatus::FileError Save(CalcTrans &Data,TransControlPerisistent& model);
};

#endif // !defined(AFX_CALCTRANSFACE_H__22575B44_9F38_4441_99C4_BEDE4EF633A5__INCLUDED_)
