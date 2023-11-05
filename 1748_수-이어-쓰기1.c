#include <stdio.h>

long long cal_digit_num(int n)
{
    long long max_num = 1;
    long long sum = 0;
    long long tmp = n;
    long long digit_num = 1;
    while (tmp >= 10)
    {
        tmp /= 10;
        max_num *= 10;
        digit_num++;
    }
    while (n > 0)
    {
        sum += (n - max_num + 1) * digit_num;
        n = max_num - 1;
        max_num /= 10;
        digit_num--;
    }
    return sum;
}

int main(void)
{
    long long sum = 0;
    int n;
    scanf("%d", &n);
    sum = cal_digit_num(n);
    printf("%lld", sum);
}