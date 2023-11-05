#include <stdio.h>
#include <string.h>

int n;
char arr[100];
int ret[10];
int flag = 0;
void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n * (n + 1) / 2; i++)
		scanf(" %c", &arr[i]);
	arr[n * (n + 1) / 2] = 0;
	// for (int i = 0; i < n * (n + 1) / 2; i++)
	// 	printf(" %c", arr[i]);
	// printf("\n");
}

int is_valid(int sum, size_t cnt)
{
	// printf("cnt : %zu\n",cnt);
	if (arr[cnt] == '-' && sum >= 0)
		return (0);
	if (arr[cnt] == '+' && sum <= 0)
		return (0);
	if (arr[cnt] == '0' && sum != 0)
		return (0);
	return 1;
}

int calc_idx(size_t row, size_t idx)
{
	int ret;

	for (int i = 0; i < row; i++)
	{
		ret += (n - row);
	}
	return (ret + idx);
}
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
// 		if (arr[calc_idx(row, idx)] == '-')
// 			for (int i = -10; i < 0; i++)
// 			{
// 				check[row + idx] = 1;
// 				sum += i;
// 				ans[row + idx] = i;
// 				if (is_valid(sum, cnt))
// 					bfs(ans, check, row, idx + 1, sum, cnt + 1);
// 				sum -= i;
// 				check[row + idx] = 0;
// 			}
// 		if (arr[calc_idx(row, idx)] == '+')
// 			for (int i = 1; i <= 10; i++)
// 			{
// 				check[row + idx] = 1;
// 				sum += i;
// 				ans[row + idx] = i;
// 				if (is_valid(sum, cnt))
// 					bfs(ans, check, row, idx + 1, sum, cnt + 1);
// 				sum -= i;
// 				check[row + idx] = 0;
// 			}
// 		else
// 		{
// 			check[row + idx] = 1;
// 			ans[row + idx] = 0;
// 			if (is_valid(sum, cnt))
// 				bfs(ans, check, row, idx + 1, sum, cnt + 1);
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
	int check[10] = {0};

	init();
	bfs(ans, check, 0, 0, 0, 0);
	// for (int i = 0; i < n; i++)
	// 	printf("%d ", ret[i]);
	// printf("\nparr : %c %c %c\n", *parr, *(parr + 1), *(parr + 2));
	return (0);
}