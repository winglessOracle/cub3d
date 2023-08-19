# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: carlo <carlo@student.42.fr>                  +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/10 09:28:26 by cwesseli      #+#    #+#                  #
#    Updated: 2023/08/19 10:18:25 by carlowessel   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

TARGET	 	= libft.a
CC			= gcc
AR			= ar -rsc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror

OBJ_FILES	= $(ft_check_extention.o)

#++============================================================================++#

all: $(TARGET)

#++============================================================================++#

$(TARGET): $(OBJ_FILES)
	@echo -e "$(GREEN)Building $(TARGET)$(RESET)"
	@$(AR) $(TARGET) $(OBJ_FILES)

#++============================================================================++#

$(OBJ_FILES): %.o: %.c
	@echo "$(GREEN)Compiling:$(RESET) $@ $(notdir $<)"
	@$(CC) -c $(CFLAGS) -o $@ $<
	
#++============================================================================++#
clean:
	@echo -e "$(BLUE)Cleaning $(TARGET)$(RESET)"
	@$(RM) $(OBJ_FILES)

fclean: clean
	@$(RM) $(TARGET)

re: fclean all

.PHONY:	all clean fclean re

#++============================================================================++#

RESET	=	\033[0m
GREEN	=	\033[32;1m
BLUE	=	\033[34;1m
