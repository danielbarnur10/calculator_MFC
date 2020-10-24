// CalcDlg.cpp : implementation file

#include "stdafx.h"
#include "Calc.h"
#include "CalcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CCalcDlg dialog

CCalcDlg::CCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALC_DIALOG, pParent)
	, Var(_T(""))
	, Display(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Var);
	DDX_Text(pDX, IDC_EDIT2, Display);
}

BEGIN_MESSAGE_MAP(CCalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CCalcDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalcDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalcDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalcDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalcDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalcDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalcDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalcDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON16, &CCalcDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalcDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalcDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalcDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalcDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalcDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalcDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalcDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON22, &CCalcDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON20, &CCalcDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON18, &CCalcDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CCalcDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON21, &CCalcDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON23, &CCalcDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CCalcDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &CCalcDlg::OnBnClickedButton25)
END_MESSAGE_MAP()

// CCalcDlg message handlers

BOOL CCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalcDlg::OnBnClicked1()
{
	Display += '1';
	Var += '1';
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton2()
{
	Display += '2';
	Var += '2';
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton3()
{
	Display += '3';
	Var += '3';
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton4()
{
	Display += '4';
	Var += '4';
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton5()
{
	Display += '5';
	Var += '5';
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton6()
{
	Display += '6';
	Var += '6';
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton7()
{
	Display += '7';
	Var += '7';
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton8()
{
	Display += '8';
	Var += '8';
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton9()
{
	Display += '9';
	Var += '9';
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton16()
{
	Display += '0';
	Var += '0';
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton10()// +
{
	UpdateData(true);
	flag = 1;
	var1 = _wtof(Display);
	Display += '+';
	Var = "";
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton11()// -
{
	UpdateData(true);
	flag = 2;
	var1 = _wtof(Display);
	Display += '-';
	Var = "";
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton12()// *
{
	UpdateData(true);
	flag = 3;
	var1 = _wtof(Display);
	Display += 'X';
	Var = "";
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton13()// '/'
{
	UpdateData(true);
	flag = 4;
	var1 = _wtof(Display);
	Display += '/';
	Var = "";
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton14()// ^
{
	UpdateData(true);
	flag = 5;
	var1 = _wtof(Display);
	Display += '^';
	Var = "";
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton15()//square root
{
	UpdateData(true);
	flag = 6;
	var1 = _wtof(Display);
	Var.Format(_T("%.3lf"), sqrt(var1));
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton17()// =
{
	Display += '=';
	UpdateData(FALSE);
	if (flag == 1 || flag == 2)
	{
		UpdateData(true);
		var2 = _wtof(Var);
		Basic action(var1, var2, flag);
		Var.Format(_T("%.3lf"), action.getresult());
	}
	else if (flag == 3 || flag == 4)
	{
		UpdateData(true);
		var2 = _wtof(Var);
		if (var2 == 0)
			Var = "Error, attemted to divide by zero!";
		else 
		{
			Basic2 action(var1, var2, flag);
			Var.Format(_T("%.3lf"), action.getresult());
		}
	}
	else if (flag == 5)
	{
		UpdateData(true);
		var2 = _wtof(Var);
		Basic3 action(var1, var2, flag);
		Var.Format(_T("%.3lf"), action.getresult());
	}
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton22()// AC
{
	Display = "";
	Var = "";
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton1()// .
{
	Display += '.';
	Var += ".";
	UpdateData(false);
}

void CCalcDlg::serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		if (flag == 6)
		{
			ar << flag;
			ar << Var;
		}
		else
		{
			ar << flag;
			ar << var1;
			ar << var2;
		}
	}
	else
	{
		ar >> flag;
		if (flag == 6)
			ar >> Var;
		else
		{
			CString temp;
			ar >> var1;
			ar >> var2;
			temp.Format(_T("%.3lf"), var2);
			if (flag == 1 || flag == 2)
			{
				Display.Format(_T("%.3lf"), var1);
				if (flag == 1)
					Display += '+';
				else if (flag == 2)
					Display += '-';
				Display += temp;
				Basic x(var1, var2, flag);
				Var.Format(_T("%.3lf"), x.getresult());
			}
			else if (flag == 3 || flag == 4)
			{
				Display.Format(_T("%.3lf"), var1);
				if (flag == 3)
					Display += '*';
				else if (flag == 4)
					Display += '/';
				Display += temp;
				Basic2 x(var1, var2, flag);
				Var.Format(_T("%.3lf"), x.getresult());
			}
			if (flag == 5)
			{
				Display.Format(_T("%.3lf"), var1);
				Display += '^';
				Display += temp;
				Basic3 x(var1, var2, flag);
				Var.Format(_T("%.3lf"), x.getresult());
			}
		}
		UpdateData(FALSE);
	}
}

void CCalcDlg::OnBnClickedButton20()//save
{
	// Save data from controls to member variables
	UpdateData(TRUE);
	// Create a file
	CFile f;
	f.Open(_T("mydialog.txt"), CFile::modeCreate | CFile::modeWrite);
	// Create a CArchive
	CArchive ar(&f, CArchive::store);
	// Serialize
	serialize(ar);
	ar.Close();
	f.Close();
}

void CCalcDlg::OnBnClickedButton18()//load
{
	CFile f;
	f.Open(_T("mydialog.txt"), CFile::modeRead);
	// Create a CArchive
	CArchive ar(&f, CArchive::load);
	// Serialize
	serialize(ar);
	ar.Close();
	f.Close();
}


void CCalcDlg::OnBnClickedButton19()// backspace
{
	UpdateData(true);
	int size1 = Var.GetLength(), size2 = Display.GetLength();
	Var.Delete(size1 - 1, 1);
	Display.Delete(size2 - 1, 1);
	UpdateData(false);
}


void CCalcDlg::OnBnClickedButton21()//LOG10
{
	UpdateData(true);
	var1 = _wtof(Display);
	Var.Format(_T("%.3lf"), log10(var1));
	var1 = 0;
	flag = 6;
	UpdateData(false);
}


void CCalcDlg::OnBnClickedButton23()//sin
{
	UpdateData(true);
	var1 = _wtof(Display);
	Var.Format(_T("%.3lf"), sin(var1));
	var1 = 0;
	flag = 6;
	UpdateData(false);
}

void CCalcDlg::OnBnClickedButton24()//cos
{
	UpdateData(true);
	var1 = _wtof(Display);
	Var.Format(_T("%.3lf"), cos(var1));
	var1 = 0;
	flag = 6;
	UpdateData(false);
}


void CCalcDlg::OnBnClickedButton25()//tan
{
	UpdateData(true);
	var1 = _wtof(Display);
	Var.Format(_T("%.3lf"), tan(var1));
	var1 = 0;
	flag = 6;
	UpdateData(false);
}
