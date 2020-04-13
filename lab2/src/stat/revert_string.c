#include "revert_string.h"
#include "swap.c"
#include <stdio.h>

void RevertString(char *str)
{
    int(i) = 0;
    while(str[i]) i++; //считаем длину строки
    int j = 0;
    int k = 0;
    for(j = 0; j < i / 2; j++)
    {
       Swap(&str[j], &str[i - j - 1]);//меняем крайние эл местами
    }
    for(k = 0; k < i; k++)//Выводим перевёрнутую строку
    {
        printf("%c", str[k]);
    }
    
}
