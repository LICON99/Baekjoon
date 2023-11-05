#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int v)
{
	visited[v] = 1;
	for (int i = 0; i < graph[v].size(); i++)
	{
		if (!visited[graph[v][i]])
			dfs(graph[v][i]);
	}
}

int main(void)
{
	cin >> n >> m;
	graph.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			dfs(i);
			ret++;
		}
	}
	cout << ret << "\n";
}