#include "GameClass.h"
#include "Color.h"

#pragma warning(disable: 4293)
#pragma warning(disable: 4390)
int priz2 = 0;
#define VK_Y 0x59
#define VK_B 0x42
#define VK_V 0x56
#define VK_Q 0x51
#define VK_N 0x4E
#define VK_C 0x43
#define VK_X 0x58
#define VK_CONTROL 0x11
#define VK_CAPITAL 0x14

DWORD Color_ESP;
DWORD Mycolor_ESP;

class SSystemGlobalEnvironment
{
public:
	//1502A0C aM_prenderer0
	//15045CC aG_pgameGetsync
	char _0x0000[60];
	IRenderer * GetIRenderer; //0x003C 
	char _0x0040[32];
	IGame* GetIGame; //0x0060 
};//Size=0x0080

SSystemGlobalEnvironment* GetSSystemGlobalEnvironment()
{
	DWORD A_SSystemGlobalEnvironment = *(DWORD*) 0x15AB720;//"*** Memory allocation for %u bytes fail"  //15A03A0
	SSystemGlobalEnvironment* m_SSystemGlobalEnvironment = NULL;
	if (A_SSystemGlobalEnvironment)
	{
		m_SSystemGlobalEnvironment = (SSystemGlobalEnvironment*) (A_SSystemGlobalEnvironment);
	}
	return m_SSystemGlobalEnvironment;
}

IActorSystem* GetIActorSystem()
{
	IActorSystem* m_IActorSystem = NULL;
	if (GetSSystemGlobalEnvironment()->GetIGame->getIGameFramework->GetIActorSystem())
	{
		m_IActorSystem = GetSSystemGlobalEnvironment()->GetIGame->getIGameFramework->GetIActorSystem();
	}
	return m_IActorSystem;
}

IActor* GetClientActor()
{
	if (!GetSSystemGlobalEnvironment()->GetIGame)
	{
		return 0;
	}

	if (!GetSSystemGlobalEnvironment()->GetIGame->getIGameFramework)
	{
		return 0;
	}
	return GetSSystemGlobalEnvironment()->GetIGame->getIGameFramework->GetClientActor();
}

IActor* GetIMyIActor()
{
	IActor* m_IActor = NULL;
	if (GetSSystemGlobalEnvironment()->GetIGame->getIGameFramework->GetClientActor())
	{
		m_IActor = GetSSystemGlobalEnvironment()->GetIGame->getIGameFramework->GetClientActor();
	}
	return GetSSystemGlobalEnvironment()->GetIGame->getIGameFramework->GetClientActor();
}



//{
//IWeapon* m_IWeapon = NULL;
//if(GetSSystemGlobalEnvironment()->GetIGame->getIGameFramework->GetClientActor())
//m_IWeapon = GetSSystemGlobalEnvironment()->GetIGame->getIGameFramework->GetClientActor();
//return m_IWeapon;
//}

IGameRules* GetIGameRules()
{
	IGameRules* m_IGameRules = NULL;
	SSystemGlobalEnvironment* m_SSystemGlobalEnvironment = GetSSystemGlobalEnvironment();
	m_IGameRules = m_SSystemGlobalEnvironment->GetIGame->getIGameFramework->GetIGameRulesSystem()->GetCurrentGameRules();
	if (m_IGameRules) 
	{
		return m_IGameRules;
	}
	else 
	{
		return m_IGameRules;
	}
}

int GetTeam(IEntity* m_IEntity)
{
	SSystemGlobalEnvironment* m_SSystemGlobalEnvironment = GetSSystemGlobalEnvironment();
	if (m_IEntity && GetIGameRules())
	{
		return GetIGameRules()->GetTeam(m_IEntity->GetId());
	}
	else return 0;
}

int cvetchar1;//цвет ботов
int cvetchar2;//синих
int cvetchar3;//красных

int vrag = 0;
int vragi = 0;

