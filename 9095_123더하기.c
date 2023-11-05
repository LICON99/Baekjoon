#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loop(long long *arr, long long t, long long idx, long long *cur)
{
    if (idx == t)
    {
        *cur = idx;
        return;
    }
    else
    {
        arr[idx] = arr[idx - 1] + arr[idx - 2] + arr[idx - 3];
        loop(arr, t, idx + 1, cur);
    }
}
/*먼저 정수 1,2,3을 만드는 방법을 배열에 저장한다. (4를 1,2,3을 이용해 만드는 방법)=
(정수 1을 만드는 각각의 방법에 3을 더함)+(정수 2를 만드는 각각의 방법에 2를 더함)
+(정수 3을 만드는 각각의 방법에 1을 더함) 이므로 이를 이용하여 캐싱하며 진행한다.*/
int main(void)
{
    long long t, n;
    scanf("%d", &n);
    long long *arr;
    long long cur = 3;
    arr = (long long *)calloc(sizeof(long long), 1000000);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 4;
    for (long long i = 0; i < n; i++)
    {
        scanf("%lld", &t);
        if (arr[t - 1] == 0)
        {
            loop(arr, t, cur, &cur);
            printf("%lld\n", arr[t - 1]);
        }
        else
            printf("%lld\n", arr[t - 1]);
    }
}