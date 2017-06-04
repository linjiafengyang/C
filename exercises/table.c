#include <stdio.h>
#include <windows.h>
int main(){
	HANDLE consolehwnd;
  	consolehwnd=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY |FOREGROUND_GREEN|FOREGROUND_GREEN);
	
	printf("+-----+-------------+---------------------------+\n");
	printf("|  i  |     i^2     |          i^3              |\n");
	printf("+-----+-------------+---------------------------+\n");
	int i;
	for(i=1;i<=10;i++){ 
	printf("| %2d  |    %3d      |        %4d               |\n",i,i*i,i*i*i);
	}
	printf("+-----+-------------+---------------------------+\n");

	return 0;
}
