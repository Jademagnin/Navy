/*
** EPITECH PROJECT, 2023
** navy
** File description:
** send_signals
*/

#include "navy.h"

int send_sigusr(int pid, int sig_num)
{
    int sig = (sig_num == 1) ? SIGUSR2 : SIGUSR1;

    if (kill(pid, sig) == -1) {
        write(2, "Error: invalid PID, could not send signal\n", 42);
        return (84);
    }
    return (0);
}

int send_int(int pid, int num)
{
    int i = 0;
    int sig = 0;

    while (i < 8) {
        sig = (num >> i) & 1;
        int res = send_sigusr(pid, sig);
        if (res == 84) return (84);
        usleep(500);
        i++;
    }

    return (0);
}

int send_data(int pid, char *str)
{
    if (send_int(pid, str[0]) == 84) return (84);
    if (send_int(pid, str[1]) == 84) return (84);

    return (0);
}
