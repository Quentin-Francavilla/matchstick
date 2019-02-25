/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../include/matchstick.h"
#include "../lib/my/lib.h"

void print_matches(t_glo *a, int i)
{
    VAR_PRINT_MATCHES

    if (y == a->line_int && a->end == 1) {
        a->already_print[y] = a->already_print[y] + a->matches_int;
        while (z < a->matches_side + (1 * a->matches_side + 1) -
        a->already_print[y]) {
            my_putchar('|');
            z += 1;
        }
    }
    else {
        while (z < a->matches_side + (1 * a->matches_side + 1) -
        a->already_print[y]) {
            my_putchar('|');
            if (a->check_total_matches == 0)
                a->total_matches += 1;
            z += 1;
        }
    }
    a->nb_of_matches[y] = z;
    z = 0;
}

void print_game_board(t_glo *a)
{
    int i = 0;
    int where_m = 0;
    int len_matches = ((a->nb_of_lines * 2) - 1);
    int y = 0;

    while (i != a->nb_of_lines) {
        my_putchar('*');
        spaces_before(a, &y);
        print_matches(a, i);
        spaces_after(a, &y, i);
        a->matches_side += 1;
        y = 0;
        my_putstr("*\n");
        i++;
    }
    a->check_total_matches = 1;
    a->total_matches -= a->matches_int;
    if (a->total_matches == 0 && a->ia_turn % 2 != 0)
        a->end_player = 1;
    if (a->total_matches == 0 && a->ia_turn % 2 == 0)
        a->end_ia = 1;
}

void start_print_map(t_glo *a, char **av)
{
    reset(a, av);
    star_lines(a);
    print_game_board(a);
    star_lines(a);
}

void ia_turn(t_glo *a, char **av)
{
    a->ia_turn += 1;
    a->line_int = rand() % a->nb_of_lines + 1;
    while (a->nb_of_matches[a->line_int] == 0)
        a->line_int = rand() % a->nb_of_lines + 1;
    a->matches_int = rand() % a->nb_of_matches[a->line_int] + 1;
    while (a->matches_int > my_getnbr(av[2]))
        a->matches_int--;
    my_putstr("AI removed ");
    my_put_nbr(a->matches_int);
    my_putstr(" match(es) from line ");
    my_put_nbr(a->line_int);
    my_putchar('\n');
}

int main(int ac, char **av)
{
    VAR_MAIN
    while (1) {
        if (a->good_matches == 0) {
            start_print_map(a, av);
            END_PLAYER
            END_IA
            DISPLAY_TURN
        }
        if (a->ia_turn % 2 == 0) {
            PLAYER_TURN
        }
        else {
            ia_turn(a, av);
        }
        a->end = 1;
    }
    return (0);
}