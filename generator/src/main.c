/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my.h"

static cases gest_err(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        return (false);
    if (is_digit(av[1]) == false
        || is_digit(av[2]) == false)
        return (false);
    if (ac == 4 && my_strcmp(av[3], "perfect") == false)
        return (false);
    if (my_getnbr(av[1]) == 0 || my_getnbr(av[2]) == 0)
        return (false);
    return (true);
}

static void init_struct(basic *all, char **av)
{
    all->maze = NULL;
    all->cols = my_getnbr(av[1]);
    all->rows = my_getnbr(av[2]);
    all->cnt = 0;
    all->p[0] = 0;
    all->p[1] = 0;
    init_end(all);
}

static void init_maze(basic *all)
{
    all->maze = malloc(sizeof(char *) * all->rows);
    for (int y = 0; y < all->rows; y++) {
        all->maze[y] = malloc(sizeof(char) * all->cols+1);
        all->maze[y][all->cols] = '\0';
        for (int x = 0; x < all->cols; x++) {
            if (y%2 == 0 && x%2 == 0)
                all->maze[y][x] = '*';
            else if (y%2 != 0 || x%2 != 0)
                all->maze[y][x] = 'X';
        }
    }
}

static void print_maze(basic *all, int ac)
{
    if (ac == 3)
        algo_maze2(all);
    else if (ac == 4)
        algo_maze1(all);
    for (int y = 0; y < all->rows; y++) {
        for (int x = 0; x < all->cols; x++) {
            if (all->maze[y][x] == 'c')
                my_putchar('*');
            else
                my_putchar(all->maze[y][x]);
        }
        free(all->maze[y]);
        if (y != all->rows-1)
            my_putchar('\n');
    }
    free(all->maze);
}

int main(int ac, char **av)
{
    basic all;
    time_t t;

    if (gest_err(ac, av) == false)
        return (84);
    srand((unsigned) time(&t));
    init_struct(&all, av);
    init_maze(&all);
    print_maze(&all, ac);
    return (0);
}
