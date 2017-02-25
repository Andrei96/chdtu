#include <Windows.h>

//��������� ��������� ������ ����, ��� ���� ��������� �����

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//���������� �����-��� ��������

char szProgName[] = "��� ��������";
char szBmpImageName[] = "bmpImage";
char szBmpImageName2[] = "bmpImage2";
char szBmpImageName3[] = "bmpImage3";
char szBmpImageName4[] = "bmpImage4";

HBITMAP hBitMap;
HBITMAP hBitMap2;
HBITMAP hBitMap3;

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

w.lpfnWndProc=WndProc; //�������� �� ������� ����

w.hCursor=LoadCursor(NULL, IDC_ARROW); //������������ �������

w.hIcon=0; //������ ���� ����

w.lpszMenuName=0; // ���� ���� �� ����

w.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH); //���� ���� ����

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

720, //������

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

HDC hdc, hmdc, hmdc2, hmdc3; //��������� ��������� ��������

PAINTSTRUCT ps; //��������� ���������� ��������� ���������� ���������

BITMAP bm, bm2, bm3;

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
SelectObject(hmdc, hBitMap);
SelectObject(hmdc2, hBitMap2);
SelectObject(hmdc3, hBitMap3);
GetObject(hBitMap, sizeof(bm), (LPSTR)&bm);
GetObject(hBitMap2, sizeof(bm2), (LPSTR)&bm2);
GetObject(hBitMap3, sizeof(bm3), (LPSTR)&bm3);
BitBlt(hdc, 50, 50, bm.bmWidth, bm.bmHeight, hmdc, 0,0, SRCCOPY);
BitBlt(hdc, 250, 50, bm2.bmWidth, bm2.bmHeight, hmdc2, 0,0, SRCCOPY);
BitBlt(hdc, 450, 50, bm3.bmWidth, bm3.bmHeight, hmdc3, 0,0, SRCCOPY);
DeleteDC(hmdc);


//������� ����� ������:

TextOut(hdc, 300,0, "������� ����-��� �����!", 30);

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