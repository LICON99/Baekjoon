#include <iostream>
#include <queue>
#define INF 2147483647
using namespace std;

int m, n;
int map[100][100];
bool visited[100][100] = {0};
int cost[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &map[i][j]);
			cost[i][j] = INF;
		}
	cost[0][0] = 0;
	// input check
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 		printf("%1d", map[i][j]);
	// 	printf("\n");
	// }
}
pair<int, int> find_next()
{
	pair<int, int> min;
	int intmin = INF;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j])
				continue;
			if (cost[i][j] < intmin)
			{
				intmin = cost[i][j];
				min = make_pair(i, j);
			}
		}
	}
	// printf("cost check\n");
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 	{
	// 		printf("%d ", cost[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("cost check\n");
	// printf("visit check\n");
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 	{
	// 		printf("%d ", visited[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("visit check\n");
	return min;
}
void dij(void)
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	while (true)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visited[x][y] = 1;
		if (x == n - 1 && y == m - 1)
			return;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (!visited[nx][ny] && cost[nx][ny] > cost[x][y] + map[nx][ny])
					cost[nx][ny] = cost[x][y] + map[nx][ny];
			}
		}
		q.push(find_next());
	}
}
int main()
{
	init();
	dij();
	printf("%d\n", cost[n - 1][m - 1]);
	return 0;
}