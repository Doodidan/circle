
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
END_MESSAGE_MAP()

// создание/уничтожение CkursovayaView

CkursovayaView::CkursovayaView()
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

void CkursovayaView::OnDraw(CDC* /*pDC*/)
{
	CkursovayaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки дл€ собственных данных
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
