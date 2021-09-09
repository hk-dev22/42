# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 18:36:21 by hkortbi           #+#    #+#              #
#    Updated: 2021/09/09 15:43:56 by hkortbi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
LIBFT = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME1) $(NAME2)

$(LIBFT):
	make -C libft/

$(SERVER):
	$(CC) $(CFLAGS) srcs/server.c libft/libft.a -o $@
	
$(CLIENT):
	$(CC) $(CFLAGS) srcs/client.c libft/libft.a -o $@

clean:
	make clean -C libft
	rm -rf $(SERVER) $(CLIENT) 

fclean: clean
	make fclean -C libft
	rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re