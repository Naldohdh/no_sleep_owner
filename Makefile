##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	usage.c	\
		103cipher.c

OBJ	=	$(SRC:.c=.o)

NAME	=	103cipher

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -lm -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
