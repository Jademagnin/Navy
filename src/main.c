/*
** EPITECH PROJECT, 2023
** navy
** File description:
** main
*/

#include "../include/navy.h"

void help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./navy [first_player_pid] navy_positions\n", 42);
    write(1, "DESCRIPTION\n", 12);
    write(1, "\tfirst_player_pid: only for the 2nd player.", 43);
    write(1, " pid of the first player.\n", 26);
    write(1, "\tnavy_positions: file representing the positions of the", 55);
    write(1, " ships.\n", 8);
}

int main(int ac, char **av)
{
    if (ac > 1 && av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return (0);
    }
    if (ac != 2 && ac != 3) {
        write(2, "Invalid number of arguments, use -h for help.\n", 46);
        return (84);
    }
    game_t *game = init_game(ac, av);
    if (game == NULL) return (84);

    return (navy(game));
}
