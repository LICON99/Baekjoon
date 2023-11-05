#include <stdio.h>
#include <string.h>

int n, m;
char map[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init(int check[][100])
{
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%c", &map[i][j]);
			check[i][j] = -1; // Initialize check array with -1 (not visited)
		}
		getchar();
	}
}

void bfs(int x, int y, int check[][100])
{
	check[x][y] = 1;
	int queue[10000][2]; // Queue for BFS
	int front = 0, rear = 1;
	queue[front][0] = x;
	queue[front][1] = y;

	while (front < rear)
	{
		x = queue[front][0];
		y = queue[front][1];
		front++;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == '1' && check[nx][ny] == -1)
			{
				check[nx][ny] = check[x][y] + 1;
				queue[rear][0] = nx;
				queue[rear][1] = ny;
				rear++;
			}
		}
	}
}

int main(void)
{
	int check[100][100];
	init(check);
	bfs(0, 0, check);
	printf("%d\n", check[n - 1][m - 1]);
	return 0;
}
