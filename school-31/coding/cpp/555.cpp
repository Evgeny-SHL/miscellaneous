#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int used[1000];
int start;
int len;
int si;//размер матрицы любви
int max;
int i,j,k;
int a[1000][1000];//матрица любви
int prev[1000];
void moodfs(int v, int* used, int papa) {
//	printf("%d %d\n", v, papa);
	used[v] = 1;
	if (v == start && papa != -1) {
		if (len > max) {
			max = len;
		}
		return;
	}
	bool atata;
	for (int u = 0; u < si; ++u) {
        atata = false;
    //    printf("%d -> %d\n", v, u);
		if (a[v][u] == 1 && (used[u] == 0 || (u == start)) && a[u][u] == 0) {
            for (int w = 0; w < si; ++w) {
            //    printf("to %d %d %d %d %d\n", w, used[w], a[w][u], a[u][v], start);
                if (used[w] == 1 && ((a[w][u] == 1 && papa != -1 && w != v) || (a[u][w] == 1 && w != start && u != start))) {
                    atata = true;
                    break;
                }
            }
            if (atata) {
                continue;
            }
         //   printf("%d -> %d OK\n", v, u);
			used[u] = 1;
			++len;
			moodfs(u, used, v);
			if (u != start) {
                used[u] = 0;
			}
			--len;
		}
	}
	used[v] = 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
	long b[1000];
	long c[1000];
	long d[1000];//люди
	int m;
	int fl1,fl2;//флаги
	long kol,askk;
	char ch;
	scanf("%d",&m);
	scanf("%c",&ch);
	kol = 0;
	for(i = 0;i < m;i++)
	{
		ch = '#';
		while((ch != ' ') && (ch != '\n'))
		{
			scanf("%c",&ch);
			if ((ch != ' ') && (ch != '\n'))
			{
				askk = (int)ch;
				kol = kol + askk * askk;
			}
		}
		b[i] = kol;
		ch = '#';
		kol = 0;
			printf("[[");
		while((ch != ' ') && (ch != '\n'))
		{
		    	printf("[[");
			scanf("%c",&ch);
			if ((ch != ' ') && (ch != '\n'))
			{
				askk = (int)ch;
				kol = kol + askk * askk;
			}
		}
		c[i] = kol;
		kol = 0;
	}
	printf("[[");
	kol = 0;
	for(i = 0;i < m;i++)
	{
		fl1 = 1;
		fl2 = 1;
		for(j = 0;j < kol;j++)
		{
			if (d[j] == b[i]) fl1 = 0;
			if (d[j] == c[i]) fl2 = 0;
		}
		if (fl1 == 1)
		{
			d[kol] = b[i];
			kol++;
		}
		if (fl2 == 1)
		{
			d[kol] = c[i];
			kol++;
		}
	}
	si = kol;
	for(i = 0;i < si;i++)
	for(j = 0;j < si;j++)
	a[i][j] = 0;
	for(i = 0;i < si;i++)
	for(j = 0;j < si;j++)
	for(k = 0;k < m;k++)
	{
		if ((b[k] == d[i]) && (c[k] == d[j])) a[i][j] = 1;
	}
	for(i = 0;i < si;i++)
	{
	//	for(j = 0;j < si;j++) printf("%d ",a[i][j]);
	//	printf("\n");
	}
	for(j = 0;j < si;j++) used[j] = 0;
	max = 2;
	for(i = 0;i < si; i++)
	{
	    if (a[i][i] == 1) {
            continue;
	    }
    //    i = 6;
		start = i;
		len = 0;
	//	for (int j = 0; j < si; ++j) {
   //         printf("%d", used[j]);
	//	}
	//	printf("\n");
		moodfs(i,used, -1);

	}
	if (max > 2) printf("%d",max);
	else printf("0");
	return 0;
}
