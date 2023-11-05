#include <stdio.h>
#include <string.h>
typedef struct s_loc
{
    int i;
    int j;
} t_loc;

void get_map(int n, int m, char map[][11], t_loc *b, t_loc *r)
{
    for (int i = 0; i < n; i++)
        scanf("%s", map[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 'B')
            {
                b->i = i;
                b->j = j;
                map[i][j] = '.';
            }
            if (map[i][j] == 'R')
            {
                r->i = i;
                r->j = j;
                map[i][j] = '.';
            }
        }
    }
}
void print_map(char map[][11], int n, int m, t_loc b, t_loc r)
{
    map[r.i][r.j] = 'R';
    map[b.i][b.j] = 'B';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%c", map[i][j]);
        printf("\n");
    }
    map[r.i][r.j] = '.';
    map[b.i][b.j] = '.';
}
int tilt_right(char map[][11], t_loc *b, t_loc *r)
{
    t_loc tmp_b = *b;
    t_loc tmp_b2 = *b;
    t_loc tmp_r = *r;
    while (map[tmp_b2.i][tmp_b2.j + 1] != '#')
    {
        if (map[tmp_b2.i][tmp_b2.j + 1] == 'O')
            return 0;
        tmp_b2.j++;
    }
    for (int i = 0; i < 2; i++)
    {
        while (map[b->i][b->j + 1] == '.' && !(b->i == r->i && b->j + 1 == r->j))
            b->j++;
        while (map[r->i][r->j + 1] == '.' && !(b->i == r->i && b->j == r->j + 1))
            r->j++;
    }
    if (map[r->i][r->j + 1] != 'O' && tmp_b.i == b->i && tmp_b.j == b->j && tmp_r.i == r->i && tmp_r.j == r->j)
    {
        *b = tmp_b;
        *r = tmp_r;
        return 0;
    }
    return 1;
}
int tilt_left(char map[][11], t_loc *b, t_loc *r)
{
    t_loc tmp_b = *b;
    t_loc tmp_b2 = *b;
    t_loc tmp_r = *r;
    while (map[tmp_b2.i][tmp_b2.j - 1] != '#')
    {
        if (map[tmp_b2.i][tmp_b2.j - 1] == 'O')
            return 0;
        tmp_b2.j--;
    }
    for (int i = 0; i < 2; i++)
    {
        while (map[b->i][b->j - 1] == '.' && !(b->i == r->i && b->j - 1 == r->j))
            b->j--;
        while (map[r->i][r->j - 1] == '.' && !(b->i == r->i && b->j == r->j - 1))
            r->j--;
    }
    if (map[r->i][r->j - 1] != 'O' && tmp_b.i == b->i && tmp_b.j == b->j && tmp_r.i == r->i && tmp_r.j == r->j)
    {
        *b = tmp_b;
        *r = tmp_r;
        return 0;
    }
    return 1;
}
int tilt_down(char map[][11], t_loc *b, t_loc *r)
{
    t_loc tmp_b = *b;
    t_loc tmp_b2 = *b;
    t_loc tmp_r = *r;
    while (map[tmp_b2.i + 1][tmp_b2.j] != '#')
    {
        if (map[tmp_b2.i + 1][tmp_b2.j] == 'O')
            return 0;
        tmp_b2.i++;
    }
    for (int i = 0; i < 2; i++)
    {
        while (map[b->i + 1][b->j] == '.' && !(b->i + 1 == r->i && b->j == r->j))
            b->i++;
        while (map[r->i + 1][r->j] == '.' && !(b->i == r->i + 1 && b->j == r->j))
            r->i++;
    }
    if (map[r->i + 1][r->j] != 'O' && tmp_b.i == b->i && tmp_b.j == b->j && tmp_r.i == r->i && tmp_r.j == r->j)
    {
        *b = tmp_b;
        *r = tmp_r;
        return 0;
    }
    return 1;
}
int tilt_up(char map[][11], t_loc *b, t_loc *r)
{
    t_loc tmp_b = *b;
    t_loc tmp_b2 = *b;
    t_loc tmp_r = *r;
    while (map[tmp_b2.i - 1][tmp_b2.j] != '#')
    {
        if (map[tmp_b2.i - 1][tmp_b2.j] == 'O')
            return 0;
        tmp_b2.i--;
    }
    for (int i = 0; i < 2; i++)
    {
        while (map[b->i - 1][b->j] == '.' && !(b->i - 1 == r->i && b->j == r->j))
            b->i--;
        while (map[r->i - 1][r->j] == '.' && !(b->i == r->i - 1 && b->j == r->j))
            r->i--;
    }
    if (map[r->i - 1][r->j] != 'O' && tmp_b.i == b->i && tmp_b.j == b->j && tmp_r.i == r->i && tmp_r.j == r->j)
    {
        *b = tmp_b;
        *r = tmp_r;
        return 0;
    }
    return 1;
}

void cal_map(char map[][11], t_loc b, t_loc r, int *cnt, int tmp_cnt)
{
    t_loc tmp_b = b, tmp_r = r;
    if (tmp_cnt > 10)
        return;
    if (tilt_right(map, &b, &r))
    {
        tmp_cnt++;
        if (map[r.i][r.j + 1] == 'O')
        {
            if (*cnt > tmp_cnt)
                *cnt = tmp_cnt;
            return;
        }
        else
            cal_map(map, b, r, cnt, tmp_cnt);
        tmp_cnt--;
        b = tmp_b;
        r = tmp_r;
    }

    if (tilt_down(map, &b, &r))
    {
        tmp_cnt++;
        if (map[r.i + 1][r.j] == 'O')
        {
            if (*cnt > tmp_cnt)
                *cnt = tmp_cnt;
            return;
        }
        else
            cal_map(map, b, r, cnt, tmp_cnt);
        tmp_cnt--;
        b = tmp_b;
        r = tmp_r;
    }
    if (tilt_left(map, &b, &r))
    {
        tmp_cnt++;
        if (map[r.i][r.j - 1] == 'O')
        {
            if (*cnt > tmp_cnt)
                *cnt = tmp_cnt;
            return;
        }
        else
            cal_map(map, b, r, cnt, tmp_cnt);
        tmp_cnt--;
        b = tmp_b;
        r = tmp_r;
    }
    if (tilt_up(map, &b, &r))
    {
        tmp_cnt++;
        if (map[r.i - 1][r.j] == 'O')
        {
            if (*cnt > tmp_cnt)
                *cnt = tmp_cnt;
            return;
        }
        else
            cal_map(map, b, r, cnt, tmp_cnt);
        tmp_cnt--;
        b = tmp_b;
        r = tmp_r;
    }
    return;
}

int main(void)
{
    t_loc b;
    t_loc r;
    int n, m;
    int cnt = 2147483647;
    char map[11][11];
    scanf("%d %d", &n, &m);
    get_map(n, m, map, &b, &r);
    cal_map(map, b, r, &cnt, 0);
    printf("%d", cnt > 10 ? -1 : cnt);
    return 0;
}