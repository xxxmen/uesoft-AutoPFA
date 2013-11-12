// CircularTunnel.h: interface for the CircularTunnelStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CIRCULARTUNNEL_H__37816806_4D34_4CC1_9CF7_CAD1739842E3__INCLUDED_)
#define AFX_CIRCULARTUNNEL_H__37816806_4D34_4CC1_9CF7_CAD1739842E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ISupportStrategy.h"

class CircularTunnelStrategy : public ISupportStrategy  
{
public:
	double GetC1(const WavespeedCalc &ref);
	static ISupportStrategy* Creator();
	virtual ~CircularTunnelStrategy();
private:
	CircularTunnelStrategy();
};

#endif // !defined(AFX_CIRCULARTUNNEL_H__37816806_4D34_4CC1_9CF7_CAD1739842E3__INCLUDED_)
