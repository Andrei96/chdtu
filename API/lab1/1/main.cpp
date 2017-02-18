#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	MessageBox(0, "Ваше імя Микита?", "ПЗС1644 БлизнюкАО", MB_ICONQUESTION|MB_CANCELTRYCONTINUE);
	return 0;
}

