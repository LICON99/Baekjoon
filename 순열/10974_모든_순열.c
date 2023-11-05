#include <stdio.h>
#include <stdlib.h>

int n;
int check[10] = {0};
int ret[16];
size_t max = 0;
void init()
{
	for (int i = 1; i < 2 * n; i += 2)
		ret[i] = ' ';
	ret[2 * n - 1] = '\0';
}

void calc_res(char ret[])
{
	for(int i=0;ret[i];i++)
	{
		res+=abs()
	}
}
void loop(size_t idx)
{
	if (idx == n * 2)
	{
		calc_res(ret);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (check[i])
			continue;
		check[i] = 1;
		ret[idx] = i;
		loop(idx + 2);
		check[i] = 0;
	}
	return;
}

int main(void)
{
	scanf("%d", &n);
	init();
	loop(0);
	return 0;
}