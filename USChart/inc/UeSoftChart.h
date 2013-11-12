// UeSoftChart.h: interface for the UeSoftChart class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UESOFTCHART_H__3B551B0F_7D43_4E02_892F_A3CB119E47C6__INCLUDED_)
#define AFX_UESOFTCHART_H__3B551B0F_7D43_4E02_892F_A3CB119E47C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "mschart.h"
#include "VcPlot.h"
#include "VcAxis.h"
#include "VcValueScale.h"
#include "VcSeriesCollection.h"
#include "VcSeries.h"
#include "VcPen.h"
#include "VcCategoryScale.h"
#include "VcColor.h"
#include "VcDataGrid.h"
#include "VcBackdrop.h"
#include "VcFill.h"
#include "VcBrush.h"
#include "VcDataPoints.h"
#include "VcDataPoint.h"
#include "VcDataPointLabel.h"
#include "VcAxisTitle.h"
#include "vcfont.h"



class  AFX_EXT_CLASS UeSoftChart  
{
public:
	UeSoftChart(CMSChart &chart);
	virtual ~UeSoftChart();

public:
	BOOL HadData();
	void Save(CStdioFile &File);
	void Init();
	void SetData(double dParme[],int ma,double dMin,double dMax);
	void SetData(double dX[],double dY[],int ma);
	void SetSortData(double dX[],double dY[],int ma);
	void ChartType(int nType);
	void Division(int nDivision);
	void Category(int nCategory);
	void SetXAXisTitle(CString strTitle);
	void SetYAXisTitle(CString strTitle);
	void SetColTitle(CString strTitle,int i);
	CMSChart &m_Chart;

	

private:
	CString RowLab(double dLab);
	void LineCount(int nLineCount);
	void PointCount(int nPointCount);
	double GetScale(double &dMin,double dMax);
	int m_nCategory;
	int m_nDivision;
	

};


#endif // !defined(AFX_UESOFTCHART_H__3B551B0F_7D43_4E02_892F_A3CB119E47C6__INCLUDED_)
