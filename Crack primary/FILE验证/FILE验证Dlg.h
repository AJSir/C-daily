
// FILE验证Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "MainDlg.h"


// CFILE验证Dlg dialog
class CFILE验证Dlg : public CDialogEx
{
// Construction
public:
	CFILE验证Dlg(CWnd* pParent = NULL);	// standard constructor
	CMainDlg m_VIPDlg;
// Dialog Data
	enum { IDD = IDD_FILE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_EditKey;
	CEdit m_editKey;
};
