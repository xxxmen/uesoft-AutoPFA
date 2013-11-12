// AFTTransDataFace.h: interface for the AFTTransDataFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AFTTRANSDATAFACE_H__2D6A5345_7589_465F_91CE_56D0318CB187__INCLUDED_)
#define AFX_AFTTRANSDATAFACE_H__2D6A5345_7589_465F_91CE_56D0318CB187__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "JunTransData.h"
#include "TransDataPersistent.h"

class AFX_EXT_CLASS AFTTransDataFace  
{
public:
	AFTTransDataFace();
	virtual ~AFTTransDataFace();

	ErrorStatus::FileError Read(JunTransData &Data,TransDataPersistent &Model);
	ErrorStatus::FileError Save(JunTransData &Data,TransDataPersistent &Model);

};

#endif // !defined(AFX_AFTTRANSDATAFACE_H__2D6A5345_7589_465F_91CE_56D0318CB187__INCLUDED_)
