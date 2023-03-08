/*
** EPITECH PROJECT, 2023
** navy
** File description:
** map
*/

#include "navy.h"

void display_map_line(char **map, int i)
{
    my_put_nbr(i + 1);
    write(1, "|", 1);
    for (int j = 0; j < 8; j++) {
        write(1, &map[i][j], 1);
        if (j != 7) write(1, " ", 1);
    }
    write(1, "\n", 1);
}

void display_map(char **map)
{
    write(1, " |A B C D E F G H\n", 18);
    write(1, "-+---------------\n", 18);
    for (int i = 0; i < 8; i++) {
        display_map_line(map, i);
    }
}

void display_maps(game_t *game)
{
    write(1, "my positions:\n", 14);
    display_map(game->map);
    write(1, "\nenemy's positions:\n", 20);
    display_map(game->enemy_map);
    write(1, "\n", 1);
}

char **init_map(boat_t **boats)
{
    char **map = malloc(sizeof(char *) * 9);
    if (map == NULL) return (NULL);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        map[i] = my_strdup("........");
    }
    for (int i = 0; boats[i] != NULL; i++) {
        if (place_boats(boats, map, i) == 84) {
            write(2, "Error: invalid boat placement\n", 30);
            return (NULL);
        }
    }

    return (map);
}

char **init_enemy_map(void)
{
    char **map = malloc(sizeof(char *) * 9);
    if (map == NULL) return (NULL);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        map[i] = my_strdup("........");
    }

    return (map);
}
