#include "Includes.h"
#include "Variables.h"
#include "Tools.h"
#include "Features.h"
#include "textures.h"
#include "Color.h"
#include "Bypass.h"
#include "Protection.h"
#include "Draw.h"
#include "Sound.h"
#include "Components.h"
#include "Menu.h"
#include "Functions.h"
#include "ESPoid.h"

D3DVIEWPORT9 viewport;
cFun Fun;
LPDIRECT3DTEXTURE9 White,Red,Green,Blue,Black,Purple,Grey,Yellow,Oranges,DeepSkyBlues,Chocolate2,Gold2,Squa;
unsigned int m_Stride;
//bool Color=true;


HRESULT GenerateTexture(IDirect3DDevice9 *pD3Ddev, IDirect3DTexture9 **ppD3Dtex, DWORD colour32)
{
    if(FAILED(pD3Ddev->CreateTexture(8, 8, 1, 0, D3DFMT_A4R4G4B4, D3DPOOL_MANAGED, ppD3Dtex, NULL)))
        return E_FAIL;
    
    WORD colour16 = ((WORD)((colour32>>28)&0xF)<<12)
	            	|(WORD)(((colour32>>20)&0xF)<<8)
	             	|(WORD)(((colour32>>12)&0xF)<<4)
                 	|(WORD)(((colour32>>4)&0xF)<<0);

    D3DLOCKED_RECT d3dlr;    
    (*ppD3Dtex)->LockRect(0, &d3dlr, 0, 0);
    WORD *pDst16 = (WORD*)d3dlr.pBits;

    for(int xy=0; xy < 8*8; xy++)
        *pDst16++ = colour16;

    (*ppD3Dtex)->UnlockRect(0);

    return S_OK;
}

HRESULT WINAPI myReset (LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	if(pFont)pFont->OnLostDevice();
	if(pLine)pLine->OnLostDevice();
	HRESULT hRet = pReset( pDevice, pPresentationParameters );
	if(SUCCEEDED(hRet))
	{
		if(pFont)pFont->OnResetDevice();
		if(pLine)pLine->OnResetDevice();
	}
	return hRet;
}

HRESULT APIENTRY myEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	if( !Create )
	{
		D3DXCreateLine(pDevice,&pLine);
	    Font("Arial",14,FW_NORMAL,pDevice);
		Create = true;
	}	
	if( pFont == NULL )pFont->OnLostDevice();
	else
	{
		if(GetAsyncKeyState(VK_HOME)&1)Show=(!Show);
		if(Show){GoldBase( pDevice);}
	}
	if(GetAsyncKeyState(VK_F3)&1)D3D9ScreenShot(pDevice); 

	if(Fun.Exit)
	{
		ExitProcess(0);
	}
	//ESP(pDevice, pFont);

	/*int plX = viewP.Width -150;
	int plY = 5;*/

	D3DXVECTOR2 Screens; 
	Screens.x = viewP.Width -100;
	Screens.y = 5;

	Text("[Teest Productions]",Screens.x,Screens.y,GREY(255),LText);

	return pEndScene( pDevice );
}

