#include <stdio.h>
main()
{
    int n,i,j;
    scanf( "%d", &n );
    for ( i=0; i<n; i++ )
    {
        for ( j=0; j<n-1-i; j++ )
            printf( " " );
        for ( j=0; j<=i; j++ )
            printf( "@" );
        printf( "\n" );
    }
    for ( i=0; i<n-1; i++ )
    {
        for ( j=0; j<n-1-i; j++ )
            printf( "@" );
        printf( "\n" );
    }
} 
/*输入：
     5
则输出（□表示空格，↙表示回车）：
     □□□□＠↙
     □□□＠＠↙
     □□＠＠＠↙
     □＠＠＠＠↙
     ＠＠＠＠＠↙
     ＠＠＠＠↙
     ＠＠＠↙
     ＠＠↙
     ＠↙
示例说明：输出共9行（2*n-1行），每行最多5列（n列）。  */
