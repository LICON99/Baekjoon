#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, v;
vector<vector<int>> graph;
vector<int> check;
void init()
{
	scanf("%d %d %d", &n, &m, &v);
	graph.resize(n + 1);
	check.resize(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());
}

void dfs(int v)
{
	check[v] = 1;
	cout << v << " ";

	for (int i = 0; i < graph[v].size(); i++)
	{
		if (!check[graph[v][i]])
			dfs(graph[v][i]);
	}
}

void bfs(int v)
{
	queue<int> q;
	check[v] = 1;
	q.push(v);

	while (!q.empty())
	{
		cout << q.front() << " ";
		v = q.front();
		q.pop();
		for (int i = 0; i < graph[v].size(); i++)
		{
			if (!check[graph[v][i]])
			{
				check[graph[v][i]] = 1;
				q.push(graph[v][i]);
			}
		}
	}
}
int main()
{
	init();
	dfs(v);
	cout << endl;
	check.assign(check.size(), 0);
	bfs(v);
	cout << endl;
}