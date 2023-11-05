#include <stdio.h>

int ans(int n, int m)
{
    int k = 1, j = 1;
    while (n * k != m * j)
    {
        while (n * k > m * j)
            j++;
        if (n * k != m * j)
            k++;
    }
    return n * k;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0, n = 0, m = 0; i < t; i++)
    {
        scanf("%d %d", &n, &m);
        printf("%d\n", ans(n, m));
    }
    return 0;
}