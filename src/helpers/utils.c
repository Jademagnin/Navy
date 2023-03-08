/*
** EPITECH PROJECT, 2023
** navy
** File description:
** utils
*/

#include "../../include/navy.h"
#include "../../include/my.h"

int usr_count(int inc)
{
    static int USR = 0;
    USR += inc;
    return USR;
}

int chr_count(int inc)
{
    static int CHR = 0;
    CHR += inc;
    return CHR;
}

int check_file(char *buffer)
{
    int j = 0;
    int len = my_strlen(buffer);
    if (len != 32)
        return (84);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            j++;
    }
    if (j != 4)
        return (84);
    if (buffer[0] != '2' && buffer[0] != '3' && buffer[0] != '4'
    && buffer[0] != '5')
        return (84);
    return (0);
}

void disp_my_pid(int pid)
{
    write(1, "my_pid: ", 8);
    my_put_nbr(pid);
    write(1, "\n", 1);
}
