#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int n, m;
int map[1000][1000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void init()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
}
void save_startp(queue<pair<int, int>> &q)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1)
				q.push(make_pair(i, j));
		}
}
void is_valid()
{
	int max = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 0)
			{
				cout << "-1\n";
				exit(0);
			}
			else
			{
				if (max < map[i][j])
					max = map[i][j];
			}
		}
	}
	cout << max - 1 << "\n";
}
void bfs()
{

	int cnt = 0;
	queue<pair<int, int>> q;
	save_startp(q);

	// printf("check\n");
	while (!q.empty())
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = q.front().first + dx[i];
			int ny = q.front().second + dy[i];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n)
			{
				if (map[nx][ny] == 0)
				{
					map[nx][ny] = map[q.front().first][q.front().second] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		q.pop();
	}
	is_valid();
	return;
}
int main()
{
	init();
	bfs();
	return 0;
}