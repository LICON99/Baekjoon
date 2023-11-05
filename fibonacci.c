#include <stdio.h>

int arr[100000000] = {0};

int fib(int idx)
{
	if (idx == 0 || idx == 1)
		return 1;
	else if (arr[idx])
		return arr[idx];
	else
	{
		arr[idx] = (fib(idx - 1) + fib(idx - 2)) % 1000000000;
		return (arr[idx]);
	}
}

int main()
{
	int sum = 0;
	arr[0] = 1;
	arr[1] = 1;
	int i, j;
	scanf("%d %d", &i, &j);
	// for (int k = i; k <= j; k++)
	// sum += fib(k - 1);
	printf("%d", (fib(j + 1) - fib(i)) % 1000000000);
}
