
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
	int Aero = 255;    //Прозрачность 200
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

	//Панель управления
	DWORD TColOff  = WHITE(Aero);         //Цвет текста    [Выкл]
	DWORD TColIsIn = EXITECOLOR(Aero);    //Цвет текста    [IsInBox]
	DWORD TColOn   = ONT(Aero);           //Цвет текста   [Вкл]
	DWORD EColOff  = BUTTONCOLOR(Aero);   //Цвет елементов [Выкл]
	DWORD EColIsIn = ISINB(Aero);         //Цвет елементов [IsInBox]
	DWORD EColOn   = ONB(Aero);           //Цвет елементов [Вкл]
	DWORD BColOn   = BUTTONON(Aero);      //Цвет кнопки    [Вкл]
	DWORD DColOn   = EXITECOLOR(Aero);    //Цвет Double Chek    [Вкл]

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
			
			ColorCheck  ("Chams WarFace",Fun.chamsWF  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+250,y+1*20+10);//Готово
			ColorCheck  ("Chams BlackWood",Fun.chamsBW  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+250,y+2*20+10);//Готово
			ColorCheck  ("Chams Голова",Fun.ЧампГоловы  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+250,y+3*20+10);//Готово
			ColorCheck  ("Chams Оружие",Fun.оружие  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+250,y+4*20+10);//Готово
			ColorCheck  ("Chams Domate",Fun.donat  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+250,y+5*20+10);//Готово
			ColorCheck  ("Chams Бомба",Fun.Bomb  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+250,y+6*20+10);//Готово
			ColorCheck  ("Chams Граната",Fun.Mine  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+250,y+7*20+10);//Готово
		}

		if(Fun.Test2)
		{
			DoubleCheck ("Нет Рук",Fun.нетрук  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,pDevice,x+105,y+1*20+10);
			DoubleCheck ("Нет Прицела",Fun.прицел  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,pDevice,x+105,y+2*20+10);
			DoubleCheck ("Нет Grass",Fun.мусор  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,pDevice,x+105,y+3*20+10);
			DoubleCheck ("Нет Оружия",Fun.оружка  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,pDevice,x+105,y+4*20+10);
			DoubleCheck ("Нет Ящиков (Ангар)",Fun.angar  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,pDevice,x+105,y+5*20+10);
			DoubleCheck ("Нет Пола",Fun.floor  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,pDevice,x+105,y+6*20+10);
		}

		if(Fun.Test3)
		{
			ColorCheck  ("CrossHair [MAX]",Fun.cross  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+105,y+1*20+10);//Готово
			ColorCheck  ("CrossHair [MIN]",Fun.crossik  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,x+105,y+2*20+10);//Готово
		}	

		if(Fun.Test4)
		{
			DoubleCheck  ("Есп ГМ",Fun.ESPGM  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+1*20+10);//Готово
			DoubleCheck  ("Быстрый Нож",Fun.SpeedKnife  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+2*20+10);//Готово
			DoubleCheck  ("Быстрый Нож ПКМ",Fun.KnifePKM  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+3*20+10);//Готово
			DoubleCheck  ("Смена",Fun.Smena  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+4*20+10);//Готово	
			DoubleCheck  ("Вертикальная стрельба",Fun.VertFire  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+5*20+10);//Готово
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
			DoubleCheck  ("Каспер MOD (V)",Fun.CasperMod  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+1*20+10);//Готово
			DoubleCheck  ("Под Карту (X)",Fun.PodKartu  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+2*20+10);//Готово
			DoubleCheck  ("Гравитация (B)",Fun.Gravitation  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+3*20+10);//Готово
			DoubleCheck  ("Выносливость",Fun.Vinos  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+4*20+10);//Готово
		}

		if(Fun.Test6)
		{
			
			DoubleCheck  ("противник",Fun.противник  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+1*20+10);//Готово
			DoubleCheck  ("ESP[2D]",Fun.кубик  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+2*20+10);//Готово
			DoubleCheck  ("Дистанция",Fun.дистанция  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+3*20+10);//Готово
			//DoubleCheck  ("Выносливость",Fun.Vinos  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,DColOn,  pDevice,x+105,y+4*20+10);//Готово*/
		}
	}

		if(A1 > 40)
		{
			Text("Public Metro Hack by Teest",x+15,y+10,WHITE(Aero),DT_LEFT|DT_NOCLIP);
			
		
			/*Options("ВСПОМАГАТЕЛЬНЫЕ", "Отображать FPS    ", "Отображать Время", "Отображать Дату", "Выйти из игры","   ",Fun.Vspomog,Fun.FPS,Fun.Time,Fun.Date,Fun.Exit,Fun.Test36,x+10 ,y+10,110,TColOff,TColOff,TColOff,EColOff,EColIsIn,EColOn,pDevice,4,Aero);
			Options("НАСТРОЙКИ      ", "Двигать меню (F2)", "Закрыть меню    ", "Свернуть       ","             ","   ",Fun.Settings,Fun.MoveMenu,Fun.CloseMenu,Fun.HideMenu,Fun.Test34,Fun.Test37,x+121,y+10,70 ,TColOff,TColOff,TColOff,EColOff,EColIsIn,EColOn,pDevice,3,Aero);
			//Options("КНОПКИ         ","HOME              ","INSERT          ","END            ","DELETE       ","F-5",Fun.B,Fun.Test26,Fun.Test29,Fun.Test32,Fun.Test35,Fun.Test38,x+192,y+10,50 ,TColOff,TColOff,TColOff,EColOff,EColIsIn,EColOn,pDevice,5,Aero);
			*/
		}
	
	
		//Button      ("Кнопка     ",Test1   ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,0,1);//Готово
		//Check       ("Чек        ",Test1   ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,0,1);//Готово
		//DoubleCheck ("ДаблЧек    ",Test1   ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,0,1);//Готово
		//RadioCheck  ("РадиоЧек   ",Test1   ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,0,1);//Готово
		//ColorCheck  ("Цветной Чек",Test11  ,TColOff,TColIsIn,TColOn  ,EColOff,EColIsIn,EColOn,  pDevice,0,1);//Готово
		//ScrollCheck ("ScrollCheck",volue,Test11  ,TColOff,EColOff,  pDevice,0,1,20);//Готово
}