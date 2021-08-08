##
## EPITECH PROJECT, 2019
## makefile of my hunter
## File description:
## do stuff
##

SRC_NM	=	source/nm/nm.c			\
		source/nm/print.c		\
		source/nm/map.c			\
		source/nm/check.c		\
		source/nm/print_second.c	\
		source/nm/utils.c		\
		source/nm/utils_second.c	\
		source/nm/list.c		\
		source/nm/list_second.c		\
		source/nm/arch.c		\
		source/nm/symbol.c		\
		source/nm/elf.c			\
		source/nm/get_func.c		\
		source/nm/get_func_second.c	\
		source/nm/symbol_second.c	\
		source/nm/check_second.c	\
		source/nm/get_func_third.c	\
		source/nm/init.c

MAIN_NM	=	source/nm/main.c

NAME_NM	=	my_nm

OBJ_NM	=	$(SRC_NM:.c=.o)	\
		$(MAIN_NM:.c=.o)

SRC_OBJ	=	source/objdump/obj.c		\
		source/objdump/objdump.c	\
		source/objdump/map.c		\
		source/objdump/utils.c		\
		source/objdump/check.c		\
		source/objdump/check_second.c	\
		source/objdump/elf.c		\
		source/objdump/print_handler.c	\
		source/objdump/print.c		\
		source/objdump/arch.c		\
		source/objdump/print_second.c	\
		source/objdump/print_third.c	\
		source/objdump/print_fourth.c	\
		source/objdump/get.c		\
		source/objdump/utils_second.c

MAIN_OBJ=	source/objdump/main.c

NAME_OBJ=	my_objdump

OBJ_OBJ	=	$(SRC_OBJ:.c=.o)	\
		$(MAIN_OBJ:.c=.o)

CC	=	gcc

CFLAGS	=	-g3 -Wall -Wextra -Werror -pedantic

CPPFLAGS=	-I include/nm/ -I include/objdump/

LDFLAGS	=

all:	$(NAME_NM) $(NAME_OBJ)

nm:	$(NAME_NM)

objdump:$(NAME_OBJ)

$(NAME_NM): $(OBJ_NM)
	$(CC) -o $(NAME_NM) $(LDFLAGS) $(OBJ_NM)

$(NAME_OBJ): $(OBJ_OBJ)
	$(CC) -o $(NAME_OBJ) $(LDFLAGS) $(OBJ_OBJ)

re:	clean all

clean:
	rm -f $(OBJ_NM) $(OBJ_OBJ)

fclean:	clean
	rm -rf $(NAME_NM) $(NAME_OBJ)

tests_run: $(NAME_NM)
	@rm -f unit_tests *.gcno *.gcda
	@$(CC) -o unit_tests tests/test_map.c $(SRC_NM) -I include/nm/ --coverage -lcriterion
	@./unit_tests
	@$(CC) -o unit_tests tests/test_obj.c $(SRC_OBJ) -I include/objdump/ --coverage -lcriterion
	@./unit_tests

clean_crit:
	@rm -f unit_tests *.gcno *.gcda

.PHONY:	all re clean fclean tests_run clean_crit nm objdump
