#include <stdio.h>
#include <stdlib.h>
int n;
int check[10] = {0};
int ret[16];
int arr[8];
size_t max = 0;
void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf(" %d", &arr[i]);
}

void calc_res(int ret[])
{
	size_t tmp = 0;

	for (int i = 0; i < n - 1; i++)
		tmp += abs(ret[i] - ret[i + 1]);
	if (tmp > max)
		max = tmp;
}

void loop(size_t idx)
{
	if (idx == n)
	{
		calc_res(ret);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (check[i])
			continue;
		check[i] = 1;
		ret[idx] = arr[i];
		loop(idx + 1);
		check[i] = 0;
	}
	return;
}

int main(void)
{
	init();
	loop(0);
	printf("%zu\n", max);
	return 0;
}