
void _stdcall GoldBase(LPDIRECT3DDEVICE9 pDevice)
{
	pDevice->GetViewport(&viewP);
	lm	 =    GetAsyncKeyState(VK_LBUTTON)&1;	
	rm   =    GetAsyncKeyState(VK_RBUTTON)&1;
	flm	 =    GetAsyncKeyState(VK_LBUTTON);	
	frm  =    GetAsyncKeyState(VK_RBUTTON);
	D3DVIEWPORT9 viewP;
	pDevice->GetViewport(&viewP);
	GetCursorPos(&mpos);
	ScreenToClient(GetForegroundWindow(),&mpos); 
	/*if(Fun.MoveMenu)
	{*/
		if(GetAsyncKeyState(VK_F2))
		{
			x =(((x<=mpos.x) && (x>=mpos.x)) || ((x>=mpos.x) && (x<=mpos.x)))?(x=mpos.x):(x+=((mpos.x-x)));
			y =(((y<=mpos.y) && (y>=mpos.y)) || ((y>=mpos.y) && (y<=mpos.y)))?(y=mpos.y):(y+=((mpos.y-y)));
		}
	//}

	if(Fun.HideMenu)
	{
		if(A1 != 0)
		{
			A1 -= 5;
		}
	}
	int Aero = 255;    //������������ 200
	#define	 WHITE(a)		   D3DCOLOR_ARGB(a, 255, 255, 255)
	#define  HEAD(a)           D3DCOLOR_ARGB(a, 182, 182, 183)
	#define  BODY(a)           D3DCOLOR_ARGB(a, 31, 31, 34)
	//#define  BORD(a)         D3DCOLOR_ARGB(a, 104, 33, 122)
	#define  BORD(a)           D3DCOLOR_ARGB(a, 52, 52, 54)
	#define  ISINB(a)          D3DCOLOR_ARGB(a, 62, 62, 64)
	#define  ISINT(a)          D3DCOLOR_ARGB(a, 104, 33, 122)
	#define  ONB(a)            D3DCOLOR_ARGB(a, 27, 27, 28)
	#define  ONT(a)            D3DCOLOR_ARGB(a, 14, 151, 189)
	#define  EXITECOLOR(a)     D3DCOLOR_ARGB(a, 199, 80, 80)
	#define  ISINE(a)          D3DCOLOR_ARGB(a, 224, 67, 67)
	#define  HIDEMENU(a)       D3DCOLOR_ARGB(a, 60, 60, 60)
	#define  ISINH(a)          D3DCOLOR_ARGB(a, 54, 101, 179)
	#define  BUTTONCOLOR(a)    D3DCOLOR_ARGB(a, 40, 40, 40)
	#define  BUTTONON(a)       D3DCOLOR_ARGB(a, 50, 50, 50)

	//������ ����������
	DWORD TColOff  = WHITE(Aero);         //���� ������    [����]
	DWORD TColIsIn = EXITECOLOR(Aero);    //���� ������    [IsInBox]
	DWORD TColOn   = ONT(Aero);           //���� ������   [���]
	DWORD EColOff  = BUTTONCOLOR(Aero);   //���� ��������� [����]
	DWORD EColIsIn = ISINB(Aero);         //���� ��������� [IsInBox]
	DWORD EColOn   = ONB(Aero);           //���� ��������� [���]
	DWORD BColOn   = BUTTONON(Aero);      //���� ������    [���]
	DWORD DColOn   = EXITECOLOR(Aero);    //���� Double Chek    [���]

	if(Fun.HideM == 0)
	{
		if(A1 != 195) //195
		{
			A1 += 5;
		}
	}

	if(Fun.HideM == 1)
	{
		if(A1 != 0)
		{
			A1 -= 5;
		}
	}

	if(IsInBox(x+10,y+10,400,A1+15))
	{
		Aero = 255;
	}

	Border(x+10,y+10,400,A1,1,BORD(Aero),pDevice);
	Box(x+10,y+10,400,A1,BODY(Aero),pDevice);
	Box(x+9,y+A1+9,402,15,BORD(Aero),pDevice); //15
	Exite(x,y,Fun.Close,EXITECOLOR(Aero),ISINE(Aero),WHITE(Aero),pDevice);
	HideMenu(x,y,Fun.HideM,HIDEMENU(Aero),ISINH(Aero),WHITE(Aero),pDevice);

	if(Fun.Close==1)
	{
		//Show=(!Show);
		Show=0;
		Fun.Close = 0;
	}

	if(IsInBox(x+379,y+9,32,15))
	{
		if(GetAsyncKeyState(0x01))
		{
			Show=0;
		}
	}
	/*
	if(Fun.Test22 != 0)
	{
		Fun.Test1=Fun.Test2=Fun.Test3=Fun.Test4=Fun.Test5=Fun.Test6=Fun.Test7=Fun.Test8=Fun.Test9=0;
	}

	if(Fun.Test23 != 0)
	{
		Fun.Test1=Fun.Test2=Fun.Test3=Fun.Test4=Fun.Test5=Fun.Test6=Fun.Test7=Fun.Test8=Fun.Test9=0;
	}
	*/
	Text("For PBhack.ru [09.10.2013]",x+15,y+A1+9,WHITE(Aero),DT_LEFT|DT_NOCLIP);

	if(A1 == 195) //195
	{


				Button ("D3D",Fun.Test1 ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,BColOn,pDevice,x+14,y+1*22+5);
				Button ("Remove",Fun.Test2 ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,BColOn,pDevice,x+14,y+2*22+5);
				Button ("CrossHair",Fun.Test3 ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,BColOn,pDevice,x+14,y+3*22+5);
				Button ("Weapon",Fun.Test4 ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,BColOn,pDevice,x+14,y+4*22+5);
				Button ("Player",Fun.Test5 ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,BColOn,pDevice,x+14,y+5*22+5);
				Button ("ESP",Fun.Test6 ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,BColOn,pDevice,x+14,y+6*22+5);
				/*Button ("Extrime",Fun.Test7 ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,BColOn,pDevice,x+14,y+7*22+5);
				Button ("About",Fun.Test8 ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,BColOn,pDevice,x+14,y+8*22+5);*/


		if(Fun.Test1)
		{
			DoubleCheck ("WallHack",Fun.WalHack  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,pDevice,x+105,y+1*20+10);
			DoubleCheck ("WireFrame",Fun.wireframe  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,pDevice,x+105,y+2*20+10);
			
			ColorCheck  ("Chams WarFace",Fun.chamsWF  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+250,y+1*20+10);//������
			ColorCheck  ("Chams BlackWood",Fun.chamsBW  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+250,y+2*20+10);//������
			ColorCheck  ("Chams ������",Fun.����������  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+250,y+3*20+10);//������
			ColorCheck  ("Chams ������",Fun.������  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+250,y+4*20+10);//������
			ColorCheck  ("Chams Domate",Fun.donat  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+250,y+5*20+10);//������
			ColorCheck  ("Chams �����",Fun.Bomb  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+250,y+6*20+10);//������
			ColorCheck  ("Chams �������",Fun.Mine  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+250,y+7*20+10);//������
		}

		if(Fun.Test2)
		{
			DoubleCheck ("��� ���",Fun.������  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,pDevice,x+105,y+1*20+10);
			DoubleCheck ("��� �������",Fun.������  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,pDevice,x+105,y+2*20+10);
			DoubleCheck ("��� Grass",Fun.�����  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,pDevice,x+105,y+3*20+10);
			DoubleCheck ("��� ������",Fun.������  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,pDevice,x+105,y+4*20+10);
			DoubleCheck ("��� ������ (�����)",Fun.angar  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,pDevice,x+105,y+5*20+10);
			DoubleCheck ("��� ����",Fun.floor  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,pDevice,x+105,y+6*20+10);
		}

		if(Fun.Test3)
		{
			ColorCheck  ("CrossHair [MAX]",Fun.cross  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+105,y+1*20+10);//������
			ColorCheck  ("CrossHair [MIN]",Fun.crossik  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+105,y+2*20+10);//������
		}	

		if(Fun.Test4)
		{
			DoubleCheck  ("��� ��",Fun.ESPGM  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+1*20+10);//������
			DoubleCheck  ("������� ���",Fun.SpeedKnife  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+2*20+10);//������
			DoubleCheck  ("������� ��� ���",Fun.KnifePKM  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+3*20+10);//������
			DoubleCheck  ("�����",Fun.Smena  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+4*20+10);//������	
			DoubleCheck  ("������������ ��������",Fun.VertFire  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+5*20+10);//������
		}
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

		if(Fun.Test5)
		{
			DoubleCheck  ("������ MOD (V)",Fun.CasperMod  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+1*20+10);//������
			DoubleCheck  ("��� ����� (X)",Fun.PodKartu  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+2*20+10);//������
			DoubleCheck  ("���������� (B)",Fun.Gravitation  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+3*20+10);//������
			DoubleCheck  ("������������",Fun.Vinos  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+4*20+10);//������
		}

		if(Fun.Test6)
		{
			
			DoubleCheck  ("���������",Fun.���������  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+1*20+10);//������
			DoubleCheck  ("ESP[2D]",Fun.�����  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+2*20+10);//������
			DoubleCheck  ("���������",Fun.���������  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+3*20+10);//������
			//DoubleCheck  ("������������",Fun.Vinos  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+4*20+10);//������*/
		}
	}

		if(A1 > 40)
		{
			Text("Public Metro Hack by Teest",x+15,y+10,WHITE(Aero),DT_LEFT|DT_NOCLIP);
			
		
			/*Options("���������������", "���������� FPS    ", "���������� �����", "���������� ����", "����� �� ����","   ",Fun.Vspomog,Fun.FPS,Fun.Time,Fun.Date,Fun.Exit,Fun.Test36,x+10 ,y+10,110,TColOff,TColOff,TColOff,EColOff,EColIsIn,EColOn,pDevice,4,Aero);
			Options("���������      ", "������� ���� (F2)", "������� ����    ", "��������       ","             ","   ",Fun.Settings,Fun.MoveMenu,Fun.CloseMenu,Fun.HideMenu,Fun.Test34,Fun.Test37,x+121,y+10,70 ,TColOff,TColOff,TColOff,EColOff,EColIsIn,EColOn,pDevice,3,Aero);
			//Options("������         ","HOME              ","INSERT          ","END            ","DELETE       ","F-5",Fun.B,Fun.Test26,Fun.Test29,Fun.Test32,Fun.Test35,Fun.Test38,x+192,y+10,50 ,TColOff,TColOff,TColOff,EColOff,EColIsIn,EColOn,pDevice,5,Aero);
			*/
		}
	
	
		//Button      ("������     ",Test1   ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,0,1);//������
		//Check       ("���        ",Test1   ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,0,1);//������
		//DoubleCheck ("�������    ",Test1   ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,0,1);//������
		//RadioCheck  ("��������   ",Test1   ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,0,1);//������
		//ColorCheck  ("������� ���",Test11  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,0,1);//������
		//ScrollCheck ("ScrollCheck",volue,Test11  ,TColOff,EColOff,  pDevice,0,1,20);//������
}