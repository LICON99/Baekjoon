#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> visited;
void init()
{
	cin >> n >> m;
	graph.resize(n);
	for (int a, b, i = 0; i < m; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}
bool dfs(int u, int len)
{
	if (len == 5)
		return true;

	visited[u] = 1;
	for (int i = 0; i < graph[u].size(); i++)
	{
		int v = graph[u][i];
		if (!visited[v])
		{
			if (dfs(v, len + 1) == true)
				return true;
		}
	}
	return false;
}

bool check()
{
	for (int i = 0; i < n; i++)
	{
		visited.assign(n, 0);
		if (dfs(i, 1) == true)
			return true;
	}
	return false;
}

int main()
{
	init();
	if (check() == true)
		cout << "1\n";
	else
		cout << "0\n";
	return 0;
}