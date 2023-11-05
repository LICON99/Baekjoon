#include <stdio.h>
int main(void)
{
    int n = 0;
    int min = 1;
    int max = 1;
    int tmp = 0;
    scanf("%d", &n);
    scanf("%d", &tmp);
    min = max = tmp;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &tmp);
        if (tmp > max)
            max = tmp;
        if (tmp < min)
            min = tmp;
    }
    if (n == 1)
        printf("%d", max * max);
    else
        printf("%d", max * min);
    return 0;
}