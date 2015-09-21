//Примеры
//Text("Test",10,10,RED,DT_LEFT|DT_NOCLIP);
//Box(10,10,100,100,RED,pDevice);
//Line(10,15,100,150,1,RED);
//GradientV2(100,10,100,25,DARK2,DARK3,DARK3,pDevice);
//Circle(100,100,10,10,DARK2);
//ColorCircle(10,10,8,0xff808080,pDevice);
#define  OPTBORD(a)        D3DCOLOR_ARGB(a, 45, 45, 48)
#define  ONBOX(a)          D3DCOLOR_ARGB(a, 27, 27, 28)
#define  ONBOX2(a)         D3DCOLOR_ARGB(a, 0, 122, 204)
void Options(char *BText,char *OText1,char *OText2,char *OText3,char *OText4,char *OText5,int &Var,int &Var2,int &Var3,int &Var4,int &Var5,int &Var6,int x,int y,int w,D3DCOLOR ctext,D3DCOLOR cisintext,D3DCOLOR ctclick,D3DCOLOR cbutton,D3DCOLOR cisinbox,D3DCOLOR cbclick,LPDIRECT3DDEVICE9 pDevice,int Number,int Alfa)
{
	if(Var==1){cbutton=cbclick;ctext=ctclick;}
	if(IsInBox(x,y,w,14))
	{
	if(Var==0){cbutton=cisinbox;ctext=cisintext;Box(x,y,w,14,cbutton,pDevice);}
	if(lm){if(Var == 1 && Var !=0){Var = 0;}else if(Var == 0){
		Fun.Vspomog=Fun.Settings=Fun.Test1=Fun.Test2=Fun.Test3=Fun.Test4=Fun.Test5=Fun.Test6=Fun.Test7=Fun.Test8=0;Var = 1;}}
	}
	if(Var==1)
	{
	Box(x,y,w,14,cbutton,pDevice);
    Border(x,y,w,14,1,OPTBORD(Alfa),pDevice);
    Border(x,y+15,150,Number*22-1,1,OPTBORD(Alfa),pDevice);
	Box(x,y+14,w,3,cbutton,pDevice);
    D3DCOLOR OPTIONS1,OPTIONS2,OPTIONS3,OPTIONS4,OPTIONS5;
	OPTIONS1=OPTIONS2=OPTIONS3=OPTIONS4=OPTIONS5=ONBOX(255);
    if(Number>0)
	{
	if(IsInBox(x+2,y+17,146,20))
	{
	if(Var2==0){OPTIONS1=cisinbox;}
	if(lm){Var2=!Var2;}
	}
	if(Var2==1){OPTIONS1=ONBOX2(Alfa);}
	Box(x+2,y+17,146,20,OPTIONS1,pDevice);
	Text(OText1,x+4,y+20,ctext,DT_LEFT|DT_NOCLIP);
	}
	if(Number>1)
	{
	if(IsInBox(x+2,y+16+22,146,20))
	{
	if(Var3==0){OPTIONS2=cisinbox;}
	if(lm){Var3=!Var3;}
	}
	if(Var3==1){OPTIONS2=ONBOX2(Alfa);}
	Box(x+2,y+16+22,146,20,OPTIONS2,pDevice);
	Text(OText2,x+4,y+19+22,ctext,DT_LEFT|DT_NOCLIP);
	}
	if(Number>2)
	{
	if(IsInBox(x+2,y+16+43,146,20))
	{
	if(Var4==0){OPTIONS3=cisinbox;}
	if(lm){Var4=!Var4;}
	}
	if(Var4==1){OPTIONS3=ONBOX2(Alfa);}
	Box(x+2,y+16+43,146,20,OPTIONS3,pDevice);
	Text(OText3,x+4,y+19+43,ctext,DT_LEFT|DT_NOCLIP);
	}
	if(Number>3)
	{
	if(IsInBox(x+2,y+16+64,146,20))
	{
	if(Var5==0){OPTIONS4=cisinbox;}
	if(lm){Var5=!Var5;}
	}
	if(Var5==1){OPTIONS4=ONBOX2(Alfa);}
	Box(x+2,y+16+64,146,20,OPTIONS4,pDevice);
	Text(OText4,x+4,y+19+64,ctext,DT_LEFT|DT_NOCLIP);
	}
	if(Number>4)
	{
	if(IsInBox(x+2,y+16+85,146,20))
	{
	if(Var6==0){OPTIONS5=cisinbox;}
	if(lm){Var6=!Var6;}
	}
	if(Var6==1){OPTIONS5=ONBOX2(Alfa);}
	Box(x+2,y+16+85,146,20,OPTIONS5,pDevice);
	Text(OText5,x+4,y+19+85,ctext,DT_LEFT|DT_NOCLIP);
	}
	}
	Text(BText,x+w/2,y,ctext,DT_CENTER|DT_NOCLIP);
}

