#include <stdio.h>

void calc(int *arr, int j, int *cur)
{
	if (j <= *cur)
		return;
	(*cur)++;
	arr[*cur] = arr[*cur - 1] + arr[*cur - 2] + arr[*cur - 3];
	calc(arr, j, cur);
}

int main()
{
	int t;
	int ans[12];
	int cur = 3;

	scanf("%d", &t);
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 4;
	for (int j = 0, i = 0; i < t; i++)
	{
		scanf("%d", &j);
		if (ans[j] == 0)
			calc(ans, j, &cur);
		printf("%d\n", ans[j]);
	}
	return (0);
}