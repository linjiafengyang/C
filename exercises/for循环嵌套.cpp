#include <stdio.h>
main()
{
    int n,i,j;
    scanf( "%d", &n );
    for ( i=0; i<n; i++ )
    {
        for ( j=0; j<=i; j++ )
            printf( "#" );
        for ( j=0; j<2*(n-i-1)-1; j++ )
            printf( " " );
        if ( i<n-1 )
            for ( j=0; j<=i; j++ )
                printf( "#" );
        else
            for ( j=0; j<i; j++ )
                printf( "#" );
        printf( "\n" );
    }
}
/*输入：
     5
则输出（□表示空格，↙表示回车）：
     ＃□□□□□□□＃↙
     ＃＃□□□□□＃＃↙
     ＃＃＃□□□＃＃＃↙
     ＃＃＃＃□＃＃＃＃↙
     ＃＃＃＃＃＃＃＃＃↙
示例说明：输出共5行（n行），每行9列（2*n-1列）。  */
