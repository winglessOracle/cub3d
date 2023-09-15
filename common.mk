# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    common.mk                                          :+:    :+:             #
#                                                      +:+                     #
#    By: cwesseli <cwesseli@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/07/19 17:26:03 by cwesseli      #+#    #+#                  #
#    Updated: 2023/09/15 11:10:50 by carlowessel   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# **********FLAGS************************************************************* #

CC		 	?=	gcc
CFLAGS	 	?=	-Wall -Wextra -Werror -O3 -flto
LDFLAGS	 	?=	$(CFLAGS)

# **********SYSTEM SPECS MLX*************************************************** #

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLXFLAGS = -ldl -lglfw -pthread -lm
else
	MLXFLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
endif


# *********LOCATIONS*********************************************************** #

INCLUDE		=	./include
LIBFT		=	./libraries/libft
LIBMLX		=	./libraries/MLX42
LIBS		=	$(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a
HEADERS		=	-I $(INCLUDE) -I $(LIBFT) -I $(MLX42)/include
SRC_DIR		=	./src
OBJ_DIR		=	./obj


# *********OPERATIONS*********************************************************** #

debug:	CFLAGS = -Wall -Werror -g
debug:	re
	@echo -e "$(YELLOW)\n!-DEBUG MODE-!\n$(RESET)"

san:	CFLAGS += -fsanitize=address
san:	re
	@echo -e "$(YELLOW)\nCOMPILED WITH ADDRESS SANITIZER\n$(RESET)"
	
thread:	CFLAGS += -fsanitize=thread
thread:	re
	@echo -e "$(YELLOW)\nCOMPILED WITH THREAD SANITIZER\n$(RESET)"

undef:	CFLAGS += -fsanitize=undefined
undef:	re
	@echo -e "$(YELLOW)\nCOMPILED WITH UNDEFINED SANITIZER\n$(RESET)"


# ***********OTHER************************************************************* #

.PHONY:	all libft libmlx clean fclean re bonus debug san thread undef


# ***********COLORS************************************************************ #

RESET	=	\033[0m
GREEN	=	\033[32;1m
BLUE	=	\033[34;1m
RED		=	\033[0;31m
YELLOW	=	\033[0;33m


# ***********RETURN VALUES***************************************************** #
# 1: parameter check
# 2: malloc primary data
# 3: malloc other structs
# 4: mlx_init
# 5: opening file
# 6: loading textures
# 7: loading colors
# 8: check input data
# 9: generarting grid
# 10: analyzing grid
