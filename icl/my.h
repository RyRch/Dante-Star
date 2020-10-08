/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "struct.h"

void my_putchar(char c);

void my_putstr(char *str);

int my_getnbr(char const *str);

int my_strlen(char const *str);

cases my_strcmp(char const *s1, char const *s2);

void set_struct(solv_s *s);

void free_array(solv_s *s);

void get_x_y(solv_s *s);

void fill_array(solv_s *s);

void malloc_array(solv_s *s);

int solver(solv_s *s, int y, int x);

void stock_display(solv_s *s);

void matrix(solv_s *s);

cases maze_solver(solv_s *s);

cases check_maze(solv_s *s, char const *maze, int fd);

cases is_digit(char *str);

static void init_struct(basic *all, char **av);

static void init_maze(basic *all);

static void print_maze(basic *all, int ac);

void algo_maze1(basic *all);

void algo_maze2(basic *all);

void init_pos(basic *all);

cases find_pos(basic *all, int m, char c);

int choice1(basic *all, int m, char c);

int choice2(basic *all, int m, char c);

void move_player(basic* all, int tmp[4], int w, char c);

void break_wall(basic *all, int val);

static cases gest_err(int ac, char **av);

void init_end(basic *all);

#endif
