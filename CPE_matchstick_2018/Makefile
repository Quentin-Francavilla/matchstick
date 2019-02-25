##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## M
##

SRC	=	./src/main.c \
		./src/get_next_line.c \
		./src/variables.c \
		./src/gestion_error.c \
		./src/graphic_fct.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

FLAG	=	-W -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	gcc $(SRC) -o $(NAME) -L./lib/my -lmy
	rm -f $(OBJ)
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#.PHONY
