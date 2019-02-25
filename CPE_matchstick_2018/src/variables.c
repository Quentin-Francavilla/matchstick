/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../include/matchstick.h"
#include "../lib/my/lib.h"

void reset(t_glo *a, char **av)
{
    a->good_matches = 0;
    a->good_line = 0;
    a->star_beg_or_end = 0;
    a->nb_of_lines = my_getnbr(av[1]);
    a->total_len = ((a->nb_of_lines * 2) - 1) + 2;
    a->matches_side = 0;
}

void variables(t_glo *a, char **av)
{
    a->rand_nb_matches = 0;
    a->rand_line = 0;
    a->end = 0;
    a->ia_turn = 0;
    a->end_player = 0;
    a->check_total_matches = 0;
    a->total_matches = 0;
    a->line_int = 0;
    a->matches_int = 0;
    a->good_matches = 0;
    a->good_line = 0;
    a->star_beg_or_end = 0;
    a->nb_of_lines = my_getnbr(av[1]);
    a->total_len = ((a->nb_of_lines * 2) - 1) + 2;
    a->matches_side = 0;
    VAR_MALLOC
}