##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## to build my project
##

CC	=	g++
NAME	=	arcade
NAME_TEST = unit_tests
FLAGS	=	-W -c -Wall -Wextra -Werror -pedantic -g3 -std=c++2a
EXT := cpp

SRC_FOLDER	:= 	src/core			\
				src/core/error		\
				src/core/interface
IGNORE_SRC := .
SRC :=	$(filter-out $(IGNORE_SRC), $(sort $(shell find $(SRC_FOLDER) -ignore_readdir_race -maxdepth 1 -name '*.$(EXT)')))

INC_FOLDER =	inc
IGNORE_INC := 	.
INC := $(filter-out $(IGNORE_INC), $(addprefix -I, $(INC_FOLDER)))

TEST_FOLDER	:= .
IGNORE_TEST := .
TEST :=	$(filter-out $(IGNORE_TEST), $(sort $(shell find $(TEST_FOLDER) -ignore_readdir_race -maxdepth 1 -name '*.$(EXT)')))

LFOLDER :=	src/libfoo src/libnon src/liboui
LIB_FOLDER := 	#-L $(LFOLDER)
LIB_NAME :=
LIB_EXT :=	-lcriterion -ldl

OBJ_PATH :=	obj/
OBJ_FOLDER := $(addprefix $(OBJ_PATH), $(SRC_FOLDER))
OBJ :=	$(addprefix $(OBJ_PATH), $(SRC:.$(EXT)=.o))

LIBR := $(R)

#----Parameter----#
SYSFILES := ./errors
SHELL	:=	/bin/bash
MAKEFLAGS	+=	--no-print-directory --silence --silent
REDIRECT := 2>> ./errors

#----Color----#

COLOR 	=	\e[
RESET	=	\e[0m
R_BOLD	=	\e[21m
R_BLINK	=	\e[25m
GREEN	=	38;5;82
RED		=	31
BOLD	=	1
BLINK	=	5
END_COLOR	=	m

all:	core games graphicals


introduction: $(OBJ_FOLDER)
	@mkdir lib
	echo -e "╔══Initialization compile"
	echo -e "║"
	echo -e "║"
	echo -e "╠══Compiling your file..."

$(OBJ_FOLDER):
	mkdir -p $@

$(NAME):	$(OBJ)
	echo -e "║"
	echo -e "╠══Now, build your project!"
	echo -e "║"
	echo -e "╠══Build in progress..."
	$(CC) -o $(NAME) $^ $(LDFLAGS) -L./ -ldl	\
		&& echo -e "╚$(COLOR)$(GREEN)$(END_COLOR)Your project was successfully built congratulation! $(RESET)"	\
		|| echo -e "╠$(COLOR)$(BOLD);$(BLINK);$(RED)$(END_COLOR)WARNING$(R_BLINK)$(R_BOLD) Your project is bad change this and retry newbie!$(RESET)"\
		"\n╚$(COLOR);$(RED)$(END_COLOR)Look in the error_list to see what is your problem.$(RESET)"

$(OBJ):	$(OBJ_PATH)%.o:	%.$(EXT)
	$(CC) -c $< -o $@ $(INC) $(FLAGS) $(REDIRECT)	\
		&& echo -e "╠══$(COLOR)$(GREEN)$(END_COLOR)$(notdir $@) built! ✔$(RESET)"	\
		|| echo -e "╠══$(COLOR)$(RED);$(BLINK);$(BOLD)$(END_COLOR)WARNING$(R_BLINK) the file $(notdir $@) failed to build! ✘$(RESET)"

$(OBJDIR):
	mkdir -p $@
	echo -e creating a folder.

clean:
	$(RM) -rf $(OBJ_PATH)
	$(RM) errors

fclean:	clean
	@rm -f $(NAME)
	rm -r lib

re: fclean all

#lib: $(LFOLDER)

core: introduction $(NAME)

games:
	make re -C src/pacman
	make re -C src/nibbler

graphicals:
	make re -C src/libsfml
	make re -C src/libncurses
	make re -C src/libsdl

$(LFOLDER):
		make -C $@ $(LIBR)

tests_run:
	g++ -o $(NAME_TEST) $(SRC) $(TEST) $(INC) --coverage -lcriterion
	./$(NAME_TEST)

rm_tests:
	rm *.gcno
	rm *.gcda
	rm $(NAME_TEST)

.PHONY: tests_run all fclean clean core graphicals games