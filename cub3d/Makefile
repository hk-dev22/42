# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 18:13:06 by hkortbi           #+#    #+#              #
#    Updated: 2021/09/30 13:58:15 by hkortbi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
NAME_TEST = test
MLX_DIR = ./minilibx-linux/
LIBFT_DIR = ./libft/
LIBFT_LIB = $(addprefix $(LIBFT_DIR), "libft.a") 
INC_DIR = ./headers/
SRC_DIR = ./srcs/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR)

SRC_FILES =	main.c\
			free.c\
			get_next_line.c\
			init.c\
			init2.c\
			map.c\
			read.c\
			draw.c\
			raycasting.c\
			player.c
			
TEST_FILE = test.c

TEST = $(addprefix $(SRC_DIR), $(TEST_FILE))

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

test:
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	$(CC) -Wall -Wextra -Werror -g -I $(MLX_DIR) -I $(LIBFT_DIR) -o $(NAME_TEST) $(TEST) $(LIBFT_LIB) -L $(MLX_DIR) -L/usr/lib -lmlx -lm -lz  -lX11 -lXext
	@echo [$(NAME_TEST)] : created!

clean:
	rm -rf $(OBJS)
	rm -rf $(NAME_TEST)
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all