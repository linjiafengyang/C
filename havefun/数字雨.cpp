#include <Windows.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")

//win32 框架 -（课后）
//数据结构 （重点）
// 

#define NumOfColumn 25  //显示列的列数
// 10 - (月老)  // 974488891
typedef struct charList
{
	struct charList * prev;
	TCHAR ch; //放字符
	struct charList * next;
}CharList;

typedef struct tagCharColumn
{
	struct charList * head, *cur;
	int x,y,iShownLen,iStrNum; //显示字数，字符数
}CharQueue;

struct showChar
{
	TCHAR myChar[60];
	int iNum; //字符个数
}charArr[7]={//,戴望舒的《雨巷》
	{TEXT("撑着油纸伞,独自,彷徨在悠长、悠长又寂寥的雨巷"),23},
	{TEXT("我希望逢着,一个丁香一样地,结着愁怨的姑娘"),21},
	{TEXT("她是有丁香一样的颜色,丁香一样的芬芳,	丁香一样的忧愁,"),28},
	{TEXT("在雨中哀怨,哀怨又彷徨"),11},
	{TEXT("她彷徨在这寂寥的雨巷,撑着油纸伞,像我一样,像我一样地,默默行着,冷漠凄清又惆怅"),40},
	{TEXT("像梦一般地凄婉迷茫.像梦中飘过一枝丁香地,"), 21 },
	{TEXT("她默默地走近走近, 又投出,太息一般的眼光,她飘过像梦一般地"),30} 
}; 

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR szCmdLine,int iCmdShow)
{
	TCHAR szClassName[]=TEXT("数字雨");
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;

	wndclass.style=CS_HREDRAW|CS_VREDRAW;
	wndclass.lpfnWndProc=WndProc;
	wndclass.cbClsExtra=0;
	wndclass.cbWndExtra=0;
	wndclass.hInstance=hInstance;
	wndclass.hIcon=NULL;
	wndclass.hCursor=NULL;
	wndclass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName=NULL;
	wndclass.lpszClassName = szClassName;

	if (!RegisterClass(&wndclass))
	{
		return 0;
	}

	hwnd = CreateWindow(szClassName, NULL, WS_DLGFRAME | WS_THICKFRAME | WS_POPUP, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd,SW_SHOWMAXIMIZED);
	UpdateWindow(hwnd);
	ShowCursor(FALSE);

	srand(time(0));

	//消息机制
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	ShowCursor(TRUE);

	return msg.wParam;
}

