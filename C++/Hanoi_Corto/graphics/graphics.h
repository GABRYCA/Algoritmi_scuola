////////////////////////////////////////////////////////////////////////////////
// codice originale BCX basic originale di Sir Joe Caverly
// tradotto in C e modificato per lavorare con Dev-C++
// linkare con GDI32.lib oppure con libgdi32.a se si utilizza Dev-C++ 
// tramite Progetto>>Opzioni del progetto>>Aggiungi libreria>>lgdi32
// funziona solo sotto windows, potrebbe non funzionare con WIN 9x
// codice potenziato e riadattato a libreria da Gobetti Andrea
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// FUNZIONI IMPLEMENTATE:
//
// punto(int,int,int)
// - coordinata x del centro
// - coordinata y del centro
// - colore RGB del punto
//
// linea(int,int,int,int,int)
// - coordinata x del punto di partenza
// - coordinata y del punto di partenza
// - coordinata x del punto di arrivo
// - coordinata y del punto di arrivo
// - colore RGB della linea
//
// cerchio(int,int,int,int,bool)
// - coordinata x del centro
// - coordinata y del centro
// - raggio del cerchio
// - colore RGB del cerchio
// - true per riempire il cerchio, false per tracciarne solo il contorno
//
// ellisse(int,int,int,int,int,bool)
// - coordinata x del primo estremo laterale dell'ellisse
// - coordinata y del primo estremo laterale dell'ellisse
// - coordinata x del secondo estremo laterale dell'ellisse
// - coordinata y del secondo estremo laterale dell'ellisse
// - colore RGB dell'ellisse
// - true per riempire l'ellisse, false per tracciarne solo il contorno
//
// poligono(*tCoord,int,int,bool)
// - vettore di strutture contenente le coordinate dei punti del poligono
// - numero di vertici del poligono
// - colore RGB del poligono
// - true per riempire il poligono, false per tracciarne solo il contorno
//
// rettangolo(int,int,int,int,int,bool)
// - coordinata x del vertice del rettangolo in alto a sinistra
// - coordinata y del vertice del rettangolo in alto a sinistra
// - coordinata x del vertice del rettangolo in basso a destra
// - coordinata y del vertice del rettangolo in basso a destra
// - colore RGB del rettangolo
// - true per riempire il rettangolo, false per tracciarne solo il contorno
//
////////////////////////////////////////////////////////////////////////////////


#include <windows.h> // Win32API Header File
#include <cstring>
#include <cstdio>

using namespace std;
 
//COSTANTI COLORI///////////////////////////////////////////////////////////////
#define rosso  RGB (255,0,0)
#define arancione RGB (255,155,0)
#define giallo RGB (255,255,0)
#define lime RGB (206,255,0)
#define verde RGB (0,255,0)
#define azzurro RGB (0,156,255)
#define blu RGB (0,0,255)
#define viola RGB (174,0,255)
#define bianco RGB (255,255,255)
#define nero RGB (0,0,0)
////////////////////////////////////////////////////////////////////////////////


//TIPI//////////////////////////////////////////////////////////////////////////
typedef struct
      {int x;
      int y;
      }tCoord;
////////////////////////////////////////////////////////////////////////////////


//PROTOTIPI/////////////////////////////////////////////////////////////////////
static HWND    hConWnd;

int     punto (int,int,int);
int     linea (int,int,int,int,int);
int     cerchio (int,int,int,int,bool);
int     ellisse(int,int,int,int,int,bool);
int     poligono(tCoord*,int,int,bool);
int     rettangolo(int,int,int,int,int,bool);
 
HWND    GetConsoleWndHandle (void);
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
int linea(int x1,int y1,int x2,int y2,int Pen)
{
  int a,b=0;
  HPEN hOPen;
  HWND Wnd=GetConsoleWndHandle();
  HDC DrawHDC=0;
  // penstyle, width, color
  HPEN hNPen = CreatePen(PS_SOLID, 1, Pen);
  if (!DrawHDC) DrawHDC = GetDC(Wnd), b = 1;
  hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
  // starting point of line
  MoveToEx(DrawHDC, x1, y1, NULL);
  // ending point of line
  a = LineTo(DrawHDC, x2, y2);
  DeleteObject(SelectObject(DrawHDC, hOPen));
  if (b) ReleaseDC(Wnd, DrawHDC);
  return a;
}

int punto(int X,int Y,int Pen)
{
return linea(X,Y,X,Y,Pen);
}

////////////////////////////////////////////////////////////////////////////////
// converts circle(centerX,centerY,radius,pen) to WinApi function
// ellipse inside box with upper left and lower right coordinates
int cerchio(int X,int Y,int R,int Pen,bool Fill)
{
  HWND Wnd=GetConsoleWndHandle();
  HDC DrawHDC=0;
  int a, b = 0;
  if (!DrawHDC) DrawHDC = GetDC(Wnd), b = 1;
  // penstyle, width, color
  HPEN   hNPen = CreatePen(PS_SOLID, 2, Pen);
  HPEN   hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
  HBRUSH hOldBrush;
  HBRUSH hNewBrush;
  // if true will fill circle with pencolor
  if (Fill)
  {
    hNewBrush = CreateSolidBrush(Pen);
    hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
  }
  else
  {
    hNewBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
    hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
  }
  a = Ellipse(DrawHDC, X-R, Y+R, X+R, Y-R);
  DeleteObject(SelectObject(DrawHDC, hOPen));
  DeleteObject(SelectObject(DrawHDC, hOldBrush));
  if (b) ReleaseDC(Wnd, DrawHDC);
  return a;
}

