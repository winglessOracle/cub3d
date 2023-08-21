# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wingessoracle <wingessoracle@student.co      +#+                      #
#                                                    +#+                       #
#    Created: 2023/06/21 08:27:49 by wingessorac   #+#    #+#                  #
#    Updated: 2023/08/21 10:48:46 by cwesseli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include common.mk

#++============================================================================++#

.DEFAULT_GOAL	:= all

TARGET	 	=	cub3d
OBJ_FILES	=	$(addprefix obj/, main.o)

#++============================================================================++#

all: libft $(TARGET)

libft:
	$(MAKE) -C $(LIBFT)


#++============================================================================++#

$(TARGET): $(OBJ_FILES)
	@echo -e "$(GREEN)Linking $(TARGET)$(RESET)"
	@$(CC) $(OBJ_FILES) $(LIBS) $(HEADERS) $(MLXFLAGS) -o $(TARGET)


#++============================================================================++#

$(OBJ_FILES): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo -e "$(GREEN)Compiling $@ $(RESET) $(notdir $<)"
	@$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<


#++============================================================================++#

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
