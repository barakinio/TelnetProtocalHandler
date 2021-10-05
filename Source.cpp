#include <string>
#include <iostream>
#include <Windows.h>
#include <winternl.h>

typedef void(__stdcall* FuncOpenUrl)(HWND, HINSTANCE, LPCSTR, int);

int main()
{
	HINSTANCE hIns = LoadLibraryA("C:\\WINDOWS\\System32\\url.dll");
	if (hIns) {
		FuncOpenUrl UrlOpenPls = (FuncOpenUrl)GetProcAddress((HMODULE)GetModuleHandleA("C:\\WINDOWS\\System32\\url.dll"), "OpenURL");
		UrlOpenPls(NULL, GetModuleHandle(NULL), "file://C:/Windows/system32/cmd.exe", 10);
	}
}
