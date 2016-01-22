
// FILE验证Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "FILE验证.h"
#include "FILE验证Dlg.h"
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
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFILE验证Dlg dialog



CFILE验证Dlg::CFILE验证Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFILE验证Dlg::IDD, pParent)
	, m_EditKey(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFILE验证Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, EDIT_KEY, m_EditKey);
	DDX_Control(pDX, EDIT_KEY, m_editKey);
}

BEGIN_MESSAGE_MAP(CFILE验证Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CFILE验证Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CFILE验证Dlg message handlers

BOOL CFILE验证Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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
	char szKey[] = "你好123456";
//	DWORD unicodeFlag = 0xFEFF;	//设置当前是用的unicode编码
	DWORD dwFileLength = 0;
	HANDLE hFile = CreateFile(
		TEXT("user.txt"),		//lpFileName
		GENERIC_WRITE,			//dwDesiredAccess
		FILE_SHARE_WRITE,		//dwShareMode
		NULL,					//lpSecurityAttributes
		CREATE_NEW,				//dwCreationDisposition
		FILE_ATTRIBUTE_NORMAL,	//dwFlagsAndAttributes
		NULL					//hTemplateFile
		);
	if (INVALID_HANDLE_VALUE == hFile)
	{
		AfxMessageBox(TEXT("产生机器码文件失败！"));
	}
	else
	{
		AfxMessageBox(TEXT("产生机器码文件成功！"));
/*		WriteFile(hFile, &unicodeFlag, sizeof(unicodeFlag), &dwFileLength, NULL);*/
		BOOL isWrite = WriteFile(
			hFile,
			szKey,
			strlen(szKey)*sizeof(char),
			&dwFileLength,
			NULL
			);
		if (isWrite)
		{
			AfxMessageBox(L"写入机器码成功~");
		}
	}

	CloseHandle(hFile);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFILE验证Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFILE验证Dlg::OnPaint()
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
HCURSOR CFILE验证Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFILE验证Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	BYTE szReadKey[MAXBYTE] = { 0 };
	DWORD dwReadLength = 0;
	HANDLE hFile = CreateFile(
		TEXT("user.txt"),		//lpFileName
		GENERIC_READ,			//dwDesiredAccess
		FILE_SHARE_READ,		//dwShareMode
		NULL,					//lpSecurityAttributes
		OPEN_EXISTING,				//dwCreationDisposition
		FILE_ATTRIBUTE_NORMAL,	//dwFlagsAndAttributes
		NULL					//hTemplateFile
		);
	if (INVALID_HANDLE_VALUE==hFile)
	{
		AfxMessageBox(TEXT("读取机器码文件失败！"));
	}
	else
	{
		AfxMessageBox(TEXT("读取机器码文件成功！"));
		ReadFile(hFile, szReadKey, MAXBYTE, &dwReadLength, NULL);
	}
	m_editKey.GetWindowTextW(m_EditKey);
	CString *pReadKey = new CString((char*)szReadKey, m_EditKey.GetLength()+2);
	if (wcscmp(pReadKey->GetString(), m_EditKey) == 0)
	{
		AfxMessageBox(_T("注册成功！"));

		m_VIPDlg.DoModal();
	}
	else
	{
		AfxMessageBox(_T("注册失败！"));
	}

	CloseHandle(hFile);
}
