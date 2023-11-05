#include <stdio.h>

int main(void)
{
    int e, s, m;
    scanf("%d %d %d", &e, &s, &m);
    if (e == 15)
        e = 0;
    if (s == 28)
        s = 0;
    if (m == 19)
        m = 0;
    for (int i = 1; 1; i++)
    {
        if (i % 15 == e && i % 28 == s && i % 19 == m)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}