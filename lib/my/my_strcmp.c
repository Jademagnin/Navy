/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0') return (0);
    return (s1[i] - s2[i]);
}
