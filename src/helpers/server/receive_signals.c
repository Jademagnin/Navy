/*
** EPITECH PROJECT, 2023
** navy
** File description:
** receive_signals
*/

#include "navy.h"
#include "my.h"

void interpret_data(game_t *game, char *data)
{
    if (my_strcmp(data, S_CONNECT) == 0) {
        game_data(NULL)->is_connected = 1;
        if (game_data(NULL)->is_server) {
            write(1, "\nenemy connected\n\n", 18);
            display_maps(game);
        }
        return;
    }
    if (handle_sent_hit(game, data)) return;

    game->turn = 1;
    handle_received_hit(game, data);
}

void callback_signal(int sig, siginfo_t *info, void *ucontext)
{
    (void) ucontext;
    (void) info;

    bin_to_list(sig == SIGUSR1 ? 0 : 1);
    usr_count(1);
    if (usr_count(0) == 8) {
        usr_count(-8);
        chr_count(1);
    }
    if (chr_count(0) == 2) {
        chr_count(-2);
        game_t *game = game_data(NULL);
        game->enemy_pid = info->si_pid;
        char *data = chr_to_cords(-1);
        interpret_data(game, data);
    }
}

void init_sigactions(void)
{
    struct sigaction action;

    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = callback_signal;
    sigemptyset(&action.sa_mask);
    if (sigaction(SIGUSR1, &action, NULL) == -1) return;
    if (sigaction(SIGUSR2, &action, NULL) == -1) return;
}
