
############################
#### PREAMBLE ##############
############################


# This makefile is fully optimized for a C project
# allowing you to do following things:
# - all:	assemble the entire project with the
#			eventual library
# - fclean:	remove your project's executable AND
#			object files
# - clean:  remove ONLY the object files, if any
# - re:		clean up and reassemble the project
#			from scratch
# - debug:	reassemble your entire project with
#			debug flag ('-g') and run GDB with custom
#			parameters sent to your program
#			(you can set custom arguments by modifying
#			the 'GDB_ARGV' variable)
# - __%_gc:	this one needs some extra explanation. When
#			you try to 'make __my_src_c' this makefile
#			will:
#				1.	compile all of your
#					source files into objects
#				2.	check for a file named 'my_src.c'
#					in your source folder
#				3.	check for a file named '__my_src.c'
#					in your tests folder
#				4.	recompile this precise source files
#					with coverage flags, without touching
#					the rest
#				5.	run the compiled unit test
#			So in the end, you compile your unit test
#			for the file 'my_src.c' if it's possible.
#			Therefore, if you want to use this ability,
#			you have to name your tests file as following:
#			'__%' where % is your original source file
#			name. Also, once unit tests launched, you can
#			analyze detailed coverage line by line
#			executing gcov (not gcovr)
# - __%:	same as previous, but without generating
#			coverage statistics
# - doc		this target calls doxygen inside of $(OXDOC_DIR)
# The only things that should be modified in this makefile
# are in the 'OPTIONS' and 'SOURCE FILES' sections.
# You have to enter all of your source files manually


############################
#### SUMMARY ###############
############################


# 1. Options
# 2. Source files
# 3. Compiler settings
# 4. Object files
# 5. Make recipies
# 6. File creation section
# 7. Pattern rules


############################
#### OPTIONS ###############
############################


TARGET_NAME			=	my_rpg
SOURCE_DIR			=	sources
OBJECT_DIR			=	objects
HEADER_DIR			=	include
TESTS_DIR			=	tests
OXDOC_DIR			=	ddoc
LIBRARY_DIR			=	lib
ISTL_DEP			=	$(SOURCE_DIR)/Makefile.istl_sources
GDB_ARGV			=

include $(ISTL_DEP)

.PRECIOUS : $(OBJECT_DIR)/%.d
.SUFFIXES :

vpath %.c $(SOURCE_DIR)
vpath %.c $(SOURCE_DIR)/$(ISTL_DIR)
vpath %.c $(SOURCE_DIR)/utility
vpath %.c $(SOURCE_DIR)/classes
vpath %.c $(SOURCE_DIR)/loaders
vpath %.c $(SOURCE_DIR)/tower
vpath %.c $(SOURCE_DIR)/shot
vpath %.c $(SOURCE_DIR)/menu_sessions/main_menu
vpath %.c $(SOURCE_DIR)/ftp

############################
#### SOURCE FILES ##########
############################

# Different game sessions
# \author Bogdan Guillemoles
# \author Guillaume Debard
# \author Iaroslav Sorokin
SESSION_MODULE		=		standard_session_1.c \
					standard_session_2.c \
					standard_session_3.c \
					scheme_1.c \
					scheme_2.c \
					scheme_3.c \
					scheme_4.c \
					scheme_5.c \
					decoration_1.c \
					decoration_2.c \
					decoration_3.c \
					combat_session.c

# Application's initialisators and
# main entry point
# \author Bogdan Guillemoles
# \author Guillaume Debard
# \author Iaroslav Sorokin
CORE_MODULE		=		init_functions_1.c \
					init_functions_2.c \
					init_functions_3.c \
					main.c

# Game engine sources
# \author Iaroslav Sorokin
ENGINE_MODULE		=		gcontext_1.c \
					gcontext_2.c \
					gcontext_3.c \
					gcontext_4.c \
					resource_holder_1.c \
					resource_holder_2.c \
					loaders_1.c \
					loaders_2.c \
					animation_loaders.c \
					resource_loaders.c \
					sound_loaders.c \
					texture_loaders.c \
					scene_1.c \
					scene_2.c \
					scene_3.c \
					scene_4.c \
					scene_5.c \
					scene_6.c \
					csfml_meta_1.c \
					csfml_meta_2.c \
					csfml_meta_3.c \
					csfml_types.c \
					cubic_bezier.c \
					gjk_core.c \
					csfml_toolbox_1.c \
					csfml_toolbox_2.c

# Different modes' handlers
# (global and local)
HANDLERS_MODULE		=		apph_handlers_1.c \
					apph_handlers_2.c \
					apph_handlers_3.c \
					apph_handlers_4.c \
					modh_creature_hover.c \
					modh_mouse_button.c \
					modh_mouse_moved.c \
					modh_btn_clicked.c \
					modh_key_pressed.c

# UI Module
# \author Bogdan Guillemoles
UI_MODULE 			= 			main_menu_session.c

