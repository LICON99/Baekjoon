#include <stdio.h>
#include <stdlib.h>
int *get_pi(char *str)
{
    int *pi;
    pi = (int *)calloc(1000000, sizeof(int));
    int j = 0;
    for (int i = 1; str[i] != 0; i++)
    {
        while (j > 0 && str[i] != str[j])
            j = pi[j - 1];
        if (str[i] == str[j])
            pi[i] = ++j;
    }
    printf("j : %d\n", j);
    // for (int k = 0; pi[k] != 0; k++)
    //     printf("pi[%d] : %d\n", k, pi[k]);
    return pi;
}
int main(void)
{
    int L = 0;
    char str[1000001];
    int *pi;
    scanf("%d", &L);
    scanf("%s", str);

    pi = get_pi(str);
    printf("%d", L - pi[L - 1]);
    return 0;
}