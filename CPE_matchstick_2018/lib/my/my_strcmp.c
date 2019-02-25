/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** 
*/

int my_strcmp(char *s1, char const *s2)
{
    int j = 0;
    int k = 0;
    int n = 0;

    while (s2[j] != '\0')
        j = j + 1;
    while (s1[k] != '\0')
        k = k + 1;
    while (s1[n] == s2[n])
        n = n + 1;
    if (j == k && j == n - 1)
        return (0);
    else {
        if (s1[n] < s2[n])
            return (-1);
        else
            return (1);
    }
}
