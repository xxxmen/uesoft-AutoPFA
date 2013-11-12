#ifndef PERSISTENTHEADER_H
#define PERSISTENTHEADER_H

class AcGePoint3d;
template<UINT size>class StrArray;
const double PI = 3.1415926535897932384626433832795;
const double GA = 9.80665;

__declspec(dllexport) double TransStd(CString strValue,CString strUnit);
__declspec(dllexport) double TransStd(double dIn,CString strUnit);
__declspec(dllexport) double TransFromStd(double dIn,CString strUnit);
__declspec(dllexport) double TransStd(StrArray<2> &Value);

__declspec(dllexport) CString GetX(AcGePoint3d &pt);
__declspec(dllexport) CString GetY(AcGePoint3d &pt);
__declspec(dllexport) CString itoStr(int n);
__declspec(dllexport) CString ftoStr(double d);
#endif 