# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/02 13:16:08 by hkortbi           #+#    #+#              #
#    Updated: 2021/10/14 21:53:50 by hkortbi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_DIR = ./libft/
SRC_DIR = srcs
OBJ_DIR = objs

SRC_FILES =	main.c\
			check_error.c\
			free.c\
			swap.c\
			push.c\
			utils.c\
			utils2.c\
			init.c\
			rotate.c\
			little_sort.c\
			sort_algorithms.c\
			big_sort.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
LIBFT = $(addprefix $(LIBFT_DIR), "libft.a")

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(DIR_OBJ) $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT)
	@echo [$(NAME)] : created!

$(DIR_OBJ):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: re fclean clean all