/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** my_atoi
*/

#include "my.h"

int my_atoi(char *str)
{
    int i = 0;
    int res = 0;
    int sign = 1;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    for (; str[i] != '\0'; ++i) res = res * 10 + str[i] - '0';
    return (sign * res);
}
