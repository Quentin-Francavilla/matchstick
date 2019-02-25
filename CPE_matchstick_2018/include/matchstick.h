/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef LS_H
#define LS_H

#include "../lib/my/lib.h"
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/sysmacros.h>

typedef struct s_glo
{
    int star_beg_or_end;
    int total_len;
    int nb_of_lines;
    int matches_side;
    int menos;
    char *line;
    int line_int;
    char *nb_remove_matches;
    int *nb_of_matches;
    int matches_int;
    int good_line;
    int good_matches;
    int end;
    int *already_print;
    int total_matches;
    int check_total_matches;
    int end_player;
    int end_ia;

    int ia_turn;
    int rand_line;
    int rand_nb_matches;
} t_glo;

//main
int arguments_check(int ac, char **av);
void reset(t_glo *a, char **);
void variables(t_glo *a, char **av);

//error
void check_error_on_matches(t_glo *a, char **av);
void check_error_on_lines(t_glo *a);

//graphic
void star_lines(t_glo *a);
void spaces_before(t_glo *a, int *y);
void spaces_after(t_glo *a, int *y, int i);

//variables
#define VAR_MALLOC a->line = malloc(sizeof(char) * 1000); \
if (!a->line) \
return; \
my_memset(a->line, 0, 999); \
a->nb_remove_matches = malloc(sizeof(char) * 1000); \
if (!a->nb_remove_matches) \
return; \
my_memset(a->nb_remove_matches, 0, 999); \
a->nb_of_matches = malloc(sizeof(int) * 1000); \
if (!a->nb_of_matches) \
return; \
a->already_print = malloc(sizeof(int) * 1000); \
if (!a->already_print) \
return; \

//error
#define CHECK_ERROR_ARG return_error = arguments_check(ac, av); \
if (return_error == 84) {my_putstr("Argument invalid\n"); \
return (84);} \

#define AT_LEAST_ONE if (a->matches_int == 0) { \
my_putstr("Error: you have to remove at "); \
my_putstr("least one match\n"); \
} \

#define POSITIVE_NB_EXPECTED else if (a->matches_int < 0 \
|| my_str_isnum(a->nb_remove_matches) == 0) { \
my_putstr("Error: invalid input "); \
my_putstr("(positive number expected)\n"); \
} \

#define MORE_THAN else if (!(a->matches_int <= my_getnbr(av[2]))) { \
my_putstr("Error: you cannot remove more than "); \
my_put_nbr(my_getnbr(av[2])); \
my_putstr(" matches per turn\n"); \
} \

#define NOT_ENOUGH else \
my_putstr("Error: not enough matches on this line\n"); \

//ending
#define END_PLAYER if (a->end_player == 1) { \
my_putstr("You lost, too bad...\n"); \
return (2); \
} \

#define END_IA if (a->end_ia == 1) { \
my_putstr("I lost... snif... but I’ll get you next time!!\n"); \
return (1); \
} \

//print matches
#define VAR_PRINT_MATCHES int y; \
int z = 0; \
y = i + 1; \

//main
#define VAR_MAIN int return_error = 0; \
srand(time(NULL)); \
CHECK_ERROR_ARG \
t_glo *a = malloc(sizeof(t_glo)); \
variables(a, av); \

#define CHECK_CTRL_D_LINES if (a->line == NULL) \
return (0); \

#define CHECK_CTRL_D_MATCHES if (a->nb_remove_matches == NULL) \
return (0); \

#define DISPLAY_TURN if (a->ia_turn % 2 == 0) \
my_putstr("\nYour turn:\n"); \
else \
my_putstr("\nAI's turn...\n"); \

#define GET_LINE my_putstr("Line: "); \
a->line = get_next_line(0); \

#define GET_MATCHES my_putstr("Matches: "); \
a->nb_remove_matches = get_next_line(0); \

#define PLAYER_TURN while (a->good_line == 0) { \
GET_LINE \
CHECK_CTRL_D_LINES \
check_error_on_lines(a); \
} \
GET_MATCHES \
CHECK_CTRL_D_MATCHES \
check_error_on_matches(a, av); \

#endif