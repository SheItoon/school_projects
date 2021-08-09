##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## to build my project
##

NAME	=	my_world

SRC	=	src/main.c						\
		src/event/event.c				\
		src/input.c						\
		src/map/reset_map.c				\
		src/map/create_map.c			\
		src/map/change_size.c			\
		src/map/texture_map.c			\
		src/draw_sprite.c				\
		src/loading/loading_game.c		\
		src/button/button.c				\
		src/button/create_button.c		\
		src/button/button_help.c		\
		src/utils/compare.c				\
		src/button/button_action.c		\
		src/init_loading.c				\
		src/loader.c					\
		src/loader_more.c				\
		src/slider/create_slider.c		\
		src/slider/slider_event.c		\
		src/slider/slider_destroy.c		\
		src/main_menu.c					\
		src/icon/set_icon.c				\
		src/normal/normal_func.c		\
		src/utils/my_strlen.c			\
		src/easter_egg.c				\
		src/display_help.c				\
		src/menu_func.c					\
		src/unload/unload_game.c		\
		src/button/draw_button.c		\
		src/button/draw_button_help.c	\
		src/button/button_text.c		\
		src/loading/load_button.c		\
		src/score.c						\
		src/shortcut.c					\
		src/draw_effect_zone.c			\
		src/loading/loading_button_bis.c	\
		src/how_to_play.c	\
		src/my_getnbr.c		\
		src/load_func.c		\
		src/get_next_line.c

CFLAGS	=	-I inc/ -g3

LDFLAGS =	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lcsfml-network -lm

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo ======Compiling...=======
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo ====Compile complete!====

%.o : %.c
		gcc -c -o $@ $< $(CFLAGS)

clean:
	@$(RM) $(OBJ)
	@echo ====.o files removed===

fclean:	clean
	@rm -f $(NAME)

re:	clean all

tests_run:
	@echo =====Compiling tests=====
	@echo ====Compile complete!====
