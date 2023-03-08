/*
** EPITECH PROJECT, 2023
** navy
** File description:
** coordinates
*/

#include "navy.h"

pos_t cords_to_pos(char *cords)
{
    if (cords == NULL) return ((pos_t) {0, 0});
    pos_t pos;
    pos.x = (int) (cords[0] - 65);
    pos.y = (cords[1] - '0') - 1;
    return (pos);
}

char *charcat(char x, char y)
{
    char *str = malloc(sizeof(char) * 3);
    str[0] = x;
    str[1] = y;
    str[2] = '\0';
    return (str);
}

boat_t *init_boat(char *filepath, int line)
{
    boat_t *boat = malloc(sizeof(boat_t));
    char *boat_arg = get_line(filepath, line);
    if (boat_arg == NULL) return (NULL);
    int is_boat_valid = check_boat(boat_arg);
    if (is_boat_valid == 84) return (NULL);
    if ((boat_arg[0] - '0') != line + 2) return (NULL);
    boat->type = boat_arg[0] - '0';
    char *cord_1 = charcat(boat_arg[2], boat_arg[3]);
    char *cord_2 = charcat(boat_arg[5], boat_arg[6]);
    boat->pos_1 = cords_to_pos(cord_1);
    boat->pos_2 = cords_to_pos(cord_2);
    boat->orientation = (boat->pos_1.x == boat->pos_2.x) ? 'V' : 'H';
    return (boat);
}

boat_t **init_boats(char *filepath)
{
    boat_t **boats = malloc(sizeof(char *) * 5);
    if (boats == NULL) return (NULL);
    for (int i = 0; i < 4; i++) {
        boats[i] = init_boat(filepath, i);
        if (boats[i] == NULL) {
            write(1, "Invalid map, boat format is incorrect.\n", 39);
            return (NULL);
        }
        if (check_cheater(boats[i]) == 84) {
            write(1, "Invalid map, boat size is incorrect.\n", 37);
            return (NULL);
        }
    }
    boats[4] = NULL;
    return (boats);
}

char *get_line(char *filepath, int line)
{
    FILE *fp = fopen(filepath, "r");
    char *buffer = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;

    if (fp == NULL) return (NULL);

    while ((read = getline(&buffer, &len, fp)) != -1) {
        if (i == line) {
            return (buffer);
        }
        i++;
    }
    fclose(fp);
    return (NULL);
}
