#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
char map[101][101];
int cnt = 0;
void init(int check[][100])
{
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%c", &map[i][j]);
		}
		getchar();
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 		printf("%c", map[i][j]);
	// 	printf("\n");
	// }
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int x, int y, int check[][100], int cnt, int *min)
{

	check[x][y] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d", check[i][j]);
		printf("\n");
	}
	printf("\n");
	if (x == n - 1 && y == m - 1)
	{

		if (cnt < *min)
			*min = cnt;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == '1' && !check[nx][ny])
		{
			bfs(nx, ny, check, cnt + 1, min);
		}
	}
	return;
}

int main(void)
{
	int check[100][100] = {0};
	int min = 2147483647;

	init(check);
	bfs(0, 0, check, 1, &min);
	printf("%d\n", min);
	return (0);
}