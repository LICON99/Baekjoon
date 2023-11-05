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
    for (int i = 0; i < idx; i++)
    {
        if (arr[i] == j)
            return 0;
    }
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
        if (is_valid_val(arr, idx, j))
        {
            arr[idx] = j;
            loop(n, m, arr, idx + 1);
        }
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