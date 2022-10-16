#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void** sort(char** str)
{
    int     count = 1;
    char* tmp;

    tmp = (char*)malloc(sizeof(char) * 30);
    while (count != 0)
    {
        count = 0;
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(str[i], str[i + 1]) > 0)
            {
                strcpy(tmp, str[i]);
                strcpy(str[i], str[i + 1]);
                strcpy(str[i + 1], tmp);
                count++;
            }
        }
    }
    free(tmp);
}

int main()
{
    char** sort_str;
    char** str;

    str = (char**)malloc(sizeof(char*) * 6);
    for (int i = 0; i < 6; i++)
        str[i] = (char*)malloc(sizeof(char) * 30);
    for (int i = 0; i < 6; i++)
        scanf("%s", str[i]);
    sort(str);
    printf("-------------------------------\n");
    for (int i = 0; i < 6; i++)
    {
        while (i < 5 && strcmp(str[i], str[i + 1]) == 0)
            i++;
        printf("%s\n", str[i]);
    }
    for (int i = 0; i < 6; i++)
        free(str[i]);
    free(str);
}