/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** my_strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dest = malloc(sizeof(char) * (len + 1));

    if (dest == NULL) return (NULL);
    for (int i = 0; i < len; i++)
        dest[i] = src[i];
    dest[len] = '\0';
    return (dest);
}
