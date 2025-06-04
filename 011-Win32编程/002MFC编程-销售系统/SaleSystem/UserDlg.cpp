// UserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "UserDlg.h"
#include "InfoFile.h"

// CUserDlg

IMPLEMENT_DYNCREATE(CUserDlg, CFormView)

CUserDlg::CUserDlg()
	: CFormView(CUserDlg::IDD)
	, m_user(_T(""))
	, m_name(_T(""))
	, m_newPwd(_T(""))
	, m_surePwd(_T(""))
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_newPwd);
	DDX_Text(pDX, IDC_EDIT4, m_surePwd);
}

BEGIN_MESSAGE_MAP(CUserDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON3, &CUserDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CUserDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CUserDlg 诊断

#ifdef _DEBUG
void CUserDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserDlg 消息处理程序


void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	//初始化代码
	m_user = TEXT("销售员");
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);
	m_name = name;

	UpdateData(FALSE);


	// TODO:  在此添加专用代码和/或调用基类
}


void CUserDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码

	//修改密码确定按钮

	UpdateData(TRUE);

	if (m_newPwd.IsEmpty() || m_surePwd.IsEmpty())
	{
		MessageBox(TEXT("输入的内容不能为空"));
		return;
	}

	//新密码与确定要一致
	if (m_newPwd!= m_surePwd)
	{
		MessageBox(TEXT("新密码与确定密码要一致"));
		return;
	}

	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);

	//新密码与原密码要不一样
	if (m_newPwd == pwd)
	{
		MessageBox(TEXT("新密码与原密码重复！"));
		return;
	}

	//修改密码
	//CString - > char * 
	CStringA tmpName;
	CStringA tmpPwd;
	tmpName = name;
	tmpPwd = m_newPwd;

	file.WritePwd(tmpName.GetBuffer(), tmpPwd.GetBuffer());
	MessageBox(TEXT("修改成功"));

	//清空输入内容
	m_newPwd.Empty();
	m_surePwd.Empty();

	UpdateData(FALSE);


}


void CUserDlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	//取消按钮
	//清空输入内容
	m_newPwd.Empty();
	m_surePwd.Empty();

	UpdateData(FALSE);
}
