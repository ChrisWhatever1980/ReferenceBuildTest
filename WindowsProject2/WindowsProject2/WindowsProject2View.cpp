
// WindowsProject2View.cpp: Implementierung der Klasse CWindowsProject2View
//

#include "stdafx.h"
// SHARED_HANDLERS können in einem ATL-Projekt definiert werden, in dem Vorschau-, Miniaturansichts- 
// und Suchfilterhandler implementiert werden, und die Freigabe von Dokumentcode für das Projekt wird ermöglicht.
#ifndef SHARED_HANDLERS
#include "WindowsProject2.h"
#endif

#include "WindowsProject2Doc.h"
#include "WindowsProject2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWindowsProject2View

IMPLEMENT_DYNCREATE(CWindowsProject2View, CView)

BEGIN_MESSAGE_MAP(CWindowsProject2View, CView)
	// Standarddruckbefehle
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CWindowsProject2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CWindowsProject2View-Erstellung/Zerstörung

CWindowsProject2View::CWindowsProject2View()
{
	// TODO: Hier Code zur Konstruktion einfügen

}

CWindowsProject2View::~CWindowsProject2View()
{
}

BOOL CWindowsProject2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Ändern Sie hier die Fensterklasse oder die Darstellung, indem Sie
	//  CREATESTRUCT cs modifizieren.

	return CView::PreCreateWindow(cs);
}

// CWindowsProject2View-Zeichnung

void CWindowsProject2View::OnDraw(CDC* /*pDC*/)
{
	CWindowsProject2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: Code zum Zeichnen der systemeigenen Daten hinzufügen
}


// CWindowsProject2View drucken


void CWindowsProject2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CWindowsProject2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Standardvorbereitung
	return DoPreparePrinting(pInfo);
}

void CWindowsProject2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: Zusätzliche Initialisierung vor dem Drucken hier einfügen
}

void CWindowsProject2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: Bereinigung nach dem Drucken einfügen
}

void CWindowsProject2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CWindowsProject2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CWindowsProject2View-Diagnose

#ifdef _DEBUG
void CWindowsProject2View::AssertValid() const
{
	CView::AssertValid();
}

void CWindowsProject2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWindowsProject2Doc* CWindowsProject2View::GetDocument() const // Nichtdebugversion ist inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWindowsProject2Doc)));
	return (CWindowsProject2Doc*)m_pDocument;
}
#endif //_DEBUG


// CWindowsProject2View-Meldungshandler
