// SellDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "SellDlg.h"
#include "InfoFile.h"


// CSellDlg

IMPLEMENT_DYNCREATE(CSellDlg, CFormView)

CSellDlg::CSellDlg()
	: CFormView(CSellDlg::IDD)
	, m_left(0)
	, m_price(0)
	, m_num(0)
	, m_sellInfo(_T(""))
{

}

CSellDlg::~CSellDlg()
{
}

void CSellDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_left);
	DDX_Text(pDX, IDC_EDIT2, m_price);
	DDX_Text(pDX, IDC_EDIT3, m_num);
	DDX_Text(pDX, IDC_EDIT4, m_sellInfo);
}

BEGIN_MESSAGE_MAP(CSellDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSellDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON3, &CSellDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CSellDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CSellDlg 诊断

#ifdef _DEBUG
void CSellDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSellDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSellDlg 消息处理程序


void CSellDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	//初始化销售管理界面
	//初始化下拉框
	CInfoFile file;
	file.ReadDocline();

	 // file.ls 容器里包含了所以商品
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{

		m_combo.AddString( CString(it->name.c_str()));
	}

	//设置默认值
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();
	

	// TODO:  在此添加专用代码和/或调用基类
}


void CSellDlg::OnCbnSelchangeCombo1()
{
	// TODO:  在此添加控件通知处理程序代码
	//商品切换 触发事件

	//获取当前索引值
	int index = m_combo.GetCurSel();
	CString str;
	m_combo.GetLBText(index, str);

	//根据商品名称 获取这个商品的库存和单价，显示到窗口中
	CInfoFile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (CString(it->name.c_str()) == str)
		{
			m_left = it->num;
			m_price = it->price;
			UpdateData(FALSE);
		}		
	}


}


void CSellDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	//购买商品 按钮点击

	UpdateData(TRUE);

	if (m_num <= 0)
	{
		MessageBox(TEXT("购买个数大于0"));
		return;
	}

	//不能大于库存量
	if (m_left < m_num)
	{
		MessageBox(TEXT("购买个数不能大于库存量"));
		return;
	}

	//购买功能
	int index = m_combo.GetCurSel();
	CString str;
	m_combo.GetLBText(index, str);
	//str是购买的商品名称

	CInfoFile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (CString(it->name.c_str()) == str)
		{
			it->num -= m_num;
			m_left = it->num;
			//右侧信息提示 TEXT ==== _T
			CString info;
			info.Format(TEXT("商品：%s \r\n单价：%d \r\n个数：%d \r\n总价：%d"), str, m_price, m_num, m_price*m_num);
			m_sellInfo = info;
			//下次再买 从0开始
			m_num = 0;

			UpdateData(FALSE);
			MessageBox(TEXT("购买成功"));
		}
	}

	//显示内容情况
	m_sellInfo.Empty();

	//将数据写到文件中
	file.WirteDocline();

	UpdateData(FALSE);

}


void CSellDlg::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	//取消按钮
	m_num = 0;
	UpdateData(FALSE);

	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();

}
