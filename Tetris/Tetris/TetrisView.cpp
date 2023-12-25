
// TetrisView.cpp : implementation of the CTetrisView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Tetris.h"
#endif

#include "TetrisDoc.h"
#include "TetrisView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CHcn.h"
#include "CHcnmau.h"
#include "CQuanco.h"
#include "CQuancoT.h"
#include "CQuancoI.h"
#include "CQuancoL.h"
#include "CQuancoV.h"
#include "CQuancoH1.h"
#include "CQuancoH2.h"
#include "CBanco.h"
// CTetrisView

IMPLEMENT_DYNCREATE(CTetrisView, CView)

BEGIN_MESSAGE_MAP(CTetrisView, CView)
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CTetrisView construction/destruction

CTetrisView::CTetrisView() noexcept
{
	// TODO: add construction code here
	banco = CBanco();
}

CTetrisView::~CTetrisView()
{
}

BOOL CTetrisView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTetrisView drawing

void CTetrisView::OnDraw(CDC* /*pDC*/)
{
	CTetrisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: add draw code for native data here
	CClientDC pdc(this);
	//CHcnmau  hcn = CHcnmau(0, 0, 50, 50, 225, 255,0);
	//banco.draw(&pdc);
	CQuanco* p = new CQuancoT(300, 300);

	//p->draw(&pdc);
	banco.draw(&pdc);

}


// CTetrisView diagnostics

#ifdef _DEBUG
void CTetrisView::AssertValid() const
{
	CView::AssertValid();
}

void CTetrisView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTetrisDoc* CTetrisView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTetrisDoc)));
	return (CTetrisDoc*)m_pDocument;
}
#endif //_DEBUG


// CTetrisView message handlers
UINT newThreadProc(LPVOID pParam) {
	CTetrisView* view = (CTetrisView*)pParam;
	view->playgame();
	return 1;
}

void CTetrisView::playgame()
{
	CClientDC pdc(this);
	banco.play(&pdc);
}

void CTetrisView::OnRButtonUp(UINT /*nFlags*/, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTetrisView::OnContextMenu(CWnd* /*pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
#endif // !SHARED_HANDLERS

}

void CTetrisView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	banco.start();
	CClientDC pdc(this);
	banco.draw(&pdc);
	//std::thread th4(&CBanco::play, &banco, &pdc);
	//th4.detach();
	//th4.join();
	//banco.play(&pdc);
	AfxBeginThread(newThreadProc, this);
	CView::OnRButtonDown(nFlags, point);
	
}


void CTetrisView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CClientDC pdc(this);
	// TODO: Add your message handler code here and/or call default
	if (nChar == 37) {
		//left
		banco.goLeft(&pdc);
	}
	if (nChar == 39) {
		banco.goRight(&pdc);
	}
	if (nChar == 40) {
		banco.goDown(&pdc);
	}
	if (nChar == 38) {
		banco.rotate(&pdc);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

