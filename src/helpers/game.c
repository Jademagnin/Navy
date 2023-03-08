/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** game
*/

#include "navy.h"

game_t *game_data(game_t *game)
{
    static game_t *GAME = NULL;
    if (game == NULL) return GAME;
    GAME = game;
    return (GAME);
}

int play_turn(game_t *game)
{
    if (game->turn) {
        char *pos = input_attack();
        while (check_data(pos) == 84) pos = input_attack();
        if (send_data(game->enemy_pid, pos) == 84) return (84);
        game->last_attack = pos;
        game->turn = 0;
        game_data(game);
    }
    return (0);
}

int game_loop(game_t *game)
{
    if (game->is_server) {
        disp_my_pid(game->pid);
        write(1, "waiting for enemy connection...\n", 32);
    } else {
        if (send_data(game->enemy_pid, S_CONNECT) == 84) return (84);
        disp_my_pid(game->pid);
        write(1, "successfully connected\n\n", 24);
        display_maps(game);
        write(1, "waiting for enemy's attack...\n", 30);
        game->is_connected = 1;
    }
    init_sigactions();
    while (1) {
        usleep(100000);
        if (!game->is_connected) continue;
        if (game->enemy_points == 14) return (ENEMY_WON);
        if (game->points == 14) return (I_WON);
        if (play_turn(game) == 84) return (84);
    }
}

game_t *init_game(int ac, char **av)
{
    game_t *game = malloc(sizeof(game_t));
    if (game == NULL) return (NULL);
    char *filepath = av[ac - 1];
    if (is_file_exist(filepath) == 84) return (NULL);
    if (check_file_size(filepath) == 84) return (NULL);
    game->is_server = ac == 2;
    game->boats = init_boats(filepath);
    if (game->boats == NULL) return (NULL);
    game->map = init_map(game->boats);
    if (game->map == NULL) return (NULL);
    game->enemy_map = init_enemy_map();
    if (game->enemy_map == NULL) return (NULL);
    game->turn = game->is_server;
    game->pid = getpid();
    game->is_connected = 0;
    game->enemy_pid = game->is_server ? 0 : my_atoi(av[1]);
    game->points = 0;
    game->enemy_points = 0;
    return (game);
}
