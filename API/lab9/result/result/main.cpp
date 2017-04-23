#include <Windows.h>

#define IDM_EXIT 1
#define IDM_ADMIN 2
#define IDM_GUEST 3
#define IDM_LOGIN 4
#define IDM_OPEN 5
#define IDM_COPY 6

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

char szMenu[] = "MainMenu";
char szText[] = " ";
char szTextPrev[] = "";

int xPoint = 0;
int yPoint = 30;

HBITMAP hBitMap;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR

lpszCmdLine, int nCmdShow)

{

HWND hWnd, hWnd1;

MSG lpMsg;

WNDCLASS w; //��������� ���������� ��������� WNDCLASS


//���������� ���� ���������

w.lpszClassName = szProgName; //��� �������� - ���������� ����

w.hInstance=hInstance; //������������� ��������� �������

//hBitMap = LoadBitmap(hInstance, szBmpImageName);

w.lpfnWndProc=WndProc; //�������� �� ������� ����

w.hCursor=LoadCursor(hInstance, szCursorName); //������������ �������

w.hIcon=LoadIcon(hInstance, szIconName); //������ ���� ����

w.lpszMenuName = szMenu;
//w.lpszMenuName=0; // ���� ���� �� ����

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

600, //������

400, //������

(HWND)NULL, //������������� ������������ ����

(HMENU)NULL, // ������������� ����

(HINSTANCE)hInstance, // ������������� ���������� ��������

(HINSTANCE)NULL); //��������� ���������� ���������

//hWnd1 = CreateWindow(szProgName, "������� �. �.", WS_CHILDWINDOW, 10, 10, 600,400, hWnd, (HMENU)IDM_GUEST, (HINSTANCE)hInstance,(HINSTANCE)NULL);

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
HPEN hPen;
HBRUSH HBRUSH;



//���� ������� ����������

switch(messg)

{
// ����������� ����
case WM_COMMAND: {
	switch(LOWORD(wParam)) {
	case IDM_EXIT: {
			MessageBox(0,"������� ���� \"�����\"", "Exit", MB_ICONINFORMATION|MB_OK);
			//DestroyWindow(hWnd);
			break;
		}
	case 2: {
			MessageBox(0,"������� ���� \"Admin\"", "Admin", MB_ICONINFORMATION|MB_OK);
			break;
		}
	case 3: {
			MessageBox(0,"������� ���� \"User\"", "test", MB_ICONINFORMATION|MB_OK);
			break;
		}
	case 4: {
			MessageBox(0,"������� ���� \"Login\"", "Login", MB_ICONINFORMATION|MB_OK);
			break;
		}
	case 5: {
			MessageBox(0,"������� ���� \"Open\"", "Open", MB_ICONINFORMATION|MB_OK);
			break;
		}
	case 6: {
			MessageBox(0,"������� ���� \"Copy\"", "Copy", MB_ICONINFORMATION|MB_OK);
			break;
		}
	default: {
		MessageBox(0,"������� �������", "Error", MB_ICONASTERISK|MB_OK);
		break;
		}
	}
}
// ĳ� � ��������
unsigned int key;

case WM_KEYDOWN: {
	key = wParam;
	_itoa(key,szText,10);
	hdc = GetDC(hWnd);
	ShowWindow(hWnd, SW_HIDE);
	ShowWindow(hWnd, SW_SHOW);
	TextOut(hdc,10,10,szText,strlen(szText));
	//TextOut(hdc,10,10,"",strlen(""));
	
	break;
}

//����������� ���������

case WM_PAINT :

//������� ���������

hdc=BeginPaint(hWnd, &ps);
//hdc2=BeginPaint(hWnd, &ps);
//hdc3=BeginPaint(hWnd, &ps);

//����� ��� ��������� ����
/*TextOut(hdc, 50,5, "��������� �������� | Enter-����� �����, Backspace - ���������", strlen("��������� �������� | Enter-����� �����, Backspace - ���������"));


Rectangle(hdc, 10,20,570,320);
TextOut(hdc, 20,30, "_", 1);*/


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