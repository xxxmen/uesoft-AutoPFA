// PageJunOutControl.cpp : 实现文件
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "PageJunOutControl.h"
#include "UnitSubSystem.h"


// PageJunOutControl 对话框

IMPLEMENT_DYNAMIC(PageJunOutControl, CDialog)

PageJunOutControl::PageJunOutControl(PFAOutModel& outModel,CWnd* pParent /*=NULL*/)
	: CDialog(PageJunOutControl::IDD, pParent)
	,m_pPageAtt(outModel)
	,m_outModel(outModel)
{

}

PageJunOutControl::~PageJunOutControl()
{
}

void PageJunOutControl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_NOTSHOWOUT, m_tab);
	DDX_Control(pDX, IDC_LIST_SHOWOUT, m_lstShowAtt);
	DDX_Control(pDX, IDC_COMBO_Unit, m_comboUnit);
}


BEGIN_MESSAGE_MAP(PageJunOutControl, CDialog)
	ON_BN_CLICKED(IDC_BTN_ADD, &PageJunOutControl::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_BTN_DELETE, &PageJunOutControl::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_BUTTON3, &PageJunOutControl::OnBtnDeleteAll)
	ON_CBN_SELCHANGE(IDC_COMBO_Unit, &PageJunOutControl::OnCbnSelchangeComboUnit)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_SHOWOUT, &PageJunOutControl::OnLvnItemchangedListShowout)
END_MESSAGE_MAP()


// PageJunOutControl 消息处理程序
BOOL PageJunOutControl::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_tab.AddPage( _T(""), &m_pPageAtt, IDD_DATALIST );
	m_tab.Show();

	m_lstShowAtt.InsertColumn( 0 , _T("") ,LVCFMT_CENTER , 100 );
	m_lstShowAtt.InsertColumn( 1 , _T("") ,LVCFMT_CENTER , 100 );

	OutMgr &outMgr = m_outModel.SteadyOut().ComponentOutMgr().JunOutMgr();
	OutAttrArray& arr = outMgr.GetArray();         

	m_strJunOrder = outMgr.m_OutPutData.JunDataOrder();
	m_strUnitOrder = outMgr.m_OutPutData.JunUnitOrder();

	LoadShowAtt( outMgr );//保存默认显示的属性字段
	LoadAllAtt( outMgr );      //保存所有可能显示的属性字段

	UpdateData( FALSE );
	return TRUE;
}

void PageJunOutControl::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码

	int nItem = m_pPageAtt.GetSelectedItem();
	int nKey = m_pPageAtt.GetItemData(nItem);
	if ( -1 == nKey )
	{
		return;
	}

	CString strName = m_pPageAtt.GetItemText( nItem, 0 );
	CString strUnit = m_pPageAtt.GetItemText( nItem, 1 );

	m_lstShowAtt.InsertItem( m_lstShowAtt.GetItemCount(), strName );
	m_lstShowAtt.SetItemText( m_lstShowAtt.GetItemCount()-1, 1, strUnit );
	m_lstShowAtt.SetItemData( m_lstShowAtt.GetItemCount()-1, nKey );

	m_pPageAtt.DeleteItem(nItem);

}

void PageJunOutControl::OnBnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	POSITION pos = m_lstShowAtt.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		TRACE0("No items were selected!\n");
	}
	else
	{
		while (pos)
		{
			int nItem = m_lstShowAtt.GetNextSelectedItem(pos);
			TRACE1("Item %d was selected!\n", nItem);
			// you could do your own processing on nItem here
			int nKey = (int)m_lstShowAtt.GetItemData( nItem );
			CString strUnit = m_lstShowAtt.GetItemText( nItem, 1 );
			CString strText = m_lstShowAtt.GetItemText( nItem, 0 );
			m_lstShowAtt.DeleteItem( nItem );
			m_pPageAtt.AddItem( strText, strUnit, nKey );

			break;
		}
	}
}

void PageJunOutControl::OnBtnDeleteAll()
{
	while( m_lstShowAtt.GetItemCount() != 0 )
	{
		int nKey = (int)m_lstShowAtt.GetItemData( 0 );
		CString strUnit = m_lstShowAtt.GetItemText( 0, 1 );
		CString strText = m_lstShowAtt.GetItemText( 0, 0 );
		m_lstShowAtt.DeleteItem( 0 );
		m_pPageAtt.AddItem( strText, strUnit, nKey );
	}
}

BOOL PageJunOutControl::Find( CString strKey )
{

	int i = 0;
	for ( ; i < m_lstShowAtt.GetItemCount(); i++ )
	{
		if ( _ttoi(strKey) == (int)m_lstShowAtt.GetItemData(i) )
		{
			return TRUE;
		}
	}
	return FALSE;

}

