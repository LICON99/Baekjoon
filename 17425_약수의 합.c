#include <stdio.h>
#include <stdlib.h>
long long *make_table(int max)
{
    // int *eratos;
    long long *g;
    g = (long long *)malloc((max + 1) * sizeof(long long));
    if (!g)
        return NULL;
    // eratos = (int *)malloc((max + 1) * sizeof(int));
    // if (!eratos)
    //     return NULL;
    // for (int i = 0; i <= max; i++)
    //     eratos[i] = 1;
    for (int i = 0; i <= max; i++)
        g[i] = 1;
    // for (int i = 2; i <= max; i++)
    // {
    //     if (eratos[i] == 1)
    //     {
    //         for (int j = i; j <= max / i; j++)
    //             eratos[i * j] = 0;
    //     }
    // }
    for (int i = 2; i <= max; i++)
    {
        for (int j = 1; j <= max / i; j++)
            g[i * j] += i;
    }
    // for (int i = 1; i <= max; i++)
    //     printf("eratos[%d] : %d\n", i, eratos[i]);

    for (int i = 2; i <= max; i++)
        g[i] += g[i - 1];
    // for (int i = 1; i <= max; i++)
    //     printf("g[%d] : %ld\n", i, g[i]);
    // free(eratos);
    return g;
}

int main(void)
{
    int t = 0;
    long long arr[100000];
    long long *g;
    int max = 0;
    int idx = 0;
    scanf("%d", &t);
    for (idx = 0; idx < t; idx++)
    {
        scanf("%d", &arr[idx]);
        if (max < arr[idx])
            max = arr[idx];
    }
    g = make_table(max);
    for (idx = 0; idx < t; idx++)
        printf("%lld\n", g[arr[idx]]);
    free(g);
    return 0;
}
