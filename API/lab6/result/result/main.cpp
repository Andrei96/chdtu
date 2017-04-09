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

//hBitMap = LoadBitmap(hInstance, szBmpImageName);

w.lpfnWndProc=WndProc; //�������� �� ������� ����

w.hCursor=LoadCursor(hInstance, szCursorName); //������������ �������

w.hIcon=LoadIcon(hInstance, szIconName); //������ ���� ����

w.lpszMenuName=0; // ���� ���� �� ����

w.hbrBackground=CreateSolidBrush(RGB(232,232,232)); //���� ���� ����

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

HDC hdc; //��������� ��������� ��������

PAINTSTRUCT ps; //��������� ���������� ��������� ���������� ���������

HBRUSH hBrush, hHatch;
HPEN hPen;
LOGFONT lf;
HFONT hFont;
RECT r, r1;


//���� ������� ����������

switch(messg)

{

//����������� ���������

case WM_PAINT :

//������� ���������

hdc=BeginPaint(hWnd, &ps);
//hdc2=BeginPaint(hWnd, &ps);
//hdc3=BeginPaint(hWnd, &ps);

//�������
// 1 ������
lf.lfHeight = 20;
lf.lfWeight = 100;
lf.lfStrikeOut = 0;
lf.lfUnderline = 0;
lf.lfEscapement = 900;
lf.lfCharSet = DEFAULT_CHARSET;
hFont = CreateFontIndirect(&lf);
SelectObject(hdc, hFont);

SetTextColor(hdc, RGB(0,0,0));
SetBkColor(hdc, RGB(232,232,232));

TextOut(hdc,160,130,"����",5);

hBrush = CreateSolidBrush(RGB(255,0,0));
hPen = CreatePen(PS_SOLID,1,RGB(0,0,0));
SelectObject(hdc, hBrush);
SelectObject(hdc, hPen);

Ellipse(hdc,50,50,150,150);
// 2 ������
TextOut(hdc,170,300,"�����������",strlen("�����������"));

hBrush = CreateSolidBrush(RGB(0,0,255));
hPen = CreatePen(PS_SOLID,2,RGB(255,101,0));
SelectObject(hdc, hPen);
SelectObject(hdc, hBrush);

r.left = 50;
r.top = 170;
r.right = 150;
r.bottom = 350;

r1.left = 50;
r1.top = 170;
r1.right = 150;
r1.bottom = 350;

SetBkColor(hdc, RGB(0,0,255));
//Rectangle(hdc,45,165,155,355);
FillRect(hdc,&r,CreateHatchBrush(HS_BDIAGONAL, RGB(0,255,0)));
FrameRect(hdc,&r1, CreateSolidBrush(RGB(255,101,0)));
// 3 ������ 
SetBkColor(hdc, RGB(232,232,232));
TextOut(hdc,500,130,"����",strlen("����"));
hBrush = CreateSolidBrush(RGB(255,255,0));
hPen = CreatePen(PS_SOLID,2,RGB(255,0,0));
SelectObject(hdc, hPen);
SelectObject(hdc, hBrush);

Ellipse(hdc,300,50,500,150);
// 4 ������ 
//SetBkColor(hdc, RGB(232,232,232));
TextOut(hdc,410,300,"����������� 2",strlen("����������� 2"));

r.left = 300;
r.top = 170;
r.right = 400;
r.bottom = 350;
FillRect(hdc,&r, CreateSolidBrush(RGB(150,0,150)));

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