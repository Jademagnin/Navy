/*
** EPITECH PROJECT, 2023
** navy
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #define S_CONNECT "00"
    #define S_HIT "01"
    #define S_MISS "02"
    #define ENEMY_WON 10
    #define I_WON 11

typedef struct pos_s {
    int x;
    int y;
} pos_t;

typedef struct boat_s {
    int type;
    pos_t pos_1;
    pos_t pos_2;
    char orientation;
} boat_t;

typedef struct game_s {
    int pid;
    int enemy_pid;
    int turn;
    int is_server;
    int is_connected;
    boat_t **boats;
    char **map;
    char **enemy_map;
    char *last_attack;
    int points;
    int enemy_points;
} game_t;

#endif /* !STRUCT_H_ */
