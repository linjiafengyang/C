#include <stdio.h> 
int main(){ 
    
    int a,b,c,d,e,f,g,h,i; 
    
    a=sizeof(short); 
   
	b=sizeof(unsigned short); 
   
	c=sizeof(int); 
   
	d=sizeof(unsigned int); 
    
	e=sizeof(long); 
   
	f=sizeof(unsigned long); 
    
	g=sizeof(float); 
    
	h=sizeof(double); 
   
	i=sizeof(long double); 
   
	printf("%d %d %d %d %d %d %d %d %d",a,b,c,d,e,f,g,h,i); 
   
	return 0; 
}