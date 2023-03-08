/*
** EPITECH PROJECT, 2023
** navy
** File description:
** navy
*/

#include "../include/navy.h"
#include "../include/my.h"

char *input_attack(void)
{
    char *str = NULL;
    size_t size = 0;
    write(1, "attack: ", 8);
    getline(&str, &size, stdin);
    return (str);
}

int navy(game_t *game)
{
    game_data(game);
    int navy_loop = game_loop(game);

    if (navy_loop == I_WON) {
        display_maps(game);
        write(1, "I won\n", 6);
        return (0);
    } else if (navy_loop == ENEMY_WON) {
        display_maps(game);
        write(1, "Enemy won\n", 10);
        return (1);
    }

    return (84);
}
