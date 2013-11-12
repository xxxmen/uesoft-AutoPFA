#include "stdafx.h"
#include <gemat3d.h>
#include <gevec3d.h>
#include <gevec2d.h>
#include <gepnt2d.h>
#include <gepnt3d.h>
#include <geplane.h>
#include "PersistentHeader.h"
#include "ListFlyWeightImp.h"
#include "QuantityManager.h"



double TransStd(CString strValue,CString strUnit)
{
	double dIn = _tcstod( strValue, NULL );
	return TransStd(dIn,strUnit);
}

double TransStd(StrArray<2> &Value)
{
	return TransStd(Value.Data(),Value.Data(1));
}

double TransStd(double dIn,CString strUnit)
{
	double dOut = dIn;
 	QuantityManager& qm = QuantityManager::Instance();
 	qm.TransformToStd(dOut,strUnit.GetBuffer(0),dIn);
	return dOut;
}

double TransFromStd(double dIn,CString strUnit)
{
	double dOut = dIn;
 	QuantityManager& qm = QuantityManager::Instance();
 	qm.TransformFromStd(dOut,strUnit.GetBuffer(0),dIn);
	return dOut;
}


CString GetX(AcGePoint3d &pt)
{
	CString strRet;
	strRet.Format(_T("%d"),int(pt.x));
	return strRet;
}
CString GetY(AcGePoint3d &pt)
{
	CString strRet;
	strRet.Format(_T("%d"),int(pt.y));
	return strRet;
}
CString itoStr(int n)
{
	CString strRet;
	strRet.Format(_T("%d"),n);
	return strRet;
}
CString ftoStr(double d)
{
	CString strRet;
	strRet.Format(_T("%f"),d);
	return strRet;
}