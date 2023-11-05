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

	while (idx1 > 0 && arr[idx1 - 1] <= arr[idx1])
		idx1--;
	if (idx1 == 0)
	{
		printf("-1\n");
		return (0);
	}
	while (arr[idx1 - 1] <= arr[idx2])
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