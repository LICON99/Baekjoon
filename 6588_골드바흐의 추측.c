#include <stdio.h>
#include <stdlib.h>

int *maldup(int n)
{
    int *tmp;
    tmp = (int *)malloc((n + 1) * sizeof(int));
    if (!tmp)
        return NULL;
    return tmp;
}

int make_arrs(int *prime_ns, int *is_prime, int n)
{
    for (int i = 0; i <= n; i++)
        is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i < n / i; i++)
    {
        if (is_prime[i] == 1)
        {
            for (int j = i; i * j <= n; j++)
                is_prime[i * j] = 0;
        }
    }
    for (int i = 2, j = 0; i <= n; i++)
    {
        if (is_prime[i] == 1)
            prime_ns[j++] = i;
    }
    return 1;
}

int main(void)
{
    int n = 0;
    int *prime_ns;
    int *is_prime;
    prime_ns = maldup(1000000);
    is_prime = maldup(1000000);
    make_arrs(prime_ns, is_prime, 1000000);
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = 0; i <= 1000000; i++)
        {
            if (is_prime[n - prime_ns[i]])
            {
                printf("%d = %d + %d\n", n, prime_ns[i], n - prime_ns[i]);
                break;
            }
            if (n < prime_ns[i])
            {
                printf("Goldbach's conjecture is wrong.");
                break;
            }
        }
    }
    return 0;
}