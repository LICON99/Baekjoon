#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 아래는 실패한 코드다.. 한 자리씩 비교해서 연산하려고 했더니.. 끝도없는 반례처리에
// 골머리 썩다가 포기했다.
int cal_max_digit(int n)
{
    int ret = 1;
    while (n > 0)
    {
        n /= 10;
        ret *= 10;
    }
    return ret / 10;
}

int ft_abs(int n)
{
    if (n > 0)
        return n;
    else
        return n * (-1);
}

int find_digit(int dest, int *digits, int ret, int max_digit, int n)
{
    int res1 = 100, res2 = 100;
    // printf("dest : %d\n", dest);
    if (max_digit != cal_max_digit(n) && ret / (max_digit * 10) > n / (max_digit * 10))
    {
        // printf("1\n");
        for (int cnt = 0; cnt <= 9; cnt++)
        {
            if (digits[cnt])
                return cnt;
        }
    }
    if (max_digit != cal_max_digit(n) && ret / (max_digit * 10) < n / (max_digit * 10))
    {
        // printf("2\n");
        for (int cnt = 9; cnt >= 0; cnt--)
        {
            if (digits[cnt])
                return cnt;
        }
    }

    // printf("3\n");
    for (int cnt = dest; cnt <= 9; cnt++)
    {
        if (digits[cnt])
        {
            res1 = cnt;
            break;
        }
    }
    for (int cnt = dest; cnt >= 0; cnt--)
    {
        if (digits[cnt])
        {
            res2 = cnt;
            break;
        }
    }
    int final;
    if (ft_abs(dest - res1) > ft_abs(dest - res2))
        final = res2;
    else
        final = res1;
    // printf("final:  %d\n", final);
    // if (ret == 0 && final == 0)

    // printf("res1: %d, res2 : %d\n", res1, res2);
    return (final);
}
int cal_ret_digits(int ret)
{
    int cnt = 1;
    while (ret >= 10)
    {
        cnt++;
        ret /= 10;
    }
    return cnt;
}
int main(void)
{
    int n, m;
    int digits[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        digits[tmp] = 0;
    }
    int max_digit = cal_max_digit(n);
    int ret = 0;
    int cnt = 0;
    while (max_digit > 0 && m != 10)
    {
        // printf("loop\n");
        ret += find_digit(n / max_digit % 10, digits, ret, max_digit, n) * max_digit;
        max_digit /= 10;
    }
    printf("ret : %d,%d %d\n", ret, ft_abs(n - ret), cal_ret_digits(ret));
    if (ft_abs(cal_max_digit(n) * 10 - n) < ft_abs(n - ret))
        cnt += ft_abs(cal_max_digit(n) * 10 - n) + cal_ret_digits(ret);
    else
        cnt += ft_abs(n - ret) + cal_ret_digits(ret);
    if (cnt > ft_abs(n - 100) || m == 10)
        printf("%d", ft_abs(n - 100));
    else
        printf("%d", cnt);
    return 0;
}