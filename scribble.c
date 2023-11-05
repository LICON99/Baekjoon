#include <stdio.h>

int n = 6;
char a[6] = "abcdef";

// void swap(char a[], int i, int j)
// {
// 	char tmp = *(a + i);
// 	*(a + i) = *(a + j);
// 	*(a + j) = tmp;
// }

// void perm(int idx)
// {
// 	if (idx == n)
// 	{
// 		for (int i = 0; i < n; i++)
// 			printf("%c ", a[i]);
// 		printf("\n");
// 		return;
// 	}
// 	for (int i = idx; i < n; i++)
// 	{
// 		swap(a, idx, i);
// 		perm(idx + 1);
// 		swap(a, idx, i);
// 	}
// 	return;
// }

int cnt = 0;
void test(int depth)
{
	cnt++;
	printf("depth : %d, cnt : %d\n", depth, cnt);
	if (depth == 3)
		return;
	for (int i = 0; i < 4; i++)
	{
		test(depth + 1);
	}
}

int main()
{
	// test(0);
	printf("t");
	printf("e");
	printf("s");
	printf("t");
}