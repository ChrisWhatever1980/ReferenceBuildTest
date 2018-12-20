
// WindowsProject1View.cpp: Implementierung der Klasse CWindowsProject1View
//

#include "stdafx.h"
// SHARED_HANDLERS können in einem ATL-Projekt definiert werden, in dem Vorschau-, Miniaturansichts- 
// und Suchfilterhandler implementiert werden, und die Freigabe von Dokumentcode für das Projekt wird ermöglicht.
#ifndef SHARED_HANDLERS
#include "WindowsProject1.h"
#endif

#include "WindowsProject1Doc.h"
#include "WindowsProject1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWindowsProject1View

IMPLEMENT_DYNCREATE(CWindowsProject1View, CView)

BEGIN_MESSAGE_MAP(CWindowsProject1View, CView)
	// Standarddruckbefehle
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CWindowsProject1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CWindowsProject1View-Erstellung/Zerstörung

CWindowsProject1View::CWindowsProject1View()
{
	// TODO: Hier Code zur Konstruktion einfügen

}

CWindowsProject1View::~CWindowsProject1View()
{
}

BOOL CWindowsProject1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Ändern Sie hier die Fensterklasse oder die Darstellung, indem Sie
	//  CREATESTRUCT cs modifizieren.

	return CView::PreCreateWindow(cs);
}

// CWindowsProject1View-Zeichnung

void CWindowsProject1View::OnDraw(CDC* /*pDC*/)
{
	CWindowsProject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: Code zum Zeichnen der systemeigenen Daten hinzufügen
}


// CWindowsProject1View drucken


void CWindowsProject1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CWindowsProject1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Standardvorbereitung
	return DoPreparePrinting(pInfo);
}

void CWindowsProject1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: Zusätzliche Initialisierung vor dem Drucken hier einfügen
}

void CWindowsProject1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: Bereinigung nach dem Drucken einfügen
}

void CWindowsProject1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CWindowsProject1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CWindowsProject1View-Diagnose

#ifdef _DEBUG
void CWindowsProject1View::AssertValid() const
{
	CView::AssertValid();
}

void CWindowsProject1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWindowsProject1Doc* CWindowsProject1View::GetDocument() const // Nichtdebugversion ist inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWindowsProject1Doc)));
	return (CWindowsProject1Doc*)m_pDocument;
}
#endif //_DEBUG


// CWindowsProject1View-Meldungshandler
