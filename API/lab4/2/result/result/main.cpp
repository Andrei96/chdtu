#include <Windows.h>

//Створення прототипу функцї вікна, яка буде визначена нижче

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//оголошення рядка-імя програми

char szProgName[] = "Імя програми";
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

WNDCLASS w; //створення екземпляру структури WNDCLASS


//заповнення цієї структури

w.lpszClassName = szProgName; //імя програми - ооголошено вище

w.hInstance=hInstance; //ідентифікатор поточного додатку

//hBitMap = LoadBitmap(hInstance, szBmpImageName);
hBitMap = LoadBitmap(hInstance, szBmpImageName2);
hBitMap2 = LoadBitmap(hInstance, szBmpImageName3);
hBitMap3 = LoadBitmap(hInstance, szBmpImageName4);

w.lpfnWndProc=WndProc; //вказівник на функцію вікна

w.hCursor=LoadCursor(NULL, IDC_ARROW); //завантаження курсору

w.hIcon=0; //іконки поки немає

w.lpszMenuName=0; // меню поки не буде

w.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH); //колір фону вікна

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

720, //ширина

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

HDC hdc, hmdc, hmdc2, hmdc3; //створення контексту пристрою

PAINTSTRUCT ps; //створення екземпляру структури графічного виведення

BITMAP bm, bm2, bm3;

//Цикл обробки повідомлень

switch(messg)

{

//повідомлення малювання

case WM_PAINT :

//початок малювання

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


//вставка свого тексту:

TextOut(hdc, 300,0, "Виберіть будь-яку карту!", 30);

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