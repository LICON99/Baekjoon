#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int k;
char input[12];
long long lmax = 0;
long long lmin = LLONG_MAX;
char *smin = NULL;
char *smax = NULL;

void init(void)
{
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
		scanf(" %c", input + i);
	input[k + 1] = '\0';
}

int is_ans(char ans[])
{
	long long parse = 0;

	for (int i = 0; i < k + 1; i++)
		parse = parse * 10 + ans[i] - '0';
	if (parse > lmax)
	{
		lmax = parse;
		free(smax);
		smax = strdup(ans);
	}
	if (parse < lmin)
	{
		lmin = parse;
		free(smin);
		smin = strdup(ans);
	}
	return (0);
}

void brut(int check[], char ans[], int pre, int idx)
{
	if (idx == k + 1)
		is_ans(ans);
	if (input[idx - 1] == '>')
	{
		for (int i = pre - 1; i >= '0'; i--)
		{
			if (check[i - '0'])
				continue;
			check[i - '0'] = 1;
			ans[idx] = i;
			brut(check, ans, i, idx + 1);
			check[i - '0'] = 0;
		}
	}
	if (input[idx - 1] == '<')
	{
		for (int i = pre + 1; i <= '9'; i++)
		{
			if (check[i - '0'])
				continue;
			check[i - '0'] = 1;
			ans[idx] = i;
			brut(check, ans, i, idx + 1);
			check[i - '0'] = 0;
		}
	}
	return;
}

int main(void)
{
	char ans[11];
	int check[10] = {0};

	init();
	ans[k + 1] = '\0';
	for (int i = '0'; i <= '9'; i++)
	{
		check[i - '0'] = 1;
		ans[0] = i;
		brut(check, ans, i, 1);
		check[i - '0'] = 0;
	}
	printf("%s\n", smax);
	printf("%s\n", smin);
	return (0);
}