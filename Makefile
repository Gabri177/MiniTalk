# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 20:32:40 by yugao             #+#    #+#              #
#    Updated: 2024/02/07 21:01:24 by yugao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = servidor.c client.c
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client
#bonus: server client

server: servitor.o libft
	$(CC) -o $@ $< -LLibft -lft

client: cliente.o libft
	$(CC) -o $@ $< -LLibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C Libft

clean:
	rm -f $(OBJECTS)
	make -C Libft clean
	
fclean: clean
	rm -f server client Libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re