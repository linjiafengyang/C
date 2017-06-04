#include<windows.h>        
#include<stdio.h>
void SetColor(unsigned short ForeColor=0,unsigned short BackGroundColor=0)                                                                              
{
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);    
SetConsoleTextAttribute(hCon,ForeColor|BackGroundColor);
}
int main()
{
SetColor(9,0);printf("Hello world!\n");
SetColor(10,0);printf("Hello world!\n");
SetColor(11,0);printf("Hello world!\n");
SetColor(12,0);printf("Hello world!\n");
SetColor(13,0);printf("Hello world!\n");
SetColor(14,0);printf("Hello world!\n");
SetColor(7,0);
}
