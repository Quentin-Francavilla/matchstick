/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../include/matchstick.h"
#include "../lib/my/lib.h"

void spaces_before(t_glo *a, int *y)
{
    while (*y != (a->total_len / 2) - 1 - a->matches_side) {
        my_putchar(' ');
        *y += 1;
    }
}

void spaces_after(t_glo *a, int *y, int i)
{
    int e = i + 1;

    *y += 1;
    if (e == a->line_int && a->end == 1) {
        while (*y != a->total_len - 2 - a->matches_side * 2 +
        a->already_print[e]) {
            my_putchar(' ');
            *y += 1;
        }
    }
    else {
        while (*y != a->total_len - 2 - a->matches_side * 2 +
        a->already_print[e]) {
            my_putchar(' ');
            *y += 1;
        }
    }
}

void star_lines(t_glo *a)
{
    int i = 0;

    while (i != a->total_len) {
        my_putchar('*');
        i++;
    }
    my_putchar('\n');
}