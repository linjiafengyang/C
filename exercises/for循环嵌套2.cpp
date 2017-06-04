#include <stdio.h>
main()
{
    int n,i,j;
    scanf( "%d", &n );
    for ( i=0; i<n; i++ )
    {
        for ( j=0; j<i; j++ )
            printf( " " );
        for ( j=0; j<2*n-1; j++ )
            if ( j==2*(n-1-i) )
                printf( "#" );
            else
                printf( "*" );
        printf( "\n" );
    }
}
/*输入：
     5
则输出（□表示空格，↙表示回车）：
     ××××××××＃↙
     □××××××＃××↙
     □□××××＃××××↙
     □□□××＃××××××↙
     □□□□＃××××××××↙    */
