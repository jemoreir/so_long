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
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
MLX_DIR = minilibx-linux
SRCS_DIR = src
INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC =	$(SRCS_DIR)/so_long.c \
		$(SRCS_DIR)/map.c \
		$(SRCS_DIR)/check_map.c \
		$(SRCS_DIR)/flood_fill.c \
		$(SRCS_DIR)/render.c \
		$(SRCS_DIR)/hooks.c \
		$(SRCS_DIR)/free.c \
		$(SRCS_DIR)/check_map_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -s -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -s -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -s -C $(MLX_DIR) clean
	$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re