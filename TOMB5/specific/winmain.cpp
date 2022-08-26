#include "../tomb5/pch.h"
#include "winmain.h"
#include "dxshell.h"
#include "function_stubs.h"
#include "output.h"

void ClearSurfaces()
{
	D3DRECT r;

	r.x1 = App.dx.rViewport.left;
	r.y1 = App.dx.rViewport.top;
	r.y2 = App.dx.rViewport.top + App.dx.rViewport.bottom;
	r.x2 = App.dx.rViewport.left + App.dx.rViewport.right;

	if (App.dx.Flags & 0x80)
		DXAttempt(App.dx.lpViewport->Clear2(1, &r, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0F, 0));
	else
		ClearFakeDevice(App.dx.lpD3DDevice, 1, &r, D3DCLEAR_TARGET, 0, 1.0F, 0);

	S_DumpScreen();

	if (App.dx.Flags & 0x80)
		DXAttempt(App.dx.lpViewport->Clear2(1, &r, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0F, 0));
	else
		ClearFakeDevice(App.dx.lpD3DDevice, 1, &r, D3DCLEAR_TARGET, 0, 1.0F, 0);

	S_DumpScreen();
}

long CheckMMXTechnology()
{
	ulong _edx;
	long mmx;

	mmx = 1;

	__try
	{
		__asm
		{
			pusha
			mov eax, 1
			cpuid
			mov _edx, edx
			popa
		}

	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		mmx = 0;
	}

	if (!mmx)
		mmx = 0;

	if (_edx & 0x800000)
	{
		__try
		{
			__asm
			{
				emms
			}
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			mmx = 0;
		}
	}
	else
		mmx = 0;

	return mmx;
}

bool WinRunCheck(LPSTR WindowName, LPSTR ClassName, HANDLE* mutex)
{
	HWND window;

	Log(2, "WinRunCheck");
	*mutex = CreateMutex(0, 1, WindowName);

	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		window = FindWindow(ClassName, WindowName);

		if (window)
		{
#ifdef GENERAL_FIXES
			SendMessage(window, WM_ACTIVATE, WA_ACTIVE, 0);
			SetWindowPos(window, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
			SetWindowPos(window, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
#else
			SendMessage(window, WM_ACTIVATE, 0, 0);
#endif
		}

		return 1;
	}

	return 0;
}

void inject_winmain(bool replace)
{
	INJECT(0x004D1AD0, ClearSurfaces, replace);
	INJECT(0x004D22D0, CheckMMXTechnology, replace);
	INJECT(0x004D2DD0, WinRunCheck, replace);
}
