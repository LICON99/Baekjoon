#include <iostream>
#include <algorithm>
using namespace std;

int k, s;
int arr[50] = {0};
int ret[50];
void dfs(int idx, int start, int arr[])
{
	if (idx == 6)
	{
		// printf("start : %d\n", start);
		for (int i = 0; i < 6; i++)
			printf("%d ", ret[i]);
		printf("\n");
		return;
	}
	for (int i = start; i < k; i++)
	{
		// if (!visited[arr[i]])
		// {
		// visited[arr[i]] = 1;
		ret[idx] = arr[i];
		// printf("i : %d, ret[i]=%d\n", i, ret[i]);
		dfs(idx + 1, i + 1, arr);
		// visited[arr[i]] = 0;
		// }
	}
}

int main(void)
{
	while (1)
	{
		int visited[50] = {0};
		cin >> k;
		if (k == 0)
			return 0;
		for (int i = 0; i < k; i++)
			cin >> arr[i];
		sort(arr, arr + k);
		// for (int i = 0; i < k; i++)
		// 	printf("%d ", arr[i]);
		dfs(0, 0, arr);
		printf("\n");
	}
	return 0;
}