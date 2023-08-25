# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wingessoracle <wingessoracle@student.co      +#+                      #
#                                                    +#+                       #
#    Created: 2023/06/21 08:27:49 by wingessorac   #+#    #+#                  #
#    Updated: 2023/08/25 17:18:12 by carlowessel   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# **********SYSTEM SPECS MLX*************************************************** #
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLXFLAGS = -ldl -lglfw -pthread -lm
else
	MLXFLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
endif


# **********FLAGS************************************************************* #

CC		 		=	gcc
CFLAGS			=	-Wall -Wextra -Werror
LFLAGS			=	-Wall -Wextra -Werror
TARGET	 		=	cub3d


# *********LOCATIONS*********************************************************** #

INCLUDE			=	./include
LIBFT			=	./libraries/libft
LIBMLX			=	./libraries/MLX42
LIBS			=	$(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a
HEADERS			=	-I $(INCLUDE) -I $(LIBFT) -I $(MLX42)/include
SRC_DIR			=	./src
OBJ_DIR			=	./obj

OBJ_FILES		=	$(addprefix obj/, main.o init.o utils.o generate_grid.o grid_functions.o \
					set_paths.o hooks.o movement.o set_colors.o build.o cleanup.o testing.o)

BONUS_OBJ_FILES	=	$(addprefix obj/, test.o)


# *********OPERATIONS*********************************************************** #

all: libft $(TARGET)

libft:
	$(MAKE) -C $(LIBFT)

$(TARGET): $(OBJ_FILES)
	@echo -e "$(GREEN)Linking $(TARGET)$(RESET)"
	@$(CC) $(OBJ_FILES) $(LFLAGS) $(LIBS) $(HEADERS) $(MLXFLAGS) -o $(TARGET)

$(OBJ_FILES): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo -e "$(GREEN)Compiling $@ $(RESET) $(notdir $<)"
	@$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<

bonus:  CFLAGS 		+= -D BONUS=1
bonus:  OBJ_FILES 	+= $(BONUS_OBJ_FILES)
bonus:	re
	@echo -e "$(YELLOW)\nCOMPILED BONUS\n$(RESET)"

debug:	CFLAGS 		= -Wall -Werror -g
debug:	re
	@echo -e "$(YELLOW)\n!-DEBUG MODE-!\n$(RESET)"

san:	CFLAGS 		+= -fsanitize=address
san:	re
	@echo -e "$(YELLOW)\nCOMPILED WITH ADDRESS SANITIZER\n$(RESET)"
	
thread:	CFLAGS 		+= -fsanitize=thread
thread:	re
	@echo -e "$(YELLOW)\nCOMPILED WITH THREAD SANITIZER\n$(RESET)"

undef:	CFLAGS 		+= -fsanitize=undefined
undef:	re
	@echo -e "$(YELLOW)\nCOMPILED WITH UNDEFINED SANITIZER\n$(RESET)"


# ***********CLEANUOP********************************************************** #

clean:
	@echo -e "$(BLUE)Remoning OBJ files$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@echo -e "$(BLUE)Removing $(TARGET)$(RESET)"
	@rm -rf $(TARGET)
	@$(MAKE) -C $(LIBFT) fclean

re: 
	$(MAKE) fclean
	$(MAKE) all

# ***********OTHER************************************************************* #

.PHONY:	all libft clean fclean re bonus debug san thread undef


# ***********COLORS************************************************************ #

RESET	=	\033[0m
GREEN	=	\033[32;1m
BLUE	=	\033[34;1m
RED		=	\033[0;31m
YELLOW	=	\033[0;33m
