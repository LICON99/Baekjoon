#include <iostream>
#include <queue>
#include <vector>
#define RED  1;
#define BLUE  -1;
using namespace std;

int t;
int n, m;
vector<int> visited;
queue<int> q;

int dfs(vector<vector<int>> &map, int u)
{
	for (int i = 0; i < map[u].size(); i++)
	{
		if (visited[map[u][i]] * visited[u] == 1)
			return 0;
		if (!visited[map[u][i]])
		{
			visited[map[u][i]] = -visited[u];
			if (!dfs(map, map[u][i]))
				return 0;
		}
	}
	return 1;
}
int bfs(vector<vector<int>> &map, int u)
{
	queue<int> q;

	visited[u] = RED;
	q.push(u);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		for (int i = 0; i < map[u].size(); i++)
		{
			int v = map[u][i];

			if (!visited[v])
			{
				q.push(v);
				visited[v] = -visited[u];
			}
			if (visited[v] == visited[u])
				return (0);
		}
	}
	return (1);
}

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		vector<vector<int>> map(20001);
		cin >> n >> m;

		visited.resize(n + 1);
		visited.assign(n + 1, 0);

		// 체크용도
		//  if (n == 2 && m != 0)
		//  {
		//  	cout << "NO\n";
		//  	continue;
		//  }
		for (int j = 0, a, b; j < m; j++)
		{
			cin >> a >> b;
			map[a].push_back(b);
			map[b].push_back(a);
		}

		// 체크용도
		//  for (int i = 1; i <= n; i++)
		//  {
		//  	for (int j = 0; j < map[i].size(); j++)
		//  	{
		//  		if (!map[i].empty())
		//  			cout << "i :" << i << "," << map[i][j];
		//  	}
		//  	cout << "\n";
		//  }
		//  printf("start\n");
		//  for (int i = 1; i <= n; i++)
		//  	printf("i : %d, color : %d\n", i, visited[i]);
		//  printf("start\n");

		// BFS풀이
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
				if (!bfs(map, i))
				{
					flag = 1;
					break;
				}
		}

		// DFS풀이
		//  for (int i = 1; i <= n; i++)
		//  {
		//  	if (!visited[i])
		//  	{
		//  		visited[i] = RED;
		//  		if (!dfs(map, i))
		//  		{
		//  			flag = 1;
		//  			break;
		//  		}
		//  	}
		//  }

		// 체크용도
		//  printf("end\n");
		//  for (int i = 1; i <= n; i++)
		//  	printf("i : %d, color : %d\n", i, visited[i]);
		//  printf("end\n");
		if (flag == 1)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}