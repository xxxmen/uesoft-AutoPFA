// PipeGraphics.h: interface for the PipeGraphics class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：PipeGraphics.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIPEGRAPHICS_H__FAF188B5_54A8_42A2_99DA_683C0896CD0F__INCLUDED_)
#define AFX_PIPEGRAPHICS_H__FAF188B5_54A8_42A2_99DA_683C0896CD0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Graphics.h"

class Pipe;
class PipeGraphics : public Graphics  
{
public:
	void Draw(CDC* pDc,COLORREF color,int nStyle,int nWidth,int Size=0);
	void DrawMark(CDC* pDc,COLORREF color,int nStyle,int nWidth,int Size=0);
	BOOL Pick(CPoint point,int Size=0);
	static PipeGraphics* Instance(Pipe *pPipe);
	virtual ~PipeGraphics();
private:
	void DrawArrow(CDC *pDc,int nWidth);
	PipeGraphics(const PipeGraphics&);
	PipeGraphics& operator=(const PipeGraphics&);
	PipeGraphics();
    Pipe *m_pPipe;
};

#endif // !defined(AFX_PIPEGRAPHICS_H__FAF188B5_54A8_42A2_99DA_683C0896CD0F__INCLUDED_)
