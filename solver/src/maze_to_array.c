/*
** EPITECH PROJECT, 2020
** maze_to_array.c progrm for Dante Alighieri
** File description:
** 19/03/20 16:54
*/

#include "my.h"

void free_array(solv_s *s)
{
    for (int y = 0; y < s->y_maze + 1; y++) {
        free(s->maze[y]);
        free(s->matrix_solv[y]);
        free(s->matrix[y]);
    }
    free(s->buff_maze);
}

void get_x_y(solv_s *s)
{
    for (int i = 0; s->buff_maze[i] != '\n'; i++)
        s->x_maze = i;
    for (int i = 0; s->buff_maze[i]; i++)
        if (s->buff_maze[i] == '\n')
            s->y_maze++;
}

void fill_array(solv_s *s)
{
    int i = 0;
    int y = 0;

    for ( ; y <= s->y_maze; y++) {
        for (int x = 0; x <= s->x_maze; x++)
            s->maze[y][x] = s->buff_maze[i++];
        s->maze[y][s->x_maze + 1] = '\0';
        i++;
    }
    s->maze[y] = NULL;
}

void malloc_array(solv_s *s)
{
    s->maze = malloc(sizeof(char *) * (s->y_maze + 2));
    for (int y = 0; y <= s->y_maze + 1; y++)
        s->maze[y] = malloc(sizeof(char) * (s->x_maze + 2));
}
