
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "HW1-1.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CArray<CPoint, POINT&> carray;
// CChildView
CList<CPoint, POINT&> list;

CChildView::CChildView()
{
	
	m_LButtonDown = false;
	m_RButtonDown = false;
	
	
}

CChildView::~CChildView()
{

}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
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

 

void CChildView::OnPaint()
{

	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	
	
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	SetCapture();
	m_LButtonDown = true;
	start_x = end_x = point.x;
	start_y = end_y = point.y;

	//Invalidate(FALSE);
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CWnd::OnLButtonDown(nFlags, point);
}

void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	CBrush brush(&bitmap);
	dc.SelectObject(&brush);

	//dc.SelectStockObject(NULL_BRUSH);

	dc.SetROP2(R2_COPYPEN);
	end_x = point.x;
	end_y = point.y;
	//Invalidate();

	dc.Rectangle(start_x, start_y, end_x, end_y);
	m_LButtonDown = false;

	::ReleaseCapture();
	CWnd::OnLButtonUp(nFlags, point);


}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	SetCapture();
	m_RButtonDown = true;
	start_x = end_x = point.x;
	start_y = end_y = point.y;
	//m_StartPoint = point;
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CBrush brush1(RGB(255,250,0));
	dc.SelectObject(&brush1);
	
	//dc.SelectStockObject(NULL_BRUSH);

	dc.SetROP2(R2_COPYPEN);
	end_x = point.x;
	end_y = point.y;
	//Invalidate();
	
	dc.Ellipse(start_x, start_y, end_x, end_y);
	m_RButtonDown = false;

	::ReleaseCapture();
	CWnd::OnRButtonUp(nFlags, point);

}


void CChildView::OnMButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		// RGB 매크로를 사용하여 COLORREF color 값으로 변환
	COLORREF color = RGB(0, 0, 100);
	// (100, 100)위치에 파란색을 칠함
	dc.SetPixel(point.x, point.y, color);
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CWnd::OnMButtonDown(nFlags, point);
}








void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_LButtonDown)
	{
		CClientDC dc(this);
	
		end_x = point.x;
		end_y = point.y;
	}
	if (m_RButtonDown)
	{
		CClientDC dc(this);
		//dc.SelectStockObject(NULL_BRUSH);

		//dc.SetROP2(R2_NOT);
		
		
		//dc.Rectangle(start_x, start_y, end_x, end_y);
	
		//dc.SetROP2(R2_NOT);
		end_x = point.x;
		end_y = point.y;
		
		//dc.Rectangle(start_x, start_y,end_x,end_y);
	}

	Invalidate(FALSE);
	CWnd::OnMouseMove(nFlags, point);

}




BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CWnd::OnEraseBkgnd(pDC);
	//return true;
}

