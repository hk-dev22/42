# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 05:59:10 by hkortbi           #+#    #+#              #
#    Updated: 2021/09/23 10:39:35 by hkortbi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
MLX_DIR = ./minilibx-linux/
LIBFT_DIR = ./libft/
LIBFT_LIB = $(addprefix $(LIBFT_DIR), "libft.a") 
INC_DIR = ./headers/
SRC_DIR = ./srcs/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR)

SRC_FILES = main.c\
			get_next_line.c\
			map.c\
			player.c\
			draw.c\
			init.c\
			free.c\
			utils.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) -L $(MLX_DIR) -L/usr/lib -lmlx -lm -lz  -lX11 -lXext
	@echo [$(NAME)] : created!

clean:
	rm -rf $(OBJS)
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all