#include <iostream>
#include <queue>
#include <time.h>
// #include <vector>
#define INF 2147483647
using namespace std;

int n, k;
// int visited[200001] = {0};
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

void dijkstra()
{
	priority_queue<pair<int, int> > pq;
	vector<int> dist(200001, INF);
	pq.push(make_pair(0, n));
	while (!pq.empty())
	{
		int u = pq.top().second;
		// 기본적으로 priority_queue는 내림차순 이므로 -로 저장하여 오름차순으로 저장하고 불러옴
		int distance = -pq.top().first;
		pq.pop();

		// if (dist[u] < distance)
			// continue;
		// visited[u] = 1;
		if (u == k)
		{
			ret = distance;
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
				cost_val = 0;
			}
			if (dist[v] > distance + cost_val)
			{
				dist[v] = distance + cost_val;
				pq.push(make_pair(-(distance + cost_val), v));
			}
		}
	}
}

int main()
{
	clock_t start = clock(); // 시작 시간 저장
	// time_t start, end;
	// start = time(NULL); // 수행 시간 측정 시작

	scanf("%d %d", &n, &k);
	// n이 k보다 큰 경우 -1씩 이동하는 수 밖에 없음.
	if (n >= k)
	{
		printf("%d\n", n - k);
		return 0;
	}
	dijkstra();

	printf("%d\n", ret);
	clock_t end = clock(); // 코드가 끝난 시간 저장
	// end = time(NULL); // 시간 측정 끝

	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	// printf("TIME : %f", (double)(end - start));

	return 0;
}