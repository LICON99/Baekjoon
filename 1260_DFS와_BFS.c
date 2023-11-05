#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, v;
int graph[1001][10001] = {{0}};
int check1[1001] = {0};
int check2[1001] = {0};

int cmp(const void *a, const void *b)
{
	if (*(int *)a > *(int *)b)
		return 1;
	if (*(int *)a < *(int *)b)
		return -1;
	else
		return 0;
}

void append(int a, int b)
{
	int j = 0;
	while (graph[a][j] != 0)
		j++;
	graph[a][j] = b;
	qsort(graph[a], j + 1, sizeof(int), cmp);
}

void init(void)
{
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		append(a, b);
		append(b, a);
	}
}

void dfs(int v)
{
	check1[v] = 1;
	printf("%d ", v);
	for (int i = 0; graph[v][i] != 0; i++)
	{
		if (!check1[graph[v][i]])
			dfs(graph[v][i]);
	}
}
void bfs(int v)
{
	int queue[20000] = {0};
	int front = 9999, rear = front;

	check2[v] = 1;
	queue[rear++] = v;

	while (front < rear)
	{
		v = queue[front++];
		printf("%d ", v);
		for (int i = 0; graph[v][i] != 0; i++)
		{
			if (!check2[graph[v][i]])
			{
				check2[graph[v][i]] = 1;
				queue[rear++] = graph[v][i];
			}
		}
	}
}

int main(void)
{
	init();
	// printf("\n");
	// for (int i = 1; i <= n; i++)
	// {
	// 	printf("%d : ", i);
	// 	for (int j = 0; graph[i][j] != 0; j++)
	// 		printf("%d ", graph[i][j]);
	// 	printf("\n");
	// }
	// printf("\n");
	dfs(v);
	printf("\n");
	bfs(v);
}