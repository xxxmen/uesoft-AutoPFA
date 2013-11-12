// FourQuadrantDBManager.h: interface for the CFourQuadrantDBManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FOURQUADRANTDBMANAGER_H__7E1A49AB_DBF0_4F35_814D_D7060FBBF701__INCLUDED_)
#define AFX_FOURQUADRANTDBMANAGER_H__7E1A49AB_DBF0_4F35_814D_D7060FBBF701__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef UNICODE
typedef wifstream ueifStream;
#else
typedef ifstream ueifStream;
#endif

class CFourQuadrantDBManager  
{
public:	
	CFourQuadrantDBManager();
	virtual ~CFourQuadrantDBManager();	
public:
	int GetAngelExpression(CString strID);
	BOOL GetSpeedOfSqecID(CString &strSpeed, CString strID);
	void GetFourQuadrantTable(CalcTable<2> &DBTable, CString ID);
	BOOL QueryID(CString &ID);
	void GetSqecSpeedTable(CalcTable<2> &speedTable);
	static CFourQuadrantDBManager& Instance();
private:
	void Init();
	CString m_configFilePath;
private:
	void SlipeString(CString &strFront, CString &strBack, CString strSource);
	void GetFourQuadrantDB(CalcTable<2> &DBTable, TCHAR *buffer, ueifStream &file);
	void GetSqecSpeed(CalcTable<2> &speedTable, ueifStream &file, TCHAR *buffer);
	static const CString strTableDBBegin;
	static const CString strTableDBEnd;
};

#endif // !defined(AFX_FOURQUADRANTDBMANAGER_H__7E1A49AB_DBF0_4F35_814D_D7060FBBF701__INCLUDED_)
