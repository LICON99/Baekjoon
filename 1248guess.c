#include <stdio.h>
#include <string.h>

int n;
char arr[100][100];
int ret[10];
int check[10] = {0};
void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
			scanf(" %c", &arr[i][j]);
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		if (j < i)
	// 		{
	// 			printf("  ");
	// 			continue;
	// 		}
	// 		printf(" %c", arr[i][j]);
	// 	}
	// 	printf("\n");
	// }
}
void bfs(int idx, int row, int col)
{
	if (arr[row][row] == '-' && arr[row - 1 [row - 1] ^ arr[row][row]] == 1)
	{
	}
}
// int is_valid(int sum, size_t cnt)
// {
// 	// printf("cnt : %zu\n",cnt);
// 	if (arr[cnt] == '-' && sum >= 0)
// 		return (0);
// 	if (arr[cnt] == '+' && sum <= 0)
// 		return (0);
// 	if (arr[cnt] == '0' && sum != 0)
// 		return (0);
// 	return 1;
// }

// void bfs(int *ans, int check[], size_t row, size_t idx, int sum, size_t cnt)
// {
// 	if (flag)
// 		return;
// 	if (row == n)
// 	{
// 		for (int i = 0; i < n; i++)
// 			printf("%d ", ans[i]);
// 		printf("\n");
// 		// memcpy(ret, ans, sizeof(int) * 10);
// 		flag = 1;
// 		cnt = 0;
// 		return;
// 	}
// 	if (row + idx == n)
// 	{
// 		bfs(ans, check, row + 1, 0, 0, cnt);
// 		return;
// 	}
// 	if (!check[row + idx])
// 	{
// 		for (int i = -10; i < 11; i++)
// 		{
// 			check[row + idx] = 1;
// 			sum += i;
// 			ans[row + idx] = i;
// 			if (is_valid(sum, cnt))
// 				bfs(ans, check, row, idx + 1, sum, cnt + 1);
// 			sum -= i;
// 			check[row + idx] = 0;
// 		}
// 	}
// 	else
// 	{
// 		sum += ans[row + idx];
// 		if (is_valid(sum, cnt))
// 			bfs(ans, check, row, idx + 1, sum, cnt + 1);
// 	}
// 	return;
// }

int main(void)
{
	int ans[10] = {0};

	init();
	if (arr[0][0] == '-')
	{
		for (int i = -10; i < 0; i++)
		{
			ret[0] = i;
			bfs(1, );
		}
	}
	if (arr[0][0] == '0')
	{
		ret[0] = 0;
		bfs(1, );
	}
	if (arr[0][0] == '+')
	{
		for (int i = 1; i <= 10; i++)
		{
			ret[0] = i;
			bfs(1, );
		}
	}
	// for (int i = 0; i < n; i++)
	// 	printf("%d ", ret[i]);
	// printf("\nparr : %c %c %c\n", *parr, *(parr + 1), *(parr + 2));
	return (0);
}