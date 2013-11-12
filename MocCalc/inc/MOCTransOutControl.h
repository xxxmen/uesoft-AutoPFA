// MOCTransOutControl.h: interface for the MOCTransOutControl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRANSOUTCONTROL_H__AB04E291_C375_46CA_947A_7A3FD3E4999B__INCLUDED_)
#define AFX_MOCTRANSOUTCONTROL_H__AB04E291_C375_46CA_947A_7A3FD3E4999B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class MOCTransOutControl  
{
public:
	MOCTransOutControl();
	virtual ~MOCTransOutControl();
public:
	BOOL IsOutStation();
private:
	BOOL m_bStation;

};

#endif // !defined(AFX_MOCTRANSOUTCONTROL_H__AB04E291_C375_46CA_947A_7A3FD3E4999B__INCLUDED_)
