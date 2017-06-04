#include <stdio.h>
main()
{
    int n,i,j;
    long a[100], t;
    int b[100];
    scanf( "%d", &n );
    for ( i=0; i<n; i++ )
        scanf( "%ld%d", &a[i], &b[i] );
    for ( i=0; i<n-1; i++ )
        for ( j=0; j<n-1-i; j++ )
            if ( (b[j] < b[j+1]) ||
                 (b[j]==b[j+1] && a[j]>a[j+1]) )
            {
                t=b[j]; b[j]=b[j+1]; b[j+1]=t;
                t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
    for ( i=0; i<n; i++ )
        printf( "%ld %d\n", a[i], b[i] );
    printf( "\n" );
} 
/*ÊäÈë£º
     4   20103 78   20107 80   20105 90   20104   80
ÔòÊä³ö£º
     20105   90
     20104   80
     20107   80
     20103   78*/
