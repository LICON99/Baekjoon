#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[101];
    char b[11];
    char c[11];
    char ret[251];
    char *pret = ret;
    int a_len, b_len, c_len;
    int i;

    ret[0] = 0;
    scanf("%[^\n] %s %s", a, b, c);
    // printf("%s\n%s\n%s", a, b, c);
    a_len = strlen(a);
    b_len = strlen(b);
    c_len = strlen(c);
    for (i = 0; i < a_len; i++)
    {
        if (strncmp(a + i, b, b_len) == 0)
        {
            // for (int j = 0; j < c_len; j++)
            //     *pret++ = c[j];
            strcpy(pret, c);
            pret += c_len;
            i += b_len;
        }
        *pret++ = a[i];
    }
    *pret = 0;
    printf("%s", ret);
    return 0;
}
#include <stdio.h>
#include <string.h>


// 꼭 3차원 배열로 풀어야할까?
int main() {
    int N;
    int max_len, min_len;
    char str[101] = {0};
    char min[101][101] = {0};
    char max[101][101] = {0};
    char clean[101] = {0};
    char res_min[101] = {0};
    char res_max[101] = {0};
    int row, col;
    int row_min, row_max;
    int i, idx;


    scanf("%d", &N);
    getchar();

    max_len = -1;
    min_len = 101;
    int index = 0;
    while (N--) {
        gets(str);

        if (min_len > strlen(str)) {
            for (int i = 0; i <= row_min; i++) {
                strcpy(min[i], clean); // min배열 초기화
            }

            i = 0, idx = 0;
            row = 0;
            while (*(str + i) != '\0') {
                if (*(str + i) == ' ') {
                    row++;
                    idx = 0;
                    i += 1; // 공백 스킵
                }

                min[row][idx] = str[i];

                i++, idx++;
            }
            row_min = row;
            min_len = strlen(str);
        }
        if (max_len < strlen(str)) {
            for (int i = 0; i <= row_max; i++) {
                strcpy(max[i], clean); // max배열 초기화
            }

            i = 0, idx = 0;
            row = 0;
            while (*(str + i) != '\0') {
                if (*(str + i) == ' ') {
                    row++;
                    idx = 0;
                    i += 1; // 공백 스킵
                }

                max[row][idx] = str[i];

                i++, idx++;
            }

            row_max = row;
            max_len = strlen(str);
        }
    }

    // 가장 짧은 문자열의 가장 빠른 단어
    strcpy(res_min, min[0]);
    for (int i = 1; i <= row_min; i++) {
        if (strcmp(res_min, min[i]) > 0) {
            strcpy(res_min, min[i]);
        }
    }
    printf("%s\n", res_min);

    // 가장 긴 문자열의 가장 늦는 단어
    strcpy(res_max, max[0]);
    for (int i = 1; i <= row_max; i++) {
        if (strcmp(res_max, max[i]) < 0) {
            strcpy(res_max, max[i]);
        }
    }
    printf("%s", res_max);

    return 0;
}