#include <Windows.h>

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

HBITMAP hBitMap;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR

lpszCmdLine, int nCmdShow)

{

HWND hWnd;

MSG lpMsg;

WNDCLASS w; //створення екземпляру структури WNDCLASS


//заповнення цієї структури

w.lpszClassName = szProgName; //імя програми - ооголошено вище

w.hInstance=hInstance; //ідентифікатор поточного додатку

//hBitMap = LoadBitmap(hInstance, szBmpImageName);

w.lpfnWndProc=WndProc; //вказівник на функцію вікна

w.hCursor=LoadCursor(hInstance, szCursorName); //завантаження курсору

w.hIcon=LoadIcon(hInstance, szIconName); //іконки поки немає

w.lpszMenuName=0; // меню поки не буде

w.hbrBackground=CreateSolidBrush(RGB(232,232,232)); //колір фону вікна

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

920, //ширина

500, //висота

(HWND)NULL, //ідентифікатор батьківського вікна

(HMENU)NULL, // ідентифікатор меню

(HINSTANCE)hInstance, // ідентифікатор екземпляру програми

(HINSTANCE)NULL); //відсутність додаткових параметрів

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

HDC hdc; //створення контексту пристрою

PAINTSTRUCT ps; //створення екземпляру структури графічного виведення

HBRUSH hBrush, hHatch;
HPEN hPen;
LOGFONT lf;
HFONT hFont;
RECT r, r1;


//Цикл обробки повідомлень

switch(messg)

{

//повідомлення малювання

case WM_PAINT :

//початок малювання

hdc=BeginPaint(hWnd, &ps);
//hdc2=BeginPaint(hWnd, &ps);
//hdc3=BeginPaint(hWnd, &ps);

//графіка
// 1 фігура
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

TextOut(hdc,160,130,"Коло",5);

hBrush = CreateSolidBrush(RGB(255,0,0));
hPen = CreatePen(PS_SOLID,1,RGB(0,0,0));
SelectObject(hdc, hBrush);
SelectObject(hdc, hPen);

Ellipse(hdc,50,50,150,150);
// 2 фігура
TextOut(hdc,170,300,"Прямокутник",strlen("Прямокутник"));

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
// 3 фігура 
SetBkColor(hdc, RGB(232,232,232));
TextOut(hdc,500,130,"Еліпс",strlen("Еліпс"));
hBrush = CreateSolidBrush(RGB(255,255,0));
hPen = CreatePen(PS_SOLID,2,RGB(255,0,0));
SelectObject(hdc, hPen);
SelectObject(hdc, hBrush);

Ellipse(hdc,300,50,500,150);
// 4 фігура 
//SetBkColor(hdc, RGB(232,232,232));
TextOut(hdc,410,300,"Прямокутник 2",strlen("Прямокутник 2"));

r.left = 300;
r.top = 170;
r.right = 400;
r.bottom = 350;
FillRect(hdc,&r, CreateSolidBrush(RGB(150,0,150)));

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