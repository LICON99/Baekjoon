#include <iostream>
#include <queue>
#include <vector>
#define INF 2147483647
using namespace std;

int n, k;
int visited[200001] = {0};
vector<int> dist(200001, INF);
int path[200001];
int ret;

// 이렇게 다음 탐색할 노드 찾으면 O(V^2)만큼 걸리기 때문에 시간초과. -> 우선순위 큐 이용해야함.
//  int find_next()
//  {
//  	int min = INF;
//  	int ret;
//  	for (int i = 0; i < 2 * max(n, k) + 1; i++)
//  	{
//  		if (visited[i] || (i == 0 && k != 0))
//  			continue;
//  		if (min > cost[i])
//  		{
//  			min = cost[i];
//  			ret = i;
//  		}
//  	}
//  	return ret;
//  }
int retu;
void dijkstra()
{
	queue<int> q;

	q.push(n);
	dist[n] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		if (u == k)
		{
			ret = dist[u];
			retu = u;
			break;
		}
		for (int i = 0; i < 3; i++)
		{
			int v, cost_val;
			if (i == 0)
			{
				if (u == 0)
					continue;
				v = u - 1;
				cost_val = 1;
			}
			else if (i == 1)
			{
				if (u > k)
					continue;
				v = u + 1;
				cost_val = 1;
			}
			else if (i == 2)
			{
				if (u == 0 || u > k)
					continue;
				v = u * 2;
				cost_val = 1;
			}
			if (!visited[v])
			{
				path[v] = u;
				visited[v] = 1;
				dist[v] = dist[u] + cost_val;
				q.push(v);
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	// n이 k보다 큰 경우 -1씩 이동하는 수 밖에 없음.
	if (n >= k)
	{
		printf("%d\n", n - k);
		// for (int i = n; i >= k; i--)
		// 	printf("%d ", i);
		// printf("\n");
		return 0;
	}
	dijkstra();

	printf("%d\n", ret);
	// int u = retu;
	// vector<int> ans;
	// while (u != n)
	// {
	// 	ans.push_back(u);
	// 	u = path[u];
	// }
	// ans.push_back(u);
	// for (int i = ans.size() - 1; i >= 0; i--)
	// 	printf("%d ", ans[i]);
	return 0;
}