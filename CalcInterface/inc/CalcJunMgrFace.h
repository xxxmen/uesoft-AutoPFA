// CalcJunMgrFace.h: interface for the CalcJunMgrFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALCJUNMGRFACE_H__081698B8_9215_44FD_902F_CE20E1D9612F__INCLUDED_)
#define AFX_CALCJUNMGRFACE_H__081698B8_9215_44FD_902F_CE20E1D9612F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CalcJunMgr;
class JunManager;
class CalcJunFace;
class CalcJunFaceFactory;

class AFX_EXT_CLASS CalcJunMgrFace  
{
public:
	CalcJunFace* CreatJunFace(int nID);
	CalcJunMgrFace();
	virtual ~CalcJunMgrFace();
    ErrorStatus::FileError Save(CalcJunMgr &Data,JunManager& model);

private:
	CalcJunFaceFactory *m_factory;
	CalcJunMgrFace(const CalcJunMgrFace &ref);
	CalcJunMgrFace& operator=(const CalcJunMgrFace &ref);
};

#endif // !defined(AFX_CALCJUNMGRFACE_H__081698B8_9215_44FD_902F_CE20E1D9612F__INCLUDED_)
