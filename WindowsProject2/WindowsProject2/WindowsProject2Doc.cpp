
// WindowsProject2Doc.cpp: Implementierung der Klasse CWindowsProject2Doc
//

#include "stdafx.h"
// SHARED_HANDLERS k�nnen in einem ATL-Projekt definiert werden, in dem Vorschau-, Miniaturansichts- 
// und Suchfilterhandler implementiert werden, und die Freigabe von Dokumentcode f�r das Projekt wird erm�glicht.
#ifndef SHARED_HANDLERS
#include "WindowsProject2.h"
#endif

#include "WindowsProject2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CWindowsProject2Doc

IMPLEMENT_DYNCREATE(CWindowsProject2Doc, CDocument)

BEGIN_MESSAGE_MAP(CWindowsProject2Doc, CDocument)
END_MESSAGE_MAP()


// CWindowsProject2Doc-Erstellung/Zerst�rung

CWindowsProject2Doc::CWindowsProject2Doc()
{
	// TODO: Hier Code f�r One-Time-Konstruktion einf�gen

}

CWindowsProject2Doc::~CWindowsProject2Doc()
{
}

BOOL CWindowsProject2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: Hier Code zur Reinitialisierung einf�gen
	// (SDI-Dokumente verwenden dieses Dokument)

	return TRUE;
}




// CWindowsProject2Doc-Serialisierung

void CWindowsProject2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: Hier Code zum Speichern einf�gen
	}
	else
	{
		// TODO: Hier Code zum Laden einf�gen
	}
}

#ifdef SHARED_HANDLERS

// Unterst�tzung f�r Miniaturansichten
void CWindowsProject2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �ndern Sie diesen Code, um die Dokumentdaten zu zeichnen.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Unterst�tzung f�r Suchhandler
void CWindowsProject2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Suchinhalte aus Dokumentdaten festlegen. 
	// Die Inhaltsteile sollten durch ";" getrennt werden.

	// Beispiel:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CWindowsProject2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CWindowsProject2Doc-Diagnose

#ifdef _DEBUG
void CWindowsProject2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWindowsProject2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CWindowsProject2Doc-Befehle
