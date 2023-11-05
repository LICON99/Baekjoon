#include <stdio.h>
#include <stdlib.h>

void print_arr(int *arr, int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("%d", arr[i]);
        if (i != m - 1)
            printf(" ");
    }
    printf("\n");
}
int is_valid_val(int *arr, int idx, int j)
{
    // printf("idx : %d\n", idx);
    // for (int i = 0; i <= idx - 1; i++)
    // {
    //     if (arr[i] > arr[i + 1])
    //         return 0;
    // }
    return 1;
}

void loop(int n, int m, int *arr, int idx)
{
    if (idx == m)
    {
        print_arr(arr, m);
        return;
    }
    for (int j = 1; j <= n; j++)
    {
        arr[idx] = j;
        if (is_valid_val(arr, idx, j))
            loop(n, m, arr, idx + 1);
    }
    return;
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[8] = {0};
    loop(n, m, arr, 0);
    return 0;
}