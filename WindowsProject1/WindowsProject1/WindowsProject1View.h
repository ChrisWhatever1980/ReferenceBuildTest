
// WindowsProject1View.h: Schnittstelle der Klasse CWindowsProject1View
//

#pragma once


class CWindowsProject1View : public CView
{
protected: // Nur aus Serialisierung erstellen
	CWindowsProject1View();
	DECLARE_DYNCREATE(CWindowsProject1View)

// Attribute
public:
	CWindowsProject1Doc* GetDocument() const;

// Vorgänge
public:

// Überschreibungen
public:
	virtual void OnDraw(CDC* pDC);  // Überschrieben, um diese Ansicht darzustellen
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementierung
public:
	virtual ~CWindowsProject1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Funktionen für die Meldungstabellen
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Debugversion in WindowsProject1View.cpp
inline CWindowsProject1Doc* CWindowsProject1View::GetDocument() const
   { return reinterpret_cast<CWindowsProject1Doc*>(m_pDocument); }
#endif

