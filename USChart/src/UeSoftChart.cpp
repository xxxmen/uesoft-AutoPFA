// UeSoftChart.cpp: implementation of the UeSoftChart class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UeSoftChart.h"
#include "UeChartHeader.h"



#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UeSoftChart::UeSoftChart(CMSChart &chart)
:m_Chart(chart)
{
	m_nCategory = 5;
	m_nDivision = 3;
}

UeSoftChart::~UeSoftChart()
{

}

void UeSoftChart::Category(int nCategory)
{
	m_nCategory = nCategory;
}
void UeSoftChart::Division(int nDivision)
{
	m_nDivision = nDivision;
}
void UeSoftChart::SetXAXisTitle(CString strTitle)
{
	VARIANT var;
	m_Chart.GetPlot().GetAxis(0,var).GetAxisTitle().SetText(strTitle);	// X轴名称
	m_Chart.Refresh();	
}
void UeSoftChart::SetYAXisTitle(CString strTitle)
{
	VARIANT var;
	m_Chart.GetPlot().GetAxis(1,var).GetAxisTitle().SetText(strTitle);	// Y轴名称
	m_Chart.Refresh();
}
void UeSoftChart::SetColTitle(CString strTitle,int i)
{
	m_Chart.SetColumn(i);
	m_Chart.SetColumnLabel(strTitle);
	m_Chart.Refresh();
}
void UeSoftChart::ChartType(int nType)
{
	m_Chart.SetChartType(nType);	
}
void UeSoftChart::LineCount(int nLineCount)
{
	m_Chart.SetColumnCount(nLineCount);
}
void UeSoftChart::PointCount(int nPointCount)
{
	if(nPointCount <=0)
		return;
	VARIANT var;
	int nNum = nPointCount / m_nCategory;
	while(nNum < m_nDivision)
	{
		nPointCount = nPointCount * 2;
		nNum = nPointCount / m_nCategory;
	}
	m_Chart.SetRowCount(nPointCount);
	m_Chart.GetPlot().GetAxis(0,var).GetCategoryScale().SetAuto(FALSE);	
	m_Chart.GetPlot().GetAxis(0,var).GetCategoryScale().SetDivisionsPerLabel(nNum);// 每刻度一个标注
	m_Chart.GetPlot().GetAxis(0,var).GetCategoryScale().SetDivisionsPerTick(nNum); // 每刻度一个刻度线
}

void UeSoftChart::Init()
{
	LineCount(0);
	PointCount(m_nCategory);
	ChartType(3);
	m_Chart.SetRandomFill(FALSE);
}

void UeSoftChart::SetData(double dParme[],int ma,double dMin,double dMax)
{
	double y = 0;
	double x= 0;
	double dx = GetScale(dMin,dMax);
	short nLine = m_Chart.GetColumnCount() + 1;
	int nRowCount = m_Chart.GetRowCount();
	LineCount(nLine);
	for(int i =1;i<=nRowCount;i++)
	{
		x = (i-1)*dx+dMin;
		m_Chart.SetRow(i);
		m_Chart.SetRowLabel(RowLab(x).GetBuffer(0));

		PolyValve(dParme,ma,x,y);
		if(x <= dMax)
			m_Chart.GetDataGrid().SetData(i,nLine,y,0);
	}
	m_Chart.Refresh();
}

void UeSoftChart::SetData(double dX[],double dY[],int ma)
{
	double y = 0;
	double x= 0;
	double dMax = 0;
	double dMin = 0;
	MaxMin(dX,ma,dMax,dMin);
	double d = dMax -dMin;
	if(-1e-6<d && d<1e-6 )
		return;
	double dx = GetScale(dMin,dMax);
	short nLine = m_Chart.GetColumnCount() + 1;
	int nRowCount = m_Chart.GetRowCount();
	LineCount(nLine);

	for(int i =1;i<=nRowCount;i++)
	{
		x = (i-1)*dx+dMin;
    	m_Chart.SetRow(i);
		m_Chart.SetRowLabel(RowLab(x).GetBuffer(0));

		LinearValue(dX,dY,ma,x,y);
		if(x <= dMax)
			m_Chart.GetDataGrid().SetData(i,nLine,y,0);
	}
	m_Chart.Refresh();
}

void UeSoftChart::SetSortData(double dX[],double dY[],int ma)
{
	VARIANT var;
	short nPointCount = (ma/m_nCategory+1)*m_nCategory;
	int nNum = nPointCount / m_nCategory;
	short nLine = m_Chart.GetColumnCount() + 1;
	m_Chart.SetRowCount(nPointCount);
	m_Chart.GetPlot().GetAxis(0,var).GetCategoryScale().SetAuto(FALSE);	
	m_Chart.GetPlot().GetAxis(0,var).GetCategoryScale().SetDivisionsPerLabel(nNum);// 每刻度一个标注
	m_Chart.GetPlot().GetAxis(0,var).GetCategoryScale().SetDivisionsPerTick(nNum); // 每刻度一个刻度线
//	PointCount((ma/m_nCategory+1)*m_nCategory);
	LineCount(nLine);
	for(int i =1;i<=ma;i++)
	{
		m_Chart.SetRow(i);
		m_Chart.SetRowLabel(RowLab(dX[i-1]).GetBuffer(0));
		m_Chart.GetDataGrid().SetData(i,nLine,dY[i-1],0);
	}
	m_Chart.Refresh();
}

double UeSoftChart::GetScale(double &dMin,double dMax)
{
	int nPower = 0;
	int nPointConut = 0;
	while(dMax>10)
	{
		dMax = dMax/10;
		dMin = dMin/10;
		nPower++;
	}
	while(dMax<=1)
	{
		dMax = dMax*10;
		dMin = dMin*10;
		nPower--;
	}
	if(dMax - int(dMax) > 0.001)
	{
		dMax = dMax + 1;
	}
	nPointConut = (int(dMax)-int(dMin))*m_nCategory;
	PointCount(nPointConut);
	dMax = int(dMax)*pow(10.0,nPower);
	dMin = int(dMin)*pow(10.0,nPower);

	return (dMax-dMin)/m_Chart.GetRowCount();
}

CString UeSoftChart::RowLab(double dLab)
{
	CString strBuf;
	strBuf.Format(_T("  %g"),dLab);
	if(-1 != strBuf.Find('.'))
	{
		strBuf.TrimRight('0');
		strBuf.TrimRight('.');
	}
	return strBuf;
}


void UeSoftChart::Save(CStdioFile &File)
{
	CString strLine;
	CString strTemp;
	short nullflag=0;
	double dValue=0;
	short nLine = m_Chart.GetColumnCount()+1;
	int nRowCount = m_Chart.GetRowCount()+1;
	for(short i =1;i<nRowCount;i++)
	{
		strLine.Empty();
		strLine.Format(_T("%d\t"),i);
		for (short j=1; j<nLine; j++)
		{
			m_Chart.GetDataGrid().GetData(i,j,&dValue,&nullflag);
			strTemp.Format(_T("%g\t"),dValue);
			strLine += strTemp;
		}
		strLine += _T("\n");
		File.WriteString(strLine);
	}
}

BOOL UeSoftChart::HadData()
{
	if(m_Chart.GetColumnCount()>0)
		return TRUE;
	return FALSE;
}