void PageJunOutControl::UpData()
{
	OutMgr &outMgr = m_outModel.SteadyOut().ComponentOutMgr().JunOutMgr();
	OutAttrArray& arr = outMgr.GetArray();
	CString strOrder = _T("");
	CString strUnit;

	int i = 0;
	for ( ; i < m_lstShowAtt.GetItemCount(); i++ )
	{
		if ( m_lstShowAtt.GetItemData(i) == 0 )
		{
			continue;
		}
		CString strDataTemp;
		strDataTemp.Format( _T("%d") , m_lstShowAtt.GetItemData(i) );
		strOrder += strDataTemp;
		strOrder += _T(",");

		strUnit += m_lstShowAtt.GetItemText( i, 1 );
		strUnit += _T(",");
	}

	strOrder.TrimRight( _T(",") );
	strUnit.TrimRight( _T(",") );
	outMgr.m_OutPutData.JunDataOrder( strOrder );
	outMgr.m_OutPutData.JunUnitOrder( strUnit );
}

void PageJunOutControl::LoadShowAtt( OutMgr& outMgr )
{
    m_lstShowAtt.DeleteAllItems();
	OutAttrArray& outShowArr = outMgr.GetArray();

	CString str[50];//保存Key;
	InitData(m_strJunOrder,str);

	int k=0;
	int j;   
	for (k = 0; k < 30;k++)
	{
		if (str[k] == "0")
			break;

		for(j = 0; j < 30; j++)
		{	
			if (str[k] != "0" && str[k] == outMgr.m_OutPutSys.GetJunOutArray()[j].GetKey())
			{
				CString strName = /*outMgr.m_OutPutSys.GetJunOutArray()[j].GetStrName();*/outShowArr.GetAt(j+1).Name();
				CString strUnit = /*outMgr.m_OutPutSys.GetJunOutArray()[j].GetStrUnit();*/outShowArr.GetAt(j+1).Unit();
				CString strKey = outMgr.m_OutPutSys.GetJunOutArray()[j].GetKey();

				//m_outShowArr.Add( outShowArr.GetAt(j+1) );
				m_lstShowAtt.InsertItem( m_lstShowAtt.GetItemCount() ,strName );
				m_lstShowAtt.SetItemText( m_lstShowAtt.GetItemCount()-1, 1, strUnit );
				m_lstShowAtt.SetItemData( m_lstShowAtt.GetItemCount()-1, _ttoi(strKey) );
				break;
			}
		}
	}
}

void PageJunOutControl::LoadAllAtt( OutMgr& outMgr )
{
	m_pPageAtt.DeleteAllItems();

	int i=0;   
	//m_outArr.RemoveAll();
	int nCount = outMgr.m_OutPutSys.GetJunOutArray().GetSize();

	for (i = 0; i < nCount; i++ )
	{
		CString strName = outMgr.m_OutPutSys.GetJunOutArray()[i].GetStrName();
		CString strUnit = outMgr.m_OutPutSys.GetJunOutArray()[i].GetStrUnit();
		CString strKey = outMgr.m_OutPutSys.GetJunOutArray()[i].GetKey();

		//m_outArr.Add(outAll.GetAt(i));

		if ( !Find( strKey ) &&  strName != _T("0") && !strName.IsEmpty() && strUnit != _T("0") )//查看该属性是否在显示属性列表里，是的话不用添加到不显示属性列表里
		{
			m_pPageAtt.AddItem( strName, strUnit, _ttoi(strKey) );
		}
	}
}

void PageJunOutControl::InitData(CString InData,CString str[50])
{
	InData.TrimLeft();
	int nIdex=0;
	int i;
	int strj=0;
	for (i=0;i<50;i++)
	{
		nIdex=InData.Find(_T(','));
		strj++;
		if (nIdex==-1)
		{
			InData.TrimRight();
			str[strj-1]=InData;
			break;
		}
		if (nIdex==0)
		{
			InData.Delete(0,1);
			continue;
		}
		str[i]=InData.Left(nIdex);
		InData.Delete(0,nIdex+1);		
	}

	for (;strj<50;strj++)
	{
		str[strj]="0";
	}

}

