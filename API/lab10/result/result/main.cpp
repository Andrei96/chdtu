#include <Windows.h>
#include <math.h>

/*#define IDM_EXIT 1
#define IDM_ADMIN 2
#define IDM_GUEST 3
#define IDM_LOGIN 4
#define IDM_OPEN 5
#define IDM_COPY 6*/
#define IDD_SUM_ROW 10101
#define IDD_PIFAGORUS 101
#define IDD_AVARAGE_AR 102
#define IDD_AVARAGE_GE 110
/*#define IDD_PIFAGORUS 101
#define IDD_PIFAGORUS 101*/
#define IDC_STATIC 50
#define IDC_EXIT 1000
#define IDC_VALUE1 1001
#define IDC_VALUE2 1002
#define IDC_VALUE3 12
#define IDC_VALUE4 1010
#define IDC_EDIT1 1003
#define IDC_COUNT 1004
#define IDC_CLEAR 1005
#define IDM_ENTER1 1
#define IDM_ENTER2 2
#define IDM_ENTER3 3
#define IDM_ENTER4 4
#define IDM_EXIT 40003
#define IDC_EDIT2 -1
#define IDC_INSERT_V 55


//Створення прототипу функцї вікна, яка буде визначена нижче
BOOL CALLBACK FormulaFunc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AvarageFuncGE(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AvarageFunc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK PifProc(HWND, UINT, WPARAM, LPARAM);
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

//char szMenu[] = "MainMenu";
char szMenu[] = "PifagrorusMenu";
char szText[] = " ";
char szTextPrev[] = "";

int xPoint = 0;
int yPoint = 30;

HBITMAP hBitMap;
HINSTANCE hInstance;

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{

HDC hdc, hmdc; //створення контексту пристрою
PAINTSTRUCT ps; //створення екземпляру структури графічного виведення
//Цикл обробки повідомлень

switch(messg)
{

// повідомлення вікна
case WM_COMMAND: {
	switch(LOWORD(wParam)) {
		// вікно Діалог
	case IDM_ENTER1: {
		DialogBox(NULL, (LPCTSTR)IDD_PIFAGORUS, hWnd, PifProc);
		break;
	}
	case IDM_ENTER2: {
		DialogBox(NULL, (LPCTSTR)IDD_AVARAGE_AR, hWnd, AvarageFunc);
		break;
	}
	case IDM_ENTER3: {
		DialogBox(NULL, (LPCTSTR)IDD_AVARAGE_GE, hWnd, AvarageFuncGE);
		break;
	}
	case IDM_ENTER4: {
		DialogBox(NULL, (LPCTSTR)IDD_SUM_ROW, hWnd, FormulaFunc);
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

double a,b,c,d,e,f,g;
	char str[80]="Рядок тексту";

int fact(int n) {
	if(n <= 0 || (n == 1))
		return 1;
	else {
		return n * fact(n-1);
	}
}


BOOL CALLBACK PifProc(HWND hdlg, UINT messg, WPARAM wParam, LPARAM lParam)
{
	bool editSymbol1 = false, editSymbol2 = false;
	//double a,b,c;
	//char str[80]="Рядок тексту";
	switch (messg)
	{
		case WM_INITDIALOG: 
			return TRUE;

		case WM_COMMAND:
			switch(LOWORD(wParam)) {
				case IDC_COUNT: //кнопка "Рахувати"
					GetDlgItemText(hdlg,IDC_VALUE1,str,40);
					a=atof(str);
					if(str[0]!=NULL) 
						editSymbol1 = true;
					GetDlgItemText(hdlg,IDC_VALUE2,str,40);
					b=atof(str);
					if(str[0]!=NULL) 
						editSymbol2 = true;
					c=sqrt(a*a+b*b);
					gcvt(c,10,str);
					if(editSymbol1 && editSymbol2)
					MessageBox(hdlg, str, "Гіпотенуза",0);
					else 
						MessageBox(hdlg, "Заповніть поля!", "Помилка",0);

				break;
				case IDC_CLEAR: //кнопка "Очистити"
					SetDlgItemText(hdlg, IDC_VALUE1, "");
					SetDlgItemText(hdlg, IDC_VALUE2, "");
					break;

				case IDC_EXIT: // кнопка "Вихід"
					EndDialog(hdlg, LOWORD(wParam));
					return TRUE;
					break;
				}
				break;
			case WM_CLOSE:
				EndDialog(hdlg, LOWORD(wParam));
			break;

			default: return false;
			}	
}
BOOL CALLBACK AvarageFunc(HWND hdlg, UINT messg, WPARAM wParam, LPARAM lParam)
{
	
	bool editSymbol1 = false, editSymbol2 = false, editSymbol3 = false;
switch (messg)
{
case WM_INITDIALOG: 
return TRUE;

case WM_CREATE: 
	break;
case WM_COMMAND:
switch(LOWORD(wParam)) {

case IDC_COUNT: //кнопка "Рахувати"

GetDlgItemText(hdlg,IDC_VALUE1,str,40);
a=atof(str);
if(str[0]!=NULL) editSymbol1 = true;

GetDlgItemText(hdlg,IDC_VALUE2,str,40);
b=atof(str);
if(str[0]!=NULL) editSymbol2 = true;

GetDlgItemText(hdlg,IDC_VALUE3,str,40);
c=atof(str);
if(str[0]!=NULL) editSymbol3 = true;
gcvt(a,2,str);
MessageBox(hdlg, str, "a", MB_CANCELTRYCONTINUE);
gcvt(b,2,str);
MessageBox(hdlg, str, "b", MB_CANCELTRYCONTINUE);
gcvt(c,2,str);
MessageBox(hdlg, str, "c", MB_CANCELTRYCONTINUE);


d=(a+b+c)/3;
gcvt(d,10,str);
if(editSymbol1 && editSymbol2 && editSymbol3)
MessageBox(hdlg, str, "Результат",MB_ICONINFORMATION);
else MessageBox(hdlg, "Заповніть поля!", "Помилка",MB_ICONWARNING);

break;

case IDC_CLEAR: //кнопка "Очистити"
SetDlgItemText(hdlg, IDC_VALUE1, "");
SetDlgItemText(hdlg, IDC_VALUE2, "");
SetDlgItemText(hdlg, IDC_VALUE3, "");

break;

case IDC_EXIT: // кнопка "Вихід"
EndDialog(hdlg, LOWORD(wParam));
return TRUE;
break;

}
break;

case WM_CLOSE:
	EndDialog(hdlg, LOWORD(wParam));
break;

default: return false;
}
}
BOOL CALLBACK AvarageFuncGE(HWND hdlg, UINT messg, WPARAM wParam, LPARAM lParam)
{

switch (messg)
{
case WM_INITDIALOG: 
return TRUE;

case WM_CREATE: 
	break;
case WM_COMMAND:
switch(LOWORD(wParam)) {

case IDC_COUNT: //кнопка "Рахувати"

GetDlgItemText(hdlg,IDC_VALUE1,str,40);
a=atof(str);

GetDlgItemText(hdlg,IDC_VALUE2,str,40);
b=atof(str);

GetDlgItemText(hdlg,IDC_VALUE3,str,40);
c=atof(str);

GetDlgItemText(hdlg,IDC_VALUE4,str,40);
e=atof(str);

d=(a*b*c*e);
d = pow(d, 1.0/4.0);
gcvt(d,10,str);

MessageBox(hdlg, str, "Результат",MB_ICONINFORMATION);

break;

case IDC_CLEAR: //кнопка "Очистити"
SetDlgItemText(hdlg, IDC_VALUE1, "");
SetDlgItemText(hdlg, IDC_VALUE2, "");
SetDlgItemText(hdlg, IDC_VALUE3, "");
SetDlgItemText(hdlg, IDC_VALUE4, "");

break;

case IDC_EXIT: // кнопка "Вихід"
EndDialog(hdlg, LOWORD(wParam));
return TRUE;
break;

}
break;

case WM_CLOSE:
	EndDialog(hdlg, LOWORD(wParam));
break;

default: return false;
}
}
BOOL CALLBACK FormulaFunc(HWND hdlg, UINT messg, WPARAM wParam, LPARAM lParam)
{
double a1,s1, x1, i1, eps1;
switch (messg)
{
case WM_INITDIALOG: 
return TRUE;

case WM_CREATE: 
	break;
case WM_COMMAND:
switch(LOWORD(wParam)) {

case IDC_COUNT: //кнопка "Рахувати"

GetDlgItemText(hdlg,IDC_VALUE1,str,40);
a=atof(str);

GetDlgItemText(hdlg,IDC_VALUE2,str,40);
b=atof(str);

if((a != 0.25) && (b != 0.00001)) {
	MessageBox(hdlg, "Невірні дані", "Error", MB_ICONERROR);
	return false;
}

a1=1;s1=0; x1=a; i1 = 1; eps1 = b;
    while (fabs(a1)>eps1)
    {
    a1=(pow(i1,2)*pow(x1, i1) + 1)/(fact(i1) + pow(i1,2)) ;
    i1++;
    s1+=a1;
    }
	gcvt(s1,10,str);

MessageBox(hdlg, str, "Результат",MB_ICONINFORMATION);

break;

case IDC_CLEAR: //кнопка "Очистити"
SetDlgItemText(hdlg, IDC_VALUE1, "");
SetDlgItemText(hdlg, IDC_VALUE2, "");
SetDlgItemText(hdlg, IDC_VALUE3, "");
SetDlgItemText(hdlg, IDC_VALUE4, "");

break;

case IDC_EXIT: // кнопка "Вихід"
EndDialog(hdlg, LOWORD(wParam));
return TRUE;
break;

}
break;

case WM_CLOSE:
	EndDialog(hdlg, LOWORD(wParam));

break;

default: return false;
}
}



