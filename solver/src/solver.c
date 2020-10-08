/*
** EPITECH PROJECT, 2020
** solver.c for Dante project
** File description:
** 22/03/20 03:20
*/

#include "my.h"

void stock_display(solv_s *s)
{
    for (int y = 0; y < s->y_maze + 1; y++) {
        for (int x = 0; x < s->x_maze + 1; x++) {
            if (s->matrix_solv[y][x] == 0
                && s->matrix[y][x] == 0)
                s->maze[y][x] = '*';
            if (s->matrix_solv[y][x] == 0
                && s->matrix[y][x] == 1)
                s->maze[y][x] = 'X';
            if (s->matrix_solv[y][x] == 1
                && s->matrix[y][x] == 0)
                s->maze[y][x] = 'o';
        }
    }
}

int solver(solv_s *s, int y, int x)
{
    if ((y == s->y_maze) && (x == s->x_maze)) {
        s->matrix_solv[y][x] = 1;
        return (1);
    }
    if (y >= 0 && x >= 0 && y <= s->y_maze && x <= s->x_maze
        && s->matrix_solv[y][x] == 0 && s->matrix[y][x] == 0) {
        s->matrix_solv[y][x] = 1;
        if (solver(s, y + 1, x))
            return (1);
        if (solver(s, y, x + 1))
            return (1);
        if (solver(s, y - 1, x))
            return (1);
        if (solver(s, y, x - 1))
            return (1);
        s->matrix_solv[y][x] = 0;
        return (0);
    }
    return (0);
}

void matrix(solv_s *s)
{
    s->matrix = malloc(sizeof(int *) * (s->y_maze + 1));
    for (int y = 0; y < s->y_maze + 1; y++) {
        s->matrix[y] = malloc(sizeof(int) * (s->x_maze + 1));
        for (int x = 0; x < s->x_maze + 1; x++) {
            if (s->maze[y][x] == 'X')
                s->matrix[y][x] = 1;
            else
                s->matrix[y][x] = 0;
        }
    }
    s->matrix_solv = malloc(sizeof(int *) * (s->y_maze + 1));
    for (int y = 0; y < s->y_maze + 1; y++) {
        s->matrix_solv[y] = malloc(sizeof(int) * (s->x_maze + 1));
        for (int x = 0; x < s->x_maze + 1; x++)
            s->matrix_solv[y][x] = 0;
    }
}
