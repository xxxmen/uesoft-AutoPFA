// RigidityTrans.h: interface for the RigidityTrans class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RIGIDITYTRANS_H__D6372F0B_F4DC_4FC6_81D0_6218C203753B__INCLUDED_)
#define AFX_RIGIDITYTRANS_H__D6372F0B_F4DC_4FC6_81D0_6218C203753B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define RIGIDITY_UNIT_NUM 6
#define RIGIDITY_STD_UNIT 0

class RigidityTrans  
{
public:
	RigidityTrans();
	virtual ~RigidityTrans();
public:
	static int UnitStringToUnitClass(const StdString& UnitString);
	static const StdString& UnitClassToUnitString(int UnitClass);
	static	bool	IsSIStd( int );
	static	double	TransToStd( int );
	static	double	TransFromStd( int );
	static  int GetStdUnitIndex()
	{
		return RIGIDITY_STD_UNIT;
	}
protected:
private:
	static const StdString UnitStringArray[RIGIDITY_UNIT_NUM];
	static	double	RigidityTransRatio[RIGIDITY_UNIT_NUM];

};

#endif // !defined(AFX_RIGIDITYTRANS_H__D6372F0B_F4DC_4FC6_81D0_6218C203753B__INCLUDED_)
