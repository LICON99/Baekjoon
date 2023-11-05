#include <stdio.h>

int *MAX(int *ar)
{
    int *pmax = ar;

    while (*ar != 0)
    {
        if (*ar > *pmax)
            pmax = ar;
        ar++;
    }
    return pmax;
}
int *MIN(int *ar)
{
    int *pmin = ar;

    while (*ar != 0)
    {
        if (*ar < *pmin)
            pmin = ar;
        ar++;
    }
    return pmin;
}

int main(void)
{
    int n = 0;
    int ar[100] = {
        0,
    };
    int tmp = 1;
    int j = 0;
    int k = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        k = j;
        while (tmp != 0)
        {

            scanf("%d", &tmp);
            if (tmp != 0)
                *(ar + j++) = tmp;
        }
        tmp = 1;
        printf("%d %d\n", *MAX(ar + k), *MIN(ar + k));
    }
    return 0;
}
