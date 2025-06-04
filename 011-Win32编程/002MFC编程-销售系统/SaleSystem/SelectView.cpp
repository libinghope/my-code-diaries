// SelectView.cpp : ʵ���ļ�
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


// CSelectView ���

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


// CSelectView ��Ϣ�������


void CSelectView::OnInitialUpdate()
{
    CTreeView::OnInitialUpdate();

    // TODO:  �ڴ����ר�ô����/����û���
    //��ʼ��

    //��ȡ���ؼ�
    m_treeCtrl = &GetTreeCtrl();


    //����TreeCtrl ����

    //1׼��ͼƬ


    /*
    m_imageList.Create(30, 30, ILC_COLOR32, 1, 1);
    for(int i=0;i<ICON_NUM;i++){
        HICON icon = AfxGetApp()->LoadIconW(IDI_ICON_USER+i);
        m_imageList.Add(icon);
    }*/
    //������� ��ICON��ID����Ϊÿ�ε���1
    //�Ϳ���һ��forѭ���㶨��,���ϣ�����ȥ����Դ�ļ��ˣ�����ճ�������ˡ�����
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

    //2���ýڵ�
    m_treeCtrl->InsertItem(TEXT("������Ϣ"), 1, 0, NULL);
    m_treeCtrl->InsertItem(TEXT("���۹���"), 3, 2, NULL);
    m_treeCtrl->InsertItem(TEXT("�����Ϣ"), 5, 4, NULL);
    m_treeCtrl->InsertItem(TEXT("������"), 7, 6, NULL);
    m_treeCtrl->InsertItem(TEXT("���ɾ��"), 9, 8, NULL);



}


void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    // TODO:  �ڴ���ӿؼ�֪ͨ����������

    //��ȡ����ǰ��Ŀ
    HTREEITEM item = m_treeCtrl->GetSelectedItem();

    //������ѡ��Ŀ ��ȡ���������
    CString str =  m_treeCtrl->GetItemText(item);

    //MessageBox(str);
    if (str == TEXT("������Ϣ"))
    {
        ::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
    }
    else if (str == TEXT("���۹���"))
    {
        ::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
    }
    else if (str == TEXT("�����Ϣ"))
    {
        ::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
    }
    else if (str == TEXT("������"))
    {
        ::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
    }
    else
    {
        ::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
    }


    *pResult = 0;
}
