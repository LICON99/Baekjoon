#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *first, const void *second)
{
	if (*(int *)first > *(int *)second)
		return (1);
	else if (*(int *)first < *(int *)second)
		return (-1);
	else
		return (0);
}

int is_valid(char *arr)
{
	int cnt1 = 0;
	int cnt2 = 0;
	int idx = 0;
	while (arr[idx])
	{
		if (arr[idx] == 'a' || arr[idx] == 'e' || arr[idx] == 'i' || arr[idx] == 'o' || arr[idx] == 'u')
			cnt1++;
		else
			cnt2++;
		idx++;
	}
	if (cnt1 == 0 || cnt2 < 2)
		return (0);
	idx = 0;
	return (1);
}

void loop(char *arr, int idx, int limit, int final, char *ret)
{
	if (idx == final)
	{
		if (is_valid(ret))
			printf("%s\n", ret);
		return;
	}
	for (int i = 0; i < limit; i++)
	{
		ret[idx] = arr[i];
		if (ret[idx - 1] >= ret[idx])
			continue;
		loop(arr, idx + 1, limit, final, ret);
	}
}

int main(void)
{
	int l, c;
	char arr[50];
	char tmp;
	int j = 0;
	char *ret;
	scanf("%d %d", &l, &c);
	for (int i = 0; i < c; i++)
	{
		scanf(" %c", &tmp);
		arr[j++] = tmp;
	}
	arr[j] = 0;
	ret = (char *)malloc(sizeof(char) * (l + 1));
	ret[l] = 0;
	loop(arr, 0, c, l, ret);
	free(ret);
	return (0);
}
