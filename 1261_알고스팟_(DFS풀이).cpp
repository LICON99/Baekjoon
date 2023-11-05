#include <cstdio>
// #include <queue>
#define MAX 2147483647
// using namespace std;

int n, m;
int map[100][100] = {0};
int check[100][100];
int visited[100][100] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void init()
{
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &map[i][j]);
			check[i][j] = MAX;
		}
}

// void bfs()
// {
// 	queue<pair<int, int>> q;
// 	q.push(make_pair(0, 0));

// 	while (!q.empty())
// 	{
// 		int x = q.front().first;
// 		int y = q.front().second;

// 		visited[x][y] = 1;
// 		for (int i = 0; i < 4; i++)
// 		{
// 			int nx = x + dx[i];
// 			int ny = y + dy[i];

// 			if (nx >= 0 && nx < n && ny >= 0 && ny < m && (!visited[nx][ny] || check[nx][ny] > check[x][y] + 1))
// 			{
// 				q.push(make_pair(nx, ny));
// 				if (map[nx][ny] == 1)
// 				{
// 					if (check[nx][ny] == 0 || check[nx][ny] > check[x][y] + 1)
// 					{
// 						check[nx][ny] = check[x][y] + 1;
// 					}
// 				}
// 			}
// 		}
// 		q.pop();
// 	}
// }
void dfs(int x, int y, int cnt)
{
	if (cnt > check[n - 1][m - 1])
		return;
	if (check[x][y] <= cnt)
		return;
	else
		check[x][y] = cnt;
	if (x == n - 1 && y == m - 1)
		return;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny])
		{
			visited[nx][ny] = 1;
			dfs(nx, ny, cnt + map[nx][ny]);
			visited[nx][ny] = 0;
		}
	}
}

int main()
{
	init();
	visited[0][0] = 1;
	dfs(0, 0, 0);
	printf("%d", check[n - 1][m - 1]);
	return 0;
}