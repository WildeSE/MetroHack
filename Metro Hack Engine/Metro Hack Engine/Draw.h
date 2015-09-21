
void Font(CHAR* FontName,int HFont,DWORD Stile,IDirect3DDevice9* pDevice )
{
	D3DXCreateFont(pDevice, HFont,0, Stile, 1, 0,RUSSIAN_CHARSET, OUT_DEVICE_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE,FontName, &pFont);
}

void  Text(LPSTR text,int x,int y,DWORD color,DWORD ST)
{
	RECT rect, rect2;
	SetRect( &rect, x, y, x, y );
	SetRect( &rect2, x - 0.1, y + 0.2, x - 0.1, y + 0. );
	pFont->DrawTextA(NULL,text,-1,&rect2, ST, 0x00000000 );
	pFont->DrawTextA(NULL,text,-1,&rect,  ST, color );
}

void FillRGB( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice )
{
	D3DRECT rec = { x, y, x + w, y + h };
	pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}

void  Box(int x, int y, int w, int h,   D3DCOLOR Color, LPDIRECT3DDEVICE9 pD3D9)
{

struct Vertex 
{
	float x,y,z,ht;
	DWORD Color;
}
V[4] ={{x,y+h, 0.0f, 0.0f, Color}, {x,y, 0.0f, 0.0f, Color},{x+w,y+h, 0.0f, 0.0f, Color},{x+w,y, 0.0f, 0.0f, Color}};

 pD3D9->SetTexture(0, NULL);
 pD3D9->SetPixelShader( 0 );
 pD3D9->SetFVF(D3DFVF_XYZRHW|D3DFVF_DIFFUSE);
 pD3D9->SetRenderState(D3DRS_ALPHABLENDENABLE,true);
 pD3D9->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);
 pD3D9->SetRenderState(D3DRS_ZENABLE , FALSE);
 pD3D9->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
 pD3D9->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,V,sizeof(Vertex));
 return;
 

}

void  Border(int x, int y, int w, int h,int s, D3DCOLOR Color, LPDIRECT3DDEVICE9 pD3D9)
{
	Box(x-s,  y, s,  h,Color,pD3D9);
	Box(x-s,y+h, w+s*2,  s,Color,pD3D9);
	Box(x-s,  y-s, w+s*2,  s,Color,pD3D9);
	Box(x+w,y, s,h+s,Color,pD3D9);
}

void  Line(long Xa,long Ya,long Xb,long Yb,int Width,D3DCOLOR Color)
{	
	D3DXVECTOR2 vLine[ 2 ];
	pLine->SetAntialias( 0 );
	pLine->SetWidth(Width);
	pLine->Begin();
		vLine[ 0 ][ 0 ] = Xa;
		vLine[ 0 ][ 1 ] = Ya;
		vLine[ 1 ][ 0 ] = Xb;
		vLine[ 1 ][ 1 ] = Yb;
	pLine->Draw( vLine, 2, Color );
	pLine->End();
}

void GradientV1(int x,int y,int w,int h,DWORD HColor,DWORD CColor1,DWORD CColor2,LPDIRECT3DDEVICE9 pD3D9)
{
struct sVertex{float x, y, z, RHW;DWORD color;};

sVertex Veri[4] =
{{(float)x,(float)y, 0.0f, 0.0f, (HColor+CColor1)},
{(float)(x+w),(float)y, 0.0f, 0.0f, (HColor+CColor2)},
{(float)x,(float)(y+(h)), 0.0f, 0.0f, (CColor1)},
{(float)(x+w),(float)(y+(h)), 0.0f, 0.0f, (CColor1)}};

pD3D9->SetRenderState( D3DRS_ZENABLE, D3DZB_FALSE );
pD3D9->SetRenderState( D3DRS_FOGENABLE, false );
pD3D9->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE );
pD3D9->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,4,Veri,sizeof(sVertex));
}

