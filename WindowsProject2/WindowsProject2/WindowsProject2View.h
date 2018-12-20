
// WindowsProject2View.h: Schnittstelle der Klasse CWindowsProject2View
//

#pragma once


class CWindowsProject2View : public CView
{
protected: // Nur aus Serialisierung erstellen
	CWindowsProject2View();
	DECLARE_DYNCREATE(CWindowsProject2View)

// Attribute
public:
	CWindowsProject2Doc* GetDocument() const;

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
	virtual ~CWindowsProject2View();
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

#ifndef _DEBUG  // Debugversion in WindowsProject2View.cpp
inline CWindowsProject2Doc* CWindowsProject2View::GetDocument() const
   { return reinterpret_cast<CWindowsProject2Doc*>(m_pDocument); }
#endif

