/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** 
*/

void my_memset(char *str, char c, int size)
{
    int i = 0;

    while (i != size)
        str[i++] = c;
}