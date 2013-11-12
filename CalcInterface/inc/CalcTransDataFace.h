// CalcTransDataFace.h: interface for the CalcTransDataFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCTRANSDATAFACE_H__3647FE44_6822_41D5_8512_41AF56BB8B43__INCLUDED_)
#define AFX_CALCTRANSDATAFACE_H__3647FE44_6822_41D5_8512_41AF56BB8B43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcTransData;
class TransDataPersistent;

class AFX_EXT_CLASS CalcTransDataFace  
{
public:
	CalcTransDataFace();
	virtual ~CalcTransDataFace();
	ErrorStatus::FileError Save(CalcTransData &Data,TransDataPersistent &Model);

};

#endif // !defined(AFX_CALCTRANSDATAFACE_H__3647FE44_6822_41D5_8512_41AF56BB8B43__INCLUDED_)
