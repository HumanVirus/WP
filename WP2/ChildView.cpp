﻿
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "WP2.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_pt=CPoint(100,100);
	m_color = RGB(255, 0, 0);
	m_dy = 10;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_CREATE()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}
void SetTimer(int id, int time, void* fp);

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.

	m_color = RGB(rand() % 256, rand() % 256, rand() % 256);

	dc.Ellipse(m_pt.x,m_pt.y,m_pt.x+50,m_pt.y+50);
	
}



void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == 0)
	{
		// 주기 마다 해 줘야 할 일
		CRect rect;
		GetClientRect(&rect);
		if (m_pt.y + 50 > rect.bottom)
			m_dy = -m_dy;
		if (m_pt.y < 0)
			m_dy = -m_dy;

		m_pt.y += m_dy;
		//m_pt.y += 10;
		Invalidate();
	}
	if (nIDEvent == 1)
	{
		m_color = RGB(rand() % 256, rand() % 256, rand() % 256);
		Invalidate();
	}
	CWnd::OnTimer(nIDEvent);
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetTimer(0, 33, NULL);// 주기 마다 해 줘야 할 일

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}
