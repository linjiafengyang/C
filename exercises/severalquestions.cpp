#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
	//开灯问题
	int n, k;
	int a[100];
	scanf("%d%d", &n, &k);
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= k; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (j % i == 0)
			{
				a[j] = !a[j];
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (a[i])
		{
			printf("%d\n", i);
		}
	}

	//蛇形填数
	int n1, x, y, t = 0;
	scanf("%d", &n1);
	int b[10][10];
	memset(b, 0, sizeof(b));
	t = b[x = 0][y = n1 - 1] = 1;
	while(t < n1 * n1) {
		while(x + 1 < n1 && !b[x + 1][y]) {
			b[++x][y] = ++t;
		}
		while(y - 1 >= 0 && !b[x][y - 1]) {
			b[x][--y] = ++t;
		}
		while(x - 1 >= 0 && !b[x - 1][y]) {
			b[--x][y] = ++t;
		}
		while(y + 1 < n1 && !b[x][y + 1]) {
			b[x][++y] = ++t;
		}
	}
	for (x = 0; x < n1; ++x)
	{
		for (y = 0; y < n1; ++y) {
			printf("%3d", b[x][y]);
		}
		printf("\n");
	}

	//竖式问题
	int i, ok, abc, de, x1, y1, z1, count = 0;
	char s[20], buf[99];
	scanf("%s", s);
	for (abc = 111; abc <= 999; abc++) {
		for (de = 11; de <= 99; de++) {
			x1 = abc * (de % 10);
			y1 = abc * (de / 10);
			z1 = abc * de;
			sprintf(buf, "%d%d%d%d%d", abc, de, x1, y1, z1);
			ok = 1;
			for (i = 0; i < strlen(buf); i++) {
				if (strchr(s, buf[i]) == NULL)
				{
					ok = 0;
				}
			}
			if (ok)
			{
				printf("<%d>\n", ++count);
				printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n", abc, de, x1, y1, z1);
			}
		}
	}
	printf("The number of sulotions = %d\n", count);

	//最长回文子串
	int m = 0, max = 0, x2, y2;
	char buf1[5010], s1[5010];
	int p[5010];
	scanf("%s", buf1);
	for (int i = 0; i < strlen(buf1); ++i)
	{
		if (isalpha(buf1[i]))
		{
			p[m] = i;
			s1[m++] = toupper(buf1[i]);
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; i - j >= 0 && i + j < m; ++j)
		{
			if (s1[i - j] != s1[i + j])
			{
				break;
			}
			if (j * 2 + 1 > max)
			{
				max = j * 2 + 1;
				x2 = p[i - j];
				y2 = p[i + j];
			}
		}
		for (int j = 0; i - j >= 0 && i - j + 1 < m; ++j)
		{
			if (s1[i - j] != s1[i - j + 1])
			{
				break;
			}
			if (j * 2 + 2 > max)
			{
				max = j * 2 + 2;
				x2 = p[i - j];
				y2 = p[i + j + 1];
			}
		}
	}
	for (int i = x2; i <= y2; i++) {
		printf("%c", buf1[i]);
	}
	printf("\n");
	return 0;
}