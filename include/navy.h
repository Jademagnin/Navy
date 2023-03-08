/*
** EPITECH PROJECT, 2023
** navy
** File description:
** navy
*/

#ifndef navy_h
    #define navy_h
    #define _XOPEN_SOURCE 700

    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <signal.h>
    #include <time.h>
    #include <string.h>
    #include "my.h"
    #include "struct.h"

int navy(game_t *game);
int check_file(char *buffer);
void init_sigactions(void);
int send_int(int pid, int num);
int bin_to_int(int *bin);
int *rev_bin_list(int *list);
int *bin_to_list(int number);
int usr_count(int inc);
char **init_map(boat_t **boats);
char *get_line(char *filepath, int line);
void display_map(char **map);
pos_t cords_to_pos(char *cords);
boat_t **init_boats(char *filepath);
int send_data(int pid, char *str);
int chr_count(int inc);
char *chr_to_cords(char c);
game_t *init_game(int ac, char **av);
int game_loop(game_t *game);
game_t *game_data(game_t *game);
char **init_enemy_map(void);
int receive_hit(game_t *game, char *cords);
char *input_attack(void);
void interpret_data(game_t *game, char *data);
void display_maps(game_t *game);
int check_boat(char *str);
int check_cheater(boat_t *boat);
int check_data(char *str);
int handle_sent_hit(game_t *game, char *data);
void handle_received_hit(game_t *game, char *data);
int place_boats(boat_t **boats, char **map, int i);
void disp_my_pid(int pid);
int check_file_size(char *filepath);

#endif
