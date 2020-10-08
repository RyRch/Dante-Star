/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/

typedef enum {
    false,
    true
}cases;

typedef struct {
    int cols;
    int rows;
    int end;
    int cnt;
    int p[2];
    int pos[4][2];
    char **maze;
}basic;

typedef struct {
    char **maze;
    int **matrix;
    int **matrix_solv;
    char *buff_maze;
    int x_maze;
    int y_maze;
    int x_final;
    int y_final;
}solv_s;
