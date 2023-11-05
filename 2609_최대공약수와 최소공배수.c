#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int tmp = n;
    while (n % tmp != 0 || m % tmp != 0)
        tmp--;
    if (m % tmp == 0 && n % tmp == 0)
        printf("%d\n", tmp);
    int k = 1, j = 1;
    while (n * k != m * j)
    {
        while (n * k > m * j)
            j++;
        if (n * k != m * j)
            k++;
    }
    printf("%d", n * k);
    return 0;
}