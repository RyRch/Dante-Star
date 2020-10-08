/*
** EPITECH PROJECT, 2020
** gest_pos
** File description:
** gest_pos
*/

#include "my.h"

void init_pos(basic *all)
{
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 2; x++)
            all->pos[y][x] = -1;
    }
}

cases find_pos(basic *all, int m, char c)
{
    int tmp[4] = {-1, -1, -1, -1};
    int nb = choice1(all, m, c)+choice2(all, m, c);
    int w = 0;

    if (nb == 0)
        return (false);
    for (int i = 0; i < 4; i++) {
        if (all->pos[i][0] >= 0) {
            tmp[w] = i;
            w++;
        }
        if (w == 1 && nb == 1)
            break;
    }
    move_player(all, tmp, w, c);
    return (true);
}

void move_player(basic *all, int tmp[4], int w, char c)
{
    int r = 0;

    if (w == 1) {
        all->p[0] = all->pos[tmp[0]][0];
        all->p[1] = all->pos[tmp[0]][1];
        if (c == '*')
            break_wall(all, tmp[0]);
    } else {
        r = rand() % w;
        all->p[0] = all->pos[tmp[r]][0];
        all->p[1] = all->pos[tmp[r]][1];
        if (c == '*')
            break_wall(all, tmp[r]);
    }
}

void break_wall(basic *all, int val)
{
    if (val % 2 == 0 && val < 2)
        all->maze[all->p[1]-1][all->p[0]] = 'c';
    if (val % 2 == 0 && val > 1)
        all->maze[all->p[1]+1][all->p[0]] = 'c';
    if (val % 2 != 0 && val < 2)
        all->maze[all->p[1]][all->p[0]-1] = 'c';
    if (val % 2 != 0 && val > 1)
        all->maze[all->p[1]][all->p[0]+1] = 'c';
}
