#include <Windows.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")

//win32 ��� -���κ�
//���ݽṹ ���ص㣩
// 

#define NumOfColumn 25  //��ʾ�е�����
// 10 - (����)  // 974488891
typedef struct charList
{
	struct charList * prev;
	TCHAR ch; //���ַ�
	struct charList * next;
}CharList;

typedef struct tagCharColumn
{
	struct charList * head, *cur;
	int x,y,iShownLen,iStrNum; //��ʾ�������ַ���
}CharQueue;

struct showChar
{
	TCHAR myChar[60];
	int iNum; //�ַ�����
}charArr[7]={//,������ġ����
	{TEXT("������ֽɡ,����,�������Ƴ����Ƴ��ּ��ȵ�����"),23},
	{TEXT("��ϣ������,һ������һ����,���ų�Թ�Ĺ���"),21},
	{TEXT("�����ж���һ������ɫ,����һ���ķҷ�,	����һ�����ǳ�,"),28},
	{TEXT("�����а�Թ,��Թ������"),11},
	{TEXT("������������ȵ�����,������ֽɡ,����һ��,����һ����,ĬĬ����,��Į���������"),40},
	{TEXT("����һ���������ã.������Ʈ��һ֦�����,"), 21 },
	{TEXT("��ĬĬ���߽��߽�, ��Ͷ��,̫Ϣһ����۹�,��Ʈ������һ���"),30} 
}; 

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR szCmdLine,int iCmdShow)
{
	TCHAR szClassName[]=TEXT("������");
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

	//��Ϣ����
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
	//bug -- ����API---д�ӿ�---ctrl+c/ctrl+v
	CharList * front;

	int NumTemp = rand() % 6;

	cc->x=x;
	cc->y=rand()%10?rand()%cyScreen:0; //��Լ9/10�ĸ��ʴ��м俪ʼ���䡣
	cc->iShownLen=1; //һ��ʼ����ʾһ���ַ���Ȼ���������ӣ����ӵ����ڸ���ַ���ʱ���ֲ���
	cc->iStrNum = charArr[NumTemp].iNum; //����ַ���
	cc->head = cc->cur = front = (CharList *)calloc(cc->iStrNum, sizeof(CharList)); //������ʾ��

	//����ÿ���ڵ�
	int i;
	for (i=0;i<cc->iStrNum-1;i++)
	{
		cc->cur->prev = front;
		cc->cur->ch = charArr[NumTemp].myChar[i];
		front = cc->cur++;
		front->next = cc->cur;
	}

	//���һ���Ǳ�����
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

		hFont = CreateFont(iFontHeight, iFontWidth, 0/*�Ƕ�����*/, 0/*�Ƕ�����*/, FW_BOLD/*����*/, 0, 0, 0,/*б�� �»��� ����ɾ����*/
			DEFAULT_CHARSET/*�ַ���*/, OUT_DEFAULT_PRECIS/*ָ���������*/, CLIP_DEFAULT_PRECIS/*ָ���ü�����*/,
			DRAFT_QUALITY/*ָ���������*/, FIXED_PITCH | FF_SWISS/*ָ��������| ������*/, TEXT("����"));
		SelectObject(hdcMem,hFont);
		DeleteObject(hFont);		

		SetBkMode(hdcMem,TRANSPARENT);
	
		//PlaySound(L"��Բ����.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//�첽ѭ������
		AllChar = (CharQueue *)calloc(NumOfColumn, sizeof(CharQueue));//�Զ���ʼ��Ϊo
		for (i=0;i<NumOfColumn;i++)
		{
			CreateQueue(AllChar + i, cyScreen, 50 * i + 20);
		}
		return 0;

	case WM_TIMER:
		//�ú���ʹ�õ�ǰѡ��ָ���豸�����е�ˢ�ӻ��Ƹ����ľ�������ͨ��ʹ�ø����Ĺ�դ�������Ը�ˢ�ӵ���ɫ�ͱ�����ɫ������ϡ�
		PatBlt(hdcMem,0,0,cxScreen,cyScreen,BLACKNESS);

		
		for (i=0;i<NumOfColumn;i++)
		{
			ccElem = AllChar + i;

			temp=ccElem->head;
			SetTextColor(hdcMem,RGB(255,255,255));
			TextOut(hdcMem,ccElem->x,ccElem->y,&temp->ch,1/*�ַ�����*/);

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
