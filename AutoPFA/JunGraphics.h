// JunGraphics.h: interface for the JunGraphics class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：JunGraphics.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUNGRAPHICS_H__B8F8A7FF_CABC_4931_AD67_F4C85D4B31BE__INCLUDED_)
#define AFX_JUNGRAPHICS_H__B8F8A7FF_CABC_4931_AD67_F4C85D4B31BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Graphics.h"

class Jun;

class JunGraphics : public Graphics  
{
public:
	void Draw(CDC* pDc,COLORREF color,int nStyle,int nWidth,int Size=0);
	void DrawMark(CDC* pDc,COLORREF color,int nStyle,int nWidth,int Size=0);
	BOOL Pick(CPoint point,int Size=0);
    static JunGraphics* Instance(Jun *pJun);
	virtual ~JunGraphics();
private:
	JunGraphics();
	JunGraphics(const JunGraphics&);
	JunGraphics& operator=(const JunGraphics&);
	
    Jun *m_pJun;
};

#endif // !defined(AFX_JUNGRAPHICS_H__B8F8A7FF_CABC_4931_AD67_F4C85D4B31BE__INCLUDED_)