////////////////////////////////////////////////////////////////////////////////
//funzione per ricevere l'handle della console
HWND GetConsoleWndHandle(void)
{
  HWND hConWnd;
  OSVERSIONINFO os;
  char szTempTitle[64], szClassName[128], szOriginalTitle[1024];
 
  os.dwOSVersionInfoSize = sizeof( OSVERSIONINFO );
  GetVersionEx( &os );
  // may not work on WIN9x
  if ( os.dwPlatformId == VER_PLATFORM_WIN32s ) return 0;
 
  GetConsoleTitle( szOriginalTitle, sizeof( szOriginalTitle ) );
  sprintf( szTempTitle,"%u - %u", GetTickCount(), GetCurrentProcessId() );
  SetConsoleTitle( szTempTitle );
  Sleep( 40 );
  // handle for NT
  hConWnd = FindWindow( NULL, szTempTitle );
  SetConsoleTitle( szOriginalTitle );
 
  // may not work on WIN9x
  if ( os.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS )
  {
    hConWnd = GetWindow( hConWnd, GW_CHILD );
    if ( hConWnd == NULL )  return 0;
    GetClassName( hConWnd, szClassName, sizeof ( szClassName ) );
    while ( strcmp( szClassName, "ttyGrab" ) != 0 )
    {
      hConWnd = GetNextWindow( hConWnd, GW_HWNDNEXT );
      if ( hConWnd == NULL )  return 0;
      GetClassName( hConWnd, szClassName, sizeof( szClassName ) );
    }
  }
  return hConWnd;
}

////////////////////////////////////////////////////////////////////////////////
int ellisse(int x1,int y1,int x2,int y2,int Pen,bool Fill)
{
  HWND Wnd=GetConsoleWndHandle();
  HDC DrawHDC=0;
  int a, b = 0;
  if (!DrawHDC) DrawHDC = GetDC(Wnd), b = 1;
  // penstyle, width, color
  HPEN   hNPen = CreatePen(PS_SOLID, 2, Pen);
  HPEN   hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
  HBRUSH hOldBrush;
  HBRUSH hNewBrush;
  // if true will fill circle with pencolor
  if (Fill)
  {
    hNewBrush = CreateSolidBrush(Pen);
    hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
  }
  else
  {
    hNewBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
    hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
  }
  a = Ellipse(DrawHDC, x1, y1, x2, y2);
  DeleteObject(SelectObject(DrawHDC, hOPen));
  DeleteObject(SelectObject(DrawHDC, hOldBrush));
  if (b) ReleaseDC(Wnd, DrawHDC);
  return a;
}

////////////////////////////////////////////////////////////////////////////////
int poligono(tCoord coord[], int Lati, int Pen, bool Fill)
{
  HWND Wnd=GetConsoleWndHandle();
  HDC DrawHDC=0;
  int a, b = 0;
  POINT Pt[Lati];
  
  //carico le coordinate in una struttura adeguata
  for(int i=0; i<Lati; i++)
    {Pt[i].x=coord[i].x;
    Pt[i].y=coord[i].y;
    }

  if (!DrawHDC) DrawHDC = GetDC(Wnd), b = 1;
  // penstyle, width, color
  HPEN   hNPen = CreatePen(PS_SOLID, 2, Pen);
  HPEN   hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
  HBRUSH hOldBrush;
  HBRUSH hNewBrush;
  // if true will fill circle with pencolor
  if (Fill)
  {
    hNewBrush = CreateSolidBrush(Pen);
    hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
  }
  else
  {
    hNewBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
    hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
  }
  a = Polygon(DrawHDC,Pt,Lati);
  DeleteObject(SelectObject(DrawHDC, hOPen));
  DeleteObject(SelectObject(DrawHDC, hOldBrush));
  if (b) ReleaseDC(Wnd, DrawHDC);
  return a;
}

////////////////////////////////////////////////////////////////////////////////
int rettangolo(int x1, int y1, int x2, int y2, int Pen, bool Fill)
{
  HWND Wnd=GetConsoleWndHandle();
  HDC DrawHDC=0;
  int a, b = 0;
  POINT Pt[4];
  
  //carico le coordinate in una struttura adeguata
  Pt[0].x=x1;
  Pt[0].y=y1;
  Pt[1].x=x1;
  Pt[1].y=y2;
  Pt[2].x=x2;
  Pt[2].y=y2;
  Pt[3].x=x2;
  Pt[3].y=y1;

  if (!DrawHDC) DrawHDC = GetDC(Wnd), b = 1;
  // penstyle, width, color
  HPEN   hNPen = CreatePen(PS_SOLID, 1, Pen);
  HPEN   hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
  HBRUSH hOldBrush;
  HBRUSH hNewBrush;
  // if true will fill circle with pencolor
  if (Fill)
  {
    hNewBrush = CreateSolidBrush(Pen);
    hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
  }
  else
  {
    hNewBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
    hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
  }
  a = Polygon(DrawHDC,Pt,4);
  DeleteObject(SelectObject(DrawHDC, hOPen));
  DeleteObject(SelectObject(DrawHDC, hOldBrush));
  if (b) ReleaseDC(Wnd, DrawHDC);
  return a;
}
