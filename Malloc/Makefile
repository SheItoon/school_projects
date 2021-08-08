##
## EPITECH PROJECT, 2019
## makefile of my hunter
## File description:
## do stuff
##

SRC	=	source/malloc.c		\
		source/memory_handler.c	\
		source/utils.c		\
		source/calloc.c		\
		source/free.c		\
		source/realloc.c

NAME	=	libmy_malloc.so

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3 -Wall -Wextra -fPIC -Wno-deprecated

CPPFLAGS=	-I include/

LDFLAGS	=

all:	$(OBJ)
	gcc -fPIC -shared -o $(NAME) $(LDFLAGS) $(OBJ)

re:	clean all

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -rf $(OBJ) $(NAME)

.PHONY:	all re clean fclean
