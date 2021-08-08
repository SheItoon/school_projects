########################
#### VARIABLES #########
########################

NAME		 	= ftrace
CC			 	= gcc
RM			 	= rm -rf

INCLUDES 	 	= -I./include/
LINK_FLAG    	= -lelf
CFLAGS 		 	= -Wall -Wextra \
				  -ggdb3 -g3 --coverage \
				  -fPIC
PATTERN 	 	= .c
OBJPATTERN  	= .o
UTESTS_BIN  	= unit_tests
SRC_DIR 		= ./sources
OBJECT_DIR 		= ./objects

vpath %$(PATTERN) $(SRC_DIR)
vpath %$(PATTERN) $(SRC_DIR)/tools
vpath %$(PATTERN) $(SRC_DIR)/display
vpath %$(PATTERN) $(SRC_DIR)/tracer
vpath %$(PATTERN) ./tests

MAIN		 	= main.c
DISPLAY 		= disp_engine.c disp_syscalls.c \
				  disp_api.c load_from_register.c \
				  disp_signal.c
TOOLS 			= tabgen.c utils.c \
				  file_handler.c tab_utils.c \
				  func_stack.c str_funcs.c
TRACER 			= setup_ptrace.c trace_loop.c trace_helper.c \
				  relative_functions.c load_symtab.c
SRC 		 	= $(TOOLS) $(TRACER) $(DISPLAY) input_handling.c elf_parsing.c
TEST_SRC 	 	= tests_tools.c tests_parser.c \
				  tests_output_engine.c tests_elf.c tests_setup.c

########################
#### COMPILATION #######
########################

COMBINED		= $(SRC) $(MAIN)
TESTS 			= $(SRC) $(TEST_SRC)
OBJ 	 		= $(patsubst %$(PATTERN), $(OBJECT_DIR)/%$(OBJPATTERN), $(COMBINED))
OBJTST 			= $(patsubst %$(PATTERN), $(OBJECT_DIR)/%$(OBJPATTERN), $(TESTS))

all: directories $(NAME)

$(OBJECT_DIR):
	@mkdir -p $@

directories: | $(OBJECT_DIR)

$(OBJECT_DIR)/%$(OBJPATTERN) : %$(PATTERN)
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES) $(LINK_FLAG)
	@echo "Compiling $@"

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $^ $(CFLAGS) $(INCLUDES) $(LINK_FLAG)
	@echo "[*** COMPILATION SUCCESSFUL ***]"

clean:
	@$(RM) objects

fclean: clean
	@$(RM) $(NAME) $(UTESTS_BIN) vgcore*
	@echo "[*** CLEAN ***]"

re: fclean all

func_tests:
	@./tests/.ftests

tests_run: clean directories $(OBJTST)
	@$(CC) -o $(UTESTS_BIN) $(OBJECT_DIR)/*$(OBJPATTERN) --coverage $(INCLUDES) $(LINK_FLAG) -lcriterion
	@./$(UTESTS_BIN) > /dev/null
	@echo "[*** TESTS OVER ***]"

tests_run_clean: tests_run
	@gcovr --exclude ./tests/test -s -p
	@$(RM) $(UTESTS_BIN) $(NAME) *.gcda *.gcno $(OBJECT_DIR)
	@echo "[*** CLEAN SUCCESSFUL ***]"

.PHONY: all clean fclean re tests_run tests_run_clean
