
// kursovayaView.cpp : реализаци€ класса CkursovayaView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позвол€ет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "kursovaya.h"
#endif

#include "kursovayaDoc.h"
#include "kursovayaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CkursovayaView

IMPLEMENT_DYNCREATE(CkursovayaView, CView)

BEGIN_MESSAGE_MAP(CkursovayaView, CView)
	// —тандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CkursovayaView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_COMMAND(ID_FUNCTION_CIRCLE, &CkursovayaView::OnFunctionCircle)
END_MESSAGE_MAP()

// создание/уничтожение CkursovayaView

CkursovayaView::CkursovayaView()
	: new_point(0)
	, current_point(0)
	, end_point(0)
{
	// TODO: добавьте код создани€

}

CkursovayaView::~CkursovayaView()
{
}

BOOL CkursovayaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CkursovayaView

void CkursovayaView::OnDraw(CDC* pDC)
{
	CPen myPen;
	CPen *myOldPen;
	myPen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	myOldPen = pDC->SelectObject(&myPen);
	CBrush myBrush;
	CBrush *myOldBrush;
	myBrush.CreateSolidBrush(RGB(255, 0, 0));
	myOldBrush = pDC->SelectObject(&myBrush);
	pDC->Ellipse(current_point.x, current_point.y, current_point.x - 10, current_point.y - 10);
}


// печать CkursovayaView


void CkursovayaView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CkursovayaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CkursovayaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CkursovayaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CkursovayaView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CkursovayaView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// диагностика CkursovayaView

#ifdef _DEBUG
void CkursovayaView::AssertValid() const
{
	CView::AssertValid();
}

void CkursovayaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CkursovayaDoc* CkursovayaView::GetDocument() const // встроена неотлаженна€ верси€
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CkursovayaDoc)));
	return (CkursovayaDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CkursovayaView


void CkursovayaView::OnLButtonDown(UINT nFlags, CPoint point)
{
	end_point.x = point.x;
	end_point.y = point.y;
	new_point.x = current_point.x;
	new_point.y = current_point.y;
	SetTimer(1, 40, NULL);
}


void CkursovayaView::OnTimer(UINT_PTR nIDEvent)
{
	if (
		(50 * abs(end_point.x - current_point.x) > abs(end_point.x - new_point.x))
		&&
		(50 * abs((end_point.y - current_point.y) > abs(end_point.y - new_point.y)))
	) {
		cpointx += (float)(end_point.x - new_point.x) / 50;
		cpointy += (float)(end_point.y - new_point.y) / 50;
		current_point.x = (int)cpointx;
		current_point.y = cpointy;
		GetDocument()->UpdateAllViews(NULL);
	}
}


void CkursovayaView::OnFunctionCircle()
{
	current_point.x = cpointx = 100;
	current_point.y = cpointy = 100;
	GetDocument()->UpdateAllViews(NULL);
}