int boxer;//это кого показывать
/*
DWORD GetColorForTeam(IEntity* m_IEntity, int Mode)
{
DWORD Color;



if(Mode == 1)
{
int Team = GetTeam(m_IEntity);
if(boxer==0||boxer==4)
{
if(Team == 0)
Color = cvetchar1;//SKYBLUE;
else if(Team == 1)
Color = cvetchar2;//BLUE;
else if(Team == 2)
Color = cvetchar3;//RED;
}

if(boxer==1)
{
if(Team == 0)
Color = cvetchar1;//SKYBLUE;
else if(Team == 1)
Color = 0;//BLUE;
else if(Team == 2)
Color = 0;//RED;
}

if(boxer==2)
{
if(Team == 0)
Color = 0;//SKYBLUE;
else if(Team == 1)
Color = cvetchar2;//BLUE;
else if(Team == 2)
Color = 0;//RED;
}
if(boxer==3)
{
if(Team == 0)
Color = 0;//SKYBLUE;
else if(Team == 1)
Color = 0;//BLUE;
else if(Team == 2)
Color = cvetchar3;//RED;
}
if(Team == 0)
vrag=1;
else if(Team == 1)
vrag=2;
else if(Team == 2)
vrag=3;


}
return Color;
}*/
DWORD GetColorForTeam(IEntity* m_IEntity, int Mode)
{
	DWORD Color;



	if (Mode == 1)
	{
		int Team = GetTeam(m_IEntity);
		if (Fun.все == 0)
		{
			if (Team == 0)
				Color = PURPLE(255);//SKYBLUE;
			else if (Team == 1)
				Color = BLUE(255);//BLUE;
			else if (Team == 2)
				Color = RED(255);//RED;
		}

		if (Fun.все == 1)
		{
			if (Team == 0)
				Color = PURPLE(255);//SKYBLUE;
			else if (Team == 1)
				Color = 0;//BLUE;
			else if (Team == 2)
				Color = 0;//RED;
		}

		if (Fun.свои == 2)
		{
			if (Team == 0)
				Color = 0;//SKYBLUE;
			else if (Team == 1)
				Color = BLUE(255);//BLUE;
			else if (Team == 2)
				Color = 0;//RED;
		}
		if (Fun.противник == 3)
		{
			if (Team == 0)
				Color = 0;//SKYBLUE;
			else if (Team == 1)
				Color = 0;//BLUE;
			else if (Team == 2)
				Color = RED(255);//RED;
		}
		if (Team == 0)
			vrag = 1;
		else if (Team == 1)
			vrag = 2;
		else if (Team == 2)
			vrag = 3;


	}
	return Color;
}
bool GetDeadPlayer(IActor* Player)
{
	if (Player->IsDead())return true;
	else return false;
}

float CalcDistance(D3DXVECTOR3 PosA, D3DXVECTOR3 PosB)
{
	float Dx = PosA.x - PosB.x;
	float Dy = PosA.y - PosB.y;
	float Dz = PosA.z - PosB.z;
	return sqrt(Dx*Dx + Dy*Dy + Dz*Dz);
}


D3DXVECTOR3 W2S(D3DXVECTOR3 vEntPos)
{
	SSystemGlobalEnvironment* m_SSystemGlobalEnvironment = GetSSystemGlobalEnvironment();
	IRenderer* Renderer = m_SSystemGlobalEnvironment->GetIRenderer;

	float x, y, z = 0.0f;

	Renderer->ProjectToScreen(vEntPos.x, vEntPos.y, vEntPos.z, &x, &y, &z);

	x *= (Renderer->GetWidth() / 100.0f);
	y *= (Renderer->GetHeight() / 100.0f);
	z *= 1.0f;

	D3DXVECTOR3 post = D3DXVECTOR3(0, 0, 0);
	post.x = x;
	post.y = y;
	post.z = z;

	return (post);
}

bool WorldToScreen(D3DXVECTOR3 Pos, D3DXVECTOR3 &Out)
{
	SSystemGlobalEnvironment* m_SSystemGlobalEnvironment = GetSSystemGlobalEnvironment();
	IRenderer* Renderer = m_SSystemGlobalEnvironment->GetIRenderer;
	Renderer->ProjectToScreen(Pos.x, Pos.y, Pos.z, &Out.x, &Out.y, &Out.z);

	if (Out.z < 0.0f || Out.z > 1.0f) 
	{
		return 0;
	}

	Out.x *= (Renderer->GetWidth() / 100.0f);
	Out.y *= (Renderer->GetHeight() / 100.0f);
	Out.z *= 1.0f;

	return ((Out.z < 1.0f));
}

bool WorldToScreenD3DXVECTOR3(D3DXVECTOR3 Pos, D3DXVECTOR3 &Out)
{
	SSystemGlobalEnvironment* m_SSystemGlobalEnvironment = GetSSystemGlobalEnvironment();
	IRenderer* Renderer = m_SSystemGlobalEnvironment->GetIRenderer;
	Renderer->ProjectToScreen(Pos.x, Pos.y, Pos.z, &Out.x, &Out.y, &Out.z);

	if (Out.z < 0.0f || Out.z > 1.0f) 
	{
		return 0;
	}
	Out.x *= (Renderer->GetWidth() / 100.0f);
	Out.y *= (Renderer->GetHeight() / 100.0f);
	Out.z *= 1.0f;



	return ((Out.z < 1.0f));
}

void DrawBox_2(FLOAT x, FLOAT y, FLOAT w, FLOAT h, D3DCOLOR Color, LPDIRECT3DDEVICE9 pDevice)
{
	D3DRECT rec = { x, y - h, x + w, y };
	pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	pDevice->Clear(1, &rec, D3DCLEAR_TARGET, Color, 0, 0);
}

