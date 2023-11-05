#include <stdio.h>
#include <string.h>
int is_isspace(char c)
{
    if (c >= 9 && c <= 13 || c == 32)
        return 1;
    return 0;
}
int main(void)
{
    int t;
    char s[1001];

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf(" %[^\n]", s);
        int s_len = strlen(s);
        // printf("s_len : %d, s[] : %c,%d\n", s_len, s[s_len], s[s_len]);
        int tmp;
        int j = 0;
        // printf("started\n");
        while (j < s_len)
        {
            while (is_isspace(s[j]) && j < s_len)
            {
                printf("%c", s[j]);
                j++;
            }
            tmp = j;
            while (!is_isspace(s[j]) && j < s_len)
                j++;
            for (int k = j - 1; k >= tmp; k--)
                printf("%c", s[k]);
        }
        printf("\n");
    }
    return 0;
}