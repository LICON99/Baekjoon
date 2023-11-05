#include <stdio.h>
#include <stdlib.h>

int n;
int arr[20][20];
int min = 2147483647;
int picked[10];

void calc_t(int checked[], int curr, int t1, int t2)
{
	if (curr == n)
	{
		if (abs(t1 - t2) < min)
			min = abs(t1 - t2);
		return;
	}
	for (int i = curr + 1; i < n; i++)
	{
		if (checked[curr] && checked[i])
			t1 += arr[curr][i] + arr[i][curr];
		if (!checked[curr] && !checked[i])
			t2 += arr[curr][i] + arr[i][curr];
	}
	calc_t(checked, curr + 1, t1, t2);
}

void comb(int checked[], size_t idx, size_t final, size_t start)
{
	if (idx == final)
	{

		calc_t(checked, 0, 0, 0);
		return;
	}
	for (int i = start; i < n; i++)
	{
		picked[idx] = i;
		checked[i] = 1;
		comb(checked, idx + 1, final, i + 1);
		checked[i] = 0;
	}
	return;
}

int main(void)
{
	int checked[10] = {0};

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf(" %d", &arr[i][j]);
	}
	for (int i = 1; i < n; i++)
		comb(checked, 0, i, 0);
	printf("%d\n", min);
	return (0);
}