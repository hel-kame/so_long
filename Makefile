# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:49:59 by hel-kame          #+#    #+#              #
#    Updated: 2023/01/05 17:03:45 by hel-kame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = better_so_long

SRC = src/hook_handlers.c				\
      src/parsing.c						\
      src/free.c						\
      src/create_image.c				\
      src/main.c						\
      src/game_events.c					\
      src/get_positions.c				\
      src/init_cross.c					\
      src/pathfinding.c					\

SRC_BONUS = bonus/hook_handlers_bonus.c				\
            bonus/parsing_bonus.c					\
            bonus/free_bonus.c						\
            bonus/create_image_bonus.c				\
            bonus/main_bonus.c						\
            bonus/game_events_bonus.c				\
            bonus/get_positions_bonus.c				\
            bonus/init_cross_bonus.c				\
            bonus/pathfinding_bonus.c				\
            bonus/colors_values_bonus.c				\

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIB_PATH = ./libft

MLX_PATH = ./mlx

LIB = -Llibft -lft

MLX = -Lmlx -lmlx

MLX_REQUIRES = -lXext -lX11 -lz

MATH = -lm

INCLUDES = ./includes

CFLAGS = -Werror -Wextra -Wall -I$(INCLUDES) -I$(MLX_PATH) -g3

all :	$(NAME)

bonus :	$(NAME_BONUS)

$(OBJ) :		%.o: %.c
		@ $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS) :		%.o: %.c
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
		@ rm -f $(OBJ) @
		@ rm -f $(OBJ_BONUS)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove binary files .. 🧹"

fclean : clean
		@ $(MAKE) -s fclean -C $(LIB_PATH)
		@ rm -f $(NAME)
		@ rm -f $(NAME_BONUS)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove executable .. 🗑️"

re :
	@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRecompile .. 🔄"
	@ $(MAKE) -s fclean $(NAME)

.PHONY: all bonus clean fclean re
