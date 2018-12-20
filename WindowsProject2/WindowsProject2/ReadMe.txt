================================================================================
 MICROSOFT FOUNDATION CLASS-BIBLIOTHEK: WindowsProject2-Projekt�bersicht
================================================================================

Der Anwendungs-Assistent hat diese WindowsProject2-Anwendung f�r Sie 
erstellt. Diese Anwendung zeigt nicht nur die Grundlagen der Verwendung von
Microsoft Foundation Classes, sondern dient auch als Ausgangspunkt f�r das
Schreiben Ihrer Anwendung.

Diese Datei enth�lt eine Zusammenfassung dessen, was Sie in jeder der Dateien
finden, aus denen Ihre WindowsProject2�Anwendung besteht.

WindowsProject2.vcxproj
    Dies ist die Hauptprojektdatei f�r VC++-Projekte, die mithilfe eines 
    Anwendungs-Assistenten erstellt werden. 
    Sie enth�lt Informationen �ber die Version von Visual C++, in der die Datei 
    erzeugt wurde, sowie Informationen �ber die Plattformen, Konfigurationen und 
    Projektfunktionen, die mit dem Anwendungs-Assistenten ausgew�hlt wurden.

WindowsProject2.vcxproj.filters
    Dies ist die Filterdatei f�r VC++-Projekte, die mithilfe eines 
    Anwendungs-Assistenten erstellt werden. 
    Sie enth�lt Informationen �ber die Zuordnung zwischen den Dateien im 
    Projekt und den Filtern. Diese Zuordnung wird in der IDE zur Darstellung der 
    Gruppierung von Dateien mit �hnlichen Erweiterungen unter einem bestimmten 
    Knoten verwendet (z. B. sind CPP-Dateien dem Filter "Quelldateien" 
    zugeordnet).

WindowsProject2.h
    Dies ist die Hauptheaderdatei f�r die Anwendung. Sie enth�lt weitere
    projektspezifische Header (einschlie�lich "Resource.h") und deklariert
    die CWindowsProject2App-Anwendungsklasse.

WindowsProject2.cpp
    Dies ist die Hauptquelldatei der Anwendung, die die CWindowsProject2App-
    Anwendungsklasse enth�lt.

WindowsProject2.rc
    Dies ist eine Auflistung aller Microsoft Windows-Ressourcen, die das
    Programm verwendet. Sie enth�lt die Symbole, Bitmaps und Cursor, die im 
    Unterverzeichnis "RES" gespeichert werden. Diese Datei kann direkt in 
    Microsoft Visual C++ bearbeitet werden. Ihre Projektressourcen befinden sich 
    in 1031.

res\WindowsProject2.ico
    Dies ist eine Symboldatei, die als Symbol der Anwendung verwendet wird. 
    Dieses Symbol ist in der Hauptressourcendatei "WindowsProject2.rc" 
    enthalten.

res\WindowsProject2.rc2
    Diese Datei enth�lt Ressourcen, die nicht von Microsoft Visual C++
    bearbeitet werden. Sie sollten alle Ressourcen, die nicht mit dem
    Ressourcen-Editor bearbeitet werden k�nnen, in dieser Datei platzieren.

/////////////////////////////////////////////////////////////////////////////

F�r das Hauptrahmenfenster:
    Das Projekt enth�lt eine standardm��ige MFC-Schnittstelle.

MainFrm.h, MainFrm.cpp
    Diese Datei enth�lt die CMainFrame�Rahmenklasse, die von
    CMDIFrameWnd abgeleitet wird und alle MDI-Rahmenfunktionen steuert.

/////////////////////////////////////////////////////////////////////////////

F�r das untergeordnete Rahmenfenster:

"ChildFrm.h", "ChildFrm.cpp"
    Diese Dateien definieren und implementieren die CChildFrame�
    Klasse, die die untergeordneten Fenster in einer MDI-Anwendung unterst�tzt.

/////////////////////////////////////////////////////////////////////////////

Der Anwendungs-Assistent erstellt einen Dokumenttyp und eine Ansicht:

WindowsProject2Doc.h, WindowsProject2Doc.cpp � das Dokument
    Diese Dateien enthalten Ihre CWindowsProject2Doc�Klasse. Bearbeiten Sie 
    diese Dateien, um spezielle Dokumentdaten hinzuzuf�gen und Dateispeicherung
    und �ladung (�ber CWindowsProject2Doc::Serialize) zu implementieren.

WindowsProject2View.h, WindowsProject2View.cpp � die Ansicht des Dokuments
    Diese Dateien enthalten Ihre CWindowsProject2View�Klasse.
    CWindowsProject2View-Objekte werden verwendet, um CWindowsProject2Doc-
    Objekte anzuzeigen.

res\WindowsProject2Doc.ico
    Dies ist eine Symboldatei, die als Symbol f�r untergeordnete MDI-Fenster
    f�r die CWindowsProject2Doc-Klasse verwendet wird. Dieses Symbol ist in der 
    Hauptressourcendatei "WindowsProject2.rc" enthalten.




/////////////////////////////////////////////////////////////////////////////

Weitere Funktionen:

ActiveX-Steuerelemente
    Die Anwendung unterst�tzt die Verwendung von ActiveX-Steuerelementen.

Druck- und Druckvorschauunterst�tzung
    Der Anwendungs-Assistent hat Code generiert, um die Befehle f�r Drucken, 
    Druckeinrichtung und Druckvorschau zu behandeln, indem Memberfunktionen in 
    der CView-Klasse aus der MFC-Bibliothek aufgerufen werden.

/////////////////////////////////////////////////////////////////////////////

Weitere Standarddateien:

"StdAfx.h", "StdAfx.cpp"
    Diese Dateien werden verwendet, um eine vorkompilierte Headerdatei
    (PCH-Datei) mit dem Namen "WindowsProject2.pch.pch2 und eine 
    vorkompilierte Typendatei mit dem Namen "StdAfx.obj" zu erstellen.

"Resource.h"
    Dies ist die Standardheaderdatei, die neue Ressourcen-IDs definiert.
    Microsoft Visual C++ liest und aktualisiert diese Datei.

WindowsProject2.manifest
	Anwendungsmanifestdateien werden von Windows XP verwendet, um eine 
	Anwendungsabh�ngigkeit von verschiedenen Versionen paralleler Assemblys 
        zu beschreiben.
	Das Ladeprogramm verwendet diese Informationen, um die entsprechende 
	Assembly aus dem Assemblycache oder privat aus der Anwendung zu laden. Das
	Anwendungsmanifest kann zur Verteilung als externe Manifestdatei
	enthalten sein, die im gleichen Ordner installiert ist wie die ausf�hrbare 
	Datei der Anwendung, oder sie kann in Form einer Ressource in der 
	ausf�hrbaren Datei enthalten sein. 
/////////////////////////////////////////////////////////////////////////////

Weitere Hinweise:

Der Anwendungs-Assistent verwendet "TODO:", um auf Teile des Quellcodes
hinzuweisen, die Sie erg�nzen oder anpassen sollten.

Wenn Ihre Anwendung MFC in einer freigegebenen DLL verwendet, m�ssen Sie die 
MFC-DLLs verteilen. Wenn die Anwendung eine andere Sprache als die des 
Gebietsschemas des Betriebssystems verwendet, m�ssen Sie au�erdem die 
entsprechenden lokalisierten Ressourcen "MFC100XXX.DLL" verteilen. Weitere 
Informationen zu diesen beiden Themen finden Sie im Abschnitt zum Verteilen 
von Visual C++-Anwendungen in der MSDN-Dokumentation.

/////////////////////////////////////////////////////////////////////////////
