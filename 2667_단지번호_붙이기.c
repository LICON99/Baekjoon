#include <stdio.h>
#include <string.h>
int n;
char arr[25][25];
int group[1000];
int check[25][25] = {0};
int id = 0;
int dx[5] = {-1, 0, 1, 0};
int dy[5] = {0, -1, 0, 1};
char tmp;

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%c", arr[i] + j);
			check[i][j] = 1;
			scanf("%c", &tmp);
		}
	}
}

void dfs(int x, int y, int id)
{
	group[id]++;
	check[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] == 1)
		{
			dfs(nx, ny, id);
		}
	}
	return;
}
int main(void)
{
	init();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
			{
				dfs(0, 0, id++);
			}
		}
	printf("id : %d\n", id);
	for (int k = 0; k < id; k++)
		printf("%d\n", group[k]);
	return 0;
}