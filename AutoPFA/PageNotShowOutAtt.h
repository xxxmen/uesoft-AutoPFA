#pragma once
#include "PageDataList.h"
#include "StmOutMgr.h"
#include "PFAOutModel.h"

// PageNotShowOutAtt 对话框

class PageNotShowOutAtt : public PageDataList
{
	DECLARE_DYNAMIC(PageNotShowOutAtt)

public:
	PageNotShowOutAtt( PFAOutModel &outModel, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PageNotShowOutAtt();

	int GetSelectedItem();
	BOOL DeleteItem(int nItm);
	BOOL AddItem(CString strText,CString strUnit, int nKey);
	void SetOutArray(OutAttrArray& arr);
	int  GetItemData( int nItem );
	CString GetItemText( int nRow, int nCol );
	void DeleteAllItems();

// 对话框数据
//	enum { IDD = IDD_PAGENOTSHOWOUTATT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
    virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
private:
	PFAOutModel& m_outModel;
	OutAttrArray m_attArr;
};
