/*
** EPITECH PROJECT, 2020
** putstr
** File description:
** putstr
*/

#include "my.h"

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
