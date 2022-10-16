#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void    sort6(char** str)
{
    char* tmp;
    int     k, j;

    for (int i = 0; i < 6; i++)
    {
        int j_min = i;
        for (j = i + 1; j < 6; j++)
            if (strcmp(str[j], str[j_min]) < 0)
                j_min = j;
        if (j_min != i)
        {
            strcpy(tmp, str[i]);
            strcpy(str[i], str[j_min]);
            strcpy(str[j_min], tmp);
        }
    }
    k = 0;
    printf("-------------------------------\n");
    while (k < 6)
    {
        while (k < 5 && strcmp(str[k], str[k + 1]) == 0)
            k++;
        printf("%s\n", str[k]);
        k++;
    }
    for (int i = 0; i < 6; i++)
        free(str[i]);
    free(str);
}

int main()
{
    char** str;

    str = (char**)malloc(sizeof(char*) * 6);
    for (int i = 0; i < 6; i++)
        str[i] = (char*)malloc(sizeof(char) * 30);
    for (int i = 0; i < 6; i++)
        scanf("%s", str[i]);
    sort6(str);
}