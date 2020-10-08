/*
** EPITECH PROJECT, 2020
** digit
** File description:
** digit
*/

#include "my.h"

cases is_digit(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57)
            return (false);
    }
    return (true);
}
