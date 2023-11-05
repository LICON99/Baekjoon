#include <stdio.h>
#include <stdlib.h>
// solution 1 : 1부터 루트n까지 i를 하나씩 증가시키면서 찾는 알고리즘
// int is_prime(int i)
// {
//     int j = 2;
//     if (i <= 1)
//         return 0;
//     while (j <= i / j)
//     {
//         if (i % j == 0)
//             return 0;
//         j++;
//     }
//     return 1;
// }
// int main(void)
// {
//     int m, n;
//     scanf("%d %d", &m, &n);
//     for (int i = m; i <= n; i++)
//     {
//         if (is_prime(i))
//             printf("%d\n", i);
//     }
//     return 0;
// }

// best solution 2 : 에라토스테네스의 체
int *eratos(int m, int n)
{
    int *arr;
    arr = (int *)malloc((n + 1) * sizeof(int));
    if (!arr)
        return NULL;
    for (int i = 0; i <= n; i++)
        arr[i] = 1;
    for (int i = 2; i <= n / i; i++)
    {
        if (arr[i] == 1)
        {
            for (int j = i; j <= n / i; j++)
                arr[i * j] = 0;
        }
    }
    return arr;
}
int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    int *arr;
    arr = eratos(m, n);
    for (int i = m; i <= n; i++)
    {
        if (i >= 2 && arr[i] == 1)
            printf("%d\n", i);
    }
    free(arr);
    return 0;
}
