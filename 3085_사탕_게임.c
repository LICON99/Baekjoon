#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_info
{
    int a;
    int b;
    int max;
    int n;
    int is_col;
} t_info;

void debug_arr(t_info *info, char **arr)
{
    for (int i = 0; i < info->n; i++)
    {
        for (int j = 0; j < info->n; j++)
            printf("%c ", arr[i][j]);
        printf("\n");
    }
}

char **alloc_arr(t_info *info)
{
    int n = 0;
    char **arr;
    char tmp[51];

    scanf("%d", &n);
    arr = (char **)malloc(sizeof(char *) * (n + 1));
    if (!arr)
        return NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", tmp);
        arr[i] = (char *)malloc(sizeof(char) * (n + 1));
        for (int j = 0; j < n; j++)
            arr[i][j] = tmp[j];
        arr[i][n] = 0;
    }
    arr[n] = NULL;
    info->n = n;
    //    debug_arr(n, arr);
    return arr;
}

void idx_change(char **arr, t_info *info)
{
    char tmp;
    int a = info->a;
    int b = info->b;
    tmp = arr[a][b];
    if (info->is_col == 1)
    {
        arr[a][b] = arr[a][b + 1];
        arr[a][b + 1] = tmp;
    }
    else
    {
        arr[a][b] = arr[a + 1][b];
        arr[a + 1][b] = tmp;
    }
}

void check_arr(char **arr, t_info *info)
{
    int cnt = 1;
    int max = cnt;

    idx_change(arr, info);
    for (int i = 0; i < info->n; i++)
    {
        cnt = 1;
        for (int j = 0; j < info->n - 1; j++)
        {
            if (arr[i][j] != arr[i][j + 1])
                cnt = 0;
            cnt++;
            if (cnt > max)
                max = cnt;
        }
    }
    for (int i = 0; i < info->n; i++)
    {
        cnt = 1;
        for (int j = 0; j < info->n - 1; j++)
        {
            if (arr[j][i] != arr[j + 1][i])
                cnt = 0;
            cnt++;
            if (cnt > max)
                max = cnt;
        }
    }
    // debug_arr(info, arr);
    // printf("---%d---\n", max);
    if (info->max < max)
        info->max = max;
    idx_change(arr, info);
}

t_info *init_info(t_info *info)
{
    t_info *ret;

    ret = (t_info *)malloc(sizeof(t_info));
    if (!ret)
        return NULL;
    ret->a = 0;
    ret->b = 0;
    ret->n = 0;
    ret->max = 1;
    ret->is_col = 1;
    return ret;
}

int main(void)
{
    t_info *info;
    char **arr;

    info = init_info(info);
    if (!info)
        return 0;
    arr = alloc_arr(info);
    if (!arr)
        return 0;
    for (int i = 0; i < info->n; i++)
    {
        for (int j = 0; j < info->n - 1; j++)
        {
            if (arr[i][j] != arr[i][j + 1])
            {
                info->a = i;
                info->b = j;
                check_arr(arr, info);
            }
        }
    }
    info->is_col = 0;
    for (int i = 0; i < info->n; i++)
    {
        for (int j = 0; j < info->n - 1; j++)
        {
            if (arr[j][i] != arr[j + 1][i])
            {
                info->a = j;
                info->b = i;
                check_arr(arr, info);
            }
        }
    }
    printf("%d", info->max);
    return 0;
}