HRESULT WINAPI  myDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE Type, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
	if(Color)
	{	
		GenerateTexture(pDevice, &Red,    RED(255));
		GenerateTexture(pDevice, &Green,  GREEN(255));
		GenerateTexture(pDevice, &Blue,   BLUE(255));
		GenerateTexture(pDevice, &White,  WHITE(255));
		GenerateTexture(pDevice, &Black,  BLACK(255));
		GenerateTexture(pDevice, &Purple, PURPLE(255));
		GenerateTexture(pDevice, &Grey,   GREY(255));
		GenerateTexture(pDevice, &Yellow, YELLOW(255));
		GenerateTexture(pDevice, &Oranges, ORANGE(255));
		GenerateTexture(pDevice, &DeepSkyBlues, DEEPSKYBLUE); 
		GenerateTexture(pDevice, &Chocolate2, CHOCOLATE2); 
		GenerateTexture(pDevice, &Gold2, GOLD2);  
		GenerateTexture(pDevice, &Squa, SQUA);
		Color = false;
	}

	if (Fun.chamsWF)
	{
		if (WF)
		{
			pDevice->SetRenderState(D3DRS_ZENABLE,0);
			if(Fun.chamsWF==1)pDevice->SetTexture(0,Red);
			if(Fun.chamsWF==2)pDevice->SetTexture(0,Green);
			if(Fun.chamsWF==3)pDevice->SetTexture(0,Blue);
			if(Fun.chamsWF==4)pDevice->SetTexture(0,Yellow);
			if(Fun.chamsWF==5)pDevice->SetTexture(0,White);
			if(Fun.chamsWF==6)pDevice->SetTexture(0,Black);
			pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE,1);
			if(Fun.chamsWF==1)pDevice->SetTexture(0,Red);
			if(Fun.chamsWF==2)pDevice->SetTexture(0,Green);
			if(Fun.chamsWF==3)pDevice->SetTexture(0,Blue);
			if(Fun.chamsWF==4)pDevice->SetTexture(0,Yellow);
			if(Fun.chamsWF==5)pDevice->SetTexture(0,White);
			if(Fun.chamsWF==6)pDevice->SetTexture(0,Black);
		}
	}

	if (Fun.chamsBW)
	{
		if (BW)
		{
			pDevice->SetRenderState(D3DRS_ZENABLE,0);
			if(Fun.chamsBW==1)pDevice->SetTexture(0,Red);
			if(Fun.chamsBW==2)pDevice->SetTexture(0,Green);
			if(Fun.chamsBW==3)pDevice->SetTexture(0,Blue);
			if(Fun.chamsBW==4)pDevice->SetTexture(0,Yellow);
			if(Fun.chamsBW==5)pDevice->SetTexture(0,White);
			if(Fun.chamsBW==6)pDevice->SetTexture(0,Black);
			pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE,1);
			if(Fun.chamsBW==1)pDevice->SetTexture(0,Red);
			if(Fun.chamsBW==2)pDevice->SetTexture(0,Green);
			if(Fun.chamsBW==3)pDevice->SetTexture(0,Blue);
			if(Fun.chamsBW==4)pDevice->SetTexture(0,Yellow);
			if(Fun.chamsBW==5)pDevice->SetTexture(0,White);
			if(Fun.chamsBW==6)pDevice->SetTexture(0,Black);
		}
	}

	if(Fun.ЧампГоловы)
	{
		if (playerheads)
		{
			pDevice->SetRenderState(D3DRS_ZENABLE,0);
			if(Fun.ЧампГоловы==1)pDevice->SetTexture(0,Red);
			if(Fun.ЧампГоловы==2)pDevice->SetTexture(0,Green);
			if(Fun.ЧампГоловы==3)pDevice->SetTexture(0,Blue);
			if(Fun.ЧампГоловы==4)pDevice->SetTexture(0,Yellow);
			if(Fun.ЧампГоловы==5)pDevice->SetTexture(0,White);
			if(Fun.ЧампГоловы==6)pDevice->SetTexture(0,Black);
			pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE,1);
			if(Fun.ЧампГоловы==1)pDevice->SetTexture(0,Red);
			if(Fun.ЧампГоловы==2)pDevice->SetTexture(0,Green);
			if(Fun.ЧампГоловы==3)pDevice->SetTexture(0,Blue);
			if(Fun.ЧампГоловы==4)pDevice->SetTexture(0,Yellow);
			if(Fun.ЧампГоловы==5)pDevice->SetTexture(0,White);
			if(Fun.ЧампГоловы==6)pDevice->SetTexture(0,Black);
		}
	}

	if (Fun.оружие)
	{
		if ((NumVertices == 1235 && primCount == 935 ) || (NumVertices == 524 && primCount == 392 ) || (NumVertices == 1046 && primCount == 869 ) || (NumVertices == 1380 && primCount == 1051 ) || (NumVertices == 1306 && primCount == 995 ) || (NumVertices == 1103 && primCount == 780 ))
		{
			pDevice->SetRenderState(D3DRS_ZENABLE, 0);
			if (Fun.оружие==1)pDevice->SetTexture(0,Red);
			if (Fun.оружие==2)pDevice->SetTexture(0,Green);
			if (Fun.оружие==3)pDevice->SetTexture(0,Blue);
			if (Fun.оружие==4)pDevice->SetTexture(0,Yellow);
			if (Fun.оружие==5)pDevice->SetTexture(0,White);
			if (Fun.оружие==6)pDevice->SetTexture(0,Black);
			pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE,1);
			if (Fun.оружие==1)pDevice->SetTexture(0,Red);
			if (Fun.оружие==2)pDevice->SetTexture(0,Green);
			if (Fun.оружие==3)pDevice->SetTexture(0,Blue);
			if (Fun.оружие==4)pDevice->SetTexture(0,Yellow);
			if (Fun.оружие==5)pDevice->SetTexture(0,White);
			if (Fun.оружие==6)pDevice->SetTexture(0,Black);
		}
	}

	if (Fun.donat)
	{
		if ((NumVertices == 590 && primCount == 764 ) || (NumVertices == 533 && primCount == 700 ) || (NumVertices == 458 && primCount == 596 ) || (NumVertices == 1767 && primCount == 1729 ) || (NumVertices == 900 && primCount == 772 ) || (NumVertices == 1677 && primCount == 1704 ) || (NumVertices == 377 && primCount == 520 ) || (NumVertices == 647 && primCount == 576 ) || (NumVertices == 750 && primCount == 840 ) || (NumVertices == 1377 && primCount == 984 ) || (NumVertices == 550 && primCount == 790 ) || (NumVertices == 1473 && primCount == 1214 ))
		{
			pDevice->SetRenderState(D3DRS_ZENABLE, 0);
			if (Fun.donat==1)pDevice->SetTexture(0,Red);
			if (Fun.donat==2)pDevice->SetTexture(0,Green);
			if (Fun.donat==3)pDevice->SetTexture(0,Blue);
			if (Fun.donat==4)pDevice->SetTexture(0,Yellow);
			if (Fun.donat==5)pDevice->SetTexture(0,White);
			if (Fun.donat==6)pDevice->SetTexture(0,Black);
			pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE,1);
			if (Fun.donat==1)pDevice->SetTexture(0,Red);
			if (Fun.donat==2)pDevice->SetTexture(0,Green);
			if (Fun.donat==3)pDevice->SetTexture(0,Blue);
			if (Fun.donat==4)pDevice->SetTexture(0,Yellow);
			if (Fun.donat==5)pDevice->SetTexture(0,White);
			if (Fun.donat==6)pDevice->SetTexture(0,Black);
		}
	}

	if (Fun.Bomb)
	{
		if ((NumVertices == 590 && primCount == 450 ))
		{
			pDevice->SetRenderState(D3DRS_ZENABLE, 0);
			if (Fun.Bomb==1)pDevice->SetTexture(0,Red);
			if (Fun.Bomb==2)pDevice->SetTexture(0,Green);
			if (Fun.Bomb==3)pDevice->SetTexture(0,Blue);
			if (Fun.Bomb==4)pDevice->SetTexture(0,Yellow);
			if (Fun.Bomb==5)pDevice->SetTexture(0,White);
			if (Fun.Bomb==6)pDevice->SetTexture(0,Black);
			pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE,1);
			if (Fun.Bomb==1)pDevice->SetTexture(0,Red);
			if (Fun.Bomb==2)pDevice->SetTexture(0,Green);
			if (Fun.Bomb==3)pDevice->SetTexture(0,Blue);
			if (Fun.Bomb==4)pDevice->SetTexture(0,Yellow);
			if (Fun.Bomb==5)pDevice->SetTexture(0,White);
			if (Fun.Bomb==6)pDevice->SetTexture(0,Black);
		}
	}

	if (Fun.Mine)
	{
		if ((NumVertices == 637 && primCount == 524 ) || (NumVertices == 661 && primCount == 776 ))
		{
			pDevice->SetRenderState(D3DRS_ZENABLE, 0);
			if (Fun.Mine==1)pDevice->SetTexture(0,Red);
			if (Fun.Mine==2)pDevice->SetTexture(0,Green);
			if (Fun.Mine==3)pDevice->SetTexture(0,Blue);
			if (Fun.Mine==4)pDevice->SetTexture(0,Yellow);
			if (Fun.Mine==5)pDevice->SetTexture(0,White);
			if (Fun.Mine==6)pDevice->SetTexture(0,Black);
			pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE,1);
			if (Fun.Mine==1)pDevice->SetTexture(0,Red);
			if (Fun.Mine==2)pDevice->SetTexture(0,Green);
			if (Fun.Mine==3)pDevice->SetTexture(0,Blue);
			if (Fun.Mine==4)pDevice->SetTexture(0,Yellow);
			if (Fun.Mine==5)pDevice->SetTexture(0,White);
			if (Fun.Mine==6)pDevice->SetTexture(0,Black);
		}
	}

	if(Fun.нетрук)
	{
		if ((NumVertices == 1100 && primCount == 1500 ) || (NumVertices == 1784 && primCount == 2814 ) || (NumVertices == 662 && primCount == 364) || (NumVertices == 2415 && primCount == 3690) || (NumVertices == 1784 && primCount == 2814))
		{
			return S_OK;
			return 0;
		}
	}

	if(Fun.мусор)
	{
		if ((NumVertices == 445 && primCount == 279 || NumVertices == 401 && primCount == 290 || NumVertices == 66 && primCount == 60 || NumVertices == 588 && primCount == 336 || NumVertices == 211 && primCount == 277 || NumVertices == 167 && primCount == 230 || NumVertices == 423 && primCount == 544))
		{
			return S_OK;
			return 0;
		}
	}

	if(Fun.прицел)
	{
		if ((NumVertices == 126 && primCount == 160))
		{
			return S_OK;
			return 0;
		}	
	}

	if(Fun.angar)
	{
		if ((NumVertices == 328 && primCount == 194) || (NumVertices == 226 && primCount == 220) || (NumVertices == 328 && primCount == 194))
		{
			return S_OK;
			return 0;
		}
	}

	if(Fun.floor)
	{
		if ((NumVertices == 555 && primCount == 495))
		{
			return S_OK;
			return 0;
		}
	}

	if(Fun.оружка)
	{
		if ((NumVertices == 1417 && primCount == 1248) || (NumVertices == 1770 && primCount == 1400) || (NumVertices == 1405 && primCount == 1240) || (NumVertices == 1761 && primCount == 1336) || (NumVertices == 1439 && primCount == 1489) || (NumVertices == 1831 && primCount == 1432) || (NumVertices == 1440 && primCount == 1153) || (NumVertices == 1330 && primCount == 1176) || (NumVertices == 1129 && primCount == 1225) || (NumVertices == 1963 && primCount == 1740) || (NumVertices == 1438 && primCount == 1149))
		{
			return S_OK;
			return 0;
		}
	}

	if(Fun.wireframe)
	{
		if(WF)
		{ 
			DWORD dwZEnable = D3DZB_TRUE;
			pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
			pDevice->GetRenderState(D3DRS_ZENABLE, &dwZEnable); 
			pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
			pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE, dwZEnable);
		}
		else
		{
			pDevice->SetRenderState( D3DRS_FILLMODE, D3DFILL_SOLID );
		} 
	}

	if (Fun.cross)
	{ 
		pDevice->GetViewport(&viewport);
		DWORD ScreenCenterX = viewport.Width /2;
		DWORD ScreenCenterY = viewport.Height / 2;

		D3DRECT rec16 = {ScreenCenterX-35, ScreenCenterY, ScreenCenterX+ 35, ScreenCenterY+1};
		D3DRECT rec17 = {ScreenCenterX, ScreenCenterY-35, ScreenCenterX+ 1,ScreenCenterY+35};
 
		if (Fun.cross==1)
		{
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET,RED(255),0,0 );
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET,RED(255),0,0 );
		}
		if (Fun.cross==2)
		{
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET,GREEN(255),0,0 );
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET,GREEN(255),0,0 );
		}
		if (Fun.cross==3)
		{
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET,BLUE(255),0,0 );
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET,BLUE(255),0,0 );
		}
		if (Fun.cross==4)
		{
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET,YELLOW(255),0,0 );
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET,YELLOW(255),0,0 );
		}
		if (Fun.cross==5)
		{
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET,WHITE(255),0,0 );
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET,WHITE(255),0,0 );
		}
		if (Fun.cross==6)
		{
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET,BLACK(255),0,0 );
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET,BLACK(255),0,0 );
		}
	}

	if (Fun.crossik)
	{	 
		pDevice->GetViewport(&viewport);
		DWORD ScreenCenterX = viewport.Width /2;
		DWORD ScreenCenterY = viewport.Height / 2;

		D3DRECT rec16 = {ScreenCenterX-20, ScreenCenterY, ScreenCenterX+ 20, ScreenCenterY+1};
		D3DRECT rec17 = {ScreenCenterX, ScreenCenterY-20, ScreenCenterX+ 1,ScreenCenterY+20};
 
		if (Fun.cross==1)
		{
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET,RED(255),0,0 );
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET,RED(255),0,0 );
		}
		if (Fun.cross==2)
		{
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET,GREEN(255),0,0 );
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET,GREEN(255),0,0 );
		}
		if (Fun.cross==3)
		{
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET,BLUE(255),0,0 );
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET,BLUE(255),0,0 );
		}
		if (Fun.cross==4)
		{
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET,YELLOW(255),0,0 );
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET,YELLOW(255),0,0 );
		}
		if (Fun.cross==5)
		{
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET,WHITE(255),0,0 );
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET,WHITE(255),0,0 );
		}
		if (Fun.cross==6)
		{
			pDevice->Clear( 1, &rec16, D3DCLEAR_TARGET,BLACK(255),0,0 );
			pDevice->Clear( 1, &rec17, D3DCLEAR_TARGET,BLACK(255),0,0 );
		}
	}

	if(Fun.WalHack)
	{
		if(BWE)
		{
			pDevice->SetRenderState(D3DRS_ZENABLE,0);
			pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE,1);
		}
	}

	if(Fun.WalHack)
	{
		if(WF||BW)
		{
			pDevice->SetRenderState(D3DRS_ZENABLE,0);
			pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE,1);
		}
	}

	return pDrawIndexedPrimitive(pDevice, Type, BaseVertexIndex,  MinVertexIndex,  NumVertices, startIndex, primCount);
}


