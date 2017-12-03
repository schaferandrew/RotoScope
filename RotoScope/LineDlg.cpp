// LineDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RotoScope.h"
#include "LineDlg.h"
#include "afxdialogex.h"


// CLineDlg dialog

IMPLEMENT_DYNAMIC(CLineDlg, CDialog)

CLineDlg::CLineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_LINEDLG, pParent)
	, m_x1(0)
	, m_y1(0)
	, m_x2(0)
	, m_y2(0)
	, m_b(0)
	, m_g(0)
	, m_r(0)
	, m_width(0)
{

}

CLineDlg::~CLineDlg()
{
}

void CLineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_X1, m_x1);
	DDX_Text(pDX, IDC_Y1, m_y1);
	DDX_Text(pDX, IDC_X2, m_x2);
	DDX_Text(pDX, IDC_Y2, m_y2);
	DDX_Text(pDX, IDC_B, m_b);
	DDV_MinMaxInt(pDX, m_b, 0, 255);
	DDX_Text(pDX, IDC_G, m_g);
	DDV_MinMaxInt(pDX, m_g, 0, 255);
	DDX_Text(pDX, IDC_R, m_r);
	DDV_MinMaxInt(pDX, m_r, 0, 255);
	DDX_Text(pDX, IDC_W, m_width);
}


BEGIN_MESSAGE_MAP(CLineDlg, CDialog)
END_MESSAGE_MAP()


// CLineDlg message handlers
