/*
** EPITECH PROJECT, 2023
** navy
** File description:
** binary
*/

#include "navy.h"

char *chr_to_cords(char c)
{
    static char *cords = NULL;
    int index = chr_count(0);
    if (cords == NULL) {
        cords = malloc(sizeof(char) * 3);
        cords[2] = '\0';
    }
    if (c == -1) return cords;

    cords[index] = c;
    return (cords);
}

int bin_to_int(int *bin)
{
    int result = 0;
    int index = 0;

    for (int i = 7; i >= 0; i--) {
        result += bin[index] * my_pow(2, i);
        index++;
    }
    chr_to_cords((char) result);
    return (result);
}

int *bin_to_list(int number)
{
    static int *list = NULL;
    if (list == NULL) list = malloc(sizeof(int) * 8);
    if (number == -1) return list;

    int index = usr_count(0);
    list[index] = number;
    if (index == 7) {
        list = rev_bin_list(list);
        bin_to_int(list);
        list = NULL;
    }
    return (list);
}

int *rev_bin_list(int *list)
{
    int *result = malloc(sizeof(int) * 8);
    int index = 0;

    for (int i = 7; i >= 0; i--) {
        result[index] = list[i];
        index++;
    }
    return (result);
}