/************************************************************************
版本: 8.0  开发时间: [2009/4/22]  作者: [ue8] 评审人:
功能: 从文件里面读取数据，控制输出结果显示字段                                                             
输入:                                                               
输出:                                                              
< 修改人 >    < 时间 >     < 版本 >        < 描述 >                                                                               
************************************************************************/
BOOL PageJunOutControl::Read(CStdioFile& file)
{
	BOOL bJunFlag = FALSE;
	CString strJunOrder;
	file.ReadString( strJunOrder );
	if ( -1 != strJunOrder.Find( _T("Junction Data Order") ) )
	{
		int pos = strJunOrder.Find( _T("=") );
		if ( -1 != pos )
		{
			strJunOrder = strJunOrder.Mid( pos + 1 );
			strJunOrder.TrimLeft();
			strJunOrder.TrimRight();
		}
		bJunFlag = TRUE;
	}

	BOOL bUnitFlag = FALSE;
	CString strUnitOrder;
	file.ReadString(strUnitOrder);
	if ( -1 != strUnitOrder.Find( _T("Junction Data Units") ) )
	{
		int pos = strUnitOrder.Find( _T("=") );
		if ( -1 != pos )
		{
			strUnitOrder.Mid( pos + 1 );
			strUnitOrder.TrimLeft();
			strUnitOrder.TrimRight();
		}
		bUnitFlag = TRUE;
	}

	if ( bJunFlag && bUnitFlag )
	{
		m_strJunOrder = strJunOrder;
		m_strUnitOrder = strUnitOrder;

		OutMgr &outMgr = m_outModel.SteadyOut().ComponentOutMgr().JunOutMgr();
		OutAttrArray& arr = outMgr.GetArray(); 
		LoadShowAtt( outMgr );
		LoadAllAtt( outMgr );
		return TRUE;
	}
	return FALSE;
}

BOOL PageJunOutControl::Save(CStdioFile& file)
{
	CString strJunOrder = _T("Junction Data Order=");
	m_strJunOrder.TrimRight( _T("\n") );
	strJunOrder += m_strJunOrder;
	strJunOrder += _T("\n");
	file.WriteString(strJunOrder);

	CString strUnitOrder = _T("Junction Data Units=");
	m_strJunOrder.TrimRight( _T("\n") );
	strJunOrder += m_strJunOrder;
	strJunOrder += _T("\n");
	file.WriteString(strJunOrder);
	return TRUE;
}

void PageJunOutControl::OnCbnSelchangeComboUnit()
{
	int nIndex = m_comboUnit.GetCurSel();
	if ( nIndex < 0 )
	{
		return;
	}
	CString strUnit = _T("");
	m_comboUnit.GetLBText( nIndex , strUnit );

	POSITION pos = m_lstShowAtt.GetFirstSelectedItemPosition();
	if ( pos == NULL )
	{
		return;
	}
	int nItem = m_lstShowAtt.GetNextSelectedItem( pos );
	if ( nItem < 0 )
	{
		return;
	}
	m_lstShowAtt.SetItemText( nItem , 1 , strUnit );
}

/************************************************************************
版本: 8.0  注释时间: [2009/4/21]  作者: [Zhufy] 评审人: 
功能:    根据所选中的列初始化单位列表                                                        
输入:                                                               
输出:                                                              
< 修改人 >    < 时间 >     < 版本 >        < 描述 >                                                                               
************************************************************************/
void PageJunOutControl::OnLvnItemchangedListShowout(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	POSITION pos = m_lstShowAtt.GetFirstSelectedItemPosition();
	if ( pos == NULL )
	{
		return;
	}

	int nItem = m_lstShowAtt.GetNextSelectedItem( pos );
	int nKey = (int)m_lstShowAtt.GetItemData(nItem);
	if ( -1 == nKey )
	{
		return;
	}
	CString strKey;
	strKey.Format( _T("%d") , nKey );

	OutMgr &outMgr = m_outModel.SteadyOut().ComponentOutMgr().JunOutMgr();
	OutAttrArray& AttArr = outMgr.GetArray();
	OutDataAttr &dataAttr = AttArr.GetAt( 0 );
	int i;
	for(i = 0; i < 30; i++)
	{	
		if ( strKey != _T("0") && strKey == outMgr.m_OutPutSys.GetJunOutArray()[i].GetKey())
		{
			dataAttr = AttArr.GetAt( i + 1 );
			break;
		}
	}
	m_comboUnit.ResetContent();
	SymbolArray array;
	UnitSubSystem &system = dataAttr.UnitSys();
	UnitTypeID id = dataAttr.UnitType();
	CString m_strCurSymbol = dataAttr.Unit();
	system.FindSymbolArray( id,array );
	for( i=0;i<array.GetSize();i++ )
	{
		m_comboUnit.AddString( array.GetAt(i) );
	}
	m_comboUnit.SelectString( -1,m_strCurSymbol );
	*pResult = 0;
}