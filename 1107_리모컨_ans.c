#include <stdio.h>
typedef struct s_info
{
    int ans;
    int num;
} t_info;
int ft_abs(int n)
{
    if (n > 0)
        return n;
    else
        return n * (-1);
}
int n_cmp(int a, int b)
{
    if (a > b)
        return 1;
    else
        return 0;
}
int cal_ret_digits(int ret)
{
    int cnt = 1;
    while (ret / 10)
    {
        cnt++;
        ret /= 10;
    }
    return cnt;
}
int is_valid(int i, int *digits, int *digits_n)
{
    // int tmp = i;
    if (i == 0)
    {
        (*digits_n)++;
        if (!digits[i % 10])
            return 0;
    }
    while (i > 0)
    {
        (*digits_n)++;
        if (!digits[i % 10])
            return 0;
        i /= 10;
    }
    // printf("valid i : %d\n", tmp);
    return 1;
}
int main(void)
{
    t_info info;
    int n, m;
    int digits[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        digits[tmp] = 0;
    }
    info.ans = ft_abs(n - 100);
    info.num = 100;

    for (int i = 0; i <= 10000000; i++)
    {
        int digits_n = 0;
        if (is_valid(i, digits, &digits_n))
        {
            if (n_cmp(info.ans, ft_abs(n - i) + digits_n))
            {
                info.num = i;
                info.ans = ft_abs(n - i) + digits_n;
            }
        }
    }
    // printf("%d %d", info.num, info.ans);
    printf("%d", info.ans);
    return 0;
}