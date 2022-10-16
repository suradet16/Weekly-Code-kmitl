#include <stdio.h>
#include <string.h>

int main()
{
    char    str[100];
    int     num = 0;
    int     sum = 0;
    char    prev, now;

    prev = 'n';
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            now = 'c';
        else if (str[i] >= '0' && str[i] <= '9')
        {
            now = 'n';
        }
        if (now == 'n' && prev == 'n')
            num = num * 10 + (str[i] - '0');
        if (now == 'n' && prev == 'c')
            num = str[i] - '0';
        if ((now == 'c' && prev == 'n') || (now == 'n' && i == strlen(str) - 1))
        {
            sum += num;
            num = 0;
        }
        prev = now;
    }
    if (sum >= 10000)
        printf("ERROR!!");
    else if (sum / 10 < 1)
        printf("000%d\n", sum);
    else if (sum / 100 < 1)
        printf("00%d\n", sum);
    else if (sum / 1000 < 1)
        printf("0%d\n", sum);
    else
        printf("%d\n", sum);
}