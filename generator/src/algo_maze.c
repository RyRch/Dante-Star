/*
** EPITECH PROJECT, 2020
** init maze
** File description:
** init maze
*/

#include "my.h"

void init_end(basic *all)
{
    if (all->rows % 2 == 0 && all->cols % 2 == 0)
        all->end = (all->cols/2)*(all->rows/2);
    if (all->rows % 2 != 0 && all->cols % 2 != 0)
        all->end = ((all->cols+1)/2)*((all->rows+1)/2);
    if (all->rows % 2 == 0 && all->cols % 2 != 0)
        all->end = (((all->cols+1)/2)*(all->rows/2));
    if (all->rows % 2 != 0 && all->cols % 2 == 0)
        all->end = ((all->cols/2)*((all->rows+1)/2));
}

int choice1(basic *all, int m, char c)
{
    int nb = 0;

    if (all->p[1] < all->rows-m
        && all->maze[all->p[1]+m][all->p[0]] == c) {
        all->pos[0][1] = all->p[1]+m;
        all->pos[0][0] = all->p[0];
        nb++;
    }
    if (all->p[0] < all->cols-m
        && all->maze[all->p[1]][all->p[0]+m] == c) {
        all->pos[1][1] = all->p[1];
        all->pos[1][0] = all->p[0]+m;
        nb++;
    }
    return (nb);
}

int choice2(basic *all, int m, char c)
{
    int nb = 0;

    if (all->p[1] >= m
        && all->maze[all->p[1]-m][all->p[0]] == c) {
        all->pos[2][1] = all->p[1]-m;
        all->pos[2][0] = all->p[0];
        nb++;
    }
    if (all->p[0] >= m
        && all->maze[all->p[1]][all->p[0]-m] == c) {
        all->pos[3][1] = all->p[1];
        all->pos[3][0] = all->p[0]-m;
        nb++;
    }
    return (nb);
}

void algo_maze1(basic *all)
{
    for (int i = 0; i < all->end; ) {
        if (all->maze[all->p[1]][all->p[0]] == '*') {
            all->maze[all->p[1]][all->p[0]] = 'c';
            init_pos(all);
            i++;
        }
        if (find_pos(all, 2, '*') == false) {
            find_pos(all, 2, 'c');
            init_pos(all);
        }
    }
    all->maze[all->rows-1][all->cols-1] = '*';
    all->maze[all->rows-1][all->cols-2] = '*';
}

void algo_maze2(basic *all)
{
    all->maze[all->rows-1][all->cols-1] = '*';
    all->maze[all->rows-1][all->cols-2] = '*';
    while (1) {
        if (all->maze[all->p[1]][all->p[0]] == '*') {
            all->maze[all->p[1]][all->p[0]] = 'c';
            init_pos(all);
        }
        if (find_pos(all, 2, '*') == false) {
            find_pos(all, 2, 'c');
            init_pos(all);
        }
        if (all->p[0] == (all->cols-1) && all->p[1] == (all->rows-1)
            || all->p[0] == (all->cols-2) && all->p[1] == (all->rows-1)
            || all->p[0] == (all->cols-2) && all->p[1] == (all->rows-2)
            || all->p[0] == (all->cols-1) && all->p[1] == (all->rows-2))
            break;
    }
}
