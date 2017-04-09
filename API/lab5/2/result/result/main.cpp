#include <Windows.h>

//��������� ��������� ������ ����, ��� ���� ��������� �����

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//���������� �����-��� ��������

char szProgName[] = "��� ��������";
char szBmpImageName[] = "bmpImage";
char szBmpImageName2[] = "bmpImage2";
char szBmpImageName3[] = "bmpImage3";
char szBmpImageName4[] = "bmpImage4";
char szBmpImageName5[] = "bmpImage4";
char szIconName[] = "ICON1";
char szCursorName[] = "CURSOR1";
char titleName[] = "������� ����-��� �����!";

HBITMAP hBitMap;
HBITMAP hBitMap2;
HBITMAP hBitMap3;
HBITMAP hBitMap4;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR

lpszCmdLine, int nCmdShow)

{

HWND hWnd;

MSG lpMsg;

WNDCLASS w; //��������� ���������� ��������� WNDCLASS


//���������� ���� ���������

w.lpszClassName = szProgName; //��� �������� - ���������� ����

w.hInstance=hInstance; //������������� ��������� �������

//hBitMap = LoadBitmap(hInstance, szBmpImageName);
hBitMap = LoadBitmap(hInstance, szBmpImageName2);
hBitMap2 = LoadBitmap(hInstance, szBmpImageName3);
hBitMap3 = LoadBitmap(hInstance, szBmpImageName4);
hBitMap4 = LoadBitmap(hInstance, szBmpImageName5);

w.lpfnWndProc=WndProc; //�������� �� ������� ����

w.hCursor=LoadCursor(hInstance, szCursorName); //������������ �������

w.hIcon=LoadIcon(hInstance, szIconName); //������ ���� ����

w.lpszMenuName=0; // ���� ���� �� ����

w.hbrBackground=CreateSolidBrush(RGB(255,255,255)); //���� ���� ����

w.style=CS_HREDRAW|CS_VREDRAW; //����� - ������������� �� � � �� �

w.cbClsExtra=0;

w.cbWndExtra=0;

//���� �� ������� ������������ ���� ���� � ��������

if(!RegisterClass(&w))

return 0;


//��������� ���� � �����, ����������� ��������� CreateWindow

hWnd=CreateWindow(szProgName, //��� ��������

"������� �. �.", //��������� ����

WS_OVERLAPPEDWINDOW, //����� ���� � ����, �� �������������

10, //��������� ���� �� ����� �� �

10, // ��������� �� �

920, //������

500, //������

(HWND)NULL, //������������� ������������ ����

(HMENU)NULL, // ������������� ����

(HINSTANCE)hInstance, // ������������� ���������� ��������

(HINSTANCE)NULL); //��������� ���������� ���������

//�������� ���� � ����� �� �����

ShowWindow(hWnd, nCmdShow);

//��������� ����� ����

//8

UpdateWindow(hWnd);

//���� ������� ����������

while(GetMessage(&lpMsg, hWnd, 0, 0)) { //�������� ����������� � �����

TranslateMessage(&lpMsg); //������������ ����������� ����� � �������

DispatchMessage(&lpMsg); //�������� ���������� �������� ������� ����

}

return(lpMsg.wParam);

}

//������� ����

LRESULT CALLBACK WndProc(HWND hWnd, UINT messg,

WPARAM wParam, LPARAM lParam)

