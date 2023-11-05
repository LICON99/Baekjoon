#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
int main(void)
{
    int t;
    scanf("%d", &t);
    int m, n, x, y, i, cnt;
    int idx = 0;
    int limit;
    for (int j = 0; j < t; j++)
    {
        scanf("%d %d %d %d", &m, &n, &x, &y);
        i = x;
        limit = lcm(m, n);
        while (i <= limit)
        {
            if (i % n == y || (i % n == 0 && y == n))
            {
                printf("%d\n", i);
                break;
            }
            i += m;
        }
        if (i > limit)
            printf("-1\n");
        // printf("x : %d, y : %d\n", x, i);
    }
    return 0;
}