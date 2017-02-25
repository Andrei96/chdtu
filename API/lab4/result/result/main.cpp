#include <Windows.h>

//Створення прототипу функцї вікна, яка буде визначена нижче

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//оголошення рядка-імя програми

char szProgName[] = "Імя програми";
char szBmpImageName[] = "bmpImage";
char szBmpImageName2[] = "bmpImage2";

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

hBitMap = LoadBitmap(hInstance, szBmpImageName);
hBitMap = LoadBitmap(hInstance, szBmpImageName2);

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

100, //положення вікна на екрані по х

100, // положення по у

500, //ширина

400, //висота

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

HDC hdc, hmdc; //створення контексту пристрою

PAINTSTRUCT ps; //створення екземпляру структури графічного виведення

BITMAP bm;

//Цикл обробки повідомлень

switch(messg)

{

//повідомлення малювання

case WM_PAINT :

//початок малювання

hdc=BeginPaint(hWnd, &ps);


hmdc = CreateCompatibleDC(hdc);
SelectObject(hmdc, hBitMap);
GetObject(hBitMap, sizeof(bm), (LPSTR)&bm);
BitBlt(hdc, 10, 10, bm.bmWidth, bm.bmHeight, hmdc, 0,0, SRCCOPY);
DeleteDC(hmdc);


//вставка свого тексту:

TextOut(hdc, 150,0, "Виберіть будь-яку карту!", 30);

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