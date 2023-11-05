#include <stdio.h>
#include <stdlib.h>

int max = 0;
int table[15][2];
int n;

void loop(size_t date, size_t sum)
{
	if (date > n)
		return;
	if (date == n)
	{
		if (sum > max)
			max = sum;
		return;
	}
	for (int i = date; i < n; i++)
	{
		if (i + table[i][0] <= n)
			loop(i + table[i][0], sum + table[i][1]);
		else
			loop(i + 1, sum);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf(" %d %d", &table[i][0], &table[i][1]);
	loop(0, 0);
	printf("%d\n", max);
}