/* 다른 인라인 함수 예제*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
__inline int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int test(int a)
{
	if (a > 1)
		return true;
	else
		return false;
}

int main(int argc, char **argv)
{
	char str[100];
	int a = 14;
	int b = 1;
	printf("%d", ~(b << (4 * 8 - 1)));
	return 0;
}