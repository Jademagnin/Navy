/*
** EPITECH PROJECT, 2023
** navy
** File description:
** placement
*/

#include "navy.h"

int place_vertical(boat_t *boat, char **map)
{
    for (int j = boat->pos_1.y; j <= boat->pos_2.y; j++) {
        if (map[j][boat->pos_1.x] != '.') return (84);
        map[j][boat->pos_1.x] = boat->type + '0';
    }
    return (0);
}

int place_horizontal(boat_t *boat, char **map)
{
    for (int j = boat->pos_1.x; j <= boat->pos_2.x; j++) {
        if (map[boat->pos_1.y][j] != '.') return (84);
        map[boat->pos_1.y][j] = boat->type + '0';
    }
    return (0);
}

int place_boats(boat_t **boats, char **map, int i)
{
    if (boats[i]->orientation == 'V') {
        if (place_vertical(boats[i], map) == 84) return (84);
    } else {
        if (place_horizontal(boats[i], map) == 84) return (84);
    }
    return (0);
}