void CreateQueue(CharQueue * cc, int cyScreen, int x)
{
	//bug -- 调用API---写接口---ctrl+c/ctrl+v
	CharList * front;

	int NumTemp = rand() % 6;

	cc->x=x;
	cc->y=rand()%10?rand()%cyScreen:0; //大约9/10的概率从中间开始下落。
	cc->iShownLen=1; //一开始就显示一个字符，然后慢慢增加，增加到等于歌词字符数时保持不变
	cc->iStrNum = charArr[NumTemp].iNum; //歌词字符数
	cc->head = cc->cur = front = (CharList *)calloc(cc->iStrNum, sizeof(CharList)); //创建显示列

	//生成每个节点
	int i;
	for (i=0;i<cc->iStrNum-1;i++)
	{
		cc->cur->prev = front;
		cc->cur->ch = charArr[NumTemp].myChar[i];
		front = cc->cur++;
		front->next = cc->cur;
	}

	//最后一个是标点符号
	cc->cur->prev = front;
	cc->cur->ch = charArr[NumTemp].myChar[i];
	cc->cur->next = cc->head;
	cc->head->prev = cc->cur;

	cc->cur = cc->head;
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	static HDC hdcMem;
	static HBITMAP hBitmap;
	static CharQueue * AllChar;
	HFONT hFont;
	static int cxScreen, cyScreen;
	static int iFontWidth=20,iFontHeight=20;
	int i,j,y,greenToblack;
	CharQueue * ccElem;
	CharList * temp;

	switch (message)
	{
	case WM_CREATE:
		cxScreen=GetSystemMetrics(SM_CXSCREEN);
		cyScreen=GetSystemMetrics(SM_CYSCREEN);
		SetTimer(hwnd,1,70,NULL);

		hdc=GetDC(hwnd);
		hdcMem=CreateCompatibleDC(hdc);
		hBitmap=CreateCompatibleBitmap(hdc,cxScreen,cyScreen);
		SelectObject(hdcMem,hBitmap);
		ReleaseDC(hwnd,hdc);

		hFont = CreateFont(iFontHeight, iFontWidth, 0/*角度设置*/, 0/*角度设置*/, FW_BOLD/*黑体*/, 0, 0, 0,/*斜体 下划线 啊、删除线*/
			DEFAULT_CHARSET/*字符集*/, OUT_DEFAULT_PRECIS/*指定输出精度*/, CLIP_DEFAULT_PRECIS/*指定裁剪精度*/,
			DRAFT_QUALITY/*指向输出质量*/, FIXED_PITCH | FF_SWISS/*指定字体间距| 字体族*/, TEXT("宋体"));
		SelectObject(hdcMem,hFont);
		DeleteObject(hFont);		

		SetBkMode(hdcMem,TRANSPARENT);
	
		//PlaySound(L"方圆几里.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//异步循环播放
		AllChar = (CharQueue *)calloc(NumOfColumn, sizeof(CharQueue));//自动初始化为o
		for (i=0;i<NumOfColumn;i++)
		{
			CreateQueue(AllChar + i, cyScreen, 50 * i + 20);
		}
		return 0;

	case WM_TIMER:
		//该函数使用当前选入指定设备环境中的刷子绘制给定的矩形区域。通过使用给出的光栅操作来对该刷子的颜色和表面颜色进行组合。
		PatBlt(hdcMem,0,0,cxScreen,cyScreen,BLACKNESS);

		
		for (i=0;i<NumOfColumn;i++)
		{
			ccElem = AllChar + i;

			temp=ccElem->head;
			SetTextColor(hdcMem,RGB(255,255,255));
			TextOut(hdcMem,ccElem->x,ccElem->y,&temp->ch,1/*字符个数*/);

			y=ccElem->y;
			greenToblack=0;
			ccElem->head=ccElem->head->next;
			temp=temp->prev;

			for (j=1;j<ccElem->iShownLen;j++)
			{
				SetTextColor(hdcMem, RGB(/*greenToblack*5%255*/0, 255 - 255 * (greenToblack++) / (ccElem->iStrNum), 0));
				TextOut(hdcMem,ccElem->x,y-=iFontHeight,&temp->ch,1);
				temp=temp->prev;
			}

			if (ccElem->iShownLen<ccElem->iStrNum)
			{
				ccElem->iShownLen++;
			}

			ccElem->y+=iFontHeight;
			if (ccElem->y-ccElem->iStrNum*iFontHeight>cyScreen)
			{
				free(ccElem->cur);
				CreateQueue(ccElem,cyScreen,128*i+17);
			}

		}
		hdc=GetDC(hwnd);
		BitBlt(hdc,0,0,cxScreen,cyScreen,hdcMem,0,0,SRCCOPY);
		ReleaseDC(hwnd,hdc);
		return 0;

	case WM_RBUTTONDOWN:
		KillTimer(hwnd,1);
		return 0;

	case WM_RBUTTONUP:
		SetTimer(hwnd,1,70,NULL);
		return 0;

	//case WM_LBUTTONDOWN:
	case WM_KEYDOWN:
	case WM_DESTROY:
		KillTimer(hwnd,1);

		for (i=0;i<NumOfColumn;i++)
		{
			ccElem=AllChar+i;
			free(ccElem->cur);
		}
		free(AllChar);

		DeleteObject(hBitmap);
		DeleteDC(hdcMem);
		PostQuitMessage(0);

		break;
	}
	return DefWindowProc(hwnd,message,wParam,lParam);
}