void Exite(int x,int y,int &Var,D3DCOLOR EXITE2,D3DCOLOR ISINE2,D3DCOLOR LINE2,LPDIRECT3DDEVICE9 pDevice)
{
	if(IsInBox(x+275,9,25,20))
	{
		if(Var==0){EXITE2=ISINE2;}
		if(lm){Var=!Var;}
	}
		Box(x+379,y+9,32,15,EXITE2,pDevice);
		Line(x+392,y+14,x+397,y+19,1,LINE2);
		Line(x+397,y+14,x+392,y+19,1,LINE2);
		Box(x+397,y+19,1,1,LINE2,pDevice);
		Box(x+392,y+19,1,1,LINE2,pDevice);
}

void HideMenu(int x,int y,int &Var,D3DCOLOR HIDEBOX,D3DCOLOR ISINH2,D3DCOLOR ISINBOX,LPDIRECT3DDEVICE9 pDevice)
{
	if(IsInBox(x+357,y+9,20,15))
	{
	HIDEBOX=ISINBOX;Box(x+357,y+9,21,15,ISINH2,pDevice);
	if(lm){Var=!Var;}
	}
	Box(x+364,y+17,8,2,HIDEBOX,pDevice);

}

//-----------------------------------------------------------------------------
// Exam: Button("Кнопка",Test1  ,TColOff,TColIsIn,TColOn  ,BColOff,BColIsIn,BColOn,  pDevice,0,1);
// Desc: Button
// Сonc: Menu/Components
//-----------------------------------------------------------------------------

void Button(char *BText,int &Var,D3DCOLOR ctext,D3DCOLOR cisintext,D3DCOLOR ctclick,D3DCOLOR cbutton,D3DCOLOR cisinbox,D3DCOLOR cbclick,LPDIRECT3DDEVICE9 pDevice,int x,int y)
{
	if(Var==1){cbutton=cbclick;ctext=ctclick;}
	if(IsInBox(x,y,80,20))
	{
	//PlaySoundMem((LPCSTR)SWITCH);
	if(Var==0){cbutton=cisinbox;ctext=cisintext;}
	if(lm){if(Var == 1 && Var !=0){Var = 0;}else if(Var == 0){
		Fun.Test1=Fun.Test2=Fun.Test3=Fun.Test4=Fun.Test5=Fun.Test6=Fun.Test7=Fun.Test8=Fun.Vspomog=Fun.Settings=0;Var = 1;}}
	}
	Box(x,y,80,20,cbutton,pDevice);
	Text(BText,x+40,y+3,ctext,DT_CENTER|DT_NOCLIP);
}

//-----------------------------------------------------------------------------
// Exam: Check("Чек",Test1  ,TColOff,TColIsIn,TColOn  ,BColOff,BColIsIn,BColOn,  pDevice,0,1);//Готово
// Desc: Check
// Сonc: Menu/Components
//-----------------------------------------------------------------------------

void Check(char *BText,bool &Var,D3DCOLOR ctext,D3DCOLOR cisintext,D3DCOLOR ctclick,D3DCOLOR cbutton,D3DCOLOR cisinbox,D3DCOLOR cbclick,LPDIRECT3DDEVICE9 pDevice,int x,int y)
{
	if(Var==1){cbutton=cbclick;ctext=ctclick;Box(x+2,y+2,9,9,cbutton,pDevice);}
	if(IsInBox(x,y,100,14))
	{
	if(Var==0){cbutton=cisinbox;ctext=cisintext;}
	if(lm){Var=!Var;}
	}
	Border(x,y,13,13,2,cbutton,pDevice);
	Text(BText,x+25,y+1,ctext,DT_LEFT|DT_NOCLIP);
}

