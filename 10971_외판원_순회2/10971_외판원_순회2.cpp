#include <iostream>
#include <queue>
#include <vector>
#define INF 2147483647
using namespace std;

int n;
int tmp = INF;
int w[11][11] = {0};
int visited[11] = {0};

void init()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> w[i][j];
	// printf("\n");
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n; j++)
	// 		cout << w[i][j];
	// 	printf("\n");
	// }
}

int is_all_done(int visited[])
{
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0)
			return 0;
	}
	return 1;
}

void dfs(int visited[], int start, int u, int sum)
{
	if (tmp <= sum)
		return;
	if (u == start && is_all_done(visited))
	{
		tmp = min(tmp, sum);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (w[u][i] != 0 && !visited[i])
		{
			visited[i] = 1;
			dfs(visited, start, i, sum + w[u][i]);
			visited[i] = 0;
		}
	}
	return;
}

int main()
{
	int min = INF;

	init();
	for (int i = 1; i <= n; i++)
	{
		dfs(visited, i, i, 0);
		if (min > tmp)
			min = tmp;
	}
	printf("%d\n", min);
	return 0;
}