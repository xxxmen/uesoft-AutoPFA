// MOCPumpInertia.h: interface for the MOCPumpInertia class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCPUMPINERTIA_H__8CFDC396_B083_43A5_8C09_7BBCF0252F29__INCLUDED_)
#define AFX_MOCPUMPINERTIA_H__8CFDC396_B083_43A5_8C09_7BBCF0252F29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class MOCPumpInertia  
{
public:
	double RotateInertia();
	void RotateInertia(double dRotateInertia);
	double Speed();
	void Speed(double dRotateInertia);
	MOCPumpInertia();
	virtual ~MOCPumpInertia();

private:
	double      m_dRotateInertia;		//转动惯量（泵，电动机，流体）
	double      m_dSpeed;				//泵额定转速

};
/*-------------------------------------------------------*/
inline void MOCPumpInertia::RotateInertia(double dRotateInertia)
{
	m_dRotateInertia = dRotateInertia;
}

/*-------------------------------------------------------*/
inline void MOCPumpInertia::Speed(double dSpeed)
{
	m_dSpeed = dSpeed;
}

inline double MOCPumpInertia::Speed()
{
	return m_dSpeed;
}
#endif // !defined(AFX_MOCPUMPINERTIA_H__8CFDC396_B083_43A5_8C09_7BBCF0252F29__INCLUDED_)
