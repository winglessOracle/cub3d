# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wingessoracle <wingessoracle@student.co      +#+                      #
#                                                    +#+                       #
#    Created: 2023/06/21 08:27:49 by wingessorac   #+#    #+#                  #
#    Updated: 2023/09/18 14:53:09 by cherrewi      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include common.mk

.DEFAULT_GOAL	:=	all
TARGET	 		:=	cub3D

OBJ_FILES		:=	$(addprefix obj/, main.o init.o utils.o generate_grid.o grid_functions.o \
					set_paths.o hooks.o move.o set_colors.o build.o checks.o cleanup.o \
					find_bounce_point.o raycasting.o raycasting_utils.o)

all: libmlx libft $(TARGET)

libft:
	$(MAKE) -C $(LIBFT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4


$(TARGET): $(OBJ_FILES)
	@echo -e "$(GREEN)Linking $(TARGET)$(RESET)"
	@$(CC) $(OBJ_FILES) $(LIBS) $(HEADERS) $(MLXFLAGS) -o $(TARGET)


$(OBJ_FILES): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo -e "$(GREEN)Compiling $@ $(RESET) $(notdir $<)"
	@$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<


clean:
	@echo -e "$(BLUE)Remoning MLX42 build$(RESET)"
	@rm -rf $(LIBMLX)/build
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
