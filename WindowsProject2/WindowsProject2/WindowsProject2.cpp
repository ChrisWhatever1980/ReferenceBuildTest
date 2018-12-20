
// WindowsProject2.cpp: Definiert das Klassenverhalten f�r die Anwendung.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "WindowsProject2.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "WindowsProject2Doc.h"
#include "WindowsProject2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWindowsProject2App

BEGIN_MESSAGE_MAP(CWindowsProject2App, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CWindowsProject2App::OnAppAbout)
	// Dateibasierte Standarddokumentbefehle
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// Standarddruckbefehl "Seite einrichten"
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// CWindowsProject2App-Erstellung

CWindowsProject2App::CWindowsProject2App()
{
	m_bHiColorIcons = TRUE;

	// Neustart-Manager unterst�tzen
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// Wenn die Anwendung mit Common Language Runtime-Unterst�tzung (/clr) erstellt wurde:
	//     1) Diese zus�tzliche Eigenschaft ist erforderlich, damit der Neustart-Manager ordnungsgem�� unterst�tzt wird.
	//     2) F�r die Projekterstellung m�ssen Sie im Projekt einen Verweis auf System.Windows.Forms hinzuf�gen.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: Ersetzen Sie die Anwendungs-ID-Zeichenfolge unten durch eine eindeutige ID-Zeichenfolge; empfohlen
	// Das Format f�r die Zeichenfolge ist: CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("WindowsProject2.AppID.NoVersion"));

	// TODO: Hier Code zur Konstruktion einf�gen
	// Alle wichtigen Initialisierungen in InitInstance positionieren
}

// Das einzige CWindowsProject2App-Objekt

CWindowsProject2App theApp;


// CWindowsProject2App-Initialisierung

BOOL CWindowsProject2App::InitInstance()
{
	// InitCommonControlsEx() ist f�r Windows XP erforderlich, wenn ein Anwendungsmanifest
	// die Verwendung von ComCtl32.dll Version 6 oder h�her zum Aktivieren
	// von visuellen Stilen angibt. Ansonsten treten beim Erstellen von Fenstern Fehler auf.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Legen Sie dies fest, um alle allgemeinen Steuerelementklassen einzubeziehen,
	// die Sie in Ihrer Anwendung verwenden m�chten.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// OLE-Bibliotheken initialisieren
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction();

	// AfxInitRichEdit2() ist f�r die Verwendung des RichEdit-Steuerelements erforderlich.	
	// AfxInitRichEdit2();

	// Standardinitialisierung
	// Wenn Sie diese Features nicht verwenden und die Gr��e
	// der ausf�hrbaren Datei verringern m�chten, entfernen Sie
	// die nicht erforderlichen Initialisierungsroutinen.
	// �ndern Sie den Registrierungsschl�ssel, unter dem Ihre Einstellungen gespeichert sind.
	// TODO: �ndern Sie diese Zeichenfolge entsprechend,
	// z.B. zum Namen Ihrer Firma oder Organisation.
	SetRegistryKey(_T("Vom lokalen Anwendungs-Assistenten generierte Anwendungen"));
	LoadStdProfileSettings(4);  // Standard INI-Dateioptionen laden (einschlie�lich MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Dokumentvorlagen der Anwendung registrieren. Dokumentvorlagen
	//  dienen als Verbindung zwischen Dokumenten, Rahmenfenstern und Ansichten.
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_WindowsProject2TYPE,
		RUNTIME_CLASS(CWindowsProject2Doc),
		RUNTIME_CLASS(CChildFrame), // Benutzerspezifischer MDI-Child-Rahmen
		RUNTIME_CLASS(CWindowsProject2View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// Haupt-MDI-Rahmenfenster erstellen
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;
	// Rufen Sie DragAcceptFiles nur auf, wenn eine Suffix vorhanden ist.
	//  In einer MDI-Anwendung ist dies unmittelbar nach dem Festlegen von m_pMainWnd erforderlich

	// Befehlszeile auf Standardumgebungsbefehle �berpr�fen, DDE, Datei �ffnen
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Verteilung der in der Befehlszeile angegebenen Befehle. Gibt FALSE zur�ck, wenn
	// die Anwendung mit /RegServer, /Register, /Unregserver oder /Unregister gestartet wurde.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// Das Hauptfenster ist initialisiert und kann jetzt angezeigt und aktualisiert werden.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CWindowsProject2App::ExitInstance()
{
	//TODO: Zus�tzliche Ressourcen behandeln, die Sie m�glicherweise hinzugef�gt haben
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CWindowsProject2App-Meldungshandler


// CAboutDlg-Dialogfeld f�r Anwendungsbefehl "Info"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialogfelddaten
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// Anwendungsbefehl zum Ausf�hren des Dialogfelds
void CWindowsProject2App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CWindowsProject2App Methoden zum Laden/Speichern von Anpassungen

void CWindowsProject2App::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CWindowsProject2App::LoadCustomState()
{
}

void CWindowsProject2App::SaveCustomState()
{
}

// CWindowsProject2App-Meldungshandler



