##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for lib compilation
##

NAME     =     libmy.a

SRC     =    ./$(wildcard *.c)

HEADER     =    ./my.h

LIBPATH =     ./../../includes/

all:
	@gcc -c $(SRC)
	@mkdir -p ./objects
	@mv *.o objects
	@ar rc $(NAME) ./objects/*.o
	@cp $(NAME) ./../../.
	@echo "[*** LIB CREATED ***]"

clean:
	@rm -rf objects
	@rm -f $(NAME)

fclean: clean
	@rm -f ../../$(NAME)
	@echo "[*** LIB CLEANED ***]"

re: fclean all

.PHONY: all clean fclean re
