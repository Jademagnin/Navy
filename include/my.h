/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my lib
*/

#ifndef my_h
    #define my_h

int my_getnbr(char *str);
int my_intlen(int value);
char *my_itoa(int nbr);
char *my_itoa_dest(char *dest, int nbr);
void my_putchar(char c);
void my_putstr(char const *str, int std);
char *my_revstr(char *str);
int my_strlen(char const *str);
int get_nbr_from(char *str, int i);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strchr(char *str, char c);
char *my_strtok(char *str, const char *delim);
char *my_strstr(char *str, char const *to_find);
char *my_strdup(char const *src);
int my_atoi(char *str);
int my_tablen(char **tab);
char *read_file(char const *path);
char *my_strchr(char *str, char c);
int get_file_size(char const *filepath);
int my_put_nbr(int nb);
int my_pow(int nb, int pow);
int is_file_exist(char *filepath);

#endif
