#pragma once
#include "mobject.h"

class StartCADObj
{
public:
	StartCADObj(void);
public:
	virtual ~StartCADObj(void);

public:
	void StartUpCAD();
	void SetTabIndex( CString tablIndex );
	CString GetTabIndex();

private:
	void GetActiveAcadDoc(BOOL bAcadR14);
	BOOL WriteFileToCAD(CMObject &refDoc, CString strDrawFileName);
	void DeleteSupportPath();
	void AddSupportPath(const CString &strInsPath);
	CString GetArxFilePath(CString strCADVersion);

	// 功能：Unicode -> Ansi
	// 输入：UNICODE字符串
	// 输出：相应的ANSI字符串
	// 备注：本函数下次调用释放上次调用分配的内存，要完全清除内存请使用ConvertUnicodeToAnsi(NULL);
	//		请确保调用结果使用完毕后才再次调用本函数。
	char* ConvertUnicodeToAnsi( IN const wchar_t* pwUNICODE );

private:
	CString m_strTabIndex;
	CMObject m_ObjAcadApp;
	CMObject m_ObjAcadDoc;
	
};

