##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/lance.c	\
		src/my_putchar.c	\
		src/mini_printf.c	\
		src/slash/number.c	\
		src/slash/lecteur.c	\
		src/slash/ctrlc.c	\
		src/slash/liberty.c	\
		src/slash/alloc.c	\
		src/slash/concat.c	\
		src/slash/comp.c	\
		src/slash/in_one.c	\
		src/slash/cation.c	\
		src/slash/array.c	\
		src/slash/pastor.c		\
		src/slash/banned.c		\
		src/slash/space_x.c 	\
		src/xcution.c	\
		src/kinary.c	\
		src/way.c		\
		src/obten.c	\
		src/zone.c	\
		src/penetre.c	\
		src/tcsh.c	\
		src/camdir.c	\
		src/nine.c	\
		src/place.c	\
		src/enleve.c	\
		src/al_dehors.c	\
		src/dedans.c	\
		src/sucerog.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-W -Wall -g3

CPPFLAGS	=	-I include/

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *#

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
