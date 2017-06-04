#include <stdio.h>
#include <windows.h>
int main(){
	
    HANDLE consolehwnd;
  	consolehwnd=GetStdHandle(STD_OUTPUT_HANDLE);
  	SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY |FOREGROUND_BLUE|FOREGROUND_BLUE);
	printf("Hello world!\n");
	SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY |FOREGROUND_GREEN|FOREGROUND_GREEN);
	printf("Hello world!\n");
	SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY |FOREGROUND_GREEN|FOREGROUND_BLUE);
	printf("Hello world!\n");
	SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY |FOREGROUND_RED|FOREGROUND_RED);
	printf("Hello world!\n");
	SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY |FOREGROUND_RED|FOREGROUND_BLUE);
	printf("Hello world!\n");
	SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY |FOREGROUND_RED|FOREGROUND_GREEN);
	printf("Hello world!\n\n\n");
	
	
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY| FOREGROUND_BLUE |BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE);
	printf("Hello world!\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY| FOREGROUND_GREEN |BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE);
	printf("Hello world!\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY| FOREGROUND_RED |BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE);
	printf("Hello world!\n");
	
	getchar();
	return 0; 
}
