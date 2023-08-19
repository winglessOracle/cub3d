# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    common.mk                                          :+:    :+:             #
#                                                      +:+                     #
#    By: cwesseli <cwesseli@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/07/19 17:26:03 by cwesseli      #+#    #+#                  #
#    Updated: 2023/08/19 10:32:56 by carlowessel   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#++===========Compiler and Flags==============================================++#

CC		 	?=	gcc
CFLAGS	 	?=	-Wall -Wextra -Werror
LDFLAGS	 	?=	$(CFLAGS)


#++===========System MLX specs================================================++#

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLXFLAGS = -ldl -lglfw -pthread -lm
else
	MLXFLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
endif


#++===========Locations=======================================================++#

INCLUDE		=	./include
LIBFT		=	./libraries/libft
LIBMLX		=	./libraries/MLX42
LIBS		=	$(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a
HEADERS		=	-I$(INCLUDE) -I $(LIBFT) -I $(MLX42)/include
SRC_DIR		=	./src
OBJ_DIR		=	./obj



#++===========Operations======================================================++#

# bonus:	SRC_DIR = ./src_bonus
# bonus:	re
# 	@echo -e "$(YELLOW)\nCOMPILED BONUS\n$(RESET)"

# debug:	CFLAGS = -Wall -Werror -g
# debug:	re
# 	@echo -e "$(YELLOW)\n!-DEBUG MODE-!\n$(RESET)"

# san:	CFLAGS += -fsanitize=address
# san:	re
# 	@echo -e "$(YELLOW)\nCOMPILED WITH ADDRESS SANITIZER\n$(RESET)"
	
# thread:	CFLAGS += -fsanitize=thread
# thread:	re
# 	@echo -e "$(YELLOW)\nCOMPILED WITH THREAD SANITIZER\n$(RESET)"

# undef:	CFLAGS += -fsanitize=undefined
# undef:	re
# 	@echo -e "$(YELLOW)\nCOMPILED WITH UNDEFINED SANITIZER\n$(RESET)"


#++===========Other============================================================++#

.PHONY:	all clean fclean re bonus debug san thread undef libft


#++===========Colors==========================================================++#
RESET	=	\033[0m
GREEN	=	\033[32;1m
BLUE	=	\033[34;1m
RED		=	\033[0;31m
YELLOW	=	\033[0;33m