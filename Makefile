# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:49:59 by hel-kame          #+#    #+#              #
#    Updated: 2023/01/06 16:42:36 by hel-kame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = better_so_long

SRC_DIR = src

SRC_BONUS_DIR = bonus

BIN_DIR = bin

SRC = $(SRC_DIR)/hook_handlers.c				\
      $(SRC_DIR)/parsing.c						\
      $(SRC_DIR)/free.c						\
      $(SRC_DIR)/create_image.c				\
      $(SRC_DIR)/main.c						\
      $(SRC_DIR)/game_events.c					\
      $(SRC_DIR)/get_positions.c				\
      $(SRC_DIR)/init_cross.c					\
      $(SRC_DIR)/pathfinding.c					\

SRC_BONUS = $(SRC_BONUS_DIR)/hook_handlers_bonus.c						\
            $(SRC_BONUS_DIR)/parsing_bonus.c							\
            $(SRC_BONUS_DIR)/free_bonus.c								\
            $(SRC_BONUS_DIR)/create_image_bonus.c						\
            $(SRC_BONUS_DIR)/char_to_img_bonus.c						\
            $(SRC_BONUS_DIR)/main_bonus.c								\
            $(SRC_BONUS_DIR)/game_events_bonus.c						\
            $(SRC_BONUS_DIR)/get_positions_bonus.c						\
            $(SRC_BONUS_DIR)/init_cross_bonus.c							\
            $(SRC_BONUS_DIR)/pathfinding_bonus.c						\
            $(SRC_BONUS_DIR)/colors_values_bonus.c						\
            $(SRC_BONUS_DIR)/ennemies_bonus.c							\
            $(SRC_BONUS_DIR)/end_message_bonus.c						\

OBJ = $(SRC:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)

OBJ_BONUS = $(SRC_BONUS:$(SRC_BONUS_DIR)/%.c=$(BIN_DIR)/%.o)

LIB_PATH = ./libft

MLX_PATH = ./mlx

LIB = -Llibft -lft

MLX = -Lmlx -lmlx

MLX_REQUIRES = -lXext -lX11 -lz

MATH = -lm

INCLUDES = ./includes

CFLAGS = -Werror -Wextra -Wall -I$(INCLUDES) -I$(MLX_PATH) -g3

all :	$(NAME)

bonus:	$(NAME_BONUS)

$(BIN_DIR):
		@ mkdir -p $(BIN_DIR)

$(OBJ) :		$(BIN_DIR)/%.o: $(SRC_DIR)/%.c $(BIN_DIR)
		@ $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS) :		$(BIN_DIR)/%.o: $(SRC_BONUS_DIR)/%.c $(BIN_DIR)
		@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME) :	$(OBJ)
			@ $(MAKE) -s -C $(MLX_PATH)
			@ $(MAKE) -s -C $(LIB_PATH)
			@ $(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_REQUIRES) $(LIB) $(MATH) -o $(NAME)
			@ echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mDone ! ✅"

$(NAME_BONUS) :	$(OBJ_BONUS)
			@ $(MAKE) -s -C $(MLX_PATH)
			@ $(MAKE) -s -C $(LIB_PATH)
			@ $(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX) $(MLX_REQUIRES) $(LIB) $(MATH) -o $(NAME_BONUS)
			@ echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mBonus ! 💸"

clean :
		@ $(MAKE) -s clean -C $(LIB_PATH)
		@ rm -f $(OBJ)
		@ rm -f $(OBJ_BONUS)
		@ rm -rf $(BIN_DIR)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove binary files .. 🧹"

fclean : clean
		@ $(MAKE) -s fclean -C $(LIB_PATH)
		@ rm -f $(NAME)
		@ rm -f $(NAME_BONUS)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove executable .. 🗑️"

re :
	@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRecompile .. 🔄"
	@ $(MAKE) -s fclean $(NAME)

.PHONY: all $(SRC_BONUS_DIR) clean fclean re
