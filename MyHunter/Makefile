##
## EPITECH PROJECT, 2019
## makefile of my hunter
## File description:
## do stuff
##

SRC	=	source/my_hunter.c		\
		source/hunter_game.c		\
		source/hunter_event.c		\
		source/hunter_animate.c		\
		source/hunter_menus.c		\
		source/hunter_score.c		\
		source/init.c			\
		source/my_getnbr.c		\
		source/init_texture.c		\
		source/rand.c			\
		source/case.c			\
		source/drawing.c		\
		source/loader.c			\
		source/init_utils.c

NAME	=	my_hunter

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3 -Wall -Wextra -pedantic

CPPFLAGS=	-I include/

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lcsfml-network

all:	$(OBJ)
	gcc -o $(NAME) $(LDFLAGS) $(OBJ)

re:	clean all

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -rf $(OBJ)

download:
ifeq (,$(wildcard ./ressources/shrek.png))
	curl http://sherk.communis.me/shrek.png -o ./ressources/shrek.png
endif

.PHONY:	all re clean fclean download
