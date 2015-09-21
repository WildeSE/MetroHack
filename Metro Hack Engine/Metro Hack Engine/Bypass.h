DWORD AddresBypass	= 0x00BC1687;//0x00E9CD97
DWORD dword_1467C10 = AddresBypass + 0x1467C10;//0x1469C0C  1467C10

__declspec(naked)int BypassHook(void)
{ 
	_asm
	{
		lea eax, [esp + 00] 
		_asm
		{
			jmp AddresBypass
		}
		_asm
		{
			call    ds : dword_1467C10
		}
	} 
}


HRESULT __stdcall Bypass()
{
	while(1)
	{
		DetourCreate((LPBYTE) AddresBypass, (LPBYTE) BypassHook, 7);
		Sleep(250);
	}
}