void DoubleCheck(char *BText,int &Var,D3DCOLOR ctext,D3DCOLOR cisintext,D3DCOLOR ctclick,D3DCOLOR cbutton,D3DCOLOR cisinbox,D3DCOLOR cbclick,LPDIRECT3DDEVICE9 pDevice,int x,int y)
{
	if(IsInBox(x-2,y-2,43,14))
	{
		if(Var==0)
		{
			cbutton=cisinbox;ctext=cisintext;
		}
		if(lm)
		{
			Var=!Var;
		}
	}
	if(Var==1)
	{
		cbutton=cbclick;
		ctext=ctclick;
	}
   
	if(Var > 0)
	{
		Box(x+20,y+2,19,8,cbutton,pDevice);
	}
	else
	{
		Box(x+2,y+2,19,8,cbutton,pDevice);
	}
	Border(x,y,41,12,2,cisinbox,pDevice);
	Text(BText,x+50,y-1,ctext,DT_LEFT|DT_NOCLIP);
}

void ColorCheck(char *BText,int &Var,D3DCOLOR ctext,D3DCOLOR cisintext,D3DCOLOR ctclick,D3DCOLOR cborder,D3DCOLOR cisinborder,D3DCOLOR cbclick,LPDIRECT3DDEVICE9 pDevice,int x,int y)
{
	D3DCOLOR cbutton;
	if(IsInBox(x-2,y-2,43,14))
	{
		if(Var==0)
		{
			ctext=cisintext;
		}
		if(lm)
		{
			if(Var>=0)
			{
				Var++;
			}
		}
		if(rm)
		{
			if(Var!=0)
			{
				Var--;
			}
		}
	}
	int X=2;
    switch (Var)
    {
    case 1: cbutton = RED(255);        break;
    case 2: cbutton = GREEN(255);/*X-1;*/  break;
    case 3: cbutton = BLUE(255); /*X-2;*/  break;
    case 4: cbutton = YELLOW(255);/*X-2;*/ break;
	case 5: cbutton = WHITE(255);/*X-2;*/ break;
	case 6: cbutton = BLACK(255);/*X-2;*/ break;
    case 7:                Var=0;      break;
    }

	if(Var>=1)
	{
		//cbutton=cbclick;
		ctext=ctclick;
	}

    if(Var > 0)
	{
		Box(x+X,y+2,37,8,cbutton,pDevice); // 9  9
		cborder=cbclick;
	}
	Border(x,y,41,12,2,cisinborder,pDevice); //13  13
	Text(BText,x+50,y-1,ctext,DT_LEFT|DT_NOCLIP);
}

//-----------------------------------------------------------------------------
// Exam: ScrollCheck ("ScrollCheck",volue,Test11  ,TColOff,EColOff,  pDevice,0,1,20);//Готово
// Desc: ScrollCheck
// Сonc: Menu/Components
//-----------------------------------------------------------------------------

void ScrollCheck(char *BText,char **typ,int &Var,D3DCOLOR ctext,D3DCOLOR cbutton,LPDIRECT3DDEVICE9 pDevice,int x,int y,int max)
{
	D3DCOLOR DopText1,DopText2;
	DopText1=DARK18;
	DopText2=DARK18;

	if(IsInBox(x,y,14,14))
    {
		DopText1=RED(255);
		if(flm)
		{
			if(Var!=0)
			{
				Var--;
				Sleep(50);
			}
		}
	}
	Box(x,y,14,14,DARK7,pDevice);
	Border(x,y,14,14,1,DARK15,pDevice);
    Text("<",x+5,y,DopText1,DT_LEFT|DT_NOCLIP);

	if(IsInBox(x+15,y,14,14))
    {
		DopText2= GREEN(255);
		if(flm)
		{
			if(Var>=0)
			{
				Var++;
				Sleep(50);
			}
			if(Var>max)
			{
				Var=max;
			}
		}
    }
	Box(x+14,y,14,14,DARK7,pDevice);
	Border(x+14,y,14,14,1,DARK15,pDevice);
    Text(">",x+5+15,y,DopText2,DT_LEFT|DT_NOCLIP);

	if(IsInBox(x+(14*2),y, 100, 14))
    {
		if(frm)
		{
			if(Var!=0)
			{
				Var--;Sleep(50);
			}
		}
		if(flm)
		{
			if(Var>=0)
			{
				Var++;
				Sleep(50);
			}
			if(Var>max)
			{
				Var=max;
			}
		}
    }
	char buf_T[ 256 ]; 
    sprintf( buf_T, "  [%s]  %s", typ[Var], BText); 
    Text(buf_T,x+(14*2),y-1,ctext,DT_LEFT|DT_NOCLIP);
}
