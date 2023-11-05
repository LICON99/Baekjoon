#include <stdio.h>
#include <stdlib.h>

char arr[100][100];
int ans[10] = {0};
int d;

void init()
{
	scanf("%d", &d);
	for (int i = 0; i < d; i++)
	{
		for (int j = i; j < d; j++)
			scanf(" %c", &arr[i][j]);
	}

}
int is_valid(int idx)
{
	int sum = 0;
	for (int i = idx; i >= 0; i--)
	{
		sum += ans[i];
		if (arr[i][idx] == '+' && !(sum > 0))
			return 0;
		if (arr[i][idx] == '-' && !(sum < 0))
			return 0;
		if (arr[i][idx] == '0' && sum != 0)
			return 0;
	}
	return 1;
}
void bfs(int idx)
{
	if (idx == d)
	{
		for (int i = 0; i < d; i++)
			printf("%d ", ans[i]);
		printf("\n");
		exit(0) ;
	}
	for (int i = -10; i <= 10; i++)
	{
		ans[idx] = i;
		if (is_valid(idx))
			bfs(idx + 1);
	}
}
int main(void)
{
	init();
	bfs(0);
	return 0;
}