DWORD dwNoRecoil1 = 0x4E9E1A;
DWORD dwNoRecoil2 = 0x4E9CBA;
DWORD dwNoSpread = 0x4C8FB3;
DWORD dwRapidFire = 0x4E9A83;
DWORD dwNoFlash = 0x67C370;
DWORD dwWallShot = 0x4D9B1A;
DWORD dwNoResp = 0x49F684;
DWORD dwPacket = 0x4ACAB0;
DWORD dwPacketMiner = 0x4B1B60;
DWORD dwMiner1 = 0x49CC88;
DWORD dwMiner2 = 0x49CCC1;
DWORD dwFastPlant = 0x49CE70;
DWORD dwFastDefuse = 0x49D479;
DWORD dwESP1 = 0x67CE59;
DWORD dwESP2 = 0x5C55D1;
DWORD dwHover = 0x4A3CDE2;
DWORD dwLongThrow = 0x4EABF2;
DWORD dwResp50 = 0x49F73E;
DWORD dwReload40 = 0x4E5546;
DWORD dwSuperSniper = 0x844DB9;
DWORD dwLockPric = 0x4EA030;
DWORD dwNoGrenDamage = FindPattern(0x401000, 0x4c8000, (PBYTE)"\x8B\ x45\xFC\x8B\xE5\x5D\xC2\ x04\x00\xCC\xCC\xCC\xCC\ xCC\x55\x8B\xEC\x83\xEC\ x44\x89\x4D\xBC\x8D\x45\ xF4\x50\x8B\x4D\xBC\x8B\ x89\x00\x00\x00\x00\xFF\ x15\x00\x00\x00\x00\xD9\ x45\xF4", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx? ???xx????xxx");

DWORD dwZoom = 0x4EAA6C;
DWORD dwFastBang = 0x4EAC89;
DWORD dwDN = 0x4EA11C;
DWORD dwNFD = 0x643AAF;
DWORD dwAirJump1 = 0x6488A3;
DWORD dwAirJump2 = 0x6488C7;
DWORD dwAirJump3 = 0x648957;
DWORD dwGMChatText = 0x41DE4C;
DWORD dwChangeTeam = 0x554A30;
DWORD dwChangeTeamCall = 0x553CA0;
DWORD dwNoReload = 0x4E5536;
DWORD ReturnNoReload = 0x4E553C;
DWORD dwSpeedHack = 0x64745F;
DWORD ReturnSpeedHack = 0x647465;
DWORD dwEnd = 0x4E25BD;
DWORD ReturnEnd = 0x4E25C4;
DWORD dwQuickSwap = 0x4D5D03B;
DWORD ReturnQuickSwap = 0x4D5D041;
DWORD dwUpJump = 0x843C50;
DWORD ReturnUpJump = 0x843C55;
DWORD dwLongJump = 0x843C8F;
DWORD ReturnLongJump = 0x843C94;

#define VK_Y 0x59
#define VK_B 0x42
#define VK_V 0x56
#define VK_Q 0x51
#define VK_N 0x4E
#define VK_C 0x43
#define VK_X 0x58
#define VK_CONTROL 0x11
#define VK_CAPITAL 0x14

HRESULT WINAPI Features()
{
	while(1)
	{
		if (Fun.ESPGM == 1)
		{
			MEMwrite((void *)(dwESP1), (void*)(PBYTE)"\x90\x90\x90\x90\x90\x90", 6);// on
			MEMwrite((void *)(dwESP2), (void*)(PBYTE)"\x90\x90\x90\x90\x90\x90", 6);// on
		}
		if (Fun.ESPGM == 0)
		{
			MEMwrite((void *)(dwESP1), (void*)(PBYTE)"\x0F\x84\x8E\x00\x00\x00", 6); //off
			MEMwrite((void *)(dwESP2), (void*)(PBYTE)"\x0F\x85\x51\x01\x00\x00", 6); //off
		}

		
		Sleep(250);
	}
}