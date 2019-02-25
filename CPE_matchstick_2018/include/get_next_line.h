/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef GETNEXT_H
#define GETNEXT_H

#define READ_SIZE (1)

#define VAR_GNL int stop = 0; \
int ret = 0; \
int count = 0; \
static int i = 0; \
int e = 0; \
static int end = 0; \
static char *buf; \
char *result = malloc(sizeof(char) * 48000); \
char *tmp = malloc(sizeof(char) * 48000); \

#define MALLOC_CHECK if (READ_SIZE == 0 || fd == -1 || !tmp || !result) \
return (NULL); \
my_memset(result, 0, 47999); \

#define END_GNL if ((ret == 0 && i) || (ret == 0 && count)) { \
if (!(result[0] >= 32 && result[0] <= 125) && \
result[1] == '\0') \
result = 0; \
i = 0; \
return (result); \
} else if (ret == 0 && !i) { \
return (NULL); \
} \

#define SECOND_CALL if (end == 1) { \
while (buf[i] != '\0') { \
if (buf[i] == '\n') { \
i++; \
result[e + 1] = 0; \
return (result); \
} \
result[e] = buf[i]; \
e++; \
i++; \
} \
} \

#define MALLOC_CHECK_2 buf = malloc(sizeof(char) * 48000); \
if (!buf) \
return (NULL); \
my_memset(buf, 0, 47999); \

#define COPY_BUF_IN_STR while (buf[i] != '\0' && stop == 0) { \
if (buf[i] == '\n') { \
stop = 1; \
tmp[i] = '\0'; \
} else { \
tmp[count++] = buf[i]; \
} \
i++; \
} \
my_strcat(result, tmp); \

#endif