{

HDC hdc, hmdc, hmdc2, hmdc3, hmdc4; //��������� ��������� ��������

PAINTSTRUCT ps; //��������� ���������� ��������� ���������� ���������

BITMAP bm, bm2, bm3, bm4;

//���� ������� ����������

switch(messg)

{

//����������� ���������

case WM_PAINT :

//������� ���������

hdc=BeginPaint(hWnd, &ps);
//hdc2=BeginPaint(hWnd, &ps);
//hdc3=BeginPaint(hWnd, &ps);


hmdc = CreateCompatibleDC(hdc);
hmdc2 = CreateCompatibleDC(hdc);
hmdc3 = CreateCompatibleDC(hdc);
hmdc4 = CreateCompatibleDC(hdc);
SelectObject(hmdc, hBitMap);
SelectObject(hmdc2, hBitMap2);
SelectObject(hmdc3, hBitMap3);
SelectObject(hmdc4, hBitMap4);
GetObject(hBitMap, sizeof(bm), (LPSTR)&bm);
GetObject(hBitMap2, sizeof(bm2), (LPSTR)&bm2);
GetObject(hBitMap3, sizeof(bm3), (LPSTR)&bm3);
GetObject(hBitMap3, sizeof(bm4), (LPSTR)&bm4);
BitBlt(hdc, 50, 50, bm.bmWidth, bm.bmHeight, hmdc, 0,0, SRCCOPY);
BitBlt(hdc, 250, 50, bm2.bmWidth, bm2.bmHeight, hmdc2, 0,0, SRCCOPY);
BitBlt(hdc, 450, 50, bm3.bmWidth, bm3.bmHeight, hmdc3, 0,0, SRCINVERT);
BitBlt(hdc, 650, 50, bm4.bmWidth, bm4.bmHeight, hmdc4, 0,0, SRCCOPY);
DeleteDC(hmdc);
DeleteDC(hmdc2);
DeleteDC(hmdc3);
DeleteDC(hmdc4);




//������� ����� ������:

TextOut(hdc, 350,0, titleName, strlen(titleName));

// ������� �����

LOGFONT lf;
HFONT hFont;

strcpy(lf.lfFaceName,"Times New Roman"); 
lf.lfHeight=50;
lf.lfItalic=1;
lf.lfStrikeOut=0;
lf.lfUnderline=0;
lf.lfWidth=10;
lf.lfWeight=40;
lf.lfCharSet=DEFAULT_CHARSET; 
lf.lfPitchAndFamily=DEFAULT_PITCH; 
lf.lfEscapement=0;

hFont = CreateFontIndirect(&lf);
SelectObject(hdc, hFont);

TextOut(hdc, 100,30, "5 ������", strlen("5 ������"));

strcpy(lf.lfFaceName,"Roboto"); 
lf.lfHeight=20;
lf.lfItalic=0;
lf.lfUnderline=1;
lf.lfWidth= 20;
lf.lfWeight= 40;

hFont = CreateFontIndirect(&lf);
SelectObject(hdc, hFont);
//SetBkMode(hdc, TRANSPARENT);

TextOut(hdc, 300,30, "2 ����", strlen("2 ����"));

strcpy(lf.lfFaceName,"Arial"); 
lf.lfStrikeOut=1;
lf.lfWidth= 10;
lf.lfWeight= 50;

hFont = CreateFontIndirect(&lf);
SelectObject(hdc, hFont);
//SetBkColor(hdc, TRANSPARENT);

TextOut(hdc, 480,300, "10 ��� �������", strlen("10 ��� �������"));

strcpy(lf.lfFaceName,"Compact"); 
lf.lfHeight=10;
lf.lfUnderline=0;
lf.lfEscapement= 100;

hFont = CreateFontIndirect(&lf);
SelectObject(hdc, hFont);
SetTextColor(hdc, RGB(255,0,0));

TextOut(hdc, 650,30, "10 ��� �� �������", strlen("10 ��� �� �������"));

strcpy(lf.lfFaceName,"Courier New");
lf.lfHeight = 50;
lf.lfStrikeOut = 0;
lf.lfWidth = 30;
lf.lfEscapement = 900;

hFont = CreateFontIndirect(&lf);
SelectObject(hdc, hFont);
SetBkColor(NULL, TRANSPARENT);
SetTextColor(hdc, RGB(0,0,255));

TextOut(hdc, 0,350, "������� �.", strlen("������� �."));

//��������� ����

ValidateRect(hWnd, NULL);

//���������� ���������

EndPaint(hWnd, &ps);

break;

//����������� ������ - ���������� ����

case WM_DESTROY:

PostQuitMessage(0); //���������� ����������� ������ � ����� 0 - ���������

//����������

break;

default:

return(DefWindowProc(hWnd, messg, wParam, lParam)); //��������� ����� �������

//�� ������������ ����������

}

return 0;

}