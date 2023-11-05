#include <stdio.h>

int main(void)
{
    long long n;
    long long g = 0;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++)
        g += n / i * i;
    printf("%lld", g);
    return 0;
}