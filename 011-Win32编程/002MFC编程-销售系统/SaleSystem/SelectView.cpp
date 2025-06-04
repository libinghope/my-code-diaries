// SelectView.cpp : 实现文件
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "SelectView.h"
#include "MainFrm.h"


// CSelectView

IMPLEMENT_DYNCREATE(CSelectView, CTreeView)

CSelectView::CSelectView()
{

}

CSelectView::~CSelectView()
{
}

BEGIN_MESSAGE_MAP(CSelectView, CTreeView)
    ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectView::OnTvnSelchanged)
END_MESSAGE_MAP()


// CSelectView 诊断

#ifdef _DEBUG
void CSelectView::AssertValid() const
{
    CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView::Dump(CDumpContext& dc) const
{
    CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView 消息处理程序


void CSelectView::OnInitialUpdate()
{
    CTreeView::OnInitialUpdate();

    // TODO:  在此添加专用代码和/或调用基类
    //初始化

    //获取树控件
    m_treeCtrl = &GetTreeCtrl();


    //创建TreeCtrl 步骤

    //1准备图片


    /*
    m_imageList.Create(30, 30, ILC_COLOR32, 1, 1);
    for(int i=0;i<ICON_NUM;i++){
        HICON icon = AfxGetApp()->LoadIconW(IDI_ICON_USER+i);
        m_imageList.Add(icon);
    }*/
    //这里可以 把ICON的ID设置为每次递增1
    //就可以一个for循环搞定了,如上，懒得去改资源文件了，复制粘贴算求了···
    HICON icon = AfxGetApp()->LoadIconW(IDI_ICON_USER);
    HICON _icon = AfxGetApp()->LoadIconW(IDI_ICON_USER2);
    HICON icon1 = AfxGetApp()->LoadIconW(IDI_ICON_SALE);
    HICON _icon1 = AfxGetApp()->LoadIconW(IDI_ICON_SALE2);
    HICON icon2 = AfxGetApp()->LoadIconW(IDI_ICON_LEFT);
    HICON _icon2 = AfxGetApp()->LoadIconW(IDI_ICON_LEFT2);

    HICON icon3 = AfxGetApp()->LoadIconW(IDI_ICON_ADD);
    HICON _icon3 = AfxGetApp()->LoadIconW(IDI_ICON_ADD3);

    HICON icon4 = AfxGetApp()->LoadIconW(IDI_ICON_DEL);
    HICON _icon4 = AfxGetApp()->LoadIconW(IDI_ICON_DEL2);

    m_imageList.Create(30, 30, ILC_COLOR32, 1, 1);
    m_imageList.Add(icon);
    m_imageList.Add(_icon);
    m_imageList.Add(icon1);
    m_imageList.Add(_icon1);
    m_imageList.Add(icon2);
    m_imageList.Add(_icon2);
    m_imageList.Add(icon3);
    m_imageList.Add(_icon3);
    m_imageList.Add(icon4);
    m_imageList.Add(_icon4);



    m_treeCtrl->SetImageList(&m_imageList, TVSIL_NORMAL);

    //2设置节点
    m_treeCtrl->InsertItem(TEXT("个人信息"), 1, 0, NULL);
    m_treeCtrl->InsertItem(TEXT("销售管理"), 3, 2, NULL);
    m_treeCtrl->InsertItem(TEXT("库存信息"), 5, 4, NULL);
    m_treeCtrl->InsertItem(TEXT("库存添加"), 7, 6, NULL);
    m_treeCtrl->InsertItem(TEXT("库存删除"), 9, 8, NULL);



}


void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    // TODO:  在此添加控件通知处理程序代码

    //获取到当前项目
    HTREEITEM item = m_treeCtrl->GetSelectedItem();

    //根据所选项目 获取里面的内容
    CString str =  m_treeCtrl->GetItemText(item);

    //MessageBox(str);
    if (str == TEXT("个人信息"))
    {
        ::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
    }
    else if (str == TEXT("销售管理"))
    {
        ::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
    }
    else if (str == TEXT("库存信息"))
    {
        ::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
    }
    else if (str == TEXT("库存添加"))
    {
        ::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
    }
    else
    {
        ::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
    }


    *pResult = 0;
}
