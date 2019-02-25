/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../include/matchstick.h"
#include "../lib/my/lib.h"

void check_error_on_matches(t_glo *a, char **av)
{
    a->matches_int = my_convert_char_int(a->nb_remove_matches);
    if (!(a->matches_int <= a->nb_of_matches[a->line_int]
    && a->matches_int > 0 && a->matches_int <= my_getnbr(av[2]))) {
        a->good_matches = 1;
        a->good_line = 0;
        AT_LEAST_ONE
        POSITIVE_NB_EXPECTED
        MORE_THAN
        NOT_ENOUGH
    }
    else {
        a->good_matches = 0;
        a->good_line = 0;
        my_putstr("Player removed ");
        my_put_nbr(a->matches_int);
        my_putstr(" match(es) from line ");
        my_put_nbr(a->line_int);
        my_putchar('\n');
        a->ia_turn += 1;
    }
}

void check_error_on_lines(t_glo *a)
{
    a->line_int = my_convert_char_int(a->line);
    if (a->line_int <= a->nb_of_lines && a->line_int > 0)
        a->good_line = 1;
    else if (a->line_int < 0 || my_str_isnum(a->line) == 0) {
        my_putstr("Error: invalid input ");
        my_putstr("(positive number expected)\n");
    }
    else
        my_putstr("Error: the line is out of range\n");
}

int arguments_check(int ac, char **av)
{
    int is_num;
    int is_num2;

    if (ac != 3)
        return (84);

    is_num = my_str_isnum(av[1]);
    is_num2 = my_str_isnum(av[2]);

    if (is_num == 0 || is_num2 == 0)
        return (84);

    if (my_getnbr(av[1]) < 1 || my_getnbr(av[1]) > 100)
        return (84);
}