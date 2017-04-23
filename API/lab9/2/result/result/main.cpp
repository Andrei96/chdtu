#include <Windows.h>

#define IDM_EXIT 1
#define IDM_ADMIN 2
#define IDM_GUEST 3
#define IDM_LOGIN 4
#define IDM_OPEN 5
#define IDM_COPY 6

//Створення прототипу функцї вікна, яка буде визначена нижче

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//оголошення рядка-імя програми

char szProgName[] = "Імя програми";
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

WNDCLASS w; //створення екземпляру структури WNDCLASS

hBitMap = LoadBitmap(hInstance, szBmpImageName2);


//заповнення цієї структури

w.lpszClassName = szProgName; //імя програми - ооголошено вище

w.hInstance=hInstance; //ідентифікатор поточного додатку

//hBitMap = LoadBitmap(hInstance, szBmpImageName);

w.lpfnWndProc=WndProc; //вказівник на функцію вікна

w.hCursor=LoadCursor(hInstance, szCursorName); //завантаження курсору

w.hIcon=LoadIcon(hInstance, szIconName); //іконки поки немає

w.lpszMenuName = szMenu;
//w.lpszMenuName=0; // меню поки не буде

w.hbrBackground=CreateSolidBrush(RGB(255,255,255)); //колір фону вікна

w.style=CS_HREDRAW|CS_VREDRAW; //стиль - перемалювання по х і по у

w.cbClsExtra=0;

w.cbWndExtra=0;

//Якщо не вдалося зареєструвати клас вікна – виходимо

if(!RegisterClass(&w))

return 0;


//Створення вікна в памяті, заповненням аргументів CreateWindow

hWnd=CreateWindow(szProgName, //Імя програми

"Близнюк А. О.", //Заголовок вікна

WS_OVERLAPPEDWINDOW, //Стиль вікна – таке, що перекривається

10, //положення вікна на екрані по х

10, // положення по у

900, //ширина

600, //висота

(HWND)NULL, //ідентифікатор батьківського вікна

(HMENU)NULL, // ідентифікатор меню

(HINSTANCE)hInstance, // ідентифікатор екземпляру програми

(HINSTANCE)NULL); //відсутність додаткових параметрів

//hWnd1 = CreateWindow(szProgName, "Близнюк А. О.", WS_CHILDWINDOW, 10, 10, 600,400, hWnd, (HMENU)IDM_GUEST, (HINSTANCE)hInstance,(HINSTANCE)NULL);

//Виводимо вікно з памяті на екран

ShowWindow(hWnd, nCmdShow);

//Оновлення вмісту вікна

//8

UpdateWindow(hWnd);

//Цикл обробки повідомлень

while(GetMessage(&lpMsg, hWnd, 0, 0)) { //Отримуємо повідомлення з черги

TranslateMessage(&lpMsg); //Перетворення повідомлення клавіш у символи

DispatchMessage(&lpMsg); //Передача повідомлень відповідній функції вікна

}

return(lpMsg.wParam);

}

//Функція вікна

LRESULT CALLBACK WndProc(HWND hWnd, UINT messg,

WPARAM wParam, LPARAM lParam)

{

HDC hdc, hmdc; //створення контексту пристрою
LOGFONT lf;
HFONT hFont;
PAINTSTRUCT ps; //створення екземпляру структури графічного виведення
HPEN hPen;
HBRUSH hBrush;
BITMAP bm;

int x,y;

int x1=180;
int y1=250; 
int x2=320; 
int y2=300;

//Цикл обробки повідомлень




switch(messg)
{
	
// повідомлення миші
case WM_RBUTTONDOWN:
case WM_LBUTTONDOWN: {
	hdc = GetDC(hWnd);
	x = LOWORD(lParam);
	y = HIWORD(lParam);

	if((x>x1)&&(x<x2)&&(y>y1)&&(y<y2))
	{
		MessageBox(hWnd, "Кнопка", "Button", MB_OK|MB_ICONINFORMATION);
	}
	else if((x > 600) && (y > 50) && (x < 800) && (y < 450)) {
		MessageBox(hWnd, "Фото", "Foto", MB_OK|MB_ICONINFORMATION);
	}
	else {
		MessageBox(hWnd, "Поле", "Form", MB_OK|MB_ICONINFORMATION);
	}
	
	break;
}

// повідомлення вікна
case WM_COMMAND: {
	switch(LOWORD(wParam)) {
	case IDM_EXIT: {
			MessageBox(0,"Вибране меню \"Вихід\"", "Exit", MB_ICONINFORMATION|MB_OK);
			//DestroyWindow(hWnd);
			break;
		}
	case 2: {
			MessageBox(0,"Вибране меню \"Admin\"", "Admin", MB_ICONINFORMATION|MB_OK);
			break;
		}
	case 3: {
			MessageBox(0,"Вибране меню \"User\"", "test", MB_ICONINFORMATION|MB_OK);
			break;
		}
	case 4: {
			MessageBox(0,"Вибране меню \"Login\"", "Login", MB_ICONINFORMATION|MB_OK);
			break;
		}
	case 5: {
			MessageBox(0,"Вибране меню \"Open\"", "Open", MB_ICONINFORMATION|MB_OK);
			break;
		}
	case 6: {
			MessageBox(0,"Вибране меню \"Copy\"", "Copy", MB_ICONINFORMATION|MB_OK);
			break;
		}
	default: {
		MessageBox(0,"Невідома команда", "Error", MB_ICONASTERISK|MB_OK);
		break;
		}
	}
}

//повідомлення малювання

case WM_PAINT :

//початок малювання

hdc=BeginPaint(hWnd, &ps);

//рамка для кнопки
hBrush = CreateSolidBrush(RGB(0,255,253));
SelectObject(hdc,hBrush);
RoundRect(hdc,x1,y1,x2,y2,20,20);

//текст для кнопки

// параметри шрифта
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
SetTextColor(hdc, RGB(255,0,0)); //колір тексту

SetBkMode(hdc, TRANSPARENT); //текст буде прозорий
TextOut(hdc, 225, 263,"Click", 5); //текст кнопки
// картинка
	
	hmdc=CreateCompatibleDC(hdc);
	SelectObject(hmdc, hBitMap);
	GetObject(hBitMap, sizeof(bm), (LPSTR)&bm);
	BitBlt(hdc, 600,50, bm.bmWidth, bm.bmHeight, hmdc, 0,0,SRCCOPY);
	DeleteDC(hmdc); 
	



//оновлюємо вікно

ValidateRect(hWnd, NULL);

//завершення малювання

EndPaint(hWnd, &ps);

break;

//повідомлення виходу - руйнування вікна

case WM_DESTROY:

PostQuitMessage(0); //Надсилання повідомлення виходу з кодом 0 - нормальне

//завершення

break;

default:

return(DefWindowProc(hWnd, messg, wParam, lParam)); //звільнення черги додатку

//від нерозпізнаних повідомлень

}

return 0;

}