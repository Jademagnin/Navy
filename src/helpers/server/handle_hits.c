/*
** EPITECH PROJECT, 2023
** navy
** File description:
** handle_hits
*/

#include "navy.h"

int receive_hit(game_t *game, char *cords)
{
    pos_t pos = cords_to_pos(cords);
    if (game->map[pos.y][pos.x] == 'x' || game->map[pos.y][pos.x] == 'o')
        return (0);
    if (game->map[pos.y][pos.x] == '.') {
        game->map[pos.y][pos.x] = 'o';
        return (0);
    }
    game->map[pos.y][pos.x] = 'x';
    game->enemy_points++;
    return (1);
}

void handle_received_hit(game_t *game, char *data)
{
    pos_t pos = cords_to_pos(data);
    if (receive_hit(game, data)) {
        write(1, data, 2);
        write(1, ": hit\n\n", 7);
        if (game->is_server) display_maps(game);
        game->map[pos.y][pos.x] = 'x';
        send_data(game->enemy_pid, S_HIT);
    } else {
        write(1, data, 2);
        write(1, ": missed\n\n", 10);
        if (game->is_server) display_maps(game);
        game->map[pos.y][pos.x] = 'o';
        send_data(game->enemy_pid, S_MISS);
    }
}

int handle_sent_hit(game_t *game, char *data)
{
    pos_t pos = cords_to_pos(game->last_attack);
    if (my_strcmp(data, S_HIT) == 0) {
        game->enemy_map[pos.y][pos.x] = 'x';
        write(1, game->last_attack, 2); write(1, ": hit\n\n", 7);
        if (!game->is_server) display_maps(game);
        game->points++;
        if (game->points == 14) return (1);
        write(1, "waiting for enemy's attack...\n", 30);
        return (1);
    }
    if (my_strcmp(data, S_MISS) == 0) {
        game->enemy_map[pos.y][pos.x] = 'o';
        write(1, game->last_attack, 2);
        write(1, ": missed\n\n", 10);
        if (!game->is_server) display_maps(game);
        if (game->points == 14) return (1);
        write(1, "waiting for enemy's attack...\n", 30);
        return (1);
    }
    return (0);
}
