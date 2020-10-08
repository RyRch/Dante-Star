/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** sokoban
*/

#include "my.h"

cases my_strcmp(char const *s1, char const *s2)
{
    int x = 0;
    int len = my_strlen(s2);

    for (int i = 0; s2[i] != '\0'; i++) {
        if (s1[i] == s2[i])
            x++;
    }
    if (x == len)
        return (true);
    return (false);
}
