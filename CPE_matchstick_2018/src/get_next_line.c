/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../include/get_next_line.h"
#include "../include/lib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

char *get_next_line(int fd)
{
    VAR_GNL
    MALLOC_CHECK
    while (stop != 1) {
        my_memset(tmp, 0, 47999);
        SECOND_CALL
        MALLOC_CHECK_2
        ret = read(fd, buf, READ_SIZE);
        if (ret == -1)
            return (NULL);
        buf[ret] = 0;
        if (ret)
            count = 0;
        COPY_BUF_IN_STR
        if (stop != 1 && ret != 0) {
            i = 0;
        }
        END_GNL
    }
    end = 1;
    return (result);
}