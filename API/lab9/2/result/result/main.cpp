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
char szTextMouse[] = "Mouse click action";

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

hBitMap = LoadBitmap(hInstance, szBmpImageName2);


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

900, //������

600, //������

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

HDC hdc, hmdc; //��������� ��������� ��������
LOGFONT lf;
HFONT hFont;
PAINTSTRUCT ps; //��������� ���������� ��������� ���������� ���������
HPEN hPen;
HBRUSH hBrush;
BITMAP bm;

int x,y;

int x1=180;
int y1=250; 
int x2=320; 
int y2=300;

//���� ������� ����������




switch(messg)
{
	
// ����������� ����
case WM_RBUTTONDOWN:
case WM_LBUTTONDOWN: {
	hdc = GetDC(hWnd);
	x = LOWORD(lParam);
	y = HIWORD(lParam);

	if((x>x1)&&(x<x2)&&(y>y1)&&(y<y2))
	{
		MessageBox(hWnd, "������", "Button", MB_OK|MB_ICONINFORMATION);
	}
	else if((x > 600) && (y > 50) && (x < 800) && (y < 450)) {
		MessageBox(hWnd, "����", "Foto", MB_OK|MB_ICONINFORMATION);
	}
	else {
		MessageBox(hWnd, "����", "Form", MB_OK|MB_ICONINFORMATION);
	}
	
	break;
}

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

//����������� ���������

case WM_PAINT :

//������� ���������

hdc=BeginPaint(hWnd, &ps);

//����� ��� ������
hBrush = CreateSolidBrush(RGB(0,255,253));
SelectObject(hdc,hBrush);
RoundRect(hdc,x1,y1,x2,y2,20,20);

//����� ��� ������

// ��������� ������
lf.lfCharSet=DEFAULT_CHARSET;
lf.lfPitchAndFamily=DEFAULT_PITCH;
strcpy(lf.lfFaceName,"Compact");  
lf.lfHeight=20; 
lf.lfWidth=10; 
lf.lfWeight=FW_BOLD; 
lf.lfEscapement=0;
lf.lfStrikeOut=0; 
lf.lfUnderline=0; 

hFont=CreateFontIndirect(&lf); 
SelectObject(hdc, hFont); 
SetTextColor(hdc, RGB(255,0,0)); //���� ������

SetBkMode(hdc, TRANSPARENT); //����� ���� ��������
TextOut(hdc, 225, 263,"Click", 5); //����� ������
// ��������
	
	hmdc=CreateCompatibleDC(hdc);
	SelectObject(hmdc, hBitMap);
	GetObject(hBitMap, sizeof(bm), (LPSTR)&bm);
	BitBlt(hdc, 600,50, bm.bmWidth, bm.bmHeight, hmdc, 0,0,SRCCOPY);
	DeleteDC(hmdc); 
	



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