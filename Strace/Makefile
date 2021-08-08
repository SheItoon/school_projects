##
## EPITECH PROJECT, 2019
## makefile of my hunter
## File description:
## do stuff
##

CC	=	gcc

SRC	=	source/strace_engine.c	\
		source/trace.c		\
		source/status.c		\
		source/kill_the_child.c	\
		source/utils.c		\
		source/print.c

MAIN	=	source/main.c

NAME	=	strace

OBJ	=	$(SRC:.c=.o)	\
		$(MAIN:.c=.o)

CFLAGS	=	-g3 -Wall -Wextra -pedantic

CPPFLAGS=	-I include/

LDFLAGS	=

all:	$(OBJ)
	$(CC) -o $(NAME) $(LDFLAGS) $(OBJ)

re:	clean all

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

tests_run:
	@$(RM) unit_tests *.gcno *.gcda
	@$(CC) -o unit_tests tests/*.c $(SRC) -I include/ -g3 --coverage -lcriterion
	@./unit_tests

clean_crit:
	@rm -f unit_tests *.gcno *.gcda

.PHONY:	all re clean fclean tests_run clean_crit
