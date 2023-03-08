/*
** EPITECH PROJECT, 2023
** navy
** File description:
** errors
*/

#include "navy.h"

int check_data(char *str)
{
    if (str[0] < 'A' || str[0] > 'H') {
        write(1, "wrong position\n", 15);
        return (84);
    }
    if (str[1] < '1' || str[1] > '8') {
        write(1, "wrong position\n", 15);
        return (84);
    }
    if (my_strlen(str) != 3) {
        write(1, "wrong position\n", 15);
        return (84);
    }
    return (0);
}

int check_size(boat_t *boat)
{
    if (boat->orientation == 'H') {
        if (boat->pos_2.x - boat->pos_1.x != boat->type - 1) return (84);
    } else {
        if (boat->pos_2.y - boat->pos_1.y != boat->type - 1) return (84);
    }

    return (0);
}

int check_cheater(boat_t *boat)
{
    if (boat->pos_1.x == boat->pos_2.x && boat->pos_2.y ==
        boat->pos_1.y)
        return (84);
    if (boat->pos_1.x != boat->pos_2.x && boat->pos_2.y !=
        boat->pos_1.y)
        return (84);
    if (boat->pos_1.x > 8 || boat->pos_1.y > 8 ||
        boat->pos_2.x > 8 || boat->pos_2.y > 8)
        return (84);
    if (boat->pos_1.x < 0 || boat->pos_1.y < 0 ||
        boat->pos_2.x < 0 || boat->pos_2.y < 0)
        return (84);
    if (check_size(boat) == 84) return (84);
    return (0);
}

int check_boat(char *str)
{
    if (str[0] < '2' || str[0] > '5')
        return (84);
    if (str[2] < 'A' || str[2] > 'H')
        return (84);
    if (str[3] < '1' || str[3] > '8')
        return (84);
    if (str[5] < 'A' || str[5] > 'H')
        return (84);
    if (str[6] < '1' || str[6] > '8')
        return (84);
    if (str[1] != ':' || str[4] != ':')
        return (84);
    if (str[2] == str[5] && str[3] == str[6])
        return (84);
    if (str[2] != str[5] && str[3] != str[6])
        return (84);
    if (str[7] != '\n' && str[7] != '\0')
        return (84);

    return (0);
}

int check_file_size(char *filepath)
{
    int size = get_file_size(filepath);

    if ((size != 32 && size != 31) || size == -1) {
        write(2, "Error: File size is not correct\n", 32);
        return (84);
    }
    return (0);
}
