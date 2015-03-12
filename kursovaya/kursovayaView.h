
// kursovayaView.h : ��������� ������ CkursovayaView
//

#pragma once
#include "atltypes.h"


class CkursovayaView : public CView
{
protected: // ������� ������ �� ������������
	CkursovayaView();
	DECLARE_DYNCREATE(CkursovayaView)

// ��������
public:
	CkursovayaDoc* GetDocument() const;

// ��������
public:

// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~CkursovayaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
	CPoint new_point;
	CPoint current_point;
	CPoint end_point;
	float cpointx, cpointy;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnFunctionCircle();
};

#ifndef _DEBUG  // ���������� ������ � kursovayaView.cpp
inline CkursovayaDoc* CkursovayaView::GetDocument() const
   { return reinterpret_cast<CkursovayaDoc*>(m_pDocument); }
#endif