void GradientV2(int x,int y,int w,int h,DWORD HColor,DWORD CColor1,DWORD CColor2,LPDIRECT3DDEVICE9 pD3D9)
{
struct sVertex{float x, y, z, RHW;DWORD color;};

sVertex Veri[6] =
	    {
        {(float)x		,(float)y		, 0.0f, 0.0f, (HColor-CColor1)},
		{(float)(x+w)	,(float)y		, 0.0f, 0.0f, (HColor-CColor2)},
		{(float)x		,(float)(y+(h/2))	, 0.0f, 0.0f, (HColor)},
		{(float)(x+w)	,(float)(y+(h/2))	, 0.0f, 0.0f, (HColor)},	
		{(float)x		,(float)(y+h)	, 0.0f, 0.0f, (HColor+CColor1)},
		{(float)(x+w)	,(float)(y+h)	, 0.0f, 0.0f, (HColor+CColor2)},
		};

pD3D9->SetRenderState( D3DRS_ZENABLE, D3DZB_FALSE );
pD3D9->SetRenderState( D3DRS_FOGENABLE, false );
pD3D9->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE );
pD3D9->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,6,Veri,sizeof(sVertex));
}

void Circle(int X, int Y, int radius, int numSides, DWORD Color)
{
	D3DXVECTOR2 Line[128];
	float Step = PI * 2.0 / numSides;
	int Count = 0;
	for (float a=0; a < PI*2.0; a += Step)
	{
		float X1 = radius * cos(a) + X;
		float Y1 = radius * sin(a) + Y;
		float X2 = radius * cos(a+Step) + X;
		float Y2 = radius * sin(a+Step) + Y;
		Line[Count].x = X1;
		Line[Count].y = Y1;
		Line[Count+1].x = X2;
		Line[Count+1].y = Y2;
		Count += 2;
	}
	pLine->Begin();
	pLine->Draw(Line,Count,Color);
	pLine->End();
}

VOID Xhair(int Size,int Width,D3DCOLOR Color,IDirect3DDevice9* pDevice )
{
	D3DVIEWPORT9 cViewport;
	pDevice->GetViewport(&cViewport); 
    int x = cViewport.Width / 2; 
    int y = cViewport.Height / 2;

	D3DRECT rec = { x - Size, y, x +Size, y + Width};
	D3DRECT rec2 = { x, y - Size, x + Width, y + Size}; 
	pDevice->Clear(1,&rec,D3DCLEAR_TARGET,Color,0,0);
	pDevice->Clear(1,&rec2,D3DCLEAR_TARGET,Color,0,0);
}

void D3D9ScreenShot(IDirect3DDevice9* pDevice) 
{    
	     sprintf(FileName, "Multiplays.org %d.jpg", I); 
         pDevice->GetBackBuffer(0,0,D3DBACKBUFFER_TYPE_MONO,&surf); 
         D3DXSaveSurfaceToFile(FileName,D3DXIFF_JPG,surf,NULL,NULL); 
		 I++;
		 Beep(1000,100);
}

BOOL  IsInBox(int x,int y,int w,int h)
{
	POINT MousePosition; 
	GetCursorPos(&MousePosition); 
	ScreenToClient(GetForegroundWindow(),&MousePosition);
	return(MousePosition.x >= x && MousePosition.x <= x + w && MousePosition.y >= y && MousePosition.y <= y + h);
}

void ButtonBorder(int x,int y,LPDIRECT3DDEVICE9 pD3D9)
{
	Box(x,y-1,100,1,DARK27,pD3D9);
	Box(x+1,y-1,98,1,DARK17,pD3D9);

	Box(x,y+20,100,1,DARK27,pD3D9);
	Box(x+1,y+20,98,1,DARK17,pD3D9);

	Box(x-1,y,1,20,DARK27,pD3D9);
	Box(x-1,y+1,1,18,DARK17,pD3D9);

	Box(x+100,y,1,20,DARK27,pD3D9);
	Box(x+100,y+1,1,18,DARK17,pD3D9);
	Border(x, y, 99, 19,1, DARK37,pD3D9);
}