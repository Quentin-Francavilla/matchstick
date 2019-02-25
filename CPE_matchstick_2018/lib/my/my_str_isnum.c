/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** 
*/

int my_str_isnum(char *str)
{
    int i = 0;
    int y = 0;
    int result = 0;

    i = 0;
    while (str[y] != '\0') {
        if (!((str[y] >= '0' && str[y] <= '9'))) {
            i = i + 1;
        }
        y = y + 1;
    }

    if (i >= 1)
        result = 0;
    else
        result = 1;
    return (result);
}
