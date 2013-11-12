// pagebendmodel.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "pagebendmodel.h"
#include "Bend.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageBendModel dialog


PageBendModel::PageBendModel(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageBendModel::IDD, pParent)
	,m_dlgBasisArea(UnitSys)
	,m_UnitSys(UnitSys)
{
	//{{AFX_DATA_INIT(PageBendModel)
	m_strAngle = _T("");
	m_strK = _T("");
	m_strRD = _T("");
	m_nType = 0;
	m_nAngelType = 0;
	//}}AFX_DATA_INIT
	BitMapID[0] = IDB_BITMAPBEND;
	BitMapID[1] = IDB_BITMAPELBOW;
	BitMapID[2] = IDB_BITMAPMITRE;
}


void PageBendModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageBendModel)
	DDX_Control(pDX, IDC_ERD, m_EditRD);
	DDX_Control(pDX, IDC_EK, m_EditK);
	DDX_Control(pDX, IDC_EANGEL, m_EditAngel);
	DDX_Control(pDX, IDC_BOX, m_Box);
	DDX_Control(pDX, IDC_BITMAP, m_Bitmap);
	DDX_Text(pDX, IDC_EANGEL, m_strAngle);
	DDX_Text(pDX, IDC_EK, m_strK);
	DDX_Text(pDX, IDC_ERD, m_strRD);
	DDX_Radio(pDX, IDC_RADIOBEND, m_nType);
	DDX_Radio(pDX, IDC_RADIO90, m_nAngelType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageBendModel, BaseDlg)
	//{{AFX_MSG_MAP(PageBendModel)
	ON_BN_CLICKED(IDC_RADIOBEND, OnRadioBend)
	ON_BN_CLICKED(IDC_RADIOELBOW, OnRadioElbow)
	ON_BN_CLICKED(IDC_RADIOMITRE, OnRadioMitre)
	ON_BN_CLICKED(IDC_RADIOCUSTOM, OnRadioCustom)
	ON_BN_CLICKED(IDC_RADIO90, OnRadio90)
	ON_BN_CLICKED(IDC_RADIONO90, OnRadioNo90)
	ON_EN_CHANGE(IDC_ERD, OnChangeErd)
	ON_EN_SETFOCUS(IDC_EK, OnSetfocusEk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageBendModel message handlers

BOOL PageBendModel::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgBasisArea.Create(IDD_DLGBASISAREA,this);
	Combine(this,m_Box,m_dlgBasisArea);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageBendModel::Init(CStringArray &PipeArea)
{
	VerticalNum = 0;
	m_dlgBasisArea.Init(Bend::ms_BasisArea);
	m_nType = Bend::ms_Type.GetnValue();
	m_nAngelType = Bend::ms_AngleType.GetnValue();
	m_strAngle = Bend::ms_Angle.GetValue();
	m_India = sqrt(4*_tcstod(PipeArea.GetAt(0), NULL )/PI);
	m_Outdia = sqrt(4*_tcstod(PipeArea.GetAt(1), NULL )/PI);
	m_strRD = Bend::ms_RD.GetValue();
	m_strK = Bend::ms_K.GetValue();
	SetTypeModel();
	SetTypeStatus();
	UpdateData(FALSE);
}

BOOL PageBendModel::UpData()
{
	UpdateData(TRUE);
	m_dlgBasisArea.UpData(Bend::ms_BasisArea);
	Bend::ms_Type.SetValue(m_nType);
	Bend::ms_AngleType.SetValue(m_nAngelType);
	Bend::ms_Angle.SetValue(m_strAngle);
	Bend::ms_RD.SetValue(m_strRD);
	Bend::ms_K.SetValue(m_strK);
	return TRUE;
}

void PageBendModel::SetTypeModel()
{
	if(m_nType>=0&&m_nType<3)
	{
		m_bitmap.DeleteObject();
		m_bitmap.LoadBitmap(BitMapID[m_nType]);
		m_Bitmap.SetBitmap(m_bitmap);
	}
	else
	{
		m_Bitmap.SetBitmap(NULL);
	}
}

void PageBendModel::OnRadioBend() 
{
	// TODO: Add your control notification handler code here
	m_nType = 0;
	SetTypeModel();
	SetTypeStatus();
}

void PageBendModel::OnRadioElbow() 
{
	// TODO: Add your control notification handler code here	
	m_nType = 1;
	double K = 30;
	CalcK(K);
	SetTypeModel();
	SetTypeStatus();
	UpdateData(TRUE);
	
}

void PageBendModel::OnRadioMitre() 
{
	// TODO: Add your control notification handler code here
	m_nType = 2;
	double K = 0;
	if(m_nAngelType == 0)
	{
		K = 60;	
		CalcK(K);
	}
	SetTypeModel();
	SetTypeStatus();
}

void PageBendModel::OnRadioCustom() 
{
	// TODO: Add your control notification handler code here
	m_nType = 3;
	SetTypeModel();
	SetTypeStatus();
}

void PageBendModel::OnRadio90() 
{
	// TODO: Add your control notification handler code here
	m_nAngelType =0;
	SetTypeStatus();
}

void PageBendModel::OnRadioNo90() 
{
	// TODO: Add your control notification handler code here
	m_nAngelType = 1;
	SetTypeStatus();
}

void PageBendModel::CalcK(double K)
{
	UpdateData(TRUE);
	double India;                  //损失模型，上游面积、下游面积、自定义面积
	double ratio = 0;
	CString area;
	switch (m_dlgBasisArea.m_nRefType){
	case 0:
		India = m_India;
		break;
	case 1:
		India = m_Outdia;
		break;
	case 2:
		India = _tcstod(m_dlgBasisArea.GetArea(), NULL );
 		India =  sqrt(4*India/PI);
		break;
	case 3:
		India = _tcstod(m_dlgBasisArea.GetArea(), NULL );
		break;
	default:
		break;
	}
	India = India/0.0254;
	if(India < 0.00000001)
		m_strK = " ";
	else
		if(India < 0.50001)
			m_strK.Format(_T("%f"),K*0.027);
		else
			if(India < 0.75001)
				m_strK.Format(_T("%f"),K*(0.027*(1-(India-0.5)/0.25)+0.025*(1-(0.75-India)/0.25)));
			else
				if(India < 1.00001)
					m_strK.Format(_T("%f"),K*(0.025*(1-(India-0.75)/0.25)+0.023*(1-(1-India)/0.25)));
				else
					if(India < 1.25001)
						m_strK.Format(_T("%f"),K*(0.023*(1-(India-1)/0.25)+0.022*(1-(1.25-India)/0.25)));
					else
						if(India < 1.50001)
							m_strK.Format(_T("%f"),K*(0.022*(1-(India-1.25)/0.25)+0.021*(1-(1.5-India)/0.25)));
						else
							if(India < 2.00001)
								m_strK.Format(_T("%f"),K*(0.021*(1-(India-1.5)/0.5)+0.019*(1-(2-India)/0.5)));
							else
								if(India < 2.50001)
									m_strK.Format(_T("%f"),K*(0.019*(1-(India-2)/0.5)+0.018*(1-(2.5-India)/0.5)));
								else
									if(India < 3.00001)
										m_strK.Format(_T("%f"),K*0.018);
									else
										if(India < 4.00001)
											m_strK.Format(_T("%f"),K*(0.018*(1-(India-3)/1)+0.017*(1-(4-India)/1)));
										else
											if(India < 5.00001)
												m_strK.Format(_T("%f"),K*(0.017*(1-(India-4)/1)+0.016*(1-(5-India)/1)));
											else
												if(India < 6.00001)
													m_strK.Format(_T("%f"),K*(0.016*(1-(India-5)/1)+0.015*(1-(6-India)/1)));
												else
													if(India < 8.00001)
														m_strK.Format(_T("%f"),K*(0.015*(1-(India-6)/2)+0.014*(1-(8-India)/2)));
													else
														if(India < 10.00001)
															m_strK.Format(_T("%f"),K*0.014);
														else
															if(India < 12.00001)
																m_strK.Format(_T("%f"),K*(0.014*(1-(India-10)/2)+0.013*(1-(12-India)/2)));
															else
																if(India < 16.00001)
																	m_strK.Format(_T("%f"),K*0.013);
																else
																	if(India < 18.00001)
																		m_strK.Format(_T("%f"),K*(0.013*(1-(India-16)/2)+0.012*(1-(18-India)/2)));
																	else
																		m_strK.Format(_T("%f"),K*0.012);
// if (VerticalNum > 0)
// {
// 	m_strK.Format(_T("%f"),_tcstod(m_strK)*0.7);
// }
	UpdateData(FALSE);
}

void PageBendModel::SetTypeStatus()
{
	switch(m_nType) {
	case 0: 
		m_EditRD.EnableWindow(TRUE);
		m_EditK.SetReadOnly(TRUE);
		break;
	case 1: 
		m_EditRD.EnableWindow(FALSE);
	//	m_EditK.SetReadOnly(TRUE);
		m_EditK.SetWindowText(m_strK);
		m_EditK.SetReadOnly(FALSE);
//		m_EditK.SetWindowText(Bend::ms_BasisArea.GetValue(0));
		break;
	case 2: 
		m_EditRD.EnableWindow(FALSE);
		m_EditK.SetWindowText(m_strK);
		m_EditK.SetReadOnly(TRUE);
		break;
	case 3: 
		m_EditRD.EnableWindow(FALSE);
		m_EditK.SetReadOnly(FALSE);
		break;
	default:
		break;
	}
	SetAngleStatus();
}

void PageBendModel::SetAngleStatus()
{
	if(m_nAngelType==0)
	{
		m_EditAngel.SetReadOnly(TRUE);
		m_strAngle = _T("90");
		m_EditAngel.SetWindowText(m_strAngle);
	}
	else
	{
		if(m_nType==1)
		{
			//m_strAngle = _T("45");
			m_EditAngel.SetReadOnly(TRUE);
		//	m_strAngle=Bend::ms_Angle.GetfValue();
			m_EditAngel.SetWindowText(m_strAngle);
		}
		else
		{
			m_strAngle.Empty();
			m_EditAngel.SetWindowText(m_strAngle);
			m_EditAngel.SetReadOnly(FALSE);
		}
	}
}

void PageBendModel::OnChangeErd() 
{
	// TODO: Add your control notification handler code here
//	UpdateData(TRUE);
	m_EditRD.GetWindowText(m_strRD);
	//UpdateData(FALSE);
}

void PageBendModel::OnSetfocusEk() 
{
	// TODO: Add your control notification handler code here
	double K = 0;
	double Rd = 0;
	CString Angle;
	double BendAngele = 90;
	switch (m_nType){
	case 0:
		m_EditAngel.GetWindowText(Angle);
		if (m_nAngelType == 1)
			BendAngele = _tcstod( Angle, NULL );
		Rd = _tcstod( m_strRD, NULL );
		if(Rd < 0.00000001)
			K = 0;
		else
			if(Rd < 1.00001)
			{
				K = 20;
				K = K*(0.005990338*BendAngele + 0.46086958);   //非90度下的拟和公式
			}
			else
				if(Rd < 1.50001)
				{
					K= 20*(0.005990338*BendAngele + 0.46086958)*(1-(Rd-1)/0.5)+14* (0.006487233* BendAngele + 0.416149)*(1-(1.5-Rd)/0.5);
				}
				else
					if(Rd < 2.00001)
						K = 14*(0.006487233* BendAngele + 0.416149)*(1-(Rd-1)/1)+12*(1-(2-Rd)/1)*(0.007012882*BendAngele+0.368841);
					else
						if(Rd < 3.00001)
							K = 12;
						else
							if(Rd < 4.00001)
								K = 12*(0.007012882*BendAngele+0.368841)*(1-(Rd-3)/1)+14*(0.008074534*BendAngele+0.273292)*(1-(4-Rd)/1);
							else
								if(Rd < 6.00001)
									K = 14*(0.008074534*BendAngele+0.273292)*(1-(Rd-4)/2)+17*(0.008633134+BendAngele+0.223018)*(1-(6-Rd)/2);
								else
									if(Rd < 8.00001)
										K = 17*(0.008633134+BendAngele+0.223018)*(1-(Rd-6)/2)+24*(0.008466184*BendAngele+0.238043)*(1-(8-Rd)/2);
									else
										if(Rd < 10.00001)
											K = 24*(0.008466184*BendAngele+0.238043)*(1-(Rd-8)/2)+30*(0.008463768*BendAngele+0.238261)*(1-(10-Rd)/2);
										else
											if(Rd < 12.00001)
												K = 30*(0.008463768*BendAngele+0.238261)*(1-(Rd-10)/2)+34*(0.008635976*BendAngele+0.222762)*(1-(12-Rd)/2);
											else
												if(Rd < 14.00001)
													K = 34*(0.008635976*BendAngele+0.222762)*(1-(Rd-12)/2)+38*(0.008769387*BendAngele+0.210755)*(1-(14-Rd)/2);
												else
													if(Rd < 16.00001)
														K = 38*(0.008769387*BendAngele+0.210755)*(1-(Rd-14)/2)+42*(0.008879687*BendAngele+0.200828)*(1-(16-Rd)/2);
													else
														if(Rd < 20.00001)
															K = 42*(0.008879687*BendAngele+0.200828)*(1-(Rd-16)/2)+50*(0.009045411*BendAngele+0.185913)*(1-(20-Rd)/2);
														else
														K = 50*(0.009045411*BendAngele+0.185913);
//	K = K*(-0.08*Rd+0.006*BendAngele + 0.721);
	CalcK(K);
    break;
	case 1:
		break;
	case 2:
		m_EditAngel.GetWindowText(Angle);
		Rd = _tcstod( Angle, NULL );
		if(Rd < 15.00001)
			K= 2*(1-(Rd-0)/15)+4*(1-(15-Rd)/15);
		else
			if(Rd < 30.00001)
				K = 4*(1-(Rd-15)/15)+8*(1-(30-Rd)/15);
			else
				if(Rd < 45.00001)
					K = 8*(1-(Rd-30)/15)+15*(1-(45-Rd)/15);
				else
					if(Rd < 60.00001)
						K = 15*(1-(Rd-45)/15)+25*(1-(60-Rd)/15);
					else
						if(Rd < 75.00001)
							K = 25*(1-(Rd-60)/15)+40*(1-(75-Rd)/15);
						else
							if(Rd <89.99999)
								K = 40*(1-(Rd-75)/15)+60*(1-(90-Rd)/15);
							else
								K = 60;
							CalcK(K);
							break;
	}
m_EditK.SetWindowText(m_strK);
}
