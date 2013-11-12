// CalcReservior.cpp: implementation of the CalcReservior class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcReservior.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcReservior::CalcReservior()
{
	m_dSurfacePress = 0;
	m_nEleOrDepthType = 0;	
}

CalcReservior::~CalcReservior()
{

}

CalcJun* CalcReservior::Creator()
{
	CalcReservior *pData = new CalcReservior;
	return pData;
}

ostream& CalcReservior::Write(ostream &CalcOut)
{
	CalcOut<<m_nKey<<s_Separator
		   <<m_nTypeID<<s_Separator
		   <<m_dSurfacePress<<s_Separator
		   <<m_dInEle<<s_Separator
		   <<abs(m_nEleOrDepthType)<<s_Separator
		   <<m_PipeInfo
		   <<m_dDesignFactor<<s_Separator
		   // <<m_TranData
		   <<endl;
	return CalcOut;
}

void CalcReservior::PipeInfo(const ListImp<StrArray<6> >& ref)
{
	ListImp<StrArray<1> > list1;
	ListImp<StrArray<5> > list2;
	ListImp<StrArray<2> > list3;
	ListImp<StrArray<3> > list4;
	ListImp<StrArray<1> > list5;
	ListImp<StrArray<2> > list6;
	ListImp<StrArray<2> > list7;
	ListImp<StrArray<4> > list8;
	Divided<1,5>(list1,list2,ref);
	Divided<2,3>(list3,list4,list2);
	Divided<1,2>(list5,list6,list4);
	list7 = Combi<1,1>(list1,list5);
	list8 = Combi<2,2>(list7,list3);
	m_PipeInfo.SetData(Combi<4,2>(list8,list6));
}

/*------------------------------------------------*/
void CalcReservior::EleOrDepthType(int nValue)
{
	m_nEleOrDepthType = nValue;
}
/*------------------------------------------------*/
void CalcReservior::SurfacePress(double dValue)
{
	m_dSurfacePress = dValue;
}


ListImp<StrArray<6> >& CalcReservior::PipeInfo()
{
	return m_PipeInfo.GetData();
}

/*------------------------------------------------*/
int CalcReservior::EleOrDepthType()
{
	return m_nEleOrDepthType;
}
/*------------------------------------------------*/
double CalcReservior::SurfacePress()
{
	return m_dSurfacePress;
}