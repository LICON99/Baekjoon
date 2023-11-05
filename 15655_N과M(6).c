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
    for (int i = 0; i <= idx - 1; i++)
    {
        if (arr[i] >= arr[idx])
            return 0;
    }
    return 1;
}

void loop(int n, int m, int *arr, int idx, int *table)
{
    if (idx == m)
    {
        print_arr(arr, m);
        return;
    }
    for (int j = 0; j < n; j++)
    {
        arr[idx] = table[j];
        if (is_valid_val(arr, idx, j))
            loop(n, m, arr, idx + 1, table);
    }
    return;
}
void bubble(int *table, int n)
{
    int tmp;
    for (int j = n - 1; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (table[i] > table[i + 1])
            {
                tmp = table[i];
                table[i] = table[i + 1];
                table[i + 1] = tmp;
            }
        }
    }
}
int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int table[8];
    for (int i = 0; i < n; i++)
        scanf("%d", &table[i]);
    bubble(table, n);
    int arr[8] = {0};
    loop(n, m, arr, 0, table);
    return 0;
}