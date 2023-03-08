/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** my_tablen
*/

#include <unistd.h>

int my_tablen(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return (i);
}
