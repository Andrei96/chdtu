#include <Windows.h>

//��������� ��������� ������ ����, ��� ���� ��������� �����

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//���������� �����-��� ��������

char szProgName[] = "��� ��������";
char szBmpImageName[] = "bmpImage";
char szBmpImageName2[] = "bmpImage2";

HBITMAP hBitMap;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR

lpszCmdLine, int nCmdShow)

{

HWND hWnd;

MSG lpMsg;

WNDCLASS w; //��������� ���������� ��������� WNDCLASS


//���������� ���� ���������

w.lpszClassName = szProgName; //��� �������� - ���������� ����

w.hInstance=hInstance; //������������� ��������� �������

hBitMap = LoadBitmap(hInstance, szBmpImageName);
hBitMap = LoadBitmap(hInstance, szBmpImageName2);

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

100, //��������� ���� �� ����� �� �

100, // ��������� �� �

500, //������

400, //������

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

HDC hdc, hmdc; //��������� ��������� ��������

PAINTSTRUCT ps; //��������� ���������� ��������� ���������� ���������

BITMAP bm;

//���� ������� ����������

switch(messg)

{

//����������� ���������

case WM_PAINT :

//������� ���������

hdc=BeginPaint(hWnd, &ps);


hmdc = CreateCompatibleDC(hdc);
SelectObject(hmdc, hBitMap);
GetObject(hBitMap, sizeof(bm), (LPSTR)&bm);
BitBlt(hdc, 10, 10, bm.bmWidth, bm.bmHeight, hmdc, 0,0, SRCCOPY);
DeleteDC(hmdc);


//������� ����� ������:

TextOut(hdc, 150,0, "������� ����-��� �����!", 30);

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