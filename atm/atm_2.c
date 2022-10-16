#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_num(char* str)
{
    int i;

    i = 0;
    for (int j = 0; str[j]; j++)
    {
        if ((str[j] >= '0' && str[j] <= '9') && (str[j + 1] < '0' || str[j + 1] > '9'))
            i++;
    }
    return (i);
}

char** seperate_num(char* str)
{
    char** str_num;
    int     i = 0, j;

    str_num = (char**)malloc(sizeof(char*) * count_num(str));
    for (int k = 0; k < count_num(str); k++)
        str_num[k] = (char*)malloc(sizeof(char) * 10);
    for (int k = 0; str[k]; k++)
    {
        j = 0;
        if (str[k] >= '0' && str[k] <= '9')
        {
            while (str[k] >= '0' && str[k] <= '9')
            {
                str_num[i][j++] = str[k++];
                if (str[k] < '0' || str[k] > '9')
                {
                    str_num[i][j] = '\0';
                    break;
                }
            }
            i++;
        }
    }
    return (str_num);
}

int* convertToInt(char** str_num, char* str)
{
    int* num;

    num = (int*)malloc(sizeof(int) * count_num(str));
    for (int i = 0; i < count_num(str); i++)
        num[i] = atoi(str_num[i]);
    for (int i = 0; i < count_num(str); i++)
        free(str_num[i]);
    free(str_num);
    return (num);
}

int main()
{
    char* str;
    char** arr_str;
    int* num;
    int     sum = 0;
    str = malloc(sizeof(char)*100);
    scanf("%s", str);
    num = convertToInt(seperate_num(str), str);
    for (int i = 0; i < count_num(str); i++)
        sum += num[i];
    if (sum >= 10000)
        printf("ERROR!!");
    else if (sum / 10 < 1)
        printf("000%d", sum);
    else if (sum / 100 < 1)
        printf("00%d", sum);
    else if (sum / 1000 < 1)
        printf("0%d", sum);
    else
        printf("%d", sum);
    free(num);
    free(str);
}