# Unsorted source files
SOURCES_LIST		=	    	creature_1.c \
					creature_2.c \
					creature_3.c \
					creature_4.c \
					creature_5.c \
					creature_6.c \
					animation_1.c \
					animation_2.c \
					action_1.c \
					road_pass.c \
					csfml_meta_1.c \
					csfml_meta_2.c \
					csfml_meta_3.c \
					csfml_meta_4.c \
					csfml_meta_5.c \
					check_connection.c \
					ftp_init.c \
					read_map.c \
					malloc_toolbox.c \
					get_next_line.c \
					easter_egg.c \
					normal_func.c \
					combat_init.c \
					fight.c \
					exp.c \
					init_bar.c \
					$(ENGINE_MODULE) \
					$(UI_MODULE) \
					$(HANDLERS_MODULE) \
					$(ISTL_MODULE) \
					$(SESSION_MODULE) \
					$(CORE_MODULE)

LIBRARY			=		$(LIBRARY_DIR)/libmy.a


############################
#### COMPILER SETTINGS #####
############################


CC			=	gcc
C_FLAGS			=	-g3 -W -Wall -Wextra -Werror \
				-I$(HEADER_DIR) -I$(HEADER_DIR)/private \
				-Wno-switch \
				-Wno-unused-variable \
				-Wno-unused-parameter \
				-Wno-unused-but-set-variable \
				-Wno-unused-but-set-parameter \
				-Wno-unused-function \
				$(C_FLAGS_INPUT)
L_FLAGS			=	-L$(LIBRARY_DIR) -lmy -lm \
				-lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lcsfml-network\
				$(L_FLAGS_INPUT)
COV_FLAGS		=	-fprofile-arcs -ftest-coverage
VALGRIND_FLAGS		=	--leak-check=full \
				--show-leak-kinds=all \
				--track-origins=yes \
				--verbose \
				--log-file=valgrind-out.txt


############################
#### OBJECT FILES (auto) ###
############################


OBJECTS			=	$(patsubst %.c, $(OBJECT_DIR)/%.o, $(SOURCES_LIST))
NON_M_OBJECTS		=	$(patsubst %main.o, , $(OBJECTS))


############################
#### RECIPE SECTION ########
############################


.PHONY: all directories re clean fclean library debug


all: directories $(LIBRARY) $(TARGET_NAME)


check: $(SOURCES_LIST)
	@echo $(ISTL_DIR)
	@echo $(ISTL_MODULE)
	@echo $(OBJECTS)
	@echo $^


fullw:
	@make all C_FLAGS=-W\ -Wall\ -Wextra\ -pedantic\ -I$(HEADER_DIR)\ $(C_INPUT_FLAGS) --no-print-directory


debug:
	@make re C_FLAGS_INPUT=-g\ -g3 --no-print-directory
	@cgdb ./$(TARGET_NAME) -ex "break main" -ex "run $(GDB_ARGV)"

valgrind:
	@make re C_FLAGS_INPUT=-g\ -g3 --no-print-directory
	valgrind $(VALGRIND_FLAGS) ./$(TARGET_NAME) $(VALGRIND_INJECT)


library: $(LIBRARY)


directories: | $(SOURCE_DIR) $(OBJECT_DIR)


re:	clean all


clean:
	@rm -rf ./$(OBJECT_DIR)/*.o
	@rm -rf ./$(OBJECT_DIR)/*.dp
	@rm -rf ./*.gc*
	@rm -rf ./__*
#	@make -C $(LIBRARY_DIR) clean --no-print-directory


fclean: clean
	@rm -rf ./$(OBJECT_DIR)
	@rm -f ./$(TARGET_NAME)

doc:
	@make -C $(OXDOC_DIR) --no-print-directory


###############################
#### FILE CREATION SECTION ####
###############################


$(TARGET_NAME): $(OBJECTS)
	@$(CC) -o $(TARGET_NAME) $^ $(L_FLAGS)
	@echo -e "--- '\e[32mBUILD SUCCESSFULL\e[39m ---"


$(LIBRARY):
	@make -C $(LIBRARY_DIR) re --no-print-directory


$(OBJECT_DIR):
	@mkdir -p $@


$(SOURCE_DIR):
	@echo "Error: source folder is not detected"


###############################
#### PATTERN RULES SECTION ####
###############################


__% : $(TESTS_DIR)/__%.c %.c $(NON_M_OBJECTS)
	@$(CC) -o __$* $(patsubst %$*.o,, $^) \
					-lcriterion $(C_FLAGS) $(L_FLAGS)
	@./__$*


__%_gc : $(TESTS_DIR)/__%.c %.c $(NON_M_OBJECTS)
	@$(CC) -o __$* $(patsubst %$*.o,, $^) \
					-lcriterion $(C_FLAGS) $(L_FLAGS) $(COV_FLAGS)
	@./__$* && gcov -k $*


$(OBJECT_DIR)/%.d : %.c
	@$(CC) $< -MM -MF $@ -MT $(OBJECT_DIR)/$*.o $(C_FLAGS)


$(OBJECT_DIR)/%.o : %.c $(OBJECT_DIR)/%.d
	@$(CC) -c -o $@ $< $(C_FLAGS)
	@echo -e "--- '\e[34m$@\e[39m'\t\e[32mSUCCESSFULLY COMPILED\e[39m ---"


$(OBJECT_DIR)/%_cov.o : %.c
	@$(CC) -c -o $@ $< $(C_FLAGS) $(COV_FLAGS)
	@echo -e "--- '\e[34m$@\e[39m'\t\e[32mSUCCESSFULLY COMPILED\e[39m ---"


__%.o : __%.c
	@$(CC) -c -o $(OBJECT_DIR)/$@ $< $(C_FLAGS) -lcriterion


include $(wildcard $(OBJECT_DIR)/*.d)
