// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "LoginDlg.h"
#include "afxdialogex.h"

#include "InfoFile.h"

// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDlg::IDD, pParent)
	, m_user(_T(""))
	, m_pwd(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	// 初始化登陆信息
	CInfoFile file;
	CString name;
	CString pwd;
	file.ReadLogin(name, pwd);

	m_user = name;
	m_pwd = pwd;

	//将变量 同步到控件中
	UpdateData(FALSE);



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CLoginDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	//登陆功能

	UpdateData(TRUE); //拿到最新的数据

	//检测数据有效性  
	if (m_user.IsEmpty() || m_pwd.IsEmpty())
	{
		MessageBox(TEXT("输入的内容不能为空"));
		return;
	}

	CInfoFile file;
	CString name;
	CString pwd;
	file.ReadLogin(name, pwd);

	if (name == m_user)
	{
		if (pwd  == m_pwd)
		{
			//关闭当前对话框
			CDialogEx::OnCancel();
		}
		else
		{
			MessageBox(TEXT("输入的密码有误！"));
		}
	}
	else
	{
		MessageBox(TEXT("输入的用户名有误！"));
		return;
	}



}


void CLoginDlg::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CLoginDlg::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//CDialogEx::OnClose();
	//退出程序
	exit(0);

}


void CLoginDlg::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类

	//CDialogEx::OnCancel();
}


void CLoginDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	//退出按钮实现
	exit(0);
}
