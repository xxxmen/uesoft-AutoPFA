// AutoPFADoc.h : interface of the CAutoPFADoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AUTOPFADOC_H__CB6B5A01_EDAF_4584_85F1_FBAD4B541A8F__INCLUDED_)
#define AFX_AUTOPFADOC_H__CB6B5A01_EDAF_4584_85F1_FBAD4B541A8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PFAOptimize.h"
#include "PFAOptimitationData.h"
#include "ScenariManage.h"
#include "MOCCalcModel.h"
#include "PFAOutModel.h"

#include "WorkSpaceRef.h"
#include "PersistentMgr.h"
#include "UnitSubSystem.h"



#include "PFAOptimize.h"
#include "OptimizationParameter.h"
#include "OptControl.h"

#include "OutPutRefItem.h"
#include "OutputRefPersist.h"
class ImpulseDataMgr;

class CAutoPFADoc : public CDocument
{
protected: // create from serialization only
	CAutoPFADoc();
	DECLARE_DYNCREATE(CAutoPFADoc)

// Attributes
    
public:
   ImpulseDataMgr* m_pImpulseData;
   UnitSubSystem m_unitSystem;
   ScenariManage m_scenarioManager;
   MOCCalcModel  m_calcModel;
   PFAOutModel   m_OutModel;
   WorkSpaceRef  m_workSpaceRef;
   PersistentMgr m_PersistentMgr;
 //  OutPutRefData m_OutPutRefData;
   OutputRefPersist m_OutPutData;
	PersistentModel GlobalModel;
// Operations
public:
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoPFADoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL Mutex();
	void Mutex(BOOL bMutex);
	BOOL OutMutex();
	void OutMutex(BOOL bMutex);
	BOOL Save(LPCTSTR lpszPathName);
//	int SetTableData( _ConnectionPtr conPtr, CString tableName,OutAttrArray outarray );
	virtual ~CAutoPFADoc();

	//CPFAOptimize* GetOptPointer();
	CPFAOptimize m_Optimize;
	int m_iAnalysisTpye;


#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
public:

protected:

	BOOL m_bMutex; 
	BOOL m_bOutMutex; 

// Generated message map functions
public:
	//{{AFX_MSG(CAutoPFADoc)
	afx_msg void OnParamUnit();
	afx_msg void OnSystemProper();
	afx_msg void OnSteadyAnalysis();
	afx_msg void OnUpdateSteadyAnalysis(CCmdUI* pCmdUI);
	afx_msg void OnTransanAlysis();
	afx_msg void OnUpdateTransAnalysis(CCmdUI* pCmdUI);
	afx_msg void OnSteadyControl();
	afx_msg void OnSectionPipe();
	afx_msg void OnTransControl();
	afx_msg void OnExportCalcFile();
	afx_msg void OnRunModel();
	afx_msg void OnCheckModel();
	afx_msg void OnPfahelp();
	afx_msg void OnViewDataModel();
	afx_msg void OnViewGraph();
	afx_msg void OnViewOutput();
	afx_msg void OnViewWorkSpece();
	afx_msg void OnIdOptimizationOptpara();
	afx_msg void OnOptcontral();
	afx_msg void OnOptanalysis();
	afx_msg void OnUpdateOptanalysis(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	

	        

	void ActiveView(const CRuntimeClass* pClass);
	BOOL GetModel(PersistentModel &model,Scenario *pScenario=NULL);
	void CalcMOCModel(const CString &strFile);
	BOOL CheckModel(BOOL bShow);
	void CreatModelDataWnd();
	void CreatOutDataWnd();
	void CreatGraphWnd();
	BOOL Read(LPCTSTR lpszPathName);
	void SetPFApipe();


    
	afx_msg void OnOutPutControl();
	afx_msg void OnOutPutResult();
};
inline void CAutoPFADoc::Mutex(BOOL bMutex)
{
	m_bMutex = bMutex;
}

inline BOOL CAutoPFADoc::Mutex()
{
	return m_bMutex;
}
inline void CAutoPFADoc::OutMutex(BOOL bMutex)
{
	m_bOutMutex = bMutex;
}

inline BOOL CAutoPFADoc::OutMutex()
{
	return m_bOutMutex;
}


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOPFADOC_H__CB6B5A01_EDAF_4584_85F1_FBAD4B541A8F__INCLUDED_)
