/*
** EPITECH PROJECT, 2020
** main for solver from Dante's project
** File description:
** 18/03/20 14:43
*/

#include "my.h"

void set_struct(solv_s *s)
{
    s->x_maze = 0;
    s->y_maze = 0;
    s->x_final = 0;
    s->y_final = 0;
    s->maze = NULL;
    s->matrix = NULL;
    s->matrix_solv = NULL;
}

cases maze_solver(solv_s *s)
{
    int y = 0;

    set_struct(s);
    get_x_y(s);
    malloc_array(s);
    fill_array(s);
    matrix(s);
    if (solver(s, 0, 0))
        stock_display(s);
    else
        return (false);
    for ( ; y <= s->y_maze - 1; y++) {
        my_putstr(s->maze[y]);
        my_putchar('\n');
    }
    my_putstr(s->maze[y]);
    free_array(s);
    return (true);
}

cases check_maze(solv_s *s, char const *maze, int fd)
{
    struct stat info;
    int size = 0;

    stat(maze, &info);
    size = info.st_size;
    s->buff_maze = malloc(sizeof(char) * (size + 1));
    if (read(fd, s->buff_maze, size) == -1)
        return (false);
    s->buff_maze[size] = '\0';
    for (int i = 0; i < size; i++) {
        if (s->buff_maze[i] != '*' && s->buff_maze[i] != 'X'
            && s->buff_maze[i] != '\n')
            return (false);
        if (s->buff_maze[0] == 'X' || s->buff_maze[size - 1] == 'X') {
            my_putstr("no solution found");
            exit(0);
        }
    }
    return (true);
}

int main(int ac, char **av)
{
    solv_s s;
    int fd = 0;

    fd = open(av[1], O_RDWR);
    if (ac != 2)
        return (84);
    if (fd == -1)
        return (84);
    if (check_maze(&s, av[1], fd) == false)
        return (84);
    if (maze_solver(&s) == false)
        my_putstr("no solution found");
    return (0);
}
