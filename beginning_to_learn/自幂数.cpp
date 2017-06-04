#include<stdio.h>
int main()
{
    int a,b,c;//分别为百位、十位、个位数
    int d,e,f;//分别为十万位、万位、千位 
    int n;
    scanf("%d", &n);
    switch(n) {
    	case 3:
    		for(a=1;a<10;a++) {
       			for(b=0;b<10;b++) {
           			for(c=0;c<10;c++) {
               			if(a*100+b*10+c==a*a*a+b*b*b+c*c*c) {
                   			printf("%d%d%d\n", a, b, c); 
               			}
           			}
       			}
    		}
    		break;
    	case 4:
    		for(f=1;f<10;f++){
    			for(a=0;a<10;a++){
    				for(b=0;b<10;b++){
    					for(c=0;c<10;c++){
    						if(f*1000+a*100+b*10+c==f*f*f*f+a*a*a*a+b*b*b*b+c*c*c*c){
    							printf("%d%d%d%d\n", f, a, b, c);
							}
						}
					}
				}
			}
			break;
		case 5:
			for(e=1;e<10;e++){
				for(f=0;f<10;f++){
    				for(a=0;a<10;a++){
    					for(b=0;b<10;b++){
    						for(c=0;c<10;c++){
    							if(e*10000+f*1000+a*100+b*10+c==e*e*e*e*e+f*f*f*f*f+a*a*a*a*a+b*b*b*b*b+c*c*c*c*c){
    								printf("%d%d%d%d%d\n", e, f, a, b, c);
								}
							}
						}
					}
				}
			}
			break;
			case 6:
				for(d=1;d<10;d++){
					for(e=0;e<10;e++){
						for(f=0;f<10;f++){
    						for(a=0;a<10;a++){
    							for(b=0;b<10;b++){
    								for(c=0;c<10;c++){
    									if(d*100000+e*10000+f*1000+a*100+b*10+c==d*d*d*d*d*d+e*e*e*e*e*e+f*f*f*f*f*f+a*a*a*a*a*a+b*b*b*b*b*b+c*c*c*c*c*c){
    										printf("%d%d%d%d%d%d\n", d, e, f, a, b, c);
										}
									}
								}
							}
						}
					}
				}
				break;
	}
    return 0;
}
