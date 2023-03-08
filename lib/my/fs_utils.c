/*
** EPITECH PROJECT, 2023
** giantman
** File description:
** fs_utils
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

int is_file_exist(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        write(2, "Invalid map, file doesn't exist.\n", 33);
        return (84);
    }
    if (read(fd, NULL, 0) == -1) {
        write(2, "Invalid map, file is not readable.\n", 35);
        return (84);
    }

    close(fd);
    return (0);
}

int get_file_size(char const *path)
{
    int fd = open(path, O_RDONLY);
    int size = 0;
    char buffer[1];

    if (fd == -1) return (-1);
    while (read(fd, buffer, 1) > 0) size++;
    close(fd);

    return (size);
}

char *read_file(char const *path)
{
    int fd = open(path, O_RDONLY);
    int size = get_file_size(path);
    char *buffer = malloc(sizeof(char) * (size + 1));

    if (fd == -1 || buffer == NULL)
        return (NULL);
    read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}
