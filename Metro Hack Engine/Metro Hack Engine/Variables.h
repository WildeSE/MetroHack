typedef HRESULT (WINAPI* oDrawIndexedPrimitive)(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE Type, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount);
typedef HRESULT (WINAPI* oPresent)(LPDIRECT3DDEVICE9 pDevice, CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion);
typedef HRESULT (WINAPI* oReset)(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
typedef HRESULT (WINAPI* oQuery)(LPDIRECT3DDEVICE9 pDevice,D3DQUERYTYPE Type,IDirect3DQuery9** ppQuery);
typedef HRESULT	(WINAPI* oEndScene)(LPDIRECT3DDEVICE9 pDevice);

oQuery pQuery;
oReset pReset;
oPresent pPresent;
oDrawIndexedPrimitive pDrawIndexedPrimitive;
oEndScene pEndScene;

bool Color = true;
BOOL Create;      //Создаем все содержимое
bool hExitThread; //Выключаем сеанс
bool Show = true;//Показ меню
int x,y,w,h;      //Координаты для элементов
POINT  mofs;      //Мышка			
POINT  mpos;      //Мышка
int	lm /*Левая Кнопка одно нажатие*/   ,rm/*Правая Кнопка одно нажатие*/   ,
flm/*Левая Кнопка быстр. нажатие*/,frm/*Правая Кнопка быстр. нажатие*/;
//LPDIRECT3DDEVICE9 pDev;//D3D9 Девайс
LPDIRECT3DDEVICE9 pD3D9;    //D3D9 Девайс pD3D9
IDirect3DDevice9* pDevice;  //D3D9 Девайс pDevice
ID3DXFont*  pFont;          //D3D9 Девайс pFont
LPD3DXLINE  pLine;          //D3D9 Девайс pLine
D3DVIEWPORT9 viewP;         //D3D9 Девайс viewP
//LPDIRECT3DTEXTURE9 White,Red,Green,Blue,Purple,Yellow, DeepPinks, DeepSkyBlues;
char FileName[1024]; 
LPDIRECT3DSURFACE9 surf;   //D3D9 Девайс 
int I;
#define CText (DT_CENTER|DT_NOCLIP)//Текст "Центр"
#define LText (DT_LEFT|DT_NOCLIP) //Текст "Лего"
#define RText (DT_RIGHT|DT_NOCLIP)//Текст "Праго"
#define PI 3.14159265//Число ПИ
float A1,A2,A3,A4;   //Анимация

//========== Переменные волуе ==========//
char *volue  [] = { "0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40"};
char *antime [] = {"0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1"};



//========== Переменные функций ==========//
class cFun
{
public:
int Test1,Test2,Test3,Test4,Test5,Test6,Test7,Test8,Test9,Test10;
int Test11,Test12,Test13,Test14,Test15,Test16;

int Close,HideM;
int Vspomog, Settings;
int FPS,Time,Date,Exit,MoveMenu,CloseMenu,HideMenu;
int Test21,Test22,Test23,Test24,Test25,Test26,Test27,Test28,Test29,Test30,Test31,Test32,Test33,Test34,Test35,Test36,Test37,Test38;

int WalHack;
				int chamsWF;
				int chamsBW;
				int wireframe;
				int cross;
				int ЧампГоловы;
				int ЧампсОружие;
				int Bomb;
				int Mine;
				int crossik;
				int оружие;
				int donat;
				int ESPGM;
			int нетрук;
			int noAFK;
			int pause;
			int прицел;
			int мусор;
			int оружка;
			int angar;
			int floor;

			int NoRecoil,CasperMod,PodKartu,Gravitation,SpeedKnife,Smena,Vinos,KnifePKM,VertFire;

			int свои,противник,все,кубик,кубик3д,дистанция,цветф,цветбв;
};
extern cFun Fun;