#include <stdio.h>

int main(void)
{
    int tmp = 1, cnt = 1;
    int n[10000];
    int i = 0;
    while (scanf("%d", &n[i]) != EOF)
        i++;
    for (int j = 0; j < i; j++)
    {
        cnt = 1;
        tmp = 1;
        while (tmp % n[j] != 0)
        {
            tmp = tmp % n[j] * 10 + 1;
            cnt++;
        }
        printf("%d", cnt);
        if (j + 1 != i)
            printf("\n");
    }
    return 0;
}