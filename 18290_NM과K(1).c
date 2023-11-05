#include <stdio.h>
typedef struct s_info
{
    int arr[100];
    int check_arr[100];
    int n;
    int m;
    int nm;
    int k;
    int sum;
} t_info;

void get_arr(t_info *info)
{
    for (int i = 0; i < info->nm; i++)
        scanf("%d", &info->arr[i]);
}

void init_check_arr(t_info *info)
{
    for (int i = 0; i < info->nm; i++)
        info->check_arr[i] = 1;
}

int is_valid(t_info *info, int idx)
{
    if (idx - 1 >= 0 && (idx - 1) % info->m != info->m - 1 && info->check_arr[idx - 1] == 0)
        return 0;
    if (idx + 1 < info->nm && (idx + 1) % info->m != 0 && info->check_arr[idx + 1] == 0)
        return 0;
    if (idx - info->m >= 0 && info->check_arr[idx - info->m] == 0)
        return 0;
    if (idx + info->m < info->nm && info->check_arr[idx + info->m] == 0)
        return 0;
    return 1;
}
void print_arr(t_info *info)
{
    for (int i = 0; i < info->nm; i++)
    {
        if (i % info->m == 0 && i != 0)
            printf("\n");
        printf("%d ", info->check_arr[i]);
    }
    printf("\n");
}
void bt(t_info *info, int idx, int sum, int cnt)
{
    if (cnt == info->k)
    {
        // print_arr(info);
        // printf("cnt : %d, sum : %d\n", cnt, sum);
        if (info->sum < sum)
            info->sum = sum;
        return;
    }
    if (info->nm == 1)
        return;
    if (idx == info->nm - 1)
        return;
    info->check_arr[idx + 1] = 0;
    if (is_valid(info, idx + 1))
        bt(info, idx + 1, sum + info->arr[idx + 1], cnt + 1);
    info->check_arr[idx + 1] = 1;
    bt(info, idx + 1, sum, cnt);
    return;
}
int main(void)
{
    t_info info;
    scanf("%d %d %d", &info.n, &info.m, &info.k);
    info.nm = info.n * info.m;
    info.sum = -2147483648;
    init_check_arr(&info);
    get_arr(&info);
    for (int idx = 0; idx < info.nm; idx++)
    {
        info.check_arr[idx] = 0;
        bt(&info, idx, info.arr[idx], 1);
        info.check_arr[idx] = 1;
    }
    printf("%d", info.sum);
    return 0;
}