int HookpDevice(void)
{
	DWORD*vtbl=0;
	DWORD hD3D9=(DWORD)LoadLibraryA("d3d9.dll");
	DWORD table=FindPattern(hD3D9,0x128000,(PBYTE)"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86","xx????xx????xx");
	memcpy(&vtbl,(void*)(table+2),4);
	pEndScene=(oEndScene)DetourCreate((PBYTE)vtbl[42],(PBYTE)myEndScene,5);
	pDrawIndexedPrimitive=(oDrawIndexedPrimitive)DetourCreate((PBYTE)vtbl[82],(PBYTE)myDrawIndexedPrimitive,5);
	return 0;
}

void ProtectMain()
{
	//Log("Start Protect!");
	for ( ; ; )
	{
		AntiDumping();
		AntiOllyDbg();
		Sleep(2);
	}
}

void MainProc()
{
	CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)HookpDevice,NULL,NULL,NULL);  
	ExitThread(hExitThread);
}

BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
	DisableThreadLibraryCalls(hDll);
	if (dwReason==DLL_PROCESS_ATTACH)
	{
		StartLogModule(hDll);
		AntiHeaders(hDll);
		HideModule(hDll);
		StartRoutine(MainProc); 
		StartRoutine(ProtectMain);
		//StartRoutine(Features);
		/*
		StartRoutine(Bypass);
		StartRoutine(Features);
		
		OpenURL("http://pbhack.ru/");
		OpenURL("http://pbhack.ru/forum/?showuser=53834");
		*/
	}
	return TRUE;
}