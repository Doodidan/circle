
// kursovayaView.h : интерфейс класса CkursovayaView
//

#pragma once


class CkursovayaView : public CView
{
protected: // создать только из сериализации
	CkursovayaView();
	DECLARE_DYNCREATE(CkursovayaView)

// Атрибуты
public:
	CkursovayaDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CkursovayaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // отладочная версия в kursovayaView.cpp
inline CkursovayaDoc* CkursovayaView::GetDocument() const
   { return reinterpret_cast<CkursovayaDoc*>(m_pDocument); }
#endif

