#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *get_pi(char *string)
{
    int *pi;
    int j;
    int str_len = strlen(string);

    pi = (int *)malloc(sizeof(int) * str_len);
    if (!pi)
        return NULL;
    for (int i = 0; i < str_len; i++)
        pi[i] = 0;
    j = 0;
    for (int k = 1; k < str_len; k++)
    {
        while (string[j] != string[k] && j > 0)
            j = pi[j - 1];
        if (string[j] == string[k])
            pi[k] = ++j;
    }
    return pi;
}

int main(void)
{
    char *a;
    char *b;
    a = (char *)malloc(sizeof(char) * 100001);
    if (!a)
        return 0;
    b = (char *)malloc(sizeof(char) * 100001);
    if (!b)
        return 0;
    int *pi;
    int words = 0;
    int j = 0;
    scanf("%s", a);
    scanf("%s", b);
    int a_len = strlen(a);
    int b_len = strlen(b);
    pi = get_pi(a);
    for (int i = 0; i < 2 * b_len - 1; i++)
    {
        while (a[j] != b[i % b_len] && j > 0)
            j = pi[j - 1];
        if (a[j] == b[i % b_len])
            ++j;
        if (j == a_len)
        {
            words++;
            j = pi[j - 1];
        }
    }
    printf("%d", words);
    free(pi);
    free(a);
    free(b);
    return 0;
}
// 처음 푼 코드. a를 순환시키는 풀이인데, 이러면 kmp를 사용 못함.
// 위 코드는 b문자열을 순환하며 kmp를 사용했음.
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int *get_pi(char *string)
// {
//     int *pi;
//     int j;
//     int str_len = strlen(string);

//     pi = (int *)malloc(sizeof(int) * str_len);

//     for (int i = 0; i < str_len; i++)
//         pi[i] = 0;
//     j = 0;
//     for (int k = 1; k < str_len; k++)
//     {
//         while (string[j] != string[k] && j > 0)
//             j = pi[j - 1];
//         if (string[j] == string[k])
//             pi[k] = ++j;
//     }
//     return pi;
// }

// int main(void)
// {
//     char *a;
//     char *b;
//     a = (char *)malloc(sizeof(char) * 100001);
//     b = (char *)malloc(sizeof(char) * 100001);
//     int *pi;
//     int words = 0;
//     int j = 0;
//     int i = 0;
//     scanf("%s", a);
//     scanf("%s", b);
//     int a_len = strlen(a);

//     pi = get_pi(a);
//     while (i < a_len)
//     {
//         j = 0;
//         while (a[(i + j) % a_len] == b[j] && b[j] != 0)
//             j++;
//         if (j == a_len)
//             words++;
//         if (j > 0)
//             i += j - pi[j - 1];
//         else
//             i++;
//     }
//     printf("%d", words);
//     free(pi);
//     free(a);
//     free(b);
//     return 0;
// }