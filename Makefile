# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/14 12:46:58 by marvin            #+#    #+#              #
#    Updated: 2025/10/14 12:46:58 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC = so_long.c map.c check_map.c flood_fill.c render.c hooks.c free.c check_map_utils.c
OBJ = $(SRC:.c=.o)

all: $(MLX) $(NAME) $(LIBFT)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -s -C $(MLX_DIR)

$(NAME): $(OBJ) $(MLX)
	@$(MAKE) -s -C $(LIBFT_DIR)
	@$(MAKE) -s -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@$(MAKE) -s -C $(MLX_DIR) clean
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean 
	@rm -f $(NAME) 
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all
