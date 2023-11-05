#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long *make_pi(char *str)
{
    long long *pi;
    long long j = 0;

    pi = (long long *)malloc(sizeof(long long) * (strlen(str)));
    for (long long i = 0; i < strlen(str); i++)
        pi[i] = 0;
    for (long long i = 1; i < strlen(str); i++)
    {
        while (j > 0 && str[j] != str[i])
            j = pi[j - 1];
        if (str[j] == str[i])
            pi[i] = ++j;
    }
    return pi;
}
long long main(void)
{
    char str[500001];
    long long n;
    long long *pi;

    scanf("%s %d", str, &n);
    pi = make_pi(str);
    printf("%lld", (strlen(str) - pi[strlen(str) - 1]) * n + pi[strlen(str) - 1]);
    free(pi);
    return 0;
}