void DrawBorder_2(int x, int y, int w, int h, int o, D3DCOLOR color, LPDIRECT3DDEVICE9 pDevice)
{

	DrawBox_2(x, y, w, 2, color, pDevice);
	DrawBox_2(x - 1, y, 2, h, color, pDevice);
	DrawBox_2(x - 1, y - h, w + 2 + 1, 2, color, pDevice);
	DrawBox_2(x + w, y, 2, h, color, pDevice);
}

void Draw_ESP_Border(int X, int Y, float Distance_Player, DWORD Color, LPDIRECT3DDEVICE9 pDevice)
{
	float drawW = 600 / Distance_Player;
	float drawH = 1400 / Distance_Player;

	DrawBorder_2(X - drawW / 2, Y, drawW, drawH, 2, Color, pDevice);
}

void DrawString(float x, float y, DWORD color, const char *fmt, ...)
{
	RECT FontPos = { x, y, x + 20, y + 10 };
	char buf[1024] = { '\0' };
	va_list va_alist;
	va_start(va_alist, fmt);
	vsprintf(buf, fmt, va_alist);
	va_end(va_alist);
	pFont->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}

void ESP(LPDIRECT3DDEVICE9 pDevice, LPD3DXFONT pFont)// LPD3DXFONT pFont
{
	D3DVIEWPORT9 viewP;
	pDevice->GetViewport(&viewP);
	DWORD ScreenCenterX = viewP.Width / 2;
	DWORD ScreenCenterY = viewP.Height / 2;
	D3DXVECTOR3 Screen;
	//D3DXVECTOR3 Screen;
	D3DXVECTOR3 Screen_2;
	D3DXVECTOR3 HeadPos;
	SSystemGlobalEnvironment* m_SSystemGlobalEnvironment = GetSSystemGlobalEnvironment();
	IRenderer* Renderer = m_SSystemGlobalEnvironment->GetIRenderer;
	if (m_SSystemGlobalEnvironment && GetSSystemGlobalEnvironment()->GetIGame->getIGameFramework->GetIActorSystem())
	{
		IActor* MyActor = GetIMyIActor();
		if (MyActor)
		{
			int myid = MyActor->getEntityId;
			IActorIteratorPtr m_IActorIterator = GetSSystemGlobalEnvironment()->GetIGame->getIGameFramework->GetIActorSystem()->CreateActorIterator();
			if (m_IActorIterator.get()->Count() != myid)
				for (; IActor* Player = m_IActorIterator.get()->Next();)
				{
					D3DXVECTOR3 PlayerPos = Player->getIEntity->GetWorldPos();
					D3DXVECTOR3 MyPos = MyActor->getIEntity->GetWorldPos();

					IEntity *pEntity = Player->getIEntity;
					{
						if ((Player->IsDead() == false) && (Player->getEntityId != myid))
						{
							int Team = GetTeam(pEntity);

							Color_ESP = GetColorForTeam(Player->getIEntity, 1);
							Mycolor_ESP = GetColorForTeam(MyActor->getIEntity, 1);

							float Distance = CalcDistance(PlayerPos, MyPos);

							if (WorldToScreen(PlayerPos, Screen))
							{

								if ((Color_ESP != Mycolor_ESP) || (vrag == 1)){ vragi = 1; }
								else{ vragi = 0; }
								//if((все==0)||(все==1)||(свои==2)||(противник==3))vragi=1;
								if (Fun.кубик)
								{
									if ((Fun.все == 0) || (Fun.все == 1))vragi = 1;
									Draw_ESP_Border(Screen.x, Screen.y, Distance, Color_ESP, pDevice);
									//Border(Screen.x, Screen.y, 20,30,1,Color_ESP, pDevice);
								}
								if ((vragi > 0)&(Color_ESP > 0)){
									if (Fun.противник)
									{
										if ((Fun.противник == 3) || (Fun.свои == 1))vragi = 1;
										Draw_ESP_Border(Screen.x, Screen.y, Distance, Color_ESP, pDevice);
									}
								}
								if (Fun.цветбв)
								{
									Draw_ESP_Border(Screen.x, Screen.y, Distance, Color_ESP, pDevice);
								}
								if (Fun.цветф)
								{
									Draw_ESP_Border(Screen.x, Screen.y, Distance, Color_ESP, pDevice);
								}
								/*if (Fun.кубик3д)
								{
									if ((Fun.все == 0) || (Fun.все == 1))vragi = 1;
									Draw_ESP3D_Border(Screen_2.x, Screen_2.y, Screen.x, Screen.y, Distance, RED(255));
								}
								if (Fun.линии)
								{
									Line(ScreenCenterX, ScreenCenterY, Screen.x, Screen.y, 1, BLUE(255));
								}*/
								if (Fun.дистанция)
								{
									DrawString(Screen.x, Screen.y, GREEN(255), "[%.0f] m ", Distance);
								}
							}

						}
					}
				}
		}
	}
}
//}