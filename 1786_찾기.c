#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *get_pi(char *string, int stringLen)
{
	int *pi;
	int j;
	pi = (int *)malloc(sizeof(int) * stringLen);

	for (int i = 0; i < stringLen; i++)
		pi[i] = 0;
	j = 0;
	for (int k = 1; k < stringLen; k++)
	{
		while (string[j] != string[k] && j > 0)
			j = pi[j - 1];
		if (string[j] == string[k])
			pi[k] = ++j;
	}
	return pi;
}

void KMP(char *string, char *pattern)
{

	int *pi;
	int stringLen = strlen(string);
	int patternLen = strlen(pattern);
	int idx = 0, cnt = 0;
	int words = 0;
	int *ret;

	ret = (int *)calloc(sizeof(int), 1000001);
	pi = get_pi(pattern, patternLen);
	int j = 0;
	for (int i = 0; i < stringLen; i++)
	{
		while (j > 0 && string[i] != pattern[j])
			j = pi[j - 1];
		if (string[i] == pattern[j])
		{
			if (j == patternLen - 1)
			{
				ret[words++] = i - j + 1;
				j = pi[j];
			}
			else
				j++;
		}
	}
	if (words == 0)
	{
		printf("0");
		free(pi);
		free(ret);
		return;
	}
	printf("%d\n", words);
	for (int i = 0; i < words; i++)
	{
		printf("%d", ret[i]);
		if (i < words - 1)
			printf(" ");
	}
	free(pi);
	free(ret);
}

int main()
{
	char *string;
	char *pattern;

	string = (char *)malloc(1000002);
	pattern = (char *)malloc(1000002);
	fgets(string, 1000002, stdin);
	fgets(pattern, 1000002, stdin);
	string[strlen(string) - 1] = 0;
	pattern[strlen(pattern) - 1] = 0;
	KMP(string, pattern);
	free(string);
	free(pattern);
	return 0;
}