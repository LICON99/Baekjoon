#include <stdio.h>

int sum = 0;
int arr[3] = {60, 100, 120};
int cnt[3] = {1, 1, 1};
int main(void)
{
	int n, m;
	while (sum <= 300)
	{
		scanf("%d %d", &n, &m);
		if (m == 1)
			sum += arr[n - 1] * (cnt[n - 1]++);
		if (m >= 2 && m <= 5)
			sum += arr[n - 1] * (cnt[n - 1]++) / 2;
		if (m >= 6 && m <= 10)
			sum += arr[n - 1] * (cnt[n - 1]++) / 4;
		if (m >= 11 && m <= 20)
			sum += arr[n - 1] * (cnt[n - 1]++) / 10;
		if (m >= 21)
			sum += arr[n - 1] * (cnt[n - 1]++) / 20;
	}
	printf("%d\n", sum);
}