#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> visited;
int dx[8] = {-2, -2, -1, -1, 2, 2, 1, 1};
int dy[8] = {1, -1, 2, -2, 1, -1, 2, -2};
int n;
queue<pair<int, int>> q;

void init(int &size, pair<int, int> &sp, pair<int, int> &ep)
{
	int a, b;
	cin >> size;
	graph.resize(size, vector<int>(size, 0));
	visited.resize(size, vector<int>(size, 0));
	visited.assign(size, vector<int>(size, 0));
	graph.assign(size, vector<int>(size, 0));
	cin >> a >> b;
	sp = make_pair(a, b);
	cin >> a >> b;
	ep = make_pair(a, b);
}

void bfs(int size, pair<int, int> sp, pair<int, int> ep)
{
	visited[sp.first][sp.second] = 1;
	graph[sp.first][sp.second] = 0;
	q.push(sp);

	while (!q.empty())
	{
		for (int i = 0; i < 8; i++)
		{
			int nx = q.front().first + dx[i];
			int ny = q.front().second + dy[i];

			if (nx >= 0 && nx < size && ny >= 0 && ny < size && !visited[nx][ny])
			{
				graph[nx][ny] = graph[q.front().first][q.front().second] + 1;
				visited[nx][ny] = 1;
				q.push(make_pair(nx, ny));
			}
		}
		q.pop();
	}
	cout << graph[ep.first][ep.second] << "\n";
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int size;
		int a, b;
		pair<int, int> sp, ep;

		init(size, sp, ep);
		// cout << sp.first << sp.second << "\n"
		// 	 << ep.first << ep.second << "\n";
		bfs(size, sp, ep);
	}
}