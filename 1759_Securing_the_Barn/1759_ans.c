#define max 18
#include <stdbool.h>
#include <stdlib.h>

int L, C;
char password[max];
char ans[max];
int visited[max];

int cmp(const void *lhs, const void *rhs)
{
	if (*(char *)lhs > *(char *)rhs)
		return 1;
	else
		return -1;
}

void Input_Base_Password()
{
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++)
		scanf(" %c", &password[i]);
	qsort(password, C, sizeof(char), cmp);
}

void dfs(int depth, int start)
{
	if (depth == L)
	{
		bool flag = false;
		int cnt = 0;
		for (int i = 0; i < depth; i++)
		{
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' | ans[i] == 'u')
			{
				flag = true;
			}
			else
				cnt++;
		}
		if (flag && cnt >= 2)
		{
			for (int i = 0; i < depth; i++)
				printf("%c", ans[i]);
			printf("\n");
			return;
		}
		else
			return;
	}

	for (int i = start; i < C; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			ans[depth] = password[i];
			dfs(depth + 1, i + 1);
			visited[i] = 0;
		}
	}
}

int main()
{
	Input_Base_Password();
	dfs(0, 0);
	return 0;
}