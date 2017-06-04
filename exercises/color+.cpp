#include <windows.h>        
#include <stdio.h>
void SetColor(unsigned short ForeColor=0,unsigned short BackGroundColor=0)                                                                                                           //可以接受0/1/2个参数
{
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);    
SetConsoleTextAttribute(hCon,ForeColor|BackGroundColor);
}
int main(){
	
	SetColor(1,0);printf("Hello world!\n");
	SetColor(2,0);printf("Hello world!\n");
	SetColor(3,0);printf("Hello world!\n");
	SetColor(4,0);printf("Hello world!\n");
	SetColor(5,0);printf("Hello world!\n");
	SetColor(6,0);printf("Hello world!\n\n\n");
	

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY| FOREGROUND_BLUE |BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE);
	printf("Hello world!\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY| FOREGROUND_GREEN |BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE);
	printf("Hello world!\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY| FOREGROUND_RED |BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE);
	printf("Hello world!\n");
	
	SetColor(7,0);
	return 0;
}
