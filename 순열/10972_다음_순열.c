// #include <stdio.h>
// #include <string.h>
// int n;
// int arr[10000];
// int ans[10000];
// int cnt = 0;
// int flag = 0;
// void init(void)
// {
// 	scanf("%d", &n);
// 	for (int i = 0; i < n; i++)
// 		scanf(" %d", &arr[i]);
// }

// void permutation(int check[], int tmp[], size_t idx)
// {
// 	if (flag == -1)
// 		return;
// 	if (idx == n)
// 	{
// 		// printf("flag : %d\n", flag);
// 		// for (int i = 0; i < n; i++)
// 		// 	printf("%d ", tmp[i]);
// 		// printf("\n");
// 		if (flag == 1)
// 		{
// 			for (int i = 0; i < n; i++)
// 				printf("%d ", tmp[i]);
// 			flag = -1;
// 			return;
// 		}
// 		if (memcmp(tmp, arr, sizeof(int) * n) == 0)
// 			flag = 1;
// 		return;
// 	}
// 	for (int i = 1; i <= n; i++)
// 	{
// 		if (check[i])
// 			continue;
// 		check[i] = 1;
// 		tmp[idx] = i;
// 		permutation(check, tmp, idx + 1);
// 		check[i] = 0;
// 	}
// 	return;
// }
// int main(void)
// {
// 	int tmp[10000] = {0};
// 	int check[10000] = {0};

// 	init();
// 	permutation(check, tmp, 0);
// 	if (flag == 0)
// 		printf("-1\n");
// 	return (0);
// }

#include <stdio.h>

int n;
int arr[10000];

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf(" %d", &arr[i]);
}

void swap(int *a1, int *a2)
{
	int tmp;

	tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
	return;
}

int main(void)
{
	init();
	int idx1 = n - 1, idx2 = n - 1;

	while (idx1 > 0 && arr[idx1 - 1] >= arr[idx1])
		idx1--;
	if (idx1 == 0)
	{
		printf("-1\n");
		return (0);
	}
	while (arr[idx1 - 1] >= arr[idx2])
		idx2--;
	swap(arr + idx1 - 1, arr + idx2);
	idx2 = n - 1;
	while (idx1 < idx2)
		swap(arr + idx1++, arr + idx2--);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return (0);
}