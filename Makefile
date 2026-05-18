# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 18:05:11 by jemoreir          #+#    #+#              #
#    Updated: 2025/11/07 18:05:11 by jemoreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

LIBFT_DIR = libft
SRCS_DIR = src
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC = $(SRCS_DIR)/so_long.c
		$(SRCS_DIR)/map.c
		$(SRCS_DIR)/check_map.c
		$(SRCS_DIR)/flood_fill.c
		$(SRCS_DIR)/render.c
		$(SRCS_DIR)/hooks.c
		$(SRCS_DIR)/free.c
		$(SRCS_DIR)/check_map_utils.c
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
