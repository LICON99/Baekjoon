#include <stdio.h>

int main(void)
{
    int arr[9];
    int ret[7];
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (sum - (arr[i] + arr[j]) == 100)
            {
                for (int k = 0, l = 0; k < 9; k++)
                {
                    if (k == i || k == j)
                        continue;
                    ret[l++] = arr[k];
                }
            }
        }
    }
    for (int i = 7; i > 0; i--)
    {
        for (int j = 0, tmp = 0; j < i - 1; j++)
        {
            if (ret[j] > ret[j + 1])
            {
                tmp = ret[j];
                ret[j] = ret[j + 1];
                ret[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < 7; i++)
        printf("%d\n", ret[i]);
    return 0;
}