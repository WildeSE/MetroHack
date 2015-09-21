/*	DWORD гамешилд = (DWORD)GetModuleHandleA("gameShieldDll.dll");
	DWORD shield1 = гамешилд + 0x14E0;
	DWORD off = shield1 + 0x44;
	DWORD off1 = shield1 + 0x52;
DWORD гамешилд1 = (DWORD)GetModuleHandleA("gameShieldDll.dll");
//--------------------------------------модуль и подключаемая к нему функция frostfunc////////////////////
HMODULE gameshield = GetModuleHandleA("gameShieldDll.dll");
   DWORD frostfunc = (DWORD)GetProcAddress(gameshield, "frostFunc");
DWORD valu = гамешилд1 + 0xB618;
DWORD valve = valu + 0xB5EB;
DWORD loc_F411F5B = frostfunc + 0x1F43;//75 16 {jnz     short loc_F411F5B}
DWORD loc_F411F75 = frostfunc + 0x1F62;//jnz     short loc_F411F75 75 11
DWORD loc_F41216E = frostfunc + 0x215E;//jz      short loc_F41216E
DWORD vv = frostfunc + 0x2168;//jz      short loc_F41216E
DWORD func5 = frostfunc + 0x2172;//pop     ebp
DWORD func6 = гамешилд1 + 0x2442;//mov     [ebp+var_4], 0FFFFFFFFh
DWORD ff = func6 + 0x0FFFFFFF;
	////////asm frost func
DWORD gg = 0x2113;//pop     ebp
DWORD aa = 0x1E13;//push    0FFFFFFFFh
DWORD bb = 0x1E5E;// mov     byte ptr [ebp-4], 1 //C6 45 FC 01
DWORD dd = gg + 0x2F;//offset
DWORD sub_F3F7CF0 = frostfunc + 0x1F4E;//call    sub_F3F7CF0 //E8 9D 5D FE FF
__declspec(naked)int funcfrost(void)
{
_asm
{
jnz     short loc_F411F5B
jnz     short loc_F411F75
jz      short loc_F41216E
jz      short vv
mov     dword ptr [ebp-4], 0FFFFFFFFh
mov     byte ptr [ebp-4], 1
call    sub_F3F7CF0
push short aa
jmp short off
jmp short off1
jmp short shield1
jmp dword ptr gg;
jmp dword ptr func5;
	jmp short func6
}
}
///-----------------------------------bypass-------------------------------------------//
__declspec(naked)int bypass(void)
{
_asm
{
mov     byte ptr [ebp-4], 0Bh
jmp dword ptr gg;
jmp dword ptr func5;
jmp dword ptr valu;
jnz     short loc_F411F5B
jnz     short loc_F411F75
jz      short loc_F41216E
}
}*/
/*
DWORD Game = (DWORD)GetModuleHandleA("Game.exe");
DWORD book = Game + 0x00E98EE1;// - 83 c4 08 //,(PBYTE)"\x90\x90",2);
DWORD addr2 = Game +0xE978D7;//,(PBYTE)"\x8D\x44\x24\x00",4);//            JE SHORT Dumped(1.00EBF42A
//DWORD addr3 = Game +0xE98A57;//,(PBYTE)"\x8D\x44\x24\x00",4);
/*_declspec(naked)int gamekik(void)
{
_asm
{
lea eax,[esp+00]
jmp [addr3]
}
}
DWORD addr3 = 0x00E98A57;
DWORD dword_145FC00 = addr3 + 0x145FC00;
_declspec(naked)int hook1(void){ _asm{lea eax,[esp+00] _asm{jmp addr3}_asm{call    ds:dword_145FC00}}}

HRESULT APIENTRY asm_bypass()
{

while(1)
{
//MEMwrite((void*)(addr2),(PBYTE)"\x8D\x44\x24\x00",4);
//MEMwrite((void*)(0x00E98A57),(PBYTE)"\x8D\x44\x24\x00",4);
DetourCreate((LPBYTE)addr3,(LPBYTE)hook1,7);
Sleep(500);
}
}
*/