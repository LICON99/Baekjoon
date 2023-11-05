#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
char arr[11][11];
char ret[11][11];
int n;
int min = 2147483647, max = 0;
int pmax[2], pmin[2];
int cur;
int find(int i, int j)
{
	int cnt = 0;
	if (i - 1 >= 0 && j - 1 >= 0 && arr[i - 1][j - 1] == '*')
		cnt++;
	if (i - 1 >= 0 && arr[i - 1][j] == '*')
		cnt++;
	if (i - 1 >= 0 && j + 1 < n && arr[i - 1][j + 1] == '*')
		cnt++;
	if (j - 1 >= 0 && arr[i][j - 1] == '*')
		cnt++;
	if (j + 1 < n && arr[i][j + 1] == '*')
		cnt++;
	if (j - 1 >= 0 && i + 1 < n && arr[i + 1][j - 1] == '*')
		cnt++;
	if (i + 1 < n && arr[i + 1][j] == '*')
		cnt++;
	if (i + 1 < n && j + 1 < n && arr[i + 1][j + 1] == '*')
		cnt++;
	return (cnt);
}
void calc_minmax()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] != '*')
			{
				cur = find(i, j);
				ret[i][j] = cur + '0';
			}
			else
			{
				ret[i][j] = arr[i][j];
				continue;
			}
			if (cur > max)
			{
				max = cur;
				pmax[0] = i;
				pmax[1] = j;
			}
			if (cur < min)
			{
				min = cur;
				pmin[0] = i;
				pmin[1] = j;
			}
		}
	}
}
void calc_route()
{
	int ret = 0;
	int cnt = 0;
	int i = 0;
	int j = 0;
	while (i + pmax[0] != pmin[0])
	{
		if (arr[i + pmax[0]][j + pmax[1]] == '*')
			cnt++;
		i += (pmin[0] - pmax[0]) / abs((pmin[0] - pmax[0]));
	}
	while (j + pmax[1] != pmin[1])
	{
		if (arr[i + pmax[0]][j + pmax[1]] == '*')
			cnt++;
		j += (pmin[1] - pmax[1]) / abs((pmin[1] - pmax[1]));
	}
	ret = cnt;
	cnt = 0;
	i = 0;
	j = 0;
	while (j + pmax[1] != pmin[1])
	{
		if (arr[i + pmax[0]][j + pmax[1]] == '*')
			cnt++;
		j += (pmin[1] - pmax[1]) / abs((pmin[1] - pmax[1]));
	}
	while (i + pmax[0] != pmin[0])
	{
		if (arr[i + pmax[0]][j + pmax[1]] == '*')
			cnt++;
		i += (pmin[0] - pmax[0]) / abs((pmin[0] - pmax[0]));
	}
	if (cnt < ret)
		ret = cnt;
	// printf("%d %d %d\n", max, min, ret);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", arr[i]);
	calc_minmax();
	// printf("pmax : %d %d\n", pmax[0], pmax[1]);
	// printf("pmin : %d %d\n", pmin[0], pmin[1]);
	// calc_route();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%c", ret[i][j]);
		printf("\n");
	}
	// for (int i = 0; i < n; i++)
	//  printf("%s\n", arr[i]);
}